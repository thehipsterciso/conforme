////////////////////////////////////////////////////////////////////////
//
//  Type_XS.Cbase64Binary.hpp
//  ConformeOVAL
//
//  Created by Thomas on 7/3/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CBASE64BINARY_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CBASE64BINARY_H_



namespace oval_definitions_schema
{

namespace xs
{	

class Cbase64Binary : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT Cbase64Binary(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT Cbase64Binary(Cbase64Binary const& init);
    
    void operator=(Cbase64Binary const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_xmlschema_Cbase64Binary); }
	void operator= (const std::vector<unsigned char>& value) 
	{
		conforme::XmlFormatter* Formatter = static_cast<conforme::XmlFormatter*>(conforme::AnySimpleTypeFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator std::vector<unsigned char>()
	{
		return CastAs<std::vector<unsigned char> >::Do(GetNode(), 0);
	}
};



} // namespace xs

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CBASE64BINARY_H_
