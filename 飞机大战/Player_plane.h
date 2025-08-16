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
	int m_attack;		//飞机子弹伤害
	int m_bullet_speed;	//飞机子弹速度
	int img_w, img_h;	//飞机素材长宽
	int m_w, m_h;		//飞机长宽(检测逻辑使用)
	float m_x, m_y;		//飞机坐标
	int m_speed;		//飞机速度
	int m_hp;			//飞机血量

	//玩家飞机的行为
	virtual void initPlayer() {};		//初始化玩家属性
	virtual void UPDATE() {};			//飞机A/B更新逻辑
	virtual void UPDATE(int& power) {};	//飞机C更新逻辑
	virtual void shoot(int& power) {};	//飞机C射击逻辑
	//绘制飞机
	virtual void DRAW() {};
	virtual void addBullet() {};
	virtual void addLBullet() {};	//绘制飞机B左子弹
	virtual void addMBullet() {};	//绘制飞机B中子弹
	virtual void addRBullet() {};	//绘制飞机B右子弹
	bool isDie_P() {				//检测是否死亡
		return m_hp <= 0 ? true : false;
	}
	void takeDamage(int damage) {	//扣除HP
		m_hp -= damage;
	};
	std::vector<Bullet*>& getBullets() {
		return m_bullets;
	};  // 返回子弹列表的引用
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