#pragma once

#include <vector>
#include "Component.h"

class GameObject
{
public:
	GameObject(
		float x,
		float y,
		float z
	);
	float x, y, z;								// transformクラス作る？
	std::vector<Component*> components;			// GameObjectsの持つコンポーネントリスト
	void AddComponent(Component* component);	// コンポーネントを追加する関数
	void Start();
	void Update();
	void Draw();
};