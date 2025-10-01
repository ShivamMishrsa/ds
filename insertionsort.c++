#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
   int n = arr.size();
   for (int i = 1; i < n; ++i) {
      int curr = arr[i];
      int j = i - 1;
   
      while (j >= 0 && arr[j] > curr) {
         arr[j + 1] = arr[j];
         --j;
      }
      arr[j + 1] = curr;
   }
}

int main() {
   std::vector<int> arr = {12, 11, 13, 5, 6};
   insertionSort(arr);

   std::cout << "Sorted array: ";
   for (int num : arr)
      std::cout << num << " ";
   std::cout << std::endl;

   return 0;
}