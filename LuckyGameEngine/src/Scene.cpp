#include "Scene.h"
#include <utility>
#include "GameObject.h"
#include "UpdateContext.h"

Scene::~Scene() = default;

void Scene::AddGameObject(std::unique_ptr<GameObject> gameObject)
{
	gameObjects.push_back(std::move(gameObject));
}

void Scene::Start()
{
	for (auto& gameObject : gameObjects)
	{
		gameObject->Start();
	}
}

void Scene::Update(const UpdateContext& context)
{
	for (auto& gameObject : gameObjects)
	{
		gameObject->Update(context);
	}
}

void Scene::Draw()
{
	for (auto& gameObject : gameObjects)
	{
		gameObject->Draw();
	}
}
