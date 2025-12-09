#pragma once   // Ensures this header file is included only once during compilation

// Display / Window configuration
const int DISPLAY_WIDTH  = 640;   // Width of the game window in pixels
const int DISPLAY_HEIGHT = 360;   // Height of the game window in pixels
const int DISPLAY_SCALE  = 2;     // Scale factor for rendering (useful for pixel-art style)

// Ball configuration
const int ballSpeed = 5;          // Speed of the ball in pixels per frame

// Brick dimensions
const int brick_width  = 16;      // Width of a single brick
const int brick_height = 10;      // Height of a single brick

// Paddle configuration
const int paddleWidth  = 80;      // Paddle width in pixels
const int paddleHeight = 10;      // Paddle height in pixels
const int paddleSpeed  = 15;      // Movement speed of the paddle in pixels per frame

// Object types used to identify different game entities
enum ObjectType
{
    TYPE_BALL,   // Represents a ball object
    TYPE_BRICK   // Represents a brick object
};