#include<bits/stdc++.h>
using namespace std;
    
#define endl '\n'
#define f first
#define s second
#define pb push_back
    
typedef long long ll;
    
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
    
int main(){
    int n, ans = 0, div; cin >> n;
    vector<int> fact(11);
    
    fact[0] = 1;
    for(int i = 1; i < 11; i++) fact[i] = i * fact[i-1];

    for(int i = 10; i > 0; i--){
        if(n >= fact[i]){
            div = n / fact[i];
            ans += div;
            n -= fact[i] * div;
        }
    }

    cout << ans << endl;

    exit(0);
}
