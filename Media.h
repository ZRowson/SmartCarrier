//===========================================================================
// File Name : Media.h
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Declaration for the Media class. Media objects represent
//		media contained in an text message and are used to calculate the
//		cost of a text message.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260619	    1.0         000         Zachary Rowson    Initial version
//===========================================================================

#ifndef MEDIA_H
#define MEDIA_H

class Media {
public:
	const static double DEFAULT_SIZE;
	const static double CHARGE_PER_MB;
	const static double MINIMUM_CHARGE;
	const static double SIZE_THRESHOLD;
private:
	double size;
public:
	Media();
	Media(double size);
	~Media();
	double get_size() const;
	bool set_size(double size);
	double GetCharge() const;
};

#endif