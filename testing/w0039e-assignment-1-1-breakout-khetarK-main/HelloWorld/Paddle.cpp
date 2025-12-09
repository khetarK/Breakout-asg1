#include "Paddle.h"
#include "constants.h"
#include "Play.h"

//Paddle paddle;

void DrawPaddle(Paddle& paddle)
{

    //// Calculate the left and top sides of the paddle rectangle
    //int topLeftX = paddle.x_Pos - paddleWidth / 2;
    //int topLeftY = paddle.y_Pos - paddleHeight / 2;

    //// Calculate the right and bottom sides of the paddle rectangle
    //int bottomRightX = paddle.x_Pos + paddleWidth / 2;
    //int bottomRightY = paddle.y_Pos + paddleHeight / 2;

    // Draw the paddle as a rectangle in the chosen colour
    //Play::DrawRect({ topLeftX, topLeftY }, { bottomRightX, bottomRightY }, Play::Colour(200, 50, 100));

    paddle.Update();
    Play::DrawRect(paddle.bot_left, paddle.top_right, paddle.color, paddle.fill);
}

void UpdatePaddle(Paddle& paddle)
{
    
    // Move paddle left when the LEFT arrow key is pressed
    if (Play::KeyDown(Play::KEY_LEFT))
    {
        paddle.pad_pos.x -= 1 * paddleSpeed;
    }

    // Move paddle right when the RIGHT arrow key is pressed
    if (Play::KeyDown(Play::KEY_RIGHT))
    {
        paddle.pad_pos.x += 1 * paddleSpeed;
    }

    // Prevent paddle from moving past the left boundary
    if (paddle.pad_pos.x < paddleWidth / 2)
    {
        paddle.pad_pos.x = 0;
    }

    // Prevent paddle from moving past the right boundary
    if (paddle.pad_pos.x > DISPLAY_WIDTH - paddleWidth / 2)
    {
        paddle.pad_pos.x = DISPLAY_WIDTH - paddleWidth / 2;
    }

    paddle.Update();
}