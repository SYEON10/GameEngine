#include "InputManager.h"

TOptional<EKeyCode> ToEngineKeyCode(WPARAM wParam)
{
	switch (wParam)
	{
		case 'W': return EKeyCode::KEY_W;
		case 'A': return EKeyCode::KEY_A;
		case 'S': return EKeyCode::KEY_S;
		case 'D': return EKeyCode::KEY_D;
		default:  return {};
	}
}

void InputManager::StartUp()
{
}

void InputManager::ShutDown()
{
}

FInputListenerHandle InputManager::Bind(FInputEvent inputEvent, FInputCallback callback)
{
	if (!callback)
		return 0;

	const FInputListenerHandle handle = nextHandle_++;
	listeners_.push_back(FListener(handle, inputEvent, callback));

	return handle;
}

void InputManager::UnbindAll()
{
	listeners_.clear();
}

FVector2D InputManager::GetMouseDelta()
{
	return FVector2D();
}

bool InputManager::GetWindowsInput(UINT& msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_KEYDOWN:
	{
		const TOptional<EKeyCode> keyCode = ToEngineKeyCode(wParam);
		if (!keyCode.has_value())
			return false;

		// bit 30: 이 키가 이전에도 눌린 상태였는가 => 꾸욱 구현할 때 쓰기
		//const bool isRepeat = (lParam & (1LL << 30)) != 0;

		Broadcast(FInputEvent(InputEventType::KeyDown, keyCode.value()));

		return true;
	}
	default:
		break;
	}

	return false;
}

void InputManager::Broadcast(const FInputEvent& event)
{
	for (const FListener& listener : listeners_)
	{
		if (listener.inputEvent_ != event) {
			continue;
		}
		
		listener.callback_();
	}
}
