#include "Enemy_Plane.h"

//------------------------------Enemy_PlaneA------------------------------//
Enemy_PlaneA::Enemy_PlaneA() {
	//��ʼ������λ��
	Enemy_PlaneA::initPosition();
	m_bullets_E.clear();
	//��ʼ����������
	m_attack = 7; m_hp = 35; ; m_bullet_speed = 7; m_w = 70; m_h = 40; img_w = 70, img_h = 60;
	//��ʼ�����˺��ݷ�����ٶ�
	x_speed = rand() % 3+1;y_speed = rand() % 2+1;
	//��ǵ�������
	m_type = Enemy_Plane::EnemyA;
	//��¼�����Ƿ�����
	isAlive = true;
	//ˢ��λ��
	Enemy_PlaneA::initPosition(); 
	//������Դ
	loadimage(&enemy_plane_1, "../Asset/plane/enemy_plane_1.png", 70, 60);
}
Enemy_PlaneA::~Enemy_PlaneA() {
	// �ͷ��ӵ�ռ�õ��ڴ�
	for (auto bullet : m_bullets_E) {
		delete bullet;  
	}
	m_bullets_E.clear();
}

void  Enemy_PlaneA::UPDATE(int x ,int y) {
	//�ӵ��Զ�����
	if(isAlive)Enemy_PlaneA::addBullet();
	//�ƶ�(��ȡ���λ��,λ��������ƶ�)
	if (isAlive)Enemy_PlaneA::move(x,y);
	//��������,�����ŵ���Ļ���λ��,������ײ���
	if (!isAlive)m_x = -500, m_y = -500;
	//����Ƿ�ɳ���Ļ��,�����ӵ�λ��
	for (auto it = Enemy_PlaneA::m_bullets_E.begin(); it != Enemy_PlaneA::m_bullets_E.end(); ) {
		Bullet* bullet_e = *it;
		bullet_e->move();
		if (bullet_e->check_outscreen()) {	// ɾ���ɳ���Ļ����ӵ�
			delete bullet_e;				// �ͷ��ӵ�����
			it = Enemy_PlaneA::m_bullets_E.erase(it);  // ɾ��Ԫ�ز�������һ����Ч������
		}
		else {
			++it;  // �ƶ�����һ��Ԫ��
		}
	}
};

void Enemy_PlaneA::DRAW() {
	//���Ʒɻ�
	putimage_new(m_x - img_w / 2, m_y - img_h / 2, &enemy_plane_1);
	//�����ӵ�
	for (Bullet* bullet : Enemy_PlaneA::m_bullets_E)	
	{
		bullet->DRAW();
	}
};

void Enemy_PlaneA::initPosition() {
	//���λ��ˢ��
	int boundary = rand() % 3;

	if (boundary == 0) {			//��
		m_x = rand() % 640;
		m_y = -20;					//��ʼy������Ϊ-20��ʹ������Ļ�Ϸ�
	}
	else if (boundary == 1) {		//��
		m_x = -20;					//��ʼx������Ϊ-20��ʹ������Ļ���
		m_y = rand() % 380;
	}
	else {							//�ұ�
		m_x = 630;					//��ʼx������Ϊ660��ʹ������Ļ�Ҳ�
		m_y = rand() % 380;
	}
};

void Enemy_PlaneA::addBullet() {
	//ʵ�����ӵ�
	if (GameView_INF::counter % 25 == 0)
	{
		m_bullets_E.push_back(new Bullet(Bullet::Enemy1, m_attack, m_bullet_speed, m_x, m_y, Bullet::Middle));//ture:���,false:����
	}
};

void Enemy_PlaneA::move(int x, int y) {
	// ���������꣬ʹ����0��400֮�䷴���˶�
	m_y += y_speed;
	if (m_y < -20 || m_y > 400) {
		y_speed = -y_speed;  // �����ƶ�
	}
	// ���º����꣬ʹ�䳯����ҵĺ����귽���ƶ�
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
	//���λ��ˢ��
	int boundary = rand() % 3;
	if (boundary == 0) {			//��
		m_x = rand() % 640;
		m_y = -20;					
	}
	else if (boundary == 1) {		//��
		m_x = -20;					 
		m_y = rand() % 380;
	}
	else {							//��
		m_x = 630;					
		m_y = rand() % 380;
	}
};

bool Enemy_PlaneB::ColliderWithPlayer(int x, int y) {
	//ʵ����ײ
	return (m_x < x + 40 / 2 &&
		m_x > x - 40 / 2 &&
		m_y < y + 30 / 2 &&
		m_y> y - 30 / 2);
};

void Enemy_PlaneB::move(int x, int y) {
	//��������ƶ�
	if (m_y < y) {
		m_y += y_speed;
	}
	else if (m_y > y) {
		m_y -= y_speed;
	}
	else {
		m_y -= 0;
	}
	// ���º����꣬ʹ�䳯����ҵĺ����귽���ƶ�
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
		m_bullets_E.push_back(new Bullet(Bullet::Enemy3, m_attack, m_bullet_speed, m_x, m_y, x, y));//ture:���,false:����
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
	if (boundary == 0) {			//��
		m_x = 660;					
		m_y = rand() % 250 +80;
		ismove = false;
	}
	else if (boundary == 1) {		 //��
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
