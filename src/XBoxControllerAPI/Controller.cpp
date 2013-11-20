// Class1.cpp
#include "pch.h"
#include "Controller.h"

using namespace XBoxControllerAPI;
using namespace Platform;

const uint64    XINPUT_ENUM_TIMEOUT_MS = 2000;  // 2 seconds

Controller::Controller()
{
}

ControllerReading^ Controller::GetCurrentReading()
{
	ControllerReading^ reading = nullptr;
	if (!m_isControllerConnected)
	{
		//
		// Ennumerating for XInput devices takes 'time' on the order of milliseconds.
		// Any time a device is not currently known as connected (not yet called XInput, or calling
		// an XInput function after a failure) ennumeration happens.
		// An app should avoid repeatedly calling XInput functions if there are no known devices connected
		// as this can slow down application performance.
		// This sample takes the simple approach of not calling XInput functions after failure
		// until a specified timeout has passed.
		//
		uint64 currentTime = ::GetTickCount64();
		if (currentTime - m_lastEnumTime < XINPUT_ENUM_TIMEOUT_MS)
		{
			return reading;
		}
		m_lastEnumTime = currentTime;

		// Check for controller connection by trying to get the capabilties
		uint32 capsResult = XInputGetCapabilities(0, XINPUT_FLAG_GAMEPAD, &m_xinputCaps);
		if (capsResult != ERROR_SUCCESS)
		{
			return reading;
		}

		// Device is connected
		m_isControllerConnected = true;
	}

	uint32 stateResult = XInputGetState(0, &m_xinputState);
	if (stateResult != ERROR_SUCCESS)
	{
		// Device is no longer connected
		m_isControllerConnected = false;
		m_lastEnumTime = ::GetTickCount64();
	}
	auto gamepad = ref new GamePad(static_cast<GamePadButtons>(m_xinputState.Gamepad.wButtons),
		m_xinputState.Gamepad.bLeftTrigger, m_xinputState.Gamepad.bRightTrigger, m_xinputState.Gamepad.sThumbLX, m_xinputState.Gamepad.sThumbLY,
		m_xinputState.Gamepad.sThumbRX, m_xinputState.Gamepad.sThumbRY);
	reading = ref new ControllerReading(gamepad);
	return reading;
}