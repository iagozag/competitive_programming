#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, total = 0; cin >> n;
    vector<int> v(n);
    vector<int> v2;
    set<int> s;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        v2.push_back(v[i]);
    }
    sort(v2.begin(), v2.end());

    for(int i = 0; i < n; i++){
        if(v[i] != v2[i]) s.insert(v[i]);
    }
    cout << s.size() << endl;
    for(auto i:s) cout << i << " ";
}