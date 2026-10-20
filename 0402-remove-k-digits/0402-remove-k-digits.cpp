class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k == n)
            return "0";
        string s = "";

        for (int i = 0; i < n; i++) {
            while ((s.length() > 0) && (k > 0) && (s.back() > num[i])) {
                s.pop_back();
                k--;
            }
            if(s.length()>0 || num[i]!='0')
            s.push_back(num[i]);
        }

        while (k > 0 && !s.empty()) {
            s.pop_back();
            k--;
        }

      if(s.length()==0){
        return "0";
      }

        return s;
    }
};