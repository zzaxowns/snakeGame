#include <iostream>
#include <windows.h>

#include "object.h"
#include "map.h"
using namespace std;

int main(){
	
	object* maps = new map(25,50,0,0);

	maps->draw();
	//system("cls"); //ȭ�� �����

	delete maps;
	return 0;
}