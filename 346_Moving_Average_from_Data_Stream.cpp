class MovingAverage {
public:
    queue<int> window;
    int capacity;
    double currentAvg;
    MovingAverage(int size) {
        capacity = size;
        currentAvg = 0.0;
    }
    
    double next(int val) {
        window.push(val);
        if(window.size() > capacity){
            int remove = window.front();
            window.pop();
            currentAvg = currentAvg - (double)remove / (double)capacity +  (double)val / (double)capacity;
        }
        else {
            if(currentAvg == 0.0){
                currentAvg = val;
                return currentAvg;
            }
            currentAvg = (currentAvg * ((double)window.size() - 1) + val) / (double)window.size();
        }
        return currentAvg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */