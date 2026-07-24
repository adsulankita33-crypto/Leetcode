class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        // ड्युप्लिकेट व्हॅल्यूज काढून टाका जेणेकरून 'n' चा आकार मर्यादित होईल
        std::sort(nums.begin(), nums.end());
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        int n = nums.size();

        // कमाल व्हॅल्यू 1500 असल्यामुळे, कोणताही XOR रिझल्ट 2048 (1 << 11) पेक्षा मोठा असणार नाही
        const int MAX_VAL = 2048;
        
        // फायनल युनिक ट्रिपलेट्स (Triplets) ट्रॅक करण्यासाठी
        std::vector<bool> found_triplet(MAX_VAL, false);
        
        // दोन संख्यांच्या (Pairs) XOR चे रिझल्ट स्टोअर करण्यासाठी
        std::vector<bool> pairs_exist(MAX_VAL, false);

        // पायरी 1: सर्व वैध i <= j जोड्यांचे (Pairs) XOR व्हॅल्यूज प्री-कम्प्युट करा - O(n^2)
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                pairs_exist[nums[i] ^ nums[j]] = true;
            }
        }

        // पायरी 2: जोड्यांच्या XOR ला उरलेल्या 'k' घटकासोबत कम्बाईन करा - O(V * n)
        // यामुळे ओव्हरऑल टाईम कॉम्प्लेक्सिटी O(n^3) वरून खूप कमी होते
        for (int pair_xor = 0; pair_xor < MAX_VAL; ++pair_xor) {
            if (!pairs_exist[pair_xor]) continue;
            
            for (int k = 0; k < n; ++k) {
                found_triplet[pair_xor ^ nums[k]] = true;
            }
        }

        // पायरी 3: एकूण युनिक XOR ट्रिपलेट्सची संख्या मोजा
        int unique_count = 0;
        for (int i = 0; i < MAX_VAL; ++i) {
            if (found_triplet[i]) {
                unique_count++;
            }
        }

        return unique_count;
    }
};