class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    map<int, vector<string>> mp;
    hash<string> hasher;
    for (auto &s : strs) {
      string temp = s;
      sort(begin(temp), end(temp));
      mp[hasher(temp)].push_back(s);
    }
    vector<vector<string>> result;
    for (auto &[first, second] : mp)
      result.emplace_back(std::move(second));
    return result;
  }
};
