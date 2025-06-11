class Solution {
public:
    unordered_map<string,int>Keys;
    unordered_map<string,unordered_map<string,double>>graph;
    double dfs(string &vertex,double &maxAns)
     {


        return maxAns; 
     }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        double ans=1.0;
        ////creating graph
        for(int i=0;i<pairs1.size();i++)
         {
            graph[pairs1[i][0]][pairs1[i][1]]=rates1[i]; 
            graph[pairs1[i][1]][pairs1[i][0]]=1/rates1[i]; 
         }
        graph.clear();
        ans=dfs(pairs1[0][0],stod(initialCurrency));
        for(int i=0;i<pairs2.size();i++)
         {
            graph[pairs2[i][0]][pairs2[i][1]]=rates2[i]; 
            graph[pairs2[i][1]][pairs2[i][0]]=1/rates2[i]; 
         }  
        ans=dfs(pairs2[0][0],stod(initialCurrency));
        return ans;
    }
};