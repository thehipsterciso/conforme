////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CCheckEnumeration.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CCHECKENUMERATION_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CCHECKENUMERATION_H_



namespace oval_definitions_schema
{

namespace oval
{	

class CCheckEnumeration : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CCheckEnumeration(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CCheckEnumeration(CCheckEnumeration const& init);
    
    void operator=(CCheckEnumeration const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_CCheckEnumeration); }

	enum EnumValues {
		Invalid =static_cast<unsigned int>(-1),
		k_all = 0, // all
		k_at_least_one = 1, // at least one
		k_none_exist = 2, // none exist
		k_none_satisfy = 3, // none satisfy
		k_only_one = 4, // only one
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

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CCHECKENUMERATION_H_
