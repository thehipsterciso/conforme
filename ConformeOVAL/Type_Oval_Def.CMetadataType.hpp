////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CMetadataType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CMETADATATYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CMETADATATYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CMetadataType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CMetadataType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CMetadataType(CMetadataType const& init);
    
    void operator=(CMetadataType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CMetadataType); }
	MemberElement<xs::CstringType, conforme_mi_oval_def_CMetadataType_title> title;
	struct title { typedef Iterator<xs::CstringType> iterator; };
    
	MemberElement<oval_def::CAffectedType, conforme_mi_oval_def_CMetadataType_affected> affected;
	struct affected { typedef Iterator<oval_def::CAffectedType> iterator; };
    
	MemberElement<oval_def::CReferenceType, conforme_mi_oval_def_CMetadataType_reference> reference;
	struct reference { typedef Iterator<oval_def::CReferenceType> iterator; };
    
	MemberElement<xs::CstringType, conforme_mi_oval_def_CMetadataType_description> description;
	struct description { typedef Iterator<xs::CstringType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CMETADATATYPE_H_
