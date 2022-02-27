class Solution {
public:
    int guessNumber(int n) {
        long int left = 1; long int right = n;
        long int mid;
        while(left <= right){
            mid = (left+right)/2;
            if(guess(mid) == -1)
                right = mid-1;
            else if(guess(mid) == 1)
                left = mid+1;
            else
                return mid;
        }
        return -1;
    }
};

