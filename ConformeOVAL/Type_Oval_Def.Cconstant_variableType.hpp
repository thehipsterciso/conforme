////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CConstantVariableType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CCONSTANTVARIABLETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CCONSTANTVARIABLETYPE_H_

#include "Type_Oval_Def.CVariableType.hpp"



namespace oval_definitions_schema
{

namespace oval_def
{	

class Cconstant_variableType : public ::oval_definitions_schema::oval_def::CVariableType
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT Cconstant_variableType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT Cconstant_variableType(Cconstant_variableType const& init);
    
    void operator=(Cconstant_variableType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_Cconstant_variableType); }
	MemberElement<oval_def::CValueType, conforme_mi_oval_def_Cconstant_variableType_value2> value2;
	struct value2 { typedef Iterator<oval_def::CValueType> iterator; };
    
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CCONSTANTVARIABLETYPE_H_
