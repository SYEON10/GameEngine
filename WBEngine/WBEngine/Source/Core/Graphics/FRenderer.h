#pragma once
#include <d3d11.h>
#include <CoreMinimal.h>

//DirectX 11 초기화 및 렌더링 담당
class FRenderer
{
public:
	void Initializer(HWND hwnd, int width, int height);
	virtual ~FRenderer();

	void RenderLoop();

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();

	ID3D11RenderTargetView* renderTargetView_;

private:
	void InitPipeline();
};

