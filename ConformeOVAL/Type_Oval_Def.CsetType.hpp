////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CsetType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSETTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSETTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CsetType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CsetType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CsetType(CsetType const& init);
    
    void operator=(CsetType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CsetType); }
	MemberAttribute<string_type,conforme_mi_oval_def_CsetType_set_operator, 1, 3> set_operator;	// set_operator CSetOperatorEnumeration
	MemberElement<oval_def::CsetType, conforme_mi_oval_def_CsetType_set> set;
	struct set { typedef Iterator<oval_def::CsetType> iterator; };
    
	MemberElement<oval::CObjectIDPatternType, conforme_mi_oval_def_CsetType_object_reference> object_reference;
	struct object_reference { typedef Iterator<oval::CObjectIDPatternType> iterator; };
    
	MemberElement<oval_def::CfilterType, conforme_mi_oval_def_CsetType_filter> filter;
	struct filter { typedef Iterator<oval_def::CfilterType> iterator; };
    
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSETTYPE_H_
