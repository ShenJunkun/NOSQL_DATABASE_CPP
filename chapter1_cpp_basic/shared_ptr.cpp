#include<iostream>
#include<memory>
#include<thread>
using namespace std;

typedef int Resource;

shared_ptr<Resource> createResource(int n) {
    return make_shared<Resource>(n);
}

void user1(shared_ptr<Resource> in) {
    if(in) {
        cout<<"Use resource in therad user1"<<endl;
    }
    return;
}

void user2(shared_ptr<Resource> in) {
    this_thread::sleep_for(chrono::milliseconds(10));
    if(in) {
        cout<<"Use resource in therad user2"<<endl;
    }
    return;
}

int main() {
    shared_ptr<Resource> res = createResource(1);
    thread t1(user1, res);
    thread t2(user2, res);

    t1.join();
    t2.join();
    return 0;
}
