////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CEntityComplexBaseType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYCOMPLEXBASETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYCOMPLEXBASETYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CEntityComplexBaseType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CEntityComplexBaseType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CEntityComplexBaseType(CEntityComplexBaseType const& init);
    
    void operator=(CEntityComplexBaseType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CEntityComplexBaseType); }

	MemberAttribute<string_type,conforme_mi_oval_def_CEntityComplexBaseType_datatype, 0, 0> datatype;	// datatype CDatatypeEnumeration
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityComplexBaseType_operation, 1, 13> operation;	// operation COperationEnumeration

	MemberAttribute<bool,conforme_mi_oval_def_CEntityComplexBaseType_mask, 0, 0> mask;	// mask Cboolean

	MemberAttribute<string_type,conforme_mi_oval_def_CEntityComplexBaseType_var_ref, 0, 0> var_ref;	// var_ref CVariableIDPattern
	MemberAttribute<string_type,conforme_mi_oval_def_CEntityComplexBaseType_var_check, 1, 5> var_check;	// var_check CCheckEnumeration
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CENTITYCOMPLEXBASETYPE_H_
