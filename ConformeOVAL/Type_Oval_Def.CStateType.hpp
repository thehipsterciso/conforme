////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CStateType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSTATETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSTATETYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CStateType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CStateType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CStateType(CStateType const& init);
    
    void operator=(CStateType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CStateType); }

	MemberAttribute<string_type,conforme_mi_oval_def_CStateType_id, 0, 0> id;	// id CStateIDPattern

	MemberAttribute<unsigned __int64,conforme_mi_oval_def_CStateType_version, 0, 0> version;	// version CnonNegativeInteger
	MemberAttribute<string_type,conforme_mi_oval_def_CStateType_operator2, 1, 4> operator2;	// operator COperatorEnumeration

	MemberAttribute<string_type,conforme_mi_oval_def_CStateType_comment, 0, 0> comment;	// comment CNonEmptyStringType

	MemberAttribute<bool,conforme_mi_oval_def_CStateType_deprecated, 0, 0> deprecated;	// deprecated Cboolean
	MemberElement<ds::CSignatureType, conforme_mi_oval_def_CStateType_Signature> Signature;
	struct Signature { typedef Iterator<ds::CSignatureType> iterator; };
    
	MemberElement<oval::CNotesType, conforme_mi_oval_def_CStateType_notes> notes;
	struct notes { typedef Iterator<oval::CNotesType> iterator; };
    
	MemberElement<oval_def::CnotesType, conforme_mi_oval_def_CStateType_notes2> notes2;
	struct notes2 { typedef Iterator<oval_def::CnotesType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSTATETYPE_H_
