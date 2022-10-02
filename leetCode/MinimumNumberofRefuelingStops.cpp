//LeetCode : 871. Minimum Number of Refueling Stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        pq.push(startFuel);
        int res=0;
        int i=0;
        int sf=0;
        while(!pq.empty() && sf<target)
        {
            sf+=pq.top();
            pq.pop();
            res++;
            while(i<stations.size() && stations[i][0]<=sf)
            {
                pq.push(stations[i][1]);
                i++;
            }
        }
        if(sf<target)   return -1;
        return res-1;       
    }
};
