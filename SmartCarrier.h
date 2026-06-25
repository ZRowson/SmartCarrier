//===========================================================================
// File Name : SmartCarrier.h
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Declaration for SmartCarrier objects that enable users to
//		interact with phone service accounts. Users can list accounts and
//		account usage, add messages to accounts, purge large messages, and
//		disconnect accounts.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260619     1.0         000         Zachary Rowson    Initial version
// 20260621     1.1         001         Zachary Rowson    Adding helper functions GetPhoneNumber(), CatchCinFail(), and FindAccount()
//===========================================================================

#ifndef SMARTCARRIER_H
#define SMARTCARRIER_H

#include "Message.h"
#include "Media.h"
#include "AccountNotFoundException.h"
#include <map>
#include <vector>
#include <iomanip>

class SmartCarrier {
public:
	const static std::string DEFAULT_CARRIER_NAME;
	const static bool DEFAULT_INIT;
private:
	std::string carrier_name;
	bool init;
	std::map<std::string, std::vector<Message<Media>*>> account_map;
public:
	SmartCarrier();
	SmartCarrier(std::string carrier_name, bool init);
	~SmartCarrier();

	bool Init();
	void StartService();
private:
	void Menu() const;
	void ListAccounts() const;
	bool InsertMessage();
	void PurgeLargeMessages();
	bool DisconnectAccount();
	int GetChoice() const;
	std::string GetPhoneNumber() const;
	bool CatchCinFail() const;
	std::map<std::string, std::vector<Message<Media>*>>::iterator
		FindAccount(const std::string& account_number);
};

#endif
