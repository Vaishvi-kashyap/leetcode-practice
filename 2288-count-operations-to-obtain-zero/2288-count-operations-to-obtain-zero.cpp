class Solution {
public:
    int ans =0;
    void help(int num1, int num2){
        if(num1==0 || num2==0) return;
        if(num1<num2) return help(num2,num1);
        ans++;
        help(num1-num2,num2);

    }
    int countOperations(int num1, int num2) {
        help(num1,num2);
        return ans;
    }
};