#pragma once
#include "Bullet.h"
#include "view.h"
#include <graphics.h>
#include <iostream>
#include <vector>

class Explosion
{
public:
	Explosion(int x, int y) {
		deltaCounts = 0;
		ExplosionisTrigger = true;
		isEnd = false;
		m_x = x;
		m_y = y;
		loadimage(&explosion1, "../Asset/Explosion/Explosion1.png", 30, 30);
		loadimage(&explosionOfB, "../Asset/Explosion/Explosion1.png", 80, 80);
	}
	~Explosion() {
	
	}

	IMAGE explosion1;
	IMAGE explosionOfB;
	int m_x, m_y;
	int deltaCounts;
	bool ExplosionisTrigger;
	bool isEnd;
	static std::vector<Explosion*> m_explosions;
	static std::vector<Explosion*> m_explosionOfB;

	void BulletExplosionUpdate();
	void EnemyExplosionUpdate();
	void Draw();
	void DrawEnemyExplosion();
	static void addBulletExplosion(Bullet* Bullet);
	static void addEnemyExplosion(int x, int y);
	static void BulletExploding();				//供外部 UPDATE() 调用
	static void EnemyExploding();				//供外部 UPDATE() 调用
	static void clearExplosion();				//供外部 UPDATE() 调用

};