#include <Windows.h>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const auto pClassName = L"MainWindow";

	//register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = nullptr;
	wc.hIconSm = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	RegisterClassEx(&wc);

	//create window instance
	HWND hWnd = CreateWindowEx(
		0,
		pClassName,
		L"MainWindow",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		0, 0,
		1366, 720,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	ShowWindow(hWnd, SW_SHOW);

	while (true);
	return 0;
}