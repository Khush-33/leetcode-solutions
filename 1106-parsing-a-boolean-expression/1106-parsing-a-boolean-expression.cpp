class Solution {
public:
    bool f(int& i, string& expression){
        if(expression[i] == 'f'){
            i++;
            return false;
        }
        else if(expression[i] == '!'){
            i+=2;
            bool res = f(i,expression);
            i++;
            return !res;
        }
        else if(expression[i] == '&'){
            bool res = true;
            i+=2;
            while(expression[i] != ')'){
                if(expression[i] == ',') i++;
                else{
                    bool temp = f(i,expression);
                    res = res&temp;
                }
            }
            i++;
            return res;
        }
        else if(expression[i] == '|'){
            bool res = false;
            i+=2;
            while(expression[i] != ')'){
                if(expression[i] == ',') i++;
                else{
                    bool temp = f(i,expression);
                    res = res|temp;
                }
            }
            i++;
            return res;
        }
        i++;
        return true;
    }
    bool parseBoolExpr(string expression) {
        int i=0;
        return f(i,expression);
    }
};