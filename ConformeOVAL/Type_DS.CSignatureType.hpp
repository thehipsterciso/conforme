////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CSignatureType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNATURETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNATURETYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CSignatureType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSignatureType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSignatureType(CSignatureType const& init);
    
    void operator=(CSignatureType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CSignatureType); }

	MemberAttribute<string_type,conforme_mi_xmldsig_CSignatureType_Id, 0, 0> Id;	// Id CID
	MemberElement<ds::CSignedInfoType, conforme_mi_xmldsig_CSignatureType_SignedInfo> SignedInfo;
	struct SignedInfo { typedef Iterator<ds::CSignedInfoType> iterator; };
    
	MemberElement<ds::CSignatureValueType, conforme_mi_xmldsig_CSignatureType_SignatureValue> SignatureValue;
	struct SignatureValue { typedef Iterator<ds::CSignatureValueType> iterator; };
    
	MemberElement<ds::CKeyInfoType, conforme_mi_xmldsig_CSignatureType_KeyInfo> KeyInfo;
	struct KeyInfo { typedef Iterator<ds::CKeyInfoType> iterator; };
    
	MemberElement<ds::CObjectType, conforme_mi_xmldsig_CSignatureType_Object> Object;
	struct Object { typedef Iterator<ds::CObjectType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNATURETYPE_H_
