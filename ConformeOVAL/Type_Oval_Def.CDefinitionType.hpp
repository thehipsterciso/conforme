////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CDefinitionType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDEFINITIONTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDEFINITIONTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CDefinitionType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDefinitionType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDefinitionType(CDefinitionType const& init);
    
    void operator=(CDefinitionType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CDefinitionType); }

	MemberAttribute<string_type,conforme_mi_oval_def_CDefinitionType_id, 0, 0> id;	// id CDefinitionIDPattern

	MemberAttribute<unsigned __int64,conforme_mi_oval_def_CDefinitionType_version, 0, 0> version;	// version CnonNegativeInteger
	MemberAttribute<string_type,conforme_mi_oval_def_CDefinitionType_class2, 1, 5> class2;	// class CClassEnumeration

	MemberAttribute<bool,conforme_mi_oval_def_CDefinitionType_deprecated, 0, 0> deprecated;	// deprecated Cboolean
	MemberElement<ds::CSignatureType, conforme_mi_oval_def_CDefinitionType_Signature> Signature;
	struct Signature { typedef Iterator<ds::CSignatureType> iterator; };
    
	MemberElement<oval_def::CMetadataType, conforme_mi_oval_def_CDefinitionType_metadata> metadata;
	struct metadata { typedef Iterator<oval_def::CMetadataType> iterator; };
    
	MemberElement<oval::CNotesType, conforme_mi_oval_def_CDefinitionType_notes> notes;
	struct notes { typedef Iterator<oval::CNotesType> iterator; };
    
	MemberElement<oval_def::CnotesType, conforme_mi_oval_def_CDefinitionType_notes2> notes2;
	struct notes2 { typedef Iterator<oval_def::CnotesType> iterator; };
    
	MemberElement<oval_def::CCriteriaType, conforme_mi_oval_def_CDefinitionType_criteria> criteria;
	struct criteria { typedef Iterator<oval_def::CCriteriaType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDEFINITIONTYPE_H_
