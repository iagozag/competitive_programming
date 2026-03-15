#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int32_t main(){
    int a, b, c;
    while(cin >> a >> b >> c and (a or b or c)){
	    if(b-a == c-b) cout << "AP " << 2*c-b << endl;
	    else cout << "GP " << (b/a)*(b/a)*(b/a) * a << endl;
    }
}
