#pragma once

/// <summary>
/// キーの種類を定義する
/// </summary>
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