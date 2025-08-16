#pragma once
#include <graphics.h>
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
inline void putimage_new(int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}
class view
{
public:
	view() = default;
	~view() = default;

	virtual void ENTER() {
		//�������,��ʼ����������
	};
	virtual void UPDATE() {
		//���½���
	};
	virtual void DRAW() {
		//���ƽ���
	};
	virtual void INPUT(ExMessage& msg) {
		//���ܲ�����Ϣ
	};
	virtual void EXIT() {
		//�˳�����
	};

private:

};