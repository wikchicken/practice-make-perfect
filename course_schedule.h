
//using topologic sort
//bfs with in_degree 0 begin
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));//这里用vector下标表示图中节点，没有使用map<int, vector<int>>来存图
        vector<int> in_degree(numCourses);
        queue<int> qin;
        vector<int> res;

        for(int i=0; i<prerequisites.size(); ++i)
        {
            pair<int ,int> tmp = prerequisites[i];
            graph[tmp.second].push_back(tmp.first);
            in_degree[tmp.first]++;
        }

        for(int j=0; j<in_degree.size(); ++j)
        {
            if(in_degree[j]==0)
            {
                qin.push(j);
            }
        }

        while(!qin.empty())
        {
            int node = qin.front();
            qin.pop();
            res.push_back(node);

            vector<int> neigh(graph[node]);
            for(int k=0; k< neigh.size(); ++k)
            {               
                in_degree[neigh[k]]--;
                if(in_degree[neigh[k]] == 0)
                {
                    qin.push(neigh[k]);
                }
            }
        }

        if(res.size() != numCourses)
            return false;
        else
            return true;
    }
};

//dfs with out_degree 0 begin
//running time error
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));//这里用vector下标表示图中节点，没有使用map<int, vector<int>>来存图
        vector<int> res;
        vector<int> visit(numCourses, 0);

        for(auto tmp: prerequisites)
        {
            graph[tmp.second].push_back(tmp.first);
        }  

        for(int i=0; i<numCourses; ++i)
        {
            if (!dfs(graph, i, visit, res)) return {};
        }

        if(res.size() == numCourses)
            reverse(res.begin(), res.end());
        else
            res.clear();
        
        return res;
    }

    bool dfs(vector<vector<int>> &G, int node, vector<int> &visit, vector<int> &res)
    {
        if(visit[node]==1) return true;
        if(visit[node]==-1) return false;

        visit[node]==-1;
        for(auto neigh: G[node])
        {
            if(visit[neigh]==-1 || (!dfs(G, neigh, visit, res))) return false;
        }
        
        res.push_back(node);
        visit[node] = 1;
        return true;
    }    
};

//AC dfs refrence
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> toposort;
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs(graph, i, onpath, visited, toposort))
                return {};
        reverse(toposort.begin(), toposort.end());
        return toposort;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    bool dfs(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort) { 
        if (visited[node]) return false;
        onpath[node] = visited[node] = true; 
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs(graph, neigh, onpath, visited, toposort))
                return true;
        toposort.push_back(node);
        return onpath[node] = false;// return false
    }
};
   
