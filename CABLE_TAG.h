// CABLE_TAG.h : main header file for the CABLE_TAG application
//

#if !defined(AFX_CABLE_TAG_H__18D4FBAB_B1DE_4CAC_8541_6A9F1D34E653__INCLUDED_)
#define AFX_CABLE_TAG_H__18D4FBAB_B1DE_4CAC_8541_6A9F1D34E653__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCABLE_TAGApp:
// See CABLE_TAG.cpp for the implementation of this class
//

class CCABLE_TAGApp : public CWinApp
{
public:
	CCABLE_TAGApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCABLE_TAGApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCABLE_TAGApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CABLE_TAG_H__18D4FBAB_B1DE_4CAC_8541_6A9F1D34E653__INCLUDED_)
