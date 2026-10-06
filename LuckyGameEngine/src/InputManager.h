#pragma once

#include <array>
#include "DxLib.h"

enum class Key
{
	// 数字キー
	Num0,
	Num1,
	Num2,
	Num3,
	Num4,
	Num5,
	Num6,
	Num7,
	Num8,
	Num9,

	// アルファベット
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,

	// ファンクションキー
	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	F10,
	F11,
	F12,

	// 矢印キー
	Up,
	Down,
	Left,
	Right,

	// 特殊キー
	Space,
	Enter,
	Tab,
	Backspace,
	Escape,

	// 修飾キー
	LeftShift,
	RightShift,
	LeftCtrl,
	RightCtrl,
	LeftAlt,
	RightAlt,

	// ナビゲーション
	Insert,
	Delete,
	Home,
	End,
	PageUp,
	PageDown,

	// その他
	CapsLock,
	NumLock,
	ScrollLock,

	// テンキー
	NumPad0,
	NumPad1,
	NumPad2,
	NumPad3,
	NumPad4,
	NumPad5,
	NumPad6,
	NumPad7,
	NumPad8,
	NumPad9,
	NumPadPlus,
	NumPadMinus,
	NumPadMultiply,
	NumPadDivide,
	NumPadDecimal,

	// 記号キー
	Minus,
	Plus,
	Comma,
	Period,
	Slash,
	Semicolon,
	Colon,
	Apostrophe,
	LeftBracket,
	RightBracket,
	Backslash,

	Count
};

struct KeyMapping
{
	Key key;
	int dxLibCode;
};

