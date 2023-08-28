#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    cin >> m;
    vector<int> v2(m);
    for(int i = 0; i < m; i++)
        cin >> v2[i];

    bool firstspace = false;
    for(int i = 0; i < n; i++){
        if(find(v2.begin(), v2.end(), v[i]) == v2.end()){
            if(firstspace) cout << " ";

            firstspace = true;
            cout << v[i];
        }
    }

    cout << "\n";
}