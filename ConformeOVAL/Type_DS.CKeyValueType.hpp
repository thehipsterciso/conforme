////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CKeyValueType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CKEYVALUETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CKEYVALUETYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CKeyValueType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CKeyValueType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CKeyValueType(CKeyValueType const& init);
    
    void operator=(CKeyValueType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CKeyValueType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator string_type();
	MemberElement<ds::CDSAKeyValueType, conforme_mi_xmldsig_CKeyValueType_DSAKeyValue> DSAKeyValue;
	struct DSAKeyValue { typedef Iterator<ds::CDSAKeyValueType> iterator; };
    
	MemberElement<ds::CRSAKeyValueType, conforme_mi_xmldsig_CKeyValueType_RSAKeyValue> RSAKeyValue;
	struct RSAKeyValue { typedef Iterator<ds::CRSAKeyValueType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CKEYVALUETYPE_H_
