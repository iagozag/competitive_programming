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
    int t, n; cin >> t;
    while(t--){
        cin >> n;
        vector<int> num;
        for(int i = 0; i < n; i++){
            int a; cin >> a; num.pb(a);
        }
        sort(num.begin(), num.end());

        vector<int> ans;
        int mid = n/2;
        if(n%2 == 1){
            ans.pb(num.at(mid));
            num.erase(num.begin()+mid);
        }
        for(int i = 0; i < n/2; i++){
            ans.pb(num.at(mid-1-i));
            ans.pb(num.at(mid+i)); 
        }

        for(auto j: ans)
            cout << j << " ";
        cout << endl;
    }
    exit(0);
}
