#include <iostream>
#include "GameOfLife.h"

using namespace std;

int main() {
	int height;
	int width;
	float density;

	cout << "Input the dimensions of the world " << endl;
	cout << "World height: " << endl;
	cin >> height;
	cout << "World width: " << endl;
	cin >> width;
	cout << "World density: " << endl;
	cin >> density;
	GameOfLife p (1);
	p.createRandomPlanet(height, width, density);
	p.printGeneration();
	p.simulateGeneration();
	p.printGeneration();

}