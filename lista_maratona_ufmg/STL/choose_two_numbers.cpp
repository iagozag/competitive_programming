#include<bits/stdc++.h>
using namespace std;
    
int main () {
    int n; cin >> n;
    vector<int> a_arr;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        a_arr.push_back(a);
    }
    //cout << endl;
    //for(int i = 0; i < n; i++) cout << a_arr[n] << " ";

    int m; cin >> m;
    vector<int> b_arr;
    for(int i = 0; i < m; i++){
        int be; cin >> be;
        b_arr.push_back(be);
    }
    //cout << endl;
    //for(int i = 0; i < m; i++) cout << b_arr[m] << " ";
    
    int sum;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum = a_arr[i] + b_arr[j];
            if(find (a_arr.begin(), a_arr.end(), sum) == a_arr.end() && 
                    find (b_arr.begin(), b_arr.end(), sum) == b_arr.end()){
                cout << a_arr[i] << " " << b_arr[j] << "\n";
                exit(0);
            }
        }
    }

    exit(0);
}  
