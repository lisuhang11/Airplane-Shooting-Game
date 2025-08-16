#include "EndView.h"
void EndView::ENTER() {
    loadimage(&endview, "../Asset/backgroud/endview.png", 640, 960);
    loadimage(&restart, "../Asset/button/restart.png", 180,60);
    loadimage(&backmenu, "../Asset/button/backmenu.png", 180, 60);
}
void EndView::UPDATE() {

}
void EndView::DRAW() {
    putimage(0, 0, &endview);
    putimage_new(120, 690, &restart);
    putimage_new(340, 690, &backmenu);
    //----���Ƶ÷�----
    setbkmode(TRANSPARENT);
    settextstyle(40, 0, _T("����"));

    char F[256];
    sprintf_s(F, "%d", GameView_INF::score);
    setcolor(RGB(184, 184, 186));
    outtextxy(383, 368, F);
    outtextxy(200, 368,_T("�÷�:"));
    settextcolor(WHITE);
    outtextxy(380, 365, F);
    outtextxy(200, 365, _T("�÷�:"));
    //----���Ƶ÷�----
}
void EndView::INPUT(ExMessage& msg) {
        if (msg.message == WM_LBUTTONDOWN) {
            if (msg.x > 120 && msg.y > 690 && msg.x < 400 && msg.y < 750) {  //����,����ʼ����Ϸ����
                view_manager.switch_to(ViewManager::ViewType::Game_inf);  
            }
            if (msg.x > 340 && msg.y > 690 && msg.x < 520 && msg.y < 750) {  //���ز˵�
                view_manager.switch_to(ViewManager::ViewType::Menu);
            }
                
        }
}
void EndView::EXIT() {

}
