#pragma once

#include <vector>
#include <memory>

class GameObject;
struct UpdateContext;

class Scene
{
private:
	std::vector<std::unique_ptr<GameObject>> gameObjects;
public:
	// デストラクタを作成するのは，Scene.cppでScene.hをインクルードした段階で暗黙のデストラクタを生成されることがある．この段階ではGameObjectの定義を知らないから．
	~Scene();
	void AddGameObject(std::unique_ptr<GameObject> gameObject);
	void Start();
	void Update(const UpdateContext& context);
	void Draw();
};