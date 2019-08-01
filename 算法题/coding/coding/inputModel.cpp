#include "inputHeader.h"
#include "core.h"

using namespace std;

//已知输入长度
void test0() {
	int N;
	cin >> N;
	vector<int> nums;
	int val;
	while (N--) {
		cin >> val;
		nums.push_back(val);
	}
}

//未知输入长度
//已知输入个数
void test1() {
	int N;
	cin >> N;
	vector<vector<int> > nums;
	vector<int> tmp;
	int val;
	string s;
	while (N--) {
		getline(cin, s);
		stringstream ss(s);
		while (ss >> val) {
			tmp.push_back(val);
			//...
		}
		nums.push_back(tmp);
		tmp.clear();
	}
}

//啥玩意都不知道
void test2() {
	ifstream fin("file.txt");
	string s;
	int val;
	vector<int> tmp;
	while (getline(fin, s)) {
		stringstream ss(s);
		while (ss >> val) {
			tmp.push_back(val);
			//...
		}
		tmp.clear();
	}
}

void func1() {
	int a, b;
	while (cin >> a >> b)//注意while处理多个case
		cout << a + b << endl;
}

//不说明有多少个 Input，以 EOF 为结束标志
void func2() {
	
	int a, b;
	while (cin >> a >> b) {
		// ...
	}
}

//输入不说明有多少个 Input，以某个特殊输入为结束标志
void func3() {
	
	int a, b;
	while (cin >> a >> b) {
		if (a == 0 && b == 0)
			break;
		// ...
	}
}

//指示有 N 个 Input
void func4() {
	
	int n;
	cin >> n;

	int a, b;
	while (n--) {
		cin >> a >> b;
	}
}

//输入是一整行
//用 char[] 接收（C/C++）
void func5() {
	
	const int MAXN = 1000;
	char buff[MAXN];
	cin.getline(buff, MAXN);  // 第三个参数默认是 '\n'
	cin.getline(buff, MAXN, '\n');
	//用 string 接收（C++）
	string s;
	getline(cin, s);          // 第三个参数默认是 '\n'
	getline(cin, s, '\n');
}

//输入是多行（包括空格）
void func6() {
	
	int n;
	cin >> n;
	cin.get();  // 上一步后，指针移动到'\n'之前，cin.get()可以读掉这个换行符，否则getline将会读取一个空行。

	while (n--) {
		string s;
		getline(cin, s);
	}
}

//从文件读取
void func7() {
	
	ifstream fin("in.txt");
	ofstream fout("out.txt");

	int a, b;
	while (fin >> a >> b) {
		fout << a + b << endl;
	}

	fin.close();
	fout.close();
}

//从文件读取多行信息！！！
//当未指定每行长度时比较有用
void func8() {
	ifstream fin("file.txt");
	string s;
	int tmp;
	while (getline(fin, s)) {//将当前行读入字符串s
		stringstream ss(s);//将字符串s转化为istream流对象，
		while (ss >> tmp) {//将ss流对象中的字符输入到tmp中。
			//...
		}
	}
}