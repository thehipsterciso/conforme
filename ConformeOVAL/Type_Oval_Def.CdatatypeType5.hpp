////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CDatatypeType5.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDATATYPETYPE5_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDATATYPETYPE5_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CdatatypeType5 : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CdatatypeType5(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CdatatypeType5(CdatatypeType5 const& init);
    
    void operator=(CdatatypeType5 const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_def_CdatatypeType5); }

	enum EnumValues {
		Invalid =static_cast<unsigned int>(-1),
		k_ipv4_address = 0, // ipv4_address
		k_ipv6_address = 1, // ipv6_address
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

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDATATYPETYPE5_H_
