////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CX509IssuerSerialType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CX509ISSUERSERIALTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CX509ISSUERSERIALTYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CX509IssuerSerialType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CX509IssuerSerialType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CX509IssuerSerialType(CX509IssuerSerialType const& init);
    
    void operator=(CX509IssuerSerialType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CX509IssuerSerialType); }
	MemberElement<xs::CstringType, conforme_mi_xmldsig_CX509IssuerSerialType_X509IssuerName> X509IssuerName;
	struct X509IssuerName { typedef Iterator<xs::CstringType> iterator; };
    
	MemberElement<xs::CintegerType, conforme_mi_xmldsig_CX509IssuerSerialType_X509SerialNumber> X509SerialNumber;
	struct X509SerialNumber { typedef Iterator<xs::CintegerType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CX509ISSUERSERIALTYPE_H_
