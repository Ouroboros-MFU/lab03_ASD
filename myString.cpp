#include "myString.h"
#include"iostream"
#include<vector>
using namespace std;
template <typename T>
myString<T>::myString()
{
	std::vector<T> data(0);
}

template <typename T>
myString<T>::myString(const T* _data, const size_t _size)
{
	if (_data == nullptr)
		throw "Bad alloc";
	for (size_t i = 0; i < _size; i++)
		data.push_back(_data[i]);
}

template <typename T>
auto myString<T>::begin()const
{
	return data.begin();
}

template <typename T>
auto myString<T>::end()const
{
	return data.end();
}

template <typename T>
size_t myString<T>::len()const
{
	return data.size();
}

template <typename T>
bool myString<T>::operator==(const myString& s)const
{
	if (data.size() != s.data.size())
		return 0;
	else
	{
		for (size_t i = 0; i < data.size(); i++)
		{
			if (data[i] != s.data[i])
			{
				return 0;
			}
		}
		return 1;
	}
}

template <typename T>
bool myString<T>::operator!=(const myString<T>& s)const
{
	return !(*this == s);
}

template <typename T>
void myString<T>::swapf(myString& s)
{
	swap(data, s.data);
}

template <typename T>
myString<T>& myString<T>::operator=(const myString& s)
{
	if (*this == s) return *this;
	myString <T> tmp(s);
	swapf(tmp);
	return *this;
}

template <typename T>
T& myString<T>::operator[](const size_t index)
{
	if (index >= data.size())
		throw"Invalid index\n";
	return data[index];
}

template <typename T>
T myString<T>::operator[](const size_t index)const
{
	if (index >= data.size())
		throw"Invalid index\n";
	return data[index];
}

template <typename T>
myString<T> myString<T>::operator+(const myString& s)const
{
	if (data.empty())
		return s;
	if (s.data.empty())
		return *this;
	myString<T> res;
	for (size_t i = 0; i < data.size(); i++)
		res.data.push_back(data[i]);
	for (size_t j = 0; j < s.data.size(); j++)
		res.data.push_back(s.data[j]);
	return res;
}

template <typename T>
myString<T> myString<T>::operator*(const size_t pow)
{
	if (data.empty())
		return *this;
	if (pow <= 0)
		throw"Invalid ratio\n";
	myString<T> res;
	for (size_t i = 0; i < pow; i++)
		res = res + *this;
	return res;
}

template <typename T>
myString<T> myString<T>::substring(const size_t index, const size_t length)const
{
	if (data.empty())
		return *this;
	if (index < 0 || index >= data.size())
		throw"Invalid index\n";
	if (length <= 0)
		throw"Invalid length\n";
	myString<T> res;
	for (size_t i = 0; i < length; i++)
		res.data.push_back(data[index + i]);
	return res;
}

template <typename T>
myString<T> myString<T>::operator() (const size_t start, const size_t stop) const
{
	if (data.empty())
		return *this;
	if (start >= data.size())
		throw"Invalid index(start)\n";
	if (stop >= data.size())
		throw"Invalid index(stop)\n";
	if (stop <= start)
		throw"Conflict index\n";
	return substring(start, stop - start);
}

template <typename T>
myString<T> myString<T>::operator() (const size_t start) const
{
	if (data.empty())
		return *this;
	if (start >= data.size())
		throw"Invalid index(start)\n";
	return substring(start, data.size() - start);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const myString<T>& s)
{
	for (auto el: s)
	{
		out << el;
	}
	return out;
}

template<typename T>
myString<T> operator*(const size_t power, const myString<T>& s)
{
	return s * pow;
}

