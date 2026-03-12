#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      vector<vector<int>>filter(vector<vector<int>>&grid,int v)
      {
          vector<vector<int>>ans(v);
          for (auto i:grid)
          {
              ans[i[0]].push_back(i[1]);
          }
          return ans;
      }
      
      void dfs(int src,vector<int>&visited,stack<int>&st,vector<vector<int>>&grid)
      {
          visited[src]=1;
          for (int i=0;i<grid[src].size();i++)
          {
              if (!visited[grid[src][i]])
              {
                  dfs(grid[src][i],visited,st,grid);
              }
          }
          st.push(src);
      }
      
      vector<int> topoSort(int V, vector<vector<int>>& edges) {
         vector<vector<int>>grid=filter(edges,V);
         vector<int>visited(V,0);
         stack<int>st;
         for (int i=0;i<V;i++)
         {
             if (!visited[i])
             {
                 dfs(i,visited,st,grid);
             }
         }
         vector<int>ans;
         while (!st.empty())
         {
             ans.push_back(st.top());
             st.pop();
         }
         return ans;
      }
  };