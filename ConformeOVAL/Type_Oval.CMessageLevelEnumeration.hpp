////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CMessageLevelEnumeration.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CMESSAGELEVELENUMERATION_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CMESSAGELEVELENUMERATION_H_



namespace oval_definitions_schema
{

namespace oval
{	

class CMessageLevelEnumeration : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CMessageLevelEnumeration(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CMessageLevelEnumeration(CMessageLevelEnumeration const& init);
    
    void operator=(CMessageLevelEnumeration const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_CMessageLevelEnumeration); }

	enum EnumValues {
		Invalid =static_cast<unsigned int>(-1),
		k_debug = 0, // debug
		k_error = 1, // error
		k_fatal = 2, // fatal
		k_info = 3, // info
		k_warning = 4, // warning
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

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CMESSAGELEVELENUMERATION_H_
