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
		//初始化敌方攻击，血量，速度等属性  player_plane_1.png  enemy_plane_2.png
		//对敌方飞行方向进行初始化(方向朝向 自身刚刷新时 玩家的所在位置)
	
	~Enemy_Plane() = default;
	enum enemy_type {
		EnemyA,
		EnemyB,
		EnemyC
	};
	enemy_type m_type;
	std::vector<Bullet*> m_bullets_E;
	int m_attack;		//飞机子弹伤害
	int m_bullet_speed;	//飞机子弹速度
	int img_w, img_h;	//飞机素材长宽
	int m_w, m_h;		//飞机长宽(检测逻辑使用)
	float m_x, m_y;		//飞机坐标
	int x_speed;		//飞机速度
	int y_speed;		//飞机速度
	int m_hp;			//飞机血量
	bool isAlive;		//飞机存活状态
	virtual void UPDATE(int x,int y) {};
	virtual void DRAW() {};
	virtual void initPosition() {};	
	virtual void shoot() {};
	virtual void move() {};				//移动逻辑
	virtual void addBullet() {};		//发射子弹逻辑
	bool getbulletEmpty() {
		return m_bullets_E.empty() ? true : false;
	}
	void takeDamage(int damage) {		//扣除HP
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
	bool ismove;				//用于飞机c移动逻辑,是否移动
	int X;						//用于飞机c移动逻辑,最终目标位置
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