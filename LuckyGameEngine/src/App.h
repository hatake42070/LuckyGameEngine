#pragma once

//class GameObject;
class Scene;

class App
{
private:
	//GameObject* player;
	Scene* scene;

public:
	bool Initialize();
	void Run();
	void Terminate(); // ImGuiとDxLibの終了処理を行う
};