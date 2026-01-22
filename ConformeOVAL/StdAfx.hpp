////////////////////////////////////////////////////////////////////////
//
//  StdAfx.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#pragma once
#ifndef OVAL_DEFINITIONS_SCHEMA_STDAFX_H_INCLUDED
#define OVAL_DEFINITIONS_SCHEMA_STDAFX_H_INCLUDED

#if _MSC_VER < 1300
#pragma warning ( disable : 4786 )	// identifier was truncated to '255' characters in the debug information
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



#pragma warning ( disable : 4786 )	// identifier was truncated to '255' characters in the debug information



#include <Conforme/Conforme.hpp>

#include <Conforme/SchemaTypes.hpp>

#include <Conforme/ConformeException.hpp>

#include <Conforme/XMLException.hpp>

#include <Conforme/Node.hpp>

using namespace conforme;


//{{AFX_INSERT_LOCATION}}

#endif // OVAL_DEFINITIONS_SCHEMA_STDAFX_H_INCLUDED
