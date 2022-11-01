// Importing required functions
import java.util.*;

class BinaryS {
	static int binarySearch(int[] arr, int k) {
		int low = 0;
		int high = arr.length - 1;

		while (low <= high) {
			// Finding the mid using floor division
			int mid = low + ((high - low) / 2);

			// k value is present at the middle of the array
			if (arr[mid] == k) {
				return mid;
			}

			// k value is present in the low subarray
			else if (k < arr[mid]) {
				high = mid - 1;
			}

			// k value is present in the high subarray
			else if (k > arr[mid]) {
				low = mid + 1;
			}
		}

		// k value is not present in the array
		return -1;
	}

	public static void main(String[] args) {
		
		int[][] arrLists = {{}, {0, 1}, {1, 2, 3}, {-1, 0, 3, 5, 9, 12}, {-1, 0, 3, 5, 9, 12}};
		
		int[] kList = {12, 1, 3, 9, 2};
		
		for (int i = 0; i < arrLists.length; i++) {
			int[] arr = arrLists[i];
			int k = kList[i];
			int index = binarySearch(arr, k);
			System.out.println(i + 1 + ". Array to search: " + Arrays.toString(arr));
			System.out.println("   k: " + kList[i]);
			if (index != -1) {
				System.out.println("   " + k + " exists in the array and its index is " + index);
			} else {
				System.out.println("   " + k + " does not exist in the array so the return value is " + index);
			}
			System.out.println(
					"----------------------------------------------------------------------------------------------------\n");
		}
	}
}