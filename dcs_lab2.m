
T=0:dt:0.04;
[ylp,t]=step(as,T);
[ybi]=step(zbi,T);
[yfh]=step(zfh,T);
[yzh]=step(zzh,T);
plot(t,ybi,'g',t,yfh,'b',t,yzh);
grid on;
title('Step response');
xlabel('time sec');
ylabel('Value of the order');
axis equal