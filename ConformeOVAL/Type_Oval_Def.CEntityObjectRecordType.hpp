////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CEntityObjectRecordType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYOBJECTRECORDTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYOBJECTRECORDTYPE_H_

#include "Type_Oval_Def.CEntityComplexBaseType.hpp"



namespace oval_definitions_schema
{

namespace oval_def
{	

class CEntityObjectRecordType : public ::oval_definitions_schema::oval_def::CEntityComplexBaseType
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CEntityObjectRecordType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CEntityObjectRecordType(CEntityObjectRecordType const& init);
    
    void operator=(CEntityObjectRecordType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CEntityObjectRecordType); }
	MemberElement<oval_def::CEntityObjectFieldType, conforme_mi_oval_def_CEntityObjectRecordType_field> field;
	struct field { typedef Iterator<oval_def::CEntityObjectFieldType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYOBJECTRECORDTYPE_H_
