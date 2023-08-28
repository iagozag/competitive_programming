#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, number, prev_sum, sum = 0; cin >> n;
    vector<int> passage;

    for(int i = 0; i < n; i++){
        cin >> number;
        passage.push_back(number);
    }

    prev_sum  = passage[0];
    for(int i = 0; i < n; i++){
        sum += passage[i];

        if(sum < passage[i])
            sum = passage[i];

        prev_sum = max(prev_sum, sum);
    }

    cout << prev_sum << '\n';
}

