%% 
% Reading the data from the source and converting the data into array

data=readtable("male_female.xlsx")
data=table2array(data)
%% 
% Plot the graph for the women in the curve

women=data(:,3)
figure
plot(women)
%% 
% year on the x axis

years=data(:,1)
figure
plot(years,women)
%% 
% men on the plot

men=data(:,2)
figure
hold on
plotW=plot(years,women)
plotM=plot(years,men)
%% 
% enhancing the  beauty of the plot

title('Unemployment rate of Nepal for both MEn ')
xlabel("number of years in the x axis")
ylabel("number of men and women rate in %")
legendme=legend('men','women')
xlim([2008,2020])
ylim([0,20])
set(gca,'fontsize',16)
set([plotM,plotW],'linewidth',2)
set(legendme,'fontsize',30)