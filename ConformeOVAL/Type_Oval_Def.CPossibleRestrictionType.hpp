////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CPossibleRestrictionType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CPOSSIBLERESTRICTIONTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CPOSSIBLERESTRICTIONTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CPossibleRestrictionType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CPossibleRestrictionType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CPossibleRestrictionType(CPossibleRestrictionType const& init);
    
    void operator=(CPossibleRestrictionType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CPossibleRestrictionType); }
	MemberAttribute<string_type,conforme_mi_oval_def_CPossibleRestrictionType_operator2, 1, 4> operator2;	// operator COperatorEnumeration

	MemberAttribute<string_type,conforme_mi_oval_def_CPossibleRestrictionType_hint, 0, 0> hint;	// hint Cstring
	MemberElement<oval_def::CRestrictionType, conforme_mi_oval_def_CPossibleRestrictionType_restriction> restriction;
	struct restriction { typedef Iterator<oval_def::CRestrictionType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CPOSSIBLERESTRICTIONTYPE_H_
