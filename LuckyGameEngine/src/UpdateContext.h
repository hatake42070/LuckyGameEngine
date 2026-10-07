#pragma once

class Input;

struct UpdateContext
{
	float deltaTime = 0.0f;
	const Input* input = nullptr;
};