class Solution {
public:

    string encode(vector<string>& strs) {
        std::string out;
        for (const string& s : strs){
            out += to_string(s.size()) + "#" + s;
        }
        return out;
    }

    vector<string> decode(string s) {
        std::vector<std::string> res;
        
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;

            const int len = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, len));

            i = j + 1 + len;
        }
        return res;
    }
};
