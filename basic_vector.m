t=0:12;
f=sin(t);
g=exp(-10*t);
h=f.*g;
plot(h,t);
xlabel('value of h');ylabel('value of t');
grid on
axis padded
axis equal