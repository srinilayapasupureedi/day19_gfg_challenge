int minChar(string& s) {
        // Write your code here
          string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        // Create the concatenated string
        string new_string = s + "#" + rev_s;

        // Compute LPS array
        int n = new_string.size();
        vector<int> lps(n, 0);

        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && new_string[i] != new_string[j]) {
                j = lps[j - 1];
            }
            if (new_string[i] == new_string[j]) {
                j++;
            }
            lps[i] = j;
        }

        // The last value of the LPS array gives the longest palindromic prefix
        int longest_palindromic_prefix_length = lps.back();

        // Minimum characters to add
        return s.size() - longest_palindromic_prefix_length;
    
    }
