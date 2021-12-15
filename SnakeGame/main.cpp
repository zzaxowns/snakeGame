#include <iostream>
#include <windows.h>
#include <conio.h>
//============================

#include "object.h"
#include "map.h"
#include "snake.h"
#include "moveCommand.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;

int main(){
	
	object* maps = new map(25,50,0,0);
	object* player = new snake(12, 25);
	command* move_Command = new moveCommand(player);

	while (1) {

		//�ʱ�ȭ

		//������Ʈ
	
		input();

		//�׸���
		maps->draw();
		player->draw();
		//�����
		Sleep(100);
		system("cls"); //ȭ�� �����
		Sleep(100);
	}


	delete maps; 
	delete player;

	return 0;
}

void input() {
	char key;

	if (_kbhit()) {
		key = _getch();

		if (key == -32) {    // -32�� �ԷµǸ�
			key = _getch();  // ���� �Է°��� �Ǻ��Ͽ� �����¿� ���
			switch (key) {
			case LEFT:
				printf("�������� �̵�\n");
				break;
			case RIGHT:
				printf("���������� �̵�\n");
				break;
			case UP:
				printf("���� �̵�\n");
				break;
			case DOWN:
				printf("�Ʒ��� �̵�\n");
				break;
			}
		}
	}
}