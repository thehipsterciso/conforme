////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CDefinitionIDPattern.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CDEFINITIONIDPATTERN_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CDEFINITIONIDPATTERN_H_



namespace oval_definitions_schema
{

namespace oval
{	

class CDefinitionIDPattern : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDefinitionIDPattern(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDefinitionIDPattern(CDefinitionIDPattern const& init);
    
    void operator=(CDefinitionIDPattern const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_CDefinitionIDPattern); }
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

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CDEFINITIONIDPATTERN_H_
