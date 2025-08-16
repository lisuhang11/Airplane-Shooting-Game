#include "menuview.h"
void MenuView::ENTER() {

}
void MenuView::UPDATE() {

}
void MenuView::DRAW() {
	IMAGE mainImg;
	loadimage(&mainImg, "../Asset/backgroud/menuview.png", 640, 960);
	putimage(0, 0, &mainImg);

	IMAGE beginImg;
	loadimage(&beginImg, "../Asset/button/start.png", 180, 60);
	putimage_new(230, 300, &beginImg);

	IMAGE setImg;
	loadimage(&setImg, "../Asset/button/set.png", 180, 60);
	putimage_new(230, 540, &setImg);

	IMAGE introduce;
	loadimage(&introduce, "../Asset/button/introduce.png", 180, 60);
	putimage_new(230, 660, &introduce);

	IMAGE wh;
	loadimage(&wh, "../Asset/button/wh.png", 180, 60);
	putimage_new(230, 420, &wh);

	IMAGE quitImg;
	loadimage(&quitImg, "../Asset/button/quit.png", 180, 60);
	putimage_new(230, 780, &quitImg);
}
void MenuView::INPUT(ExMessage& msg) {
	if (peekmessage(&msg), EX_SHOWCONSOLE) {
		switch (msg.message) {
		case WM_LBUTTONDOWN:

			// 主菜单界面的开始游戏
			if (msg.x >= 230 && msg.x <= 410 && msg.y >= 300 && msg.y <= 360) {
				view_manager.switch_to(ViewManager::ViewType::Game_inf);
			}

			// 主菜单界面的游戏设置
			if (msg.x >= 230 && msg.x <= 410 && msg.y >= 540 && msg.y <= 600) {
				view_manager.switch_to(ViewManager::ViewType::Set);
			}

			// 主菜单界面的小组介绍
			if (msg.x >= 230 && msg.x <= 410 && msg.y >= 660 && msg.y <= 720) {
				//view_manager.switch_to(ViewManager::ViewType::小组介绍);
			}

			// 主菜单界面的商店游戏
			if (msg.x >= 230 && msg.x <= 410 && msg.y >= 420 && msg.y <= 480) {
				view_manager.switch_to(ViewManager::ViewType::WH);
			}

			//主菜单界面的退出游戏
			if (msg.x >= 230 && msg.x <= 410 && msg.y >= 780 && msg.y <= 840) {
				exit(0);
			}
			break;
		}
	}
}

void MenuView::EXIT() {

}