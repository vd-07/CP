#include <iostream>
using namespace std;

int n, m, k;
char maze[502][502];
bool done = false;

void dfs(int x, int y, int count = 1) {
	if(x > n || y > m) return;
	if(count == n * m - k) {
		done = true;
	}
	if(done == true) return;
	maze[x][y] = 'O';
	if(maze[x + 1][y] != '#' && maze[x + 1][y] != 'O')
		dfs(x + 1, y, count + 1);
	if(maze[x - 1][y] != '#' && maze[x - 1][y] != 'O')
		dfs(x - 1, y, count + 1);
	if(maze[x][y + 1] != '#' && maze[x][y + 1] != 'O')
		dfs(x , y + 1, count + 1);
	if(maze[x][y - 1] != '#' && maze[x][y - 1] != 'O')
		dfs(x , y - 1, count + 1);
		
}
int main() {
	cin >> n >> m >> k;
	int freex, freey;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> maze[i][j];
			if(maze[i][j] == '.') freex = i, freey = j;
		}
	}
	dfs(freex, freey);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(maze[i][j] != 'O' && maze[i][j] != '#')
				maze[i][j] = 'X';
			if(maze[i][j] == 'O')
				maze[i][j] = '.';	
			cout << maze[i][j];
		}
		cout << endl;
	}
	
	return 0;
}
