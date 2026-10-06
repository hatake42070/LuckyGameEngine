#pragma once
#include <memory>
#include "UpdateContext.h"

//class GameObject;
class Scene;
class InputManager;

class App
{
private:
	//GameObject* player;
	std::unique_ptr<Scene> scene;
	long long previousTime = 0;
	long long currentTime = 0;
	float deltaTime = 0;
	std::unique_ptr<InputManager> inputManager;
	UpdateContext updateContext;

public:
	App();
	~App();
	bool Initialize();
	void Run();
	void Terminate(); // ImGuiとDxLibの終了処理を行う
};