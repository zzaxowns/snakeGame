#include "input.h"

input::input():object(x,y) {
}

input::~input() {
}

void input::update() {
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

void input::draw() {
}