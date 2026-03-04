#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define ll long long

int main(){
    int n;
    cin >> n;
    while(n != 1){
        if (n % 2){
            n /= 2;
            cout << n;
        }else{
            n = n * 3 + 1;
            cout << n;
        }
    }
    return 0;

}