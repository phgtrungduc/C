#include <windows.h>
LRESULT CALLBACK WndProc ( IIWND. UINT, WPARAM, LPARAM );
int WINAPI WinMain (HINSTANCE hlnstance, HINSTANCE hPrevInstance, PSTR
szCmdLine, int iCmdShow)
{
static TCHAR szAppName [] = TEXT ("HelloWorld");
HWND hwnd;
MSG msg;
WNDCLASS wndclass;
wndclass.style = CS_HREDRAW|CS_VREDRAW;
wndclass.lpfnWndProc = WndProc;
wndclass.cbClsExtta = 0;
wndclass.cbWndExtra = 0;
wndclass.hlnstance = hlnstance;
wndclass.hlcon = Loadicon ( NULL, IDI_APPLICATION );
wndclass.hCursor = LoadCursor ( NULL, IDC_ARROW );
wndclass.hbrBackground =
( HBRUSH ) GetStockObject ( WHITE_BRUSH );
wndclass.lpszMenuName = NULL;
wndclass.lpszClassName = szAppName;
if ( ¡RegisterClass ( &wndclass))
{
MessageBox(NULL, TEXT (" The program requires Windows"), szAppName,
MB JCONERROR);
return 0;
}
hwnd = CreateWindow ( szAppName, // Tên l?p c?a s?
TEXT (" The Hello World Program"), // Tiêu d? c?a s?
WS_OVERLAPPEDWINDOW, //Ki?u c?a s?
CWJJSEDEFAULT, // T?a d? X
CWJJSEDEFAULT, // T?a d? y
CWJJSEDEFAULT, // Chi?u ngang
CWJJSEDEFAULT, // Chi?u d?c
NULL, // c?a s? cha
NULL, //Th?c don
hlnstance, //Ð?nh danh
NULL ); // Tham s?
ShowWindow ( hwnd, iCmdShow);
UpdateWindow ( hwnd);
while ( GetMessage ( &msg, NULL, 0, 0))
{
TranslateMessage (&msg);
DispatchMessage (& m sg);
}
return msg.wParam;
}//End WinMain
LRESULT CALLBACK WndProc (HWND hwnd, UINT msg, WPARAM wParam,
LPARAM IParam)
{
HDC hdc;
PAINTSTRU CT ps;
RECT rect;
switch ( msg)
{
case WM_CREATE:
return 0;
case WM_PAINT:
hdc = BeginPaint ( hwnd, &ps);
GetClientRect ( hwnd, &rect);
DrawText( hdc, TEXTfHello World"), -1, &rect,
DT_SINGLELINE I DT_CENTER I DT_VCENTER );
EndPaint ( hwnd, &ps);
return 0;
case WMJDESTROY:
PostQuitMessage (0);
return 0;
}//End switch
return DefWindowProc ( hwnd, msg, wParam, IParam);
}
