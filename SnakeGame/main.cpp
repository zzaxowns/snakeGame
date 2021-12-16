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
vector<pair<int, int>> tails;
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
				for (auto pos : tails) {
					if (i == pos.second && j == pos.first) {
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

	for (auto pos : tails) {
		cout << "(" << pos.first << "," << pos.second << ")  ";
	}
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

	pair<int, int> new_Tail = {x,y};
	pair<int, int> front_Tail;

	for (auto pos : tails) {
		front_Tail = pos;
		pos = new_Tail;
		new_Tail = front_Tail;
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

	if (x == fruit_X && y == fruit_Y) {
		score += 10;

		fruit_X = rand() % WIDTH;
		fruit_Y = rand() % HEIGHT;
		tails.push_back({ x,y });
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


