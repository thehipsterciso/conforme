////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CRetrievalMethodType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CRETRIEVALMETHODTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CRETRIEVALMETHODTYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CRetrievalMethodType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CRetrievalMethodType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CRetrievalMethodType(CRetrievalMethodType const& init);
    
    void operator=(CRetrievalMethodType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CRetrievalMethodType); }

	MemberAttribute<string_type,conforme_mi_xmldsig_CRetrievalMethodType_URI, 0, 0> URI;	// URI CanyURI

	MemberAttribute<string_type,conforme_mi_xmldsig_CRetrievalMethodType_Type, 0, 0> Type;	// Type CanyURI
	MemberElement<ds::CTransformsType, conforme_mi_xmldsig_CRetrievalMethodType_Transforms> Transforms;
	struct Transforms { typedef Iterator<ds::CTransformsType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CRETRIEVALMETHODTYPE_H_
