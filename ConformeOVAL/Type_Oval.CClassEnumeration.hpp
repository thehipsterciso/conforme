////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CClassEnumeration.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CCLASSENUMERATION_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CCLASSENUMERATION_H_



namespace oval_definitions_schema
{

namespace oval
{	

class CClassEnumeration : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CClassEnumeration(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CClassEnumeration(CClassEnumeration const& init);
    
    void operator=(CClassEnumeration const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_CClassEnumeration); }

	enum EnumValues {
		Invalid =static_cast<unsigned int>(-1),
		k_compliance = 0, // compliance
		k_inventory = 1, // inventory
		k_miscellaneous = 2, // miscellaneous
		k_patch = 3, // patch
		k_vulnerability = 4, // vulnerability
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

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CCLASSENUMERATION_H_
