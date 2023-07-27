class Solution {
public:
    
    double calculateTime(vector<int>& dist, double hour, int speed){
        double time = 0.0;
        for(int i = 0 ; i < dist.size() - 1; i++){
            time += ceil((double)dist[i] / (double) speed);
        }
        time += (double)dist[dist.size() - 1] / (double)speed;
        return time;
    }


    int minSpeedOnTime(vector<int>& dist, double hour) {
        int start = 1;
        int mid;
        int end = 10000000;
        double lastTrainTime = (double)dist[dist.size() - 1] / (double) end;

        if(hour < dist.size() - 1 + lastTrainTime){
            return -1;
        }        
        while(start < end){
            int mid = start + (end - start)/2;
            double time = calculateTime(dist, hour, mid);
            if(time > hour){
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return end;
    }
};