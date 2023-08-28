#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int x, aux, t = 1;
    vector<int> v;

    cin >> aux;
    for(int i = 1; i < n; i++){
        cin >> x;
        if(x == aux) t++;
        else{
            v.push_back(t);
            t = 1;
        }
        aux = x;
    }
    v.push_back(t);
    cout << endl << *max_element(v.begin(), v.end());
}