#pragma once
#include "constants.h"


// Spawns a new ball into the scene.
// Typically initializes its position, velocity, and any related state.
void SpawnBall();

// Advances the game simulation by one frame.
//  - elapsedTimeSinceLastStep: time passed since the previous frame (in seconds)
// This function usually updates positions, handles collisions, and processes game logic.
void StepFrame(float elapsedTimeSinceLastStep);

// Sets up the initial game scene.
// Usually responsible for creating bricks, placing the paddle, and resetting state.
void SetupScene();