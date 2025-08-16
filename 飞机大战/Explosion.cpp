#include "Explosion.h"

std::vector<Explosion*> Explosion::m_explosions;
std::vector<Explosion*> Explosion::m_explosionOfB;

void Explosion::BulletExplosionUpdate() {	//每个子弹爆炸的更新（在外部遍历数组）
	if (ExplosionisTrigger && deltaCounts <= 30) {// && deltaCounts <= 60
		deltaCounts++;
		Draw();
	}
	else if (ExplosionisTrigger && deltaCounts > 30) {
		isEnd = true;
	}
}

void Explosion::EnemyExplosionUpdate() {	//每个敌人爆炸的更新（在外部遍历数组）
	if (ExplosionisTrigger && deltaCounts <= 60) {// && deltaCounts <= 60
		deltaCounts++;
		DrawEnemyExplosion();
	}
	else if (ExplosionisTrigger && deltaCounts > 60) {
		isEnd = true;
	}
}

void Explosion::Draw() {
	putimage_new(m_x - 35, m_y - 10, &explosion1);
}

void Explosion::DrawEnemyExplosion() {
	putimage_new(m_x - 60, m_y - 40, &explosionOfB);		//调试用
}

void Explosion::addBulletExplosion(Bullet* Bullet) {	//子弹爆炸
	m_explosions.push_back(new Explosion(Bullet->m_x + 20, Bullet->m_y));
};

void Explosion::addEnemyExplosion(int x, int y) {//EnemyPlaneB爆炸
	m_explosionOfB.push_back(new Explosion(x + 20, y));
};

void Explosion::BulletExploding() {
	//更新爆炸
	for (auto it = m_explosions.begin(); it != m_explosions.end(); ++it) {
		Explosion* explosion = *it;
		explosion->BulletExplosionUpdate();
	}
}

void Explosion::EnemyExploding() {
	//更新爆炸
	for (auto it = m_explosionOfB.begin(); it != m_explosionOfB.end(); ++it) {
		Explosion* explosion = *it;
		explosion->EnemyExplosionUpdate();
	}
}

void Explosion::clearExplosion() {
	//检测爆炸是否结束
	for (auto it = m_explosions.begin(); it != m_explosions.end(); ) {
		Explosion* explosion = *it;
		if (explosion->isEnd) {
			delete explosion;  // 释放爆炸对象
			it = m_explosions.erase(it);  // 删除元素并返回下一个有效迭代器
		}
		else {
			++it;  // 移动到下一个元素
		}
	}
}
