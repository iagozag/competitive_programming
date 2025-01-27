#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main() {
    int n = 200000; cout << n << endl;
	for(int i = 0; i < n; i++){
		int l = rand(1, 500000), r = rand(l, 500000);
		cout << l << ' ' << r << endl;
	}
	int q = 300000; cout << q << endl;
	for(int i = 0; i < q; i++){
		int x = rand(1, 500000); cout << x << endl;
	}
}
