#pragma once
#include <graphics.h>
#include <iostream>
#include "bullet.h"


class Plane
{
public:


	//��Ա����
	int m_attack;		//�ɻ��˺�
	int m_x, m_y;		//�ɻ�����
	int m_speed;		//�ɻ��ٶ�
	int m_hp;			//�ɻ�Ѫ��

	//��Ա����
	virtual void UPDATE() {
		//
	};
	virtual void DRAW() {
		//���Ʒɻ�
	};
	virtual void initPosition() {
		//��ʼ��λ��
	};
	void shoot() {
		//���
	}
	int getPositionX() {
		return m_x;
	}
	int getPositionY() {
		return m_y;
	}

};