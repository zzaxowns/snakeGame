#include <iostream>
#include <windows.h>
//============================

#include "object.h"
#include "map.h"
#include "input.h"
#include "snake.h"

using namespace std;

int main(){
	
	object* maps = new map(25,50,0,0);
	object* input_Key = new input(0,0);
	object* player = new snake(12, 25);

	while (1) {

		maps->draw();
		input_Key->update();

		system("cls"); //화면 지우기
		Sleep(1000);
	}


	delete maps; 
	delete input_Key;

	return 0;
}