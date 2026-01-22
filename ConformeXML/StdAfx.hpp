//
//  StdAfx.hpp
//  conformexml
//
//  Created by Thomas on 1/15/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#pragma once
#ifndef CONFORMEXML_STDAFX_HPP
#define CONFORMEXML_STDAFX_HPP

#if _MSC_VER < 1300
#pragma warning ( disable : 4786 )    // identifier was truncated to '255' characters in the debug information
#endif

#if !defined( __GNUC__ )

#define VC_EXTRALEAN // Exclude rarely-used stuff from Windows headers
#include <afx.h>
#include <afxwin.h>
#include <afxdisp.h>

#endif

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

#ifdef _DEBUG
#pragma comment(lib, "xerces-c_3D")
#else
#pragma comment(lib, "xerces-c_3")
#endif

//{{AFX_INSERT_LOCATION}}

#endif /* CONFORMEXML_STDAFX_HPP */

