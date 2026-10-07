#include "PlayerController.h"
#include "GameObject.h"
#include "UpdateContext.h"
#include "Input.h"
#include "Key.h"

void PlayerController::Update(const UpdateContext& context)
{
	// 斜め移動もいつか正規化する．
	if (context.input != nullptr && context.input->IsKeyHeld(Key::W))
	{
		gameObject->y -= playerSpeed * context.deltaTime;
	}

	if (context.input != nullptr && context.input->IsKeyHeld(Key::S))
	{
		gameObject->y += playerSpeed * context.deltaTime;
	}

	if (context.input != nullptr && context.input->IsKeyHeld(Key::A))
	{
		gameObject->x -= playerSpeed * context.deltaTime;
	}

	if (context.input != nullptr && context.input->IsKeyHeld(Key::D))
	{
		gameObject->x += playerSpeed * context.deltaTime;
	}
}
