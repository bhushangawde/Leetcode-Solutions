class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans = "";
        for(auto s : strs){
            string currString = "";
            for(int i = 0 ; i < s.size(); i++){
                if(s[i] == '/'){
                    currString += '/';
                }
                currString += s[i];
            }
            currString += "/:";
            ans += currString;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        string currString = "";

        for(int i  = 0 ; i < s.size(); i++){
            if(s[i] == '/' && i + 1 < s.size() && s[i + 1] == '/'){
                currString += '/';
                i++;
            }
            else if(s[i] == '/' && i + 1 < s.size() && s[i + 1] == ':'){
                ans.push_back(currString);
                currString.clear();
                i++;
            }
            else if(s[i] != '/'){
                currString += s[i];
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs)); 