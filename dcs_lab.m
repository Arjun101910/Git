clear;
dt=2e-3;
ns=[0  1];
ds=[.03  10];
as=tf(ns,ds);
zbi=c2d(as,dt,'tustin');%s domain transfer function%c2d command makes continuous to discrete
zfh=c2d(as,dt,'foh');%z domain transfer function using bilinear 
zzh=c2d(as,dt,'zoh');%z domain transfer function using zero order
