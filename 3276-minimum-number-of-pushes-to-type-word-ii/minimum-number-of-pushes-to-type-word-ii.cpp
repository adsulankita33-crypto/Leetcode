class Solution {
public:
    int minimumPushes(string word) {
        // Count frequency of each letter in the word
        vector<int> frequency(26, 0);
        for (char& ch : word) {
            frequency[ch - 'a']++;
        }
      
        // Sort frequencies in descending order to assign most frequent letters first
        sort(frequency.rbegin(), frequency.rend());
      
        // Calculate minimum pushes needed
        // Letters are assigned to 8 keys (like phone keypad 2-9)
        // First 8 letters need 1 push, next 8 need 2 pushes, etc.
        int totalPushes = 0;
        for (int i = 0; i < 26; i++) {
            // (i / 8 + 1) gives the number of pushes needed for this letter position
            // i / 8 = 0 for first 8 letters (1 push)
            // i / 8 = 1 for next 8 letters (2 pushes)
            // i / 8 = 2 for next 8 letters (3 pushes)
            // i / 8 = 3 for last 2 letters (4 pushes)
            int pushesPerLetter = (i / 8) + 1;
            totalPushes += pushesPerLetter * frequency[i];
        }
      
        return totalPushes;
    }
};