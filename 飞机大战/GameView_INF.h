//�޾�ģʽ��Ϸ����
#pragma once
#include "view.h"
#include "ViewManager.h"
#include <vector>
#include "Enemy_Plane.h"
#include "Player_plane.h"
#include <iostream>
#include <mmsystem.h>
#include <string>
#include "Explosion.h"
class Player_plane;//��ǰ����
class Enemy_Plane;
class Enemy_PlaneB;
class Enemy_PlaneC;
extern Player_plane*player;
extern ViewManager view_manager;

class GameView_INF :public view
{
public:
	//1.������Ϸ������ز�  
	//2.��ʼ����Ϸ�������� ����
	GameView_INF() {
		loadimage(&gameview, "../Asset/backgroud/gameview.png", 640, 960);
		loadimage(&HP1, "../Asset/HP/hp1.png", 20, 320);
		loadimage(&introduce1, "../Asset/backgroud/introduce1.png", 300, 375);
		loadimage(&introduce2, "../Asset/backgroud/introduce2.png", 300, 375);
		loadimage(&introduce3, "../Asset/backgroud/introduce3.png", 300, 375);
	};

	//�ͷŵ����� ���
	~GameView_INF() {
		//�ͷ������
		if (player) {
			delete player;
		}
	};
	IMAGE gameview,HP1,HP2, introduce1, introduce2, introduce3;
	static std::vector<Enemy_Plane*> enemy_listA;
	static std::vector<Enemy_PlaneB*> enemy_listB;
	static std::vector<Enemy_PlaneC*> enemy_listC;
	static int counter ;	//��ʱ��,����ˢ��
	static int score;		//��Ϸ�÷�
	static int power;		//�ɻ�C����ֵ
	static int level;		//��¼��Ϸ�Ѷ�

	static bool move_is_up ;
	static bool move_is_down;
	static bool move_is_left ;
	static bool move_is_right ;
	static bool is_shoot;
	static int X;			//������Ϸ���ܿ��ƶ�
	void ENTER();
	//�޾�ģʽ��Ϸ���������߼�
		//*ˢ�µ��˷ɻ�
		//*���˷ɻ�����Ϊ
		//*��ҷɻ�����Ϊ
		//*��Ϸ״̬�ж�(����,��ͣ->��ѭ��,����)
		//*���ݸ���(�÷�,���,����)
	void UPDATE();
	void DRAW();
	void INPUT(ExMessage& msg);
	void EXIT();
	void PauseView(ExMessage& msg);		//��ͣ����
	void CheckCollisions();				//�ӵ���ײ
	void CheckEnemyBCollisions();		//���˷ɻ�B��ײ
	void EnemyDie();
};