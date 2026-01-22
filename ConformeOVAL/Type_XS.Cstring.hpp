////////////////////////////////////////////////////////////////////////
//
//  Type_XS.Cstring.hpp
//  ConformeOVAL
//
//  Created by Thomas on 7/3/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CSTRING_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CSTRING_H_



namespace oval_definitions_schema
{

namespace xs
{	

class Cstring : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT Cstring(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT Cstring(Cstring const& init);
    
    void operator=(Cstring const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_xmlschema_Cstring); }
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



} // namespace xs

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CSTRING_H_
