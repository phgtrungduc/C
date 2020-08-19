
#include <windows.h>
const char g_szClassName[] = "myWindowClass"; /* tên l?p cu?a s? */
// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam,
LPARAM lParam)
{
 switch(msg)
 {
 case WM_CLOSE:
 DestroyWindow(hwnd);
 break;
 case WM_DESTROY:
 PostQuitMessage(0);
 break;
 default:
 // dê? windows xu? lý các thông diê?p co`n la?i
 return DefWindowProc(hwnd, msg, wParam, lParam);
 }
 return 0;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
 LPSTR lpCmdLine, int nCmdShow)
{
 WNDCLASSEX wc;
 HWND hwnd;
 MSG Msg;
 //Step 1: Registering the Window Class
 wc.cbSize = sizeof(WNDCLASSEX);
 wc.style = 0;
 wc.lpfnWndProc = WndProc; /* hàm xu? lý thông diê?p cu?a s? */
 wc.cbClsExtra = 0;/* không c?n thông tin thêm cho cu?a s? */
 wc.cbWndExtra = 0;
 wc.hInstance = hInstance;
 wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
 wc.hCursor = LoadCursor(NULL, IDC_ARROW);
 wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); /* màu nen */
 /*wc.hbrBackground = GetStockObject(WHITE_BRUSH); mau nen trang */
 wc.lpszMenuName = NULL; /* không co´ hê thong thuc don */
 wc.lpszClassName = g_szClassName; /* tên lop cua so */
 wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
 /* dang ký lop cua so */
 if(!RegisterClassEx(&wc))
 {
 MessageBox(NULL, "Window Registration Failed!", "Error!",
 MB_ICONEXCLAMATION | MB_OK);
 return 0;
 }
 // Step 2: Creating the Window
 // Ta?o ra mô?t thê? nghiê?m cu?a l?p cu?a s? cho ?ng du?ng
 hwnd = CreateWindowEx(
 WS_EX_CLIENTEDGE,
 g_szClassName,
 "The title of my window",
 WS_OVERLAPPEDWINDOW,
 CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
 NULL, NULL, hInstance, NULL);
 if(hwnd == NULL)
 {
 MessageBox(NULL, "Window Creation Failed!", "Error!",
 MB_ICONEXCLAMATION | MB_OK);
 return 0;
 }
 // Hiê?n thi? cu?a s?
 ShowWindow(hwnd, nCmdShow);
 UpdateWindow(hwnd);
 // Step 3: The Message Loop
 // Step 3: Ta?o vo`ng la?p xu? lý thông diê?p
 while(GetMessage(&Msg, NULL, 0, 0) > 0)
 {
 TranslateMessage(&Msg);
 DispatchMessage(&Msg);
 }
 return Msg.wParam;
}
