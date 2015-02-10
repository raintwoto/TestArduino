%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Function:  SerialDataAvail() returns message
%
%  Waits for a message from the Arduino, Pausing the script in the meantime.
%  WaitForMessage() waits for one byte to arrive (default).
%  WaitForMessage(bytes) waits for the indicated number of bytes to arrive.
%
%  Global Variables:
%    Owned:
%    External:
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function bAvail = SerialDataAvail()
		bAvail = (calllib('ArduinoCommDLL','GetCharAvailable') > 0);
end
