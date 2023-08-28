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
    int n, m, ans = 0; cin >> n;
    string t;

    vector<pair<int,string>> vec;
    for(int i = 0; i < n; i++){
        cin >> m >> t;
        vec.pb({m,t});
    }

    string par;
    for(int i = 0; i < vec.size()-1; i++){
        (vec.at(i).second == "D") ? par = "E" : par = "D";

        auto it = find(vec.begin()+i+1, vec.end(), pair<int,string>({vec.at(i).first,par}));
        if(it != vec.end()){
            ans++;
            vec.erase(it);
        }
    }
    cout << ans << endl;

    exit(0);
}
