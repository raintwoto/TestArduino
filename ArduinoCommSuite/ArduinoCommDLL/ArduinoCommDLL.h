// ArduinoCommDLL.h : Defines the exported functions for the DLL application.
//
#ifndef ARDUINOCOMMDLL_H_
#define ARDUINOCOMMDLL_H_

#ifdef ARDUINOCOMMDLL_EXPORTS
#define ARDUINOCOMMDLL_API __declspec(dllexport)
#else
#define ARDUINOCOMMDLL_API __declspec(dllimport)
#endif

#include "ArduinoClass.h"
#include <string>

namespace SerialComm
{
	class Arduino;

	class ArduinoComm
	{
	public:
		static ARDUINOCOMMDLL_API bool Init();

		static ARDUINOCOMMDLL_API bool SetProperties(bool bRefl, bool bPaired = false, bool bMaster = false);

		static ARDUINOCOMMDLL_API bool Connect(int iPortNum);

		static ARDUINOCOMMDLL_API void FindArduinos(int *piArduinos, int iMaxPortNum);

		static ARDUINOCOMMDLL_API bool SendChar(const char ccMessage);
		static ARDUINOCOMMDLL_API bool SendChars(const char *cszMessage, int iLength);
		static ARDUINOCOMMDLL_API bool SendString(const std::string csMessage);

		static ARDUINOCOMMDLL_API int GetCharAvailable();

		static ARDUINOCOMMDLL_API char ReadChar();
		static ARDUINOCOMMDLL_API void ReadChars(char *szMessage, int iNumChars);
		static ARDUINOCOMMDLL_API void ReadString(std::string &sMessage);

		static ARDUINOCOMMDLL_API char WaitForChar(int msTimeout);
		static ARDUINOCOMMDLL_API int WaitForChars(char *szMessage, int iCharNum, int msTimeout);
		static ARDUINOCOMMDLL_API int WaitForString(std::string &sMessage, int iCharNum, int msTimeout);

		static ARDUINOCOMMDLL_API bool Disconnect();
	protected:
		static bool m_bInitialized;
		static Arduino m_sArduino;
	};

}

#endif