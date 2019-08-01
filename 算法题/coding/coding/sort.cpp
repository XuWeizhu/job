#include "sort.h"

using namespace std;

// 静态成员类型需要在此初始化，就是重定义下，调用vector的默认构造函数。
vector<vector<int> > sort::vecRandom;
vector<vector<int> > sort::vecLabel;

//读取数据并检查合法性
bool sort::initialize(string dir)
{
	//read data from file and store the random list and label list to vectors.
	//check the size of two vectors.
	ifstream fin(dir);
	string label;
	string testCase;
	int tmp;
	vector<int> tmpVec;
	while (getline(fin, testCase)) {
		stringstream s1(testCase);
		cout << testCase << endl;
		while (s1 >> tmp) {
			tmpVec.push_back(tmp);
		}
		vecRandom.push_back(tmpVec);
		tmpVec.clear();

		getline(fin, label);
		stringstream s2(label);
		cout << label << endl;
		while (s2 >> tmp) {
			tmpVec.push_back(tmp);
		}
		vecLabel.push_back(tmpVec);
		tmpVec.clear();

		cout << endl;
	}
	fin.close();
	

	if (vecLabel.size() != vecRandom.size()) {
		//cout << vecLabel.size() <<"  "<< vecRandom.size() << endl;
		return false;
	}

	for (int i = 0;i < vecLabel.size();++i) {
		if (vecLabel[i].size() != vecRandom[i].size()) {
			//cout << vecLabel[i].size() <<"  "<< vecRandom[i].size() << endl;
			return false;
		}
	}
	return true;
}

//判断两个vector是否相等
bool sort::checkCore(vector<int> random, vector<int> label)
{
	if (random.size() != label.size()) return false;
	if (random.empty() && label.empty()) return true;
	for (int i = 0;i < random.size();++i) {
		if (random[i] != label[i]) return false;
	}
	return true;
}

//判断sort函数是否通过所有用例
void sort::check(pf p)
{
	vector<int> res;
	for (int i = 0;i < vecLabel.size();++i) {
		res = p(vecRandom[i]);
		if (!checkCore(res, vecLabel[i])) {
			cout << "wrong!" << i << endl;

			cout << "the random input : " << endl;
			for (int j = 0;j < vecRandom[i].size();++j) {
				cout << vecRandom[i][j] << ' ';
			}
			cout << endl;

			cout << "the result : " << endl;
			for (int j = 0;j < res.size();++j) {
				cout << res[j] << ' ';
			}
			cout << endl;

			cout << "the label : " << endl;
			for (int j = 0;j < vecLabel[i].size();++j) {
				cout << vecLabel[i][j] << ' ';
			}
			cout << endl;
		}
			
	}
	cout << "finish" << endl;
}

//交换vector中两个元素
void sort::exch(vector<int>& random, int index1, int index2)
{
	int tmp = random[index1];
	random[index1] = random[index2];
	random[index2] = tmp;
	return;
}

//选择排序
//- 每次选一个最小的放到数组前面
//- 运行时间与输入无关，需要N^2/2次比较与N次交换．
//- 数据移动最少．
vector<int> sort::select(vector<int> nums)
{
	if (nums.empty()) return nums;

	int N = nums.size();
	for (int i = 0;i < N;++i) {
		int min_val = nums[i];
		for (int j = i;j < N;++j) {
			if (nums[j] < min_val) {
				min_val = nums[j];
				exch(nums, i, j);
			}
		}
	}
	return nums;
}

//插入排序
//- 排序速度与数据分布有关，当数据部分有序时速度较快
//- 需要较多的交换次数
vector<int> sort::insert(vector<int> nums) {
	int N = nums.size();
	for (int i = 1;i < N;++i) {
		int j = i;
		while (nums[j] < nums[j - 1] && j >= 1) {
			exch(nums, j-1, j);
			--j;
		}
	}
	return nums;
}

//希尔排序
//- 唯一无法准确描述其对乱序数组的性能特征．
//- 一次移动更远的距离，来提高运算速度.
//- 在数据量并不是特别大时，速度仅比高级排序慢一两倍，而且代码简单，五额外空间．
vector<int> sort::shell(vector<int> A)
{
	int N = A.size();
	int h = 0;
	while (h < N / 3) h = h * 3 + 1;
	while (h >= 1) {
		for (int i = h;i < N;++i) {
			int j = i;
			while (A[j] < A[j - h] && j >= h) {
				exch(A, j, j - h);
				j -= h;
			}
		}
		h /= 3;
	}
	return A;
}



vector<int> sort::quick(vector<int> nums)
{
	return vector<int>();
}
