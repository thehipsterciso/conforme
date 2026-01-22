////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CVariableComponentType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CVARIABLECOMPONENTTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CVARIABLECOMPONENTTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CVariableComponentType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CVariableComponentType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CVariableComponentType(CVariableComponentType const& init);
    
    void operator=(CVariableComponentType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CVariableComponentType); }

	MemberAttribute<string_type,conforme_mi_oval_def_CVariableComponentType_var_ref, 0, 0> var_ref;	// var_ref CVariableIDPattern
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CVARIABLECOMPONENTTYPE_H_
