// Simplified Binary Search 
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        while(start < end){
            int mid = start + (end - start) / 2;

            if(arr[mid] < arr[mid + 1]){
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }

        return end;
    }
};

// or 

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;

            if(arr[mid] < arr[mid + 1]){
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }

        return end;
    }
};

// Binary Search 
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(mid - 1 >= 0 && arr[mid] > arr[mid - 1] && mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
                return mid;

            if(mid + 1 < arr.size() && arr[mid] < arr[mid + 1]){
                start = mid + 1;
            } 
            else if(mid - 1 >= 0 && arr[mid - 1] > arr[mid]){
                end = mid - 1;
            }
        }

        return -1;
    }
};