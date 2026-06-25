//===========================================================================
// File Name : main.cpp
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Main() for assignment 4. Instantiate, initialize and run a
//		dynamically allocated SmartCarrier object.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260619	    1.0         000         Zachary Rowson    Initial version
// 20260619	    2.0         000         Zachary Rowson    Unit testing of AccountNotFoundException class
// 20260619	    3.0         000         Zachary Rowson    Unit testing of Media class
// 20260619	    4.0         000         Zachary Rowson    Unit testing of Message template class
// 20260620	    5.0         000         Zachary Rowson    Unit testing of SmartCarrier class
// 20260621	    6.0         000         Zachary Rowson    Final version
//===========================================================================

#include "SmartCarrier.h"

int main() {
	SmartCarrier* p_smart_carrier{ new SmartCarrier("Wonderful Wireless", false) };
	p_smart_carrier->Init();
	p_smart_carrier->StartService();
	delete p_smart_carrier;

	return 0;
}