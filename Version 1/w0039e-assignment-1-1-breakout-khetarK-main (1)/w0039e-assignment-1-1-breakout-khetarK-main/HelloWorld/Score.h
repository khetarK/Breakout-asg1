#pragma once
#include "constants.h"
#include "Play.h"
#include <iostream>

using namespace std;



//struct Score
//{
//
//
//	Play::Point2D score_pos = Play::Point2D(DISPLAY_WIDTH, DISPLAY_HEIGHT / 50.0f);
//};

class DynamicArray
{
	unsigned int* arr = nullptr; 
	int size = 0;

public:

	DynamicArray()
	{
	}

	// **TODO**
	// I need a method to increase size

	void append(unsigned int newMember)
	{
		unsigned int* newArr = new unsigned int[size + 1]; 
		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i]; 
		}

		newArr[size] = newMember;

		delete[] arr;

		arr = newArr;

		size++;
	}


	// **TODO**
	// I need a method to decrease size

	void remove()
	{
		unsigned int* newArr = new unsigned int[size - 1];

		for (int i = 0; i < size - 1; i++)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;

		arr = newArr;

		size--;
	}


	// **TODO**
	// sort the array



};

//extern Score score;
//
//
//void UpdateScore(Score& score);