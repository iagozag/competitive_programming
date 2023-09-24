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
    int n, m, ans = 0; cin >> n >> m;
    vector<string> v;
    for(int i = 0; i < n; i++){
        string a; cin >> a; v.pb(a);
    }

    string st1, st2, st3; bool flag;
    for(int i = 0; i < n-2; i++){
        st1 = v[i];
        for(int j = i+1; j < n-1; j++){
            st2 = v[j];
            for(int l = j+1; l < n; l++){
                st3 = v[l]; flag = true;
                for(unsigned k = 0; k < st1.size(); k++){
                    if((st1[k] == st2[k] && st3[k] != st1[k]) || 
                       (st1[k] != st2[k] && (st3[k] == st1[k] || st3[k] == st2[k]))){
                        flag = false; break;
                    }
                }
                if(flag) ans++;
            }
        }
    }

    cout << ans << endl;

    exit(0);
}
