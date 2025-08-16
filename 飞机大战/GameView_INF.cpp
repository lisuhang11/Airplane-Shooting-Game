#include "gameview_inf.h"
//--------------------定义静态成员变量--------------------
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
//--------------------定义静态成员变量--------------------

void GameView_INF::ENTER() {
	//初始化玩家属性
	player->initPlayer();
	//初始化游戏界面操作状态和数值
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
//EnemyA更新
void EnemyA_UPDATE(std::vector<Enemy_Plane*>& enemy_listA) {
	//敌人刷新逻辑
	if ((GameView_INF::counter)%70==0) 
	{		
		enemy_listA.push_back(new Enemy_PlaneA());
	}
	//更新敌人行为
	for (Enemy_Plane* enemy : enemy_listA)
	{
		enemy->UPDATE(player->m_x, player->m_y);
	}
}
//EnemyB更新
void EnemyB_UPDATE(std::vector<Enemy_PlaneB*>& enemy_listB) {
	if ((GameView_INF::counter) % (400-70* GameView_INF::level) == 0) 
	{		
		enemy_listB.push_back(new Enemy_PlaneB());
	
	}
	//更新敌人行为
	for (Enemy_PlaneB* enemy : enemy_listB)
	{
		enemy->UPDATE(player->m_x, player->m_y);
	}
}
//EnemyC更新
void EnemyC_UPDATE(std::vector<Enemy_PlaneC*>& enemy_listC) {
	if ((GameView_INF::counter) % (3000- 490*GameView_INF::level) == 0) 
	{		
		enemy_listC.push_back(new Enemy_PlaneC());
	}
	//更新敌人行为
	for (Enemy_PlaneC* enemy : enemy_listC)
	{
		enemy->UPDATE(player->m_x, player->m_y);
	}
}
void GameView_INF::CheckCollisions() {
	// 遍历玩家子弹,对敌人A
	for (auto it = player->m_bullets.begin(); it != player->m_bullets.end();) {
		Bullet* bullet = *it;
		// 遍历敌人A
		for (Enemy_Plane* enemy : enemy_listA) {
			if (bullet->checkCollisionE(*enemy)) {
				// 处理碰撞，例如减少敌人生命值
				enemy->takeDamage(bullet->getDamage());
				Explosion::addBulletExplosion(bullet);    //发生爆炸
				if (bullet->bullettype == Bullet::PlayerC1 ||
					bullet->bullettype == Bullet::PlayerC2 ||
					bullet->bullettype == Bullet::PlayerC3) {
					break;
				}
				// 删除子弹
				delete bullet;
				it = player->m_bullets.erase(it);
				break;  // 跳出内层循环，子弹已经处理
			}
		}
		if (it != player->m_bullets.end()) {
			++it;  // 移动到下一个子弹
		}
	}
	// 遍历玩家子弹,对敌人B
	for (auto it = player->m_bullets.begin(); it != player->m_bullets.end();) {
		Bullet* bullet = *it;
		// 遍历敌人B
		for (Enemy_PlaneB* enemyB : enemy_listB) {
			if (bullet->checkCollisionE(*enemyB)) {
				// 处理碰撞，例如减少敌人生命值
				enemyB->takeDamage(bullet->getDamage());
				Explosion::addBulletExplosion(bullet);    //发生爆炸
				if (bullet->bullettype == Bullet::PlayerC1 ||
					bullet->bullettype == Bullet::PlayerC2 ||
					bullet->bullettype == Bullet::PlayerC3) {
					break;
				}
				// 删除子弹
				delete bullet;
				it = player->m_bullets.erase(it);
				break;  // 跳出内层循环，子弹已经处理
			}
		}
		if (it != player->m_bullets.end()) {
			++it;  // 移动到下一个子弹
		}
	}
	// 遍历玩家子弹,对敌人C
	for (auto it = player->m_bullets.begin(); it != player->m_bullets.end();) {
		Bullet* bullet = *it;
		// 遍历敌人C
		for (Enemy_PlaneC* enemyC : enemy_listC) {
			if (bullet->checkCollisionE(*enemyC)) {
				// 处理碰撞，例如减少敌人生命值
				enemyC->takeDamage(bullet->getDamage());
				Explosion::addBulletExplosion(bullet);    //发生爆炸
				if (bullet->bullettype == Bullet::PlayerC1 ||
					bullet->bullettype == Bullet::PlayerC2 ||
					bullet->bullettype == Bullet::PlayerC3) {
					break;
				}
				// 删除子弹
				delete bullet;
				it = player->m_bullets.erase(it);
				break;  // 跳出内层循环，子弹已经处理
			}
		}
		if (it != player->m_bullets.end()) {
			++it;  // 移动到下一个子弹
		}
	}
	// 遍历敌人子弹A
	for (Enemy_Plane* enemy : enemy_listA) {
		std::vector<Bullet*>& enemyBullets = enemy->getBullets();
		for (Bullet* enemyBullet : enemyBullets) {
			if (enemyBullet->checkCollisionP(*player)) {
				// 处理碰撞，例如减少玩家生命值
				player->takeDamage(enemyBullet->getDamage());
				Explosion::addBulletExplosion(enemyBullet);    //发生爆炸

				// 删除子弹
				delete enemyBullet;
				enemyBullets.erase(std::remove(enemyBullets.begin(), enemyBullets.end(), enemyBullet), enemyBullets.end());

				break;  // 跳出内层循环，因为子弹已经处理
			}
		}
	}
	// 遍历敌人子弹C
	for (Enemy_Plane* enemyC : enemy_listC) {
		std::vector<Bullet*>& enemyBullets = enemyC->getBullets();
		for (Bullet* enemyBullet : enemyBullets) {
			if (enemyBullet->checkCollisionP(*player)) {
				// 处理碰撞，例如减少玩家生命值
				player->takeDamage(enemyBullet->getDamage());
				Explosion::addBulletExplosion(enemyBullet);    //发生爆炸
				// 删除子弹
				delete enemyBullet;
				enemyBullets.erase(std::remove(enemyBullets.begin(), enemyBullets.end(), enemyBullet), enemyBullets.end());

				break;  // 跳出内层循环，因为子弹已经处理
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
			// 敌人还活着，继续更新
			++it;
		}
	}
};
void GameView_INF::EnemyDie() {
	// 遍历敌人A列表
	for (auto it = enemy_listA.begin(); it != enemy_listA.end();) {
		Enemy_Plane* enemy = *it;
		// 检测敌人是否死亡
		if (enemy->isDie_E()) {
			// 敌人死亡，检测子弹数组是否为空
			if (enemy->getbulletEmpty()) {
				// 子弹数组为空，直接删除敌人
				delete enemy;
				it = enemy_listA.erase(it);
				GameView_INF::score += 400;
			}
			else {
				// 子弹数组不为空，标记敌人状态为非活跃
				enemy->isAlive = false;
				++it;  // 更新迭代器
			}
		}
		else {
			// 敌人还活着，继续更新
			++it;
		}
	}
	//遍历敌人B列表
	for (auto it = enemy_listB.begin(); it != enemy_listB.end();) {
		Enemy_PlaneB* enemyB = *it;
		// 检测敌人是否死亡
		if (enemyB->isDie_E()) {
			// 敌人死亡，检测子弹数组是否为空
			if (enemyB->getbulletEmpty()) {
				// 子弹数组为空，直接删除敌人
				delete enemyB;
				GameView_INF::score += 1000;
				it = enemy_listB.erase(it);
			}
			else {
				// 子弹数组不为空，标记敌人状态为非活跃
				enemyB->isAlive = false;
				++it;  // 更新迭代器
			}
		}
		else {
			// 敌人还活着，继续更新
			++it;
		}
	}
	// 遍历敌人C列表
	for (auto it = enemy_listC.begin(); it != enemy_listC.end();) {
		Enemy_PlaneC* enemyC = *it;
		// 检测敌人是否死亡
		if (enemyC->isDie_E()) {
			// 敌人死亡，检测子弹数组是否为空
			if (enemyC->getbulletEmpty()) {
				// 子弹数组为空，直接删除敌人
				delete enemyC;
				it = enemy_listC.erase(it);
				GameView_INF::score += 5000;
			}
			else {
				// 子弹数组不为空，标记敌人状态为非活跃
				enemyC->isAlive = false;
				++it;  // 更新迭代器
			}
		}
		else {
			// 敌人还活着，继续更新
			++it;
		}
	}

};
void GameView_INF::UPDATE() {
	//等待3秒开始刷新敌人
	GameView_INF::counter++;
	//--------------------游戏难度改变--------------------
	if (GameView_INF::counter > 6000&& GameView_INF::counter<=8000)level = 1;
	if (GameView_INF::counter > 8000 && GameView_INF::counter <= 11000)level = 2;
	if (GameView_INF::counter > 11000)level = 3;
	//--------------------随时间增加得分--------------------
	if (GameView_INF::counter > 400)GameView_INF::score++;
	
	
	//--------------------敌人刷新,敌人行为更新--------------------
	if (GameView_INF::counter >400)
	{
		EnemyA_UPDATE(enemy_listA);		
		EnemyB_UPDATE(enemy_listB);
		EnemyC_UPDATE(enemy_listC);
	}
	//--------------------更新玩家行为--------------------
	if (player->m_type != Player_plane::PlayerC) {		//更新飞机A/B
		player->UPDATE();
	}
	else if (player->m_type == Player_plane::PlayerC) {	//更新飞机C
		player->UPDATE(power);
	}

	//--------------------碰撞检测--------------------
	GameView_INF::CheckCollisions();		//子弹碰撞逻辑
	GameView_INF::CheckEnemyBCollisions();	//敌人B爆炸

	GameView_INF::EnemyDie();				//敌人释放逻辑
	Explosion::BulletExploding();
	Explosion::EnemyExploding();
	Explosion::clearExplosion();

	//--------------------检测游戏是否结束--------------------
	if (player->isDie_P()) 
	{
		view_manager.switch_to(ViewManager::ViewType::End);//游戏结束
	}

}
void GameView_INF::DRAW() {
	putimage(0, 0, &gameview);
	
	//--------------------绘制爆炸效果--------------------
	Explosion::BulletExploding();
	Explosion::EnemyExploding();

	//--------------------绘制玩家--------------------
	player->DRAW();

	//--------------------绘制敌人--------------------
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

	//--------------------绘制飞机介绍框--------------------
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
	//--------------------绘制得分&时间--------------------
	setbkmode(TRANSPARENT);
	settextstyle(40,0, _T("IPix"));
	setcolor(RGB(184, 184, 186));

	char F[256];
	sprintf_s(F, "%d", GameView_INF::score);
	outtextxy(33, 33, F);
	settextcolor(WHITE);
	outtextxy(30, 30, F);
	

	//--------------------绘制血条--------------------
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
				is_shoot = true;	//J射击
				break;
			case 0x50:				//P暂停
				GameView_INF::PauseView(msg);//进入暂停界面
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

	//更新玩家坐标
	if (move_is_up&& player->m_y>5)player->m_y -= player->m_speed;
	if (move_is_down && player->m_y < 940)player->m_y += player->m_speed;
	if (move_is_left && player->m_x > 0)player->m_x -= player->m_speed;
	if (move_is_right && player->m_x <600)player->m_x += player->m_speed;

	//发射子弹
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
	//释放存储敌人vector数组
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
	//释放玩家子弹数组
	player->m_bullets.clear();
}

void GameView_INF::PauseView(ExMessage& msg){
	//加载图片素材
	IMAGE pauseview,backgame,restart,backmenu;
	loadimage(&pauseview, "../Asset/backgroud/pauseview.png", 640, 960);
	loadimage(&backgame, "../Asset/button/backgame.png", 180,60);
	loadimage(&restart, "../Asset/button/restart.png", 180, 60);
	loadimage(&backmenu, "../Asset/button/backmenu.png", 180, 60);
		
	while (true) 
	{
		BeginBatchDraw();
		cleardevice();
		
		//----------绘制界面----------
		//背景
		putimage_new(0, 0, &pauseview);
		//返回游戏
		putimage_new(230, 400, &backgame);
		//重来
		putimage_new(230, 550, &restart);
		//返回菜单
		putimage_new(230, 700, &backmenu);
		//----------操作信息处理----------
		FlushBatchDraw();
		if (peekmessage(&msg)) 
		{
			switch (msg.message) 
			{
			case WM_LBUTTONDOWN:
				// 返回游戏
				if (msg.x >= 230 && msg.x <= 410 && msg.y >= 400 && msg.y <= 460) {
					move_is_up = false;
					move_is_down = false;
					move_is_left = false;
					move_is_right = false;
					is_shoot = false;
					return;
				}
				// 重来
				if (msg.x >= 230 && msg.x <= 410 && msg.y >= 550 && msg.y <= 610) {
					//初始化,进入游戏界面
					GameView_INF::EXIT();
					GameView_INF::ENTER();
					return;
				}

				// 返回菜单
				if (msg.x >= 230 && msg.x <= 410 && msg.y >= 700 && msg.y <= 770) {
					//初始化.进入菜单界面
					view_manager.switch_to(ViewManager::ViewType::Menu);
					return;
				}
			}
		}

	}

}
