#include "Player_plane.h"

//--------------------Player_PlaneA--------------------
Player_planeA::Player_planeA()
{	//�ɻ���ʼ��
	m_attack = 15; m_speed = 5; m_bullet_speed = 10;
	m_w = 40; m_h = 30; img_w = 60, img_h = 45;
	//�����ɻ�����
	m_type = Player_planeA::PlayerA;
	//���طɻ��ز�
	loadimage(&planeIMG, "../Asset/plane/player_plane_1.png", img_w, img_h);
}
Player_planeA::~Player_planeA()
{
	//�ͷ��ӵ�����
	for (Bullet* bullet : Player_planeA::m_bullets) {
		delete bullet;  // ɾ��ÿ��ָ��ָ��Ķ���
	}
}
void Player_planeA::initPlayer() {
	//��ʼ�����,Ѫ��,����
	m_x = 300; m_y = 750; m_hp = 200;

}
void Player_planeA::UPDATE() {
	//����Ƿ�ɳ���Ļ��,�����ӵ�λ��
	for (auto it = Player_planeA::m_bullets.begin(); it != Player_planeA::m_bullets.end(); ) {
		Bullet* bullet = *it;
		bullet->move();
		if (bullet->check_outscreen()) {
			// ɾ���ɳ���Ļ����ӵ�
			delete bullet;  // �ͷ��ӵ�����
			it = Player_planeA::m_bullets.erase(it);  // ɾ��Ԫ�ز�������һ����Ч������
		}
		else {
			++it;  // �ƶ�����һ��Ԫ��
		}
	}
};
void Player_planeA::DRAW() {
	putimage_new(m_x - img_w / 2, m_y - img_h / 2, &planeIMG);		//���Ʒɻ�
	for (Bullet* bullet : Player_planeA::m_bullets)					//�����ӵ�
		bullet->DRAW();
};
void Player_planeA::addBullet() {
	//ʵ�����ӵ�
	if (GameView_INF::counter % 10 == 5)
	{
		m_bullets.push_back(new Bullet(Bullet::PlayerA, m_attack, m_bullet_speed, m_x, m_y, Bullet::Middle));//ture:���,false:����

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
		m_bullets.push_back(new Bullet(Bullet::PlayerB, m_attack, m_bullet_speed, m_x, m_y, Bullet::Left));//ture:���,false:����
	};
}
void Player_planeB::addMBullet() {
	if (GameView_INF::counter % 7 == 5)
	{
		m_bullets.push_back(new Bullet(Bullet::PlayerB, m_attack, m_bullet_speed, m_x, m_y, Bullet::Middle));//ture:���,false:����
	};
}
void Player_planeB::addRBullet() {
	if (GameView_INF::counter % 7 == 5)
	{
		m_bullets.push_back(new Bullet(Bullet::PlayerB, m_attack, m_bullet_speed, m_x, m_y, Bullet::Right));//ture:���,false:����
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
	//�ɻ�C��������
	if (power >= 150	) {			//����ֵ����150,�������ӵ�
		addBullet(power);
		power = 0;
	}
	else if (power >= 60) {			//����ֵ����90,����С���ӵ�
		addBullet(power);
		power = 0;
	}
	else {							//����ֵС��90,����С���ӵ�
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