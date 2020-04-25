class DisjointUnion {
	let p = [], rank = [];
	constructor(N) {
		for(let i = 1; i <= N; i++) {
			rank[i] = 0;
			p[i] = i;
		}
	}
	findMe(i) {
		return p[i] == i ? i ; p[i] = findMe(p[i]);
	}
	unionMe(i, j) {
		let x = findMe(i), y = findMe(j);
		if( x != y) {
			if(rank[x] > rank[y]) {
				p[y] = x;
			} else {
				p[x] = y;
				if(rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
}

