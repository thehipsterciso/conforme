////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CRSAKeyValueType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CRSAKEYVALUETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CRSAKEYVALUETYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CRSAKeyValueType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CRSAKeyValueType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CRSAKeyValueType(CRSAKeyValueType const& init);
    
    void operator=(CRSAKeyValueType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CRSAKeyValueType); }
	MemberElement<ds::CCryptoBinaryType, conforme_mi_xmldsig_CRSAKeyValueType_Modulus> Modulus;
	struct Modulus { typedef Iterator<ds::CCryptoBinaryType> iterator; };
    
	MemberElement<ds::CCryptoBinaryType, conforme_mi_xmldsig_CRSAKeyValueType_Exponent> Exponent;
	struct Exponent { typedef Iterator<ds::CCryptoBinaryType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CRSAKEYVALUETYPE_H_
