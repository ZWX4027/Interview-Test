#include<stdio.h>
typedef struct ADD
{
	int left;
	int right;
}ADD;

int parition(int arr[], int start, int end)//找到基准点后的基准点下标
{
	int boundkey = arr[start];
	while (start < end)//元素没有遍历完，如果start<=end表示所有数据比较完成
	{
		while (start < end && arr[end] >= boundkey)//元素没有遍历完并且大数就在后面，不用移动
			end--;
		arr[start] = arr[end];//后面有数据比基准值小
		while (start < end && arr[start] <= boundkey)//元素没有遍历完并且小数就在前面，不用移动
			start++;
		arr[end] = arr[start];
	}
	arr[end] = boundkey;
	return start;//此时start = end
}
void Quick(int arr[], int start, int end)//控制区间
{
	int key;
	if (start < end)//判断这个区间是否需要排序
	{
		key = parition(arr, start, end);//在start和end找到基准点
		Quick(arr, start, key - 1);//递归调用把基准点左边划分成一个区间
		Quick(arr, key + 1, end);//递归调用把基准点右边划分成一个区间
	}
}
void QuickSort(int arr[], int len)//拿到数据和数组大小,在主函数中被调用
{
	Quick(arr, 0, len - 1);
}

ADD EquipToK(int arr[], int len, int k)
{
	QuickSort(arr, len);
	ADD index = { -1, -1 };
	int low = 0;
	int high = len - 1;
	int sum;

	while (low <= high)
	{
		sum = arr[low] + arr[high];
		if (sum < k)
		{
			low++;
		}
		else if (sum > k)
		{
			high--;
		}
		else
		{
			index.left = low;
			index.right = high;
			break;
		}
	}
	return index;
}

int main()
{
	int arr[] = { 12, 3, 21, 32, 1, 34, 12, 35, 34 };
	int len = sizeof(arr) / sizeof(arr[0]);

	QuickSort(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	int k = 33;
	ADD index = EquipToK(arr, sizeof(arr) / sizeof(arr[0]), k);
	if (index.left == -1)
		printf("没有两数相加等于%d\n", k);
	else
		printf("相加等于%d的为%d,%d下标的值\n", k, index.left, index.right);

	return 0;
}