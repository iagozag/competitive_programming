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
    int t, m, n; cin >> t;
    
    while(t--){
        cin >> m >> n;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                (i == 0 && j == 0) ? cout << "W" : cout << "B";
            }
            cout << endl;
        }
    }
    exit(0);
}
