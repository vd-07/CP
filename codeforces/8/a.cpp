//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

// debug start
	template <typename A, typename B>
	string to_string(pair<A, B> p);
	 
	template <typename A, typename B, typename C>
	string to_string(tuple<A, B, C> p);
	 
	template <typename A, typename B, typename C, typename D>
	string to_string(tuple<A, B, C, D> p);
	 
	string to_string(const string& s) {
	  return '"' + s + '"';
	}
	 
	string to_string(const char* s) {
	  return to_string((string) s);
	}
	 
	string to_string(bool b) {
	  return (b ? "true" : "false");
	}
	 
	string to_string(vector<bool> v) {
	  bool first = true;
	  string res = "{";
	  for (int i = 0; i < static_cast<int>(v.size()); i++) {
	    if (!first) {
	      res += ", ";
	    }
	    first = false;
	    res += to_string(v[i]);
	  }
	  res += "}";
	  return res;
	}
	 
	template <size_t N>
	string to_string(bitset<N> v) {
	  string res = "";
	  for (size_t i = 0; i < N; i++) {
	    res += static_cast<char>('0' + v[i]);
	  }
	  return res;
	}
	 
	template <typename A>
	string to_string(A v) {
	  bool first = true;
	  string res = "{";
	  for (const auto &x : v) {
	    if (!first) {
	      res += ", ";
	    }
	    first = false;
	    res += to_string(x);
	  }
	  res += "}";
	  return res;
	}
	 
	template <typename A, typename B>
	string to_string(pair<A, B> p) {
	  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
	}
	 
	template <typename A, typename B, typename C>
	string to_string(tuple<A, B, C> p) {
	  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
	}
	 
	template <typename A, typename B, typename C, typename D>
	string to_string(tuple<A, B, C, D> p) {
	  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
	}
	 
	void debug_out() { cerr << endl; }
	 
	template <typename Head, typename... Tail>
	void debug_out(Head H, Tail... T) {
	  cerr << " " << to_string(H);
	  debug_out(T...);
	}
	 
	#ifndef ONLINE_JUDGE
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
	#else
	#define debug(...) 42
	#endif
// end debug


const int mxN = 3e5 + 1;

int cartridges, dollars, recycleRewards, perksCost;
int a[mxN];

pair<int, bool> calculate(int cartridges, int dollars, int recycleRewards, int perksCost, int soldCartridges) {
	long long int leftMoney = 1ll * recycleRewards * soldCartridges;
	leftMoney += 1ll * dollars;

	int leftCartridges = cartridges - soldCartridges;

	long long int perksMoney = leftMoney / (1ll * perksCost);

	// either leftCartridges are the bounding value or the leftMoney
	int perks = min(perksMoney, 1ll * leftCartridges);

	if(perksMoney >= leftCartridges) 
		return {perks, true};

	return {perks, false};
}

int maxPerksItems(int cartridges, int dollars, int recycleRewards, int perksCost) {
	int lo = 0, hi = cartridges;
	int perks = 0;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;

		pair<int, bool> currPerks = calculate(cartridges, dollars, recycleRewards, perksCost, mid);
		perks = max(currPerks.first, perks);

		if(currPerks.second) {
			// need to sell less cartridges
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}

	}
	return perks;
}

int main() {
	string filename;
	cin >> filename;

	 // for getting input from file
	ifstream cin(filename);

	// for writing output to bytes_file
	filename = "bytes_" + filename;
	ofstream cout(filename);

	// for maintaining the count of " character
	bool count = 1;
	// reading characters from file
	char c;

	unsigned long long countRequests = 0, bytesRequests = 0;

	while(cin >> c) {
		if(c == '"') {
			count ^= 1;
			if(count) {
				unsigned long long responseCode, sizeRequest;
				cin >> responseCode >> sizeRequest;

				if(sizeRequest > 5000) {
					countRequests ++;
					bytesRequests += sizeRequest;
				}

			}
		}
	}

	cout << countRequests << endl;
	cout << bytesRequests;

	return 0;
}