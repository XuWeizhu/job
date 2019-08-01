#### 基础操作

[ref1](https://github.com/imhuay/Algorithm_Interview_Notes-Chinese)

##### 输入输出

```C++
//输入输出
//使用循环读入,while(cin >> a;){}
//使用cout<<a<<endl;
#include <iostream>
using namespace std;
int main() {
    int a,b;
    while(cin >> a >> b)//注意while处理多个case
        cout << a+b << endl;
}

//不说明有多少个 Input，以 EOF 为结束标志
int a, b;
while (cin >> a >> b) {
    // ...
}

//输入不说明有多少个 Input，以某个特殊输入为结束标志
// 示例 1
int a, b;
while (cin >> a >> b) {
    if (a == 0 && b == 0)
        break;
    // ...
}
// 示例 2
int n;
while (cin >> n && n != 0) {
    // ...
}

//指示有 N 个 Input
int n;
cin >> n;

int a, b;
while(n--) {
    cin >> a >> b;
}

//输入是一整行（包括空格）

//用 char[] 接收（C/C++）
const int MAXN = 1000;
char buff[MAXN];
cin.getline(buff, MAXN);  // 第三个参数默认是 '\n'
cin.getline(buff, MAXN, '\n');
//用 string 接收（C++）
string s;
getline(cin, s);          // 第三个参数默认是 '\n'
getline(cin, s, '\n');

//输入是多行（包括空格）
int n;
cin >> n;
cin.get();  // 否则，n 也会计入下面的 getline()，导致少一组数据

while (n--) {
    string s;
    getline(cin, s);
}

//从文件读取
ifstream fin("in.txt");
ofstream fout("out.txt");

int a, b;
while (fin >> a >> b) {
    fout << a + b << endl;
}

fin.close();
fout.close();
```

##### 直接使用各种结构

```C++
//堆
//队列
//vector
vector.size()//大小
vector.empty()//判断是否为空
vector<int>::iterator iterint;

```

#### 一些骚操作

##### IOU:交并比的计算:

```c++
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct A
{
	int x0;
	int x1;
	int y0;
	int y1;
};

//判断是否重叠！该方法中边相交不算重合,将<=改为<,就可以将相交算作重合.
int f(A& a1, A& a2)
{
	int min_x = max(a1.x0, a2.x0);
	int min_y = max(a1.y0, a2.y0);
	int max_x = min(a1.x1, a2.x1);
	int max_y = min(a1.y1, a2.y1);
	//cout << min_x << " " << min_y << " " << max_x << " " << max_y << endl;
	if (max_x <= min_x || max_y <= min_y)
		return 0;
	return (max_x - min_x) * ( max_y - min_y);
}
```

