////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CSignaturePropertyType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNATUREPROPERTYTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNATUREPROPERTYTYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CSignaturePropertyType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSignaturePropertyType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSignaturePropertyType(CSignaturePropertyType const& init);
    
    void operator=(CSignaturePropertyType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CSignaturePropertyType); }

	MemberAttribute<string_type,conforme_mi_xmldsig_CSignaturePropertyType_Target, 0, 0> Target;	// Target CanyURI

	MemberAttribute<string_type,conforme_mi_xmldsig_CSignaturePropertyType_Id, 0, 0> Id;	// Id CID
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator string_type();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CSIGNATUREPROPERTYTYPE_H_
