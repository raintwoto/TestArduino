// ArduinoCommCDLL.h : Defines the exported functions for the DLL application.
//
#ifndef ARDUINOCOMMDLL_H_
#define ARDUINOCOMMDLL_H_

#ifndef NOTMATLAB

#ifdef ARDUINOCOMMDLL_EXPORTS
#define ARDUINOCOMMDLL_API __declspec(dllexport)
#else
#define ARDUINOCOMMDLL_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif
	/*  Init() initializes the ArduinoCommDLL.  Returns success.
	*/
	ARDUINOCOMMDLL_API bool Init();
	/*  SetProperties(Relfectivity) is used to set the properties the Arduino will initialize with.
	If Reflexive, it will copy Serial messages back to their source.
	*/
	ARDUINOCOMMDLL_API bool SetRefl(bool bRefl);
	/*  SetProperties(Relfectivity,Pairedness,Masterness) is used to set the properties the Arduino will initialize with.
	If Reflexive, it will copy Serial messages back to their source.
	If Paired, it will communicate to a second Arduino using I2C
	If Master (and paired) it will be the Master in the I2C connection.
	If Not Master, it will be the Slave in the I2C connection.
	*/
	ARDUINOCOMMDLL_API bool SetProperties(bool bRefl, bool bPaired, bool bMaster);


	/*  IsConnected() returns whether the DLL is currently connected to an Arduino.
	*/
	ARDUINOCOMMDLL_API bool IsConnected();
	/*  Connect(PortNum) connects to the indicated Com Port number.
	Also responsible for communicating properties and initiating Arduino loop.
	Returns success.
	*/
	ARDUINOCOMMDLL_API bool Connect(int iPortNum);
	/*  FindArduinos(Arduinos[], MaxPortNum) writes an array of discovered Arduino ports to the supplied buffer.
	Buffer must be at least MaxPortNum in length.
	Searches from Com 1 up to the Com Port MaxPortNum.
	*/
	ARDUINOCOMMDLL_API void FindArduinos(int *piArduinos, int iMaxPortNum);


	/*  SendChar(char) sends a single character to the currently connected Arduino.
	Returns success.
	*/
	ARDUINOCOMMDLL_API bool SendChar(const char ccMessage);
	/*  SendChars(chars[],length) sends a full character string to the Arduino, of indicated length.
	Returns success.
	*/
	ARDUINOCOMMDLL_API bool SendChars(const char *cszMessage, int iLength);


	/*  GetCharAvailable() returns how many characters are currently in the Queue to be read.
	Returns -1 if not connected.
	*/
	ARDUINOCOMMDLL_API int GetCharAvailable();


	/*  ReadChar() returns the next character in the buffer if one is available.
	Returns a null character if the buffer is empty.
	Returns a null character if not connected.
	*/
	ARDUINOCOMMDLL_API char ReadChar();
	/*  ReadChars(Message[],Length) writes buffered messages to the supplied character buffer, up to indicated length.
	Returns the number of characters read.
	Writes a null character to Message[0] if the buffer is empty or the Arduino is not connected.
	Returns -1 if not connected.
	*/
	ARDUINOCOMMDLL_API int ReadChars(char *szMessage, int iNumChars);


	/*	WaitForChar(timeout) waits up to the indicated number of milliseconds for a character to arrive in the buffer.
	Returns as soon as message arrives, or immediately if the buffer is not empty.
	Returns a null character if the wait times out.
	Returns a null character if not connected.
	*/
	ARDUINOCOMMDLL_API char WaitForChar(int msTimeout);
	/*	WaitForChar(Message[],Length,timeout) waits up to the indicated number of milliseconds for the indicated number of character to be in the buffer.
	Returns as soon as sufficient characters are buffered, or immediately if the condition is met.
	If sufficient characters arrive, they are written to the supplied buffer.
	Writes a null character to the buffer if the wait times out or Arduino is not connected.
	Returns success.
	*/
	ARDUINOCOMMDLL_API bool WaitForChars(char *szMessage, int iCharNum, int msTimeout);

	/*  Disconnect() disconnects from the Arduino and destroys the serial information.
	*/
	ARDUINOCOMMDLL_API bool Disconnect();

#ifdef __cplusplus
}
#endif

#endif

#endif
