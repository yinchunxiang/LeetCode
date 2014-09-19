void dfs(vector<int>& v, int start, vector<int> path, vector<vector<int> >& result) {
    if (start >= v.size()) {
        result.push_back(path);
        return;
    }

    dfs(v, start + 1, path, result);
    path.push_back(v[start]);
    dfs(v, start + 1, path, result);

}
vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > result;
    if (S.empty()) return result;
    sort(S.begin(), S.end());
    dfs(S, 0, vector<int>(), result);
    return result;
}

vector<vector<int> > subsets2(vector<int> &S) {
    vector<vector<int> > result(1);
    sort(S.begin(), S.end());
    for(int i = 0; i < S.size(); ++i) {
        int n = result.size();
        for (int j = 0; j < n; ++j) {
            result.push_back(result[j]);
            result.back().push_back(S[i]);
        }
    }
    return result;
}
