#pragma once


namespace Input {
	//キーボード取得関連
	void KeyStateUpdate();
	//キーが離された瞬間
	bool IsKeyUP(int keyCode);
	bool IsKeyDown(int keyCode);
	int IsKeepKeyDown(int keyCode);
}