#include "Score.h"
#include "constants.h"
#include "Play.h"
#include "fstream"


unsigned int currentScore = 0;

unsigned int highScore = 0;

DynamicArray D_array;

HighScore highscore;

CurrentScore current_score;

void DrawScore()
{
	
	Play::DrawDebugText(highscore.score_pos,"High Score", highscore.score_colour, false);

	Play::DrawDebugText(current_score.score_pos,("Current Score " + std::to_string(currentScore)).c_str(), current_score.score_colour, false);

	for (int i = 0; i < std::min(highscore.high_scores.size,5); i++)
	{
		std::string scoreStr = std::to_string(highscore.high_scores.arr[i]);
		Play::DrawDebugText({ 550, (130 - (16 * i)) }, scoreStr.c_str(), D_array.array_colour, false);
	}
}

void WriteInFile()
{
	std::ofstream MyFile("HighScore.txt");

	for (int i = 0; i < highscore.high_scores.size; i++)
	{
		MyFile << highscore.high_scores.arr[i] << std::endl;
	}

	MyFile.close();
}


void ReadMyFile()
{
	std::ifstream MyFile("HighScore.txt");	

	if (MyFile)
	{
		unsigned int scores;

		while (MyFile >> scores)
		{
			highscore.high_scores.append(scores);
		}

		MyFile.close();
	}

}