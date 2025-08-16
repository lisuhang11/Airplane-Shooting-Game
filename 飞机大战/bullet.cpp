#include "bullet.h"
#include "Enemy_Plane.h"
#include "Player_plane.h"


//获取伤害
int Bullet::getDamage() const {
	return m_damage;
}
//子弹移动
void Bullet::move() {
	//玩家子弹向前发射,y-
	if (bullettype != Bullet::Enemy1)m_y -= m_speed;
	else if (bullettype == Bullet::Enemy1) {
		m_y += m_speed;
	}
	if (bullettype == Bullet::Enemy3) {
		if (abs(speed_x) > 0.34f && abs(speed_y) > 0.34f) {	
			precise1Count++;
			fm_y += speed_y;
			fm_x += speed_x;
			if (precise1Count >= 3) {
				m_y = (int)fm_y;
				m_x = (int)fm_x;
				precise1Count = 0;
			}
		}
		else if (abs(speed_x) < 0.34f) {	//横向精度
			precise1Count++;
			precise2Count++;
			fm_x += speed_x;
			fm_y += speed_y;
			if (precise1Count >= 1) {
				m_y = (int)fm_y;
				precise1Count = 0;
			}
			if (precise2Count >= 6) {
				m_x = ceil(fm_x);
				precise2Count = 0;
			}
		}
		else if (abs(speed_y) < 0.34f) {	//纵向精度
			precise1Count++;
			precise2Count++;
			fm_x += speed_x;
			fm_y += speed_y;
			if (precise1Count >= 3) {
				m_x = (int)fm_x;
				precise1Count = 0;
			}
			if (precise2Count >= 6) {
				m_y = ceil(fm_y);
				precise2Count = 0;
			}
		}
		else if (speed_x == 0) {
			fm_y += speed_y;
			m_y = (int)fm_y;
		}
		else if (speed_y == 0) {
			fm_x += speed_x;
			m_x = (int)fm_x;
		}
	}
}
void Bullet::movePlayerB_L() {
	m_x -= m_speed / 2;
	m_y -= m_speed;
}
void Bullet::movePlayerB_M() {
	m_y -= m_speed;
}
void Bullet::movePlayerB_R() {
	m_x += m_speed / 2;
	m_y -= m_speed;
}
//检测碰撞,对敌人
bool Bullet::checkCollisionE(Enemy_Plane& enemy) {
	bool ans;
	if (bullettype == Bullet::PlayerA || bullettype == Bullet::PlayerB) {
		ans = m_x < enemy.getX() + enemy.getW() / 2 &&
			m_x > enemy.getX() - enemy.getW() / 2 &&
			m_y < enemy.getY() + enemy.getH() / 2 &&
			m_y> enemy.getY() - enemy.getH() / 2;
	}
	else if (bullettype == Bullet::PlayerC1) {
		ans = m_x - 8 < enemy.getX() + enemy.getW() / 2 &&
			m_x + 8 > enemy.getX() - enemy.getW() / 2 &&
			m_y - 8 < enemy.getY() + enemy.getH() / 2 &&
			m_y + 8 > enemy.getY() - enemy.getH() / 2;
	}
	else if (bullettype == Bullet::PlayerC2) {
		ans = m_x - 22 < enemy.getX() + enemy.getW() / 2 &&
			m_x + 22 > enemy.getX() - enemy.getW() / 2 &&
			m_y - 22 < enemy.getY() + enemy.getH() / 2 &&
			m_y + 22 > enemy.getY() - enemy.getH() / 2;
	}
	else if (bullettype == Bullet::PlayerC3) {
		ans = m_x - 36 < enemy.getX() + enemy.getW() / 2 &&
			m_x + 36 > enemy.getX() - enemy.getW() / 2 &&
			m_y - 36 < enemy.getY() + enemy.getH() / 2 &&
			m_y + 36 > enemy.getY() - enemy.getH() / 2;
	}
	return ans;
};
//检测碰撞,对玩家
bool Bullet::checkCollisionP(Player_plane& player) {
	return (m_x - 12 < player.getX() + player.getW() / 2 &&
		m_x + 12 > player.getX() - player.getW() / 2 &&
		m_y - 12 < player.getY() + player.getH() / 2 &&
		m_y + 12 >player.getY() - player.getH() / 2);
};
//检测子弹是否飞出屏幕外
bool Bullet::check_outscreen() {
	return (m_y > 960 || m_y  < 0 || m_x > 640 || m_x < 0);
}
//子弹逻辑
void Bullet::UPDATA() {

}
//绘制子弹
void Bullet::DRAW() {
	if (bullettype == Bullet::PlayerA) {					//玩家A子弹
		putimage_new(m_x - 4, m_y - 20, &bullet1);
	}
	else if (bullettype == Bullet::PlayerB) {				//玩家B子弹
		putimage_new(m_x - 3, m_y - 20, &PlaneB_Bullet);
	}
	else if (bullettype == Bullet::PlayerC1) {				//玩家C子弹
		putimage_new(m_x - 8, m_y - 8, &PlaneC_Bullet1);
	}
	else if (bullettype == Bullet::PlayerC2) {
		putimage_new(m_x - 22, m_y - 20, &PlaneC_Bullet2);
	}
	else if (bullettype == Bullet::PlayerC3) {
		putimage_new(m_x - 36, m_y - 20, &PlaneC_Bullet3);
	}
	else if (bullettype == Bullet::Enemy1) {
		putimage_new(m_x - 4, m_y + 20, &bullet2);			//敌人A子弹
	}
	else if (bullettype == Bullet::Enemy3) {
		putimage(m_x - 24, m_y + 20, &bullet3);				//敌人C子弹
	}
}
float Bullet::getXSpeed(int p_x, int p_y) {
	if ((p_x - m_x) == 0)
		return 0;
	return ((float)m_speed * (p_x - m_x) / (float)sqrt((p_x - m_x) * (p_x - m_x) + (p_y - m_y) * (p_y - m_y)));
}
float Bullet::getYSpeed(int p_x, int p_y) {
	if ((p_y - m_y) == 0)
		return 0;
	return ((float)m_speed * (p_y - m_y) / (float)sqrt((p_x - m_x) * (p_x - m_x) + (p_y - m_y) * (p_y - m_y)));
}
