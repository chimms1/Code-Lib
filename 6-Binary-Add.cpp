class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;

        string answer = "";

        int i = a.size() - 1;
        int j = b.size() - 1;

        while(i>=0 || j>=0 || carry == 1)
        {
            int sum = carry;

            if(i>=0)
            {
                sum += a[i] - '0';
                i--;
            }

            

            if(j>=0)
            {
                sum += b[j] - '0';
                j--;
            }

            

            if (sum>1)
            {
                carry = 1;
            }
            else{
                carry = 0;
            }

            answer = to_string(sum % 2) + answer;
        }

        return answer;
    }
};
