////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CVariablesType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CVARIABLESTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CVARIABLESTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CVariablesType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CVariablesType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CVariablesType(CVariablesType const& init);
    
    void operator=(CVariablesType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CVariablesType); }
	MemberElement<oval_def::Cconstant_variableType, conforme_mi_oval_def_CVariablesType_constant_variable> constant_variable;
	struct constant_variable { typedef Iterator<oval_def::Cconstant_variableType> iterator; };
    
	MemberElement<oval_def::Cexternal_variableType, conforme_mi_oval_def_CVariablesType_external_variable> external_variable;
	struct external_variable { typedef Iterator<oval_def::Cexternal_variableType> iterator; };
    
	MemberElement<oval_def::Clocal_variableType, conforme_mi_oval_def_CVariablesType_local_variable> local_variable;
	struct local_variable { typedef Iterator<oval_def::Clocal_variableType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CVARIABLESTYPE_H_
