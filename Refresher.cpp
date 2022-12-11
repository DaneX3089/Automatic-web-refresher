#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>
using namespace std;

// Declare the setcolor function
void setcolor(int color);

int main() {
    setcolor(FOREGROUND_GREEN);
    cout << "Click CTRL+B to enable. CTRL+X to disable";
    while (1) {
        Sleep(1);
        bool enabler = false;
        if (GetAsyncKeyState(VK_LCONTROL) && GetAsyncKeyState(0x42)) {
            enabler = true;
        }
        while (enabler == true) {
            keybd_event(VK_LCONTROL, 0, 0, 0);
            keybd_event(VK_F5, 0, 0, 0);
            Sleep(50);
            keybd_event(VK_LCONTROL, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_F5, 0, KEYEVENTF_KEYUP, 0);
            Sleep(100);
            if (GetAsyncKeyState(VK_LCONTROL) && GetAsyncKeyState(0x58)) {
                enabler = false;

            }


        }

    }

}

// Define the setcolor function
void setcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
