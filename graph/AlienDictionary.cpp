
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    pair<char,char>filter(string f,string s)
    {
        int size=min(f.size(),s.size());
        for (int i=0;i<size;i++)
        {
            if (s[i]!=f[i])
             return make_pair(f[i],s[i]);
        }
    }
    void dfs(char src,map<char,vector<char>>&grid,vector<int>&visited,stack<char>&st)
    {
        visited[src-'a']=1;
        for (int i=0;i<grid[src].size();i++)
        {
            if (visited[grid[src][i]-'a']==0)
              dfs(grid[src][i],grid,visited,st);
        }
        st.push(src);
    }
    string toposort(map<char,vector<char>>grid)
    {
        vector<int>visited(26,0);
        stack<char>st;
        for (auto i:grid)
        {
            if (visited[i.first - 'a'] == 0)
            dfs(i.first,grid,visited,st);
        }
        string ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
      string findOrder(vector<string> &words) {
          map<char,vector<char>>grid;
          set<char> nodes;
          for (auto word : words)
              for (auto ch : word)
                  nodes.insert(ch);
          for (int i=1;i<words.size();i++)
          {
              string f=words[i-1];
              string s=words[i];
              pair<char,char>temp=filter(f,s);
              grid[temp.first].push_back(temp.second);
          }
          return toposort(grid);
      }
  };