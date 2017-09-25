#include <iostream>
using namespace std;

class GameOfLife {
	public:
		GameOfLife();
		~GameOfLife();
		void createRandomPlanet(int height, int width, float density);
		void createPlanetFromFile(string fileName);
		void printGeneration();
		void simulateGeneration();
	private:
		int height;
		int width;
		int generationCount;
		char** generation;
		char** nextGeneration;
		void getMates(int r, int c);
};