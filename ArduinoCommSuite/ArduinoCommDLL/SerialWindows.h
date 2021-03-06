/*************************************
**  Serial Windows
**
**  A good chunk of this implementation was initially plagarized off of the
**  Arduino-C++ interface page of the Arduino CC Playground, located here:
**
**  http://playground.arduino.cc/Interfacing/CPPWindows
**
**  However, I identified several bugs associated with the implementation,
**  and have fixed them and uploaded the changes to the above link.
**
********************************/

#ifdef _WINDOWS
#ifndef SERIALWINDOWS_H_INCLUDED
#define SERIALWINDOWS_H_INCLUDED

namespace SerialComm
{
	//Class meant to handle Serial communication in Windows
	class SerialWindows : public SerialGenericCOM
	{
	private:
		//Serial comm handle
		HANDLE hSerial;

		//Connection status
		bool connected;

		//Get various information about the connection
		COMSTAT status;

		//Keep track of last error
		DWORD errors;
	public:
		SerialWindows(bool bErrorSuppress);
		SerialWindows();

		virtual ~SerialWindows();

		virtual bool Connect();

		virtual int ReadData(char *buffer, unsigned int nbChar);

		virtual bool WaitReadData(char *buffer, unsigned int nbChar, unsigned long long ullMaxWait);
		virtual bool WriteData(const char *buffer, unsigned int nbChar);
		virtual bool WriteData(const std::string &sData);

		virtual bool IsConnected();
		virtual bool FlushBuffer();
		virtual int CharsInQueue();

		static const char *GetPortTemplate();
	};
}

#endif
#endif
