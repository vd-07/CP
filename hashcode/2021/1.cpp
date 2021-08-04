//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

int D, I, S, V, F;

map<string, array<int, 3>> streets;
map<int, vector<string>> paths;
map<int, vector<string>> intersections;
vector<int> waitTime; 
map<string, vector<int>> currQueue;
map<string, int> ans;
map<int, bool> done;


void inputStreets() {

	for(int i = 1; i <= S; i++) {
		int B, E;
		string streetName;
		int L;

		cin >> B >> E;

		cin >> streetName;

		cin >> L;

		streets[streetName] = {B + 1, E + 1, L};

		intersections[E + 1].push_back(streetName);
	}
	
}

void inputCars() {

	waitTime = vector<int> (V + 1, 0);

	// intersect = vector<int> (I + 1, 0);

	for(int i = 1; i <= V; i++) {
		int P;
		string streetName;

		cin >> P;

		for(int j = 1; j <= P; j++) {

			cin >> streetName;

			// cars start at the end of the first street

			// traffic lights will be equal to the no of streets at each intersection

			// o/p is 
			// intersection id : {street name, T}
			// traffic light can be green atmost once

			paths[i].push_back(streetName);
		}

		reverse(paths[i].begin(), paths[i].end());
	}

}

void populate(int t) {
	for(int i = 1; i <= V; i++) {
		// only end matters
		if(paths[i].empty()) {
			// done
			continue;
		}

		string curr = paths[i].back();

		if(waitTime[i] == t) {
			// done
			paths[i].pop_back();

			int currInters = streets[curr][1];

			waitTime[i] += streets[curr][2];

			currQueue[curr].push_back(i);
		}
	}
}

void recalculate(string curr, int cycle) {
	int done = 0;
	for(int car : currQueue[curr]) {

		waitTime[car] += done++;
	}
}

void decide() {
	// over all intersections
	for(int i = 1; i <= I; i++) {
		// calc the no of cars at the current 

		if(done[i]) {
			continue;
		}

		vector<pair<int, string>> curr;

		for(string s : intersections[i]) {

			int cars = currQueue[s].size();

			curr.push_back({cars, s});

		}

		sort(curr.begin(), curr.end());

		for(int i = 0; i < curr.size(); i++) {
			done[i] = true;

			ans[curr[i].second] = curr[i].first;

			recalculate(curr[i].second, curr[i].first);
		}

		// after this the waitTimeing time will change

		// for that i need to recalc the waitTime vector

	}


}


void simulation() {
	populate(0);
	for(int i = 1; i <= D; i += 100) {
		populate(i);
		cerr << i << "\n";
		decide();
	}
}

vector<string> findAns(vector<string> s) {
	vector<string> curr;

	for(string t : s) {
		if(ans[t]) {
			curr.push_back(t);
		}
	}

	return curr;
}

void printAns() {

	vector<pair<int, vector<string>>> real;

	for(int i = 1; i <= I; i++) {
		// cout << i - 1 << "\n";
		// cout << intersections[i].size() << "\n";

		// for(string s : intersections[i]) {
		// 	cout << s << " " << ans[s] << "\n";
		// }

		vector<string> curr = findAns(intersections[i]);

		if(curr.empty()) {
			continue;
		}	

		real.push_back({i - 1, curr});
		// cout << i - 1 << "\n";	
		// cout << curr.size() << "\n";

		// for(string s : curr) {
		// 	cout << s << " " << ans[s] << "\n";
		// }
	}

	cout << real.size() << "\n";

	for(pair<int, vector<string>> obj : real) {
		cout << obj.first << "\n";

		cout << obj.second.size() << "\n";

		for(string s : obj.second) {
			cout << s << " " << ans[s] << "\n";
		}
	}
}

int main() {
	freopen("f.txt", "r", stdin);
	freopen("o6.txt", "w", stdout);

	cin >> D >> I >> S >> V >> F;

	inputStreets();

	inputCars();
	
	simulation();

	printAns();

	return 0;
}