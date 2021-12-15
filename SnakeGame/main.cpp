#include <iostream>
#include <windows.h>
#include <conio.h>
//============================

#include "object.h"
#include "snake.h"
#include "moveCommand.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define HEIGHT 25
#define WIDTH 20

using namespace std;

int map[HEIGHT][WIDTH];

command* move_Command[4];
object* player;
int main(){
	
	player = new snake(10, 10);

	move_Command[0] = new moveCommand(player, 0, -1); //Up
	move_Command[1] = new moveCommand(player, 0, 1);  //Down
	move_Command[2] = new moveCommand(player, -1, 0); //Left
	move_Command[3] = new moveCommand(player, 0, 1);  //Right


	while (1) {

		//�ʱ�ȭ
		init_map();

		//������Ʈ
		update();

		//�׸���
		draw();
		
		//�����
		Sleep(100);
		system("cls"); //ȭ�� �����
		Sleep(100);
	}



	delete player;
	delete move_Command;

	return 0;
}

void update() { 
	input(); // Ű �Է�
	map[player->x][player->y] = '0';
}

void init_map() { 
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1)
				map[i][j] = '#';
		}
	}
}

void draw() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
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