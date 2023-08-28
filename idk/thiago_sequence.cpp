#include<bits/stdc++.h>
using namespace std;
     
int main () {
    int tests_case, number; cin >> tests_case;
        
    int first, second, third, last;
    for(int i = 0; i < tests_case; i++){
        cin >> number;
        first = 0, second = 1, third = 1, last = 2;
            
        for(int j = 3; j < number; j++){
            first = second;
            second = third;
            third = last;
            last = third + second - first;
        }
     
        cout << last << "\n";
    }
}
