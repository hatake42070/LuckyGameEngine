#include "Input.h"

// 押されているか（押しっぱなし判定）
bool Input::IsKeyHeld(Key key) const
{
	int code = dxLibCodes[static_cast<size_t>(key)];
	return currentKeyStates[code] == 1;
}

// 押された瞬間か
bool Input::IsKeyPressed(Key key) const
{
	int code = dxLibCodes[static_cast<size_t>(key)];
	// 今回は押されている 且つ 前回は押されていなかった
	return currentKeyStates[code] == 1 && prevKeyStates[code] == 0;
}

// 離された瞬間か
bool Input::IsKeyReleased(Key key) const
{
	int code = dxLibCodes[static_cast<size_t>(key)];
	// 今回は押されていない 且つ 前回は押されていた
	return currentKeyStates[code] == 0 && prevKeyStates[code] == 1;
}

void Input::SetDxLibCode(Key key, int dxLibCode)
{
	dxLibCodes[static_cast<size_t>(key)] = dxLibCode;
}