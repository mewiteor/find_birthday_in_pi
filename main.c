/*
 * MIT License
 * 
 * Copyright (c) 2021 mewiteor
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include "pi.h"
#include<stdio.h>
#include<windows.h>
#include<CommCtrl.h>
#include<windowsx.h>

#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    LPCSTR lpClassName = "FBIPI_Class",           // 窗口类名
           lpWindowTitle = "查找生日在π小数点后的首次出现的位置";         // 窗口标题
    WNDCLASSA wc =
    {
        CS_HREDRAW | CS_VREDRAW,
        WndProc,
        0,0,hInstance,NULL,
        LoadCursor(NULL,IDC_ARROW),
        (HBRUSH)(COLOR_WINDOW+1),
        NULL,lpClassName
    };
    HWND hWnd;
    MSG msg = { 0 };
    INITCOMMONCONTROLSEX icex = {sizeof(icex), sizeof(icex)};
    enum { WIDTH = 620, HEIGHT = 79 };
    int x, y;
    int width, height;

    InitCommonControlsEx(&icex);

    RegisterClass(&wc);

    width = GetSystemMetrics(SM_CXSCREEN);
    height = GetSystemMetrics(SM_CYSCREEN);

    x = (width - WIDTH) / 2;
    y = (height - HEIGHT) / 2;

    hWnd = CreateWindowA(lpClassName, lpWindowTitle, WS_CAPTION | WS_SYSMENU, x, y, WIDTH, HEIGHT, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HFONT hFont = NULL;
    static HWND hPicker = NULL;
    static unsigned int index = 0;
    HINSTANCE hInstance;
	RECT rc;
	PAINTSTRUCT paint;
    HDC hdc;
    HFONT hOldFont;
    char buf[100];
    SYSTEMTIME st;
    LPNMDATETIMECHANGE lpChange;
	unsigned int year, month, day;
    switch (uMsg)
    {
        case WM_CREATE:
            hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
            hFont = CreateFontA(18, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Segeo UI");
            hPicker = CreateWindowA(DATETIMEPICK_CLASSA, NULL, WS_CHILD | WS_VISIBLE | DTS_LONGDATEFORMAT, 10, 10, 200, 20, hWnd, NULL, hInstance, NULL);
            SendMessageA(hPicker, WM_SETFONT, (WPARAM)hFont, 0);
            return 0;
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &paint);
            hOldFont = SelectFont(hdc, hFont);
            GetClientRect(hWnd, &rc);
            rc.left += 215;
            rc.top += 12;
            buf[0] = 0;
            DateTime_GetSystemtime(hPicker, &st);
			year = st.wYear;
			month = st.wMonth;
			day = st.wDay;
			index = 0;
			// 日期范围: 1年1月1日到9999年12月31日
			if (year >= 1 && year <= 9999 &&
				month >= 1 && month <= 12 &&
				day >= 1 && day <= days_of_month[month - 1])
			{
				// 从1年1月1日开始的日期数，每一年都按闰年366天计算
				unsigned int all_days = (year - 1) * 366 + all_days_of_month[month - 1] + day - 1;
				OutputDebugStringA("t2\n");
				// 此日期在pi小数点后的首次出现的位置
				// index 不为0则为有效位置
				index = indexes_in_pi[all_days];
			}
            sprintf_s(buf, _countof(buf), "在π小数点后的首次出现的位置为: %d", index);
            DrawTextA(hdc, buf, (int)strlen(buf), &rc, DT_LEFT | DT_TOP | DT_SINGLELINE);
            SelectFont(hdc, hOldFont);
            EndPaint(hWnd, &paint);
            return 0;
        case WM_NOTIFY:
            lpChange = (LPNMDATETIMECHANGE)lParam;
            if (lpChange->nmhdr.hwndFrom == hPicker && lpChange->nmhdr.code == DTN_DATETIMECHANGE)
            {
                InvalidateRect(hWnd, NULL, TRUE);
                return 0;
            }
            break;
        case WM_DESTROY:
            DeleteFont(hFont);
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
