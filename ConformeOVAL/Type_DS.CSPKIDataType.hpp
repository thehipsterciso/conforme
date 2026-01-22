////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CSPKIDataType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSPKIDATATYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSPKIDATATYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CSPKIDataType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSPKIDataType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSPKIDataType(CSPKIDataType const& init);
    
    void operator=(CSPKIDataType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CSPKIDataType); }
	MemberElement<xs::Cbase64BinaryType, conforme_mi_xmldsig_CSPKIDataType_SPKISexp> SPKISexp;
	struct SPKISexp { typedef Iterator<xs::Cbase64BinaryType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSPKIDATATYPE_H_
