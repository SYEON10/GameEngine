#pragma once

#include "../Manager/IManager.h"

class EditorManager : public IManager<EditorManager>
{
public:
	void StartUp() override;
	void ShutDown() override;
};

