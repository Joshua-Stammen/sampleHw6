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
	lowIndex = begIndex;
	highIndex = begIndex + capacity - 1;
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
        realIndex -= lowIndex;


    if (realIndex < 0)
    {
        throw "Invalid index request, too low";
    }

    if (realIndex > capacity -1)
    {
        throw "Invalid index request, too high";
    }
//    cout << index << " " << lowIndex << " " << highIndex << " " << capacity <<  endl;
//    if (index < lowIndex)
//    {
//        throw "Invalid index request, too low";
//    }
//    else if (index > highIndex)
//    {
//        throw "Invalid index request, too high";
//    }
//    else
//    {
//        realIndex = index - lowIndex;
//
//    }
//


	return arr[realIndex];
}

/**
 * Method for returning lowIndex of array
 * @return : Low Index
 */
int SuperArray::getLowIndex() const
{
	return lowIndex;
}

/**
 * Method for returning highIndex of array
 * @return : High Index
 */
int SuperArray::getHighIndex() const
{
	return highIndex;
}

/**
 * Method for returning length of array
 * @return : length (capacity)
 */
unsigned int SuperArray::length() const
{
    //int *temp = new int[capacity];
    unsigned int length = static_cast<unsigned int>(capacity);

	return length;
}

/*!
 * Method for resize length of Index
 * @param begIndex: new starting point for array
 * @param capacity: new capacity for array
 */
void SuperArray::resize(const int begIndex, const unsigned int capacity)
{
    int *temp = new int[capacity];
    int diff = lowIndex - begIndex;
    cout << diff << endl;
    int* parr = arr;

    for (int i = 0; i < diff; i++)
    {
        *(temp + i) = 0;
        cout << *(temp + i) << endl;
    }
    if (capacity > SuperArray::capacity + diff)
    {
        for (int i = diff; i < SuperArray::capacity + diff; i++)
        {
            *(temp + i) = *parr;
            parr++;
            cout << *(temp + i) << endl;
        }
        for (int i = SuperArray::capacity + diff; i < capacity; i++)
        {
            *(temp + i) = 0;
            cout << *(temp + i) << endl;
        }
    }
    else
    {
        for (int i = diff; i < capacity; i++)
        {
            *(temp + i) = *parr;
            parr++;
            cout << *(temp + i) << endl;
        }
    }

//    for (int i = SuperArray::capacity; i < capacity; i++)
//    {
//        *(temp + i) = 0;
//        cout << *(temp + i) << endl;
//    }
    cout << "New Array Created" << endl;
    delete[] arr;
    cout << "Old Memory Deleted" << endl;
    arr = temp;

    SuperArray::capacity = capacity;
    lowIndex = begIndex;
    highIndex = (begIndex + capacity - 1);
    cout << "Resize complete!" << endl;

}
