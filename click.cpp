#include <iostream>
#include <windows.h>  

using namespace std;
void click(int x, int y) {
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, x, y, 0, 0);
}

int main()
{
	POINT c;
	GetCursorPos(&c);
	int x = c.x;
	int y = c.y;
	click(x, y);
}
