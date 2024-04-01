#include <bits/stdc++.h>

using namespace std;
int N, C, T;
vector<int> pipoca;

bool possivel(int m){
    int c=1;
    int sum=0;
    for(int i=0; i<N; i++){
        while(i<N && sum<T*m){
            sum += pipoca[i];
            i++;
        }
        c++;

        if(sum > T*m){
            i--;
            sum=0;
        }


    }
    return c <= C;
}

int main()
{
    int maior=0;
    cin >> N >> C >> T;
    pipoca.resize(N);

    for(int i=0; i<N; i++){
        cin >> pipoca[i];
        if(pipoca[i]>maior) maior = pipoca[i];
    }

    int l = 0;
    int r = maior*N;
    int ans;
    while(l<=r){
        int m = l + (r-l)/2;
        if(possivel(m)){
            ans = m;
            r = m - 1;
        }else{
            l = m + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
