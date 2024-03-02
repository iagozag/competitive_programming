#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    vector<int> nums(3001, 0);
    while(cin >> n){
       nums[n]++; 
    }
    
    for(int i = 0; i <= 3000; i++){
        if(nums[i] != 0){
            cout << i << ' ' << nums[i] << endl;
        }
    }

    return 0;
}
