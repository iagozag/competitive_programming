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
    int t; cin >> t;
    ll x, y, a, b, sum = 0;
    for(int i = 0; i < t; i++){
        cin >> x >> y >> a >> b;

        if(x > y) swap(x, y);
        sum += (y-x) * a;

        if(2 * a < b) sum += 2*x*a;
        else sum += x*b;
        
        cout << sum << endl;
        sum = 0;
    }
    
    exit(0);
}
