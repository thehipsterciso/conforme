////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CAffectedType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CAFFECTEDTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CAFFECTEDTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CAffectedType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CAffectedType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CAffectedType(CAffectedType const& init);
    
    void operator=(CAffectedType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CAffectedType); }
	MemberAttribute<string_type,conforme_mi_oval_def_CAffectedType_family, 1, 13> family;	// family CFamilyEnumeration
	MemberElement<xs::CstringType, conforme_mi_oval_def_CAffectedType_platform> platform;
	struct platform { typedef Iterator<xs::CstringType> iterator; };
    
	MemberElement<xs::CstringType, conforme_mi_oval_def_CAffectedType_product> product;
	struct product { typedef Iterator<xs::CstringType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CAFFECTEDTYPE_H_
