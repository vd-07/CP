#include <iostream>
#include <vector>

using namespace std;

void printCurrentPath(vector<pair<int, int>> paths, int pathCount) {
	cout << "Path count : " << pathCount++ << endl;

	for(pair<int, int> coordinate : paths) {
		cout << coordinate.first << " " << coordinate.second << endl;
	}

	cout << endl;
}

bool check(int x, int y, vector<vector<bool>> &visited, int n) {
	return (x < 1 || x > n || y < 1 || y > n || visited[x][y]);
}

void printAllPaths(int x, int y, vector<pair<int, int>> &paths, vector<vector<bool>> &visited, int n, int &pathCount) {
	if(check(x, y, visited, n)) {
		return;
	}

	paths.push_back({x, y});

	if(x == n && y == n) {
		printCurrentPath(paths, pathCount++);

		paths.pop_back();

		return;

	}

	visited[x][y] = true;

	// neighbhours
	printAllPaths(x + 1, y, paths, visited, n, pathCount);
	printAllPaths(x, y + 1, paths, visited, n, pathCount);
	printAllPaths(x - 1, y, paths, visited, n, pathCount);
	printAllPaths(x, y - 1, paths, visited, n, pathCount);

	// unmark and remove it for other possible combinations with the current coordinate

	visited[x][y] = false;

	paths.pop_back();
}

int main() {

    int n;

    cout << "Enter the size of the matrix (N X N) : ";
    cin >> n;

    // to store path
    vector<pair<int, int>> paths;
    // to mark visited
    vector<vector<bool>> visited(n + 1, vector<bool> (n + 1, false));
    int pathCount = 1;

    printAllPaths(1, 1, paths, visited, n, pathCount);

    return 0;
}