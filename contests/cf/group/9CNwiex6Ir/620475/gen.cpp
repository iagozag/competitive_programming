#include <bits/stdc++.h>
using namespace std;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int rand(int a, int b) {
    return uniform(a, b);
}

int main() {
	int n = rand(2, 10000), m = rand(1, 10);
	cout << n << ' ' << m << endl;
	for(int j = 0; j < n; j++){
		for(int i = 0; i < m; i++) cout << (char)(rand(0, 25)+'a');
		cout << endl;
	}
}
