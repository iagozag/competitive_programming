#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "N" << endl; }
void yes(){ cout << "S" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    string s1, s2; cin >> s1 >> s2;
    map<char, int> mp, mp2; 
    forr(x, s1) mp[x]++;
    forr(x, s2) mp2[x]++;

    forr(x, mp){
        if(mp2[x.ff] == x.ss) continue;
        if(mp2[x.ff] > x.ss) return no();
        if(mp2['*'] >= x.ss-mp2[x.ff]) mp2['*'] -= x.ss-mp2[x.ff]; 
        else return no();
    }
    return yes();
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
