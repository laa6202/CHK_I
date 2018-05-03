%xdm-i.m
%debug for UART3

%0.
clear all
clc

com_num = 'COM13';
total_sec = 10;


%1. file name
tt = clock;
fn = strcat('d',num2str(tt(1)-2000),num2str(tt(2)),num2str(tt(3)),'_',num2str(tt(4)),num2str(tt(5)),num2str(round(tt(6))),'.dat');
fid = fopen(fn,'a+');
clear tt;


%2. open COM
data = zeros(8000,1);
s13 =  serial(com_num, 'BaudRate', 115200);
set(s13,'InputBufferSize',50000);
fopen(s13);

if(s13.BytesAvailable >0)
	data = fread(s13,s13.BytesAvailable,'uint8');
end

%3. save data
sec_index = 0;
while(1)
    if(s13.BytesAvailable > 8000)
      data = fread(s13,8000,'uint8');
      fwrite(fid,data,'uint8');
			sec_index = sec_index + 1;
			if(sec_index == total_sec)
				break;
    end
end


%4.close file
clear sec_index;
clear total_sec;
fclose(s13);
fclose(fid);
