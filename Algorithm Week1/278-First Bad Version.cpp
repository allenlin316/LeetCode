// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int left = 1;
        long int right = n;
        long int mid;
        while(left <= right){
            mid = (left+right)/2;
            if(!isBadVersion(mid))
                left = mid+1;
            else{
                break;
            }
        }
        while(isBadVersion(mid-1)){
            mid--;
        }
        return mid;
    }
};
