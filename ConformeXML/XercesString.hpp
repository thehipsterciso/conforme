//
//  XercesString.hpp
//  conformexml
//
//  Created by Thomas on 1/15/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#pragma once
#ifndef CONFORME_XERCESSTRING_HPP
#define CONFORME_XERCESSTRING_HPP

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <xercesc/framework/Wrapper4InputSource.hpp>
#include <xercesc/framework/MemBufFormatTarget.hpp>

typedef std::basic_string<XMLCh> XercesString;
#if defined(UNICODE) || defined(_UNICODE)
// actually should be if sizeof(XmlCh) == sizeof(char_type), but PP cannot determine
class XercesStringTemp
{
    XercesString s;
public:
    XercesStringTemp(const string_type& str) : s(str.begin(), str.end()) {}
    XercesStringTemp(const char_type* str)
    {
        string_type tmpStr( str ? str : L"");
        s = XercesString( tmpStr.begin(), tmpStr.end());
    }
    
    operator const XMLCh*() const { return s.c_str(); }
};

#else

class XercesStringTemp
{
    XercesString s;
    XMLCh* mBuf;
public:
    XercesStringTemp(const string_type& str)
    {
        mBuf = xercesc::XMLString::transcode(str.c_str());
        s = XercesString( mBuf);
    }
    XercesStringTemp(const char_type* str)
    {
        mBuf = xercesc::XMLString::transcode(str);
        s = XercesString( mBuf);
    }
    virtual ~XercesStringTemp() {
        xercesc::XMLString::release( &mBuf);
    }
    operator const XMLCh*() const { return s.c_str(); }
};
#endif

class XercesUnstringTemp
{
    string_type s;
public:
    XercesUnstringTemp(const XMLCh* pxstr)  : s( _T(""))
    {
        if( pxstr != NULL)
        {
            XercesString xstr( pxstr);
            s = string_type( xstr.begin(), xstr.end());
        }
    }
    ~XercesUnstringTemp() {}
    
    operator const string_type&() const { return s; }
};

#endif /* CONFORME_XERCESSTRING_HPP */

