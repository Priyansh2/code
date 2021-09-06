class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream s(preorder);
        int diff = 1;
        string temp;
        while(getline(s,temp,',')){
            diff--;
            if(diff <0) return false;
            if(temp!="#") diff+=2;
        }
        return diff ==0;
        
    }
};