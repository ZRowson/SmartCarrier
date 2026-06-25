//===========================================================================
// File Name : Media.cpp
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Definition for Media class.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260619     1.0         000         Zachary Rowson    Initial version
//===========================================================================

#include "Media.h"

const double Media::DEFAULT_SIZE{ 0.0 };
const double Media::CHARGE_PER_MB{ 0.05 };
const double Media::MINIMUM_CHARGE{ 1.0 };
const double Media::SIZE_THRESHOLD{ 100.0 };

Media::Media() : size(Media::DEFAULT_SIZE) {}
Media::Media(double size) : size(size) {}
Media::~Media() {}

double Media::get_size() const {
	return size;
}
bool Media::set_size(double size) {
	this->size = size;
	return true;
}

double Media::GetCharge() const {
	double charge{ size * Media::CHARGE_PER_MB };
	if (charge < Media::MINIMUM_CHARGE) {
		return Media::MINIMUM_CHARGE;
	}
	return charge;
}