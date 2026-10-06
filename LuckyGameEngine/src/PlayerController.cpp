#include "PlayerController.h"
#include "DxLib.h"
#include "GameObject.h"
#include "UpdateContext.h"
#include "InputManager.h"

void PlayerController::Update(const UpdateContext& context)
{
	// 斜め移動もいつか正規化する．
	if (context.inputManager->IsKeyDown(Key::W))
	{
		gameObject->y -= playerSpeed * context.deltaTime;
	}

	if (context.inputManager->IsKeyDown(Key::S))
	{
		gameObject->y += playerSpeed * context.deltaTime;
	}

	if (context.inputManager->IsKeyDown(Key::A))
	{
		gameObject->x -= playerSpeed * context.deltaTime;
	}

	if (context.inputManager->IsKeyDown(Key::D))
	{
		gameObject->x += playerSpeed * context.deltaTime;
	}
}
