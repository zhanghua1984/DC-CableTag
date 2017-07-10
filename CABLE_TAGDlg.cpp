// CABLE_TAGDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CABLE_TAG.h"
#include "CABLE_TAGDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCABLE_TAGDlg dialog

CCABLE_TAGDlg::CCABLE_TAGDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCABLE_TAGDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCABLE_TAGDlg)
	m_strdatainput = _T("");
	m_strdataoutput = _T("");
	m_strcheckoutput = _T("");
	m_strdataoutputlenth = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCABLE_TAGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCABLE_TAGDlg)
	DDX_Control(pDX, IDC_DATAOUTPUTLENTH, m_csdataoutputlenth);
	DDX_Control(pDX, IDC_CHECKOUTPUT, m_cscheckoutput);
	DDX_Control(pDX, IDC_DATAOUTPUT, m_csdataoutput);
	DDX_Control(pDX, IDC_DATAINPUT, m_csdatainput);
	DDX_Text(pDX, IDC_DATAINPUT, m_strdatainput);
	DDX_Text(pDX, IDC_DATAOUTPUT, m_strdataoutput);
	DDX_Text(pDX, IDC_CHECKOUTPUT, m_strcheckoutput);
	DDX_Text(pDX, IDC_DATAOUTPUTLENTH, m_strdataoutputlenth);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCABLE_TAGDlg, CDialog)
	//{{AFX_MSG_MAP(CCABLE_TAGDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CACULATETAG, OnCaculatetag)
	ON_BN_CLICKED(IDC_CHECK, OnCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCABLE_TAGDlg message handlers

BOOL CCABLE_TAGDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_bytetostrresult=0xff;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCABLE_TAGDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCABLE_TAGDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCABLE_TAGDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCABLE_TAGDlg::OnCaculatetag() 
{
	// TODO: Add your control notification handler code here
	BYTE m_byteresult=0;	//异或结果值
	int m_intinputlenth=0;	//输入字节长度
	m_csdatainput.GetWindowText(m_strdatainput);

	int m_intlenth=m_strdatainput.GetLength();

	for (int i=0;i<m_intlenth;i++)
	{
		

		CString m_strcurstr=m_strdatainput.GetAt(i);

		if (m_strcurstr!=" ")
		{
			CString m_calnumber=m_strdatainput.Mid(i,2);

			unsigned int m_hexnumber;

			m_hexnumber=strtoul(m_calnumber,NULL,16);

			m_byteresult = (m_byteresult) ^ (m_hexnumber);
			
			i++;

			m_intinputlenth++;
		}

	}

	m_byteresult= m_byteresult ^ 0x02;


	m_bytetostrresult=m_byteresult;

	m_strdataoutput.Format("%x",m_byteresult);

	if (m_byteresult<10)
	{
		m_strdataoutput.Insert(0,"0");
	}

	m_csdataoutput.SetWindowText(m_strdataoutput);
	
	m_strdataoutputlenth.Format("%d",m_intinputlenth);

	m_csdataoutputlenth.SetWindowText(m_strdataoutputlenth);

}

void CCABLE_TAGDlg::OnCheck() 
{
	// TODO: Add your control notification handler code here
	int		m_intpostion=0;

	CString m_strinsert="10 ";

	BOOL	m_boolhave=FALSE;

	m_csdatainput.GetWindowText(m_strdatainput);
	
	m_strcheckoutput=m_strdatainput;

	int m_intlenth=m_strdatainput.GetLength();
	
	for (int i=0;i<m_intlenth;i++)
	{
			
		CString m_strcurstr=m_strdatainput.GetAt(i);
		
		if (m_strcurstr!=" ")
		{
			CString m_calnumber=m_strdatainput.Mid(i,2);
			
			unsigned int m_hexnumber;
			
			m_hexnumber=strtoul(m_calnumber,NULL,16);
			
			//检测数据中是否存在0x03,0x02,0x10值，如果存在则在此数据前面加
			if((m_hexnumber==0x03)|(m_hexnumber==0x02)|(m_hexnumber==0x10))
			{
			
				m_strcheckoutput.Insert(i+m_intpostion,m_strinsert);

				m_boolhave=TRUE;

				m_intpostion+=3;
			}
			
			i++;
		}
		
	}
	

	if (m_boolhave==FALSE)
	{
		AfxMessageBox("没有检测到0x03的值!");
	}
	else
	{
		//m_strcheckoutput=m_strdatainput;
		if (m_bytetostrresult==0xff)
		{
			AfxMessageBox("请先点击计算!");
			return ;
		}

	}
	CString m_strresult;
	BOOL m_in=FALSE;
	m_strresult.Format("%x",m_bytetostrresult);

	if((m_bytetostrresult==0x02)|(m_bytetostrresult==0x03)|(m_bytetostrresult==0x10))
	{
		int	m_resultoutputlenth=m_strcheckoutput.GetLength();
		m_strinsert.Insert(0," ");
		m_strcheckoutput.Insert(m_resultoutputlenth,m_strinsert);
		m_in=TRUE;
	}

	if (m_bytetostrresult<10)
	{
		m_strresult.Insert(0,"0");
	}
	if (m_in==FALSE)
	{
		m_strresult.Insert(0," ");
	}

	
	int	m_outputlenth=m_strcheckoutput.GetLength();
	
	m_strcheckoutput.Insert(m_outputlenth,m_strresult);
	

	
	CString m_stradd03=" 03";
	
	CString m_stradd02="02 ";
	
	int		m_intoutputlenth=m_strcheckoutput.GetLength();
	
	m_strcheckoutput.Insert(m_intoutputlenth,m_stradd03);
	
	m_strcheckoutput.Insert(0,m_stradd02);
	
	m_cscheckoutput.SetWindowText(m_strcheckoutput);
}
