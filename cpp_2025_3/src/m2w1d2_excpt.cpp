#include "../includes/common_include.hpp"

template <typename T>
class Queue
{
public:
    void add(T t)
    {
        unique_lock<mutex> lock(m);
        v.push_back(t);
        cv.notify_all();
    };

    T take()
    {
        unique_lock<mutex> lock(m);
        if(v.empty()){
            // always use predict to prevent spurious wake up
            cv.wait(lock, [this](){return !this->v.empty();});
        }

        if(!v.empty()){
            T &t = v.front();
            v.erase(v.begin());
            return t;
        }else{
            i("error take resumed and v is empty");
            throw std::runtime_error("error take resumed and v is empty");
        }
    }

private:
    condition_variable cv;
    mutex m;
    vector<T> v;
};

int
main()
{
    std::shared_ptr<Queue<int>> q = std::make_shared<Queue<int>>();
    q->add(1);
    auto element = q->take();
    cout << "element: " << element << endl;
    int x = 0;

    Queue<int> p;
    // do not pass value here, because capture in lambda is a copy of the original variable. using pointer or reference
    std::thread producer(
        [q, &x](){
        // int x = 0;
        while(x < 10){
            std::this_thread::sleep_for(std::chrono::seconds(1)); 
            cout << "producer add i :" << x << endl;
            q->add(x++);
        }
    }
);
   std::thread consumer([q, &x](){
        while(x < 10){
            auto val = q->take();
            cout << "consumer takes i : " << val << endl;
        }
    });
producer.join();
consumer.join();
cout << "join threads" << endl;

 
    return 0;
}