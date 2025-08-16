//仓库界面(进行飞机装备)
#pragma once
#include "view.h"
#include <iostream>
#include <graphics.h>
#include "ViewManager.h"
#include "Player_plane.h"
class Player_plane;
extern ViewManager view_manager;
extern Player_plane* player;
class WHView :public view
{
public:
	WHView() = default;
	~WHView() = default;
	IMAGE whview, wh_plane_1, wh_plane_2, wh_plane_3,equiped,equip,backmenu;
	void ENTER();
	void UPDATE();
	void DRAW();
	void INPUT(ExMessage& msg);
	void EXIT();
};