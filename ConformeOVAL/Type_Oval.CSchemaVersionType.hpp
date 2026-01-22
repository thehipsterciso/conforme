////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CSchemaVersionType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CSCHEMAVERSIONTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CSCHEMAVERSIONTYPE_H_

#include "Type_Oval.CSchemaVersionPatternType.hpp"



namespace oval_definitions_schema
{

namespace oval
{	

class CSchemaVersionType : public ::oval_definitions_schema::oval::CSchemaVersionPatternType
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSchemaVersionType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSchemaVersionType(CSchemaVersionType const& init);
    
    void operator=(CSchemaVersionType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_CSchemaVersionType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);

	MemberAttribute<string_type,conforme_mi_oval_CSchemaVersionType_platform, 0, 0> platform;	// platform CanyURI
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CSCHEMAVERSIONTYPE_H_
