#include <iostream>
#include <vector>

using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    long long n;
    cin >> n;

    bool done = false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0 && isPrime(i) && isPrime(n / i)) {
            done = true;
            break;
        }
    }

    if (done) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}
