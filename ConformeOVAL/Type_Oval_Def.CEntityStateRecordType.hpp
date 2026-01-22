////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CEntityStateRecordType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYSTATERECORDTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYSTATERECORDTYPE_H_

#include "Type_Oval_Def.CEntityStateComplexBaseType.hpp"



namespace oval_definitions_schema
{

namespace oval_def
{	

class CEntityStateRecordType : public ::oval_definitions_schema::oval_def::CEntityStateComplexBaseType
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CEntityStateRecordType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CEntityStateRecordType(CEntityStateRecordType const& init);
    
    void operator=(CEntityStateRecordType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CEntityStateRecordType); }
	MemberElement<oval_def::CEntityStateFieldType, conforme_mi_oval_def_CEntityStateRecordType_field> field;
	struct field { typedef Iterator<oval_def::CEntityStateFieldType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYSTATERECORDTYPE_H_
