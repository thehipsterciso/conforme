//
//  StdAfx.h
//  conforme
//
//  Created by Thomas on 1/15/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#pragma once
#ifndef STDAFX_HPP
#define STDAFX_HPP

#if _MSC_VER < 1300
#pragma warning ( disable : 4786 )    // identifier was truncated to '255' characters in the debug information
#endif

#if !defined( __GNUC__ )

#define VC_EXTRALEAN // Exclude rarely-used stuff from Windows headers
#include <afx.h>
#include <afxwin.h>
#include <afxdisp.h>

#endif

//{{AFX_INSERT_LOCATION}}

#endif /* STDAFX_H */


