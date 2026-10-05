#include "App.h"
#include "DxLib.h"
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

#include "CircleDrawComponent.h"
#include "GameObject.h"
#include "Scene.h"
#include <memory>
#include <utility>

// ImGuiのWin32メッセージハンドラを外部参照
// 渡されたメッセージ（マウスやキーの操作情報）を読み解いて、ImGuiのボタンを押したり、ウィンドウを動かしたりするImGui専用の入力処理関数
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// DxLibのウィンドウプロシージャをフックし、ImGuiにマウスやキーボードの操作を伝達する
LRESULT CALLBACK WndProcHook(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
	{
		// imgui のボタンを押していたら true が返る
		return 1;
	}
	return 0; // 処理しなかったメッセージはDxLib側に任せる
}

App::App() = default;

App::~App() = default;

// DxLibの初期化と，ImGuiの初期化
bool App::Initialize()
{
	// 1. DxLibの初期化
	ChangeWindowMode(TRUE); // 初期状態はフルスクリーンモードなのでウィンドウモードへの変更
	SetGraphMode(1280, 720, 32); // 解像度と色深度の設定
	if (DxLib_Init() == -1) return false; // DxLibの初期化（DirextXのセットアップ，VRAMの確保，ウィンドウの生成など）
	SetDrawScreen(DX_SCREEN_BACK); // これからの描画命令はすべて，裏画面に対して行う

	// ImGuiに操作を伝えるためのフックを設定
	SetHookWinProc(WndProcHook);

	// 2. ImGuiの初期化
	IMGUI_CHECKVERSION(); // (.hと.cppのバージョンが完全に一致しているかをチェックするマクロ)
	ImGui::CreateContext(); // ImGuiContextというマウスカーソルの位置，どのウィンドウが前面にあるか，どのボタンが押されているか，フォントのデータなどを記憶する巨大な箱がメモリ上に作られる
	ImGui::StyleColorsDark(); // エディタらしいダークテーマ

	// DxLibが内部で生成したDirectX11のデバイス（描画機構）を取得
	ID3D11Device* pDevice = (ID3D11Device*)GetUseDirect3D11Device();
	ID3D11DeviceContext* pContext = (ID3D11DeviceContext*)GetUseDirect3D11DeviceContext();

	// 3. ImGuiの初期化実行と成否チェック
	// どちらか一方でも初期化に失敗したら false を返す
	// ImGuiとDxLib(Win32/DX11)を紐付け
	if (!ImGui_ImplWin32_Init(GetMainWindowHandle()))
	{
		return false;
	}
	if (!ImGui_ImplDX11_Init(pDevice, pContext))
	{
		return false;
	}

	scene = std::make_unique<Scene>();
	auto player = std::make_unique<GameObject>(640, 360, 0);
	//player->x = 640;
	//player->y = 360;
	auto circleComp = std::make_unique<CircleDrawComponent>();
	circleComp->radius = 15;
	player->AddComponent(std::move(circleComp));
	scene->AddGameObject(std::move(player));
	scene->Start();

	// 全ての初期化が無事に突破できたらtrueを返す
	return true;
}

void App::Run()
{
	// メインループ
	// ESCキーで終了するように設定
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen(); // 前フレームで描いた絵（裏画面）を真っ黒に塗りつぶして，新たなキャンバスを用意する

		scene->Update();

		// ImGuiのフレーム開始
		ImGui_ImplDX11_NewFrame(); // DirectX側の準備
		ImGui_ImplWin32_NewFrame(); // マウス座標などの入力情報の更新
		ImGui::NewFrame(); // ImGuiのUI構築スタート

		// ---------- UIの構築 ----------
		ImGui::ShowDemoWindow(); // テスト用の全機能入りウィンドウを表示

		// 独自のUIを追加する場合の例
		ImGui::Begin("Engine Control");
		ImGui::Text("Hello, Custom Game Engine!");
		ImGui::End();
		// ------------------------------

		// 5. ImGuiのUIデータ構築を完了させる
		ImGui::Render();

		// ---------- DxLibの描画 ----------
		// ImGuiの裏側にDxLibの描画が行われるかテスト
		//DrawCircle(640, 360, 100, GetColor(255, 128, 0), TRUE);
		scene->Draw();
		// ---------------------------------

		// 6. ImGuiの実際の描画をDirectX11経由で画面に書き込む
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

		// 裏画面を表画面に反映
		ScreenFlip();
	}
}

void App::Terminate()
{
	// 終了処理
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	DxLib_End();
}
