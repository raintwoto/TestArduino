// ArduinoCommTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#ifdef _WINDOWS
#include "../ArduinoCommDLL/ArduinoCommDLL.h"
#endif // _WINDOWS

#ifdef _UNIX
#include "../ArduinoCommDLL/ArduinoCommSO.h"
#define _tmain main
#define _TCHAR char
#endif // _UNIX

#include "../ArduinoCommDLL/CoreFunctions.h"


int _tmain(int argc, _TCHAR* argv[])
{
	SerialComm::ArduinoComm::Init();

	int piArduinos[10] = {};
	SerialComm::ArduinoComm::FindArduinos(piArduinos, 10);
	if (piArduinos[0] != 0)
	{
		std::cout << "Arduinos found on ports: ";
	}
	else
	{
		std::cout << "No Arduinos found." << std::endl << "Quitting" << std::endl;
		std::string sInput;
		std::cin >> sInput;
		return 0;
	}

	for (int i : piArduinos)
	{
		if (i)
		{
			std::cout << i << "  ";
		}
	}

	int iPort;
	std::cout << std::endl << "Connect to Port: ";
	std::cin >> iPort;

	SerialComm::ArduinoComm::SetProperties(true);

	if (!SerialComm::ArduinoComm::Connect(iPort))
	{
		std::cout << "Failure to connect to Port " << iPort << "." << std::endl << "Quitting" << std::endl;
		std::string sInput;
		std::cin >> sInput;
		return 0;
	}

	SerialComm::millisecond msReadyTime = SerialComm::millisecondsNow() + 1000;

	std::cout << std::endl;

	if (SerialComm::ArduinoComm::GetCharAvailable())
	{
		while (SerialComm::millisecondsNow() < msReadyTime)
		{
			while (SerialComm::ArduinoComm::GetCharAvailable())
			{
				std::cout << SerialComm::ArduinoComm::ReadChar();
			}
		}
	}
	std::cout << std::endl;

	SerialComm::ArduinoComm::SendChar('Q');

	char cReflChar = SerialComm::ArduinoComm::WaitForChar(5000);

	std::cout << "Received Char: " << cReflChar << std::endl;
	std::cout << "Results: " << ((cReflChar == 'Q') ? "Success!" : "Failure!") << std::endl;
	std::cout << "More Chars: ";
	std::cout << std::endl;

	SerialComm::ArduinoComm::Disconnect();

	std::string sInput;
	std::cin >> sInput;
	return 0;
}

