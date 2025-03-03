#ifndef FUNCTORS_H
#define FUNCTORS_H

#include "../../lib.h"

template<typename TReturn> bool isEmpty(const vector<TReturn>& arr) { return arr.empty(); }

template<typename TValue>
class findMin
{
public:
	TValue operator()(const vector<TValue>& arr) const { if (isEmpty(arr)) { return TValue(); } return *min_element(arr.begin(), arr.end()); }
};
template<typename TValue>
class findMax
{
public:
	TValue operator()(const vector<TValue>& arr) const { if (isEmpty(arr)) { return TValue(); } return *max_element(arr.begin(), arr.end()); }
};

template<typename TValue>
class sortAscending
{
public:
	void operator()(vector<TValue>& arr) const { if (isEmpty(arr)) { return; }; sort(arr.begin(), arr.end()); }
};
template<typename TValue>
class sortDescending
{
public:
	void operator()(vector<TValue>& arr) const { if (isEmpty(arr)) { return; }; sort(arr.rbegin(), arr.rend()); }
};

template<typename TValue> class increase
{
private:
	TValue _value;
public:
	increase(const TValue& value) : _value(value) {}

	void operator()(vector<TValue>& arr) const
	{
		if (isEmpty(arr)) { return; };
		for_each(arr.begin(), arr.end(), [this](TValue& currentValue) { currentValue += _value; });
	}
};
template<typename TValue> class decrease
{
private:
	TValue _value;
public:
	decrease(const TValue& value) : _value(value) {}

	void operator()(vector<TValue>& arr) const
	{
		if (isEmpty(arr)) { return; };
		for_each(arr.begin(), arr.end(), [this](TValue& currentValue) { currentValue -= _value; });
	}
};

template<typename TValue> class removeItem
{
private:
	TValue _value;
public:
	removeItem(const TValue& value) : _value(value) {}

	void operator()(vector<TValue>& arr) const
	{
		if (isEmpty(arr)) { return; }
		typename vector<TValue>::iterator id = find(arr.begin(), arr.end(), _value);
		if (id != arr.end()) { arr.erase(id); }
	}
};

#endif