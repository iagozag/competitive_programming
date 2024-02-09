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
    string st1, st2; cin >> st1 >> st2;
    int N = st1.size();

    bool flag = false; 
    for(int i = 0; i < N; i++){
        if(st1[i] == '0' && st2[i] == '0' && st1[i+1] == '1' && st2[i+1] == '1'){
            flag = true;
            break;
        }
    }

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
