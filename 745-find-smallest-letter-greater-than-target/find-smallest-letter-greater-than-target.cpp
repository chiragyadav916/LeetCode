class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char y) {
        set<char> s;
        for(auto x : letters) {
            s.insert(x);
        }
        auto it = s.upper_bound(y);
        if(it != s.end()) {
            return *it;
        }

        else {
            return *s.begin();
        }        
    }
};