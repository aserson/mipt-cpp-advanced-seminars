import matplotlib.pyplot as plt
import matplotlib.style as style
import pandas as pd
import numpy as np

print("Введите, какой график хотите:\n0 - ex 1 for Segment \n1 - ex 1 for Set\n2 - Ex 3 for -Set + Segment "
      "\n3 - Ex 2 for Segment\n4 - Ex 2 for Set")
c = int(input())
if c == 0:
    data = pd.read_csv('./1_segment.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')
if c == 1:
    data = pd.read_csv('./1_set.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')
if c == 2:
    data = pd.read_csv('./3_comparicon.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')
if c == 3:
    data = pd.read_csv('./2_segment.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')
if c == 4:
    data = pd.read_csv('./2_set.txt', sep=r'\s*-\s*', header=0, encoding='utf8', engine='python')

style.use('ggplot')
if 0 <= c <= 2:
    x = data['Test_count'].to_numpy()
    y = data['P'].to_numpy()

    plt.ylabel('P')
    plt.xlabel('Test_count')

    plt.plot(x, y)
    plt.show()
else:
    x = data['end'].to_numpy()
    y1 = data['P(1000)'].to_numpy()
    y2 = data['P(2)'].to_numpy()
    y3 = data['P(3)'].to_numpy()
    y4 = data['P(4)'].to_numpy()
    y5 = data['P(5)'].to_numpy()
    y6 = data['P(6)'].to_numpy()
    y7 = data['P(7)'].to_numpy()
    y8 = data['P(8)'].to_numpy()
    y9 = data['P(9)'].to_numpy()
    y10 = data['P(10)'].to_numpy()

    plt.xlabel('end')
    plt.ylabel('P')

    plt.plot(x, y1, label='P(1000)')
    plt.plot(x, y2, label='P(2)')
    plt.plot(x, y3, label='P(3)')
    plt.plot(x, y4, label='P(4)')
    plt.plot(x, y5, label='P(5)')
    plt.plot(x, y6, label='P(6)')
    plt.plot(x, y7, label='P(7)')
    plt.plot(x, y8, label='P(8)')
    plt.plot(x, y9, label='P(9)')
    plt.plot(x, y10, label='P(10)')

    plt.legend()
    plt.grid(True)
    plt.show()
