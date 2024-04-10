##how to find factorial of a number in python using recursive loop
def facto(num):
    if(num!=1 and num!=0):
        return num*facto(num-1)
    ##it is because 5!=5*4*3*2*1
    else: 
        return 1
    
result=facto(6)
print("the factorial of a number is",result)    
