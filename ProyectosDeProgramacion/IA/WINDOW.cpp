#include "WINDOW.h"
#define LOWORD
///FALTA REFRESH DE LA TEXTBOX Y LA AI (OBLIGATORIO)///
///Opcional:Agregar imagenes.
std::string TextAI="WIN";
std::string TextUser;
//////////////////////////
char textSaved[20];
HWND hWndUserTalk;
void AIResponces();
//////////////////////////
LPSTR TextAIC;
LPSTR TextUSERC;
LPSTR TextTitleMessage="AI Answer";
///IMAGES PREFAPS///

///=======================/////
LRESULT CALLBACK WindowProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam){
 switch(uMsg){
case WM_CREATE:
    break;
case WM_CLOSE:
        DestroyWindow(hWnd);
    break;
case WM_DESTROY:
        PostQuitMessage(0);
    break;
case WM_COMMAND:{
    if(LOWORD(wParam) ==1){
        int gwstat=0;
        gwstat= GetWindowText(hWndUserTalk,&textSaved[0],20);
        TextUser = textSaved;
       AIResponces();
    }
}
    return 0;
    }
    return DefWindowProc(hWnd,uMsg,wParam,lParam);
}
void WINDOW::UPDATE(){
    TextAIC=TextUSERC;
}
WINDOW::WINDOW(): m_hinstance(GetModuleHandle(nullptr)){
////////////////////////////////////////////
    const char* CLASS_NAME = "Ventanita";
///=====WINDOW PRELOAD======///
    WNDCLASS wndclass = {};
    wndclass.lpszClassName = CLASS_NAME;
    wndclass.hInstance = m_hinstance;
    wndclass.hIcon = LoadIcon(NULL,IDI_WINLOGO);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpfnWndProc = WindowProc;
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW);

    RegisterClass(&wndclass);
    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
//WIDTH AND HEIGHT OF THE WINDOW//
    int width = 350;
    int height = 50;
///==WINDOW MEASUREMENTS===========////
    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
///====================================///
    AdjustWindowRect(&rect, style, false);
///WINDOW PROPERTIES
    m_hWnd = CreateWindowEx(0,CLASS_NAME,"AIH :Artificial Inteligence Happy",style,rect.left,rect.top,
                            rect.right - rect.left,rect.bottom - rect.top,
                            NULL,NULL,m_hinstance,NULL);
    ShowWindow(m_hWnd,SW_SHOW);
///CREATE ITEMS WINDOWS
HWND hWndGIFAI = CreateWindow(
        ("Static"),
        ("Artificial Inteligence Happy"),
        WS_CHILD | WS_VISIBLE | NULL,
        110,
        1,
        150,
        20,
        m_hWnd,
        NULL,
        NULL,
        NULL);
HWND hWndGf = CreateWindowW(
        L"Static",
        NULL,
        WS_VISIBLE| WS_CHILD | SS_BITMAP,
        0,
        0,
        60,
        60,
        m_hWnd,
        NULL,
        NULL,
        NULL);
hWndUserTalk = CreateWindow(
        ("Edit"),
        (""),
        WS_CHILD | WS_VISIBLE | WS_BORDER,
        25,
        25,
        245,
        20,
        m_hWnd,
        NULL,
        NULL,
        NULL);
HWND hWndUserButtom = CreateWindow(
        ("BUTTON"),
        ("SEND"),
        WS_CHILD | WS_VISIBLE | WS_BORDER,
        270,
        25,
        50,
        20,
        m_hWnd,
        (HMENU) 1,
        NULL,
        NULL);
}

////DestroyWindow//////
WINDOW::~WINDOW(){
////////////////////////////////////////////
  const char* CLASS_NAME = "Ventanita";
  UnregisterClass(CLASS_NAME, m_hinstance);
////////////////////////////////////////////
}
///////////////
bool WINDOW::ProcessMessages(){
    MSG msg ={};
//////////////////////////////////////////////////
   while(PeekMessage(&msg,nullptr,0u,0u,PM_REMOVE)){
        if(msg.message == WM_QUIT){
            return false;
        }
///////////////////////////////
TranslateMessage(&msg);
DispatchMessage(&msg);
///////////////////////////
    }
    return true;
}
void AIResponces(){
    TextUSERC = const_cast<char *>(TextUser.c_str());
    TextAIC = const_cast<char *>(TextAI.c_str());
         if(strcmp(TextUSERC,"How are you?")==0){
            TextAIC="GOOD,happy to be alive!:D";
            MessageBox(hWndUserTalk,TextAIC,TextTitleMessage,MB_OK);
        }
        if(strcmp(TextUSERC,"Do you want to be my friend?")==0){
            TextAIC="Of course,nothing would make me happier :D";
            MessageBox(hWndUserTalk,TextAIC,TextTitleMessage,MB_OK);

        }
        if(strcmp(TextUSERC,"How you?")==0){
            TextAIC="SEX...NOW";
            MessageBox(hWndUserTalk,TextAIC,TextTitleMessage,MB_OK);
        }
}
///LOAD IMAGE///
