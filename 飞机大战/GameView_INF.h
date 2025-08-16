//无尽模式游戏界面
#pragma once
#include "view.h"
#include "ViewManager.h"
#include <vector>
#include "Enemy_Plane.h"
#include "Player_plane.h"
#include <iostream>
#include <mmsystem.h>
#include <string>
#include "Explosion.h"
class Player_plane;//向前声明
class Enemy_Plane;
class Enemy_PlaneB;
class Enemy_PlaneC;
extern Player_plane*player;
extern ViewManager view_manager;

class GameView_INF :public view
{
public:
	//1.加载游戏界面的素材  
	//2.初始化游戏界面数据 分数
	GameView_INF() {
		loadimage(&gameview, "../Asset/backgroud/gameview.png", 640, 960);
		loadimage(&HP1, "../Asset/HP/hp1.png", 20, 320);
		loadimage(&introduce1, "../Asset/backgroud/introduce1.png", 300, 375);
		loadimage(&introduce2, "../Asset/backgroud/introduce2.png", 300, 375);
		loadimage(&introduce3, "../Asset/backgroud/introduce3.png", 300, 375);
	};

	//释放掉敌人 玩家
	~GameView_INF() {
		//释放玩家类
		if (player) {
			delete player;
		}
	};
	IMAGE gameview,HP1,HP2, introduce1, introduce2, introduce3;
	static std::vector<Enemy_Plane*> enemy_listA;
	static std::vector<Enemy_PlaneB*> enemy_listB;
	static std::vector<Enemy_PlaneC*> enemy_listC;
	static int counter ;	//计时器,负责刷新
	static int score;		//游戏得分
	static int power;		//飞机C蓄力值
	static int level;		//记录游戏难度

	static bool move_is_up ;
	static bool move_is_down;
	static bool move_is_left ;
	static bool move_is_right ;
	static bool is_shoot;
	static int X;			//负责游戏介绍框移动
	void ENTER();
	//无尽模式游戏界面运行逻辑
		//*刷新敌人飞机
		//*敌人飞机的行为
		//*玩家飞机的行为
		//*游戏状态判断(结束,暂停->死循环,继续)
		//*数据更新(得分,玩家,敌人)
	void UPDATE();
	void DRAW();
	void INPUT(ExMessage& msg);
	void EXIT();
	void PauseView(ExMessage& msg);		//暂停界面
	void CheckCollisions();				//子弹碰撞
	void CheckEnemyBCollisions();		//敌人飞机B碰撞
	void EnemyDie();
};