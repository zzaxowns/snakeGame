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

		//초기화

		//업데이트
	
		input();

		//그리기
		maps->draw();
		player->draw();
		//지우기
		Sleep(100);
		system("cls"); //화면 지우기
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

		if (key == -32) {    // -32로 입력되면
			key = _getch();  // 새로 입력값을 판별하여 상하좌우 출력
			switch (key) {
			case LEFT:
				printf("왼쪽으로 이동\n");
				break;
			case RIGHT:
				printf("오른쪽으로 이동\n");
				break;
			case UP:
				printf("위로 이동\n");
				break;
			case DOWN:
				printf("아래로 이동\n");
				break;
			}
		}
	}
}