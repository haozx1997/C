#include<windows.h>
#include<stdlib.h>
#include<time.h>
#define NUM 10

LRESULT CALLBACK Winproc(HWND,UINT,WPARAM,LPARAM);
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstanc,LPSTR lpCmdLine,int nShowCmd)
{
    MSG msg;
    static TCHAR szClassName[] = TEXT("::Bezier样条计算公式由法国雷诺汽车公司的工程师Pierm Bezier于六十年代提出");
    HWND hwnd;
    WNDCLASS wc;
    wc.cbClsExtra =0;
    wc.cbWndExtra =0;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hIcon = LoadIcon(NULL,IDI_APPLICATION);
    wc.hInstance = hInstance;
    wc.lpfnWndProc = Winproc;
    wc.lpszClassName = szClassName;
    wc.lpszMenuName = NULL;
    wc.style = CS_HREDRAW|CS_VREDRAW;

    if(!RegisterClass(&wc))
    {
        MessageBox(NULL,TEXT("注册失败"),TEXT("警告框"),MB_ICONERROR);
        return 0;
    }
    hwnd = CreateWindow(szClassName,szClassName,
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT,CW_USEDEFAULT,
                        CW_USEDEFAULT,CW_USEDEFAULT,
                        NULL,NULL,hInstance,NULL);

    ShowWindow(hwnd,SW_SHOWMAXIMIZED);
    UpdateWindow(hwnd);

    while(GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK Winproc(HWND hwnd,UINT message, WPARAM wparam,LPARAM lparam)
{
  HDC hdc;
  static POINT pt[NUM];
  TEXTMETRIC tm;
  static int cxClient,cyClient;
  HPEN hpen;
  int i,j,k,n,t;

  switch(message)
  {
  case WM_CREATE:
      static int cxchar;
      hdc = GetDC(hwnd);
      GetTextMetrics(hdc,&tm);
      cxchar = tm.tmAveCharWidth;
      ReleaseDC(hwnd,hdc);

  case WM_SIZE:
       cxClient = LOWORD(lparam);
      cyClient = HIWORD(lparam);
      return 0;
  case WM_PAINT:
       hdc = GetDC(hwnd);
       srand(time(0));

       Rectangle(hdc,0,0,cxClient,cyClient);
      for(i=0; i<500; i++)
          {
            SelectObject(hdc,GetStockObject(WHITE_PEN));
            PolyBezier(hdc,pt,NUM);
            for(j=0; j<NUM; j++)
            {
                pt[j].x = rand()%cxClient;
                pt[j].y = rand()%cyClient;
            }
            hpen = CreatePen(PS_INSIDEFRAME,3,RGB(rand()%256,rand()%256,rand()%256));
             DeleteObject(SelectObject(hdc,hpen));
            PolyBezier(hdc,pt,NUM);
            for(k=0; k<50000000;k++);
          }
      for(i=0; i<100;i++)
      {
        Ellipse(hdc,rand()%cxClient,rand()%cyClient,rand()%cxClient,rand()%cyClient);

        Pie(hdc,j=rand()%cxClient,k=rand()%cyClient,n=rand()%cxClient,t=rand()%cyClient,rand()%cxClient,rand()%cyClient,rand()%cxClient,rand()%cyClient) ; 

      }
       if((n=(n+j)/2)>cxchar*20) n=cxchar*20;  
        SetTextColor(hdc,RGB(rand()%256,rand()%256,rand()%256));
        TextOut(hdc,n/2,(t+k)/2,TEXT("瑾以此向Pierm Bezier致敬!"),lstrlen(TEXT("瑾以此向Pierm Bezier致敬!")));
        ReleaseDC(hwnd,hdc);
          DeleteObject(hpen);
          ValidateRect(hwnd,NULL);
   return 0;

  case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
  }
  return DefWindowProc(hwnd,message,wparam,lparam);
}
 
