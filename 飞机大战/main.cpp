#include <Windows.h>
#include <graphics.h>
#include <string>
#include <iostream>
using namespace std;
//引用界面头文件
#include "view.h"
#include "ViewManager.h"
#include "MenuView.h"
#include "GameView_INF.h"
#include "Enemy_Plane.h"
#include "Endview.h"
#include "SetView.h"
#include "WHView.h"
//引入玩家头文件
#include "Player_plane.h"
Player_plane* player = new Player_planeA();
//全局指针,用于界面跳转
view* menu_view = new MenuView();
view* set_view = new SetView();
view* wh_view = new WHView();
view* game_inf_view = new GameView_INF();
view* end_view = new EndView();

//界面管理器
ViewManager view_manager;

int main() {
	ExMessage msg;
	initgraph(640, 960);

	//程序运行默认为菜单界面
	view_manager.set_current_view(menu_view);

	//播放音乐
	mciSendString("open ../Asset/Music/3.mp3  type mpegvideo alias BGM", NULL, 0, NULL);
	mciSendString("play BGM repeat", NULL, 0, NULL);

	//游戏主循环
	while (true)
	{
		BeginBatchDraw();
		DWORD start_time = GetTickCount();
		//读取操作
		peekmessage(&msg);
		view_manager.INPUT(msg);
	
		//处理数据,界面逻辑
		view_manager.UPDATE();

		//绘制画面
		cleardevice();
		view_manager.DRAW();
		FlushBatchDraw();

		//控制帧数
		DWORD end_time = GetTickCount();
		DWORD delete_time = end_time - start_time;
		if (delete_time < 1000 / 90)
		{
			Sleep(1000 / 90 - delete_time);
		}	
	}
	//释放资源
	EndBatchDraw();
	return 0;
}