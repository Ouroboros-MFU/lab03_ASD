#pragma once
#include"iostream"
#include<vector>
using namespace std;
template <typename T>
class myString
{
private:
	vector<T> data;
public:
	myString();
	myString(const T* data, const size_t size);
	auto begin()const;
	auto end()const;
	size_t len()const;
	bool operator==(const myString& s)const;
	bool operator!=(const myString& s)const;
	void swapf(myString& s);
	myString<T>& operator=(const myString& s);
	T& operator [](const size_t index);
	T operator [](const size_t index)const;
	myString operator+(const myString& s)const;
	myString operator* (const size_t power);
	myString substring(const size_t index, const size_t length)const;
	myString operator() (const size_t start, const size_t stop) const;
	myString operator() (const size_t start) const;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const myString<T>& s);

template <typename T>
myString<T> operator* (const size_t power, const myString<T>& s);