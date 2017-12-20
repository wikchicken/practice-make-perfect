class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;

        dfs(0,0,n,path,result);
        return result;
    }

    void dfs(int left, int right, int n, string path, vector<string> &res)
    {
        if (right == n)
        {
            res.push_back(path);
            return;
        }

        if (left < n)
            dfs(left+1, right, n, path+"(", res);
        if(right < left)
            dfs(left, right+1, n, path+")", res);
    }
};
