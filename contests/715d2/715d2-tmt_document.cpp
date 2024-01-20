#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; string st; cin >> n >> st;

    int t = 0; bool flag;
    (n%3) ? flag = false : flag = true;
    for(int i = 0; i < n; i++){
        if(st[i]=='T') t++;
        else t--;

        if(t < 0) { flag = false; break; }
    } 
    if(t!=n/3) flag = false;

    t = 0;
    for(int i = n-1; i >= 0; i--){
        if(st[i]=='T') t++;
        else t--;

        if(t < 0) { flag = false; break; }
    }
    if(t!=n/3) flag = false;

    (flag) ? cout << "YES" : cout << "NO";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
