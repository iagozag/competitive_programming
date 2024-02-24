#include <bits/stdc++.h>

using namespace std;

string doSum(string a, string b)
{
    if(a.size() < b.size())
        swap(a, b);

    int j = a.size()-1;
    for(int i=b.size()-1; i>=0; i--, j--)
        a[j]+=(b[i]-'0');

    for(int i=a.size()-1; i>0; i--)
    {
        if(a[i] > '9')
        {
            int d = a[i]-'0';
            a[i-1] = ((a[i-1]-'0') + d/10) + '0';
            a[i] = (d%10)+'0';
        }
    }
    if(a[0] > '9')
    {
        string k;
        k+=a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        a = k+a;
    }
    return a;
}

int main(){
    int n; cin >> n;
    vector<string> fib(n);
    fib[0] = "1"; fib[1] = "1"; fib[2] = "1";
    
    for(int i = 3; i < n; i++){
        fib[i] = doSum(doSum(fib[i-1], fib[i-2]), fib[i-3]);
    }
    
    cout << fib[n-1] << endl;

    return 0;
}
