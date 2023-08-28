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

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);

    int mult_right = 1, mult_left = 1;
    for(unsigned i = 0; i < n; i++){
        ans[i] = mult_left;
        mult_left *= nums[i];
    }

    for(int i = n-1; i >= 0; i--){
        ans[i] *= mult_right;
        mult_right *= nums[i];
    } 
        
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a; cin >> a; v.pb(a);
    }

    vector<int> answer = productExceptSelf(v);
    for(auto a: answer) cout << a << " ";
    cout << endl;
}

int main(){ // _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
