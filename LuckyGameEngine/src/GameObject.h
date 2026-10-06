#pragma once

#include <vector>
#include "Component.h"
#include <memory>

struct UpdateContext;

class GameObject
{
public:
	GameObject(
		float x,
		float y,
		float z
	);
	float x, y, z;								// transformクラス作る？	
	std::vector<std::unique_ptr<Component>> components;
	void AddComponent(std::unique_ptr<Component>);	// コンポーネントを追加する関数
	void Start();
	void Update(const UpdateContext& context);
	void Draw();
};