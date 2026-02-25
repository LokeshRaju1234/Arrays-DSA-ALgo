class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
                vector<vector<int>>adj(V);
                vector<int>indegree(V,0);

                for(int i = 0;i < edges.size();i++)
                {
                    int u = edges[i][0];
                    int v = edges[i][1];
                    adj[v].push_back(u);
                    indegree[u]++;
                }

                queue<int>q;
                vector<int>ans;

                for(int i = 0;i < indegree.size();i++)
                {
                    if(indegree[i] == 0)
                    {
                        q.push(i);
                    }
                }

                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    ans.push_back(node);

                    for(auto neigh : adj[node])
                    {
                        indegree[neigh]--;
                        if(indegree[neigh] == 0)
                        {
                            q.push(neigh);
                        }
                    }
                }

                if(ans.size() != V)
                {
                    return {};
                }
                else
                {
                return ans;
                }
    }
};