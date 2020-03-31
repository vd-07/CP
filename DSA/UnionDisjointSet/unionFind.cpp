#include <iostream>
#include <vector>
using namespace std;
//constructor UnionFind(int N) to initialize the Union ds for elements of size of N

// findSet(int node) -> find the parent of the node

// isSameSet(int node1, int node2) -> checks if both the nodes belong to the same set

//unionSet(itn node1, int node2) -> joins the two sets containing node1 and node2
//			It also maintains the rank of the root representing the union

// numDisjointSets() -> returns the number of disjoint sets

// sizeofSet(int node) -> returns the size of the set in which the node is present
class UnionFind {
	private:
	vector<int> p, rank;
	public:
	UnionFind(int N) {
		rank.assign(N, 0);
		p.assign(N, 0);
		for(int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int  i, int j) {
		if(!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y])
				p[y] = x;
			else {
				p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}	
	int numDisjointSets() {
		int count = 0;
		for(int  i = 0; i < p.size(); i++) {
			if(p[i] == i)
				count++;
		}
		return count;
	}
	int sizeofSet(int i) {
		int parent = findSet(i);
		int count = 0;
		for(int i = 0; i < p.size(); i++) {
			if(p[i] == parent)
				count++;
		}
		return count;
	}
};


	
int main() {
	UnionFind ufds(8);
	for(int i = 0; i < 7; i += 2)
	ufds.unionSet(i, i + 1);
	ufds.unionSet(0, 2); ufds.unionSet(4, 6);
	ufds.unionSet(0, 7);
	for(int i = 0; i < 7; i++) {
		cout<<i<<" -> "<<ufds.isSameSet(i, i+1)<<" -> "<<i+1<<endl;
	}
}