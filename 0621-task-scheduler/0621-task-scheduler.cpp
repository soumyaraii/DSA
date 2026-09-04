class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char task : tasks) {
            freq[task - 'A']++;
        }

        // Max heap: {frequency, task}
        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                pq.push({freq[i], 'A' + i});
            }
        }

        int time = 0;

        while(!pq.empty()) {

            // Tasks used in this cycle
            vector<pair<int, char>> temp;

            // One cycle has n + 1 positions
            for(int i = 0; i <= n; i++) {

                if(!pq.empty()) {

                    auto curr = pq.top();
                    pq.pop();

                    int frequency = curr.first;
                    char task = curr.second;

                    // Execute task
                    frequency--;

                    // Still has occurrences left
                    if(frequency > 0) {
                        temp.push_back({frequency, task});
                    }
                }

                time++;

                // No tasks left at all
                if(pq.empty() && temp.empty()) {
                    break;
                }
            }

            // Put remaining tasks back into heap
            for(auto x : temp) {
                pq.push(x);
            }
        }

        return time;

    }
};