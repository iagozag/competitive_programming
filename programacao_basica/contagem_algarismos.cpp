#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string num;
    vector<int> v(10);

    for(int i = 0; i < n; i++){
        cin >> num;
        for(int j = 0; j < num.size(); j++){
            switch(num[j]){
                case '0': 
                    v[0]++;
                    break;
                case '1': 
                    v[1]++;
                    break;
                case '2': 
                    v[2]++;
                    break;
                case '3': 
                    v[3]++;
                    break;
                case '4': 
                    v[4]++;
                    break;
                case '5': 
                    v[5]++;
                    break;
                case '6': 
                    v[6]++;
                    break;
                case '7': 
                    v[7]++;
                    break;
                case '8': 
                    v[8]++;
                    break;
                case '9': 
                    v[9]++;
                    break;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        cout << i << " - " << v[i] << endl;
    }
}