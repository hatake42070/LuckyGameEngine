#pragma once

class InputManager;

struct UpdateContext
{
	float deltaTime = 0.0f;
	InputManager* inputManager = nullptr;
};