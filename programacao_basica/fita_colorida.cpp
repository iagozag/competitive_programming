#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x = 0; cin >> n;
    vector<int> v(n); 
    vector<int> v1;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < v.size(); i++){
        if(i == 0){
            do{
                x++;
            } while(v[i+x] != 0);
        } else if(i == v.size()-1){
            do{
                x++;
            } while(v[i-x] != 0);
        } else{
            do{
                x++;
            } while(v[i-x] != 0 && v[i+x] != 0);
        }
        if(v[i] == 0){
            v1.push_back(0);
            x = 0;
            continue;
        } else{
            v1.push_back(x);
            x = 0;
        }
    }
    for(auto i:v1) cout << i << " ";
}