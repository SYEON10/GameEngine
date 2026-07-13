#include <d3d11.h>
#include <tchar.h>
#include <windows.h> 
#include <windowsx.h> 
#include "Core/Application.h"

int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
	Application app(hInstance, nCmdShow);
	app.Run();

    return 0;
}
