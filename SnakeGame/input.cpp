#include "input.h"

input::input(int x, int y):object(x,y) {
}

input::~input() {
}

void input::update() {
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

void input::draw() {
}