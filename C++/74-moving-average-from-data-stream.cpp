/*
https://leetcode.com/problems/moving-average-from-data-stream/
*/
class MovingAverage {
    queue<int> q;
    int window_size;
    int count;
    int sum;
public:
    MovingAverage(int size) {
        window_size = size;
        count = 0;
        sum = 0;
    }
    
    double next(int val) {
        if (count < window_size) {
            q.push(val);
            sum += val;
            count++;           
        } else {
            sum -= q.front();
            q.pop();
            q.push(val);
            sum += val;   
        }
        return (double)sum/count;
    }
};

//Implemented this using Deque. Didn't see performance benefit
class MovingAverage {
    deque<int> q;
    int window_size;
    int count;
    int sum;
public:
    MovingAverage(int size) {
        window_size = size;
        count = 0;
        sum = 0;
    }
    
    double next(int val) {
        if (count < window_size) {
            q.push_front(val);
            sum += val;
            count++;           
        } else {
            sum -= q.back();
            q.pop_back();
            q.push_front(val);
            sum += val;   
        }
        return (double)sum/count;
    }
};
