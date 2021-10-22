class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int l1 = num1.length(), l2 = num2.length();
        if(l1 < l2) {
            swap(l1,l2);
            swap(num1,num2);
        }
        string res(l1+l2,'0');
        int shift = -1;
        for(int j = l2-1;j>=0;j--){
            shift++;
            int k = l1 +l2  - shift -1;
            int c= 0;
            int carry = 0;
            for(int i=l1-1;i>=0;i--){
                int prod = (num1[i]-'0') *(num2[j]-'0') + carry;
                int rem = prod%10;
                carry = prod/10;
                int temp = rem + (res[k] -'0') + c;
                c = temp/10;
                int r = temp%10;
                res[k--]  = r + '0';
            }
            res[k] = carry + c + '0';
        }
        string ans;
        int i=0;
        for(;i<l1+l2;i++){
            if(res[i]!='0') break;
        }
        for(;i<l1 +l2 ;i++) ans+=res[i];
        return ans;
        
    }
};