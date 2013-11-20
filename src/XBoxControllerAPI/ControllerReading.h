// PacketNumber
// float LeftTrigger
// float RightTrigger
// Point LeftThumb
// Point RightThumb
// Buttons :
//      A B X Y RT LT R D L U UL DR DL UR
// 
// Capabilities
//    byte Type
//    byte Subtype
//    Flags
//        Wireless
//        Voice Support

#pragma once
namespace XBoxControllerAPI
{
	[Platform::Metadata::Flags]
	public enum class GamePadButtons : unsigned int
	{
		PadUp            = 0x0001,
		PadDown          = 0x0002,
		PadLeft          = 0x0004,
		PadRight         = 0x0008,
		Start            = 0x0010,
		Back             = 0x0020,
		LeftThumb        = 0x0040,
		RightThumb       = 0x0080,
		LeftShoulder     = 0x0100,
		RightShoulder    = 0x0200,
		A                = 0x1000,
		B                = 0x2000,
		X                = 0x4000,
		Y                = 0x8000
	};
	public ref class GamePad sealed
	{
	internal:
		GamePad(GamePadButtons buttons, byte leftTrigger, byte rightTrigger,
			short ltx, short lty, short rtx, short rty);
	public:
		property byte LeftTrigger { byte get() { return m_leftTrigger; } }
		property byte RightTrigger { byte get() { return m_rightTrigger; } }
		property short LeftThumbX { short get() { return m_leftThumbX; } }
		property short LeftThumbY { short get() { return m_leftThumbY; } }
		property short RightThumbX { short get() { return m_rightThumbX; } }
		property short RightThumbY { short get() { return m_rightThumbY; } }
		property GamePadButtons Buttons { GamePadButtons get() { return m_buttons; } }
		
	private:
		byte m_leftTrigger;
		byte m_rightTrigger;
		short m_leftThumbX;
		short m_leftThumbY;
		short m_rightThumbX;
		short m_rightThumbY;
		GamePadButtons m_buttons;
	};

	public ref class ControllerReading sealed
	{
	internal:
		ControllerReading(XBoxControllerAPI::GamePad^ pad);
	public:
		property XBoxControllerAPI::GamePad^ GamePad { XBoxControllerAPI::GamePad^ get() { return m_gamePad; } }
	private:
		XBoxControllerAPI::GamePad^ m_gamePad;
	};
}