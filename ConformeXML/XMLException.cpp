//
//  XMLException.cpp
//  conformexml
//
//  Created by Thomas on 1/15/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#include "StdAfx.hpp"
#include <Conforme/Conforme.hpp>
#include <Conforme/SchemaTypes.hpp>
#include "XMLException.hpp"

namespace conforme {
    CXmlException::CXmlException(int nCode, const tstring& sMessage)
    : CConformeException(nCode, sMessage)
    {
    }
} // namespace conforme

