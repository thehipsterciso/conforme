////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CSignaturePropertiesType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNATUREPROPERTIESTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNATUREPROPERTIESTYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CSignaturePropertiesType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSignaturePropertiesType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSignaturePropertiesType(CSignaturePropertiesType const& init);
    
    void operator=(CSignaturePropertiesType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CSignaturePropertiesType); }

	MemberAttribute<string_type,conforme_mi_xmldsig_CSignaturePropertiesType_Id, 0, 0> Id;	// Id CID
	MemberElement<ds::CSignaturePropertyType, conforme_mi_xmldsig_CSignaturePropertiesType_SignatureProperty> SignatureProperty;
	struct SignatureProperty { typedef Iterator<ds::CSignaturePropertyType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNATUREPROPERTIESTYPE_H_
