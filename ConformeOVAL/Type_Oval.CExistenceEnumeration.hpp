////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CExistenceEnumeration.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CEXISTENCEENUMERATION_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CEXISTENCEENUMERATION_H_



namespace oval_definitions_schema
{

namespace oval
{	

class CExistenceEnumeration : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CExistenceEnumeration(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CExistenceEnumeration(CExistenceEnumeration const& init);
    
    void operator=(CExistenceEnumeration const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_CExistenceEnumeration); }

	enum EnumValues {
		Invalid =static_cast<unsigned int>(-1),
		k_all_exist = 0, // all_exist
		k_any_exist = 1, // any_exist
		k_at_least_one_exists = 2, // at_least_one_exists
		k_none_exist = 3, // none_exist
		k_only_one_exists = 4, // only_one_exists
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

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CEXISTENCEENUMERATION_H_
