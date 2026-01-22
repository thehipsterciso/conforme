////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CSetOperatorEnumeration.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSETOPERATORENUMERATION_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSETOPERATORENUMERATION_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CSetOperatorEnumeration : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSetOperatorEnumeration(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSetOperatorEnumeration(CSetOperatorEnumeration const& init);
    
    void operator=(CSetOperatorEnumeration const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_def_CSetOperatorEnumeration); }

	enum EnumValues {
		Invalid =static_cast<unsigned int>(-1),
		k_COMPLEMENT = 0, // COMPLEMENT
		k_INTERSECTION = 1, // INTERSECTION
		k_UNION = 2, // UNION
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



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSETOPERATORENUMERATION_H_
