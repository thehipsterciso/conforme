////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CCryptoBinaryType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CCRYPTOBINARYTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CCRYPTOBINARYTYPE_H_

namespace oval_definitions_schema
{

namespace ds
{	

class CCryptoBinaryType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CCryptoBinaryType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CCryptoBinaryType(CCryptoBinaryType const& init);
    
    void operator=(CCryptoBinaryType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CCryptoBinaryType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const std::vector<unsigned char>& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator std::vector<unsigned char>();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CCRYPTOBINARYTYPE_H_
