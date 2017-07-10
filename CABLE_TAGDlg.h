// CABLE_TAGDlg.h : header file
//

#if !defined(AFX_CABLE_TAGDLG_H__8F4D602C_3161_4473_B9FD_D14812F81BAA__INCLUDED_)
#define AFX_CABLE_TAGDLG_H__8F4D602C_3161_4473_B9FD_D14812F81BAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCABLE_TAGDlg dialog

class CCABLE_TAGDlg : public CDialog
{
// Construction
public:
	CCABLE_TAGDlg(CWnd* pParent = NULL);	// standard constructor
	BYTE m_bytetostrresult;
// Dialog Data
	//{{AFX_DATA(CCABLE_TAGDlg)
	enum { IDD = IDD_CABLE_TAG_DIALOG };
	CEdit	m_csdataoutputlenth;
	CEdit	m_cscheckoutput;
	CEdit	m_csdataoutput;
	CEdit	m_csdatainput;
	CString	m_strdatainput;
	CString	m_strdataoutput;
	CString	m_strcheckoutput;
	CString	m_strdataoutputlenth;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCABLE_TAGDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCABLE_TAGDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCaculatetag();
	afx_msg void OnCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CABLE_TAGDLG_H__8F4D602C_3161_4473_B9FD_D14812F81BAA__INCLUDED_)
