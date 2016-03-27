/*258. Add Digits*/
/*easy*/
class Solution {
public:
    int addDigits(int num) {
        int result=(num-1)%9+1;
        return result;
    }
};




/* 292 Nim Game       Easy */
class Solution {
public:
    bool canWinNim(int n) {
        if(n<=3)
            return true;
        if(n%4==0)
            return false;
        else
            return true;
    }
};
