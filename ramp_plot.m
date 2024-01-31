%% 
% making a unit funtion
% 
% inorder to make a array of the sine wave we need to initialize the array of 
% zeros

y_array=zeros(1,10)
%% 
% logic code


for i=1:10:90
       
    y_array(i)=sin(i*180/pi)
end
%% 
% ploting all the points together

m=plot(i,y_array,'s-')
xlabel=('value of the i')
ylabel=('value of the y')
%% 
% making the plot beautiful

set(gca,'fontsize',16)
legendme=legend('Ramp')
set(rampplot,'linewidth',20,'color','r')