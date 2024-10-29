#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main() {
    int n = rand(1, 30), m = rand(1, 30), q = rand(1, 30);
    cout << n << m << q;
    for(int i = 0; i < q; i++){
        int ok = rand(0, 1), a, b, c, d;
        if(ok) a = rand(1, n), b = rand(1, m), c = a, d = rand(1, m);
        else a = rand(1, n), b = rand(1, m), c = rand(1, n), d = b;
        cout << a << " " << b << " " << c << " " << d << endl;
    }
}
