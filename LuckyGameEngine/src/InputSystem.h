#pragma once

#include "Input.h"
#include <array>

/// <summary>
/// DxLibから情報を取得してInputを更新する
/// </summary>
class InputSystem
{
private:
	Input input;
	// DxLibから取得した現在のキー状態

public:
	void Initialize();	// JSONを読む
	void Update();	// DxLibから現在のキー状態を取得

	const Input& GetInput() const;
};