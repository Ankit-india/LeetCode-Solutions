class MyCircularQueue {
public:
    vector<int> arr;
    int front = 0, rear = 0, size = 0;
    MyCircularQueue(int k) {
        arr.resize(k,-1);
        // int front = 0;
        // int rear = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        if(isEmpty()){
            front = 0, rear = 0;
            arr[rear] = value;
            size++;
            return true;
        }
        rear++;
        size++;
        rear = rear % arr.size();
        arr[rear] = value;
        return true;
        
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        arr[front] = -1;
        size--;
        front++;
        front = front % arr.size();
        return true;        
    }
    
    int Front() {
        return arr[front];
    }
    
    int Rear() {
        return arr[rear];
    }
    
    bool isEmpty() {
        return (size == 0);
    }
    
    bool isFull() {
        return (size == arr.size());
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