function[result]=factorial_in_matlab(num)
%  UNTITLED2 program to calculate the factorial of a number
if num~=1 && num~=1
    result= num*factorial_in_matlab(num-1);
else
    result= 1;
end
end
