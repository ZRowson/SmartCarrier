//===========================================================================
// File Name : AccountNotFoundException.h
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Declaration for an exception derived from std::exception.
//		Used to notify users that a requested phone account has not been
//		found.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260619     1.0         000         Zachary Rowson    Initial version
// 20260621     1.1         001         Zachary Rowson    Adding helper function CreateMessage()
//===========================================================================

#ifndef ACCOUNTNOTFOUNDEXCEPTION_H
#define ACCOUNTNOTFOUNDEXCEPTION_H

#include <exception>
#include <string>
#include <iostream>

class AccountNotFoundException : public std::exception {
public:
	const static std::string DEFAULT_PHONE_NUMBER;
	std::string phone_number;
	std::string message;

	AccountNotFoundException();
	AccountNotFoundException(std::string phone_number);
	virtual ~AccountNotFoundException() noexcept;
	virtual const char* what() const noexcept override;
private:
	// helper added to create returned message
	std::string CreateMessage(std::string phone_number) const;
};
#endif
