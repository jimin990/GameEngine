#pragma once

#include <windows.h>

class Window
{
public:
	bool Create(HINSTANCE instance, int showCommand);

	bool ProcessMessages();

	HWND GetHandle() const { return hwnd; }

private:
	HWND hwnd = nullptr;

	static LRESULT CALLBACK WindowProc(
		HWND hwnd,
		UINT message,
		WPARAM wparam,
		LPARAM lparam
	);
};

