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

bool is_prime(int n){
    for(int i = 2; i <= sqrt(n); i++)
        if(n%i == 0) return false;
    
    return true;
}

void solve(){
    string str; cin >> str;
    int N = str.size();
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            if(str[j]%2 == 0) continue;

            string num = ""; num += str[i]; num += str[j];
            int p = stoi(num);
            if(is_prime(p)){cout << p << endl; return;}
        }
    }

    cout << -1 << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
