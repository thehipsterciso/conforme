////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CEntityStateIPAddressType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYSTATEIPADDRESSTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYSTATEIPADDRESSTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CEntityStateIPAddressType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CEntityStateIPAddressType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CEntityStateIPAddressType(CEntityStateIPAddressType const& init);
    
    void operator=(CEntityStateIPAddressType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CEntityStateIPAddressType); }
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityStateIPAddressType_operation, 1, 13> operation;	// operation COperationEnumeration

	MemberAttribute<bool,conforme_mi_oval_def_CEntityStateIPAddressType_mask, 0, 0> mask;	// mask Cboolean

	MemberAttribute<string_type,conforme_mi_oval_def_CEntityStateIPAddressType_var_ref, 0, 0> var_ref;	// var_ref CVariableIDPattern
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityStateIPAddressType_var_check, 1, 5> var_check;	// var_check CCheckEnumeration
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityStateIPAddressType_entity_check, 1, 5> entity_check;	// entity_check CCheckEnumeration
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityStateIPAddressType_check_existence, 1, 5> check_existence;	// check_existence CExistenceEnumeration
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityStateIPAddressType_datatype, 1, 2> datatype;	// datatype CdatatypeType5
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator string_type();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYSTATEIPADDRESSTYPE_H_
