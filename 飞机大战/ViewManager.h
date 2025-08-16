#pragma once
//�������ϵͳ:����״̬����,�������ת
#include "view.h"

//��ȡȫ��ָ��
extern view* menu_view;
extern view* set_view;
extern view* wh_view;
extern view* game_inf_view;
extern view* end_view;

class ViewManager
{
public:

	//ö�ٸ�������,���ڱ�ǵ�ǰ���ڽ���

	enum class ViewType {
		Menu=1,
		Set,
		WH,
		Game_inf,
		End
	};
public:
	ViewManager() = default;
	//�ͷŽ����ȫ��ָ��
	~ViewManager() {
		if(menu_view){ delete menu_view; }
		if (set_view) { delete set_view; }
		if (wh_view) { delete wh_view; }
		if (game_inf_view) { delete game_inf_view; }
		if (end_view) { delete end_view; }
	}
	//���õ�ǰ״̬
	void set_current_view(view* view) {
		current_view = view;
		current_view->ENTER();
	}

	//������ת
	void switch_to(ViewType type) {
		//��������ת����ʱ,������(����)��һ��������״̬
		current_view->EXIT();
		switch (type)
		{
		case ViewType::Menu:
			current_view = menu_view;
			break;
		case ViewType::Set:
			current_view = set_view;
			break;
		case ViewType::WH:
			current_view = wh_view;
			break;
		case ViewType::Game_inf:
			current_view = game_inf_view;
			break;
		case ViewType::End:
			current_view = end_view;
			break;
		default:
			break;
		}
		//��Ϸ����->��ͣ����->����/����/�˳�
		


		//����(����)��һ�������״̬
		current_view->ENTER();
	}

	void UPDATE() {
		current_view->UPDATE();
		//���½���
		//���������߼�
	};
	void DRAW() {
		current_view->DRAW();
		//���ƽ���
	};
	void INPUT(ExMessage& msg) {
		current_view->INPUT(msg);
		//���ܲ�����Ϣ
		//1.�л����� ����� current_viewΪ��Ӧ�����ȫ��ָ��
		//2.���в��� ����ö�Ӧ�ķ���
	};

private:
	//��ǰ�����״̬  
	view* current_view = nullptr;
};