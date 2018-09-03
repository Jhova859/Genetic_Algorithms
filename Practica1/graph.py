import matplotlib.pyplot as plt
import numpy as np

def readValues():
	file = open("/tmp/values.txt")
	lines = file.readlines()
	list = []
	for x in lines:
		if x != "\n":
			list.append(int(x))

	return list


print("Creating histogram...")
values = readValues()
l = len(values)
n, bins, patches = plt.hist(x=values, bins=l, range=(0,values[l-1]), color='#0504aa',
                            alpha=0.7, rwidth=1.8, align='right')

plt.grid(axis='y', alpha=0.75)
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('Histogram')
plt.text(23, 45, r'$\mu=15, b=3$')
maxfreq = n.max()

plt.ylim(ymax=np.ceil(maxfreq / 10) * 10 if maxfreq % 10 else maxfreq + 10)
plt.show()
