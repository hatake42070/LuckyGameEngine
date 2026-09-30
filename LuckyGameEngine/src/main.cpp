#include "App.h"
#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	App app; // アプリケーションの本体

	// 初期化に成功したら
	if (app.Initialize())
	{
		// メインループ実行
		app.Run();
	}

	// 終了処理
	app.Terminate();

	return 0;
}