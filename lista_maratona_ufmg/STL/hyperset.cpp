#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n, m, points = 0, ans = 0; cin >> n >> m;
    vector<vector<char>> s(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        string c; cin >> c;
        for(int j = 0; j < m; j++){
            s.at(i).at(j) = c.at(j);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << s[i][j] << " ";
        cout << endl;
    }
    exit(0);
}
