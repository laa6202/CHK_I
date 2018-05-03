%xdm-i.m
%debug for UART3

%0.
clear all
clc

%1. global varialbe
com_num = 'COM13';
total_sec = 30;


%2. file name
tt = clock;
fn = strcat('d',num2str(tt(1)-2000),num2str(tt(2)),num2str(tt(3)),'_',num2str(tt(4)),num2str(tt(5)),num2str(round(tt(6))),'.dat');
disp(strcat('file name :', fn));
fid = fopen(fn,'a+');
clear tt;


%3. open COM
data = zeros(8000,1);
s13 =  serial(com_num, 'BaudRate', 115200);
set(s13,'InputBufferSize',50000);
fopen(s13);

if(s13.BytesAvailable >0)
	data = fread(s13,s13.BytesAvailable,'uint8');
end

%4. save data
sec_index = 0;
while(1)
    if(s13.BytesAvailable > 8000)
        data = fread(s13,8000,'uint8');
        fwrite(fid,data,'uint8');
        sec_index = sec_index + 1;
        disp(strcat('sec_index : ',int2str(sec_index),'/',int2str(total_sec)));
        if(sec_index == total_sec)
			break;
        end
    end
end


%5.close file
clear sec_index;
clear total_sec;
fclose(s13);
fclose(fid);
disp('END of uart data file save');

