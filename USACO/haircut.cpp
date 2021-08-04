#include <iostream>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds; 

using namespace std;

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

// test cases are really cool and it was so fun trying to solve this easy-medium question 
// really very enjoyable :)

int main() {
	// for getting input from input.txt
	freopen("haircut.in", "r", stdin);
    	// for writing output to output.txt
    	//this can be opted out if you want to print the output to the sublime console
	freopen("haircut.out", "w", stdout);

	int n;

	cin >> n;

	vector<int> a(n);

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<long long int> ans(n + 1);
	vector<int> frequency(n + 1);

	ordered_set X;

	// add inversion count for each element to ans[element]
	for(int i = 0; i < n; i++) {

		int idx = X.order_of_key(a[i]);

		// it is giving the first index of element
		int inversionCount = (int)X.size() - idx - frequency[a[i]];

		X.insert(a[i]);

		frequency[a[i]]++;

		ans[a[i]] += inversionCount;

	}

	// keep summing up previous answers

	long long int sum = 0;

	for(int i = 1; i <= n; i++) {
		cout << sum << "\n";

		int element = i - 1;

		sum += ans[element];
	}

	return 0;
}