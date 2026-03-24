class Solution {
public:
    string reverseWords(string s) {
        
        int n =s.size();
        stringstream ss(s);
        string word; //individual unit 
        
        vector<string>result;
        while(ss>>word)
        {
            result.push_back(word);
        }

        reverse(result.begin(),result.end());

        string final = "";
        
       for(int i =0;i<result.size();i++)
       {
        if(i!=result.size()-1)
        {
            final+=result[i];
            final+=" ";
        }
        else
        {
            final+=result[i];
        }
       }

       return final;
    }
};