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

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> mp;
    for(auto s: strs){
        string aux = s;
        sort(s.begin(), s.end());

        if(mp.count(s))
            mp.at(s).pb(aux);
        else
            mp.insert(pair<string,vector<string>>(s, {aux}));
    }

    vector<vector<string>> ans;
    for(auto m: mp)
        ans.pb(m.second);

    return ans;
}

int main(){ _
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"}; 
    vector<vector<string>> ans = groupAnagrams(strs);

    cout << "[";
    for(auto a: ans){
        cout << "[";
        for(auto an: a){
            cout << an << " ";
        }
        cout << "]";
    }
    cout << "]";
    exit(0);
}
