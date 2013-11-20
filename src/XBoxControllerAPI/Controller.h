#include <ControllerReading.h>

#pragma once

namespace XBoxControllerAPI
{
    public ref class Controller sealed
    {
    public:
        Controller();
		ControllerReading^ GetCurrentReading();
	private:
		// Input related members
		bool                    m_isControllerConnected;  // Do we have a controller connected
		XINPUT_CAPABILITIES     m_xinputCaps;             // Capabilites of the controller
		XINPUT_STATE            m_xinputState;            // The current state of the controller
		uint64                  m_lastEnumTime;           // Last time a new controller connection was checked

    };
}