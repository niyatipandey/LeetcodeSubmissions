class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);

        for(auto edge : prerequisites){
            int u = edge[0];
            int v = edge[1];

            graph[v].push_back(u);
        }

        vector<int>indegree(numCourses);

        for(int i=0;i<numCourses;i++){
            for(int x : graph[i]){
                indegree[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>topo;

        while(!q.empty()){
            int x = q.front();
            q.pop();
            topo.push_back(x);

            for(auto it : graph[x]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        vector<int>ans;
        if(topo.size() < numCourses){
            return ans;
        }

        return topo;
    }
};