////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CObjectComponentType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COBJECTCOMPONENTTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COBJECTCOMPONENTTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CObjectComponentType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CObjectComponentType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CObjectComponentType(CObjectComponentType const& init);
    
    void operator=(CObjectComponentType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CObjectComponentType); }

	MemberAttribute<string_type,conforme_mi_oval_def_CObjectComponentType_object_ref, 0, 0> object_ref;	// object_ref CObjectIDPattern

	MemberAttribute<string_type,conforme_mi_oval_def_CObjectComponentType_item_field, 0, 0> item_field;	// item_field CNonEmptyStringType

	MemberAttribute<string_type,conforme_mi_oval_def_CObjectComponentType_record_field, 0, 0> record_field;	// record_field CNonEmptyStringType
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COBJECTCOMPONENTTYPE_H_
