//À¿ÕˆΩÁ√Ê
#pragma once
#include "view.h"
#include "ViewManager.h"
#include "GameView_INF.h"

extern ViewManager view_manager;
class EndView :public view
{
public:
	EndView() = default;
	~EndView() = default;
	IMAGE endview, restart, backmenu;
	void ENTER();
	void UPDATE();
	void DRAW();
	void INPUT(ExMessage& msg);
	void EXIT();
};