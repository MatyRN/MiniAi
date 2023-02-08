#pragma once
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
LRESULT CALLBACK WindowProc(HWND hWnd,UINT uMsg, WPARAM wParam,LPARAM lParam);

class WINDOW{
public:
    WINDOW();
    WINDOW(const WINDOW&) = delete;
    WINDOW& operator =(const WINDOW&) = delete;
    ~WINDOW();
    void UPDATE();
    bool ProcessMessages();
    //TEXTAI + NEWMESSANGE
    //NOTE FOR ME: No igualar Este string a si mismo, ya que el valor entrara en bucle.
private:

    HINSTANCE m_hinstance;
    HWND m_hWnd;

};
