/*
https://leetcode.com/problems/design-circular-queue/
*/
class MyCircularQueue {
    vector<int> q;
    int size;
    int front;
    int rear;
    bool is_empty;
public:
    MyCircularQueue(int k) {
        q.resize(k);
        size = k;
        rear = 0;
        front = 0;
        is_empty = true;
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;
        is_empty = false;
        q[rear] = value;
        rear = (rear + 1) % size;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        front = (front + 1) % size;
        if (front == rear) {
            is_empty = true;
            rear = 0;
            front = 0;
        }
        return true;
    }
    
    int Front() {
        if (isEmpty())
            return -1;
        return q[front];
    }
    
    int Rear() {
        if (isEmpty())
            return -1;
        if (rear > 0)
            return q[rear-1];
        else
            return q[size-1];
    }
    
    bool isEmpty() {
        return is_empty;
    }
    
    bool isFull() {
        return !is_empty && front == rear;
    }
};

