#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) (int) x.size()
#define ff first
#define ss second
#define int ll

int32_t main() { _
    
    int n, q; cin >> n >> q;
    vector<int> cur(1ll<<n);
    for(int i = 0 ; i < (1ll << n); i ++){
        cur[i] = i;
    }

    while(q --){

        int typ; cin >> typ;
        if(typ == 1){
            int control, target; cin >> control >> target;
            for(auto& el: cur){
                if(el & (1LL << control)){
                    // cout <<"before " << el ;
                    el ^= (1LL << target);
                    // cout << "after " << el << endl;
                }
            }

        } else {
            int c1, c2, target; cin >> c1 >> c2 >> target;

            for(auto& el : cur){
                if((el & (1LL << c1)) and (el & (1LL << c2))){
                    el ^= (1LL << target);
                }
            }
        }

    }

    // for(auto el : cur) cout << el << " ";
    // cout << endl;

    vector<vector<bool>> res(1LL << n, vector<bool>(1LL<< n, 0) );
    int i = 0;
    for(auto el : cur){
        res[i][el] = 1;
        i ++;
    }
    for(auto &row : res){
        for(auto el : row){
            cout << el; 
        }
        cout << endl;
    }

}
