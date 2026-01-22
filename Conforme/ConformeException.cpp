//
//  ConformeException.cpp
//  conforme
//
//  Created by Thomas on 1/15/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#include "StdAfx.hpp"
#include "Conforme.hpp"
#include "ConformeException.hpp"

namespace conforme {
    
    
    CConformeException::CConformeException(int nCode, const tstring& sMessage, bool bUserExc)
    : m_nCode(nCode), m_sMessage(sMessage), m_bUserExc(bUserExc)
    {
    }
    
    
    int CConformeException::GetCode()
    {
        return m_nCode;
    }
    
    
    const tstring& CConformeException::GetInfo() const
    {
        return m_sMessage;
    }
    
    bool CConformeException::IsUserException() const
    {
        return m_bUserExc;
    }
    
} // namespace conforme

