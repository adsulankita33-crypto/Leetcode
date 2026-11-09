
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {completion time, server ID}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Release servers whose requests are completed
            while (!busy.empty() && busy.top().first <= arrival[i]) {

                int server = busy.top().second;

                busy.pop();

                available.insert(server);
            }

            // If all servers are busy, drop request
            if (available.empty()) {
                continue;
            }

            // Find preferred server
            int preferred = i % k;

            auto it = available.lower_bound(preferred);

            // Circular search
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request
            available.erase(it);

            count[server]++;

            // Mark server busy
            long long finish = (long long)arrival[i] + load[i];

            busy.push({finish, server});
        }

        // Find maximum requests handled
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
