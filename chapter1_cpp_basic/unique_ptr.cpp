#include<memory>
#include<iostream>
#include<cstring>
using namespace std;

unique_ptr<char []>mydumpstr(const char* p) {
    if(p == nullptr) {
        return unique_ptr<char[]>(nullptr);
    }

    size_t len = strlen(p);
    unique_ptr<char []> res(new char[len+1]);
    strcpy(res.get(), p);
    return res;
}

int main() {
    auto res = mydumpstr("123");
    cout<<res.get()<<endl;
}
// g++ -std=c++11 -o unique_ptr unique_ptr.cpp
// ./unique_ptr