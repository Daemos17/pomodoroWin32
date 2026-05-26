#include <windows.h>
#include "app_state.h"

static struct AppState g_state;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hwnd, msg, wParam, lParam);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    AppState_Init(&g_state, NULL);
    const char* CLASS_NAME = "PomodoroWin32";
    WNDCLASSEX wc = {0};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  

    if(!RegisterClassEx(&wc)){
        MessageBox(NULL, "Couldn`t register window in OS!", "Error", MB_ICONERROR);
        return -1;
    }


    return 0;
}
