#pragma once


// A paddle in the game. It has an x and y position.
// The paddle starts at x = 320 and y = 35.
struct Paddle
{
    int x_Pos = 320; // Paddle's left/right position
    int y_Pos = 35;  // Paddle's up/down position
};

// This tells the program that a Paddle named "paddle"
// exists somewhere else in the code.
extern Paddle paddle;

// Draws the paddle on the screen.
// Uses the paddle's position but does not change it.
void DrawPaddle(const Paddle& paddle);

// Updates the paddle (for example, moving it based on input).
// Can change the paddle's position.
void UpdatePaddle(Paddle& paddle);