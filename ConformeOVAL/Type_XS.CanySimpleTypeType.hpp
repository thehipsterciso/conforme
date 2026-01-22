////////////////////////////////////////////////////////////////////////
//
//  Type_XS.CanySimpleTypeType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 7/3/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CANYSIMPLETYPETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CANYSIMPLETYPETYPE_H_



namespace oval_definitions_schema
{

namespace xs
{	

class CanySimpleTypeType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CanySimpleTypeType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CanySimpleTypeType(CanySimpleTypeType const& init);
    
    void operator=(CanySimpleTypeType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmlschema_CanySimpleTypeType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator string_type();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace xs

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CANYSIMPLETYPETYPE_H_
