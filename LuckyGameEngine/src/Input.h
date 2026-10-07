#pragma once

#include <array>
#include <cstddef>
#include "Key.h"

/// <summary>
/// キーの対応表を保持する
/// </summary>
class Input
{
private:
	// Key → DxLibのキーコード
	std::array<int, static_cast<size_t>(Key::Count)> dxLibCodes{};

	// 今回と前回のキー状態を保持 (char型で256バイトずつ)
	std::array<char, 256> currentKeyStates{};
	std::array<char, 256> prevKeyStates{};

public:
	// 毎フレーム InputSystem から呼ばれる
	void UpdateState(const std::array<char, 256>& newStates)
	{
		// 今の配列を「過去」に回し、新しい配列を「現在」として受け取る
		prevKeyStates = currentKeyStates;
		currentKeyStates = newStates;
	}

	// 状態判定関数 (Unityの Input クラスを真似た設計)
	bool IsKeyHeld(Key key) const;			// 押されているか（押しっぱなし）
	bool IsKeyPressed(Key key) const;		// 押された瞬間か
	bool IsKeyReleased(Key key) const;		// 離された瞬間か

	void SetDxLibCode(Key key, int dxLibCode);
};