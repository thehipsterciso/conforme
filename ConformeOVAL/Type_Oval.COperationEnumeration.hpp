////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.COperationEnumeration.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_COPERATIONENUMERATION_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_COPERATIONENUMERATION_H_



namespace oval_definitions_schema
{

namespace oval
{	

class COperationEnumeration : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT COperationEnumeration(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT COperationEnumeration(COperationEnumeration const& init);
    
    void operator=(COperationEnumeration const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_COperationEnumeration); }

	enum EnumValues {
		Invalid =static_cast<unsigned int>(-1),
		k_equals = 0, // equals
		k_not_equal = 1, // not equal
		k_case_insensitive_equals = 2, // case insensitive equals
		k_case_insensitive_not_equal = 3, // case insensitive not equal
		k_greater_than = 4, // greater than
		k_less_than = 5, // less than
		k_greater_than_or_equal = 6, // greater than or equal
		k_less_than_or_equal = 7, // less than or equal
		k_bitwise_and = 8, // bitwise and
		k_bitwise_or = 9, // bitwise or
		k_pattern_match = 10, // pattern match
		k_subset_of = 11, // subset of
		k_superset_of = 12, // superset of
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

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_COPERATIONENUMERATION_H_
