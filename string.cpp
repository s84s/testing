#include "string.h"
#include <iostream>
#include <algorithm>

String::String()
{}

size_t strlen(const char* string)
{
	size_t lenght;
	for(lenght=0; string[lenght]; lenght++);
	return lenght;
}

String::String(const char* other)
{
	mSize = strlen(other);
	mData = std::make_unique<char[]>(mSize);
	mCapacity = mSize;

	size_t i;
	for(size_t i=0; i < mSize; ++i)
	{
		mData[i] = other[i];
	}
}

char& String::operator[] (size_t i)
{
	return mData[i];
}

bool String::operator== (const String& other) const
{
	if(size() != other.size())
	{
		return false;
	}
	else
	{
		for(int i=0; i < size(); ++i)
		{
			if(mData[i] != other.mData[i])
			{
				return false;
			}
		}
	}
	return true;
}

std::ostream& operator<< (std::ostream& os, const String& string)
{
	os << string.c_str();
	return os;
}
