//
//sasha pacholkov email:sasha4685847@mail.ru
//2004 all right reserved
#include <windows.h>  
#include <windowsx.h> 
#include "Enumwnd.h" 
//#include "DlgDirLt.h" 

#include <stdio.h>
#define TIMER_ID	1
#define TIMER_RATE	100//

#define FRAMEX 15
#define FRAMEY 16
#define LEFT 390
#define TOP 02
#define RIGTH LEFT+FRAMEX
#define BOTTOM TOP+FRAMEY
#define MAX 60000//200*221
#define MAX_LEN_STR 40
#define MAX_LEN_MAS 100
#include "struct.h" //int Max=80; 
BOOL	bActive;
 char alfavit_rus[34]; 
 char alfavit_chin[34]; 
static char szText1[MAX_LEN_STR+20 ];
static char szText2[MAX_LEN_STR ];
static char szText3[MAX_LEN_STR ];
static char szTextE[MAX_LEN_STR+20 ];
static char szTextN[8];
static char szText[MAX_LEN_STR+20 ];
static char szOut[MAX_LEN_STR+4 ];
static char szText2p[MAX_LEN_STR];
static HWND hListBox;
static HWND hListBox2;
static HWND hListBox3;
static HWND hListBox2s;
static HWND hListBox2z;
static HWND hEdit1  = NULL;
static HWND hEdit2  = NULL;
static HWND hEdit3  = NULL;
static HWND hEdit1e  = NULL;
static HWND hEdit2t  = NULL;
 static HWND hEdit2et  = NULL;
static HWND hEdit2e  = NULL;
static HWND hEdit2ep= NULL;

static HWND hEdit2ex  = NULL;static HWND hEdit2ey  = NULL;
static HWND hEdit2ex2  = NULL;static HWND hEdit2ey2  = NULL;
static HWND hEdit2ex3  = NULL;static HWND hEdit2ey3  = NULL;
static HWND hEdit2ex4  = NULL;static HWND hEdit2ey4  = NULL;
static HWND hEdit3e  = NULL;
 //HWND hEdit2len = NULL;
//char* pFilename={"china.bmp"};//
int up,down,ups,downs;
int auto_key_sw=1,help_on=1;
int save=0,nSel2,nSel2X=-1,nSel2s,nSel2Xs=-1;
int edit=0;
int x=1,y=1,n=1,line=200,ie=0;

DWORD max_struct=0;
int mas[MAX_LEN_MAS];
int maszi[20];
int maszie[20];
int indexmaszi;
int indexmaszie;
int index_mas;
int zi[4]={0,0,0,0};
int numerzi;
char* pFilename={"china.bmp"};//
char* pFilename2={"enrus.dic"};//
char* pFilename3={"main.dic"};//
int y1=3792-51+17;
int x1=49-16;
int dx=16;
int dy=17;
int lenstr=0;
	BYTE* pBmp;
	BYTE* pFile;
	DWORD dwBmpSize,dwFileSize;
	DWORD dwFileLength;
	DWORD nBytesRead,dwWritten;
	BITMAPINFO* pBmpInfo;
	BYTE*		pPixels;
	HDC hdc;
	HANDLE	hFile;
	HANDLE	hFile2;
	HANDLE	hFile3;
	static	int numer_zi[4]={0,0,0,0};
int		numer_i=0;//numer_zi=(y-1)*200+x,index=2;

void D_OnActivate(HWND hWnd, UINT state, HWND hwndActDeact, BOOL fMinimized);
void D_OnKey(HWND hWnd, UINT vk, BOOL fDown, int cRepeat, UINT flags);
void D_OnTimer(HWND hwnd, UINT id);

//static char szOut[MAX_LEN_STR ];
//static char szText3[MAX_LEN_STR ];
HWND hFocus;
HWND hFocusX;
 //	struct MyBase Base[80];//, *pMyBase=&MyBase[Max];
void D_OnIdle(HWND hwnd);
			  
struct Base MyBase[MAX], *pBase=&MyBase[0];
//struct Base MyBase[80], *pMyBase=&MyBase[Max];
//struct Rus MyRus[33][10], *pRus=&MyRus[0][0];
//struct Chin_pin MyChin_pin[33][10], *pChin_pin=&MyChin_pin[0][0];
//struct Eng MyEng[33][10], *pEng=&MyEng[0][0];
char* pFileBase="base.dic";

HINSTANCE hInst;   // current instance
LPCTSTR lpszAppName  = "MyApp";
LPCTSTR lpszTitle    = "Dictonary"; 

HWND       hWnd; 
int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
                      LPTSTR lpCmdLine, int nCmdShow)
{
   MSG        msg;
   
   WNDCLASSEX wc;

   // Register the main application window class.
   //............................................
   wc.style         = CS_HREDRAW | CS_VREDRAW;
   wc.lpfnWndProc   = (WNDPROC)WndProc;       
   wc.cbClsExtra    = 0;                      
   wc.cbWndExtra    = 0;                      
   wc.hInstance     = hInstance;              
   wc.hIcon         = LoadIcon( hInstance, lpszAppName ); 
   wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
   wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);//GCL_HBRBACKGROUND, 
                                        (LONG)GetStockObject( LTGRAY_BRUSH );
   wc.lpszMenuName  = lpszAppName;              
   wc.lpszClassName = lpszAppName;              
   wc.cbSize        = sizeof(WNDCLASSEX);
   wc.hIconSm       = LoadImage( hInstance, lpszAppName,  
                                 IMAGE_ICON, 16, 16,
                                 LR_DEFAULTCOLOR );

   if ( !RegisterClassEx( &wc ) )
      return( FALSE );

   hInst = hInstance; 

   // Create the main application window.
   //....................................
   hWnd = CreateWindow( lpszAppName, 
                        lpszTitle,    
                        WS_OVERLAPPEDWINDOW, 
                        200, 400, 
                        690,330,  
                        NULL,              
                        NULL,              
                        hInstance,         
                        NULL               
                      );

   if ( !hWnd ) 
      return( FALSE );

   ShowWindow( hWnd, nCmdShow ); 
   UpdateWindow( hWnd );         

   // while( GetMessage( &msg, NULL, 0, 0) )   
   //{
   // TranslateMessage( &msg ); 
   //   DispatchMessage( &msg );  
   //}
   	while (TRUE)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			if (msg.message==WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
   
		else
			if (bActive)
				D_OnIdle(hWnd); //delaem na taimere
	}

   return( msg.wParam ); 
}

void ErrorHandle(HWND hWnd, LPCTSTR szError)
{
	char szErrorMessage[255];	
	//ShowWindow(hwnd, SW_HIDE);
	wsprintf(szErrorMessage, "Ошибка в %s", szError);
	MessageBox(hWnd, szErrorMessage, lpszAppName, MB_OK);
	//MessageBox(hwnd, szError, lpszAppName, MB_OK);
	//DestroyWindow(hwnd);
}

void load(void)
{
FILE *fp;
//HWND       hWnd;
	if((fp=fopen(pFileBase,"rb"))==NULL)
		ErrorHandle( hWnd, "open_file");
//	if(fread(&Max,4,1,fp)!=1)
//		ErrorHandle(hWnd, "read_Size");
//	if(Max>80)ErrorHandle(hWnd,"Max>80");
	//MaxX=MaxY=MaxQ*Q_WIDTH;	
	//for(int m=0;m<Max;m++)
//	if(fread(pBase,sizeof(MyBase[80]),80,fp)!=unsigned int(Max))
//		ErrorHandle(hWnd, "read_file");
//	if((fclose(fp))!=NULL)
//		ErrorHandle(hWnd, "close_file");
}

LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{

	int temp;//int temp;
	static RECT rect;
	int i,j,k,t; 
	int len=0;

   switch( uMsg )
   {
     
   case WM_CREATE: 

	 //SetTimer(hWnd,TIMER_ID,TIMER_RATE,NULL);

	i=0;
	//Открытие файла с графическими данными
	//HANDLE
		hFile=CreateFile(pFilename, GENERIC_READ,
			FILE_SHARE_READ, NULL,OPEN_EXISTING, 0, NULL);
	if (hFile==INVALID_HANDLE_VALUE)
		ErrorHandle(hWnd, "error open file");
	//Получение размера файла и размера данных
	dwFileLength=GetFileSize (hFile, NULL) ;
	dwBmpSize=dwFileLength-sizeof(BITMAPFILEHEADER);
	
	//Выделение памяти под данные
	pBmp=	(BYTE*) malloc(dwBmpSize);
	SetFilePointer(hFile, sizeof(BITMAPFILEHEADER), NULL, FILE_BEGIN);
	//SetFilePointer(hFile,45000+ sizeof(BITMAPFILEHEADER), NULL, FILE_BEGIN);

	//Чтение файла с данными
	ReadFile(hFile, (LPVOID)pBmp, dwBmpSize, &nBytesRead, NULL);
	CloseHandle(hFile);

	pBmpInfo=(BITMAPINFO*)pBmp;
	//pPixels=pBmp+sizeof(BITMAPINFOHEADER)+sizeof(RGBQUAD)*256;
	pPixels=pBmp+sizeof(BITMAPINFOHEADER)+sizeof(RGBQUAD)*16;
//---------------

	hFile3=CreateFile(pFilename3, GENERIC_READ,
			FILE_SHARE_READ, NULL,OPEN_EXISTING, 0, NULL);
	if (hFile3==INVALID_HANDLE_VALUE)
		ErrorHandle(hWnd, "error open file3");
	dwFileLength=GetFileSize (hFile3, NULL) ;	
	ReadFile(hFile3, (LPVOID)&max_struct,100, &nBytesRead, NULL);
	 ReadFile(hFile3, (LPVOID)pBase, dwFileLength-100
	  , &nBytesRead, NULL);
	CloseHandle(hFile3);
	numer_i=max_struct;
			//------------------------------------
			numer_zi[0]=0;
			numer_zi[1]=0;
			numer_zi[2]=0;
			numer_zi[3]=0;
				zi[0]=0;
				zi[1]=0;
				zi[2]=0;
				zi[3]=0;
				numerzi=-1;
				lenstr=0;
			//---------------------------
			  SetClassLong( hWnd, GCL_HBRBACKGROUND, 
                                  (LONG)GetStockObject( LTGRAY_BRUSH ) );

               hListBox3 = CreateWindow("LISTBOX", "",
                                       WS_CHILD | WS_BORDER |
                                       WS_VISIBLE | LBS_STANDARD,
                                       0, 25, 160, 200,
                                       hWnd, (HMENU) 101,  
                                       hInst, NULL );
			  
               hListBox2 = CreateWindow("LISTBOX", "",
                                       WS_CHILD | WS_BORDER |
                                       WS_VISIBLE| LBS_STANDARD,
                                       215, 25, 160, 200,
                                       hWnd, (HMENU) 101,  
                                       hInst, NULL );

			   hListBox2s = CreateWindow("LISTBOX", "",//LBS_NODATA 
                                       WS_CHILD |//LBS_NOTIFY|LBS_MULTICOLUMN |// WS_BORDER |
                                       WS_VISIBLE,// | LBS_STANDARD,
                                       170, 25, 30, 200,
                                       hWnd, (HMENU) 101,  
                                       hInst, NULL );

			   /* hListBox2z = CreateWindow("LISTBOX", "",
                                       WS_CHILD |//LBS_NOTIFY|LBS_MULTICOLUMN |// WS_BORDER |
                                       WS_VISIBLE,// | LBS_STANDARD,
                                       375, 25, 15, 200,
                                       hWnd, (HMENU) 101,  
                                       hInst, NULL );
				*/
			   hListBox = CreateWindow("LISTBOX", "",
                                       WS_CHILD | WS_BORDER |//LBS_SORT|
                                       WS_VISIBLE | LBS_STANDARD,
                                       460, 25, 200, 200,
                                       hWnd, (HMENU) 101,  
                                       hInst, NULL );


			    hEdit3 = CreateWindow("EDIT", "",
                                          WS_CHILD | WS_BORDER |
                                          WS_VISIBLE |ES_LEFT,
                                          0, 0, 160, 20,
                                          hWnd, (HMENU) 101,  
                                          hInst, NULL );
  
                  hEdit2 = CreateWindow("EDIT", "", 
                                         WS_CHILD | WS_BORDER |
                                         WS_VISIBLE | ES_LEFT,
                                         215, 0, 160, 20,
                                         hWnd, (HMENU) 102,  
                                         hInst, NULL );

				  hEdit1 = CreateWindow("EDIT", "",
                                          WS_CHILD | WS_BORDER |
                                          WS_VISIBLE |ES_LEFT,
                                          460, 0, 210, 20,
                                          hWnd, (HMENU) 101,  
                                          hInst, NULL );

				   hEdit1e = CreateWindow("EDIT", "",
                                          WS_CHILD | WS_BORDER |
                                          WS_VISIBLE |ES_LEFT,
                                          460, 225, 220, 20,
                                          hWnd, (HMENU) 101,  
                                          hInst, NULL );

				   hEdit2t = CreateWindow("EDIT", "", 
                                         WS_CHILD | WS_BORDER |
                                         WS_VISIBLE | ES_LEFT,
                                         170, 0, 40, 20,
                                         hWnd, (HMENU) 102,  
                                         hInst, NULL );

				   hEdit2e = CreateWindow("EDIT", "", 
                                         WS_CHILD | WS_BORDER |
                                         WS_VISIBLE | ES_LEFT,
                                         170, 225, 160, 20,
                                         hWnd, (HMENU) 102,  
                                         hInst, NULL );

					 hEdit2et = CreateWindow("EDIT", "", 
                                         WS_CHILD | WS_BORDER |
                                         WS_VISIBLE | ES_LEFT,
                                         330, 225, 40, 20,
                                         hWnd, (HMENU) 102,  
                                         hInst, NULL );
				 
				   hEdit2ep = CreateWindow("EDIT", "", 
                                         WS_CHILD | WS_BORDER |
                                         WS_VISIBLE | ES_LEFT,
                                         332, 245, 80, 20,
                                         hWnd, (HMENU) 102,  
                                         hInst, NULL );

				    hEdit3e = CreateWindow("EDIT", "",
                                          WS_CHILD | WS_BORDER |
                                          WS_VISIBLE |ES_LEFT,
                                          0, 225, 160, 20,
                                          hWnd, (HMENU) 101,  
                                          hInst, NULL );
  
				   hEdit2ex = CreateWindow("EDIT", "0", 
                                         WS_CHILD | WS_BORDER |
                                         WS_VISIBLE | ES_LEFT,
                                         170, 265, 40, 20,
                                         hWnd, (HMENU) 102,  
                                         hInst, NULL );

					hEdit2ey = CreateWindow("EDIT", "0", 
                                         WS_CHILD | WS_BORDER |
                                         WS_VISIBLE | ES_LEFT,
                                         170, 245, 40, 20,
                                         hWnd, (HMENU) 102,  
                                         hInst, NULL );
				  
				  hEdit2ex2 = CreateWindow("EDIT", "0", 
                                         WS_CHILD | WS_BORDER |
                                         WS_VISIBLE | ES_LEFT,
                                         210, 265, 40, 20,
                                         hWnd, (HMENU) 102,  
                                         hInst, NULL );

					hEdit2ey2 = CreateWindow("EDIT", "0", 
                                         WS_CHILD | WS_BORDER |
                                         WS_VISIBLE | ES_LEFT,
                                         210, 245, 40, 20,
                                         hWnd, (HMENU) 102,  
                                         hInst, NULL );

				  hEdit2ex3 = CreateWindow("EDIT", "0", 
                                         WS_CHILD | WS_BORDER |
                                         WS_VISIBLE | ES_LEFT,
                                         250, 265, 40, 20,
                                         hWnd, (HMENU) 102,  
                                         hInst, NULL );

					hEdit2ey3 = CreateWindow("EDIT", "0", 
                                         WS_CHILD | WS_BORDER |
                                         WS_VISIBLE | ES_LEFT,
                                         250, 245, 40, 20,
                                         hWnd, (HMENU) 102,  
                                         hInst, NULL );

					hEdit2ex4 = CreateWindow("EDIT", "0", 
                                         WS_CHILD | WS_BORDER |
                                         WS_VISIBLE | ES_LEFT,
                                         290, 265, 40, 20,
                                         hWnd, (HMENU) 102,  
                                         hInst, NULL );

					hEdit2ey4 = CreateWindow("EDIT", "0", 
                                         WS_CHILD | WS_BORDER |
                                         WS_VISIBLE | ES_LEFT,
                                         290, 245, 40, 20,
                                         hWnd, (HMENU) 102,  
                                         hInst, NULL );

/*					hEdit2len_zi = CreateWindow("EDIT", "", 
                                         WS_CHILD | WS_BORDER |
                                         WS_VISIBLE | ES_LEFT,
                                         330, 265, 40, 20,
                                         hWnd, (HMENU) 102,  
                                         hInst, NULL );
				 */	
						for(i=1;i<=221;i++)
							{
							wsprintf( szOut, "%d", i);
							SendMessage( (HWND)(HANDLE)hListBox2s , LB_INSERTSTRING, (WPARAM)-1,
									(LPARAM)(LPTSTR)szOut);
							}

						SendMessage( hListBox2s, LB_SETSEL, 0, 0 );

							  i=0;
									alfavit_rus[i]='а'; i++;
									alfavit_rus[i]='б'; i++;
									alfavit_rus[i]='в'; i++;
									alfavit_rus[i]='г'; i++;
									alfavit_rus[i]='д'; i++;
									alfavit_rus[i]='е'; i++;
									alfavit_rus[i]='ё'; i++;
									alfavit_rus[i]='ж'; i++;
									alfavit_rus[i]='з'; i++;
									alfavit_rus[i]='и'; i++;
									alfavit_rus[i]='й'; i++;
									alfavit_rus[i]='к'; i++; 
									alfavit_rus[i]='л'; i++;
									alfavit_rus[i]='м'; i++;
									alfavit_rus[i]='н'; i++;
									alfavit_rus[i]='о'; i++;
									alfavit_rus[i]='п'; i++;
									alfavit_rus[i]='р'; i++;
									alfavit_rus[i]='с'; i++;
									alfavit_rus[i]='т'; i++;
									alfavit_rus[i]='у'; i++;
									alfavit_rus[i]='ф'; i++;
									alfavit_rus[i]='х'; i++;
									alfavit_rus[i]='ц'; i++;
									alfavit_rus[i]='ч'; i++;
									alfavit_rus[i]='ш'; i++;
									alfavit_rus[i]='щ'; i++;
									alfavit_rus[i]='ъ'; i++;
									alfavit_rus[i]='ы'; i++;
									alfavit_rus[i]='ь'; i++;
									alfavit_rus[i]='э'; i++;
									alfavit_rus[i]='ю'; i++;
									alfavit_rus[i]='я'; i++;
									i=0;
									alfavit_chin[i]='a'; i++;
									alfavit_chin[i]='b'; i++;
									alfavit_chin[i]='c'; i++;
									alfavit_chin[i]='d'; i++;
									alfavit_chin[i]='e'; i++;
									alfavit_chin[i]='f'; i++;
									alfavit_chin[i]='g'; i++;
									alfavit_chin[i]='h'; i++;
									alfavit_chin[i]='i'; i++;
									alfavit_chin[i]='j'; i++;
									alfavit_chin[i]='k'; i++;
									alfavit_chin[i]='l'; i++;
									alfavit_chin[i]='m'; i++;
									alfavit_chin[i]='n'; i++;
									alfavit_chin[i]='o'; i++;
									alfavit_chin[i]='p'; i++;
									alfavit_chin[i]='q'; i++;
									alfavit_chin[i]='r'; i++;
									alfavit_chin[i]='s'; i++;
									alfavit_chin[i]='t'; i++;
									alfavit_chin[i]='u'; i++;
									alfavit_chin[i]='v'; i++;
									alfavit_chin[i]='w'; i++;
									alfavit_chin[i]='x'; i++;
									alfavit_chin[i]='y'; i++;
									alfavit_chin[i]='z'; i++;		
			
						break;

			   
		  case WM_COMMAND :
				  switch( LOWORD( wParam ) )
				  {	//HANDLE_MSG(hWnd,WM_KEYDOWN,D_OnKey);
		
				case IDM_FIND:
				  
				  		indexmaszie=0;
						index_mas=0;
						indexmaszi=0;
						numer_zi[0]=0;	
						numer_zi[1]=0;
						numer_zi[2]=0;
						numer_zi[3]=0;
						nSel2X=-1;
						nSel2=0;
						if(nSel2X==-1)
						{up=0;down=12;}
						
						SendMessage((hListBox2), LB_RESETCONTENT, 0, 0 );					
						SendMessage((hListBox3), LB_RESETCONTENT, 0, 0 );
						SendMessage((hListBox), LB_RESETCONTENT, 0, 0 );
					
				
						for(i=1;i<=221;i++)
						{
							wsprintf( szOut, "%d", i);
							SendMessage( (HWND)(HANDLE)hListBox2s , LB_INSERTSTRING, (WPARAM)-1,
									(LPARAM)(LPTSTR)szOut);
						}			
						
					
					InvalidateRect( hWnd, NULL, TRUE );
					 break;

			  case IDM_CHKITEM :
                      { 
                         HMENU hMenu  = GetMenu( hWnd );
                         UINT  uState = GetMenuState( hMenu,
                                                      IDM_CHKITEM,
                                                      MF_BYCOMMAND );
                         if ( uState & MFS_CHECKED )
						 {
							 CheckMenuItem( hMenu, IDM_CHKITEM, 
                                           MF_BYCOMMAND | MFS_UNCHECKED );
							auto_key_sw=0;
						 }
                         else
						 {
							 CheckMenuItem( hMenu, IDM_CHKITEM,
                                         MF_BYCOMMAND | MFS_CHECKED );
							auto_key_sw=1;
						 }
					 }
					  InvalidateRect( hWnd, NULL, TRUE );
                      break;

				case IDM_HELP :
                      { 
						  
                         HMENU hMenu  = GetMenu( hWnd );
                         UINT  uState = GetMenuState( hMenu,
                                                      IDM_HELP,
                                                      MF_BYCOMMAND );

                         if ( uState & MFS_CHECKED )
						 {
							 CheckMenuItem( hMenu, IDM_HELP, 
                                           MF_BYCOMMAND | MFS_UNCHECKED );
						help_on=0;
						 }
                         else
						 {
							 CheckMenuItem( hMenu, IDM_HELP,
                                         MF_BYCOMMAND | MFS_CHECKED );
						help_on=1;
						 }
					 }
					  InvalidateRect( hWnd, NULL, TRUE );

                      break;

				case IDM_SAVESTRING1:
					
					numerzi=-1;
					GetWindowText(hEdit1e, szTextE, MAX_LEN_STR-1 );
						i=strlen(szTextE);
						if(i!=0)
						strcpy(MyBase[numer_i].name_rus,szTextE);
						
					GetWindowText(hEdit2e, szTextE, MAX_LEN_STR-1 );
						i=strlen(szTextE);
						if(i!=0)
						{	for(j=MAX_LEN_STR-1;j>=0;j--)
							if(szTextE[j]==49||szTextE[j]==50||szTextE[j]==51||szTextE[j]==52)
							MyBase[numer_i].tones=0;t=1;
							for(j=MAX_LEN_STR-1;j>=0;j--)
							for(k=48;k<58;k++)
							if(szTextE[j]==k)
							{
								szTextE[j]=0;
								MyBase[numer_i].tones+=(k-48)*t;
								t=t*10;	
							}	
							strcpy(MyBase[numer_i].name_chinese,szTextE);

						}
							GetWindowText(hEdit2et, szTextE, MAX_LEN_STR-1 );
						i=strlen(szTextE);
						if(i!=0)
						{	//for(j=MAX_LEN_STR-1;j>=0;j--)
							//if(szTextE[j]==49||szTextE[j]==50||szTextE[j]==51||szTextE[j]==52)
							MyBase[numer_i].tones=0;t=1;
							for(j=MAX_LEN_STR-1;j>=0;j--)
							for(k=48;k<58;k++)
							if(szTextE[j]==k)
							{
								szTextE[j]=0;
								MyBase[numer_i].tones+=(k-48)*t;
								t=t*10;	
							}	
						}



					GetWindowText(hEdit3e, szTextE, MAX_LEN_STR-1 );
						i=strlen(szTextE);
						if(i!=0)
						strcpy(MyBase[numer_i].name_english,szTextE);

					x=0;y=0;
					GetWindowText(hEdit2ex, szOut, 4 );
						i=strlen(szOut);
						if(i==3)x=(szOut[0]-48)*100+(szOut[1]-48)*10+szOut[2]-48;
						if(i==2)x=(szOut[0]-48)*10+szOut[1]-48;
						if(i==1)x=szOut[0]-48;
						if(i==0)x=0;
					GetWindowText(hEdit2ey, szOut, 4 );
						i=strlen(szOut);
						if(i==3)y=(szOut[0]-48)*100+(szOut[1]-48)*10+szOut[2]-48;
						if(i==2)y=(szOut[0]-48)*10+szOut[1]-48;
						if(i==1)y=szOut[0]-48;
				
					if(y==0&&x==0)
						MyBase[numer_i].index_zi[0]=0;
					else
						MyBase[numer_i].index_zi[0]=(y-1)*line+x;

					x=0;y=0;
					GetWindowText(hEdit2ex2, szOut, 4 );
					i=strlen(szOut);
						if(i==3)x=(szOut[0]-48)*100+(szOut[1]-48)*10+szOut[2]-48;
						if(i==2)x=(szOut[0]-48)*10+szOut[1]-48;
						if(i==1)x=szOut[0]-48;
						if(i==0)x=0;
					GetWindowText(hEdit2ey2, szOut, 4 );
						i=strlen(szOut);
						if(i==3)y=(szOut[0]-48)*100+(szOut[1]-48)*10+szOut[2]-48;
						if(i==2)y=(szOut[0]-48)*10+szOut[1]-48;
						if(i==1)y=szOut[0]-48;
				
					if(y==0&&x==0)
					MyBase[numer_i].index_zi[1]=0;
					else
					MyBase[numer_i].index_zi[1]=(y-1)*line+x;

					x=0;y=0;
					GetWindowText(hEdit2ex3, szOut, 4 );
						i=strlen(szOut);
						if(i==3)x=(szOut[0]-48)*100+(szOut[1]-48)*10+szOut[2]-48;
						if(i==2)x=(szOut[0]-48)*10+szOut[1]-48;
						if(i==1)x=szOut[0]-48;
						if(i==0)x=0;
					GetWindowText(hEdit2ey3, szOut, 4 );
						i=strlen(szOut);
						if(i==3)y=(szOut[0]-48)*100+(szOut[1]-48)*10+szOut[2]-48;
						if(i==2)y=(szOut[0]-48)*10+szOut[1]-48;
						if(i==1)y=szOut[0]-48;
				
					if(y==0&&x==0)
						MyBase[numer_i].index_zi[2]=0;
					else
						MyBase[numer_i].index_zi[2]=(y-1)*line+x;

					x=0;y=0;
					GetWindowText(hEdit2ex4, szOut, 4 );
						i=strlen(szOut);
						if(i==3)x=(szOut[0]-48)*100+(szOut[1]-48)*10+szOut[2]-48;
						if(i==2)x=(szOut[0]-48)*10+szOut[1]-48;
						if(i==1)x=szOut[0]-48;
						if(i==0)x=0;
					GetWindowText(hEdit2ey4, szOut, 4 );
						i=strlen(szOut);
						if(i==3)y=(szOut[0]-48)*100+(szOut[1]-48)*10+szOut[2]-48;
						if(i==2)y=(szOut[0]-48)*10+szOut[1]-48;
						if(i==1)y=szOut[0]-48;
				
					if(y==0&&x==0)
						MyBase[numer_i].index_zi[3]=0;
					else
						MyBase[numer_i].index_zi[3]=(y-1)*line+x;
						SetWindowText(hEdit1e, szText );
						SetWindowText(hEdit2e, szText );
						SetWindowText(hEdit2et, szText );

						SetWindowText(hEdit3e, szText );
					if(numerzi!=0)
						MyBase[numer_i].index_zi_how_mani=numerzi;

					save=1;
					zi[0]=0;
					zi[1]=0;
					zi[2]=0;
					zi[3]=0;
					numerzi=-1;
					lenstr=0;
					numer_i=max_struct+1;
					InvalidateRect( hWnd, NULL, TRUE );	
					break;

				  case ADD_STR :
						if(max_struct<MAX-1)
								{
								max_struct++;
								SetWindowText(hEdit1e, 	MyBase[numer_i].name_rus);
								SetWindowText(hEdit2e,	MyBase[numer_i].name_chinese );
								SetWindowText(hEdit3e, MyBase[numer_i].name_english);
								MyBase[max_struct].index_zi_how_mani=MyBase[numer_i].index_zi_how_mani;
								MyBase[max_struct].index_zi[0]=MyBase[numer_i].index_zi[0];
								MyBase[max_struct].index_zi[1]=MyBase[numer_i].index_zi[1];
								MyBase[max_struct].index_zi[2]=MyBase[numer_i].index_zi[2];
								MyBase[max_struct].index_zi[3]=MyBase[numer_i].index_zi[3];
								MyBase[max_struct].tones=MyBase[numer_i].tones;
								numer_i=max_struct;
								}
						 else
								ErrorHandle(hWnd, "can't new string");
								save=1;
								InvalidateRect( hWnd, NULL, TRUE );
						
							  break;

                 case DEL_STR :
						 strcpy(MyBase[max_struct].name_rus,szText);
						 strcpy(MyBase[max_struct].name_chinese,szText);
						 strcpy(MyBase[max_struct].name_english,szText);

						 MyBase[max_struct].index_zi[0]=0;
						 MyBase[max_struct].index_zi[1]=0;
						 MyBase[max_struct].index_zi[2]=0;
						 MyBase[max_struct].index_zi[3]=0;
						 MyBase[max_struct].tones=0;
						 max_struct--;
						 save=1;InvalidateRect( hWnd, NULL, TRUE );
						
						 break;

				case RES_EDIT :
					//reset-----
						 	zi[0]=0;
							zi[1]=0;
							zi[2]=0;
							zi[3]=0;
							numerzi=-1;
							lenstr=0;
					//-----------
							SetWindowText(hEdit2e, szText );
							InvalidateRect( hWnd, NULL, TRUE );
							break;

                 case CL_STR :
					 	 strcpy(MyBase[numer_i].name_rus,szText);
						 strcpy(MyBase[numer_i].name_chinese,szText);
						 strcpy(MyBase[numer_i].name_english,szText);
						 MyBase[numer_i].index_zi_how_mani=0;
						 MyBase[numer_i].index_zi[0]=0;
						 MyBase[numer_i].index_zi[1]=0;
						 MyBase[numer_i].index_zi[2]=0;
						 MyBase[numer_i].index_zi[3]=0;
						 MyBase[numer_i].tones=0;
						 save=1;
						 InvalidateRect( hWnd, NULL, TRUE );
						 break;

		

                case IDM_LOAD :
					hFile=CreateFile(pFilename, GENERIC_READ,
								FILE_SHARE_READ, NULL,OPEN_EXISTING, 0, NULL);
						if (hFile==INVALID_HANDLE_VALUE)
							ErrorHandle(hWnd, "error open file");
						dwFileLength=GetFileSize (hFile, NULL) ;
						dwBmpSize=dwFileLength-sizeof(BITMAPFILEHEADER);	
						pBmp=	(BYTE*) malloc(dwBmpSize);
						SetFilePointer(hFile, sizeof(BITMAPFILEHEADER), NULL, FILE_BEGIN);
						ReadFile(hFile, (LPVOID)pBmp, dwBmpSize, &nBytesRead, NULL);
						CloseHandle(hFile);
						pBmpInfo=(BITMAPINFO*)pBmp;
						pPixels=pBmp+sizeof(BITMAPINFOHEADER)+sizeof(RGBQUAD)*16;


						hFile3=CreateFile(pFilename3, GENERIC_READ,
							FILE_SHARE_READ, NULL,OPEN_EXISTING, 0, NULL);
						if (hFile3==INVALID_HANDLE_VALUE)
						ErrorHandle(hWnd, "error open file3");
						dwFileLength=GetFileSize (hFile3, NULL) ;	
					//	ReadFile(hFile3, (LPVOID)&max_struct,100, &nBytesRead, NULL);
					//	  ReadFile(hFile3, (LPVOID)pBase, dwFileLength-100
					//	  , &nBytesRead, NULL);
						CloseHandle(hFile3);
                        break;

                 case IDM_ABOUT :
                        DialogBox( hInst, "AboutBox", hWnd, (DLGPROC)About );
						 break;

                 case IDM_EXIT :
                        DestroyWindow( hWnd );
                        break;

				 case IDM_SAVE:
						save=0;
                       	hFile3=CreateFile(pFilename3, GENERIC_WRITE,
						FILE_SHARE_READ, NULL,OPEN_EXISTING, 0, NULL);
						if (hFile3==INVALID_HANDLE_VALUE)
						ErrorHandle(hWnd, "error open file3");
						//SetFilePointer(hFile3, 0, NULL, FILE_BEGIN);
						//max_struct=51500;
						WriteFile( hFile3, &max_struct, 100, 
											   &dwWritten, NULL );
						WriteFile( hFile3, pBase, sizeof(struct Base[MAX]), 
											   &dwWritten, NULL );
						SetEndOfFile( hFile3 );      
					 //ReadFile(hFile2, (LPVOID)pFile, dwFileSize, &nBytesRead, NULL);
						CloseHandle(hFile3);
						break;
              }
              break;

			   case WM_PAINT : 
              {	
				  //pPixels=pBmp+sizeof(BITMAPINFOHEADER)+sizeof(RGBQUAD)*256;
				 PAINTSTRUCT ps;
                  HDC  dc = BeginPaint( hWnd, &ps );
					// up,down;
							//	if(edit==2)
							{	
							if(downs>221)downs=221;
							j=3;
							for(i=0,k=ups;i<12,k<downs;i++,k++)
							{
								y=k+1;//(temp>line)?temp/line+1:1;
								x=0;
							 StretchDIBits(dc ,200, 25+i*FRAMEY,FRAMEX,FRAMEY,
									x1+dx*x,
									y1-dy*(y+0),
									15,16,
									pPixels, pBmpInfo, 0, SRCCOPY);
									
							  /*StretchDIBits(dc ,LEFT+j*FRAMEX, 25+i*FRAMEY,FRAMEX,FRAMEY,
									x1+dx*0,
									y1+dy*1,
									15,16,
									pPixels, pBmpInfo, 0,SRCCOPY  );
									*/
							  /* if(k==nSel2)
								StretchDIBits(dc ,LEFT-16+0*FRAMEX, 25+i*FRAMEY,FRAMEX,FRAMEY,
									x1+dx*0,
									y1-dy*0,
									15,16,
									pPixels, pBmpInfo, 0,SRCCOPY  );
							*/
							}
								
						}


								if(edit==1)
								{
									for(j=0;j<4;j++)
							  if(zi[j]!=0)
							  {
									temp=zi[j];
									y=(temp>line)?temp/line+1:1;
									x=(temp>line)?temp%line:temp;
								  StretchDIBits(dc ,LEFT+j*FRAMEX, 226,FRAMEX,FRAMEY,
										x1+dx*x,
								y1-dy*(y+0),
								15,16,
								pPixels, pBmpInfo, 0, SRCCOPY);
								}

								if(zi[0]!=0)
								 {temp=zi[0];
									 y=(temp>line)?temp/line+1:1;
									x=(temp>line)?temp%line:temp;
								 }else {x=0;y=0;}
									wsprintf( szOut, "%d",x);           
									SetWindowText(hEdit2ex, szOut );
									wsprintf( szOut, "%d",y);               
									SetWindowText(hEdit2ey, szOut );

									if(zi[1]!=0)
								 {temp=zi[1];
									 y=(temp>line)?temp/line+1:1;
									x=(temp>line)?temp%line:temp;
								}else {x=0;y=0;}
									wsprintf( szOut, "%d",x);           
									SetWindowText(hEdit2ex2, szOut );
									wsprintf( szOut, "%d",y);               
									SetWindowText(hEdit2ey2, szOut );
								   
									if(zi[2]!=0)
								 {temp=zi[2];
									 y=(temp>line)?temp/line+1:1;
									x=(temp>line)?temp%line:temp;
									}else {x=0;y=0;}
									wsprintf( szOut, "%d",x);           
									SetWindowText(hEdit2ex3, szOut );
									wsprintf( szOut, "%d",y);               
									SetWindowText(hEdit2ey3, szOut );
								  
									if(zi[3]!=0)
								 {temp=zi[3];
									 y=(temp>line)?temp/line+1:1;
									x=(temp>line)?temp%line:temp;
									}else {x=0;y=0;}
									wsprintf( szOut, "%d",x);           
									SetWindowText(hEdit2ex4, szOut );
									wsprintf( szOut, "%d",y);               
									SetWindowText(hEdit2ey4, szOut );
								}
					if(indexmaszie>0)
					{
						if(indexmaszie>12)indexmaszie=12;
						if(nSel2<12)
						for(i=0;i<indexmaszie;i++)
						for(j=0;j<4;j++)
					  if(MyBase[maszie[i]].index_zi[j]!=0)
						  {
							temp=MyBase[maszie[i]].index_zi[j];
								y=(temp>line)?temp/line+1:1;
								x=(temp>line)?temp%line:temp;	
							  StretchDIBits(dc ,LEFT+j*FRAMEX, 25+i*FRAMEY,FRAMEX,FRAMEY,
									x1+dx*x,
									y1-dy*(y+0),
									15,16,
									pPixels, pBmpInfo, 0, SRCCOPY);
							/* if(i==nSel2)
								StretchDIBits(dc ,LEFT-16+0*FRAMEX, 25+i*FRAMEY,FRAMEX,FRAMEY,
									x1+dx*0,
									y1-dy*0,
									15,16,
									pPixels, pBmpInfo, 0,SRCCOPY  );
							 */
							}
								
					}
					else
					
				  {
					if(indexmaszi>0)
						{
						 	if(down>indexmaszi)down=indexmaszi;
							for(i=0,k=up;i<12,k<down;i++,k++)
							for(j=0;j<4;j++)
						  if(MyBase[maszi[k]].index_zi[j]!=0)
						  {
								temp=MyBase[maszi[k]].index_zi[j];
								y=(temp>line)?temp/line+1:1;
								x=(temp>line)?temp%line:temp;
							 	  StretchDIBits(dc ,LEFT+j*FRAMEX, 25+i*FRAMEY,FRAMEX,FRAMEY,
									x1+dx*x,
									y1-dy*(y+0),
									15,16,
									pPixels, pBmpInfo, 0, SRCCOPY);
								if(k==nSel2)
								StretchDIBits(dc ,LEFT-15+0*FRAMEX, 25+i*FRAMEY,FRAMEX,FRAMEY,
									x1+dx*0,
									y1-dy*0,
									15,16,
									pPixels, pBmpInfo, 0,SRCCOPY  );
							}
					
						}
						else
						{	
							if(down>index_mas)down=index_mas;
							for(i=0,k=up;i<12,k<down;i++,k++)
							for(j=0;j<4;j++)
							  if(MyBase[mas[k]].index_zi[j]!=0)
							  {
								temp=MyBase[mas[k]].index_zi[j];
								y=(temp>line)?temp/line+1:1;
								x=(temp>line)?temp%line:temp;
							  StretchDIBits(dc ,LEFT+j*FRAMEX, 25+i*FRAMEY,FRAMEX,FRAMEY,
									x1+dx*x,
									y1-dy*(y+0),
									15,16,
									pPixels, pBmpInfo, 0, SRCCOPY);
							   if(k==nSel2)
								StretchDIBits(dc ,LEFT-15+0*FRAMEX, 25+i*FRAMEY,FRAMEX,FRAMEY,
									x1+dx*0,
									y1-dy*0,
									15,16,
									pPixels, pBmpInfo, 0,SRCCOPY  );
							}else 
								if(j==0)
									StretchDIBits(dc ,LEFT+j*FRAMEX, 25+i*FRAMEY,FRAMEX,FRAMEY,
									x1+dx*0,
									y1+dy*1,
									15,16,
									pPixels, pBmpInfo, 0,SRCCOPY  );
						}

				  	
				  }
				//----------------------
				 if(edit==0)
				 {
					 for(j=0;j<4;j++)
				 if(numer_zi[j]!=0)
				  {
						temp=numer_zi[j];
					  	y=(temp>line)?temp/line+1:1;
						x=(temp>line)?temp%line:temp;
				
						StretchDIBits(dc ,LEFT+j*FRAMEX, TOP,FRAMEX,FRAMEY,
							x1+dx*x,
							y1-dy*(y+0),
							15,16,
							pPixels, pBmpInfo, 0, SRCCOPY);
				  }
				 /*else 
				 {if(j==0)
				 StretchDIBits(dc ,LEFT+j*FRAMEX, TOP,FRAMEX,FRAMEY,
									x1+dx*0,
									y1+dy*1,
									15,16,
									pPixels, pBmpInfo, 0,SRCCOPY  );
				  if(j==1&&numer_zi[j-1]==0)
					  StretchDIBits(dc ,LEFT+j*FRAMEX, TOP,FRAMEX,FRAMEY,
									x1+dx*0,
									y1+dy*1,
									15,16,
									pPixels, pBmpInfo, 0,SRCCOPY  );
				  }*/

				 if(numer_zi[0]!=0)
				 {temp=numer_zi[0];
					 y=(temp>line)?temp/line+1:1;
					x=(temp>line)?temp%line:temp;
				 }else {x=0;y=0;}
					wsprintf( szOut, "%d",x);           
					SetWindowText(hEdit2ex, szOut );
					wsprintf( szOut, "%d",y);               
					SetWindowText(hEdit2ey, szOut );
				 
				 if(numer_zi[1]!=0)
				 {temp=numer_zi[1];
					 y=(temp>line)?temp/line+1:1;
					x=(temp>line)?temp%line:temp;
				}else {x=0;y=0;}
					wsprintf( szOut, "%d",x);           
					SetWindowText(hEdit2ex2, szOut );
					wsprintf( szOut, "%d",y);               
					SetWindowText(hEdit2ey2, szOut );
				 
				 if(numer_zi[2]!=0)
				 {temp=numer_zi[2];
					 y=(temp>line)?temp/line+1:1;
					x=(temp>line)?temp%line:temp;
					}else {x=0;y=0;}
					wsprintf( szOut, "%d",x);           
					SetWindowText(hEdit2ex3, szOut );
					wsprintf( szOut, "%d",y);               
					SetWindowText(hEdit2ey3, szOut );
				 
				 if(numer_zi[3]!=0)
				 {temp=numer_zi[3];
					 y=(temp>line)?temp/line+1:1;
					x=(temp>line)?temp%line:temp;
					}else {x=0;y=0;}
					wsprintf( szOut, "%d",x);           
					SetWindowText(hEdit2ex4, szOut );
					wsprintf( szOut, "%d",y);               
					SetWindowText(hEdit2ey4, szOut );
				 
				 }
		//---------------------			  
					wsprintf( szOut, "sel2=%d sel2x=%d ups=%d downs=%d",nSel2,nSel2X,
					 ups,downs);
					TextOut( dc, 450, 245, szOut, lstrlen( szOut ) );
                 	 wsprintf( szOut, "max_struct=%d i=%d Sel2s=%d Sel2x=%d"
											,max_struct,numer_i,nSel2s,nSel2Xs );
					TextOut( dc, 350, 263, szOut, lstrlen( szOut ) );
				    EndPaint( hWnd, &ps );
              }
              break;


      //case WM_CLOSE :  
        //          if ( MessageBox( hWnd, "Do you want to quit?", lpszAppName, MB_YESNO | MB_ICONQUESTION ) == IDNO )
		//			  break;
	  case WM_DESTROY :
		  if(save==1)
		  { hFile3=CreateFile(pFilename3, GENERIC_WRITE,
					FILE_SHARE_READ, NULL,OPEN_EXISTING, 0, NULL);
					if (hFile3==INVALID_HANDLE_VALUE)
						ErrorHandle(hWnd, "error open file3");
						//SetFilePointer(hFile3, 0, NULL, FILE_BEGIN);
						WriteFile( hFile3, &max_struct, 100, 
											   &dwWritten, NULL );
						WriteFile( hFile3, pBase, sizeof(struct Base[MAX]), 
											   &dwWritten, NULL );
						SetEndOfFile( hFile3 );      
			}
		  bActive=FALSE;
		//	free(pFile);
		  	free(pBmp);
			free(pFile);
		
              PostQuitMessage(0);
              break;
	 
	HANDLE_MSG(hWnd,WM_ACTIVATE,D_OnActivate);
	HANDLE_MSG(hWnd,WM_KEYDOWN,D_OnKey);
	HANDLE_MSG(hWnd,WM_TIMER,D_OnTimer);
	



      default :
            return( DefWindowProc( hWnd, uMsg, wParam, lParam ) );
   }

   return( 0L );
}



