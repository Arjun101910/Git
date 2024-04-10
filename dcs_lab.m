t = 0:0.1:10;
h = ones(1,11);
x = power(0.5,t);
y = conv(x,h);
subplot(3,1,1);
plot(t, x);
title('Continuous Time Convolutions (077BEL010 Arjun Oli)'); ylabel('x(t)');

subplot(3,1,2); plot(h); ylabel('h(t)');
subplot(3,1,3); plot(y); ylabel('y(t)');
xlabel('time');
