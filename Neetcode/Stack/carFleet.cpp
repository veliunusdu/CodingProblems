// Stack
class Solution{
    public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){
        vector<pair<int, int>> cars;
        for(int i=0; i<position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        vector<double> fleet_arrival_times;
        for(auto& p: cars){
            double time_to_target = (double)(target - p.first) / p.second;
            fleet_arrival_times.push_back(time_to_target);
            if (fleet_arrival_times.size() >= 2 &&
             fleet_arrival_times.back() <= fleet_arrival_times[fleet_arrival_times.size() - 2]){
                fleet_arrival_times.pop_back();
            }
        }

        return fleet_arrival_times.size();
    }
};


// Iteration
class Solution1{
    public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){
        int n = position.size();
        
        vector<pair<int, int>> cars;
        for(int i=0;i<n;i++){
            cars.push_back({position[i], speed[i]});
        }
        
        sort(cars.rbegin(), cars.rend()); 

        int fleets = 0;
        double max_time_to_target = 0.0;

        for(int i=0;i<n;i++){
            double current_car_time = (double)(target - cars[i].first) / cars[i].second;
            
            if(current_car_time > max_time_to_target){
                fleets++; 
                max_time_to_target = current_car_time;
            }
        }
        return fleets;
    }
};