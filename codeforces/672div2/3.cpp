#include <iostream>

using namespace std;

bool isValid(int x, int y, int n, int m) {
	return x < n && n >= 0 && y < m && y >= 0;
}

int main() {
	int n, m, p;
	cin >> n >> m >> p;

	bool park[n][m] = {};

	int x, y;
	while(p--) {
		cin >> x >> y;

		for(int i = -2; i <= 2; i++) {
			for(int j = -2; j <= 2; j++) {
				if(abs(i) + abs(j) > 2) {
					continue;
				}

				int nx = x + i;
				int ny = y + j;

				if(isValid(nx, ny, n, m)) {
					park[nx][ny] = true;
				}
			}
		}
	}

	int safePlace = n * m;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			safePlace -= park[i][j];
		}
	}

	cout << safePlace;
	
	return 0;
}