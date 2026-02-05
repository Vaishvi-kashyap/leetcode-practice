class Solution {
public:
    unordered_map<string, vector<string>> parent;
    unordered_map<string, int> dist;
    vector<vector<string>> ans;

    void dfs(string word, string& beginWord, vector<string>& path) {
        if (word == beginWord) {
            auto temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto& p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;

        int L = beginWord.size();

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            int steps = dist[curr];
            string word = curr;

            for (int i = 0; i < L; i++) {
                char orig = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if (dict.count(word)) {
                        if (!dist.count(word)) {
                            dist[word] = steps + 1;
                            parent[word].push_back(curr);
                            q.push(word);
                        } else if (dist[word] == steps + 1) {
                            parent[word].push_back(curr);
                        }
                    }
                }
                word[i] = orig;
            }
        }

        if (!dist.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, path);

        return ans;
    }
};
