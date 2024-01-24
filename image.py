import matplotlib.pyplot as plt
import numpy as np
x=np.linspace(0,20,16)
matrix=x.reshape(4,4)
print(matrix)
positive=x
negative=sorted(positive,reverse=True)
print("the value of the positive x is \n",positive)

print("the value of the negative x is \n ",negative)
positive1=[1,2,3,4]
negative1=[4,3,2,1]

plt.imshow(matrix)
plt.plot(positive1)
plt.plot(negative1)
plt.show()