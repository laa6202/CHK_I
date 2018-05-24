%rdata.m
%read data and analyze

%0 
clear all
clc

%1 
fn1 = 'd18524_205919.dat';
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


fclose(fid1);
clear fn1 fid1;

