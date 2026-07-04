#pragma once
#include <d3d11.h>

//DirectX 11 초기화 및 렌더링 담당
class FRenderer
{
public:
	void Initializer(HWND hwnd, int width, int height);

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();
};

