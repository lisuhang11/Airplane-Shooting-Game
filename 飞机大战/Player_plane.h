#pragma once
#include "bullet.h"
#include "GameView_INF.h"
#include<vector>
extern ViewManager view_manager;
class Player_plane
{
public:
	Player_plane() = default;
	~Player_plane() = default;

	enum player_type {
		PlayerA,
		PlayerB,
		PlayerC
	};
	player_type m_type;

	IMAGE planeIMG;
	std::vector<Bullet*> m_bullets;
	std::vector<Bullet*> m_Lbullets;
	std::vector<Bullet*> m_Rbullets;
	int m_attack;		//�ɻ��ӵ��˺�
	int m_bullet_speed;	//�ɻ��ӵ��ٶ�
	int img_w, img_h;	//�ɻ��زĳ���
	int m_w, m_h;		//�ɻ�����(����߼�ʹ��)
	float m_x, m_y;		//�ɻ�����
	int m_speed;		//�ɻ��ٶ�
	int m_hp;			//�ɻ�Ѫ��

	//��ҷɻ�����Ϊ
	virtual void initPlayer() {};		//��ʼ���������
	virtual void UPDATE() {};			//�ɻ�A/B�����߼�
	virtual void UPDATE(int& power) {};	//�ɻ�C�����߼�
	virtual void shoot(int& power) {};	//�ɻ�C����߼�
	//���Ʒɻ�
	virtual void DRAW() {};
	virtual void addBullet() {};
	virtual void addLBullet() {};	//���Ʒɻ�B���ӵ�
	virtual void addMBullet() {};	//���Ʒɻ�B���ӵ�
	virtual void addRBullet() {};	//���Ʒɻ�B���ӵ�
	bool isDie_P() {				//����Ƿ�����
		return m_hp <= 0 ? true : false;
	}
	void takeDamage(int damage) {	//�۳�HP
		m_hp -= damage;
	};
	std::vector<Bullet*>& getBullets() {
		return m_bullets;
	};  // �����ӵ��б������
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

//--------------------Player_PlaneA--------------------
class Player_planeA :public Player_plane
{
public:
	Player_planeA();
	~Player_planeA();
	void initPlayer();
	void UPDATE();
	void DRAW();
	void addBullet();
	int getPositionX() {
		return m_x;
	}
	int getPositionY() {
		return m_y;
	}
};
//--------------------Player_PlaneA--------------------


//--------------------Player_PlaneB--------------------
class Player_planeB :public Player_plane
{
public:
	Player_planeB();
	~Player_planeB();
	void initPlayer();
	void UPDATE();
	void DRAW();
	void addLBullet();
	void addMBullet();
	void addRBullet();
	int getPositionX() {
		return m_x;
	}
	int getPositionY() {
		return m_y;
	}
};
//--------------------Player_PlaneB--------------------


//--------------------Player_PlaneC--------------------
class Player_planeC :public Player_plane
{
public:
	Player_planeC();
	~Player_planeC();
	void initPlayer();
	void UPDATE(int& power);
	void DRAW();
	void shoot(int& power);
	void addBullet(int& power);
	int getPositionX() {
		return m_x;
	}
	int getPositionY() {
		return m_y;
	}
};
//--------------------Player_PlaneC--------------------