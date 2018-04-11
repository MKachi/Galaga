#pragma once

#include "Rule.h"

class Size final
{
public:
	uint width;
	uint height;

	Size();
	Size(const uint w, const uint h);
	Size(const Size& rhs);
	Size(Size&& rhs);
	~Size();

	Size& operator=(const Size& rhs);
	Size operator+(const Size& rhs) const;
	Size operator*(uint value) const;
	Size operator/(uint value) const;

	void setSize(const uint w, const uint h);

	static const Size zero;
	static const Size one;


};