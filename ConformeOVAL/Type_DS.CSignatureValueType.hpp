////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CSignatureValueType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNATUREVALUETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNATUREVALUETYPE_H_

#include "Type_XS.Cbase64BinaryType.hpp"



namespace oval_definitions_schema
{

namespace ds
{	

class CSignatureValueType : public ::oval_definitions_schema::xs::Cbase64BinaryType
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSignatureValueType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSignatureValueType(CSignatureValueType const& init);
    
    void operator=(CSignatureValueType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CSignatureValueType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const std::vector<unsigned char>& value);

	MemberAttribute<string_type,conforme_mi_xmldsig_CSignatureValueType_Id, 0, 0> Id;	// Id CID
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNATUREVALUETYPE_H_
