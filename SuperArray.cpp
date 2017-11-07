// File: SuperArray
// Created by Hugo Valle on 10/31/2017.
// Copyright (c) 2017 WSU
//

#include "SuperArray.h"
/*!
 * Constructor
 * @param begIndex User's low index
 * @param capacity Maximum array capacity
 */
SuperArray::SuperArray(const int begIndex, const unsigned int capacity)
{
	/* This is declaring a local variable, if you have data member
	 * called int* arr, the code on line ## will NOT refer to the data
	 * member, instead you created a second arr pointer, and this
	 * second pointer dies and is lost forever when the constructor ends
	 */
	arr = new int[capacity];
    SuperArray::capacity = capacity;
	// Other info below
}

/*!
 * Class Destructor
 */
SuperArray::~SuperArray()
{
	delete[] arr;
}


/*!
 * Convert int array to string.
 * Note: You do not need to modify this function
 * @param obj Instance of SuperArray to convert to string
 * @return string form of array
 */
string arrayToString(const SuperArray& obj)
{
	stringstream ss;

	for (int i = 0; i < obj.capacity; i++)
    {
        //cout << obj.arr[i] << " i " << i<<endl;
        ss << obj.arr[i] << " ";
    }
	string str = ss.str();
	size_t found;
	found = str.find_last_not_of(" ");
	if (found != string::npos)
		str.erase(found + 1);
	else
		str.clear();            // str is all whitespace

	return str;
}

/*!
 * Index operator overload
 * @param index User's index notation
 * @return Actual index notation
 */
int &SuperArray::operator[](const int index)
{
	int realIndex = index;
	//
	// Define your logic here
	//
	return arr[realIndex];
}
