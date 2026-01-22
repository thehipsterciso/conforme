////////////////////////////////////////////////////////////////////////
//
//  Type_XS.CstringType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 7/3/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CSTRINGTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CSTRINGTYPE_H_



namespace oval_definitions_schema
{

namespace xs
{	

class CstringType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CstringType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CstringType(CstringType const& init);
    
    void operator=(CstringType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmlschema_CstringType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator string_type();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace xs

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CSTRINGTYPE_H_
