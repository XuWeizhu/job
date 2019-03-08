#输入输出。
import sys 
for line in sys.stdin:
    a = line.split()
    print(int(a[0]) + int(a[1]))

#以空行作退出
while True:
    try:
        a = input()
        print(a)
    except:
        break
#python3里还是多用input，方便点。
#input 会把末尾的换行符去掉
#input要在外围包一个try excpet 防止eof异常

