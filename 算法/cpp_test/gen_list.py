import random

length = 10
begin = -10
end = 10

list_out = []

for i in range(length):
    list_out.append(random.randint(begin, end))

list_sorted = sorted(list_out)

str_random = ' '.join([str(i) for i in list_out])
str_sort = ' '.join([str(i) for i in list_sorted])


baconFile = open('sort', 'w')
baconFile.write(str(length) + '\n' + str_random+'\n'+str_sort)
baconFile.close()
