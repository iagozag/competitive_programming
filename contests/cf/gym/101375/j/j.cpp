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

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

vector<vector<int>> grid;
int n;
vector<pair<int, int>> mvs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

vector<pair<int, int>> mvs2 = {{1, 0}, {-1, 0}, {0, 1}};
void dfs(int i, int j){
    grid[i][j] = 2;
    for(auto [newi, newj] : mvs2){
        newi += i, newj += j;
        if(newi < 0 or newi >= 3 or newj < 0 or newj >= n) continue;
        if(grid[newi][newj] == 0) dfs(newi, newj);
    }
}

void solve(){
    int t; cin >> n >> t;
    grid.assign(3, vector<int>(n, 0));
    while (t --) {
        int col; char s; cin  >> col >> s; col --;
        string st = "HMS";
        int row;
        for(int i= 0; i < sz(st); i++){
            if(s == st[i]){ row = i; break;}
        }
        for(auto [newi, newj] : mvs){
            newi += row, newj += col;
            if(newi < 0 or newi >= 3 or newj < 0 or newj >= n) continue;
            grid[newi][newj] = -1;
        }
        grid[row][col] = -1;
    }

    bool foi = false;
    for(int i = 0; i < 3; i ++){
        if(grid[i][0] == -1) continue;
        foi =true;
        dfs(i, 0);
    }

    if(!foi) {cout  << "No\n"; return;} 
    
    for(int i = 0; i < 3; i ++){
        if(grid[i][n-1] == 2) { cout << "Yes\n"; return;}
    }
    cout << "No\n";

}

int main(){ _
    int ttt = 1; 
    while(ttt--) solve();

    exit(0);
}

