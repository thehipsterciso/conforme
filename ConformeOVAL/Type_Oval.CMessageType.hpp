////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CMessageType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CMESSAGETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CMESSAGETYPE_H_

#include "Type_XS.CstringType.hpp"



namespace oval_definitions_schema
{

namespace oval
{	

class CMessageType : public ::oval_definitions_schema::xs::CstringType
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CMessageType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CMessageType(CMessageType const& init);
    
    void operator=(CMessageType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_CMessageType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);
	MemberAttribute<string_type,conforme_mi_oval_CMessageType_level, 1, 5> level;	// level CMessageLevelEnumeration
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CMESSAGETYPE_H_
