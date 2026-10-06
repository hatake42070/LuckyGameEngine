#pragma once

#include "Component.h"

struct UpdateContext;

class PlayerController : public Component
{
private:
	float playerSpeed = 100.0f;

public:
	void Update(const UpdateContext& context) override;
};