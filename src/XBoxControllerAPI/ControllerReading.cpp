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

float GamePad::LeftThumbXNormalized::get() 
{
	float LX = m_leftThumbX;
	if (LX<0)LX = -LX;
	//check if the controller is outside a circular dead zone
	if (LX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		//adjust magnitude relative to the end of the dead zone
		LX -= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE;

		//optionally normalize the magnitude with respect to its expected range
		//giving a magnitude value of 0.0 to 1.0
		LX = LX / (32767 - XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
	}
	else //if the controller is in the deadzone zero out the magnitude
	{
		LX = 0.0;
	}
	return m_leftThumbX < 0 ? -LX : LX;
}
float GamePad::LeftThumbYNormalized::get()
{
	float LY = m_leftThumbY;
	if (LY<0)LY = -LY;
	//check if the controller is outside a circular dead zone
	if (LY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		//adjust magnitude relative to the end of the dead zone
		LY -= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE;

		//optionally normalize the magnitude with respect to its expected range
		//giving a magnitude value of 0.0 to 1.0
		LY = LY / (32767 - XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
	}
	else //if the controller is in the deadzone zero out the magnitude
	{
		LY = 0.0;
	}
	return m_leftThumbY < 0 ? -LY : LY;
}


float GamePad::RightThumbXNormalized::get()
{
	float LX = m_rightThumbX;
	if (LX<0)LX = -LX;
	//check if the controller is outside a circular dead zone
	if (LX > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
	{
		//adjust magnitude relative to the end of the dead zone
		LX -= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE;

		//optionally normalize the magnitude with respect to its expected range
		//giving a magnitude value of 0.0 to 1.0
		LX = LX / (32767 - XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
	}
	else //if the controller is in the deadzone zero out the magnitude
	{
		LX = 0.0;
	}
	return m_rightThumbX < 0 ? -LX : LX;
}
float GamePad::RightThumbYNormalized::get()
{
	float LY = m_rightThumbY;
	if (LY<0)LY = -LY;
	//check if the controller is outside a circular dead zone
	if (LY > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
	{
		//adjust magnitude relative to the end of the dead zone
		LY -= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE;

		//optionally normalize the magnitude with respect to its expected range
		//giving a magnitude value of 0.0 to 1.0
		LY = LY / (32767 - XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
	}
	else //if the controller is in the deadzone zero out the magnitude
	{
		LY = 0.0;
	}
	return m_rightThumbY < 0 ? -LY : LY;
}


float GamePad::LeftTriggerNormalized::get()
{
	float t = m_leftTrigger;
	//check if the controller is outside a circular dead zone
	if (t > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
	{
		//adjust magnitude relative to the end of the dead zone
		t -= XINPUT_GAMEPAD_TRIGGER_THRESHOLD;

		//optionally normalize the magnitude with respect to its expected range
		//giving a magnitude value of 0.0 to 1.0
		t = t / (255 - XINPUT_GAMEPAD_TRIGGER_THRESHOLD);
	}
	else //if the controller is in the deadzone zero out the magnitude
	{
		t = 0.0;
	}
	return t;
}

float GamePad::RightTriggerNormalized::get()
{
	float t = m_rightTrigger;
	//check if the controller is outside a circular dead zone
	if (t > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
	{
		//adjust magnitude relative to the end of the dead zone
		t -= XINPUT_GAMEPAD_TRIGGER_THRESHOLD;

		//optionally normalize the magnitude with respect to its expected range
		//giving a magnitude value of 0.0 to 1.0
		t = t / (255 - XINPUT_GAMEPAD_TRIGGER_THRESHOLD);
	}
	else //if the controller is in the deadzone zero out the magnitude
	{
		t = 0.0;
	}
	return t;
}