class Solution {
public:
    void sortColors(vector<int>& arr) {
        int high = arr.size() - 1;
        int low = 0;
        int mid = 0;
        
        while(mid <= high){
            switch(arr[mid]){
                case 0:
                    swap(arr[low], arr[mid]);
                    low++; mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(arr[high],arr[mid]);
                    high--;
                    break;
            }
        }
        
        return; 
        
    }
};