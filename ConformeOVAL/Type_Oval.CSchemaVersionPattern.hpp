////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CSchemaVersionPattern.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CSCHEMAVERSIONPATTERN_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CSCHEMAVERSIONPATTERN_H_



namespace oval_definitions_schema
{

namespace oval
{	

class CSchemaVersionPattern : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSchemaVersionPattern(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSchemaVersionPattern(CSchemaVersionPattern const& init);
    
    void operator=(CSchemaVersionPattern const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_CSchemaVersionPattern); }
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

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CSCHEMAVERSIONPATTERN_H_
