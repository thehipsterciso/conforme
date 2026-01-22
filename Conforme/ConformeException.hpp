//
//  ConformeException.hpp
//  conforme
//
//  Created by Thomas on 1/15/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#pragma once
#ifndef CONFORMEEXCEPTION_HPP
#define CONFORMEEXCEPTION_HPP

namespace conforme {
    
    
    class CONFORME_DECLSPECIFIER CConformeException
    {
    public:
        typedef enum
        {
            eError1,
            eError2,
            eDatabaseError,
        } ECode;
        
        CConformeException(int nCode, const tstring& sMessage, bool bUserExc = false);
        int GetCode();
        const tstring& GetInfo() const;
        bool IsUserException() const;
        
    protected:
        int        m_nCode;
        tstring    m_sMessage;
        bool m_bUserExc;
    };
    
    ////////////////////////////////////////////////////////////////////////
    //
    //  Utility functions and templates
    //
    ////////////////////////////////////////////////////////////////////////
    
    template<typename TValue>
    TValue InRangeInt(TValue nValue, CONFORME_INT64 nMin, CONFORME_INT64 nMax)
    {
        if( nValue < nMin || nValue > nMax )
            throw CConformeException(CConformeException::eError1, _T("Out of range!"));
        return nValue;
    }
    
    
    template<typename TValue>
    TValue InRangeDbl(TValue nValue, const double nPosMin, const double nPosMax)
    {
        TValue nTmpValue = nValue;
        if( nTmpValue == 0 )
            return nValue;
        if( nTmpValue < 0 )
            nTmpValue = -nTmpValue;
        if( nTmpValue >= nPosMin  &&  nTmpValue <= nPosMax )
            return nValue;
        throw CConformeException(CConformeException::eError1, _T("Out of range!"));
    }
    
} // namespace conforme

#endif /* CONFORMEEXCEPTION_H */

