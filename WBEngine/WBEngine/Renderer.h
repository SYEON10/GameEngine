#pragma once
#include <d3d11.h>

class Renderer
{
public:
	void Initializer(HWND hwnd, int width, int height);
	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();
};

