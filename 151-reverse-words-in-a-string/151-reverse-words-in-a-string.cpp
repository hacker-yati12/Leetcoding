class Solution {
  public:
    string reverseWords(string s) {
      int n = s.size();
      string temp = "", result = "";
      vector < string > words;     
      for (int i = 0; i < n; i++) 
      {        
        if (isalpha(s[i]) || isdigit(s[i]))
          temp.push_back(s[i]);       
        else if (temp.size() > 0) 
        {
          words.push_back(temp);
          temp = "";
        }
      }     
      if (temp.size() > 0)
        words.push_back(temp);     
      reverse(words.begin(), words.end());     
      for (int i = 0; i < words.size(); i++) 
      {
        if (i == words.size() - 1)
          result += words[i];
        else
          result += words[i] + " ";
      }
      return result;
    }
};