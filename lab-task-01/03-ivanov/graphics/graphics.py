import matplotlib.pyplot as plt
import numpy as np
print ("Введите номер файла")
print ("1 - DiscreteState.txt")
print ("2 - SegmentState.txt")
print ("3 - SetState.txt")
a = int(input())
if (a == 1):
    my_file = open("DiscreteState.txt", "r")
elif (a == 2):
    my_file = open("SegmentState.txt", "r")
elif (a == 3):
    my_file = open("SetState.txt", "r")
content = my_file.read()
content_list = content.split("\n")
content_list.pop()
my_file.close()
N = []
for i in range(0, 100000, 500):
    N.append(i)
for i in range(len(content_list)):
    content_list[i] = float(content_list[i]) 
fig = plt.figure()
ax = fig.add_subplot(111)
ax.set_xlabel('N')
ax.set_ylabel('pt(a)')
ax.grid()
ax.set_title('pt(N)')
ax.plot(N, content_list, '.k')

plt.show()
