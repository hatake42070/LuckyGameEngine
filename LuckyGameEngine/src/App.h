#pragma once

class App
{
private:

public:
	bool Initialize();
	void Run();
	void Terminate(); // ImGuiとDxLibの終了処理を行う
};