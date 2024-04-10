import numpy as np
x=np.linspace(0,2*np.pi,100)
y=np.sin(x)
import matplotlib.pyplot as plt
print(x,y)
plt.plot(x,y)
plt.xlabel('value of x')
plt.ylabel('value of y')
plt.show()