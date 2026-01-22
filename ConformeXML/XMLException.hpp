//
//  XMLException.hpp
//  conformexml
//
//  Created by Thomas on 1/15/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#pragma once
#ifndef CONFORMEXML_XMLEXCEPTION_HPP
#define CONFORMEXML_XMLEXCEPTION_HPP

#include "ConformeXMLAPI.hpp"
#include <Conforme/ConformeException.hpp>

namespace conforme {
    
    
    class CONFORMEXML_DECLSPECIFIER CXmlException : public CConformeException
    {
    public:
        CXmlException(int nCode, const tstring& sMessage);
    };
    
    
} // namespace conforme

#endif /* CONFORMEXML_XMLEXCEPTION_HPP */

