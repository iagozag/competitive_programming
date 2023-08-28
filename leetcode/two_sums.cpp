#include <algorithm>
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

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> mp;
    for(int i = 0; i < nums.size(); i++)
        mp.insert(nums[i], i);

    for(int i = 0; i < nums.size(); i++){
        int rest = target - nums[i];
        if(mp.count(rest) > 0 && mp[rest] != i)
            return {i, mp[rest]};
    }
    return {};
}

int main(){ _
    vector<int> values({0,4,3,0});
    vector<int> v = twoSum(values, 0);
    
    for(auto n: v) cout << n << " ";
    cout << endl;

    exit(0);
}
