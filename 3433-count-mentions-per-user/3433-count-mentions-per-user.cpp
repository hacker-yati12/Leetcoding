class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(),
        [](const vector<string> &a1, const vector<string> &b1) {
            int a = stoi(a1[1]);
            int b = stoi(b1[1]);
            if (a != b)
                return a < b;

            bool aOffline = (a1[0] == "OFFLINE");
            bool bOffline = (b1[0] == "OFFLINE");

            return aOffline > bOffline;   
        });

        vector<int> ans(numberOfUsers, 0);
        unordered_map<int, int> offline;
        for (auto event: events) {
            auto x1 = event[0];
            auto x2 = event[1];
            auto x3 = event[2];
            if (x1 == "MESSAGE") {
                if (x3 == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++)
                        ans[i]++;
                } else if (x3 == "HERE") {
                    int time = stoi(x2);
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (offline.count(i)) {
                            if (time - offline[i] >= 60) {
                                ans[i]++;
                                offline.erase(i);
                            }
                        } else
                            ans[i]++;
                    }
                } else {
                    stringstream ss(x3);
                    string temp;
                    while (ss >> temp) {
                        int ch = stoi(temp.substr(2));
                        ans[ch]++;
                    }
                }
            } else {
                int user = stoi(x3);
                int time = stoi(x2);
                offline[user] = time;
            }
        }
        return ans;
    }
};