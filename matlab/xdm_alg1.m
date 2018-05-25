%rdata.m
%read data and analyze

%0 
clear all
clc

%1 
fn1 = 'd18525_171455.dat';
fid1 =  fopen(fn1,'r');


%2
d_all = fread(fid1, 'uint8');
len_all = length(d_all);
slice_all = len_all/4000;

%3
d = zeros(4000,slice_all);
f = zeros(4000,slice_all);
for i=1:slice_all
	for j=1:4000
		d(j,i) = d_all((i-1) * 4000 +j);
	end
	f(:,i) = abs(fft(d(:,i)));
end

%4 filter
fir_low = 200;
for i=1:slice_all
	for j=1:fir_low
		f(j:i) = 0;
	end
	for(j=4000-fir_low:4000)
		f(j:i) = 0;
	end
end


%5 fm
fm = zeros(2000,slice_all);
for i=1:slice_all
	fm(:,i) = f(1:2000,i);
end


%6 m
m = zeros(1,slice_all);
for i=1:slice_all
	m(1,i) = mean(fm(:,i));
end


%7
mz = zeros(1,slice_all-4);
for i=1:slice_all-4
	mz(1,i) = (m(1,i) + m(1,i+1) + m(1,i+2) + m(1,i+3) + m(1,i+4)) /5;
end


%8 rot
b = 60;
h = 150;
rot = zeros(1,slice_all);
for i=1:slice_all-4
	y = mz(1,i) - 60;
	y1 = y / (h-b);
	y2 = y1 * 28;
	y3 = ceil(y2);
	if y3 > 28
		y3 = 28;
	end
	if y3 < 0
		y3 = 0;
	end
	y4 = y3 * 100;
	rot(1,i) = y4;
end


%9 plot
subplot(1,2,1);
plot(m);
subplot(1,2,2);
plot(rot);


fclose(fid1);
clear fn1 fid1;

