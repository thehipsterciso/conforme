////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CnameType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CNAMETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CNAMETYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CnameType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CnameType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CnameType(CnameType const& init);
    
    void operator=(CnameType const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_def_CnameType); }
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

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CNAMETYPE_H_
