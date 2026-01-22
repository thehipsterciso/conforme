////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CObjectType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_COBJECTTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_COBJECTTYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CObjectType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CObjectType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CObjectType(CObjectType const& init);
    
    void operator=(CObjectType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CObjectType); }

	MemberAttribute<string_type,conforme_mi_xmldsig_CObjectType_Id, 0, 0> Id;	// Id CID

	MemberAttribute<string_type,conforme_mi_xmldsig_CObjectType_MimeType, 0, 0> MimeType;	// MimeType Cstring

	MemberAttribute<string_type,conforme_mi_xmldsig_CObjectType_Encoding, 0, 0> Encoding;	// Encoding CanyURI
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator string_type();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_COBJECTTYPE_H_
