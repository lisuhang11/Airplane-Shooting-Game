#include "setview.h"
#include <iostream>
#include <string>
using namespace std;
// ��ǰ�������ƺ�����
std::string music = "����1"; // Ĭ������
int volume = 50;            // Ĭ������

const char* toCString(const std::string& str) {
    return str.c_str();
}

void SetView::ENTER() {
    loadimage(&setview, "../Asset/backgroud/setview.png", 640, 960);
    loadimage(&music1, "../Asset/button/music1.png", 180,60);
    loadimage(&music2, "../Asset/button/music2.png", 180, 60);
    loadimage(&music3, "../Asset/button/music3.png", 180, 60);
    loadimage(&pausemusic, "../Asset/button/pausemusic.png", 180, 60);
    loadimage(&backmenu, "../Asset/button/backmenu.png", 180, 60);
}
void SetView::UPDATE() {

}
void SetView::DRAW() {
    putimage(0, 0, &setview);
    putimage_new(230, 290, &music1);
    putimage_new(230, 380, &music2);
    putimage_new(230, 470, &music3);
    putimage_new(230, 560, &pausemusic);
    putimage_new(230, 710, &backmenu);
   
}
void SetView::INPUT(ExMessage& msg) {
    if (msg.message == WM_LBUTTONDOWN) { // �ж�����������
        // �жϵ�����ְ�ť
        if (msg.x >= 230 && msg.x <= 410) {
            if (msg.y >= 290 && msg.y <= 350) { // ����1
                music = "����1";
                mciSendString("close BGM", 0, 0, 0);
                mciSendString("open ../Asset/Music/1.mp3 alias BGM", 0, 0, 0);
                mciSendString("play BGM repeat", 0, 0, 0); 
            }
            else if (msg.y >= 380 && msg.y <= 440) { // ����2
                music = "����2";
                mciSendString("close BGM", 0, 0, 0);
                mciSendString("open ../Asset/Music/2.mp3 alias BGM", 0, 0, 0);
                mciSendString("play BGM repeat", 0, 0, 0);
            }
            else if (msg.y >= 470 && msg.y <= 530) { // ����3
                music = "����3";
                mciSendString("close BGM", 0, 0, 0);
                mciSendString("open ../Asset/Music/3.mp3 alias BGM", 0, 0, 0);
                mciSendString("play BGM repeat", 0, 0, 0);
            }
            else if (msg.y >= 560 && msg.y <= 620) { // ��ͣ����
                music = "��ͣ";
                mciSendString("pause BGM", 0, 0, 0);
            }
        }
        // ������ذ�ť
        if (msg.x >= 230 && msg.x <= 410 && msg.y >= 710 && msg.y <= 770) {
            view_manager.switch_to(ViewManager::ViewType::Menu); // �л������˵�
            FlushMouseMsgBuffer();
            return;
        }
    }
}
void SetView::EXIT() {

}