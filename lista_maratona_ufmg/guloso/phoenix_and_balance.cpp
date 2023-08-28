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
    int t, n; cin >> t;
    vector<int> powers;
    pair<int,int> sums(0, 0);

    for(int i = 1; i <= 30; i++) powers.pb(pow(2, i));
    
    for(int j = 0; j < t; j++){
        cin >> n;

        for(int i = 1; i <= n; i++){
            if(i < n/2 || i == n) sums.first += powers[i-1];
            else sums.second += powers[i-1];
        }

        cout << abs(sums.f - sums.s) << endl;
        sums.f = 0;
        sums.s = 0;
    }

    exit(0);
}
