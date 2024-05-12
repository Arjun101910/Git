import matplotlib.pyplot as plt
import numpy as np

matrix = [
    [0, 1, 2, 3],
    [0,1,2,3],
    [0,1,2,3],
    [0,1,2,3]
]

print(matrix)


negative1=[2.5,3]
positive1=[3,2,1,0]
plt.imshow(matrix)
plt.plot(positive1,'rs-',linewidth=30)
plt.plot(negative1,'rs-',linewidth=30)
plt.show()