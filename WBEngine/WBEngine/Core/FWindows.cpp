#include "Windows.h"
#include "FWindows.h"

UINT FWindows::width_ = 1280;  // 기본 가로 크기
UINT FWindows::height_ = 800;  // 기본 세로 크기

FWindows::FWindows(HINSTANCE hInstance, int nCmdShow)
{
    WNDCLASSEXW wc{};

	wc.cbSize = sizeof(WNDCLASSEXW);
	wc.style = CS_HREDRAW | CS_VREDRAW; //가로 및 세로 크기 변경 시 윈도우를 다시 그리도록 설정
    wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
    wc.lpszClassName = L"WBEngine";

    wc_ = wc;

	//wc.에 윈도우 창의 아이콘, 커서, 배경색 등 필요한 설정을 추가할 수 있습니다.

	::RegisterClassExW(&wc);

	hwnd_ = ::CreateWindowW(
        wc.lpszClassName, 
        L"S2 Happy S2",         //상단 윈도우 창 이름
        WS_OVERLAPPEDWINDOW, 
        100,                    //윈도우 창 x 좌표
		100,                    //윈도우 창 y 좌표
        (int)(1280 * main_scale),   //윈도우 창 width
        (int)(800 * main_scale),    //윈도우 창 height
        nullptr, 
        nullptr, 
        wc.hInstance,
        nullptr);

	nCmdShow_ = nCmdShow;
}
FWindows::~FWindows()
{
	::DestroyWindow(hwnd_);
	::UnregisterClassW(wc_.lpszClassName, wc_.hInstance);
}

void FWindows::ShowWindow()
{
    ::ShowWindow(hwnd_, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd_);
}
LRESULT __stdcall FWindows::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_SIZE:
        if (wParam == SIZE_MINIMIZED)
            return 0;
        width_ = (UINT)LOWORD(lParam); // Queue resize
        height_ = (UINT)HIWORD(lParam);
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}
;