constexpr KeyMapping keyMappings[] =
{
	// 数字キー
	{ Key::Num0, KEY_INPUT_0 },
	{ Key::Num1, KEY_INPUT_1 },
	{ Key::Num2, KEY_INPUT_2 },
	{ Key::Num3, KEY_INPUT_3 },
	{ Key::Num4, KEY_INPUT_4 },
	{ Key::Num5, KEY_INPUT_5 },
	{ Key::Num6, KEY_INPUT_6 },
	{ Key::Num7, KEY_INPUT_7 },
	{ Key::Num8, KEY_INPUT_8 },
	{ Key::Num9, KEY_INPUT_9 },

	// アルファベット
	{ Key::A, KEY_INPUT_A },
	{ Key::B, KEY_INPUT_B },
	{ Key::C, KEY_INPUT_C },
	{ Key::D, KEY_INPUT_D },
	{ Key::E, KEY_INPUT_E },
	{ Key::F, KEY_INPUT_F },
	{ Key::G, KEY_INPUT_G },
	{ Key::H, KEY_INPUT_H },
	{ Key::I, KEY_INPUT_I },
	{ Key::J, KEY_INPUT_J },
	{ Key::K, KEY_INPUT_K },
	{ Key::L, KEY_INPUT_L },
	{ Key::M, KEY_INPUT_M },
	{ Key::N, KEY_INPUT_N },
	{ Key::O, KEY_INPUT_O },
	{ Key::P, KEY_INPUT_P },
	{ Key::Q, KEY_INPUT_Q },
	{ Key::R, KEY_INPUT_R },
	{ Key::S, KEY_INPUT_S },
	{ Key::T, KEY_INPUT_T },
	{ Key::U, KEY_INPUT_U },
	{ Key::V, KEY_INPUT_V },
	{ Key::W, KEY_INPUT_W },
	{ Key::X, KEY_INPUT_X },
	{ Key::Y, KEY_INPUT_Y },
	{ Key::Z, KEY_INPUT_Z },

	// ファンクションキー
	{ Key::F1,  KEY_INPUT_F1 },
	{ Key::F2,  KEY_INPUT_F2 },
	{ Key::F3,  KEY_INPUT_F3 },
	{ Key::F4,  KEY_INPUT_F4 },
	{ Key::F5,  KEY_INPUT_F5 },
	{ Key::F6,  KEY_INPUT_F6 },
	{ Key::F7,  KEY_INPUT_F7 },
	{ Key::F8,  KEY_INPUT_F8 },
	{ Key::F9,  KEY_INPUT_F9 },
	{ Key::F10, KEY_INPUT_F10 },
	{ Key::F11, KEY_INPUT_F11 },
	{ Key::F12, KEY_INPUT_F12 },

	// 矢印キー
	{ Key::Up,    KEY_INPUT_UP },
	{ Key::Down,  KEY_INPUT_DOWN },
	{ Key::Left,  KEY_INPUT_LEFT },
	{ Key::Right, KEY_INPUT_RIGHT },

	// 特殊キー
	{ Key::Space,     KEY_INPUT_SPACE },
	{ Key::Enter,     KEY_INPUT_RETURN },
	{ Key::Tab,       KEY_INPUT_TAB },
	{ Key::Backspace, KEY_INPUT_BACK },
	{ Key::Escape,    KEY_INPUT_ESCAPE },

	// 修飾キー
	{ Key::LeftShift,  KEY_INPUT_LSHIFT },
	{ Key::RightShift, KEY_INPUT_RSHIFT },
	{ Key::LeftCtrl,   KEY_INPUT_LCONTROL },
	{ Key::RightCtrl,  KEY_INPUT_RCONTROL },
	{ Key::LeftAlt,    KEY_INPUT_LALT },
	{ Key::RightAlt,   KEY_INPUT_RALT },

	// ナビゲーション
	{ Key::Insert,   KEY_INPUT_INSERT },
	{ Key::Delete,   KEY_INPUT_DELETE },
	{ Key::Home,     KEY_INPUT_HOME },
	{ Key::End,      KEY_INPUT_END },
	{ Key::PageUp,   KEY_INPUT_PGUP },
	{ Key::PageDown, KEY_INPUT_PGDN },

	// その他
	{ Key::CapsLock,   KEY_INPUT_CAPSLOCK },
	{ Key::NumLock,    KEY_INPUT_NUMLOCK },
	{ Key::ScrollLock, KEY_INPUT_SCROLL },

	// テンキー
	{ Key::NumPad0, KEY_INPUT_NUMPAD0 },
	{ Key::NumPad1, KEY_INPUT_NUMPAD1 },
	{ Key::NumPad2, KEY_INPUT_NUMPAD2 },
	{ Key::NumPad3, KEY_INPUT_NUMPAD3 },
	{ Key::NumPad4, KEY_INPUT_NUMPAD4 },
	{ Key::NumPad5, KEY_INPUT_NUMPAD5 },
	{ Key::NumPad6, KEY_INPUT_NUMPAD6 },
	{ Key::NumPad7, KEY_INPUT_NUMPAD7 },
	{ Key::NumPad8, KEY_INPUT_NUMPAD8 },
	{ Key::NumPad9, KEY_INPUT_NUMPAD9 },

	{ Key::NumPadPlus,     KEY_INPUT_ADD },
	{ Key::NumPadMinus,    KEY_INPUT_SUBTRACT },
	{ Key::NumPadMultiply, KEY_INPUT_MULTIPLY },
	{ Key::NumPadDivide,   KEY_INPUT_DIVIDE },
	{ Key::NumPadDecimal,  KEY_INPUT_DECIMAL },

	// 記号キー
	{ Key::Minus,       KEY_INPUT_MINUS },
	{ Key::Plus,        KEY_INPUT_PREVTRACK },
	{ Key::Comma,       KEY_INPUT_COMMA },
	{ Key::Period,      KEY_INPUT_PERIOD },
	{ Key::Slash,       KEY_INPUT_SLASH },
	{ Key::Semicolon,   KEY_INPUT_SEMICOLON },
	{ Key::Colon,       KEY_INPUT_COLON },
	{ Key::Apostrophe,  KEY_INPUT_AT },       // ← 要注意
	{ Key::LeftBracket, KEY_INPUT_LBRACKET },
	{ Key::RightBracket, KEY_INPUT_RBRACKET },
	{ Key::Backslash,   KEY_INPUT_BACKSLASH },
};

// 将来的にはマウスやパッドは分ける
// InputManager
// ├── Keyboard
// ├── Mouse
// └── GamePad
// もしくは以下のように
// Input/
// ├─ Key.h
// ├─ InputManager.h
// └─ InputManager.cpp


class InputManager
{
private:
	std::array<bool, static_cast<size_t>(Key::Count)> currentStates{};	// falseで初期化
	std::array<bool, static_cast<size_t>(Key::Count)> previousStates{};

	std::array<int, 256> keyStateArray{};	// 0で初期化

public:
	void Update();			// 現在の状態を更新する処理

	bool IsKeyDown(Key key);		// 押されている間ずっと true
	bool WasKeyPressed(Key key);	// 押された瞬間だけ　true
	bool WasKeyReleased(Key key);	// 離された瞬間だけ true
};