#include <iostream>
#include <thread>

using namespace std;

void hello(){
    cout << "Hello";
}

int main(){
    thread t(hello);
    t.join();
}