class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, set<int>> mp;

        // Store reserved seats row-wise
        for(auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            // Seats 1 and 10 don't affect any group
            if(s >= 2 && s <= 9)
                mp[row].insert(s);
        }

        long long ans = 0;

        // Rows having reservations
        for(auto &[row, seats] : mp) {

            bool left = true;    // 2,3,4,5
            bool middle = true;  // 4,5,6,7
            bool right = true;   // 6,7,8,9

            // Check left block
            for(int s = 2; s <= 5; s++) {
                if(seats.count(s)) {
                    left = false;
                    break;
                }
            }

            // Check middle block
            for(int s = 4; s <= 7; s++) {
                if(seats.count(s)) {
                    middle = false;
                    break;
                }
            }

            // Check right block
            for(int s = 6; s <= 9; s++) {
                if(seats.count(s)) {
                    right = false;
                    break;
                }
            }

            // Two groups possible
            if(left && right) {
                ans += 2;
            }
            // At least one block possible
            else if(left || middle || right) {
                ans += 1;
            }
        }

        // Rows with NO reservations
        // Each such row can accommodate 2 groups
        long long reservedRows = mp.size();

        ans += (long long)(n - reservedRows) * 2;

        return ans;
    }
};