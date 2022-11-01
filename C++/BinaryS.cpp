#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(int nums[], int target, int length) {
	int low = 0;
	int high = length - 1;

	while (low <= high) {

		// Finding the mid using floor division
		int mid = low + ((high - low) / 2);

		// Target value is present at the middle of the array
		if (nums[mid] == target) {
			return mid;
		}

		// Target value is present in the low subarray
		else if (target < nums[mid]) {
			high = mid - 1;
		}

		// Target value is present in the high subarray
		else if (target > nums[mid]) {
			low = mid + 1;
		}
	}

	// Target value is not present in the array
	return -1;
}

int main() {
	vector<vector<int> > nums = {
	    {},{0, 1}, {1, 2, 3}, {-1, 0, 3, 5, 9, 12}, {-1, 0, 3, 5, 9, 12}};

	vector<int> sizes = {0, 2, 3, 6, 6};
	vector<int> targets = {12, 1, 3, 9, 2};
	for (int i = 0; i < nums.size(); i++) {
		cout << i + 1 << ". Array to search: ";
		// A custom function to neatly print the list
		PrintList(nums[i]);
		cout << "   Target: " << targets[i] << endl;
		int index = BinarySearch(nums[i].data(), targets[i], sizes[i]);
		if (index != -1) {
			cout << "   " << targets[i] << " exists in the array at index " << index << endl;
		} else {
			cout << "   " << targets[i] << " does not exist in the array so the return value is " << index << endl;
		}
		cout << "------------------------------------------------------------------------------------------------------\n" << endl;
	}
}
