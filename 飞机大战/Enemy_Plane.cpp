#include "Enemy_Plane.h"

//------------------------------Enemy_PlaneA------------------------------//
Enemy_PlaneA::Enemy_PlaneA() {
	//初始化敌人位置
	Enemy_PlaneA::initPosition();
	m_bullets_E.clear();
	//初始化敌人属性
	m_attack = 7; m_hp = 35; ; m_bullet_speed = 7; m_w = 70; m_h = 40; img_w = 70, img_h = 60;
	//初始化敌人横纵方向的速度
	x_speed = rand() % 3+1;y_speed = rand() % 2+1;
	//标记敌人类型
	m_type = Enemy_Plane::EnemyA;
	//记录敌人是否死亡
	isAlive = true;
	//刷新位置
	Enemy_PlaneA::initPosition(); 
	//加载资源
	loadimage(&enemy_plane_1, "../Asset/plane/enemy_plane_1.png", 70, 60);
}
Enemy_PlaneA::~Enemy_PlaneA() {
	// 释放子弹占用的内存
	for (auto bullet : m_bullets_E) {
		delete bullet;  
	}
	m_bullets_E.clear();
}

void  Enemy_PlaneA::UPDATE(int x ,int y) {
	//子弹自动发射
	if(isAlive)Enemy_PlaneA::addBullet();
	//移动(获取玩家位置,位置随玩家移动)
	if (isAlive)Enemy_PlaneA::move(x,y);
	//敌人死亡,将他放到屏幕外的位置,避免碰撞检测
	if (!isAlive)m_x = -500, m_y = -500;
	//检测是否飞出屏幕外,更新子弹位置
	for (auto it = Enemy_PlaneA::m_bullets_E.begin(); it != Enemy_PlaneA::m_bullets_E.end(); ) {
		Bullet* bullet_e = *it;
		bullet_e->move();
		if (bullet_e->check_outscreen()) {	// 删除飞出屏幕外的子弹
			delete bullet_e;				// 释放子弹对象
			it = Enemy_PlaneA::m_bullets_E.erase(it);  // 删除元素并返回下一个有效迭代器
		}
		else {
			++it;  // 移动到下一个元素
		}
	}
};

void Enemy_PlaneA::DRAW() {
	//绘制飞机
	putimage_new(m_x - img_w / 2, m_y - img_h / 2, &enemy_plane_1);
	//绘制子弹
	for (Bullet* bullet : Enemy_PlaneA::m_bullets_E)	
	{
		bullet->DRAW();
	}
};

void Enemy_PlaneA::initPosition() {
	//随机位置刷新
	int boundary = rand() % 3;

	if (boundary == 0) {			//上
		m_x = rand() % 640;
		m_y = -20;					//初始y坐标设为-20，使其在屏幕上方
	}
	else if (boundary == 1) {		//左
		m_x = -20;					//初始x坐标设为-20，使其在屏幕左侧
		m_y = rand() % 380;
	}
	else {							//右边
		m_x = 630;					//初始x坐标设为660，使其在屏幕右侧
		m_y = rand() % 380;
	}
};

void Enemy_PlaneA::addBullet() {
	//实例化子弹
	if (GameView_INF::counter % 25 == 0)
	{
		m_bullets_E.push_back(new Bullet(Bullet::Enemy1, m_attack, m_bullet_speed, m_x, m_y, Bullet::Middle));//ture:玩家,false:敌人
	}
};

void Enemy_PlaneA::move(int x, int y) {
	// 更新纵坐标，使其在0到400之间反复运动
	m_y += y_speed;
	if (m_y < -20 || m_y > 400) {
		y_speed = -y_speed;  // 反向移动
	}
	// 更新横坐标，使其朝着玩家的横坐标方向移动
	if (m_x < x) {
		m_x += x_speed;
	}
	else if (m_x> x) {
		m_x -= x_speed;
	}
};

//------------------------------Enemy_PlaneA------------------------------//


//------------------------------Enemy_PlaneB------------------------------//
Enemy_PlaneB::Enemy_PlaneB() {
	Enemy_PlaneB::initPosition();
	m_bullets_E.clear();
	m_attack = 30;m_hp = 10; m_w = 70; m_h = 40; img_w = 70, img_h = 60;
	x_speed = 6;y_speed = 6;
	isAlive = true;
	m_type = Enemy_Plane::EnemyB;
	loadimage(&enemy_plane_2, "../Asset/plane/enemy_plane_2.png", 60, 50);
}
Enemy_PlaneB::~Enemy_PlaneB() {

}

