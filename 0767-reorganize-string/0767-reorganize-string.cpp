class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }

        priority_queue<pair<int, char>> q;

        for (auto p : mp) {
            q.push({p.second, p.first});
        }

        string res = "";
        if (q.top().first > (s.size() + 1) / 2)
            return "";
        while (q.size() > 1) {
            auto p1 = q.top();
            q.pop();
            auto p2 = q.top();
            q.pop();

            int x = p1.first;
            int y = p2.first;
            res.push_back(p1.second);
            res.push_back(p2.second);
            x--;
            y--;
            if (x != 0)
                q.push({x, p1.second});
            if (y != 0)
                q.push({y, p2.second});
        }
        auto p1 = q.top();
        int x = p1.first;

        if (res.empty() || res.back() != p1.second) {
            while (x > 0) {
                res.push_back(p1.second);
                x--;
            }
        }

        return res;
    }
};