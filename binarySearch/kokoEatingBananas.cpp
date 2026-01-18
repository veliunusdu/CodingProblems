// Brute Force
class Solution{
    public:
    int minEatingSpeed(vector<int>& piles, int h){
        int speed = 1;
        while(true){
            long long totalTime = 0;
            for(int pile : piles){
                totalTime += (pile + speed - 1) / speed;
            }
            if(totalTime <= h){
                return speed;
            }
            speed++;
        }
    }
};


// Binary Search
class Solution{
    public:
    int minEatingSpeed(vector<int>& piles, int h){
        int lowSpeed = 1;
        int highSpeed = *max_element(piles.begin(), piles.end());
        int ans = highSpeed;
        while(lowSpeed <= highSpeed){
            int currentSpeed = lowSpeed + (highSpeed - lowSpeed) / 2; // Prevent potential overflow
            long long hoursTaken = 0;
            for(int pile : piles){
                hoursTaken += (pile + currentSpeed - 1) / currentSpeed; // Equivalent to ceil(pile / currentSpeed) for integers
            }
            if(hoursTaken <= h){
                ans = currentSpeed;
                highSpeed = currentSpeed - 1;
            }
            else{
                lowSpeed = currentSpeed + 1;
            }
        }
        return ans;
    }
};