//
//  ConformeXMLAPI.h
//  conformexml
//
//  Created by Thomas on 1/15/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#pragma once
#ifndef CONFORMEXMLAPI_HPP
#define CONFORMEXMLAPI_HPP

#if !defined( __GNUC__ )
#ifdef CONFORMEXML_EXPORTS
#define CONFORMEXML_DECLSPECIFIER __declspec(dllexport)
#define CONFORMEXML_EXPIMP_TEMPLATE
#else
#define CONFORMEXML_DECLSPECIFIER __declspec(dllimport)
#define CONFORMEXML_EXPIMP_TEMPLATE extern
#endif
#else
#define CONFORMEXML_DECLSPECIFIER
#endif

#ifndef _MFC_VER
#pragma warning(disable: 4660)
#pragma warning(disable: 4231)
#pragma warning(disable: 4251)
#endif


#endif /* CONFORMEXMLAPI_HPP */

