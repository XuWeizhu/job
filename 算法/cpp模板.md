### 基础操作

#### 输入输出

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
```

#### 直接使用各种结构

```C++
//堆
//队列
//

```



### 一些骚操作

#### IOU:交并比的计算:

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

