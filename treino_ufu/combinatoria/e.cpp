#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

long long comb(long long x, long long y){
    long long num = 1;
    while(x != y){
        num *= x;
        x--;
    }
    
    return num;
}

int main(){ _
    while(1){
        long long x, y; cin >> x >> y;
        if(x == 0 && y == 0) break;
        
        long long num = comb(x, x-y);
        long long num2 = comb(y, 1);
        cout << num/num2 << endl;
    }

    return 0;
}
