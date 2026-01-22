////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.Cexternal_variableType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CEXTERNAL_VARIABLETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CEXTERNAL_VARIABLETYPE_H_

#include "Type_Oval_Def.CVariableType.hpp"



namespace oval_definitions_schema
{

namespace oval_def
{	

class Cexternal_variableType : public ::oval_definitions_schema::oval_def::CVariableType
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT Cexternal_variableType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT Cexternal_variableType(Cexternal_variableType const& init);
    
    void operator=(Cexternal_variableType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_Cexternal_variableType); }
	MemberElement<oval_def::CPossibleValueType, conforme_mi_oval_def_Cexternal_variableType_possible_value> possible_value;
	struct possible_value { typedef Iterator<oval_def::CPossibleValueType> iterator; };
    
	MemberElement<oval_def::CPossibleRestrictionType, conforme_mi_oval_def_Cexternal_variableType_possible_restriction> possible_restriction;
	struct possible_restriction { typedef Iterator<oval_def::CPossibleRestrictionType> iterator; };
    
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CEXTERNAL_VARIABLETYPE_H_
