#### python处理字符串

##### 字符串读取：

- 读取原始字符串：

```python
import sys
line = sys.stdin.readline().strip()
#用sys.stdin.readline( )获取输入，会把末尾得'\n'也提取出来
#需要用.strip()来去掉首位符号，默认为空格或换行符。
line = raw_input()
#raw_input()不包含末尾得换行符
```

- 注意：python3 里 input() 默认接收到的是 str 类型。
- 注意：input() 和 raw_input() 这两个函数均能接收 字符串 ，但 raw_input() 直接读取控制台的输入（任何类型的输入它都可以接收）。而对于 input() ，它希望能够读取一个合法的 python 表达式，即你输入字符串的时候必须使用引号将它括起来，否则它会引发一个 SyntaxError 。除非对 input() 有特别需要，否则一般情况下我们都是推荐使用 raw_input() 来与用户交互。

- 一个骚操作：

```python
sn = list(map(int,input('Please input some numbers:\n').split()))#python3
sn = list(float(x) for x in line.split())
#将输入的带空格数字字符转换为int型数字
#我一般这么处理:
sample = [int(i) for i in input().split(' ')]
```

---



#### 其他整理

##### 字符串内建方法：

##### 1、去空格及特殊符号

复制代码代码如下:

s.strip().lstrip().rstrip(',')

##### **2、复制字符串**

复制代码代码如下:

\#strcpy(sStr1,sStr2)
sStr1 = 'strcpy'
sStr2 = sStr1
sStr1 = 'strcpy2'
print sStr2



##### **3、连接字符串**

复制代码代码如下:

\#strcat(sStr1,sStr2)
sStr1 = 'strcat'
sStr2 = 'append'
sStr1 += sStr2
print sStr1



##### **4、查找字符**

复制代码代码如下:

\#strchr(sStr1,sStr2)
\# < 0 为未找到
sStr1 = 'strchr'
sStr2 = 's'
nPos = sStr1.index(sStr2)
print nPos



##### **5、比较字符串**

复制代码代码如下:

\#strcmp(sStr1,sStr2)
sStr1 = 'strchr'
sStr2 = 'strch'
print cmp(sStr1,sStr2)



**6、扫描字符串是否包含指定的字符**

复制代码代码如下:

\#strspn(sStr1,sStr2)
sStr1 = '12345678'
sStr2 = '456'
\#sStr1 and chars both in sStr1 and sStr2
print len(sStr1 and sStr2)



##### **7、字符串长度**

复制代码代码如下:

\#strlen(sStr1)
sStr1 = 'strlen'
print len(sStr1)

##### **8、将字符串中的大小写转换**

复制代码代码如下:

S.lower() #小写 

S.upper() #大写 

S.swapcase() #大小写互换 

S.capitalize() #首字母大写 

String.capwords(S) #这是模块中的方法。它把S用split()函数分开，然后用capitalize()把首字母变成大写，最后用join()合并到一起 

\#实例：

\#strlwr(sStr1)

sStr1 = 'JCstrlwr'

sStr1 = sStr1.upper()

\#sStr1 = sStr1.lower()

print sStr1

##### **9、追加指定长度的字符串**

复制代码代码如下:

\#strncat(sStr1,sStr2,n)
sStr1 = '12345'
sStr2 = 'abcdef'
n = 3
sStr1 += sStr2[0:n]
print sStr1



##### **10、字符串指定长度比较**

复制代码代码如下:

\#strncmp(sStr1,sStr2,n)
sStr1 = '12345'
sStr2 = '123bc'
n = 3
print cmp(sStr1[0:n],sStr2[0:n])



##### **11、复制指定长度的字符**

复制代码代码如下:

\#strncpy(sStr1,sStr2,n)
sStr1 = ''
sStr2 = '12345'
n = 3
sStr1 = sStr2[0:n]
print sStr1



##### **12、将字符串前n个字符替换为指定的字符**

复制代码代码如下:

\#strnset(sStr1,ch,n)
sStr1 = '12345'
ch = 'r'
n = 3
sStr1 = n * ch + sStr1[3:]
print sStr1



##### **13、扫描字符串**

复制代码代码如下:

\#strpbrk(sStr1,sStr2)
sStr1 = 'cekjgdklab'
sStr2 = 'gka'
nPos = -1
for c in sStr1:
    if c in sStr2:
        nPos = sStr1.index(c)
        break
print nPos



##### **14、翻转字符串**

复制代码代码如下:

\#strrev(sStr1)
sStr1 = 'abcdefg'
sStr1 = sStr1[::-1]
print sStr1



##### **15、查找字符串**

复制代码代码如下:

\#strstr(sStr1,sStr2)
sStr1 = 'abcdefg'
sStr2 = 'cde'
print sStr1.find(sStr2)



##### **16、分割字符串**

复制代码代码如下:

\#strtok(sStr1,sStr2)
sStr1 = 'ab,cde,fgh,ijk'
sStr2 = ','
sStr1 = sStr1[sStr1.find(sStr2) + 1:]
print sStr1
\#或者
s = 'ab,cde,fgh,ijk'
print(s.split(','))



##### **17、连接字符串**

复制代码代码如下:

delimiter = ','
mylist = ['Brazil', 'Russia', 'India', 'China']
print delimiter.join(mylist)



##### **18、PHP 中 addslashes 的实现**

复制代码代码如下:

def addslashes(s):
    d = {'"':'\\"', "'":"\\'", "\0":"\\\0", "\\":"\\\\"}
    return ''.join(d.get(c, c) for c in s)

