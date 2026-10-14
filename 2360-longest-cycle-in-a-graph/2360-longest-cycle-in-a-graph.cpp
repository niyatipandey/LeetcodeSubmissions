class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>visited(n,0);
        int longest = -1;

        for(int i=0;i<n;i++){
            if(visited[i]){
                continue;
            }
            int node = i;
            int step = 0;
            unordered_map<int,int>seenAt;

            while(node != -1 && !visited[node]){
                visited[node]= 1;
                seenAt[node] = step;

                step++;
                node = edges[node];
            }

            if(seenAt.count(node)){
                int len = step - seenAt[node];
                longest = max(len,longest);
            }
        }
        return longest;
    }
};