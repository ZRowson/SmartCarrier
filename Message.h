//===========================================================================
// File Name : Message.h
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : A template class to encapsulate text message data. Contains
//		receiving phone number and message media.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260619     1.0         000         Zachary Rowson    Initial version
//===========================================================================

#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>

/* Declaration */
template <class T>
class Message {
public:
	const static std::string DEFAULT_TO;
private:
	std::string to;
	T message_data;
public:
	Message();
	Message(std::string to, T message_data);
	~Message();
	std::string get_to() const;
	T get_message_data() const;
	bool set_to(std::string to);
	bool set_message_data(T& message_data);
};


/* Definition */
template <class T>
const std::string Message<T>::DEFAULT_TO{ "000-000-0000" };

// constructors and destructor
template<class T>
Message<T>::Message() :
	to(Message<T>::DEFAULT_TO),
	message_data(T{})
{}
template<class T>
Message<T>::Message(std::string to, T message_data) :
	to(to),
	message_data(message_data)
{}
template <class T>
Message<T>::~Message() {}

// accessors
template <class T>
std::string Message<T>::get_to() const {
	return to;
}
template <class T>
T Message<T>::get_message_data() const {
	return message_data;
}

// mutators
template <class T>
bool Message<T>::set_to(std::string to) {
	this->to = to;
	return true;
}
template <class T>
bool Message<T>::set_message_data(T& message_data) {
	this->message_data = message_data;
	return true;
}

#endif