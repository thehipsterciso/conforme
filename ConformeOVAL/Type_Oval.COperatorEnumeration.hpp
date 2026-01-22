////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.COperatorEnumeration.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_COPERATORENUMERATION_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_COPERATORENUMERATION_H_



namespace oval_definitions_schema
{

namespace oval
{	

class COperatorEnumeration : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT COperatorEnumeration(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT COperatorEnumeration(COperatorEnumeration const& init);
    
    void operator=(COperatorEnumeration const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_COperatorEnumeration); }

	enum EnumValues {
		Invalid = static_cast<unsigned int>(-1),
		k_AND = 0, // AND
		k_ONE = 1, // ONE
		k_OR = 2, // OR
		k_XOR = 3, // XOR
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

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_COPERATORENUMERATION_H_
