//Q.1

#include <iostream>
#include <vector>
#include <algorithm>  // For max function

using namespace std;

int maxSubArray(vector<int>& nums) {
    // Initialize the two variables for the Kadane's algorithm
    int max_so_far = nums[0]; // This will hold the largest sum found so far
    int max_ending_here = nums[0]; // This will hold the sum of the current subarray
    
    // Loop through the array starting from the second element
    for (int i = 1; i < nums.size(); i++) {
        // Update max_ending_here to the larger of current element or current subarray sum + current element
        max_ending_here = max(nums[i], max_ending_here + nums[i]);
        
        // Update max_so_far to the maximum of max_so_far and max_ending_here
        max_so_far = max(max_so_far, max_ending_here);
    }
    
    return max_so_far;  // This will be the result
}

int main() {
    // Example input array
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    // Call the function to find the maximum subarray sum
    int result = maxSubArray(nums);
    
    // Print the result
    cout << "The largest sum of a subarray is: " << result << endl;  // Expected output: 6
    
    return 0;
}


//Q.2

#include <iostream>
#include <vector>
using namespace std;

int countInversions(const vector<int>& arr) {
    int n = arr.size();
    int inversionCount = 0;

    // Loop through the array with two nested loops
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // If arr[i] > arr[j], it means an inversion
            if (arr[i] > arr[j]) {
                inversionCount++;  // Count this inversion
            }
        }
    }

    return inversionCount;  // Return the total count of inversions
}

int main() {
    // Sample input array
    vector<int> arr = {7, 2, 6, 3};
    
    // Get the inversion count
    int result = countInversions(arr);
    
    // Output the result
    cout << "Number of inversions: " << result << endl;  // Expected output: 4

    return 0;
}


//Q.3

#include <iostream>
#include <vector>
#include <queue> // For using the priority_queue (min-heap)

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    // Min-heap (priority_queue by default is max-heap, so use the reverse comparison for min-heap)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Process each element in the array
    for (int num : nums) {
        // If the heap has fewer than k elements, add the current number
        if (minHeap.size() < k) {
            minHeap.push(num);
        } else {
            // If heap has k elements, compare with the smallest element (heap root)
            if (num > minHeap.top()) {
                minHeap.pop();  // Remove the smallest element
                minHeap.push(num); // Add the current number
            }
        }
    }

    // The root of the heap now contains the kth largest element
    return minHeap.top();
}

int main() {
    // Sample input
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    // Find the kth largest element
    int result = findKthLargest(nums, k);

    // Output the result
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}


//Q.4

#include <iostream>
#include <cctype> // For isalnum() and tolower()
using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        // Move the left pointer to the next alphanumeric character
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        // Move the right pointer to the previous alphanumeric character
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Compare the characters, ignoring case
        if (tolower(s[left]) != tolower(s[right])) {
            return false; // If characters don't match, it's not a palindrome
        }

        // Move both pointers towards the center
        left++;
        right--;
    }

    return true; // If all checks passed, it's a palindrome
}

int main() {
    // Example 1
    string s1 = "A man, a plan, a canal: Panama";
    cout << "Is \"" << s1 << "\" a palindrome? " << (isPalindrome(s1) ? "True" : "False") << endl;

    // Example 2
    string s2 = "race a car";
    cout << "Is \"" << s2 << "\" a palindrome? " << (isPalindrome(s2) ? "True" : "False") << endl;

    return 0;
}


//Q.5

#include <iostream>
#include <vector>
using namespace std;

int findEquilibriumIndex(const vector<int>& arr) {
    int n = arr.size();
    
    // If the array is empty, return -1
    if (n == 0) return -1;

    // Step 1: Calculate the total sum of the array
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
    }

    // Step 2: Initialize left_sum to 0
    int left_sum = 0;

    // Step 3: Traverse the array
    for (int i = 0; i < n; i++) {
        // Subtract current element from total sum to get right_sum
        int right_sum = total_sum - left_sum - arr[i];

        // If left_sum is equal to right_sum, we have found the equilibrium index
        if (left_sum == right_sum) {
            return i + 1; // Return the 1-based index
        }

        // Update left_sum for the next iteration
        left_sum += arr[i];
    }

    // If no equilibrium index is found, return -1
    return -1;
}

int main() {
    // Test cases
    vector<int> arr1 = {-7, 1, 5, 2, -4, 3, 0};
    vector<int> arr2 = {1, 2, 3};
    vector<int> arr3 = {1, 3, 5, 2, 2};

    // Find equilibrium index for each test case
    cout << "Equilibrium Index of arr1: " << findEquilibriumIndex(arr1) << endl;
    cout << "Equilibrium Index of arr2: " << findEquilibriumIndex(arr2) << endl;
    cout << "Equilibrium Index of arr3: " << findEquilibriumIndex(arr3) << endl;

    return 0;
}



//Q.6

#include <iostream>
#include <vector>
using namespace std;

int findEquilibriumIndex(const vector<int>& arr) {
    int n = arr.size();
    
    // If the array is empty, return -1
    if (n == 0) return -1;

    // Step 1: Calculate the total sum of the array
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
    }

    // Step 2: Initialize left_sum to 0
    int left_sum = 0;

    // Step 3: Traverse the array
    for (int i = 0; i < n; i++) {
        // Subtract current element from total sum to get right_sum
        int right_sum = total_sum - left_sum - arr[i];

        // If left_sum is equal to right_sum, we have found the equilibrium index
        if (left_sum == right_sum) {
            return i + 1; // Return the 1-based index
        }

        // Update left_sum for the next iteration
        left_sum += arr[i];
    }

    // If no equilibrium index is found, return -1
    return -1;
}

