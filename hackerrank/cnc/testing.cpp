#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
//from cp-algorithm
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
 
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
   
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
 
void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}
 
int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;
 
    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;
 
    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;
 
    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;
 
    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;
 
    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;
 
    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);
 
    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}
 
int a, b, n, s;
 
 #define ll int

int solve2() {
       if(a * n + b < s) {
        return 0;
    }
    if(a * n < s) {
        return 1;
    }
    else {
        if(b >= (s%n)) {
            return 1;
        }
        return 0;
    }
 
}
int solve1() {
    if(find_all_solutions(n, 1, s, 0, a, 0, b))
        return 1;
    else
        return 0;
}

int main() {
    srand(time(0));
    while(1) {
        int range = 1000000;
        a = (rand() % range) + 1, b = (rand() % range) + 1, n = (rand() % range) + 1, s = (rand() % range) + 1;
        cout << a << " " << b << " " << n << " " << s << endl;
        if(solve1() != solve2()) {
            cout << solve1(); break;
        }
    }
    return 0;
}

