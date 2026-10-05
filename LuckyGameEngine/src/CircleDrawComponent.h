#pragma once

#include "Component.h"
#include "DxLib.h"
#include "GameObject.h"

// Componentを継承(拡張)する
class CircleDrawComponent : public Component
{
public:
	int radius = 100;
	void Draw() override // 親のDrawを上書き(オーバーライド)する
	{
		float x = gameObject->x;
		float y = gameObject->y;
		float z = gameObject->z;
		DrawCircle((int)x, (int)y, radius, GetColor(255, 128, 0));
	}
};