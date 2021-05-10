#include <bits/stdc++.h>
using namespace std;

//交换两个节点值
void swap(vector<int>& nums, int m, int n) {
	int mid = nums[m];
	nums[m] = nums[n];
	nums[n] = mid;
}

//对一个节点进行堆化（大小顶堆）
//对于叶节点变动节点，需要判断与其子节点是否也能构成大（小）顶堆
//若不能，则需对该节点进行堆化操作（采用递归方法）
void heapify(vector<int>& nums, int n, int i) {
	if(i >= n) {
		return;
	}
	int c1 = 2 * i + 1;
	int c2 = 2 * i + 2;
	int max = i;
	if(c1 < n && nums[c1] > nums[max]) {
		max = c1;
	}
	if(c2 < n && nums[c2] > nums[max]) {
		max = c2;
	}
	if(max != i) {
		swap(nums, max, i);
		heapify(nums, n, max);
	}
}

//从完全二叉树最后一个根节点向上建堆
void build_heap(vector<int>& nums, int len) {
	int last_node = len - 1;
	int parent = (last_node - 1) / 2;

	for(int i = parent ; i >= 0 ; i --) {
		heapify(nums, len, i);
	}
}

//堆排序，每次获得堆顶的最大值元素
void sort_heap(vector<int>& nums, int len) {
	build_heap(nums, len);
	for(int i = len - 1 ; i >= 0 ; i--) {
		swap(nums, i, 0);
		build_heap(nums, i);
	}
}

int main() {
	vector<int> nums{1, 5, 7, 9, 15, 24, 6, 4, 8, 9, 9, 3};
	sort_heap(nums, nums.size());
	for(int i = 0 ; i < nums.size() ; i++)
		cout << nums[i] << " ";
	cout << endl;
	return 0;
}
