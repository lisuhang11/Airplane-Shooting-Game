#pragma once
#include <graphics.h>
#include <iostream>
#include <math.h>

class Enemy_Plane;  // 前向声明
class Player_plane;	// 前向声明
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
	//玩家子弹初始化
	Bullet(playerPlaneBullet bulletType, int attack, int speed, int x, int y, directions dir) {
		bullettype = bulletType;
		//初始化子弹位置,伤害,速度
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
		//初始化子弹位置,伤害,速度
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
	
	int getDamage()const;	//获取子弹伤害
	void move();			//飞机A/B子弹移动
	void movePlayerB_L();	//飞机B左测子弹移动
	void movePlayerB_M();	//飞机B中间子弹移动
	void movePlayerB_R();	//飞机B右侧子弹移动
	bool check_outscreen();				//检测子弹是否飞出屏幕外
	void UPDATA();						//子弹更新逻辑
	void DRAW();						//绘制子弹
	float getXSpeed(int p_x, int p_y);
	float getYSpeed(int p_x, int p_y);


	int m_x, m_y;			//子弹坐标
	int m_w, m_h;			//子弹长宽
	int m_damage;			//子弹伤害
	int m_speed;			//子弹速度
	bool m_remove = false;	//子弹是否可以被删除
	int precise1Count;		//子弹精确度积攒(积攒3次，即3帧)
	int precise2Count;		//子弹精确度积攒(积攒6次，用于处理角度过小的情况)
	float fm_x, fm_y;		//子弹精确坐标
	float speed_x, speed_y;	//玩家坐标
};