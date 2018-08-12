#pragma once
#include <iosfwd>
#include <memory>

class String
{
public:
	String();
	size_t size() const { return mSize; };
	size_t capacity() const { return mCapacity; };
	bool empty() const { return String::size() == 0; };
	char* c_str() const { return mData.get(); }

	String(const char*);
	String& operator=(const char*);

	char& operator[](size_t);
	
	bool operator==(const String&) const;
  
  private:
    size_t mSize{0};
    size_t mCapacity{0};
    std::unique_ptr<char[]> mData{nullptr};
};
