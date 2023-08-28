#include<bits/stdc++.h>
using namespace std;
        
int main () {
    int n, m, difference = 1001; cin >> n >> m;
    vector<int> puzzles(m);
     
    for(int i = 0; i < m; i++)
        cin >> puzzles[i];
     
    sort(puzzles.begin(), puzzles.end());
    //for(auto i: puzzles) cout << i << " ";
     
    for(int i = 0; i <= m-n; i++){
        difference = min(difference, puzzles[n-1] - puzzles[i]);
        n++;
        m++;
    }
     
    cout << difference << "\n";
}
