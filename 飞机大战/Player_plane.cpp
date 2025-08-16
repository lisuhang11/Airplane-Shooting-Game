#include "Player_plane.h"

//--------------------Player_PlaneA--------------------
Player_planeA::Player_planeA()
{	//飞机初始化
	m_attack = 15; m_speed = 5; m_bullet_speed = 10;
	m_w = 40; m_h = 30; img_w = 60, img_h = 45;
	//表明飞机类型
	m_type = Player_planeA::PlayerA;
	//加载飞机素材
	loadimage(&planeIMG, "../Asset/plane/player_plane_1.png", img_w, img_h);
}
Player_planeA::~Player_planeA()
{
	//释放子弹数组
	for (Bullet* bullet : Player_planeA::m_bullets) {
		delete bullet;  // 删除每个指针指向的对象
	}
}
void Player_planeA::initPlayer() {
	//初始化玩家,血量,长宽
	m_x = 300; m_y = 750; m_hp = 200;

}
void Player_planeA::UPDATE() {
	//检测是否飞出屏幕外,更新子弹位置
	for (auto it = Player_planeA::m_bullets.begin(); it != Player_planeA::m_bullets.end(); ) {
		Bullet* bullet = *it;
		bullet->move();
		if (bullet->check_outscreen()) {
			// 删除飞出屏幕外的子弹
			delete bullet;  // 释放子弹对象
			it = Player_planeA::m_bullets.erase(it);  // 删除元素并返回下一个有效迭代器
		}
		else {
			++it;  // 移动到下一个元素
		}
	}
};
void Player_planeA::DRAW() {
	putimage_new(m_x - img_w / 2, m_y - img_h / 2, &planeIMG);		//绘制飞机
	for (Bullet* bullet : Player_planeA::m_bullets)					//绘制子弹
		bullet->DRAW();
};
void Player_planeA::addBullet() {
	//实例化子弹
	if (GameView_INF::counter % 10 == 5)
	{
		m_bullets.push_back(new Bullet(Bullet::PlayerA, m_attack, m_bullet_speed, m_x, m_y, Bullet::Middle));//ture:玩家,false:敌人

	}
};
//--------------------Player_PlaneA--------------------


//--------------------Player_PlaneB--------------------
Player_planeB::Player_planeB()
{
	m_attack = 8;m_speed = 5; m_bullet_speed = 10;
	m_w = 40; m_h = 30;img_w = 60, img_h = 45;
	m_type = Player_planeB::PlayerB;
	loadimage(&planeIMG, "../Asset/plane/player_plane_3.png", img_w, img_h);
}
Player_planeB::~Player_planeB()
{
	for (Bullet* bullet : Player_planeB::m_bullets) {
		delete bullet;  
	}
}
void Player_planeB::initPlayer() {
	m_x = 300; m_y = 750; m_hp = 200;

}
void Player_planeB::UPDATE() {
	for (auto it = Player_planeB::m_bullets.begin(); it != Player_planeB::m_bullets.end(); ) {
		Bullet* bullet = *it;
		if (bullet->bulletDirection == Bullet::Left)
			bullet->movePlayerB_L();
		else if (bullet->bulletDirection == Bullet::Middle)
			bullet->movePlayerB_M();
		else if (bullet->bulletDirection == Bullet::Right)
			bullet->movePlayerB_R();
		if (bullet->check_outscreen()) {
			delete bullet;
			it = Player_planeB::m_bullets.erase(it);
		}
		else {
			++it;
		}
	}
};
void Player_planeB::DRAW() {
	putimage_new(m_x - img_w / 2, m_y - img_h / 2, &planeIMG);
	for (Bullet* bullet : Player_planeB::m_bullets)
		bullet->DRAW();
};
void Player_planeB::addLBullet() {
	if (GameView_INF::counter % 7 == 5)
	{
		m_bullets.push_back(new Bullet(Bullet::PlayerB, m_attack, m_bullet_speed, m_x, m_y, Bullet::Left));//ture:玩家,false:敌人
	};
}
void Player_planeB::addMBullet() {
	if (GameView_INF::counter % 7 == 5)
	{
		m_bullets.push_back(new Bullet(Bullet::PlayerB, m_attack, m_bullet_speed, m_x, m_y, Bullet::Middle));//ture:玩家,false:敌人
	};
}
void Player_planeB::addRBullet() {
	if (GameView_INF::counter % 7 == 5)
	{
		m_bullets.push_back(new Bullet(Bullet::PlayerB, m_attack, m_bullet_speed, m_x, m_y, Bullet::Right));//ture:玩家,false:敌人
	};
}
//--------------------Player_PlaneB--------------------


//--------------------Player_PlaneC--------------------
Player_planeC::Player_planeC()
{	
	m_attack = 4; m_speed = 5; m_bullet_speed = 20;
	m_w = 40; m_h = 30; img_w = 80; img_h = 60;
	m_type = Player_planeC::PlayerC;
	loadimage(&planeIMG, "../Asset/plane/player_plane_2.png", img_w, img_h);
}
Player_planeC::~Player_planeC()
{
	for (Bullet* bullet : Player_planeC::m_bullets) {
		delete bullet;
	}
}
void Player_planeC::initPlayer() {
	m_x = 300; m_y = 750; m_hp = 200;

}
void Player_planeC::UPDATE(int& power) {
	for (auto it = Player_planeC::m_bullets.begin(); it != Player_planeC::m_bullets.end(); ) {
		Bullet* bullet = *it;
		bullet->move();
		if (bullet->check_outscreen()) {
			delete bullet;
			it = Player_planeC::m_bullets.erase(it);
		}
		else {
			++it;
		}
	}
};
void Player_planeC::DRAW() {
	putimage_new(m_x - img_w / 2, m_y - img_h / 2, &planeIMG);
	for (Bullet* bullet : Player_planeC::m_bullets)
		bullet->DRAW();
};
void Player_planeC::shoot(int& power) {
	//飞机C蓄力发射
	if (power >= 150	) {			//蓄力值大于150,发射大号子弹
		addBullet(power);
		power = 0;
	}
	else if (power >= 60) {			//蓄力值大于90,发射小号子弹
		addBullet(power);
		power = 0;
	}
	else {							//蓄力值小于90,发射小号子弹
		addBullet(power);
		power = 0;
	}
}
void Player_planeC::addBullet(int& power) {

	if (power >= 150)
	{
		m_bullets.push_back(new Bullet(Bullet::PlayerC3, m_attack + 38, m_bullet_speed, m_x, m_y, Bullet::Middle));
	}
	else if (power >= 60)
	{
		m_bullets.push_back(new Bullet(Bullet::PlayerC2, m_attack + 18, m_bullet_speed, m_x, m_y, Bullet::Middle));
	}
	else
	{
		m_bullets.push_back(new Bullet(Bullet::PlayerC1, m_attack, m_bullet_speed, m_x, m_y, Bullet::Middle));
	}
};
//--------------------player_PlaneC--------------------