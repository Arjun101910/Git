import matplotlib.pyplot as plt
import numpy as np

matrix = [
    [0, 1, 2, 3],
    [0,1,2,3],
    [0,1,2,3],
    [0,1,2,3]
]

print(matrix)

positive1=[0,1,2,3]
negative1=[3,2,1,0]

plt.imshow(matrix)
plt.plot(positive1,'rs-',linewidth=30)
plt.plot(negative1,'rs-',linewidth=30)
plt.show()