////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CDigestValueTypeType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//
// TODO: CORRECT "TYPETYPE" -> TYPE2 ????

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CDIGESTVALUETYPETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CDIGESTVALUETYPETYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CDigestValueTypeType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDigestValueTypeType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDigestValueTypeType(CDigestValueTypeType const& init);
    
    void operator=(CDigestValueTypeType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CDigestValueTypeType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const std::vector<unsigned char>& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator std::vector<unsigned char>();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CDIGESTVALUETYPETYPE_H_
