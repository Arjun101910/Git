%first is the frequency sampling
order=1;
startf=1;
decround=6;
f1=1:.1:9.9;
f1=startf*f1;
for l=1:decround
    for k=1:90
        i=(l-1)*90+k;
        f(i)=f1(k)*10^(l-1);

    end
end

%below is the numerator and denominator of the z transfer function
[nzbi,dzbi]=tfdata(zbi,'v');
[nzfh,dzfh]=tfdata(zfh,'v');
[nzzh,dzzh]=tfdata(zzh,'v');


na=order+1;% vector order is 1 more than system order

for l=1:decround*90;
z=2*cos(2*pi*f(i)*dt)+sqrt(-1)*sin(2*pi*f(i)*dt);
s=sqrt(-1)*(2*pi*f(i));
As(i)=0;
Bs(i)=0;
Abi(i)=0;
Bbi(i)=0;
Afh(i)=0;
Bfh(i)=0;
Azh(i)=0;
Bzh(i)=0;

for l1=1:na
    As(i)=As(i)+ns(11)*s(na-l1);
    Bs(i)=Bs(i)+ds(l1)*s(na-l1);
    Abi(i)=Abi(i)+nzbi(l1)*z(na-l1);
    Bbi(i)=Bbi(i)+dzbi(l1)*z(na-l1);
    Afh(i)=Afh(i)+nzfh(l1)*z(na-l1);
Bfh(i)=Bfh(i)+dzfh(l1)*z(na-l1);
Azh(i)=Azh(i)+nzzh(l1)*z(na-l1);
Bzh(i)=Bzh(i)+dzzh(l1)*z(na-l1);


end

Frqlap(i)=As(i)/Bs(i);
Frqzbi(i)=Abi(i)/Bbi(i);
Frqzfh(i)=Afh(i)/Bfh(i);
Frqzzh(i)=Azh(i)/Bzh(i);

end 
figure;
semilogx(f,abs(Frqlap),'r',f,abs(Frqzbi),'b',f,abs(Frqzfh),'g',f,abs(Frqzzh));
grid;
title('Frequency response');
xlabel('frequency_HZ');
ylabel('Value');
axis image



