////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CKeyInfoType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CKEYINFOTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CKEYINFOTYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CKeyInfoType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CKeyInfoType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CKeyInfoType(CKeyInfoType const& init);
    
    void operator=(CKeyInfoType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CKeyInfoType); }

	MemberAttribute<string_type,conforme_mi_xmldsig_CKeyInfoType_Id, 0, 0> Id;	// Id CID
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator string_type();
	MemberElement<xs::CstringType, conforme_mi_xmldsig_CKeyInfoType_KeyName> KeyName;
	struct KeyName { typedef Iterator<xs::CstringType> iterator; };
    
	MemberElement<ds::CKeyValueType, conforme_mi_xmldsig_CKeyInfoType_KeyValue> KeyValue;
	struct KeyValue { typedef Iterator<ds::CKeyValueType> iterator; };
    
	MemberElement<ds::CRetrievalMethodType, conforme_mi_xmldsig_CKeyInfoType_RetrievalMethod> RetrievalMethod;
	struct RetrievalMethod { typedef Iterator<ds::CRetrievalMethodType> iterator; };
    
	MemberElement<ds::CX509DataType, conforme_mi_xmldsig_CKeyInfoType_X509Data> X509Data;
	struct X509Data { typedef Iterator<ds::CX509DataType> iterator; };
    
	MemberElement<ds::CPGPDataType, conforme_mi_xmldsig_CKeyInfoType_PGPData> PGPData;
	struct PGPData { typedef Iterator<ds::CPGPDataType> iterator; };
    
	MemberElement<ds::CSPKIDataType, conforme_mi_xmldsig_CKeyInfoType_SPKIData> SPKIData;
	struct SPKIData { typedef Iterator<ds::CSPKIDataType> iterator; };
    
	MemberElement<xs::CstringType, conforme_mi_xmldsig_CKeyInfoType_MgmtData> MgmtData;
	struct MgmtData { typedef Iterator<xs::CstringType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CKEYINFOTYPE_H_
