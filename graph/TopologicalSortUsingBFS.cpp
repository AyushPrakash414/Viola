#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      
      vector<int>AyushAlgo(vector<vector<int>>&grid,vector<int>&indegree)
      {
          vector<int>ans;
          queue<int>qu;
          for (int i=0;i<indegree.size();i++)
          {
              if(indegree[i]==0)
              {
                  qu.push(i);
              }
          }
          while(!qu.empty())
          {
              int temp=qu.front();
              ans.push_back(temp);
              qu.pop();
              for (int i=0;i<grid[temp].size();i++)
              {
                  indegree[grid[temp][i]]--;
                  if (indegree[grid[temp][i]]==0)
                      qu.push(grid[temp][i]);
              }
          }
          return ans;
      }
      
      vector<int> topoSort(int V, vector<vector<int>>& edges) {
          vector<vector<int>>grid(V);
          for(auto i:edges)
          {
              grid[i[0]].push_back(i[1]);
          }
          vector<int> indegree(V, 0);
  
          for(auto &i : edges)
          {
              indegree[i[1]]++;
          }
          return AyushAlgo(grid,indegree);
          
      }
  };