# !/usr/bin/env python3
# -*- coding: utf-8 -*-

# print absolute value of an integer
a = -100
if a >= 0:
    print(a)
else:
    print(-a)
# elif 是 else if 的缩写

# r 'strings'   ==  不转义
print(r'I\'m a \"OK\"\'')

# print more line use one "print"
print(r'''line1
line2
line3''')

s3 = r'Hello, "Bart"'
s4 = r'''Hello,
Lisa!'''
print(s3,
      s4)

# python中 如果一个val的值被更改了, 原内存中的数值不会变(有另一个变量指向这个内存的时候.没有是则回收垃圾)
# 当被更改时, 不会在指针区域重新新建,而是在内村中新建val的值

b = 'ABC'
c = b
b = 'abc'
print('b = ' + b)
print('c = ' + c)

# python字符串unicode编码

# 对于单个字符的编辑:
print(ord('A'))
print(chr(66))

# b开头表示bytes型数据 每个字符只占有一个字节 而python采取unicode编码 是每个字符两个字节
x = b'ABC'
y = 'ABC'
print(x == y)  # output false

# encode and decode
print('ABC'.encode('ascii'))
print('中'.encode('utf-8'))  # 中文转化为ascii时候回报错 ascii无法表示汉字

print(b'ABC'.decode('ascii'))

# 格式化输出 不要 " , " 号
print('%.2f' % 3.1415926)

# list duple
# list是有序的集合,可以添加和删除其中的元素
classmates = ['Michael', 'Bob', 'Tracy']
print(classmates)
print(len(classmates))
print(classmates[1])
print(classmates[-1])  # 最多倒数三个

classmates.append('ljp')
classmates.insert(2, 'lj')
# classmates.pop(i)  # 无参数的时候就表示删除最后一个元素.
print(classmates)

# tuple 元组.类似list 但是tuple一旦初始化就不能修改.(没有append(), insert()方法)
t = (1, 2, 5)
r = (1,)  # 表示r是只有一个元素的tuple
print(t)
# list tuple中的元素的类型可以不一致

# input
s = input('birth: ')
birth = int(s)
if birth < 2000:
    print('00前')
else:
    print('00后')





