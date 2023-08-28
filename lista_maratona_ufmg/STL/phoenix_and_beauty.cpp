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
    int t, n, k; cin >> t;
    while(t--){
        cin >> n >> k;
        set<int> num;
        for(int i = 0; i < n; i++){
            int a; cin >> a; num.insert(a);
        }
        
        if(num.size() > k){
            cout << -1 << endl;
            continue;
        }

        cout << n*k << endl;
        for(int i = 0; i < n; i++){
            for(auto a: num) 
                cout << a << " ";
            for(unsigned j = 0; j < k-num.size(); j++)
                cout << 1 << " ";
        }
        cout << endl;
    }

    exit(0);
}
