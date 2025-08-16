#pragma once
#include <graphics.h>
#include <iostream>
#include "bullet.h"


class Plane
{
public:


	//成员属性
	int m_attack;		//飞机伤害
	int m_x, m_y;		//飞机坐标
	int m_speed;		//飞机速度
	int m_hp;			//飞机血量

	//成员函数
	virtual void UPDATE() {
		//
	};
	virtual void DRAW() {
		//绘制飞机
	};
	virtual void initPosition() {
		//初始化位置
	};
	void shoot() {
		//射击
	}
	int getPositionX() {
		return m_x;
	}
	int getPositionY() {
		return m_y;
	}

};