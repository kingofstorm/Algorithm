class Solution {
    public:
        vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
            vector<int> result;
            if(n==1) { result.push_back(0); return result; }
            vector<unordered_set<int>> graph(n, unordered_set<int>());
            for(int i=0; i<edges.size(); i++){
                graph[edges[i].first].insert(edges[i].second);
                graph[edges[i].second].insert(edges[i].first);
            }
            vector<int> degree(n, 0);
            for(int i=0; i<n; i++){
                degree[i]=graph[i].size();
                cout<<i<<":"<<degree[i]<<endl;
            }
            int count=n;
            while(count>2){
                vector<int> record;
                for(int i=0; i<n; i++){
                    if(degree[i]==1) {
                        count--;
                        degree[i]=-1;
                        record.push_back(i);
                    }
                }
                for(int i=0; i<record.size(); i++){
                    for(auto it : graph[record[i]])  degree[it]--;
                }
            }
            for(int i=0; i<n; i++){
                if(degree[i]==1 || degree[i]==0)  result.push_back(i);
            }
            return result;
        }
    };
