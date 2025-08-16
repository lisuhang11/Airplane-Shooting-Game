#include <Windows.h>
#include <graphics.h>
#include <string>
#include <iostream>
using namespace std;
//���ý���ͷ�ļ�
#include "view.h"
#include "ViewManager.h"
#include "MenuView.h"
#include "GameView_INF.h"
#include "Enemy_Plane.h"
#include "Endview.h"
#include "SetView.h"
#include "WHView.h"
//�������ͷ�ļ�
#include "Player_plane.h"
Player_plane* player = new Player_planeA();
//ȫ��ָ��,���ڽ�����ת
view* menu_view = new MenuView();
view* set_view = new SetView();
view* wh_view = new WHView();
view* game_inf_view = new GameView_INF();
view* end_view = new EndView();

//���������
ViewManager view_manager;

int main() {
	ExMessage msg;
	initgraph(640, 960);

	//��������Ĭ��Ϊ�˵�����
	view_manager.set_current_view(menu_view);

	//��������
	mciSendString("open ../Asset/Music/3.mp3  type mpegvideo alias BGM", NULL, 0, NULL);
	mciSendString("play BGM repeat", NULL, 0, NULL);

	//��Ϸ��ѭ��
	while (true)
	{
		BeginBatchDraw();
		DWORD start_time = GetTickCount();
		//��ȡ����
		peekmessage(&msg);
		view_manager.INPUT(msg);
	
		//��������,�����߼�
		view_manager.UPDATE();

		//���ƻ���
		cleardevice();
		view_manager.DRAW();
		FlushBatchDraw();

		//����֡��
		DWORD end_time = GetTickCount();
		DWORD delete_time = end_time - start_time;
		if (delete_time < 1000 / 90)
		{
			Sleep(1000 / 90 - delete_time);
		}	
	}
	//�ͷ���Դ
	EndBatchDraw();
	return 0;
}