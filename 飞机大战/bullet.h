#pragma once
#include <graphics.h>
#include <iostream>
#include <math.h>

class Enemy_Plane;  // ǰ������
class Player_plane;	// ǰ������
class Bullet
{
public:
	enum directions {
		Left,
		Middle,
		Right
	};
	directions bulletDirection;

	enum playerPlaneBullet {
		Enemy1,
		Enemy3,
		PlayerA,
		PlayerB,
		PlayerC1,
		PlayerC2,
		PlayerC3,
	};
	playerPlaneBullet bullettype;
	//����ӵ���ʼ��
	Bullet(playerPlaneBullet bulletType, int attack, int speed, int x, int y, directions dir) {
		bullettype = bulletType;
		//��ʼ���ӵ�λ��,�˺�,�ٶ�
		m_x = x, m_y = y;
		m_damage = attack;
		m_speed = speed;
		bulletDirection = dir;
		loadimage(&bullet1, "../Asset/bullet/bullet_1.png", 8, 8);
		loadimage(&bullet2, "../Asset/bullet/bullet_4.png", 8, 8);
		loadimage(&PlaneB_Bullet, "../Asset/bullet/bullet_5.png", 6, 6);
		loadimage(&PlaneC_Bullet1, "../Asset/bullet/bullet_7.png", 16, 16);
		loadimage(&PlaneC_Bullet2, "../Asset/bullet/bullet_7.png", 44, 44);
		loadimage(&PlaneC_Bullet3, "../Asset/bullet/bullet_7.png", 72, 72);
	}
	Bullet(playerPlaneBullet bulletType, int attack, int speed, int x, int y, int Player_x, int Player_y) {
		bullettype = bulletType;
		//��ʼ���ӵ�λ��,�˺�,�ٶ�
		m_x = x, m_y = y;
		fm_x = x, fm_y = y;
		m_speed = speed;
		m_damage = attack;
		precise1Count = 0;
		precise2Count = 0;
		speed_x = getXSpeed(Player_x, Player_y);
		speed_y = getYSpeed(Player_x, Player_y);
		loadimage(&bullet3, "../Asset/bullet/bullet_3.png", 48, 48);
	}
	~Bullet() = default;

	IMAGE bullet1, bullet2,bullet3;
	IMAGE PlaneB_Bullet;
	IMAGE PlaneC_Bullet1, PlaneC_Bullet2, PlaneC_Bullet3;
	
	bool checkCollisionE(Enemy_Plane& enemy);
	bool checkCollisionP(Player_plane& enemy);
	
	int getDamage()const;	//��ȡ�ӵ��˺�
	void move();			//�ɻ�A/B�ӵ��ƶ�
	void movePlayerB_L();	//�ɻ�B����ӵ��ƶ�
	void movePlayerB_M();	//�ɻ�B�м��ӵ��ƶ�
	void movePlayerB_R();	//�ɻ�B�Ҳ��ӵ��ƶ�
	bool check_outscreen();				//����ӵ��Ƿ�ɳ���Ļ��
	void UPDATA();						//�ӵ������߼�
	void DRAW();						//�����ӵ�
	float getXSpeed(int p_x, int p_y);
	float getYSpeed(int p_x, int p_y);


	int m_x, m_y;			//�ӵ�����
	int m_w, m_h;			//�ӵ�����
	int m_damage;			//�ӵ��˺�
	int m_speed;			//�ӵ��ٶ�
	bool m_remove = false;	//�ӵ��Ƿ���Ա�ɾ��
	int precise1Count;		//�ӵ���ȷ�Ȼ���(����3�Σ���3֡)
	int precise2Count;		//�ӵ���ȷ�Ȼ���(����6�Σ����ڴ���Ƕȹ�С�����)
	float fm_x, fm_y;		//�ӵ���ȷ����
	float speed_x, speed_y;	//�������
};