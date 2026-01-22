////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CSimpleDatatypeEnumeration.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CSIMPLEDATATYPEENUMERATION_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CSIMPLEDATATYPEENUMERATION_H_



namespace oval_definitions_schema
{

namespace oval
{	

class CSimpleDatatypeEnumeration : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSimpleDatatypeEnumeration(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSimpleDatatypeEnumeration(CSimpleDatatypeEnumeration const& init);
    
    void operator=(CSimpleDatatypeEnumeration const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_CSimpleDatatypeEnumeration); }

	enum EnumValues {
		Invalid =static_cast<unsigned int>(-1),
		k_binary = 0, // binary
		k_boolean = 1, // boolean
		k_evr_string = 2, // evr_string
		k_debian_evr_string = 3, // debian_evr_string
		k_fileset_revision = 4, // fileset_revision
		k_float = 5, // float
		k_ios_version = 6, // ios_version
		k_int = 7, // int
		k_ipv4_address = 8, // ipv4_address
		k_ipv6_address = 9, // ipv6_address
		k_string = 10, // string
		k_version = 11, // version
		EnumValueCount
	};
	void operator= (const string_type& value) 
	{
		conforme::XmlFormatter* Formatter = static_cast<conforme::XmlFormatter*>(conforme::AnySimpleTypeFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator string_type()
	{
		return CastAs<string_type >::Do(GetNode(), 0);
	}
};



} // namespace oval

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CSIMPLEDATATYPEENUMERATION_H_
