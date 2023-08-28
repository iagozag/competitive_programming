#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n, m, dif, prev = -1; cin >> n;
    int sum = 0;

    for(int i = 0; i < n; i++){
        cin >> m;
        dif = m - prev;
        if(prev > -1 && dif < 10) sum = sum - (10 - dif);

        prev = m;
        sum += 10;
    }

    cout << sum << '\n';
}
