////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CHMACOutputLengthTypeType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//
// TODO: TYPETYPE -> TYPE2

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CHMACOUTPUTLENGTHTYPETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CHMACOUTPUTLENGTHTYPETYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CHMACOutputLengthTypeType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CHMACOutputLengthTypeType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CHMACOutputLengthTypeType(CHMACOutputLengthTypeType const& init);
    
    void operator=(CHMACOutputLengthTypeType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CHMACOutputLengthTypeType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const __int64& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator __int64();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CHMACOUTPUTLENGTHTYPETYPE_H_
