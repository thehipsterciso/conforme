////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CDSAKeyValueType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CDSAKEYVALUETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CDSAKEYVALUETYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CDSAKeyValueType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDSAKeyValueType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDSAKeyValueType(CDSAKeyValueType const& init);
    
    void operator=(CDSAKeyValueType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CDSAKeyValueType); }
	MemberElement<ds::CCryptoBinaryType, conforme_mi_xmldsig_CDSAKeyValueType_P> P;
	struct P { typedef Iterator<ds::CCryptoBinaryType> iterator; };
    
	MemberElement<ds::CCryptoBinaryType, conforme_mi_xmldsig_CDSAKeyValueType_Q> Q;
	struct Q { typedef Iterator<ds::CCryptoBinaryType> iterator; };
    
	MemberElement<ds::CCryptoBinaryType, conforme_mi_xmldsig_CDSAKeyValueType_G> G;
	struct G { typedef Iterator<ds::CCryptoBinaryType> iterator; };
    
	MemberElement<ds::CCryptoBinaryType, conforme_mi_xmldsig_CDSAKeyValueType_Y> Y;
	struct Y { typedef Iterator<ds::CCryptoBinaryType> iterator; };
    
	MemberElement<ds::CCryptoBinaryType, conforme_mi_xmldsig_CDSAKeyValueType_J> J;
	struct J { typedef Iterator<ds::CCryptoBinaryType> iterator; };
    
	MemberElement<ds::CCryptoBinaryType, conforme_mi_xmldsig_CDSAKeyValueType_Seed> Seed;
	struct Seed { typedef Iterator<ds::CCryptoBinaryType> iterator; };
    
	MemberElement<ds::CCryptoBinaryType, conforme_mi_xmldsig_CDSAKeyValueType_PgenCounter> PgenCounter;
	struct PgenCounter { typedef Iterator<ds::CCryptoBinaryType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CDSAKEYVALUETYPE_H_
