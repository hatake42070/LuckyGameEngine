#include "InputSystem.h"
#include "Key.h"
#include <DxLib.h>

void InputSystem::Initialize()
{
	input.SetDxLibCode(Key::W, KEY_INPUT_W);
	input.SetDxLibCode(Key::A, KEY_INPUT_A);
	input.SetDxLibCode(Key::S, KEY_INPUT_S);
	input.SetDxLibCode(Key::D, KEY_INPUT_D);
}

void InputSystem::Update()
{
	// 今回のフレーム用の空の配列を作る
	std::array<char, 256> tempKeyStates{};

	// DxLibから最新のキー状態を取得して書き込んでもらう
	GetHitKeyStateAll(tempKeyStates.data());

	// Inputに最新の配列を渡し、内部で「過去」と「現在」の更新を行わせる
	input.UpdateState(tempKeyStates);
}

const Input& InputSystem::GetInput() const	// 後ろのconstはInputSystem自身のメンバ変数を書き換えない
{
	return input;
}
