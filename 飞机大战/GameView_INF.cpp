#include "gameview_inf.h"
//--------------------���徲̬��Ա����--------------------
std::vector<Enemy_Plane*> GameView_INF::enemy_listA;
std::vector<Enemy_PlaneB*> GameView_INF::enemy_listB;
std::vector<Enemy_PlaneC*> GameView_INF::enemy_listC;
int GameView_INF::level = 0;	
int GameView_INF::score = 0;
int GameView_INF::counter = -1;
int GameView_INF::power = 0;
int GameView_INF::X = 170;
bool GameView_INF::move_is_up = false;
bool GameView_INF::move_is_down = false;
bool GameView_INF::move_is_left = false;
bool GameView_INF::move_is_right = false;
bool GameView_INF::is_shoot = false;
//--------------------���徲̬��Ա����--------------------

void GameView_INF::ENTER() {
	//��ʼ���������
	player->initPlayer();
	//��ʼ����Ϸ�������״̬����ֵ
	move_is_up = false;
	move_is_down = false;
	move_is_left = false;
	move_is_right = false;
	is_shoot = false;
	GameView_INF::counter = -1;
	GameView_INF::power = 0;
	GameView_INF::X = 170;
	GameView_INF::score = 0;
	GameView_INF::level = 0;
}
//EnemyA����
void EnemyA_UPDATE(std::vector<Enemy_Plane*>& enemy_listA) {
	//����ˢ���߼�
	if ((GameView_INF::counter)%70==0) 
	{		
		enemy_listA.push_back(new Enemy_PlaneA());
	}
	//���µ�����Ϊ
	for (Enemy_Plane* enemy : enemy_listA)
	{
		enemy->UPDATE(player->m_x, player->m_y);
	}
}
//EnemyB����
void EnemyB_UPDATE(std::vector<Enemy_PlaneB*>& enemy_listB) {
	if ((GameView_INF::counter) % (400-70* GameView_INF::level) == 0) 
	{		
		enemy_listB.push_back(new Enemy_PlaneB());
	
	}
	//���µ�����Ϊ
	for (Enemy_PlaneB* enemy : enemy_listB)
	{
		enemy->UPDATE(player->m_x, player->m_y);
	}
}
//EnemyC����
void EnemyC_UPDATE(std::vector<Enemy_PlaneC*>& enemy_listC) {
	if ((GameView_INF::counter) % (3000- 490*GameView_INF::level) == 0) 
	{		
		enemy_listC.push_back(new Enemy_PlaneC());
	}
	//���µ�����Ϊ
	for (Enemy_PlaneC* enemy : enemy_listC)
	{
		enemy->UPDATE(player->m_x, player->m_y);
	}
}
void GameView_INF::CheckCollisions() {
	// ��������ӵ�,�Ե���A
	for (auto it = player->m_bullets.begin(); it != player->m_bullets.end();) {
		Bullet* bullet = *it;
		// ��������A
		for (Enemy_Plane* enemy : enemy_listA) {
			if (bullet->checkCollisionE(*enemy)) {
				// ������ײ��������ٵ�������ֵ
				enemy->takeDamage(bullet->getDamage());
				Explosion::addBulletExplosion(bullet);    //������ը
				if (bullet->bullettype == Bullet::PlayerC1 ||
					bullet->bullettype == Bullet::PlayerC2 ||
					bullet->bullettype == Bullet::PlayerC3) {
					break;
				}
				// ɾ���ӵ�
				delete bullet;
				it = player->m_bullets.erase(it);
				break;  // �����ڲ�ѭ�����ӵ��Ѿ�����
			}
		}
		if (it != player->m_bullets.end()) {
			++it;  // �ƶ�����һ���ӵ�
		}
	}
	// ��������ӵ�,�Ե���B
	for (auto it = player->m_bullets.begin(); it != player->m_bullets.end();) {
		Bullet* bullet = *it;
		// ��������B
		for (Enemy_PlaneB* enemyB : enemy_listB) {
			if (bullet->checkCollisionE(*enemyB)) {
				// ������ײ��������ٵ�������ֵ
				enemyB->takeDamage(bullet->getDamage());
				Explosion::addBulletExplosion(bullet);    //������ը
				if (bullet->bullettype == Bullet::PlayerC1 ||
					bullet->bullettype == Bullet::PlayerC2 ||
					bullet->bullettype == Bullet::PlayerC3) {
					break;
				}
				// ɾ���ӵ�
				delete bullet;
				it = player->m_bullets.erase(it);
				break;  // �����ڲ�ѭ�����ӵ��Ѿ�����
			}
		}
		if (it != player->m_bullets.end()) {
			++it;  // �ƶ�����һ���ӵ�
		}
	}
	// ��������ӵ�,�Ե���C
	for (auto it = player->m_bullets.begin(); it != player->m_bullets.end();) {
		Bullet* bullet = *it;
		// ��������C
		for (Enemy_PlaneC* enemyC : enemy_listC) {
			if (bullet->checkCollisionE(*enemyC)) {
				// ������ײ��������ٵ�������ֵ
				enemyC->takeDamage(bullet->getDamage());
				Explosion::addBulletExplosion(bullet);    //������ը
				if (bullet->bullettype == Bullet::PlayerC1 ||
					bullet->bullettype == Bullet::PlayerC2 ||
					bullet->bullettype == Bullet::PlayerC3) {
					break;
				}
				// ɾ���ӵ�
				delete bullet;
				it = player->m_bullets.erase(it);
				break;  // �����ڲ�ѭ�����ӵ��Ѿ�����
			}
		}
		if (it != player->m_bullets.end()) {
			++it;  // �ƶ�����һ���ӵ�
		}
	}
	// ���������ӵ�A
	for (Enemy_Plane* enemy : enemy_listA) {
		std::vector<Bullet*>& enemyBullets = enemy->getBullets();
		for (Bullet* enemyBullet : enemyBullets) {
			if (enemyBullet->checkCollisionP(*player)) {
				// ������ײ����������������ֵ
				player->takeDamage(enemyBullet->getDamage());
				Explosion::addBulletExplosion(enemyBullet);    //������ը

				// ɾ���ӵ�
				delete enemyBullet;
				enemyBullets.erase(std::remove(enemyBullets.begin(), enemyBullets.end(), enemyBullet), enemyBullets.end());

				break;  // �����ڲ�ѭ������Ϊ�ӵ��Ѿ�����
			}
		}
	}
	// ���������ӵ�C
	for (Enemy_Plane* enemyC : enemy_listC) {
		std::vector<Bullet*>& enemyBullets = enemyC->getBullets();
		for (Bullet* enemyBullet : enemyBullets) {
			if (enemyBullet->checkCollisionP(*player)) {
				// ������ײ����������������ֵ
				player->takeDamage(enemyBullet->getDamage());
				Explosion::addBulletExplosion(enemyBullet);    //������ը
				// ɾ���ӵ�
				delete enemyBullet;
				enemyBullets.erase(std::remove(enemyBullets.begin(), enemyBullets.end(), enemyBullet), enemyBullets.end());

				break;  // �����ڲ�ѭ������Ϊ�ӵ��Ѿ�����
			}
		}
	}

}
void GameView_INF::CheckEnemyBCollisions() {
	for (auto it = enemy_listB.begin(); it != enemy_listB.end();) {
		Enemy_PlaneB* enemy = *it;
		if (enemy->m_type == Enemy_PlaneB::EnemyB &&
			enemy->ColliderWithPlayer(player->getX(), player->getY())) {
			Explosion::addEnemyExplosion(enemy->getPositionX(), enemy->getPositionY());
			player->takeDamage(enemy->m_attack);
			enemy->isAlive = false;
			delete enemy;
			it = enemy_listB.erase(it);
		}
		else {
			// ���˻����ţ���������
			++it;
		}
	}
};
void GameView_INF::EnemyDie() {
	// ��������A�б�
	for (auto it = enemy_listA.begin(); it != enemy_listA.end();) {
		Enemy_Plane* enemy = *it;
		// �������Ƿ�����
		if (enemy->isDie_E()) {
			// ��������������ӵ������Ƿ�Ϊ��
			if (enemy->getbulletEmpty()) {
				// �ӵ�����Ϊ�գ�ֱ��ɾ������
				delete enemy;
				it = enemy_listA.erase(it);
				GameView_INF::score += 400;
			}
			else {
				// �ӵ����鲻Ϊ�գ���ǵ���״̬Ϊ�ǻ�Ծ
				enemy->isAlive = false;
				++it;  // ���µ�����
			}
		}
		else {
			// ���˻����ţ���������
			++it;
		}
	}
	//��������B�б�
	for (auto it = enemy_listB.begin(); it != enemy_listB.end();) {
		Enemy_PlaneB* enemyB = *it;
		// �������Ƿ�����
		if (enemyB->isDie_E()) {
			// ��������������ӵ������Ƿ�Ϊ��
			if (enemyB->getbulletEmpty()) {
				// �ӵ�����Ϊ�գ�ֱ��ɾ������
				delete enemyB;
				GameView_INF::score += 1000;
				it = enemy_listB.erase(it);
			}
			else {
				// �ӵ����鲻Ϊ�գ���ǵ���״̬Ϊ�ǻ�Ծ
				enemyB->isAlive = false;
				++it;  // ���µ�����
			}
		}
		else {
			// ���˻����ţ���������
			++it;
		}
	}
	// ��������C�б�
	for (auto it = enemy_listC.begin(); it != enemy_listC.end();) {
		Enemy_PlaneC* enemyC = *it;
		// �������Ƿ�����
		if (enemyC->isDie_E()) {
			// ��������������ӵ������Ƿ�Ϊ��
			if (enemyC->getbulletEmpty()) {
				// �ӵ�����Ϊ�գ�ֱ��ɾ������
				delete enemyC;
				it = enemy_listC.erase(it);
				GameView_INF::score += 5000;
			}
			else {
				// �ӵ����鲻Ϊ�գ���ǵ���״̬Ϊ�ǻ�Ծ
				enemyC->isAlive = false;
				++it;  // ���µ�����
			}
		}
		else {
			// ���˻����ţ���������
			++it;
		}
	}

};
void GameView_INF::UPDATE() {
	//�ȴ�3�뿪ʼˢ�µ���
	GameView_INF::counter++;
	//--------------------��Ϸ�Ѷȸı�--------------------
	if (GameView_INF::counter > 6000&& GameView_INF::counter<=8000)level = 1;
	if (GameView_INF::counter > 8000 && GameView_INF::counter <= 11000)level = 2;
	if (GameView_INF::counter > 11000)level = 3;
	//--------------------��ʱ�����ӵ÷�--------------------
	if (GameView_INF::counter > 400)GameView_INF::score++;
	
	
	//--------------------����ˢ��,������Ϊ����--------------------
	if (GameView_INF::counter >400)
	{
		EnemyA_UPDATE(enemy_listA);		
		EnemyB_UPDATE(enemy_listB);
		EnemyC_UPDATE(enemy_listC);
	}
	//--------------------���������Ϊ--------------------
	if (player->m_type != Player_plane::PlayerC) {		//���·ɻ�A/B
		player->UPDATE();
	}
	else if (player->m_type == Player_plane::PlayerC) {	//���·ɻ�C
		player->UPDATE(power);
	}

	//--------------------��ײ���--------------------
	GameView_INF::CheckCollisions();		//�ӵ���ײ�߼�
	GameView_INF::CheckEnemyBCollisions();	//����B��ը

	GameView_INF::EnemyDie();				//�����ͷ��߼�
	Explosion::BulletExploding();
	Explosion::EnemyExploding();
	Explosion::clearExplosion();

	//--------------------�����Ϸ�Ƿ����--------------------
	if (player->isDie_P()) 
	{
		view_manager.switch_to(ViewManager::ViewType::End);//��Ϸ����
	}

}
void GameView_INF::DRAW() {
	putimage(0, 0, &gameview);
	
	//--------------------���Ʊ�ըЧ��--------------------
	Explosion::BulletExploding();
	Explosion::EnemyExploding();

	//--------------------�������--------------------
	player->DRAW();

	//--------------------���Ƶ���--------------------
	for (Enemy_Plane* enemy : enemy_listA)
	{
		enemy->DRAW();
	}
	for (Enemy_PlaneB* enemyB : enemy_listB)
	{
		enemyB->DRAW();
	}
	for (Enemy_PlaneC* enemyC : enemy_listC)
	{
		enemyC->DRAW();
	}

	//--------------------���Ʒɻ����ܿ�--------------------
	if (GameView_INF::counter < 460)
	{
		if (GameView_INF::counter < 400)
		{
			if(player->m_type == Player_plane::PlayerA)
				putimage_new(170, 293, &introduce1);
			else if(player->m_type == Player_plane::PlayerB)
				putimage_new(170, 293, &introduce2);
			else if(player->m_type == Player_plane::PlayerC)
				putimage_new(170, 293, &introduce3);
		}
		else 
		{
			X += 20;
			if (player->m_type == Player_plane::PlayerA)
				putimage_new(X, 293, &introduce1);
			else if (player->m_type == Player_plane::PlayerB)
				putimage_new(X, 293, &introduce2);
			else if (player->m_type == Player_plane::PlayerC)
				putimage_new(X, 293, &introduce3);
		}
	}
	//--------------------���Ƶ÷�&ʱ��--------------------
	setbkmode(TRANSPARENT);
	settextstyle(40,0, _T("IPix"));
	setcolor(RGB(184, 184, 186));

	char F[256];
	sprintf_s(F, "%d", GameView_INF::score);
	outtextxy(33, 33, F);
	settextcolor(WHITE);
	outtextxy(30, 30, F);
	

	//--------------------����Ѫ��--------------------
	putimage_new(10, 330, &HP1);
	int IMG_Y=1;
	IMG_Y = (200-(player->m_hp))*1.5;
	loadimage(&HP2, "../Asset/HP/hp2.png", 20, IMG_Y);
	putimage_new(10, 330, &HP2);

}
void GameView_INF::INPUT(ExMessage& msg) {
		switch (msg.message)
		{
		case WM_KEYDOWN:
			switch (msg.vkcode) {
			case 0x57:
				move_is_up = true;
				break;
			case 0x53:
				move_is_down = true;
				break;
			case 0x41:
				move_is_left = true;
				break;
			case 0x44:
				move_is_right = true;
				break;
			case 0x4A:
				is_shoot = true;	//J���
				break;
			case 0x50:				//P��ͣ
				GameView_INF::PauseView(msg);//������ͣ����
				break;
			}
			break;
		case WM_KEYUP:
			switch (msg.vkcode) {
			case 0x57:
				move_is_up = false;
				break;
			case 0x53:
				move_is_down = false;
				break;
			case 0x41:
				move_is_left = false;
				break;
			case 0x44:
				move_is_right = false;
				break;
			case 0x4A:
				is_shoot = false;
				break;
			}
			break;
		default:
			break;
		}

	//�����������
	if (move_is_up&& player->m_y>5)player->m_y -= player->m_speed;
	if (move_is_down && player->m_y < 940)player->m_y += player->m_speed;
	if (move_is_left && player->m_x > 0)player->m_x -= player->m_speed;
	if (move_is_right && player->m_x <600)player->m_x += player->m_speed;

	//�����ӵ�
	if (is_shoot) {
		if (player->m_type == Player_plane::PlayerA)
			player->addBullet();
		else if (player->m_type == Player_plane::PlayerB) {
			player->addLBullet();
			player->addMBullet();
			player->addRBullet();
		}
		else if (player->m_type == Player_plane::PlayerC) {
			if (power < 500) {
				power++;
			}
		}
	}
	if (!is_shoot && power != 0 && player->m_type == Player_plane::PlayerC) {
		player->shoot(power);
	}

}
void GameView_INF::EXIT() {
	//�ͷŴ洢����vector����
	for (auto it = enemy_listA.begin(); it != enemy_listA.end();) {
		Enemy_Plane* enemy = *it;
		delete enemy;
		it = enemy_listA.erase(it);
	}
	for (auto it = enemy_listB.begin(); it != enemy_listB.end();) {
		Enemy_PlaneB* enemyB = *it;
		delete enemyB;
		it = enemy_listB.erase(it);
	}
	for (auto it = enemy_listC.begin(); it != enemy_listC.end();) {
		Enemy_PlaneC* enemyC = *it;delete enemyC;
		it = enemy_listC.erase(it);
	}
	//�ͷ�����ӵ�����
	player->m_bullets.clear();
}

