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

int MAX = 5*1e5+10;
vector<vi> v(MAX); 
vi num(MAX);

void dfs(int x, int sum){
    for(auto& ve: v[x]){
        num[ve] += sum;
        dfs(ve, sum);
    }
}

void solve(){
    int n, sz = 1; cin >> n;
    for(int i = 0; i < n; i++){
        int op; cin >> op;
        if(op == 1){
            int a; cin >> a; a--;
            v[a].pb(sz), sz++;
        }
        else{
            int a, sum; cin >> a >> sum; a--; 
            num[a] += sum;
            dfs(a, sum);
        }
    }

    for(int i = 0; i < sz; i++) 
        cout << num[i] << " ";
    cout << endl;

    v = vector<vi>(MAX);
    num = vi(MAX);
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
