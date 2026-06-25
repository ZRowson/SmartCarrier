//===========================================================================
// File Name : AccountNotFoundException.cpp
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Definition for AccountNotFoundException
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260619     1.0         000         Zachary Rowson    Initial version
// 20260621     1.1         001         Zachary Rowson    Adding helper function CreateMessage()
//===========================================================================

#include "AccountNotFoundException.h"

const std::string AccountNotFoundException::DEFAULT_PHONE_NUMBER{ "000-000-0000" };

AccountNotFoundException::AccountNotFoundException() :
	phone_number(AccountNotFoundException::DEFAULT_PHONE_NUMBER),
	message(AccountNotFoundException::CreateMessage(AccountNotFoundException::DEFAULT_PHONE_NUMBER))
{}
AccountNotFoundException::AccountNotFoundException(std::string phone_number) :
	phone_number(phone_number),
	message(AccountNotFoundException::CreateMessage(phone_number))
{}
AccountNotFoundException::~AccountNotFoundException() noexcept {}

const char* AccountNotFoundException::what() const noexcept {
	return message.c_str();
}
// helper function to create message returned by what()
std::string AccountNotFoundException::CreateMessage(std::string phone_number) const {
	return "*** Account " + phone_number + " not found ***";
}