int main() {
    // Test cases
    vector<int> arr1 = {-7, 1, 5, 2, -4, 3, 0};
    vector<int> arr2 = {1, 2, 3};
    vector<int> arr3 = {1, 3, 5, 2, 2};

    // Find equilibrium index for each test case
    cout << "Equilibrium Index of arr1: " << findEquilibriumIndex(arr1) << endl;
    cout << "Equilibrium Index of arr2: " << findEquilibriumIndex(arr2) << endl;
    cout << "Equilibrium Index of arr3: " << findEquilibriumIndex(arr3) << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

bool findPairTwoPointer(const vector<int>& A, int N, int X) {
    int left = 0, right = N - 1;
    
    while (left < right) {
        int sum = A[left] + A[right];
        
        if (sum == X) {
            return true;  // Pair found
        } else if (sum < X) {
            left++;  // Move left pointer to the right
        } else {
            right--;  // Move right pointer to the left
        }
    }
    
    return false;  // No pair found
}

int main() {
    vector<int> A = {1, 2, 4, 5, 7, 11};
    int N = 6;
    int X = 9;

    if (findPairTwoPointer(A, N, X)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}


//Q.8

#include <iostream>
#include <vector>
using namespace std;

int maxSumSlidingWindow(const vector<int>& arr, int n, int k) {
    // If k is greater than the size of the array, return "Invalid"
    if (k > n) {
        cout << "Invalid" << endl;
        return -1;
    }
    
    // Step 1: Calculate the sum of the first window (first k elements)
    int current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += arr[i];
    }
    
    int max_sum = current_sum;  // Initialize the maximum sum as the first window sum
    
    // Step 2: Slide the window, update the sum and track the maximum sum
    for (int i = k; i < n; i++) {
        current_sum = current_sum - arr[i - k] + arr[i];
        max_sum = max(max_sum, current_sum);  // Update the maximum sum if needed
    }
    
    return max_sum;  // Return the maximum sum found
}

int main() {
    vector<int> arr1 = {100, 200, 300, 400};
    int k1 = 2;
    int n1 = arr1.size();
    
    vector<int> arr2 = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k2 = 4;
    int n2 = arr2.size();
    
    vector<int> arr3 = {2, 3};
    int k3 = 3;
    int n3 = arr3.size();
    
    // Test case 1
    cout << "Max sum of " << k1 << " consecutive elements: " << maxSumSlidingWindow(arr1, n1, k1) << endl;
    
    // Test case 2
    cout << "Max sum of " << k2 << " consecutive elements: " << maxSumSlidingWindow(arr2, n2, k2) << endl;
    
    // Test case 3 (Invalid case)
    cout << "Max sum of " << k3 << " consecutive elements: " << maxSumSlidingWindow(arr3, n3, k3) << endl;

    return 0;
}


//Q.9

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(const vector<int>& prices) {
    int n = prices.size();
    
    if (n <= 1) {
        return 0; // If there's 1 or fewer days, we can't make any profit
    }
    
    int min_price = prices[0];  // Start with the first price as the minimum
    int max_profit = 0;  // Initialize max profit to 0
    
    // Loop through the prices from the second day onwards
    for (int i = 1; i < n; i++) {
        // If current price is less than min_price, update min_price
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
        
        // Calculate the profit if we sell on day i
        int profit = prices[i] - min_price;
        
        // Update max_profit if the current profit is greater
        if (profit > max_profit) {
            max_profit = profit;
        }
    }
    
    return max_profit;  // Return the maximum profit
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};  // Example input
    
    int result = maxProfit(prices);
    cout << "Maximum profit: " << result << endl;  // Expected Output: 5
    
    return 0;
}


//Q.10

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> maxSubArraySum(const vector<int>& nums, int target) {
    unordered_map<int, int> sumMap;  // Stores cumulative sum and its first occurrence index
    int currentSum = 0;
    int maxLength = 0;
    int startIndex = -1;
    
    // Add a dummy entry for sum = 0 at index -1 (to handle cases where subarray starts from the beginning)
    sumMap[0] = -1;

    // Iterate through the array
    for (int i = 0; i < nums.size(); i++) {
        currentSum += nums[i];  // Update the cumulative sum

        // Check if the (currentSum - target) exists in the sumMap
        if (sumMap.find(currentSum - target) != sumMap.end()) {
            int length = i - sumMap[currentSum - target];  // Length of subarray
            if (length > maxLength) {
                maxLength = length;  // Update maximum length
                startIndex = sumMap[currentSum - target] + 1;  // Update the start index
            }
        }

        // If currentSum is not in sumMap, store it with its index
        if (sumMap.find(currentSum) == sumMap.end()) {
            sumMap[currentSum] = i;
        }
    }

    // If we found a subarray, return it
    if (startIndex != -1) {
        vector<int> result(nums.begin() + startIndex, nums.begin() + startIndex + maxLength);
        return result;
    }

    // If no subarray is found, return an empty vector
    return {};
}

int main() {
    vector<int> nums = {5, 6, -5, 5, 3, 5, 3, -2, 0};
    int target = 8;

    vector<int> result = maxSubArraySum(nums, target);

    if (!result.empty()) {
        cout << "Longest subarray with sum " << target << ": { ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << "}" << endl;
    } else {
        cout << "No subarray with the given sum found." << endl;
    }

    return 0;
}




