////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CDeprecatedInfoType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CDEPRECATEDINFOTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CDEPRECATEDINFOTYPE_H_



namespace oval_definitions_schema
{

namespace oval
{	

class CDeprecatedInfoType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDeprecatedInfoType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDeprecatedInfoType(CDeprecatedInfoType const& init);
    
    void operator=(CDeprecatedInfoType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_CDeprecatedInfoType); }
	MemberElement<oval::CversionType, conforme_mi_oval_CDeprecatedInfoType_version> version;
	struct version { typedef Iterator<oval::CversionType> iterator; };
    
	MemberElement<xs::CstringType, conforme_mi_oval_CDeprecatedInfoType_reason> reason;
	struct reason { typedef Iterator<xs::CstringType> iterator; };
    
	MemberElement<xs::CstringType, conforme_mi_oval_CDeprecatedInfoType_comment> comment;
	struct comment { typedef Iterator<xs::CstringType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CDEPRECATEDINFOTYPE_H_
