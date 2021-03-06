%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  TestSpeed.m
%
%  A Task meant to characterize the response time of the Arduino
%
%  Global Variables:
%    Owned:
%    External:
%      Owner: Init
%        bCallback - Can be used to disable the callback.
%
%  Required Functions:
%    Init
%    SerialInit
%    SendMessage
%    WaitForMessage
%    SerialCleanup
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

global bCallback;

%Prepare global variables
Init();

%These properties can be used to set the Arduino into Reflective mode and Paired Mode
%%Reflective Mode has the Arduino reflect messages back to the sender.
%%%NOTE: This task (unlike most) is dependent on the Reflective property.
bReflective = true;
%%Paired Mode has the Arduino initiate communication with another Arduino.
bPaired = false;
%Initiate the Serial Device and pass along the Property values.
SerialInit(bReflective,bPaired);

%Disables the callback feature, as we'll be waiting on messages manually
bCallback = false;

deltat1=zeros(1,10000);

while ( SerialDataAvail() )
    display(ReadChar());
end

tmp1=toc;
SendMessage('G');
tmp = WaitForMessage();
while ( tmp ~= 'G')
   display(['Wrong Char: ',int(tmp)]); 
   tmp = WaitForMessage();
end
tmp2=toc;
%display(1000*(tmp2-tmp1));


for i=1:10000
	tmp1=toc;
    SendMessage('G');
    tmp = WaitForMessage();
    while ( tmp ~= 'G')
       display(['Wrong Char: ',tmp]); 
       tmp = WaitForMessage();
    end
    tmp2=toc;
	deltat1(i)=tmp2-tmp1;
end

deltat1=1000*deltat1;

disp(['Mean time(ms): ',num2str(mean(deltat1))]);
disp(['Standard Dev(ms): ',num2str(std(deltat1))]);
disp(['Max time(ms): ',num2str(max(deltat1))]);

SerialCleanup();