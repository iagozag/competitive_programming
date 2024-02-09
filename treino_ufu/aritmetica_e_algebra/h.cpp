#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    long long verify;
    double nota, inicio, fim;
    vector<string> dentro;
    cin >> verify;

    for(int i =0; i< verify;i++){
        cin>>nota>>inicio>>fim;
        if (nota>inicio and nota<fim){
            dentro.push_back("True");
        }else{
            dentro.push_back("False");
        }
    }

    for(auto it: dentro){
        cout << it << endl;
    }

    return 0;
}
