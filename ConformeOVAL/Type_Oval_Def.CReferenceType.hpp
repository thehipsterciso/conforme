////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CReferenceType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CREFERENCETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CREFERENCETYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CReferenceType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CReferenceType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CReferenceType(CReferenceType const& init);
    
    void operator=(CReferenceType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CReferenceType); }

	MemberAttribute<string_type,conforme_mi_oval_def_CReferenceType_source, 0, 0> source;	// source Cstring

	MemberAttribute<string_type,conforme_mi_oval_def_CReferenceType_ref_id, 0, 0> ref_id;	// ref_id Cstring

	MemberAttribute<string_type,conforme_mi_oval_def_CReferenceType_ref_url, 0, 0> ref_url;	// ref_url CanyURI
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CREFERENCETYPE_H_
