#include<iostream>
#include<cstring>
#include<memory>
#include<functional>

using namespace std;

int main() {
    int r = 1;
    auto updateLamada = [](int *res) {(*res)++;};
    std::function<void()> callback = std::bind(updateLamada, &r);
    callback();

    cout<<r<<endl;
}
//g++ -std=c++11 -o lamada lamada.cpp
// ./lamada