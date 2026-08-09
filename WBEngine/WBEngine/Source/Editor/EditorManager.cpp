#include "EditorManager.h"

#include "ImGUI/imgui.h"
#include "ImGUI/imgui_impl_dx11.h"
#include "ImGUI/imgui_impl_win32.h"

void EditorManager::StartUp()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    //ImGui_ImplWin32_Init(hWnd);
}

void EditorManager::ShutDown()
{
}

