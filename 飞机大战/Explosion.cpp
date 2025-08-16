#include "Explosion.h"

std::vector<Explosion*> Explosion::m_explosions;
std::vector<Explosion*> Explosion::m_explosionOfB;

void Explosion::BulletExplosionUpdate() {	//ÿ���ӵ���ը�ĸ��£����ⲿ�������飩
	if (ExplosionisTrigger && deltaCounts <= 30) {// && deltaCounts <= 60
		deltaCounts++;
		Draw();
	}
	else if (ExplosionisTrigger && deltaCounts > 30) {
		isEnd = true;
	}
}

void Explosion::EnemyExplosionUpdate() {	//ÿ�����˱�ը�ĸ��£����ⲿ�������飩
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
	putimage_new(m_x - 60, m_y - 40, &explosionOfB);		//������
}

void Explosion::addBulletExplosion(Bullet* Bullet) {	//�ӵ���ը
	m_explosions.push_back(new Explosion(Bullet->m_x + 20, Bullet->m_y));
};

void Explosion::addEnemyExplosion(int x, int y) {//EnemyPlaneB��ը
	m_explosionOfB.push_back(new Explosion(x + 20, y));
};

void Explosion::BulletExploding() {
	//���±�ը
	for (auto it = m_explosions.begin(); it != m_explosions.end(); ++it) {
		Explosion* explosion = *it;
		explosion->BulletExplosionUpdate();
	}
}

void Explosion::EnemyExploding() {
	//���±�ը
	for (auto it = m_explosionOfB.begin(); it != m_explosionOfB.end(); ++it) {
		Explosion* explosion = *it;
		explosion->EnemyExplosionUpdate();
	}
}

void Explosion::clearExplosion() {
	//��ⱬը�Ƿ����
	for (auto it = m_explosions.begin(); it != m_explosions.end(); ) {
		Explosion* explosion = *it;
		if (explosion->isEnd) {
			delete explosion;  // �ͷű�ը����
			it = m_explosions.erase(it);  // ɾ��Ԫ�ز�������һ����Ч������
		}
		else {
			++it;  // �ƶ�����һ��Ԫ��
		}
	}
}
