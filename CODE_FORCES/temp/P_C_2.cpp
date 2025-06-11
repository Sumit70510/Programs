
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        long long product = 1; // Initialize the product
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {

            std::cin >> a[i];
            product*=a[i];
        }

        std::string s;
        std::cin >> s;


        for (int i = 0; i < n; ++i) {
            // Output remainder when dividing the product by m
            std::cout << (product % m)%m << " ";

            // Update the product based on the command
            if (s[i] == 'L') {
                product = (product / a[0]);
                a.erase(a.begin()); // Remove the leftmost element
            } else {
                product = (product / a.back());
                a.pop_back(); // Remove the rightmost element
            }
        }

        std::cout << "\n";
    }

    return 0;
}
