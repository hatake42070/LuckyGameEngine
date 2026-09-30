#pragma once

class GameObject;

class App
{
private:
	GameObject* player;

public:
	bool Initialize();
	void Run();
	void Terminate(); // ImGuiとDxLibの終了処理を行う
};