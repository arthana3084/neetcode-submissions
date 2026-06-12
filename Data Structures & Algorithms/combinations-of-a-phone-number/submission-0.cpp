class Solution {
public:
    vector<string> ans;
    string curr;
    void lettergenerator(string digits,vector<string> phone,int index,string curr)
    {
        if(index==digits.size())
        {
            ans.push_back(curr);
            return;
        }
        string letters=phone[digits[index]-'0'];
        for(int i=0;i<letters.size();i++)
        {
            lettergenerator(digits,phone,index+1,curr+letters[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        {
            return {};
        }
        vector<string> phone={"","","abc","def","ghi","jkl","mno","pqrs" ,"tuv","wxyz"};
        lettergenerator(digits,phone,0,curr);
        return ans;
    }
};
