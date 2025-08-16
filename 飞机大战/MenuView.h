//≤Àµ•ΩÁ√Ê
#pragma once
#include "view.h"
#include "ViewManager.h"
#pragma comment(lib,"MSIMG32.LIB")
extern ViewManager view_manager;

class MenuView :public view
{
public:
	MenuView() = default;
	~MenuView() = default;

	void ENTER();
	void UPDATE();
	void DRAW();
	void INPUT(ExMessage& msg);
	void EXIT();
};