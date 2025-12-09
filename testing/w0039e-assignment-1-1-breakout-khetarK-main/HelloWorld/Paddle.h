#pragma once
#include "constants.h"
#include "Play.h"

 /*A paddle in the game. It has an x and y position.
 The paddle starts at x = 320 and y = 35.*/
//struct Paddle
//{
//    int x_Pos = 320; // Paddle's left/right position
//    int y_Pos = 35;  // Paddle's up/down position
//};



struct Paddle
{


	Play::Point2D pad_pos = Play::Point2D(DISPLAY_WIDTH / 2, 50.0f);

	Play::Point2D bot_left = Play::Point2D(pad_pos.x - paddleWidth / 2, pad_pos.y);
	Play::Point2D top_right = Play::Point2D(bot_left.x + paddleWidth, bot_left.y + paddleHeight);

	void Update()
	{

		bot_left.x = pad_pos.x - paddleWidth / 2;
		bot_left.y = pad_pos.y - paddleHeight / 2;
		top_right.x = bot_left.x + paddleWidth;
		top_right.y = bot_left.y + paddleHeight;
	}

	Play::Colour color = Play::cWhite;

	bool fill = true;



};








// This tells the program that a Paddle named "paddle"
// exists somewhere else in the code.
//extern Paddle paddle;

// Draws the paddle on the screen.
// Uses the paddle's position but does not change it.
void DrawPaddle(Paddle& paddle);

// Updates the paddle (for example, moving it based on input).
// Can change the paddle's position.
void UpdatePaddle(Paddle& paddle);