#pragma once
//界面管理系统:界面状态管理,界面的跳转
#include "view.h"

//获取全局指针
extern view* menu_view;
extern view* set_view;
extern view* wh_view;
extern view* game_inf_view;
extern view* end_view;

class ViewManager
{
public:

	//枚举各个界面,用于标记当前所在界面

	enum class ViewType {
		Menu=1,
		Set,
		WH,
		Game_inf,
		End
	};
public:
	ViewManager() = default;
	//释放界面的全局指针
	~ViewManager() {
		if(menu_view){ delete menu_view; }
		if (set_view) { delete set_view; }
		if (wh_view) { delete wh_view; }
		if (game_inf_view) { delete game_inf_view; }
		if (end_view) { delete end_view; }
	}
	//设置当前状态
	void set_current_view(view* view) {
		current_view = view;
		current_view->ENTER();
	}

	//界面跳转
	void switch_to(ViewType type) {
		//当调用跳转方法时,先重置(更改)上一个场景的状态
		current_view->EXIT();
		switch (type)
		{
		case ViewType::Menu:
			current_view = menu_view;
			break;
		case ViewType::Set:
			current_view = set_view;
			break;
		case ViewType::WH:
			current_view = wh_view;
			break;
		case ViewType::Game_inf:
			current_view = game_inf_view;
			break;
		case ViewType::End:
			current_view = end_view;
			break;
		default:
			break;
		}
		//游戏界面->暂停界面->返回/重来/退出
		


		//重置(更改)下一个界面的状态
		current_view->ENTER();
	}

	void UPDATE() {
		current_view->UPDATE();
		//更新界面
		//界面运行逻辑
	};
	void DRAW() {
		current_view->DRAW();
		//绘制界面
	};
	void INPUT(ExMessage& msg) {
		current_view->INPUT(msg);
		//接受操作信息
		//1.切换界面 则更改 current_view为对应界面的全局指针
		//2.进行操作 则调用对应的方法
	};

private:
	//当前界面的状态  
	view* current_view = nullptr;
};