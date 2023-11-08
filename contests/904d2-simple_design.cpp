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
    string x; int k; cin >> x >> k;
    if(stoi(x) < k) x = to_string(k);

    int sum = 0;
    for(auto& z: x) sum += z-'0';

    while(sum%k != 0){
        int j = x.size()-1;
        if(x[j] < '9') { x[j]++, sum++; continue; }

        while(x[j] == '9') sum -= 9, x[j] = '0', j--;
        if(x[0] == '0') x[0] = '1', x += "0";
        else x[j]++;

        sum++;
    }

    cout << x << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

