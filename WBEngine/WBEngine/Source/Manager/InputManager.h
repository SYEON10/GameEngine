#pragma once

#include "IManager.h"
#include "ManagerMinimal.h"
#include <Windows.h>

enum class EKeyCode : INT8 {
	KEY_W,
	KEY_A,
	KEY_S,
	KEY_D,

	MOUSE_LEFT,
	MOUSE_RIGHT,
};

enum class InputEventType : INT8 {
	KeyDown,
	KeyUp,
	KeyPress,

	MouseDown,
	MouseUp,
};

using InputParam = TVariant<EKeyCode, FVector2D>;

struct FInputEvent {

	FInputEvent(InputEventType eventType, EKeyCode keyCode)
		: eventType_(eventType), keyCode_(keyCode) {}

	FInputEvent(InputEventType eventType, EKeyCode keyCode, FVector2D mousePos)
		: eventType_(eventType), keyCode_(keyCode), mousePos_(mousePos) {
	}

	InputEventType eventType_;
	EKeyCode keyCode_;

	TOptional<FVector2D> mousePos_;

	bool operator==(const FInputEvent& other) const = default;
};

using FInputCallback = std::function<void()>;
using FInputListenerHandle = INT64;

class InputManager : public IManager<InputManager>
{
	friend class IManager<InputManager>;

private:
	InputManager() = default;

public:
	void StartUp() override;
	void ShutDown() override;

	FInputListenerHandle Bind(FInputEvent inputEvent, FInputCallback callback);
	void UnbindAll();

	FVector2D GetMouseDelta();

	bool GetWindowsInput(UINT& msg, WPARAM wParam, LPARAM lParam);

private:
	struct FListener
	{
		explicit FListener(FInputListenerHandle handle, FInputEvent inputEvent, FInputCallback callback)
			: handle_(handle), inputEvent_(inputEvent), callback_(callback){ }

		FInputListenerHandle handle_;
		FInputEvent inputEvent_;
		FInputCallback callback_;
	};

	void Broadcast(const FInputEvent& event);

	TArray<FListener> listeners_;
	FInputListenerHandle nextHandle_ = INDEX_NONE;
};

