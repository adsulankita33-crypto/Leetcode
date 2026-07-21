class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int index=0;
        int i=0;
        string ans="";
        while(i<n){
            int count=0;
            int current=chars[i];
            while(i<n && chars[i]==current){
                count++;
                i++;
            }
            ans+=current;
            if(count==1){
                chars[index++]=current;
            }
            else{
                chars[index++]=current;
                string copy=to_string(count);
                ans+=copy;
                for(char dig:copy){
                    chars[index++]=dig;
                }
            }
        }
        return index;
    }
};