#pragma once

class GameObject; // 前方宣言

class Component
{
public:
	GameObject* gameObject;

	// #includeが少ないうちはこの中に処理を書く
	virtual ~Component() {}
	virtual void Start() {}		// 初期化処理
	virtual void Update() {}
	virtual void Draw() {}		// 描画処理
}