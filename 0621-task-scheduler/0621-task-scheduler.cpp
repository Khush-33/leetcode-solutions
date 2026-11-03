class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();

        unordered_map<char, int> mpp;
        unordered_map<char, int> next_seat; // Task next kab execute ho sakta hai

        for (auto i : tasks) {
            mpp[i]++;

            // Har task initially time 0 par available hai
            next_seat[i] = 0;
        }

        // Max heap banaya hai
        // Jiski frequency sabse zyada hogi, woh top par rahega
        priority_queue<pair<int, char>> pq;

        for (auto i : mpp) {
            pq.push({i.second, i.first});
        }

        int seat = 0; // Current time ko track karega

        while (!pq.empty()) {

            // Jo tasks abhi cooldown mein hain,
            // unhe temporarily yahan store karenge
            vector<pair<int, char>> side;

            // Current time par execute hone wala task dhundho
            while (!pq.empty()) {

                auto p = pq.top();
                pq.pop();

                int freq = p.first; // Task kitni baar aur execute hona hai
                char ele = p.second; // Kaunsa task hai

                // Check karo ki task ka cooldown khatam hua hai ya nahi
                if (next_seat[ele] <= seat) {

                    // Task execute ho gaya
                    // Agar frequency 1 se zyada hai,
                    // toh task ko future mein dobara execute karna hai
                    if (freq > 1) {

                        // Frequency 1 decrease karke heap mein wapas daalo
                        pq.push({freq - 1, ele});

                        // Task dobara tabhi execute ho sakta hai
                        // jab n intervals + current execution complete ho
                        next_seat[ele] = seat + n + 1;
                    }

                    // Ek time slot mein sirf ek task execute hoga
                    // Isliye current loop se bahar aa jao
                    break;
                }
                else {

                    // Task abhi cooldown mein hai
                    // Isko abhi execute nahi kar sakte
                    // Temporarily side vector mein store karo
                    side.push_back(p);
                }
            }

            // Cooldown wale saare tasks ko heap mein wapas daalo
            // Taaki next time unhe check kar sakein
            for (auto i : side) {
                pq.push(i);
            }

            // Ek time slot complete ho gaya
            // Chahe task execute hua ho ya idle time ho
            seat++;
        }

        // Total time return karo
        return seat;
    }
};