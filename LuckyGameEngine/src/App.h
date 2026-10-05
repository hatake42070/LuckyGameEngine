#pragma once
#include <memory>

//class GameObject;
class Scene;

class App
{
private:
	//GameObject* player;
	std::unique_ptr<Scene> scene;

public:
	App();
	~App();
	bool Initialize();
	void Run();
	void Terminate(); // ImGuiとDxLibの終了処理を行う
};