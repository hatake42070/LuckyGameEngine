#include "InputManager.h"
#include "DxLib.h"

void InputManager::Update()
{
	GetHitKeyStateAllEx(keyStateArray.data()); // .dataで先頭要素へのポインタを渡す
}

bool InputManager::IsKeyDown(Key key)
{
	for (const KeyMapping& mapping : keyMappings)
	{
		if (mapping.key == key)
		{
			return keyStateArray[mapping.dxLibCode] > 0;
		}
	}

	return false; // 対応表にないキー
}

bool InputManager::WasKeyPressed(Key key)
{
	return false;
}

bool InputManager::WasKeyReleased(Key key)
{
	return false;
}
