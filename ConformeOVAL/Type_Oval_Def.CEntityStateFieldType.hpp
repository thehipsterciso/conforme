////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CEntityStateFieldType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYSTATEFIELDTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYSTATEFIELDTYPE_H_

#include "Type_XS.CanySimpleTypeType.hpp"



namespace oval_definitions_schema
{

namespace oval_def
{	

class CEntityStateFieldType : public ::oval_definitions_schema::xs::CanySimpleTypeType
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CEntityStateFieldType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CEntityStateFieldType(CEntityStateFieldType const& init);
    
    void operator=(CEntityStateFieldType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CEntityStateFieldType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);

	MemberAttribute<string_type,conforme_mi_oval_def_CEntityStateFieldType_name, 0, 0> name;	// name CnameType2

	MemberAttribute<string_type,conforme_mi_oval_def_CEntityStateFieldType_datatype, 0, 0> datatype;	// datatype CDatatypeEnumeration
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityStateFieldType_operation, 1, 13> operation;	// operation COperationEnumeration

	MemberAttribute<bool,conforme_mi_oval_def_CEntityStateFieldType_mask, 0, 0> mask;	// mask Cboolean

	MemberAttribute<string_type,conforme_mi_oval_def_CEntityStateFieldType_var_ref, 0, 0> var_ref;	// var_ref CVariableIDPattern
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityStateFieldType_var_check, 1, 5> var_check;	// var_check CCheckEnumeration
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityStateFieldType_entity_check, 1, 5> entity_check;	// entity_check CCheckEnumeration
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYSTATEFIELDTYPE_H_
