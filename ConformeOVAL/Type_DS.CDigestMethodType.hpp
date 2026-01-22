////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CDigestMethodType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CDIGESTMETHODTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CDIGESTMETHODTYPE_H_

namespace oval_definitions_schema
{

namespace ds
{	

class CDigestMethodType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDigestMethodType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDigestMethodType(CDigestMethodType const& init);
    
    void operator=(CDigestMethodType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CDigestMethodType); }

	MemberAttribute<string_type,conforme_mi_xmldsig_CDigestMethodType_Algorithm, 0, 0> Algorithm;	// Algorithm CanyURI
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator string_type();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CDIGESTMETHODTYPE_H_
