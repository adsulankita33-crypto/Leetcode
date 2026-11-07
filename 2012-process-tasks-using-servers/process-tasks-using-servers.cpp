class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // Min-heap for free servers: {weight, index}
        using FreeServer = pair<int, int>;
        priority_queue<FreeServer, vector<FreeServer>, greater<FreeServer>> freeServers;

        for (int i = 0; i < n; ++i) {
            freeServers.push({servers[i], i});
        }

        // Min-heap for busy servers: {free_time, {weight, index}}
        using BusyServer = pair<long long, FreeServer>;
        priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busyServers;

        vector<int> ans(m);
        long long currentTime = 0;

        for (int j = 0; j < m; ++j) {
            // Advance current time to at least the arrival of task j
            currentTime = max(currentTime, (long long)j);

            // If no servers are available, fast-forward time to the earliest finishing server
            if (freeServers.empty()) {
                currentTime = busyServers.top().first;
            }

            // Release all servers that have completed their tasks by currentTime
            while (!busyServers.empty() && busyServers.top().first <= currentTime) {
                auto [finishTime, serverInfo] = busyServers.top();
                busyServers.pop();
                freeServers.push(serverInfo);
            }

            // Assign task j to the free server with the smallest weight (and smallest index on ties)
            auto [weight, idx] = freeServers.top();
            freeServers.pop();

            ans[j] = idx;
            busyServers.push({currentTime + tasks[j], {weight, idx}});
        }

        return ans;
    }
};