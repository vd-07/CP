#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;

int t[4 * MAXN];

void build(vector<int> &inputArray, int v, int l, int r) {
	if(l == r) {
		t[v] = inputArray[l];
	} else {
		int mid = (l + r) / 2;

		build(inputArray, 2 * v, l, mid);
		build(inputArray, 2 * v + 1, mid + 1, r);

		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if(l > r) {
		return 0;
	}

	if(l == tl and r == tr) {
		return t[v];
	}

	int tm = (tl + tr) / 2;

	return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
	if(tl == tr) {
		t[v] = new_val;
	} else {
		int tm = (tl + tr) / 2;

		if(pos <= tm) {
			update(v * 2, tl, tm, pos, new_val);
		} else {
			update(v * 2 + 1, tm + 1, tr, pos, new_val);
		}
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

int countSetBits(int num) {
	int count = 0;

	while(num) {
		count += (num % 2);
		num /= 2;
	}

	return count;
}

vector<string> solveOddSetBit(vector<int> inputArray, vector<vector<int>> queryArray) {
	for(int &i : inputArray) {
		i = ((countSetBits(i)) & 1);
	}

	int n = inputArray.size();

	build(inputArray, 1, 0, n - 1);

	vector<string> ans;

	for(vector<int> v : queryArray) {
		if(v[0] == 1) {
			int count = query(1, 0, n - 1, v[1] - 1, v[2] - 1);
			if(count <= v[3]) {
				ans.push_back("YES");
			} else {
				ans.push_back("NO");
			}
		} else {
			v[2] = (countSetBits(v[2]) & 1);

			update(1, 0, n - 1, v[1] - 1, v[2]);
		}
	}

	return ans;
}

int main() {
	int N;
	cin >> N;

	vector<int> inputArray(N);
	for(int i = 0; i < N; ++ i) {
		cin >> inputArray[i];
	}

	int Q;
	cin >> Q;
	int query_input;
	cin >> query_input;

	vector<vector<int>> queryArray(Q, vector<int> (query_input));

	for(int i = 0; i < Q; ++ i) {
		for(int j = 0; j < 4; ++ j) {
			cin >> queryArray[i][j];
		}
	}

	vector<string> out;

	out = solveOddSetBit(inputArray, queryArray);

	for(int i = 0; i < out.size(); ++ i) {
		cout << out[i] << "\n";
	}
}