#pragma once
#include "Plane.h"
#include "bullet.h"
#include "view.h"
#include <iostream>
#include "GameView_INF.h"
#include <vector>
#include <random>
class Enemy_Plane 
{
public:
	Enemy_Plane()= default;
		//��ʼ���з�������Ѫ�����ٶȵ�����  player_plane_1.png  enemy_plane_2.png
		//�Եз����з�����г�ʼ��(������ �����ˢ��ʱ ��ҵ�����λ��)
	
	~Enemy_Plane() = default;
	enum enemy_type {
		EnemyA,
		EnemyB,
		EnemyC
	};
	enemy_type m_type;
	std::vector<Bullet*> m_bullets_E;
	int m_attack;		//�ɻ��ӵ��˺�
	int m_bullet_speed;	//�ɻ��ӵ��ٶ�
	int img_w, img_h;	//�ɻ��زĳ���
	int m_w, m_h;		//�ɻ�����(����߼�ʹ��)
	float m_x, m_y;		//�ɻ�����
	int x_speed;		//�ɻ��ٶ�
	int y_speed;		//�ɻ��ٶ�
	int m_hp;			//�ɻ�Ѫ��
	bool isAlive;		//�ɻ����״̬
	virtual void UPDATE(int x,int y) {};
	virtual void DRAW() {};
	virtual void initPosition() {};	
	virtual void shoot() {};
	virtual void move() {};				//�ƶ��߼�
	virtual void addBullet() {};		//�����ӵ��߼�
	bool getbulletEmpty() {
		return m_bullets_E.empty() ? true : false;
	}
	void takeDamage(int damage) {		//�۳�HP
		m_hp -= damage;
		if (m_hp <= 0) {
			isAlive = false;
		}
	};
	bool isDie_E() {
		return m_hp <= 0 ? true : false;
	};
	std::vector<Bullet*>& getBullets() {
		return m_bullets_E;
	};
	int getX() {
		return m_x;
	}
	int getY() {
		return m_y;
	}
	int getW() {
		return m_w;
	}
	int getH() {
		return m_h;
	}
};

//--------------------Enemy_PlaneA--------------------

class Enemy_PlaneA :public Enemy_Plane
{
public:
	Enemy_PlaneA();
	~Enemy_PlaneA();
	IMAGE enemy_plane_1;

	void UPDATE(int x, int y);
	void DRAW();
	void initPosition();
	void addBullet();
	void move(int x, int y);
	int getPositionX() {
		return m_x;
	}
	int getPositionY() {
		return m_y;
	}

};
//--------------------Enemy_PlaneA--------------------

//--------------------Enemy_PlaneB--------------------
class Enemy_PlaneB :public Enemy_Plane
{
public:
	Enemy_PlaneB();
	~Enemy_PlaneB();
	IMAGE enemy_plane_2;

	void UPDATE(int x, int y);
	void DRAW();
	void initPosition();
	bool ColliderWithPlayer(int x, int y);
	void move(int x, int y);
	int getPositionX() {
		return m_x;
	}
	int getPositionY() {
		return m_y;
	}

};
//--------------------Enemy_PlaneB--------------------

//--------------------Enemy_PlaneC--------------------
class Enemy_PlaneC :public Enemy_Plane
{
public:
	Enemy_PlaneC();
	~Enemy_PlaneC();
	IMAGE enemy_plane_3;
	bool ismove;				//���ڷɻ�c�ƶ��߼�,�Ƿ��ƶ�
	int X;						//���ڷɻ�c�ƶ��߼�,����Ŀ��λ��
	void UPDATE(int x, int y);
	void addBullet(int x, int y);
	void DRAW();
	void initPosition();
	bool ColliderWithPlayer(int x, int y);
	void move(int x, int y);
	int getPositionX() {
		return m_x;
	}
	int getPositionY() {
		return m_y;
	}

};
//--------------------Enemy_PlaneC--------------------