#include "WindowsMessageMap.h"
#include <string>
#include <sstream>
#include <iomanip>

#define REGISTER_MESSAGE(msg){msg, #msg}

WindowsMessageMap::WindowsMessageMap() : map({
	REGISTER_MESSAGE(WM_MOVE),
	REGISTER_MESSAGE(WM_CLOSE),
	REGISTER_MESSAGE(WM_LBUTTONDOWN),
	})
{}

std::string WindowsMessageMap::operator() (DWORD msg, LPARAM lp, WPARAM wp) const
{
	constexpr int firstColWidth = 25;
	const auto i = map.find(msg);
	std::ostringstream oss;

	if (i != map.end())
	{
		oss << std::left << std::setw(firstColWidth) << i->second << std::right;
	}
	else
	{
		std::ostringstream padss;
		padss << "Unknown message: 0x" << std::hex << msg;
		oss << std::left << std::setw(firstColWidth) << padss.str() << std::right;
	}

	oss << "   LP: 0x" << std::hex << std::setfill('0') << std::setw(8) << lp;
	oss << "   WP: 0x" << std::hex << std::setfill('0') << std::setw(8) << wp << std::endl;


	return oss.str();
}