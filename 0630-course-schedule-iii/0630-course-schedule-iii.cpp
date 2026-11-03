
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        priority_queue<int> pq;

        int daysDone = 0;

        for (auto& course : courses) {
            int duration = course[0];
            int deadline = course[1];

            daysDone += duration;
            pq.push(duration);

            if (daysDone > deadline) {
                daysDone -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};
