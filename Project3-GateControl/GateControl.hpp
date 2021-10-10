#pragma once


#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

typedef size_t CardNumber;

typedef size_t GateNumber;



struct Authorization
{
	Authorization() { }
	
	Authorization(CardNumber number, const string& name, const string& startTime, const string& endTime)
	: number_(number), name_(name), startTime_(startTime), endTime_(endTime) { }

	CardNumber number_;

	string name_;
	
	string startTime_;
	
	string endTime_;
};

typedef map<CardNumber, Authorization> AuthorizationMap;
typedef	AuthorizationMap::iterator AuthorizationMapIterator;

typedef	vector<Authorization> AuthorizationVector;

struct Transaction
{
	Transaction() { }

	Transaction(CardNumber number, const string& name, const string& date, const string& time, bool accessAllowed)
	: number_(number), name_(name), date_(date), time_(time), accessAllowed_(accessAllowed) { }

	CardNumber number_;
	
	string name_;
	
	string date_;

	string time_;
	
	bool accessAllowed_;
};

typedef	vector<Transaction> TransactionVector;
typedef	TransactionVector::iterator TransactionVectorIterator;

class	GateControl
{
	public:
		bool accessAllowed(CardNumber number);
	
		bool addAuthorization(CardNumber number, const string& name, const string& startTime, const string& endTime);
		
		bool changeAuthorization(CardNumber number, const string& name, const string& startTime, const string& endTime);
		
		bool deleteAuthorization(CardNumber number);
		
		void getAllAuthorizations(AuthorizationVector& authorizationVector);
		
		void getAllTransactions(TransactionVector& transactionVector);
	
		bool getCardAuthorization(CardNumber number, Authorization& authorization);

		void getCardTransactions(CardNumber number, TransactionVector& transactionVector);

	private:
		AuthorizationMap authorizationMap_;
		
		TransactionVector transactionVector_;
};



extern string gCurrentDate;

extern string gCurrentTime;



//****************************************************************************************
//
//	TO DO
//
//****************************************************************************************


bool GateControl::accessAllowed(CardNumber number) //wrong
{

	AuthorizationMapIterator it;
	for (it = authorizationMap_.begin(); it != authorizationMap_.end(); it++) {
		if (number == it->first && gCurrentTime >= it->second.startTime_ && gCurrentTime <= it->second.endTime_) {				
			transactionVector_.push_back(Transaction(number, it->second.name_, gCurrentDate, gCurrentTime, (true)));
			return true;
		}
		else
			transactionVector_.push_back(Transaction(number, it->second.name_, gCurrentDate, gCurrentTime, (false)));
			return false;
	}
}


bool GateControl::addAuthorization(CardNumber number, const string& name, const string& startTime, const string& endTime) //wrong
{
	Authorization a1(number, name, startTime, endTime);
	std::pair<CardNumber, Authorization> KeyVal(number, a1);
	if (authorizationMap_.empty()) {				//if map is already empty, than add
		authorizationMap_.insert(KeyVal);
		return true;
	}
	else {
		if (authorizationMap_.find(number) == authorizationMap_.end()) {		//if the keyval doesnt exist, than add
			authorizationMap_.insert(KeyVal);
				return true;
		}
		else          //if not return false
			return false;
	}
}


bool GateControl::changeAuthorization(CardNumber number, const string& name, const string& startTime, const string& endTime)
{	
	Authorization a1(number, name, startTime, endTime);
	std::pair<CardNumber, Authorization> KeyVal(number, a1);
	if (authorizationMap_.find(number) != authorizationMap_.end()) {      //if the keyvalue exist
		authorizationMap_.erase(number);								//erase the values you want to replace
		authorizationMap_.insert(KeyVal);								//than replace it
		return true;
	}
	else
		return false;
}


bool GateControl::deleteAuthorization(CardNumber number)
{
	if (authorizationMap_.find(number) != authorizationMap_.end()){
		authorizationMap_.erase(number);				//key is founded and is deleted rom the map
		return true;
	}else
		return false;				//key is not found 
}


void GateControl::getAllAuthorizations(AuthorizationVector& authorizationVector)
{
	AuthorizationMapIterator it;
	authorizationVector.clear();
		for (it = authorizationMap_.begin(); it != authorizationMap_.end(); it++) {
			authorizationVector.push_back(it->second);
		}
}


void GateControl::getAllTransactions(TransactionVector& transactionVector) //wrong
{
	TransactionVectorIterator it;
	transactionVector.clear();
	for (it = transactionVector_.begin(); it != transactionVector_.end(); it++) {
		transactionVector.push_back(Transaction(it->number_, it->name_, it->date_, it->time_, it->accessAllowed_));
	}
}


bool GateControl::getCardAuthorization(CardNumber number, Authorization& authorization)
{
	if (authorizationMap_.find(number) != authorizationMap_.end()) {
		authorization = authorizationMap_.at(number);
		return true;
	}
	else
		return false;				
}


void GateControl::getCardTransactions(CardNumber number, TransactionVector& transactionVector) //wrong
{
	TransactionVectorIterator it;
	if (!transactionVector_.empty()) {
		for (size_t i = 0; i < transactionVector_.size(); i++) {
			if (transactionVector_[i].number_ = number) {
				transactionVector = transactionVector_;
			}
		}
	}
	else 
		transactionVector.clear();
}
