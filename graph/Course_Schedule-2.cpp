#include<bits/stdc++.h>
using  namespace std;
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
    vector<vector<int>>filter(vector<vector<int>>& prerequisites,int x)
        {
            vector<vector<int>>grid(x);
            for (auto it:prerequisites)
            {
                grid[it[1]].push_back(it[0]);
            }
            return grid;
        }
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>>grid=filter(prerequisites,numCourses);
            vector<int> indegree(numCourses, 0);
    
            for(int u = 0; u < numCourses; u++)
    {
        for(int v : grid[u])
        {
            indegree[v]++;
        }
    }
            return AyushAlgo(grid,indegree);
        }
    };