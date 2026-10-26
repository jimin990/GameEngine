#include "Window.h"

bool Window::Create(HINSTANCE instance, int showCommand)
{
    const wchar_t* className = L"GameEngine";

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance;
    wc.lpszClassName = className;

    if (!RegisterClassW(&wc))
    {
        return false;
    }

    hwnd = CreateWindowExW(
        0,
        className,
        L"My Game Engine",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        1280,
        720,
        nullptr,
        nullptr,
        instance,
        nullptr
    );

    if (!hwnd)
    {
        return false;
    }

    ShowWindow(hwnd, SW_SHOW);

    return true;
}

bool Window::ProcessMessages()
{
    MSG msg{};
    
    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
        {
            return false;
        }

        DispatchMessage(&msg);
    }

    return true;
}

LRESULT Window::WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProcW(hwnd, message, wparam, lparam);
}
