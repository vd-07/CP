//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

// Function returns the
// minimum number of swaps
// required to sort the array
int minSwaps(int arr[], int n)
{
	// Create an array of
	// pairs where first
	// element is array element
	// and second element
	// is position of first element
	pair<int, int> arrPos[n];
	for (int i = 0; i < n; i++)
	{
		arrPos[i].first = arr[i];
		arrPos[i].second = i;
	}

	// Sort the array by array
	// element values to
	// get right position of
	// every element as second
	// element of pair.
	sort(arrPos, arrPos + n);

	// To keep track of visited elements.
	// Initialize
	// all elements as not visited or false.
	vector<bool> vis(n, false);

	// Initialize result
	int ans = 0;

	// Traverse array elements
	for (int i = 0; i < n; i++)
	{
		// already swapped and corrected or
		// already present at correct pos
		if (vis[i] || arrPos[i].second == i)
			continue;

		 
		int cycle_size = 0;
		int j = i;
		while (!vis[j])
		{
			vis[j] = 1;

			// move to next node
			j = arrPos[j].second;
			cycle_size++;
		}

		// Update answer by adding current cycle.
		if (cycle_size > 0)
		{
			ans += (cycle_size - 1);
		}
	}

	// Return result
	return ans;
}

// Driver program to test the above function

int32_t main() {
	#ifdef CODINGINVEINS
	    // for getting input from input.txt
		freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    //this can be opted out if you want to print the output to the sublime console
		freopen("output.txt", "w", stdout);
	#endif

	// for fast i/o
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	// test cases
	int t = 1;
	cin >> t;
	for(int i = 0; i < t; ++ i) {
		int arr[t];
		for(int j = i; j < t; ++ j) {
			arr[j] = j - i + 1;
		}
		for(int j = 0; j < i; ++ j) {
			arr[j] = t - j;
		}
		reverse(arr, arr + i);
		for(int i = 0; i < t; ++ i) {
			cerr << arr[i] << " ";
		}
		cerr << "\n";
		cout << minSwaps(arr, t) << "\n";
	}

	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif
    	
	return 0;
}