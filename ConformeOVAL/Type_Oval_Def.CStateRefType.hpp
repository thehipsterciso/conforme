////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CStateRefType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSTATEREFTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSTATEREFTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CStateRefType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CStateRefType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CStateRefType(CStateRefType const& init);
    
    void operator=(CStateRefType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CStateRefType); }

	MemberAttribute<string_type,conforme_mi_oval_def_CStateRefType_state_ref, 0, 0> state_ref;	// state_ref CStateIDPattern
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSTATEREFTYPE_H_
