////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CX509DataType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CX509DATATYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CX509DATATYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CX509DataType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CX509DataType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CX509DataType(CX509DataType const& init);
    
    void operator=(CX509DataType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CX509DataType); }
	MemberElement<ds::CX509IssuerSerialType, conforme_mi_xmldsig_CX509DataType_X509IssuerSerial> X509IssuerSerial;
	struct X509IssuerSerial { typedef Iterator<ds::CX509IssuerSerialType> iterator; };
    
	MemberElement<xs::Cbase64BinaryType, conforme_mi_xmldsig_CX509DataType_X509SKI> X509SKI;
	struct X509SKI { typedef Iterator<xs::Cbase64BinaryType> iterator; };
    
	MemberElement<xs::CstringType, conforme_mi_xmldsig_CX509DataType_X509SubjectName> X509SubjectName;
	struct X509SubjectName { typedef Iterator<xs::CstringType> iterator; };
    
	MemberElement<xs::Cbase64BinaryType, conforme_mi_xmldsig_CX509DataType_X509Certificate> X509Certificate;
	struct X509Certificate { typedef Iterator<xs::Cbase64BinaryType> iterator; };
    
	MemberElement<xs::Cbase64BinaryType, conforme_mi_xmldsig_CX509DataType_X509CRL> X509CRL;
	struct X509CRL { typedef Iterator<xs::Cbase64BinaryType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CX509DATATYPE_H_
