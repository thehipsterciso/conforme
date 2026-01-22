////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CEntityStateSimpleBaseType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYSTATESIMPLEBASETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYSTATESIMPLEBASETYPE_H_

#include "Type_Oval_Def.CEntitySimpleBaseType.hpp"



namespace oval_definitions_schema
{

namespace oval_def
{	

class CEntityStateSimpleBaseType : public ::oval_definitions_schema::oval_def::CEntitySimpleBaseType
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CEntityStateSimpleBaseType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CEntityStateSimpleBaseType(CEntityStateSimpleBaseType const& init);
    
    void operator=(CEntityStateSimpleBaseType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CEntityStateSimpleBaseType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityStateSimpleBaseType_entity_check, 1, 5> entity_check;	// entity_check CCheckEnumeration
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityStateSimpleBaseType_check_existence, 1, 5> check_existence;	// check_existence CExistenceEnumeration
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYSTATESIMPLEBASETYPE_H_
