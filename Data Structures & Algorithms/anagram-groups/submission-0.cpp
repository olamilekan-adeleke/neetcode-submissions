class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> groups;
        for (auto s : strs){
            string word = s;
            std::sort(word.begin(), word.end());
            groups[word].push_back(s);
        }

        vector<vector<string>> result;
        for (auto [key, val] : groups){
            result.push_back(val);
        }
        return result;
    }
};