void GameView_INF::PauseView(ExMessage& msg){
	//����ͼƬ�ز�
	IMAGE pauseview,backgame,restart,backmenu;
	loadimage(&pauseview, "../Asset/backgroud/pauseview.png", 640, 960);
	loadimage(&backgame, "../Asset/button/backgame.png", 180,60);
	loadimage(&restart, "../Asset/button/restart.png", 180, 60);
	loadimage(&backmenu, "../Asset/button/backmenu.png", 180, 60);
		
	while (true) 
	{
		BeginBatchDraw();
		cleardevice();
		
		//----------���ƽ���----------
		//����
		putimage_new(0, 0, &pauseview);
		//������Ϸ
		putimage_new(230, 400, &backgame);
		//����
		putimage_new(230, 550, &restart);
		//���ز˵�
		putimage_new(230, 700, &backmenu);
		//----------������Ϣ����----------
		FlushBatchDraw();
		if (peekmessage(&msg)) 
		{
			switch (msg.message) 
			{
			case WM_LBUTTONDOWN:
				// ������Ϸ
				if (msg.x >= 230 && msg.x <= 410 && msg.y >= 400 && msg.y <= 460) {
					move_is_up = false;
					move_is_down = false;
					move_is_left = false;
					move_is_right = false;
					is_shoot = false;
					return;
				}
				// ����
				if (msg.x >= 230 && msg.x <= 410 && msg.y >= 550 && msg.y <= 610) {
					//��ʼ��,������Ϸ����
					GameView_INF::EXIT();
					GameView_INF::ENTER();
					return;
				}

				// ���ز˵�
				if (msg.x >= 230 && msg.x <= 410 && msg.y >= 700 && msg.y <= 770) {
					//��ʼ��.����˵�����
					view_manager.switch_to(ViewManager::ViewType::Menu);
					return;
				}
			}
		}

	}

}
