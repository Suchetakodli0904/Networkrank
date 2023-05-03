

int maximalNetworkRank(int n, vector<vector<int>>& roads){
        int result = 0;
        vector<vector<bool>>graph(n,vector<bool>(n,0));
        vector<int>degrees(n,0);
        for(int i=0;i<roads.size();i++){
            degrees[roads[i][0]]++;
            degrees[roads[i][1]]++;
            graph[roads[i][0]][roads[i][1]]=1;
            graph[roads[i][1]][roads[i][0]]=1;
        }
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                result = max(result,(degrees[i]+degrees[j]-(graph[i][j]? 1 : 0)));
        return result;
    }
