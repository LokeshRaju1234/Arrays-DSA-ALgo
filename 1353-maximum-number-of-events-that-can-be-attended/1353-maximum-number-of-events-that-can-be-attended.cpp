class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
       int count = 0,i = 0,n = events.size();
       int day = 1;
       priority_queue<int,vector<int>,greater<int>> pq;
       sort(events.begin(),events.end());

       //process all events efficiently 
       while(i < n || !pq.empty())
       {

        if(pq.empty())
        {
            day = events[i][0];
        }

        while(i < n && events[i][0] == day)
        {
            pq.push(events[i][1]);//push all events that start on this day
            i++;
        }

        while(!pq.empty() && pq.top() < day)
        {
            pq.pop();//the day is expired
        }

        if(!pq.empty())
        {
            pq.pop();
            count++;
            day++;
        }
       }
       return count;
    }
};