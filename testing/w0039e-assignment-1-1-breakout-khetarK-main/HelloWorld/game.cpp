#include "game.h"
#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Paddle.h"


Paddle paddle;
//-----------------------------------------------------------------------
// Spawns a ball in the center area and assigns an initial velocity
//-----------------------------------------------------------------------

void SpawnBall() 
{
	// Create the ball object at a fixed position with radius 4 and sprite name "ball"
	const int objectId = Play::CreateGameObject(ObjectType::TYPE_BALL,
		{ DISPLAY_WIDTH / 2, DISPLAY_HEIGHT - 280 }, 4, "ball");


	// Access the created ball
	GameObject& ball = Play::GetGameObject(objectId);

	// Set its normalized direction (1, -1) multiplied by base ball speed
	ball.velocity = normalize({ 1, -1 }) * ballSpeed;
}



//-----------------------------------------------------------------------
// Clamp helpers (though naming is reversed compared to standard)
// Max(a, b) returns the larger of a and b
//-----------------------------------------------------------------------

float Max(float topLeft, float min)
{
	return (topLeft > min) ? topLeft : min;
}


// Min(a, b) returns the smaller of a and b
float Min(float ballPos, float bottomRight)
{
	return (ballPos < bottomRight) ? ballPos : bottomRight;
}




//-----------------------------------------------------------------------
// Checks collision between paddle (AABB) and ball (circle)
// Uses clamped closest-point technique
//-----------------------------------------------------------------------
bool isColliding(const Paddle& paddle, const GameObject& obj)
{
	// Paddle bounding box coordinates
	//int topLeftX = paddle.pad_pos.x + paddleWidth / 2;
	//int topLeftY = paddle.pad_pos.y + paddleHeight / 2;
	//int bottomRightX = paddle.pad_pos.x - paddleWidth / 2;
	//int bottomRightY = paddle.pad_pos.y - paddleHeight / 2;

	//const float dx = obj.pos.x - Max(topLeftX, Min(obj.pos.x, bottomRightX));
	//const float dy = obj.pos.y - Max(topLeftY, Min(obj.pos.y, bottomRightY));

	const float dx = obj.pos.x - Max(paddle.bot_left.x, Min(obj.pos.x, paddle.top_right.x));
	const float dy = obj.pos.y - Max(paddle.bot_left.y, Min(obj.pos.y, paddle.top_right.y));

	return (dx * dx + dy * dy) < (obj.radius * obj.radius);
}



//-----------------------------------------------------------------------
// Main frame update: draws, moves, manages collisions
//-----------------------------------------------------------------------
void StepFrame(float elapsedTimeSinceLastStep)
{
	// -----------------------------------------
	// Retrieve all balls currently in the game
	// -----------------------------------------
	const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);

	// Handle ball movement, drawing, and wall collision
	for (int i = 0; i < ballIds.size(); i++)
	{
		int id = ballIds[i];
		Play::GameObject& ball_object = Play::GetGameObject(id);
		Play::DrawObject(ball_object);
		Play::UpdateGameObject(Play::GetGameObject(id));


		// Bounce horizontally
		if (ball_object.pos.x > DISPLAY_WIDTH || ball_object.pos.x < 0)
		{
			ball_object.velocity.x = -ball_object.velocity.x;
		}

		// Bounce vertically
		if (ball_object.pos.y > DISPLAY_HEIGHT || ball_object.pos.y < 0)
		{
			ball_object.velocity.y = -ball_object.velocity.y;
		}
	}


	// -----------------------------------------
	// Retrieve and manage all bricks
	// -----------------------------------------
	const std::vector<int> brickIds = Play::CollectGameObjectIDsByType(TYPE_BRICK);

	for (int i = 0; i < brickIds.size(); i++)
	{
		int b_id = brickIds[i];
		Play::GameObject& brick_object = Play::GetGameObject(b_id);
		Play::DrawObject(brick_object);
		Play::UpdateGameObject(Play::GetGameObject(b_id));
	}


	// -----------------------------------------
	// Ball -> Brick collisions
	// -----------------------------------------
	for (int i = 0; i < ballIds.size(); i++)
	{
		int id = ballIds[i];
		Play::GameObject& ball_object = Play::GetGameObject(id);


		for (int b = 0; b < brickIds.size(); b++)
		{
			int b_id = brickIds[b];
			Play::GameObject& brick_object = Play::GetGameObject(b_id);

			// Using built-in collision
			if (Play::IsColliding(ball_object, brick_object))
			{
				// Destroy the brick
				Play::DestroyGameObject(b_id);

				// Reverse ball direction (simple bounce)
				ball_object.velocity.y = -ball_object.velocity.y;

			}
		}
	}


	// -----------------------------------------
	// Ball -> Paddle collision
	// -----------------------------------------
	for (int i = 0; i < ballIds.size(); i++)
	{
		int currentBall = ballIds[i];
		GameObject& ball = Play::GetGameObject(currentBall);
		if (isColliding(paddle, ball))
		{
			// Bounce vertically when hitting the paddle
			ball.velocity.y = -ball.velocity.y;
		}
	}

	// -----------------------------------------
	// Draw + update the player's paddle
	// -----------------------------------------
	UpdatePaddle(paddle);
	DrawPaddle(paddle);
}


//-----------------------------------------------------------------------
// Builds the brick wall at the start of the scene
//-----------------------------------------------------------------------
void SetupScene()
{
	// Create a grid of bricks: 7 rows, 38 columns
	for (int rows = 1; rows < 8; rows++)
	{
		for (int piller = 1; piller < 39; piller++)
		{
			int x = piller * brick_width;
			int y = DISPLAY_HEIGHT - ((rows + 1)  * brick_height);
			Play::CreateGameObject(ObjectType::TYPE_BRICK, { x, y }, 6, "brick");
		}
	}
}

