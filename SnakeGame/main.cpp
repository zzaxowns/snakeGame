#include <iostream>
#include <windows.h>
#include <conio.h>
//============================

#define HEIGHT 20
#define WIDTH 20

using namespace std;

int map[HEIGHT][WIDTH];
bool gameOver;

int x, y, fruit_X, fruit_Y, score;

enum Direction {
	STOP = 0,
	LEFT, 
	RIGHT, 
	UP, 
	DOWN
};

Direction dir;

void Setup() {
	gameOver = false;
	dir = STOP;
	x = WIDTH / 2;
	y = HEIGHT / 2;
	fruit_X = rand() % WIDTH;
	fruit_Y = rand() % HEIGHT;
	score = 0;
}

void Draw() {
	system("cls");

	for (int i = 0; i < WIDTH; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (j == 0 || j == WIDTH - 1)
				cout << "#";
			else
				cout << " ";

			if (i == y && j == x)
				cout << "O";
			else if (i == fruit_Y && j == fruit_X)
				cout << "F";
			else
				cout << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < WIDTH; i++)
		cout << "#";
	cout << endl;
}

void Input() {
	char key;

	if (_kbhit()) {
		key = _getch();

		if (key == -32) {    // -32로 입력되면
			key = _getch();  // 새로 입력값을 판별하여 상하좌우 출력
			switch (key) {
			case LEFT:

				break;
			case RIGHT:

				break;
			case UP:

				break;
			case DOWN:

				break;
			}
		}
	}
}

void Logic() {

}

int main(){

	Setup();

	while (!gameOver) {
		Draw();
		Input();
		Logic();

	}

	return 0;
}


