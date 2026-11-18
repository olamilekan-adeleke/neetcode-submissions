class Solution {
public:

    string encode(vector<string>& strs) {
        string output;
        for (const auto s : strs) {
            output += to_string(s.size()) + "#" + s;
        }
        return output;
    }

    vector<string> decode(string s) {
        std::vector<string> result = {};

        int i = 0;
        while (i < s.size()) {
            int j = i;

            // find #
            while (s[j] != '#') j++;

            // get len
            const int len = stoi(s.substr(i, i + j));
            const auto val = s.substr(j + 1, len);
            result.push_back(val);
            
            i = j + 1 + len;
        }

        return result;
    };
};
