////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CReferenceType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CREFERENCETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CREFERENCETYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CReferenceType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CReferenceType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CReferenceType(CReferenceType const& init);
    
    void operator=(CReferenceType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CReferenceType); }

	MemberAttribute<string_type,conforme_mi_xmldsig_CReferenceType_Id, 0, 0> Id;	// Id CID

	MemberAttribute<string_type,conforme_mi_xmldsig_CReferenceType_URI, 0, 0> URI;	// URI CanyURI

	MemberAttribute<string_type,conforme_mi_xmldsig_CReferenceType_Type, 0, 0> Type;	// Type CanyURI
	MemberElement<ds::CTransformsType, conforme_mi_xmldsig_CReferenceType_Transforms> Transforms;
	struct Transforms { typedef Iterator<ds::CTransformsType> iterator; };
    
	MemberElement<ds::CDigestMethodType, conforme_mi_xmldsig_CReferenceType_DigestMethod> DigestMethod;
	struct DigestMethod { typedef Iterator<ds::CDigestMethodType> iterator; };
    
	MemberElement<ds::CDigestValueTypeType, conforme_mi_xmldsig_CReferenceType_DigestValue> DigestValue;
	struct DigestValue { typedef Iterator<ds::CDigestValueTypeType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CREFERENCETYPE_H_