LRESULT CALLBACK About( HWND hDlg,           
                        UINT message,        
                        WPARAM wParam,       
                        LPARAM lParam)
{
   switch (message) 
   {
       case WM_INITDIALOG: 
               return (TRUE);

       case WM_COMMAND:                              
               if (   LOWORD(wParam) == IDOK         
                   || LOWORD(wParam) == IDCANCEL)    
               {
                       EndDialog(hDlg, TRUE);        
                       return (TRUE);
               }
               break;
   }

   return (FALSE); 
}

void D_OnIdle(HWND hWnd)
{
static char szTextX1[MAX_LEN_STR+20 ];
static char szTextX2[MAX_LEN_STR];
static char szTextX3[MAX_LEN_STR ];
static char szTextX2e[MAX_LEN_STR];
static int indexziX=0;
static RECT rect;
int temp;
static int nSel,nSel3,nSel3X=-1,nSelX=-1;
int i, j,n;
char szKBName[ KL_NAMELENGTH ];
unsigned	int a;
unsigned	int b;
				
RECT lpr;
lpr.left = 350;//LEFT;
lpr.top = 0;//TOP;
lpr.right = 500;//RIGTH;
lpr.bottom = 300;//BOTTOM;
//InvalidateRect(hWnd, &lpr, true);
	hFocus = GetFocus();

		if(hFocus==hEdit1e)
				  {		
						if(auto_key_sw)
							{			
							if(hFocusX!=hEdit1e)//||
							if(hFocusX!=hEdit1)
							ActivateKeyboardLayout(HKL_NEXT,NULL);
							hFocusX=hFocus;
							}
					}
		 if(hFocus==hEdit1)
				  {
						if(auto_key_sw)
							{
							if(hFocusX!=hEdit1)//||hFocusX!=hEdit1e)
							if(hFocusX!=hEdit1e)
							ActivateKeyboardLayout(HKL_NEXT,NULL);
							hFocusX=hFocus;
							}
		 			GetWindowText(hEdit1, szText1, MAX_LEN_STR+20 );		
				if(  strcmp(&szText1,&szTextX1))
				{//reset-----
						 	zi[0]=0;
							zi[1]=0;
							zi[2]=0;
							zi[3]=0;
							numerzi=-1;
							lenstr=0;
							//-----------
					
					edit=0;	
					numerzi=-1;
				
					SendMessage((hListBox), LB_RESETCONTENT, 0, 0 );
					SendMessage((hListBox2), LB_RESETCONTENT, 0, 0 );
					SendMessage((hListBox3), LB_RESETCONTENT, 0, 0 );
				
						strcpy(	 szTextX1, szText1);
						SetWindowText(hEdit3, szText );
						SetWindowText(hEdit2, szText );
						SetWindowText(hEdit3e, szText );
						SetWindowText(hEdit2e, szText );
						SetWindowText(hEdit1e, szText );
						SetWindowText(hEdit2t, szText );
						SetWindowText(hEdit2ex, szText );
						SetWindowText(hEdit2ey, szText );
						SetWindowText(hEdit2ex2, szText );
						SetWindowText(hEdit2ey2, szText );
						SetWindowText(hEdit2ex3, szText );
						SetWindowText(hEdit2ey3, szText );
						SetWindowText(hEdit2ex4, szText );
						SetWindowText(hEdit2ey4, szText );
				
						n=strlen(szText1);
						indexmaszie=0;
						index_mas=0;
						indexmaszi=0;
						numer_zi[0]=0;	
						numer_zi[1]=0;
						numer_zi[2]=0;
						numer_zi[3]=0;	nSelX=-1;
					if(n!=0)
					for(i=0;i<MAX;i++)
					if( ! strcmp(&szText1,&MyBase[i].name_rus))
					{	
						SendMessage( (HWND)(HANDLE)hListBox2 , LB_INSERTSTRING, (WPARAM)-1,
								(LPARAM)(LPTSTR)MyBase[i].name_chinese);
						SendMessage( (HWND)(HANDLE)hListBox3 , LB_INSERTSTRING, (WPARAM)-1,
								(LPARAM)(LPTSTR)MyBase[i].name_english );
						SetWindowText(hEdit2e,MyBase[i].name_chinese );
						SetWindowText(hEdit1e,MyBase[i].name_rus );
						SetWindowText(hEdit3e,MyBase[i].name_english );
					//	SetWindowText(hEdit2len_zi, MyBase[i].index_zi_how_mani );
						numer_zi[0]=MyBase[i].index_zi[0];
						numer_zi[1]=MyBase[i].index_zi[1];
						numer_zi[2]=MyBase[i].index_zi[2];
						numer_zi[3]=MyBase[i].index_zi[3];
								
						numer_i=i;

							
						//break;
					}
					else
					{
						if(szText1[0]==MyBase[i].name_rus[0])
							switch(n)
							{
							default:
								if(szText1[12]==MyBase[i].name_rus[12])
							case 12:
								if(szText1[11]==MyBase[i].name_rus[11])
							case 11:
								if(szText1[10]==MyBase[i].name_rus[10])
							case 10:
								if(szText1[9]==MyBase[i].name_rus[9])
							case 9:
								if(szText1[8]==MyBase[i].name_rus[8])
							case 8:
								if(szText1[7]==MyBase[i].name_rus[7])
							case 7:
								if(szText1[6]==MyBase[i].name_rus[6])
							case 6:
								if(szText1[5]==MyBase[i].name_rus[5])
							case 5:
								if(szText1[4]==MyBase[i].name_rus[4])
							case 4:
								if(szText1[3]==MyBase[i].name_rus[3])
							case 3:
								if(szText1[2]==MyBase[i].name_rus[2])
							case 2:
								if(szText1[1]==MyBase[i].name_rus[1])
							case 1:
								//if(szText1[0]==MyBase[i].name_rus[0])
							SendMessage( (HWND)(HANDLE)hListBox , LB_INSERTSTRING, (WPARAM)-1,
								(LPARAM)(LPTSTR)MyBase[i].name_rus );
							break;	
							}
						
						}
						InvalidateRect( hWnd, NULL, TRUE );
							UpdateWindow( hWnd );
						
				  }
			 }

			if(hFocus==hEdit2ey)
			{
			GetWindowText(hEdit2ey, szTextN, 5 );	
				n=strlen(szTextN);
						if(n>=1)
							for	(i=0;i<5;i++)
								if(szTextN[i]==32)
									{
									
									szTextN[i]=0;
									SetWindowText(hEdit2ey, szTextN );
									SetFocus( hEdit2ex);
								}
			}
			if(hFocus==hEdit2ex)
			{
			GetWindowText(hEdit2ex, szTextN, 5 );	
				n=strlen(szTextN);
						if(n>=1)
							for	(i=0;i<5;i++)
								if(szTextN[i]==32)
									{
									
									szTextN[i]=0;
									SetWindowText(hEdit2ex, szTextN );
									SetFocus( hEdit2ey2);
								}
			}
			if(hFocus==hEdit2ey2)
			{
			GetWindowText(hEdit2ey2, szTextN, 5 );	
				n=strlen(szTextN);
						if(n>=1)
							for	(i=0;i<5;i++)
								if(szTextN[i]==32)
									{
									
									szTextN[i]=0;
									SetWindowText(hEdit2ey2, szTextN );
									SetFocus( hEdit2ex2);
								}
			}	  
			if(hFocus==hEdit2ex2)
			{
			GetWindowText(hEdit2ex2, szTextN, 5 );	
				n=strlen(szTextN);
						if(n>=1)
							for	(i=0;i<5;i++)
								if(szTextN[i]==32)
									{
									
									szTextN[i]=0;
									SetWindowText(hEdit2ex2, szTextN );
									SetFocus( hEdit2ey3);
								}
			}if(hFocus==hEdit2ey3)
			{
			GetWindowText(hEdit2ey3, szTextN, 5 );	
				n=strlen(szTextN);
						if(n>=1)
							for	(i=0;i<5;i++)
								if(szTextN[i]==32)
									{
									
									szTextN[i]=0;
									SetWindowText(hEdit2ey3, szTextN );
									SetFocus( hEdit2ex3);
								}
			}	  
			if(hFocus==hEdit2ex3)
			{
			GetWindowText(hEdit2ex3, szTextN, 5 );	
				n=strlen(szTextN);
						if(n>=1)
							for	(i=0;i<5;i++)
								if(szTextN[i]==32)
									{
									
									szTextN[i]=0;
									SetWindowText(hEdit2ex3, szTextN );
									SetFocus( hEdit2ey4);
								}
			}
			if(hFocus==hEdit2ep)
				  {
					if(auto_key_sw)
							{
							if(hFocusX==hEdit1||hFocusX==hEdit1e)
								ActivateKeyboardLayout(HKL_PREV,NULL);
							hFocusX=hEdit2ep;
							}
					edit=1;
					//hFocusX=hEdit2ep;
					GetWindowText(hEdit2ep, szTextE, MAX_LEN_STR );	
					if(  strcmp(&szTextE,&szTextX2e))
						{
						nSel2X=-1;nSel2=1;
					
						if(numerzi==-1)
						{
							numerzi=0;
							lenstr=0;nSel2X=-1;
							for(i=0;i<MAX_LEN_STR;i++)szText2p[i]=0;
						}
						//	SetWindowText(hEdit2ep, szText );
					
						strcpy(	 szTextX2e, szTextE);
						SetWindowText(hEdit1, szText );
						SetWindowText(hEdit2, szText );
						SetWindowText(hEdit3, szText );
						
						n=strlen(szTextE);
						//lenstr=n;
						indexmaszie=0;
						index_mas=0;
						indexmaszi=0;
						//not_zi=0;
						SendMessage((hListBox2), LB_RESETCONTENT, 0, 0 );					
							if(	help_on==1)
							{
								SendMessage((hListBox3), LB_RESETCONTENT, 0, 0 );
								SendMessage((hListBox), LB_RESETCONTENT, 0, 0 );
							}

						if(n!=0)	
						for(i=0;i<MAX;i++)
						if( ! strcmp(&szTextE,&MyBase[i].name_chinese))
						{
							if(indexmaszie<20-1)
							{
							maszie[indexmaszie]=i;
							indexmaszie++;
							}
						}
						if(indexmaszie>0)
						for(i=0;i<indexmaszie;i++)
							{	
							SendMessage( (HWND)(HANDLE)hListBox2 , LB_INSERTSTRING, (WPARAM)-1,
								(LPARAM)(LPTSTR)MyBase[maszie[i]].name_chinese );
								if(	help_on==1)
								{	SendMessage( (HWND)(HANDLE)hListBox , LB_INSERTSTRING, (WPARAM)-1,
									(LPARAM)(LPTSTR)MyBase[maszie[i]].name_rus );
									SendMessage( (HWND)(HANDLE)hListBox3 , LB_INSERTSTRING, (WPARAM)-1,
									(LPARAM)(LPTSTR)MyBase[maszie[i]].name_english );
								}
							}
						GetWindowText(hEdit2ep, szTextE, MAX_LEN_STR );			
	
						n=strlen(szTextE);
						if(n>=1)
							for	(i=0;i<MAX_LEN_STR;i++)
								if(szTextE[i]==32)
									{
									n--;
									szTextE[i]=0;
									for	(i=0;i<n;i++)
									szText2p[lenstr+i]=szTextE[i];
									lenstr=lenstr+i;
									SetWindowText(hEdit2ep,szText );
								//	ie=maszie[nSel2];
									zi[numerzi]=0;//MyBase[ie].index_zi[0];
									numerzi++;
								//	nSel2X=-1;
									SetWindowText(hEdit2e,szText2p );
									//	SetFocus( hEdit2e);
									break;
									}
									/*if(szTextE[0]==0D)
									{
									//n--;
									szTextE[0]=0;
									for	(i=0;i<4;i++)
									zi[i]=0;
									lenstr=0;//lenstr+i;
									SetWindowText(hEdit2ep,szText );
									SetWindowText(hEdit2e,szText );
									numerzi=-1;
									}
									*/
						InvalidateRect( hWnd, NULL, TRUE );
						}
						
					}
		if(hFocus==hEdit2t)
		{nSel2X=-1;	SetWindowText(hEdit2, szText );}
					

		if(hFocus==hEdit2e)
				  {
					if(auto_key_sw)
						{
						if(hFocusX==hEdit1||hFocusX==hEdit1e)	ActivateKeyboardLayout(HKL_PREV,NULL);			
						hFocusX=hEdit2e;
						}
					}
	 if(hFocus==hEdit2)
				  {
					if(auto_key_sw)
							{
							if(hFocusX==hEdit1||hFocusX==hEdit1e)
								ActivateKeyboardLayout(HKL_PREV,NULL);
					
							hFocusX=hEdit2;
							}
					
					GetWindowText(hEdit2, szText2, MAX_LEN_STR );			
					if(  strcmp(&szText2,&szTextX2))
					{
						//reset-----
						 	zi[0]=0;
							zi[1]=0;
							zi[2]=0;
							zi[3]=0;
							numerzi=-1;
							lenstr=0;
							//-----------
							edit=0;numerzi=-1;
			
						strcpy(	 szTextX2, szText2);
						SetWindowText(hEdit1, szText );
						SetWindowText(hEdit3, szText );
						SetWindowText(hEdit1e, szText );
						SetWindowText(hEdit3e, szText );
						SetWindowText(hEdit2e, szText );
						SetWindowText(hEdit2t, szText );
						SetWindowText(hEdit2ex, szText );
						SetWindowText(hEdit2ey, szText );
						SetWindowText(hEdit2ex2, szText );
						SetWindowText(hEdit2ey2, szText );
						SetWindowText(hEdit2ex3, szText );
						SetWindowText(hEdit2ey3, szText );
						SetWindowText(hEdit2ex4, szText );
						SetWindowText(hEdit2ey4, szText );
				
						indexmaszie=0;
						index_mas=0;
						indexmaszi=0;
						numer_zi[0]=0;	
						numer_zi[1]=0;
						numer_zi[2]=0;
						numer_zi[3]=0;
						nSel2X=-1;nSelX=-1;nSel3X=-1;
						nSel2=0;if(nSel2X==-1){up=0;down=12;}
									
						SendMessage((hListBox2), LB_RESETCONTENT, 0, 0 );					
						SendMessage((hListBox3), LB_RESETCONTENT, 0, 0 );
						SendMessage((hListBox), LB_RESETCONTENT, 0, 0 );
						n=strlen(szText2);
						
						if(n!=0)	
						for(i=0;i<MAX;i++)
						if( ! strcmp(&szText2,&MyBase[i].name_chinese))
						{
							if(indexmaszi<20-1)
							{
							maszi[indexmaszi]=i;
							indexmaszi++;
							}
						}
						else		
						{
						if(szText2[0]==MyBase[i].name_chinese[0])
							switch(n)
							{
							default:
								if(szText2[12]==MyBase[i].name_chinese[12])
							case 12:
								if(szText2[11]==MyBase[i].name_chinese[11])
							case 11:
								if(szText2[10]==MyBase[i].name_chinese[10])
							case 10:
								if(szText2[9]==MyBase[i].name_chinese[9])
							case 9:
								if(szText2[8]==MyBase[i].name_chinese[8])
							case 8:
								if(szText2[7]==MyBase[i].name_chinese[7])
							case 7:
								if(szText2[6]==MyBase[i].name_chinese[6])
							case 6:
								if(szText2[5]==MyBase[i].name_chinese[5])
							case 5:
								if(szText2[4]==MyBase[i].name_chinese[4])
							case 4:
								if(szText2[3]==MyBase[i].name_chinese[3])
							case 3:
								if(szText2[2]==MyBase[i].name_chinese[2])
							case 2:
								if(szText2[1]==MyBase[i].name_chinese[1])
							case 1:
								//if(szText2[0]==MyBase[i].name_chinese[0])
								//wsprintf( szOut, "%s %d",MyBase[i].name_chinese,MyBase[i].tones);           
								//SetWindowText(hEdit2ex, szOut );
							//	SendMessage( (HWND)(HANDLE)hListBox2 , LB_INSERTSTRING, (WPARAM)-1,
							//	(LPARAM)(LPTSTR)MyBase[i].name_chinese );
								if(index_mas<MAX_LEN_MAS-1)
								{mas[index_mas]=i;
								index_mas++;}
						
							

							break;	
							}//sw
						
						}//el
						//sortirovka-
						//-------------------------------------------------------
							j=0;
							while(j<=index_mas)
							{
								for(i=index_mas-1;i>=j;i--)
								{
									a=MyBase[mas[i]].name_chinese[1];
									b=MyBase[mas[i-1]].name_chinese[1];
								//if(a!=b)
								if(a<b)
								//if(MyBase[mas[i]].name_chinese[1]<MyBase[mas[i-1]].name_chinese[1])
								{
									temp=mas[i];mas[i]=mas[i-1];mas[i-1]=temp;
								}
								if(a==b)
								{	a=MyBase[mas[i]].name_chinese[2];
									b=MyBase[mas[i-1]].name_chinese[2];
									if(a<b)
									{
										temp=mas[i];mas[i]=mas[i-1];mas[i-1]=temp;
										
									}
									if(a==b)
										{	a=MyBase[mas[i]].name_chinese[3];
											b=MyBase[mas[i-1]].name_chinese[3];
											if(a<b)
											{
												temp=mas[i];mas[i]=mas[i-1];mas[i-1]=temp;
												
											}
											if(a==b)
											{
												a=MyBase[mas[i]].name_chinese[4];
												b=MyBase[mas[i-1]].name_chinese[4];
												if(a<b)
												{
													temp=mas[i];mas[i]=mas[i-1];mas[i-1]=temp;
													
												}
												if(a==b)
												{
													a=MyBase[mas[i]].name_chinese[5];
													b=MyBase[mas[i-1]].name_chinese[5];
													if(a<b)
													{
														temp=mas[i];mas[i]=mas[i-1];mas[i-1]=temp;
														
													}
													if(a==b)
														{
															a=MyBase[mas[i]].name_chinese[6];
															b=MyBase[mas[i-1]].name_chinese[6];
															if(a<b)
															{
																temp=mas[i];mas[i]=mas[i-1];mas[i-1]=temp;
																
															}
														}	
												}	
											}	
										}	
								}		
								}
							j++;
							}
							//------------------------------------------------------------
							//sortir

					if(indexmaszi>0)
					for(i=0;i<indexmaszi;i++)
							SendMessage( (HWND)(HANDLE)hListBox2 , LB_INSERTSTRING, (WPARAM)-1,
								(LPARAM)(LPTSTR)MyBase[maszi[i]].name_chinese );
					else
					for(i=0;i<index_mas;i++)
						SendMessage( (HWND)(HANDLE)hListBox2 , LB_INSERTSTRING, (WPARAM)-1,
						(LPARAM)(LPTSTR)MyBase[mas[i]].name_chinese );
				
					InvalidateRect( hWnd, NULL, TRUE );
							//UpdateWindow( hWnd );
					}//if

							

				}

			if(hFocus==hEdit3e)
					{	
						if(auto_key_sw)
							{
							if(hFocusX==hEdit1||hFocusX==hEdit1e)	ActivateKeyboardLayout(HKL_PREV,NULL);
							hFocusX=hEdit3e;
							}
					}
				
			if(hFocus==hEdit3)
				  {		if(auto_key_sw)
							{
						if(hFocusX==hEdit1||hFocusX==hEdit1e)	ActivateKeyboardLayout(HKL_PREV,NULL);
						hFocusX=hEdit3;
							}
				

					GetWindowText(hEdit3, szText3, MAX_LEN_STR );
					if(  strcmp(&szText3,&szTextX3))
					{
						//reset-----
						 	zi[0]=0;
							zi[1]=0;
							zi[2]=0;
							zi[3]=0;
							numerzi=-1;
							lenstr=0;
							//-----------edit=0;numerzi=-1;
			
						SendMessage((hListBox3), LB_RESETCONTENT, 0, 0 );					
						SendMessage((hListBox), LB_RESETCONTENT, 0, 0 );
						SendMessage((hListBox2), LB_RESETCONTENT, 0, 0 );
						strcpy(	 szTextX3, szText3);
						SetWindowText(hEdit1, szText );
						SetWindowText(hEdit2, szText );
						SetWindowText(hEdit1e, szText );
						SetWindowText(hEdit2e, szText );
						SetWindowText(hEdit3e, szText );
						SetWindowText(hEdit2t, szText );
						SetWindowText(hEdit2ex, szText );
						SetWindowText(hEdit2ey, szText );
						SetWindowText(hEdit2ex2, szText );
						SetWindowText(hEdit2ey2, szText );
						SetWindowText(hEdit2ex3, szText );
						SetWindowText(hEdit2ey3, szText );
						SetWindowText(hEdit2ex4, szText );
						SetWindowText(hEdit2ey4, szText );
				
						indexmaszi=0;
						index_mas=0;
						n=strlen(szText3);
						numer_zi[0]=0;	
						numer_zi[1]=0;
						numer_zi[2]=0;
						numer_zi[3]=0;
								nSel3X=-1;
						//SetWindowText( GetActiveWindow(), "finding" );
							if(n!=0)	
						for(i=0;i<MAX;i++)
						if( ! strcmp(&szText3,&MyBase[i].name_english))
						{	
							SendMessage( (HWND)(HANDLE)hListBox , LB_INSERTSTRING, (WPARAM)-1,
								(LPARAM)(LPTSTR)MyBase[i].name_rus );
							SendMessage( (HWND)(HANDLE)hListBox2 , LB_INSERTSTRING, (WPARAM)-1,
								(LPARAM)(LPTSTR)MyBase[i].name_chinese );
							SetWindowText(hEdit2e,MyBase[i].name_chinese );
							SetWindowText(hEdit1e,MyBase[i].name_rus );
								SetWindowText(hEdit3e,MyBase[i].name_english );
//								SetWindowText(hEdit2len_zi, MyBase[i].index_zi_how_mani );
					
							numer_zi[0]=MyBase[i].index_zi[0];
								numer_zi[1]=MyBase[i].index_zi[1];
								numer_zi[2]=MyBase[i].index_zi[2];
								numer_zi[3]=MyBase[i].index_zi[3];
									numer_i=i;
							//InvalidateRect( hWnd, NULL, TRUE );
							//	UpdateWindow( hWnd );
							
							//break;
						} 
						else
						{
						if(szText3[0]==MyBase[i].name_english[0])
							switch(n)
							{
							default:
							//	if(szText3[12]==MyBase[i].name_english[12])
							case 12:
								if(szText3[11]==MyBase[i].name_english[11])
							case 11:
								if(szText3[10]==MyBase[i].name_english[10])
							case 10:
								if(szText3[9]==MyBase[i].name_english[9])
							case 9:
								if(szText3[8]==MyBase[i].name_english[8])
							case 8:
								if(szText3[7]==MyBase[i].name_english[7])
							case 7:
								if(szText3[6]==MyBase[i].name_english[6])
							case 6:
								if(szText3[5]==MyBase[i].name_english[5])
							case 5:
								if(szText3[4]==MyBase[i].name_english[4])
							case 4:
								if(szText3[3]==MyBase[i].name_english[3])
							case 3:
								if(szText3[2]==MyBase[i].name_english[2])
							case 2:
								if(szText3[1]==MyBase[i].name_english[1])
							case 1:
								//if(szText3[0]==MyBase[i].name_english[0])
							SendMessage( (HWND)(HANDLE)hListBox3 , LB_INSERTSTRING, (WPARAM)-1,
								(LPARAM)(LPTSTR)MyBase[i].name_english );
							//SetWindowText( GetActiveWindow(), lpszAppName);
							break;	
							}
						
						}
						InvalidateRect( hWnd, NULL, TRUE );
							UpdateWindow( hWnd );
					}
				}

	if(hFocus==hListBox)
				  {
					
					nSel = SendMessage( hListBox, LB_GETCURSEL, 0, 0 ); 
						if(nSel!=nSelX)
						{	
							nSelX=nSel;
							SendMessage((hListBox), LB_GETTEXT, (WPARAM)(int)(nSel), 
								(LPARAM)(LPCSTR)(szText1));
							SetWindowText(hEdit1, szText1 );
							SetWindowText(hEdit1e, szText1 );
							SendMessage((hListBox2), LB_RESETCONTENT, 0, 0 );
							SendMessage((hListBox3), LB_RESETCONTENT, 0, 0 );
							strcpy(	 szTextX1, szText1);
							for(i=0;i<MAX;i++)
							if( ! strcmp(&szText1,&MyBase[i].name_rus))
							{	
								SendMessage( (HWND)(HANDLE)hListBox2 , LB_INSERTSTRING, (WPARAM)-1,
								(LPARAM)(LPTSTR)MyBase[i].name_chinese );
								SendMessage( (HWND)(HANDLE)hListBox3 , LB_INSERTSTRING, (WPARAM)-1,
								(LPARAM)(LPTSTR)MyBase[i].name_english );
								numer_zi[0]=MyBase[i].index_zi[0];
								numer_zi[1]=MyBase[i].index_zi[1];
								numer_zi[2]=MyBase[i].index_zi[2];
								numer_zi[3]=MyBase[i].index_zi[3];
									wsprintf( szOut, "%d",MyBase[i].tones);           
								SetWindowText(hEdit2t, szOut );
								SetWindowText(hEdit2e,MyBase[i].name_chinese );
								SetWindowText(hEdit3e,MyBase[i].name_english );
//								SetWindowText(hEdit2len_zi, MyBase[i].index_zi_how_mani );
					
								numer_i=i;
								InvalidateRect( hWnd, NULL, TRUE );
									//	UpdateWindow( hWnd );
								//break;
							}
						}
				  }
	
	
				
	 if(hFocus==hListBox2)
				  {
				  	
					nSel2 = SendMessage( hListBox2, LB_GETCURSEL, 0, 0 ); 
						if(nSel2!=nSel2X)
						{		
								SendMessage((hListBox3), LB_RESETCONTENT, 0, 0 );
								SendMessage((hListBox), LB_RESETCONTENT, 0, 0 );
								
							//if(edit!=2)
								if(indexmaszie>0)
								{		

									n=strlen(szTextE);
									for	(i=0;i<n;i++)
									szText2p[lenstr+i]=szTextE[i];
									lenstr=lenstr+i;
									SetWindowText(hEdit2ep,szText );
									ie=maszie[nSel2];
									zi[numerzi]=MyBase[ie].index_zi[0];
									numerzi++;
									if(nSel2X==-1){up=0;down=12;}
										
										if(nSel2>11||up>0)
										{
											if(nSel2>nSel2X)
											if(nSel2>down-1)
											{up++;down++;}	
											if(nSel2<nSel2X)
											if(nSel2<up){up--;down--;}	
										}
										
									nSel2X=-1;
									SetWindowText(hEdit2e,szText2p );
									//wsprintf( szOut, "%d",MyBase[ie].tones);           
									//	SetWindowText(hEdit2t, szOut );
								
										SetFocus( hEdit2ep);
								}
								else
								{			
									if(indexmaszi>0)
									{
									SendMessage((hListBox2), LB_GETTEXT,
									(WPARAM)(int)(nSel2), (LPARAM)(LPCSTR)(szText2));
									strcpy(	 szTextX2, szText2);
								
									i=maszi[nSel2];
									if(nSel2X==-1){up=0;down=12;}
										if(nSel2==0){up=0;down=12;}
										if(nSel2>11||up>0)
										{
											if(nSel2>nSel2X)
											if(nSel2>down-1)
											{up++;down++;}	
											if(nSel2<nSel2X)
											if(nSel2<up){up--;down--;}	
										}
									}
									else	
									{//if(index_mas>0)
										SendMessage((hListBox2), LB_GETTEXT,
									(WPARAM)(int)(nSel2), (LPARAM)(LPCSTR)(szText2));
										strcpy(	 szTextX2, szText2);
										i=mas[nSel2];	
										if(nSel2X==-1){up=0;down=12;}
										if(nSel2==0){up=0;down=12;}
									
										if(nSel2>11||up>0)
										{
											if(nSel2>nSel2X)
											if(nSel2>down-1)
											{up++;down++;}	
											if(nSel2<nSel2X)
											if(nSel2<up){up--;down--;}	
										}
									}
									

									SetWindowText(hEdit2, szText2 );
										SetWindowText(hEdit2e, szText2 );
								
										numer_zi[0]=MyBase[i].index_zi[0];
										numer_zi[1]=MyBase[i].index_zi[1];
										numer_zi[2]=MyBase[i].index_zi[2];
										numer_zi[3]=MyBase[i].index_zi[3];
										wsprintf( szOut, "%d",MyBase[i].tones);           
										SetWindowText(hEdit2t, szOut );
									SendMessage( (HWND)(HANDLE)hListBox , LB_INSERTSTRING, (WPARAM)-1,
										(LPARAM)(LPTSTR)MyBase[i].name_rus );
									SendMessage( (HWND)(HANDLE)hListBox3 , LB_INSERTSTRING, (WPARAM)-1,
										(LPARAM)(LPTSTR)MyBase[i].name_english );
									SetWindowText(hEdit1e, MyBase[i].name_rus );
									SetWindowText(hEdit3e, MyBase[i].name_english );
								//		SetWindowText(hEdit2len_zi, MyBase[i].index_zi_how_mani );
					
									numer_i=i;
								nSel2X=nSel2;
								}
							//if(edit==1)	{nSel2X=-1;nSel2=0;}

								
								//	SetWindowText(hEdit2t,MyBase[i].tones );
								InvalidateRect( hWnd, NULL, TRUE );
								//UpdateWindow( hWnd );
								//InvalidateRect(hWnd, &lpr, TRUE);
							//break;
							}	

				  }

				 
		if(hFocus==hListBox2s)
				  {
				  	
					nSel2s = SendMessage( hListBox2s, LB_GETCURSEL, 0, 0 ); 
						if(nSel2s!=nSel2Xs)	
							
								{
										SetWindowText(hEdit1, szText );
										SetWindowText(hEdit2, szText );
										SetWindowText(hEdit3, szText );
										SetWindowText(hEdit1e, szText );
										SetWindowText(hEdit3e, szText );
										SetWindowText(hEdit2e, szText );
										SetWindowText(hEdit2t, szText );
										SetWindowText(hEdit2ex, szText );
										SetWindowText(hEdit2ey, szText );
										SetWindowText(hEdit2ex2, szText );
										SetWindowText(hEdit2ey2, szText );
										SetWindowText(hEdit2ex3, szText );
										SetWindowText(hEdit2ey3, szText );
										SetWindowText(hEdit2ex4, szText );
										SetWindowText(hEdit2ey4, szText );
								
										indexmaszie=0;
										index_mas=0;
										indexmaszi=0;
										numer_zi[0]=0;	
										numer_zi[1]=0;
										numer_zi[2]=0;
										numer_zi[3]=0;
										nSel2X=-1;
										nSel2=0;if(nSel2X==-1){up=0;down=12;}
													
										SendMessage((hListBox2), LB_RESETCONTENT, 0, 0 );					
										SendMessage((hListBox3), LB_RESETCONTENT, 0, 0 );
										SendMessage((hListBox), LB_RESETCONTENT, 0, 0 );
										
										if(nSel2Xs==-1){ups=0;downs=12;}
										if(nSel2s==0){ups=0;downs=12;}
										//if(nSel2s<=11){ups=0;downs=12;}
										
									
										if(nSel2s>11||ups>0)
										{
											if(nSel2s>nSel2Xs)
											if(nSel2s>downs-1)
											{ups++;downs++;}	
											if(nSel2s<nSel2Xs)
											if(nSel2s<ups){ups--;downs--;}	
										}
										//else
										//{ups=0;downs=12;}

										nSel2Xs=nSel2s;

								
								//if(nSel2Xs==-1)
								//{ups=0;downs=12;}
								
								
					
							y=nSel2s+1;
						for(i=0;i<MAX;i++)
						if(	MyBase[i].index_zi[0]>(y-1)*line&&MyBase[i].index_zi[0]<y*line
					)
					{	
						if(index_mas<MAX_LEN_MAS-1)
						{mas[index_mas]=i;
						index_mas++;}
							
					}
					
					j=0;
					if(y>0)
					while(j<=index_mas)
					{//for(j=0;j<index_mas;j++)
					for(i=index_mas-1;i>=j;i--)
				

						if(MyBase[mas[i]].index_zi[0]<MyBase[mas[i-1]].index_zi[0])
							{
							temp=mas[i];mas[i]=mas[i-1];mas[i-1]=temp;
							}
						
						j++;
					}
					//----------
					j=0;
					if(y>0)
					while(j<=index_mas)
					{//for(j=0;j<index_mas;j++)
					for(i=index_mas-1;i>=j;i--)
				

					if(MyBase[mas[i]].index_zi[0]==MyBase[mas[i-1]].index_zi[0])
					if(MyBase[mas[i]].index_zi[1]<MyBase[mas[i-1]].index_zi[1])
							{
							temp=mas[i];mas[i]=mas[i-1];mas[i-1]=temp;
							}
						
						
						j++;
					}
					//-----------
				
		//	SendMessage((hListBox2), LB_RESETCONTENT, 0, 0 );					
					
					for(i=0;i<index_mas;i++)
					{
						SendMessage( (HWND)(HANDLE)hListBox2 , LB_INSERTSTRING, (WPARAM)-1,
						(LPARAM)(LPTSTR)MyBase[mas[i]].name_chinese );
						SendMessage( (HWND)(HANDLE)hListBox , LB_INSERTSTRING, (WPARAM)-1,
						(LPARAM)(LPTSTR)MyBase[mas[i]].name_rus);
					
					}
					InvalidateRect( hWnd, NULL, TRUE );
				}
				
			}
					  
	 if(hFocus==hListBox3)
				  {
					nSel3 = SendMessage( hListBox3, LB_GETCURSEL, 0, 0 ); 
						//if(nSel3!=-1)
						if(nSel3!=nSel3X)
						{	
							nSel3X=nSel3;
							SendMessage((hListBox3), LB_GETTEXT,
								(WPARAM)(int)(nSel3), (LPARAM)(LPCSTR)(szText3));
							SetWindowText(hEdit3, szText3 );
							SetWindowText(hEdit3e, szText3 );
						
							strcpy(	 szTextX3, szText3);
							SendMessage((hListBox2), LB_RESETCONTENT, 0, 0 );
							SendMessage((hListBox), LB_RESETCONTENT, 0, 0 );
							for(i=0;i<MAX;i++)
							if( ! strcmp(&szText3,&MyBase[i].name_english))
							{
								numer_zi[0]=MyBase[i].index_zi[0];
								numer_zi[1]=MyBase[i].index_zi[1];
								numer_zi[2]=MyBase[i].index_zi[2];
								numer_zi[3]=MyBase[i].index_zi[3];
									wsprintf( szOut, "%d",MyBase[i].tones);           
								//if(MyBase[i].tones!=0)
									SetWindowText(hEdit2t, szOut );
							
								SendMessage( (HWND)(HANDLE)hListBox , LB_INSERTSTRING, (WPARAM)-1,
									(LPARAM)(LPTSTR)MyBase[i].name_rus );
								SendMessage( (HWND)(HANDLE)hListBox2 , LB_INSERTSTRING, (WPARAM)-1,
									(LPARAM)(LPTSTR)MyBase[i].name_chinese );
								SetWindowText(hEdit1e, MyBase[i].name_rus );
								SetWindowText(hEdit2e, MyBase[i].name_chinese );
							//	SetWindowText(hEdit2len_zi, MyBase[i].index_zi_how_mani );
					
								numer_i=i;
								InvalidateRect( hWnd, NULL, TRUE );
								//UpdateWindow( hWnd );InvalidateRect(hWnd, &lpr, TRUE);
								//InvalidateRect(hWnd, &lpr, TRUE);		
								//break;
							}
						
						}
				  }
//InvalidateRect( hWnd, NULL, TRUE );
					//	UpdateWindow( hWnd );
}
/*
BOOL LoadBMPO(LPDIRECTDRAWSURFACE7 pSurface,int width,int height, char* filename)
{
	//Объявление переменных, необходимых для чтения данных из BMP-файла
	BYTE* pBmp;
	DWORD dwBmpSize;
	DWORD dwFileLength;
	DWORD nBytesRead;
	BITMAPINFO* pBmpInfo;
	BYTE*		pPixels;
	HDC hdc;

	//Открытие файла с графическими данными
	HANDLE hFile=CreateFile(filename, GENERIC_READ,
			FILE_SHARE_READ, NULL,OPEN_EXISTING, 0, NULL);
	if (hFile==INVALID_HANDLE_VALUE)
		return (FALSE);

	//Получение размера файла и размера данных
	dwFileLength=GetFileSize (hFile, NULL) ;
	dwBmpSize=dwFileLength-sizeof(BITMAPFILEHEADER);
	

	//Выделение памяти под данные
	pBmp=	(BYTE*) malloc(dwBmpSize);
	SetFilePointer(hFile, sizeof(BITMAPFILEHEADER), NULL, FILE_BEGIN);
	//SetFilePointer(hFile,45000+ sizeof(BITMAPFILEHEADER), NULL, FILE_BEGIN);

	//Чтение файла с данными
	ReadFile(hFile, (LPVOID)pBmp, dwBmpSize, &nBytesRead, NULL);
	CloseHandle(hFile);

	pBmpInfo=(BITMAPINFO*)pBmp;
	pPixels=pBmp+sizeof(BITMAPINFOHEADER)+sizeof(RGBQUAD)*256;

	//Получение заголовка контекста устройства внеэкранной поверхности
	if ((pSurface->GetDC(&hdc)) == DD_OK)
	{
	//Копирование графических данных из памяти
	//на внеэкранную поверхность средствами GDI
		StretchDIBits(hdc , 0, 0,width,height, 0, 0,width,height, pPixels, pBmpInfo, 0, SRCCOPY);
		pSurface->ReleaseDC(hdc);
	}
	//Освобождение памяти
	free(pBmp);
	return (TRUE);
}
*/
void D_OnActivate(HWND hWnd, UINT state, HWND hwndActDeact, BOOL fMinimized)
{
	//Обновить флаг состояния активности
	if (state==WA_INACTIVE)
		bActive=FALSE;
	else
		bActive=TRUE;
}
void D_OnKey(HWND hWnd, UINT vk, BOOL fDown, int cRepeat, UINT flags)
{
int i;	
	//if(hFocus==hEdit2e)
	if (vk==VK_SPACE)
	{	
	;//nSel2s+=5;
							
	}
	if (vk==VK_ESCAPE)		
	
		;
	if (vk==VK_F1)
		;

	
//	if (vk==VK_ADD)
//		level+=1;	
//	if (vk==VK_SUBTRACT)
//		level-=1	;
}
void D_OnTimer(HWND hWnd, UINT id)
{
	//static n=1;
;
	D_OnIdle(hWnd);
	
	/*
	nSel2s+=n;
	if(nSel2s>100||nSel2s<00)
	{
		n=-n;
		nSel2s+=n;
		nSel2s+=n;
	}
*/

}