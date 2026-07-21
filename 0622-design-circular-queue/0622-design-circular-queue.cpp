class MyCircularQueue {
public:
    vector<int> v;
    int cs=0;
    int n=0;
    int f;
    int e;
    MyCircularQueue(int k) {
        v.resize(k);
        n=k;
        f=0;
        e=n-1;
    }
    
    bool enQueue(int value) {
        if(cs>=n){
            return false;
        }
        e=(e+1)%n;
        v[e]=value;
        cs++;
        return true;
    }
    
    bool deQueue() {
        if(cs<=0){
            return false;
        }
        f=(f+1)%n;
        cs--;
        return true;
    }
    
    int Front() {
        if(cs==0){
            return -1;
        }
        return v[f];
    }
    
    int Rear() {
        if(cs==0){
            return -1;
        }
        return v[e];
    }
    
    bool isEmpty() {
        if(cs==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(cs==n){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */