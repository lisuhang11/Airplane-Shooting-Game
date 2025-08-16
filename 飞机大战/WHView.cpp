#include "WHView.h"
void WHView::ENTER() {
    loadimage(&whview, "../Asset/backgroud/whview.png", 640, 960);
    loadimage(&wh_plane_1, "../Asset/plane/wh_plane_1.png", 200, 150);
    loadimage(&wh_plane_2, "../Asset/plane/wh_plane_2.png", 200, 150);
    loadimage(&wh_plane_3, "../Asset/plane/wh_plane_3.png", 200, 150);
    loadimage(&equip, "../Asset/button/equip.png", 100, 70);
    loadimage(&equiped, "../Asset/button/equiped.png", 100, 70);
    loadimage(&backmenu, "../Asset/button/backmenu.png", 180, 60);
}

void WHView::UPDATE() {
}

void WHView::DRAW() {
    //����
    putimage(0, 0, &whview);
    //�ɻ�һ��װ��
    putimage_new(120, 260, &wh_plane_1);
    if(player->m_type==Player_plane::PlayerA)putimage_new(410, 300, &equiped);
    else putimage_new(410, 300, &equip);
    //�ɻ�����װ��
    putimage_new(120, 410, &wh_plane_2);
    if (player->m_type == Player_plane::PlayerB)putimage_new(410, 445, &equiped);
    else putimage_new(410, 445, &equip);
    //�ɻ�����װ��
    putimage_new(120, 560, &wh_plane_3);
    if (player->m_type == Player_plane::PlayerC)putimage_new(410, 600, &equiped);
    else putimage_new(410, 600                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            , &equip);
    //���ز˵�
    putimage_new(230, 712, &backmenu);
}

void WHView::INPUT(ExMessage& msg)
{
    if (peekmessage(&msg), EX_SHOWCONSOLE)
    {
        switch (msg.message) 
        {
            case WM_LBUTTONDOWN:
       
            // �ɻ�A
            if (msg.x >= 410 && msg.x <= 410 + 100 && msg.y >= 300 && msg.y <= 300 + 70) {
                // ��ӷɻ�һ��Ӧװ���Ĵ����߼�
                delete player;
                player = new Player_planeA();
            }

            // �ɻ�B
            if (msg.x >= 410 && msg.x <= 410 + 100 && msg.y >= 445 && msg.y <= 445 + 70) {
                // ��ӷɻ�����Ӧװ���Ĵ����߼�
                delete player;
                player = new Player_planeB();
            }

            // C
            if (msg.x >= 410 && msg.x <= 410 + 100 && msg.y >= 600 && msg.y <= 600 + 70) {
                // ��ӷɻ�����Ӧװ���Ĵ����߼�
                delete player;
                player = new Player_planeC();
            }

            // ������ز˵������ж�
            if (msg.x >= 230 && msg.x <= 230 + 180 && msg.y >= 712 && msg.y <= 712 + 60) {
                view_manager.switch_to(ViewManager::ViewType::Menu);
      
            }
        }
    }

}



void WHView::EXIT() {
}