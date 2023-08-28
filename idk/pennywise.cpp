#include<bits/stdc++.h>
using namespace std;
        
int main () {
    int hours, minutes, minutes_to_begin;
    cin >> hours >> minutes >> minutes_to_begin;
        
    minutes += minutes_to_begin;
    if(minutes >= 60){
        hours += minutes / 60;
        minutes %= 60;
    }
    if(hours >= 24) hours %= 24;
     
    cout << hours << ":" << minutes << "\n";
}
