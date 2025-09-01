class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [&](int p, int t) {
            return (double)(p+1)/(t+1) - (double)p/t;
        };

        priority_queue<pair<double, pair<int,int>>> pq;

        for(int i=0; i<classes.size(); i++){
            int p = classes[i][0], t = classes[i][1];
            pq.push({gain(p,t), {p,t}});
        }

        while(extraStudents--){
            auto top = pq.top(); pq.pop();
            int p = top.second.first;
            int t = top.second.second;
            p++; t++;
            pq.push({gain(p,t), {p,t}});
        }

        double ratiosum = 0.0;
        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            int p = top.second.first;
            int t = top.second.second;
            ratiosum += (double)p/t;
        }

        return ratiosum / classes.size();
    }
};