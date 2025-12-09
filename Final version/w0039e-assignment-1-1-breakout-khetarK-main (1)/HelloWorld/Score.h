#pragma once
#include "Play.h"
#include "constants.h"



extern unsigned int currentScore;
extern unsigned int highScore;



struct DynamicArray
{
	unsigned int* arr = nullptr;
	int size = 0;


	void append(unsigned int &currentScore)
	{
		unsigned int* newArr = new unsigned int[size + 1];

		for(int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}

		if (arr != nullptr)
		{
			delete[] arr;
		}

		arr = newArr;

		arr[size] = currentScore;
		
		size++;
	}



	void remove()
	{
		if (!arr)
		{
			unsigned int* newArr = new unsigned int[size - 1];

			for (int i = 0; i < (size - 1); i++)
			{
				newArr[i] = arr[i];
			}

			delete[] arr;

			arr = newArr;

			size--;

		}
	}


	void sort()
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (arr[j] < arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	
	Play::Colour array_colour = Play::cWhite;
};




struct HighScore
{
	Play::Point2D score_pos = Play::Point2D(550, 150);

	Play::Colour score_colour = Play::cWhite;

	/*DynamicArray* high_scores = nullptr;*/

	DynamicArray high_scores;

};


struct CurrentScore
{
	Play::Point2D score_pos = Play::Point2D(10, 12);

	Play::Colour score_colour = Play::cWhite;
};


extern HighScore highscore;

extern CurrentScore current_score;

extern DynamicArray D_array;


void DrawScore();
