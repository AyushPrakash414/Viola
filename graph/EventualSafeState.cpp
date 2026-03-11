#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool dfs(int src,vector<int>&visited,vector<int>&path,vector<vector<int>>&grid)
      {
          visited[src]=1;
          path[src]=1;
          for (int i=0;i<grid[src].size();i++)
          {
              if (visited[grid[src][i]]==0&&path[grid[src][i]]==0)
              {
                  if (dfs(grid[src][i],visited,path,grid))
                    return true;
              }
              else
              {
                  if (visited[grid[src][i]]==1&&path[grid[src][i]]==1)
                    return true;
              }
          }
          path[src]=0;
          return false;
      }
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            vector<int>ans;
            int V=graph.size();
            vector<int>visited(V,0);
            vector<int>path(V,0);
            for (int i=0;i<graph.size();i++)
            {
                if (!dfs(i,visited,path,graph))
                {
                    ans.push_back(i);
                }
            }
            return ans;
        }
    };