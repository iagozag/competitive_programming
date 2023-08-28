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

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    for(const auto& n: nums)
        mp[n]++;

    priority_queue<pair<int,int>> pq;
    for(const auto& n: mp)
        pq.push({n.second, n.first});

    vector<int> ans;
    while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

int main(){ _
    vector<int> nums = {1,1,1,2,2,3};

    vector<int> ans = topKFrequent(nums, 2);
    for(const auto& n: ans) cout << n << " ";
    cout << endl;

    exit(0);
}
