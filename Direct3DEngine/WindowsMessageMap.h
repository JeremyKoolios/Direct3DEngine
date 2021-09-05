#pragma once
#include <Windows.h>
#include <unordered_map>

class WindowsMessageMap
{
public:
	WindowsMessageMap();
	std::string operator() (DWORD msg, LPARAM lp, WPARAM wp) const; //overloads the () operator
private:
	std::unordered_map<DWORD, std::string> map;
};