////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CEntityObjectIPAddressType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYOBJECTIPADDRESSTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYOBJECTIPADDRESSTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CEntityObjectIPAddressType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CEntityObjectIPAddressType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CEntityObjectIPAddressType(CEntityObjectIPAddressType const& init);
    
    void operator=(CEntityObjectIPAddressType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CEntityObjectIPAddressType); }
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityObjectIPAddressType_operation, 1, 13> operation;	// operation COperationEnumeration

	MemberAttribute<bool,conforme_mi_oval_def_CEntityObjectIPAddressType_mask, 0, 0> mask;	// mask Cboolean

	MemberAttribute<string_type,conforme_mi_oval_def_CEntityObjectIPAddressType_var_ref, 0, 0> var_ref;	// var_ref CVariableIDPattern
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityObjectIPAddressType_var_check, 1, 5> var_check;	// var_check CCheckEnumeration
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityObjectIPAddressType_datatype, 1, 2> datatype;	// datatype CdatatypeType2
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator string_type();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYOBJECTIPADDRESSTYPE_H_
