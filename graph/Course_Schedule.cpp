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
        vector<vector<int>>filter(vector<vector<int>>& prerequisites,int x)
        {
            vector<vector<int>>grid(x);
            for (auto it:prerequisites)
            {
                grid[it[1]].push_back(it[0]);
            }
            return grid;
        }
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<int>visited(numCourses,0);
            vector<int>path(numCourses,0);
            vector<vector<int>>adj(numCourses);
            for (auto i:prerequisites)
            {
                adj[i[0]].push_back(i[1]);
            }
            
            for (int i=0;i<numCourses;i++)
            {
                if(visited[i]==0&&dfs(i,visited,path,adj))
                {
                    return false;
                }
            }
            return true;
        }
    };