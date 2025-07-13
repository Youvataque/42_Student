#include "Account.hpp"
#include "iostream"
#include <ctime>
#include <iomanip>

/////////////////////////////////////////////////////////////////////////////////////// Attributs de la class
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/////////////////////////////////////////////////////////////////////////////////////// Obligatoires de la class

///////////////////////////////////////////////////////////////////////////////
// Constructeur
Account::Account(int initial_deposit) {
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Destructeur
Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

/////////////////////////////////////////////////////////////////////////////////////// Méthodes de la class

///////////////////////////////////////////////////////////////////////////////
// Permet de récupérer le nombre de compte
int Account::getNbAccounts(void) {
	_displayTimestamp();
	return Account::_nbAccounts;
}

///////////////////////////////////////////////////////////////////////////////
//	récupère le montant total au seins de la banque
int Account::getTotalAmount(void) {
	_displayTimestamp();
	return Account::_totalAmount;
}

///////////////////////////////////////////////////////////////////////////////
// récupère le nombre total de dépot affectué à la banque
int Account::getNbDeposits(void) {
	_displayTimestamp();
	return Account::_totalNbDeposits;
}

///////////////////////////////////////////////////////////////////////////////
// récupère le montant total de retrait effectué à la banque
int Account::getNbWithdrawals(void) {
	_displayTimestamp();
	return Account::_totalNbWithdrawals;
}

///////////////////////////////////////////////////////////////////////////////
// affiche l'ensemble des infos générales de la banque
void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
	          << ";total:" << _totalAmount
	          << ";deposits:" << _totalNbDeposits
	          << ";withdrawals:" << _totalNbWithdrawals
	          << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Fonction pour déposer un moment auprès de la banque.
void Account::makeDeposit(int deposit) {
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	          << ";p_amount:" << (this->_amount - deposit)
	          << ";deposit:" << deposit
	          << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits
	          << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Fait un retrait sur un compte x si possible sinon renvoie une erreur
bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (this->_amount > withdrawal) {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << "index:" << this->_accountIndex
				<< ";p_amount:" << (this->_amount + withdrawal)
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << this->_amount
				<< ";nb_withdrawals:" << this->_nbWithdrawals
				<< std::endl;
		return true;
	}
	std::cout << "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";withdrawal:refused"
				<< std::endl;
	return false;
}

///////////////////////////////////////////////////////////////////////////////
// Fonction pour controler le solde du compte x
int Account::checkAmount(void) const {
	return this->_amount;
}

///////////////////////////////////////////////////////////////////////////////
// affiche les infos d'un compte x
void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";deposits:" << _nbDeposits
	          << ";withdrawals:" << _nbWithdrawals
	          << std::endl;
}

/////////////////////////////////////////////////////////////////////////////////////// Méthodes privés de la class

///////////////////////////////////////////////////////////////////////////////
// Affiche la date actuelle
void Account::_displayTimestamp(void) {
	std::time_t now = std::time(NULL);
	std::tm *ltm = std::localtime(&now);

	std::cout << "["
	          << std::setfill('0') << std::setw(4) << 1900 + ltm->tm_year
	          << std::setw(2) << 1 + ltm->tm_mon
	          << std::setw(2) << ltm->tm_mday << "_"
	          << std::setw(2) << ltm->tm_hour
	          << std::setw(2) << ltm->tm_min
	          << std::setw(2) << ltm->tm_sec
	          << "] ";
}