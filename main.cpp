#include <iostream>
#include "GameOfLife.h"

using namespace std;

int main() {
	int height;
	int width;

	cout << "Input the dimensions of the world " << endl;
	cout << "World height: " << endl;
	cin >> height;
	cout << "World width: " << endl;
	cin >> width;

	GameOfLife w (1);
	
	w.printGeneration();

}