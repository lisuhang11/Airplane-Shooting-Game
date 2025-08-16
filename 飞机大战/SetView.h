//“Ù¿÷…Ë÷√ΩÁ√Ê
#pragma once
#include "view.h"
#include "ViewManager.h"
extern ViewManager view_manager;
class SetView :public view
{
public:
	SetView() = default;
	~SetView() = default;
	IMAGE setview,music1,music2,music3,pausemusic,backmenu;
	void ENTER();
	void UPDATE();
	void DRAW();
	void INPUT(ExMessage& msg);
	void EXIT();
};