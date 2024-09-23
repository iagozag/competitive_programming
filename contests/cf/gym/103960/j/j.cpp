#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

int main() { _
    int n;
    cin >> n;

    vi v(n);
    mii m;
    for(int i=1;i<10;i++) m.insert({i,4});
    m.insert({10,16});

    int a,b;
    cin >> a >> b;
    a = min(10,a);
    b = min(10,b);
    m.at(a)--;
    m.at(b)--;
    int j = a+b;
    
    cin >> a >> b;
    a = min(10,a);
    b = min(10,b);
    m.at(a)--;
    m.at(b)--;
    int ma = min(a,10)+min(b,10);

    for(int i=0;i<n;i++) {
        cin >> v[i];
        ma += min(10,v[i]);
        j +=min(10,v[i]);
        m.at(min(v[i],10))--;
    }
    
    int fm = 23-ma, fj = 23-j;

    if(j<=ma) {// maria tem mais ou igual, logo tem q fazer 23 se n estora
        if(m.at(fm)) cout << fm << '\n';
        else cout << -1 << '\n';
    } else { // joao tem mais, tem q estorar ele
        for(int i=fj+1;i<11;i++) {
            if(i>fm) {
                cout << "-1\n";
                return 0;
            }
            if(m.at(i)) {
                cout << i << '\n';
                return 0;
            }
        }
        cout << "-1\n";
    }

    return 0;
}
