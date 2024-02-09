#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main()
{
    long long tests;
    string before;
    cin >> tests;
    long long dec[tests], bin[tests];
    for(int i = 0; i < tests; i++){
        cin>>before;
        dec[i] = 0;
        bin[i] = stoll(before);
        for(int j=0;j<before.size();j++){
            if(bin[i]%10!=0){
                dec[i] = dec[i] + pow(2,j)*(bin[i]%10);
            }
            bin[i] = bin[i] / 10;

        }
    }

    for(int i =0; i < tests;i++){
        cout << dec[i] << endl;
    }
    return 0;
}
