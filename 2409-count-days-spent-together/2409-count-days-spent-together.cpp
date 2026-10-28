class Solution {
public:
    int find(string date,vector<int>& total_days){
        int month = stoi(date.substr(0,2)); // start idx , length
        int days = stoi(date.substr(3)); // no length means till end of string
        return total_days[month-1] + days;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> total_days(13,0);
        total_days[1] = 31;
        for(int i=2;i<=12;i++){
            total_days[i] = total_days[i-1] + months[i-1];
        }
        int arriveAliceDay = find(arriveAlice,total_days);
        int leaveAliceDay = find(leaveAlice,total_days);
        int arriveBobDay = find(arriveBob,total_days);
        int leaveBobDay = find(leaveBob,total_days);

        int ans = (min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay))+1;
        return ans<0?0:ans;

    }
};