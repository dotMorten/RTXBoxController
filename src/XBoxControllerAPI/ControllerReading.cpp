#include "pch.h"
#include "ControllerReading.h"

using namespace XBoxControllerAPI;

ControllerReading::ControllerReading(XBoxControllerAPI::GamePad^ gamepad)
{
	m_gamePad = gamepad;
}

GamePad::GamePad(GamePadButtons buttons, byte leftTrigger, byte rightTrigger,
	short ltx, short lty, short rtx, short rty)
{
	m_buttons = buttons;
	m_leftTrigger = leftTrigger;
	m_rightTrigger = rightTrigger;
	m_leftThumbX = ltx;
	m_leftThumbY = lty;
	m_rightThumbX = rtx;
	m_rightThumbY = rty;
}
