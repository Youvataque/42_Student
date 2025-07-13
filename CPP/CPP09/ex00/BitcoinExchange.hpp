#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <map>
#include <limits>

class BitcoinExchange {
private:
	/////////////////////////////////////////////////////////////////////////// méthodes privées
	void		_loadDatas();
	std::string	_findBestValue(std::string date);
	bool		_checkInt(std::string nString, int type);
	bool		_checkDateFormat(std::string date);
	int			_checkValueFormat(std::string value);
	void		_writeResult(std::string key, std::string value);
	std::string _returnError(int n);
	std::string _to_string(double value);

	/////////////////////////////////////////////////////////////////////////// attributs
	std::multimap<std::string, float> _datas;
	std::multimap<std::string, float> _toTest;
public:
	/////////////////////////////////////////////////////////////////////////// constructeur
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();

	/////////////////////////////////////////////////////////////////////////// opérateur d'affectation
	BitcoinExchange& operator=(const BitcoinExchange& other);

	/////////////////////////////////////////////////////////////////////////// méthodes
	void		loadToTest(std::string path);

	/////////////////////////////////////////////////////////////////////////// exceptions
};

#endif