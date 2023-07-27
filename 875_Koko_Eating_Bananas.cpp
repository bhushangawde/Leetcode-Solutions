// Binary Search on Answer
class Solution {
public:
    int totalTime(vector<int>& piles, int speed){
        int time = 0;
        for(int i = 0; i < piles.size(); i++){
            time += ceil((double)piles[i]/(double)speed);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        while(start < end){
            int mid = start + (end - start) / 2;
            int time = totalTime(piles, mid);
            if(time > h){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }
        return end;
    }
};