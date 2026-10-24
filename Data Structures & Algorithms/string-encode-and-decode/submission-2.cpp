class Solution {
   public:
    // "5#Hello5#World"
    string encode(vector<string>& strs) {
        std::string out;
        for (auto word : strs) out += std::to_string(word.size()) + '#' + word;
        return out;
    }

    // "5#Hello5#World" -> ["Hello","World"]
    vector<string> decode(string s) {
        std::vector<string> out;

        for (int i = 0; i < s.size();) {
            int j = s.find('#', i);
            int count = std::stoi(s.substr(i, j - i));

            out.push_back(s.substr(j + 1, count));
            i = j + 1 + count;
        }
        return out;
    }
};
