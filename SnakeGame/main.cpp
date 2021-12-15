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

command* move_Command[4];

int main(){
	
	object* maps = new map(25,50,0,0);
	object* player = new snake(12, 25);

	move_Command[0] = new moveCommand(player, 0, -1); //Up
	move_Command[1] = new moveCommand(player, 0, 1);  //Down
	move_Command[2] = new moveCommand(player, -1, 0); //Left
	move_Command[3] = new moveCommand(player, 0, 1);  //Right


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
	delete move_Command;

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
				move_Command[2]->excute();
				break;
			case RIGHT:
				move_Command[3]->excute();
				break;
			case UP:
				move_Command[0]->excute();
				break;
			case DOWN:
				move_Command[1]->excute();
				break;
			}
		}
	}
}