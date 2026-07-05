#include "FRenderer.h"
#include <d3d11.h>
#include <wrl/client.h> // Microsoft::WRL::ComPtr 사용을 위한 헤더

#pragma comment(lib, "d3d11.lib")

Microsoft::WRL::ComPtr<ID3D11Device>        g_device = nullptr;        // 리소스 생성 담당
Microsoft::WRL::ComPtr<ID3D11DeviceContext> g_context = nullptr;       // 렌더링 명령 담당
Microsoft::WRL::ComPtr<IDXGISwapChain>      g_swapChain = nullptr;


void FRenderer::Initializer(HWND hwnd, int width, int height)
{
    // 스왑 체인 옵션 설정 (화면 해상도, 주사율 등)
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

    // DirectX 11 설정
    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

    // 디바이스, 컨텍스트, 스왑체인 동시 생성
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

    ID3D11Texture2D* pBackBuffer = nullptr;
    renderTargetView_ = nullptr;
    g_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

    // use the back buffer address to create the render target
    g_device->CreateRenderTargetView(pBackBuffer, NULL, &renderTargetView_);
    pBackBuffer->Release();

    // set the render target as the back buffer
    g_context->OMSetRenderTargets(1, &renderTargetView_, NULL);

    D3D11_VIEWPORT vp;
    vp.Width = 800.0f;     // 출력할 가로 화면 크기
    vp.Height = 600.0f;    // 출력할 세로 화면 크기
    vp.MinDepth = 0.0f;    // 최소 깊이 값 (보통 0)
    vp.MaxDepth = 1.0f;    // 최대 깊이 값 (보통 1)
    vp.TopLeftX = 0.0f;    // 시작 X 좌표 (좌상단 0)
    vp.TopLeftY = 0.0f;    // 시작 Y 좌표 (좌상단 0)

    // 컨텍스트의 래스터라이저 단계에 뷰포트를 설정합니다.
    g_context->RSSetViewports(1, &vp);
}

FRenderer::~FRenderer()
{
    g_device->Release();
    g_context->Release();
	g_swapChain->Release(); 
}

void FRenderer::RenderLoop()
{
    float clearColor[] = { 0.0f, 0.125f, 0.3f, 1.0f };
    g_context->ClearRenderTargetView(renderTargetView_, clearColor);

    // 물체 렌더링 로직

    // 후면 버퍼와 전면 버퍼를 교체하여 화면에 출력 (수직동기화 여부: 0은 즉시 출력)
    g_swapChain->Present(0, 0);
}

ID3D11Device* FRenderer::GetDevice()
{
	return g_device.Get();
}

ID3D11DeviceContext* FRenderer::GetDeviceContext()
{
	return g_context.Get();
}
