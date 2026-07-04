#include "FRenderer.h"
#include <d3d11.h>
#include <wrl/client.h> // Microsoft::WRL::ComPtr 사용을 위한 헤더

#pragma comment(lib, "d3d11.lib")

// 이 변수들을 엔진의 메인 초기화 클래스 멤버나 전역에 둡니다.
Microsoft::WRL::ComPtr<ID3D11Device>        g_device = nullptr;        // 리소스 생성 담당
Microsoft::WRL::ComPtr<ID3D11DeviceContext> g_context = nullptr;       // 렌더링 명령 담당
Microsoft::WRL::ComPtr<IDXGISwapChain>      g_swapChain = nullptr;


void FRenderer::Initializer(HWND hwnd, int width, int height)
{
    // 1. 스왑 체인 옵션 설정 (화면 해상도, 주사율 등)
    DXGI_SWAP_CHAIN_DESC sd = {};
    sd.BufferCount = 1;                                    // 백 버퍼 개수
    sd.BufferDesc.Width = width;                           // 화면 가로 크기
    sd.BufferDesc.Height = height;                         // 화면 세로 크기
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;     // 색상 포맷
    sd.BufferDesc.RefreshRate.Numerator = 60;              // 60Hz 주사율 기본 세팅
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;      // 렌더 타겟으로 사용
    sd.OutputWindow = hwnd;                                // UI를 띄울 윈도우 창 핸들
    sd.SampleDesc.Count = 1;                               // 멀티샘플링 안함
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;                                    // 창모드 실행
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    // 2. 디바이스의 기능 레벨 (DirectX 11 설정)
    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

    // 3. 디바이스, 컨텍스트, 스왑체인 동시 생성 함수 호출
    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr,                    // 기본 그래픽 카드 어댑터 사용
        D3D_DRIVER_TYPE_HARDWARE,   // GPU 하드웨어 가속 사용
        nullptr,
        0,                          // 디버그 레이어 켤 때 플래그 입력 영역
        &featureLevel,
        1,
        D3D11_SDK_VERSION,          // SDK 버전 전달
        &sd,
        g_swapChain.GetAddressOf(),
        g_device.GetAddressOf(),
        nullptr,
        g_context.GetAddressOf()
    );

    if (FAILED(hr)) {
        MessageBox(hwnd, L"DirectX 11 디바이스 생성 실패!", L"에러", MB_OK);
        return;
    }
}

ID3D11Device* FRenderer::GetDevice()
{
	return g_device.Get();
}

ID3D11DeviceContext* FRenderer::GetDeviceContext()
{
	return g_context.Get();
}