void  Enemy_PlaneB::UPDATE(int x, int y) {
	if (isAlive)
		Enemy_PlaneB::move(x, y);
	if (!isAlive)
		m_x = -500, m_y = -500;
};

void Enemy_PlaneB::DRAW() {
	putimage_new(m_x - img_w / 2, m_y - img_h / 2, &enemy_plane_2);
};

void Enemy_PlaneB::initPosition() {
	//随机位置刷新
	int boundary = rand() % 3;
	if (boundary == 0) {			//上
		m_x = rand() % 640;
		m_y = -20;					
	}
	else if (boundary == 1) {		//左
		m_x = -20;					 
		m_y = rand() % 380;
	}
	else {							//右
		m_x = 630;					
		m_y = rand() % 380;
	}
};

bool Enemy_PlaneB::ColliderWithPlayer(int x, int y) {
	//实现碰撞
	return (m_x < x + 40 / 2 &&
		m_x > x - 40 / 2 &&
		m_y < y + 30 / 2 &&
		m_y> y - 30 / 2);
};

void Enemy_PlaneB::move(int x, int y) {
	//跟随玩家移动
	if (m_y < y) {
		m_y += y_speed;
	}
	else if (m_y > y) {
		m_y -= y_speed;
	}
	else {
		m_y -= 0;
	}
	// 更新横坐标，使其朝着玩家的横坐标方向移动
	if (m_x < x) {
		m_x += x_speed;
	}
	else if (m_x > x) {
		m_x -= x_speed;
	}
};
//------------------------------Enemy_PlaneB------------------------------//

//------------------------------Enemy_PlaneC------------------------------//
Enemy_PlaneC::Enemy_PlaneC() {
	Enemy_PlaneC::initPosition();
	m_bullets_E.clear();
	m_attack = 50;m_hp = 150; m_w = 70; m_h = 40; img_w = 140, img_h = 120;
	m_bullet_speed = 7;
	x_speed = 2;y_speed = 2;
	m_type = Enemy_Plane::EnemyC;
	isAlive = true;
	Enemy_PlaneC::initPosition();
	loadimage(&enemy_plane_3, "../Asset/plane/enemy_plane_3.png", img_w, img_h);
}
Enemy_PlaneC::~Enemy_PlaneC() {
	for (auto bullet : m_bullets_E) {
		delete bullet;  
	}
	m_bullets_E.clear();
}
void  Enemy_PlaneC::UPDATE(int x, int y) {
	if (isAlive)Enemy_PlaneC::addBullet(x, y);
	if (isAlive)Enemy_PlaneC::move(x,y);
	if (!isAlive) {
			m_x = -500, m_y = -500;
	}
	for (auto it = Enemy_PlaneC::m_bullets_E.begin(); it != Enemy_PlaneC::m_bullets_E.end(); ) {
		Bullet* bullet_e = *it;
		bullet_e->move();
		if (bullet_e->check_outscreen()) {
			delete bullet_e;  
			it = Enemy_PlaneC::m_bullets_E.erase(it); 
		}
		else {
			++it;  
		}
	}
};
void Enemy_PlaneC::addBullet(int x, int y) {
	if (GameView_INF::counter % 80 == 5)
	{
		m_bullets_E.push_back(new Bullet(Bullet::Enemy3, m_attack, m_bullet_speed, m_x, m_y, x, y));//ture:玩家,false:敌人
	}
};
void Enemy_PlaneC::DRAW() {
	putimage_new(m_x - img_w / 2, m_y - img_h / 2, &enemy_plane_3);
	for (Bullet* bullet : Enemy_PlaneC::m_bullets_E)	
	{
		bullet->DRAW();
	}
};
void Enemy_PlaneC::initPosition() {
	int boundary = rand() % 2;
	if (boundary == 0) {			//右
		m_x = 660;					
		m_y = rand() % 250 +80;
		ismove = false;
	}
	else if (boundary == 1) {		 //左
		m_x = -20;					 
		m_y = rand() % 250+80;
		ismove = true;
	}
	X = rand() % 500 + 100;
};
void Enemy_PlaneC::move(int x, int y) {
	if (m_x < X&& ismove) {
		m_x += x_speed;
	}
	else if (m_x > X&&!ismove) {
		m_x -= x_speed;
	}
};
//------------------------------Enemy_PlaneC------------------------------//
