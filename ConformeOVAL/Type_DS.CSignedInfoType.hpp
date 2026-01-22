////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CSignedInfoType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNEDINFOTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNEDINFOTYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CSignedInfoType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSignedInfoType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSignedInfoType(CSignedInfoType const& init);
    
    void operator=(CSignedInfoType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CSignedInfoType); }

	MemberAttribute<string_type,conforme_mi_xmldsig_CSignedInfoType_Id, 0, 0> Id;	// Id CID
	MemberElement<ds::CCanonicalizationMethodType, conforme_mi_xmldsig_CSignedInfoType_CanonicalizationMethod> CanonicalizationMethod;
	struct CanonicalizationMethod { typedef Iterator<ds::CCanonicalizationMethodType> iterator; };
    
	MemberElement<ds::CSignatureMethodType, conforme_mi_xmldsig_CSignedInfoType_SignatureMethod> SignatureMethod;
	struct SignatureMethod { typedef Iterator<ds::CSignatureMethodType> iterator; };
    
	MemberElement<ds::CReferenceType, conforme_mi_xmldsig_CSignedInfoType_Reference> Reference;
	struct Reference { typedef Iterator<ds::CReferenceType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNEDINFOTYPE_H_
