#include <iostream>
#include <windows.h>
#include <conio.h>
#include <utility>
#include <vector>
//============================

#define HEIGHT 20
#define WIDTH 20

using namespace std;

int map[HEIGHT][WIDTH];
bool gameOver;
int tailX[100], tailY[100];
int tail_Number;
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

	for (int i = 0; i < WIDTH+1; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (j == 0 || j == WIDTH - 1)
				cout << "#";

			if (i == y && j == x)
				cout << "O";
			else if (i == fruit_Y && j == fruit_X)
				cout << "F";
			else {
				bool print = false;
				for (int k = 0; k < tail_Number; k++) {
					if (i == tailY[k] && j == tailX[k]) {
						cout << "o";
						print = true;
					}
				}

				if(!print)
					cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < WIDTH+1; i++)
		cout << "#";
	cout << endl;

	cout << "SCORE: " << score << endl;

	/*for (auto pos : tails) {
		cout << "(" << pos.first << "," << pos.second << ")  ";
	}*/
}

void Input() {
	char key;

	if (_kbhit()) {
		key = _getch();

		switch (key) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;

		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic() {

	int prevX1, prevY1, prevX2, prevY2;
	prevX1 = tailX[0];
	prevY1 = tailY[0];
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < tail_Number; i++) {
		prevX2 = tailX[i];
		prevY2 = tailY[i];
		tailX[i] = prevX1;
		tailY[i] = prevY1;
		prevX1 = prevX2;
		prevY1 = prevY2;
	}

 
	switch (dir) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	if (x< 0 || x>WIDTH || y<0 || y>HEIGHT) {
		gameOver = true;
	}

	for (int i = 0; i < tail_Number; i++) {
		if (x == tailX[i] && y == tailY[i])
			gameOver = true;
	}

	if (x == fruit_X && y == fruit_Y) {
		score += 10;

		fruit_X = rand() % WIDTH;
		fruit_Y = rand() % HEIGHT;
		tail_Number++;
	}
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


