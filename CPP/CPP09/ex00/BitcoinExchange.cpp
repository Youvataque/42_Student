#include "BitcoinExchange.hpp"

/////////////////////////////////////////////////////////////////////////// méthodes privées
void		BitcoinExchange::_loadDatas() {
	std::ifstream file("data.csv");
	if (!file) {
		throw std::invalid_argument("Error: give us data.csv !");
	}
	std::string line;
	while (getline(file, line)) {
		std::size_t pos = line.find(',');
		if (pos != std::string::npos) {
			this->_datas.insert(std::make_pair(
				line.substr(0, pos),
				atof(line.substr(pos + 1).c_str())
			));
		} else {
			throw std::invalid_argument("Error: seriously you can't give me a good database ?!");
		}
	}
};

bool		BitcoinExchange::_checkDateFormat(std::string date) {
	std::size_t index;
	if (date.size() != 10) {
		return false;
	}

	index = date.find('-');
	if (index == std::string::npos || index != 4) {
		return false;
	}
	if (!_checkInt(date.substr(0, index), 2))
		return false;
	if (date.substr(4, 1).find('-') == std::string::npos || date.substr(4, 1).find('-') != 0) {
		return false;
	}
	if (!_checkInt(date.substr(5, 2), 0))
		return false;
	if (date.substr(8, 2).size() != 2) {
		return false;
	}
	if (!_checkInt(date.substr(8, 2), 1))
		return false;
	return true;
};

bool BitcoinExchange::_checkInt(std::string nString, int type) {
    std::istringstream	iss(nString);
    int					nb;
    char				c;

    if (!(iss >> nb) || (iss.get(c)))
        return false;
    if (type == 0 && (nb < 1 || nb > 12))
        return false;
    else if (type == 1 && (nb < 1 || nb > 31))
        return false;
    else
        return true;
}

std::string BitcoinExchange::_returnError(int n) {
	switch (n) {
		case -1:
			return "not a number.";
		case -2:
			return "not a positive number.";
		case -3:
			return "number too large.";
		default:
			return "";
	}
}

std::string BitcoinExchange::_to_string(double value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

int		BitcoinExchange::_checkValueFormat(std::string value) {
    std::istringstream	iss(value);
    double				temp;
    char				c;
	
    if (!(iss >> temp) || (iss.get(c)))
        return -1;
    if (temp < 0)
        return -2;
    if (temp > std::numeric_limits<int>::max())
        return -3;
    return 1;
}

std::string	BitcoinExchange::_findBestValue(std::string date) {
	std::multimap<std::string, float>::iterator it = _datas.find(date);
	if (it != _datas.end()) {
		return _to_string(it->second);
	} else {
		std::multimap<std::string, float>::iterator itLower = _datas.lower_bound(date);
		if (itLower != _datas.begin()) {
			--itLower;
		}
		return _to_string(itLower->second);
	}
};

void		BitcoinExchange::_writeResult(std::string key, std::string value) {
	std::size_t pos = key.find("Error:");
	std::cout << key;
	if (pos == std::string::npos)
		std::cout << " => " << value;
	std::cout << std::endl;
};

/////////////////////////////////////////////////////////////////////////// constructeur
BitcoinExchange::BitcoinExchange() : _datas(), _toTest() {
	_loadDatas();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	this->_datas = other._datas;
	this->_toTest = other._toTest;
}

BitcoinExchange::~BitcoinExchange() {}

/////////////////////////////////////////////////////////////////////////// opérateur d'affectation
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->_datas = other._datas;
		this->_toTest = other._toTest;
	}
	return *this;
}

/////////////////////////////////////////////////////////////////////////// méthodes
void		BitcoinExchange::loadToTest(std::string path) {
	std::ifstream file(path.c_str());
	if (!file) {
		throw std::invalid_argument("Error: Seriously? Use good input next time, newbies!");
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::size_t pos = line.find(" | ");
		if (pos != std::string::npos) {
			std::string key = line.substr(0, pos);
			std::string value = line.substr(pos + 3);
			int n = _checkValueFormat(value);
			if (!_checkDateFormat(key)) {
				_writeResult("Error: bad input => " + key, "");
			} else if (n < 0) {
				_writeResult("Error: " + _returnError(n), "");
			} else {
				double temp = std::atof(value.c_str()) * std::atof(_findBestValue(key).c_str());
				_writeResult(key, value + " = " + _to_string(temp));
			}
		} else {
			_writeResult("Error: bad input => " + line, "");
		}
	}
};

