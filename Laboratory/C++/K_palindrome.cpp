#include <bits/stdc++.h>
using namespace std;

string largestPalindrome(int n, int k) {
    // Helper function to create the largest palindrome with n digits
    auto createLargestPalindrome = [](int n) -> string {
        string half = string((n + 1) / 2, '9'); // Half of the palindrome, filled with '9'
        string palindrome = half;
        
        // If n is odd, omit the last digit of half before mirroring
        if (n % 2 != 0) {
            half.pop_back();
        }
        
        // Append the reverse of the half to form the full palindrome
        reverse(half.begin(), half.end());
        palindrome += half;
        
        return palindrome;
    };
    
    // Generate the largest palindrome with n digits
    string palindrome = createLargestPalindrome(n);
    
    // Convert the palindrome to a long long for divisibility check
    while (stoll(palindrome) % k != 0) {
        int len = palindrome.length();
        int half_len = (len + 1) / 2;
        
        // Decrement the first half of the palindrome and then mirror it
        string first_half = palindrome.substr(0, half_len);
        first_half = to_string(stoll(first_half) - 1);
        
        if (first_half.length() < half_len) {
            return "-1"; // If decrementing results in a shorter number, no valid palindrome exists
        }
        
        string new_palindrome = first_half;
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());
        
        if (n % 2 != 0) {
            new_palindrome += second_half.substr(1); // Omit the middle digit when mirroring
        } else {
            new_palindrome += second_half;
        }
        
        palindrome = new_palindrome;
    }
    
    return palindrome;
}

int main() {
    int n =0;
    int k ;
    cin>>k;
    for(int i=1;i<100;i++)
    {string result = largestPalindrome(i, k);
    cout << "Largest " << n << "-digit " << k << "-palindromic number: " << result << endl;
    }
    return 0;
}