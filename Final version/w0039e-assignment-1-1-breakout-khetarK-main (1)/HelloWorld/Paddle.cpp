#include "Paddle.h"
#include "constants.h"
#include "Play.h"

Paddle paddle;

void DrawPaddle(const Paddle& paddle)
{
    // Calculate the left and top sides of the paddle rectangle
    int topLeftX = paddle.x_Pos - paddleWidth / 2;
    int topLeftY = paddle.y_Pos - paddleHeight / 2;

    // Calculate the right and bottom sides of the paddle rectangle
    int bottomRightX = paddle.x_Pos + paddleWidth / 2;
    int bottomRightY = paddle.y_Pos + paddleHeight / 2;

    // Draw the paddle as a rectangle in the chosen colour
    Play::DrawRect({ topLeftX, topLeftY }, { bottomRightX, bottomRightY }, Play::Colour(200, 50, 100));
}

void UpdatePaddle(Paddle& paddle)
{
    // Move paddle left when the LEFT arrow key is pressed
    if (Play::KeyDown(Play::KEY_LEFT))
    {
        paddle.x_Pos -= 1 * paddleSpeed;
    }

    // Move paddle right when the RIGHT arrow key is pressed
    if (Play::KeyDown(Play::KEY_RIGHT))
    {
        paddle.x_Pos += 1 * paddleSpeed;
    }

    // Prevent paddle from moving past the left boundary
    if (paddle.x_Pos < 40)
    {
        paddle.x_Pos = 40;
    }

    // Prevent paddle from moving past the right boundary
    if (paddle.x_Pos > DISPLAY_WIDTH - 45)
    {
        paddle.x_Pos = DISPLAY_WIDTH - 40;
    }
}