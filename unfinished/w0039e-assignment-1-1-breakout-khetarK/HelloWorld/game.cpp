#include "game.h"
#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"


void SpawnBall() 
{
	const int objectId = Play::CreateGameObject(ObjectType::TYPE_BALL,
		{ DISPLAY_WIDTH / 2, DISPLAY_HEIGHT - 280 }, 4, "ball");
	
	GameObject& ball = Play::GetGameObject(objectId);
	ball.velocity = normalize({ 1, -1 }) * ballSpeed;
}

void StepFrame(float elapsedTimeSinceLastStep)
{
	const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);

	for (int i = 0; i < ballIds.size(); i++)
	{
		int id = ballIds[i];
		Play::GameObject& object = Play::GetGameObject(id);
		Play::DrawObject(object);
		Play::UpdateGameObject(Play::GetGameObject(id));
		
		if (Play::GetGameObject(id).pos.x > DISPLAY_WIDTH || Play::GetGameObject(id).pos.x < 0)
		{
			Play::GetGameObject(id).velocity.x = -Play::GetGameObject(id).velocity.x;
		}
		if (Play::GetGameObject(id).pos.y > DISPLAY_HEIGHT || Play::GetGameObject(id).pos.y < 0)
		{
			Play::GetGameObject(id).velocity.y = -Play::GetGameObject(id).velocity.y;
		}
	}
}

void SetupScene()
{
	Play::CreateGameObject(ObjectType::TYPE_BRICK, { x, y }, 6, "brick");

	if (Play::)
}