s = "John 'Johny' Doe (a.k.a. \"Super Joe\")\\\0"
print s
print addslashes(s)



##### **19、只显示字母与数字**

复制代码代码如下:

def OnlyCharNum(s,oth=''):
    s2 = s.lower();
    fomart = 'abcdefghijklmnopqrstuvwxyz0123456789'
    for c in s2:
        if not c in fomart:
            s = s.replace(c,'');
    return s;

print(OnlyStr("a000 aa-b"))



##### **20、截取字符串**

复制代码代码如下:

str = '0123456789′
print str[0:3] #截取第一位到第三位的字符
print str[:] #截取字符串的全部字符
print str[6:] #截取第七个字符到结尾
print str[:-3] #截取从头开始到倒数第三个字符之前
print str[2] #截取第三个字符
print str[-1] #截取倒数第一个字符
print str[::-1] #创造一个与原字符串顺序相反的字符串
print str[-3:-1] #截取倒数第三位与倒数第一位之前的字符
print str[-3:] #截取倒数第三位到结尾
print str[:-5:-3] #逆序截取，具体啥意思没搞明白？



##### **21、字符串在输出时的对齐** 

复制代码代码如下:

S.ljust(width,[fillchar]) 
\#输出width个字符，S左对齐，不足部分用fillchar填充，默认的为空格。 
S.rjust(width,[fillchar]) #右对齐 
S.center(width, [fillchar]) #中间对齐 
S.zfill(width) #把S变成width长，并在右对齐，不足部分用0补足



##### **22、字符串中的搜索和替换** 

复制代码代码如下:

S.find(substr, [start, [end]]) 
#返回S中出现substr的第一个字母的标号，如果S中没有substr则返回-1。start和end作用就相当于在S[start:end]中搜索 
S.index(substr, [start, [end]]) 
#与find()相同，只是在S中没有substr时，会返回一个运行时错误 
S.rfind(substr, [start, [end]]) 
#返回S中最后出现的substr的第一个字母的标号，如果S中没有substr则返回-1，也就是说从右边算起的第一次出现的substr的首字母标号 
S.rindex(substr, [start, [end]]) 
S.count(substr, [start, [end]]) #计算substr在S中出现的次数 
S.replace(oldstr, newstr, [count]) 
#把S中的oldstar替换为newstr，count为替换次数。这是替换的通用形式，还有一些函数进行特殊字符的替换 
S.strip([chars]) 
#把S中前后chars中有的字符全部去掉，可以理解为把S前后chars替换为None 
S.lstrip([chars]) 
S.rstrip([chars]) 
S.expandtabs([tabsize]) 
#把S中的tab字符替换没空格，每个tab替换为tabsize个空格，默认是8个



##### **23、字符串的分割和组合** 

复制代码代码如下:

S.split([sep, [maxsplit]]) 
\#以sep为分隔符，把S分成一个list。maxsplit表示分割的次数。默认的分割符为空白字符 
S.rsplit([sep, [maxsplit]]) 
S.splitlines([keepends]) 
\#把S按照行分割符分为一个list，keepends是一个bool值，如果为真每行后而会保留行分割符。 
S.join(seq) #把seq代表的序列──字符串序列，用S连接起来



##### **24、字符串的mapping，这一功能包含两个函数** 

复制代码代码如下:

String.maketrans(from, to) 
\#返回一个256个字符组成的翻译表，其中from中的字符被一一对应地转换成to，所以from和to必须是等长的。 
S.translate(table[,deletechars]) 
\# 使用上面的函数产后的翻译表，把S进行翻译，并把deletechars中有的字符删掉。需要注意的是，如果S为unicode字符串，那么就不支持 deletechars参数，可以使用把某个字符翻译为None的方式实现相同的功能。此外还可以使用codecs模块的功能来创建更加功能强大的翻译表。



##### **25、字符串还有一对编码和解码的函数** 

复制代码代码如下:

S.encode([encoding,[errors]]) 
\# 其中encoding可以有多种值，比如gb2312 gbk gb18030 bz2 zlib big5 bzse64等都支持。errors默认值为"strict"，意思是UnicodeError。可能的值还有'ignore', 'replace', 'xmlcharrefreplace', 'backslashreplace' 和所有的通过codecs.register_error注册的值。这一部分内容涉及codecs模块，不是特明白 
S.decode([encoding,[errors]])



**26、字符串的测试、判断函数，这一类函数在string模块中没有，这些函数返回的都是bool值** 

复制代码代码如下:

S.startswith(prefix[,start[,end]]) 
\#是否以prefix开头 
S.endswith(suffix[,start[,end]]) 
\#以suffix结尾 
S.isalnum() 
\#是否全是字母和数字，并至少有一个字符 
S.isalpha() #是否全是字母，并至少有一个字符 
S.isdigit() #是否全是数字，并至少有一个字符 
S.isspace() #是否全是空白字符，并至少有一个字符 
S.islower() #S中的字母是否全是小写 
S.isupper() #S中的字母是否便是大写 
S.istitle() #S是否是首字母大写的

##### 27、字符串类型转换函数，这几个函数只在string模块中有**

复制代码代码如下:

string.atoi(s[,base]) 
\#base默认为10，如果为0,那么s就可以是012或0x23这种形式的字符串，如果是16那么s就只能是0x23或0X12这种形式的字符串 
string.atol(s[,base]) #转成long 
string.atof(s[,base]) #转成float

