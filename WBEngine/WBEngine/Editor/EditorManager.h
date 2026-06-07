#pragma once

#include "../Core/IManager.h"

class EditorManager : public IManager<EditorManager>
{
public:
	void StartUp() override;
	void ShutDown() override;
};

