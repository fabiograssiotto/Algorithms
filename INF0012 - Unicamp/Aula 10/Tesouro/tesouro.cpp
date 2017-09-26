#include <iostream>
using namespace std;

int adjMatrix[1000][1000];
int treasure[1000];

void init() {
	for (int i = 0; i < 1000; i++) {
		treasure[i] = 0;
		for (int j = 0; j < 1000; j++) {
			adjMatrix[i][j] = 0;
		}
	}
}

int main() {
	while (1) {
		init();
		int totalTreasure = 0;

		// input
		int rooms;
		cin >> rooms;
		if (rooms == 0) {
			break;
		}
		for (int i = 0; i < rooms; i++) {
			int corridors;
			cin >> treasure[i];
			cin >> corridors;
			for (int j = 0; j < corridors; j++) {
				int nextRoom;
				cin >> nextRoom;
				adjMatrix[i][nextRoom] = 1;
			}
		}

		// Output
		cout << totalTreasure << endl;
	}
}