#include<memory>
#include<iostream>
#include<thread>


using namespace std;
typedef int Resource;

shared_ptr<Resource> res;

void thread1() {
    res = make_shared<Resource>(1);
    this_thread::sleep_for(chrono::seconds(5));
    res = nullptr;
    cout<<"thread1 exit"<<endl;
}

void therad2() {
    weak_ptr<Resource> wp(res);
    this_thread::sleep_for(chrono::seconds(1));
    while (1)
    {
        // cout<<wp.lock()<<endl;
        // auto re1(wp.lock());
        auto re = wp.lock();
        // cout<<re1<<endl;
        cout<<re<<endl;
        if(re) {
            cout<<"success"<<endl;
            this_thread::sleep_for(chrono::seconds(1));
        }else {
            cout<<"fail"<<endl;
            break;
        }
    }
    
}



int main() {
    thread t1(thread1);
    thread t2(therad2);
    t1.join();
    t2.join();
}

//g++ -o weak_ptr -std=c++11 weak_ptr.cpp -lpthread