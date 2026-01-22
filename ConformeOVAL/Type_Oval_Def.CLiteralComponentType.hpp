////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CLiteralComponentType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CLITERALCOMPONENTTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CLITERALCOMPONENTTYPE_H_

#include "Type_XS.CanySimpleTypeType.hpp"



namespace oval_definitions_schema
{

namespace oval_def
{	

class CLiteralComponentType : public ::oval_definitions_schema::xs::CanySimpleTypeType
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CLiteralComponentType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CLiteralComponentType(CLiteralComponentType const& init);
    
    void operator=(CLiteralComponentType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CLiteralComponentType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);
	MemberAttribute<string_type,conforme_mi_oval_def_CLiteralComponentType_datatype, 1, 12> datatype;	// datatype CSimpleDatatypeEnumeration
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CLITERALCOMPONENTTYPE_H_
