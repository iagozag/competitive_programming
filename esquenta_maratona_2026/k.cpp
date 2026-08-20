#include <bits/stdc++.h>
using namespace std;

#define _ ios_sync:stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

int32_t main(){
    int a, b; cin >> a >> b;
    if(a == b and a == -1) cout << "NINGUEM" << endl;
    else if(a == -1) cout << "B" << endl;
    else if(b == -1) cout << "A" << endl;
    else if(a == b) cout << "EMPATE" << endl;
    else if(a < b) cout << "A" << endl;
    else cout << "B" << endl;
    exit(0);
}