////////////////////////////////////////////////////////////////////////
//
//  Type_XS.Cinteger.hpp
//  ConformeOVAL
//
//  Created by Thomas on 7/3/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CINTEGER_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CINTEGER_H_



namespace oval_definitions_schema
{

namespace xs
{	

class Cinteger : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT Cinteger(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT Cinteger(Cinteger const& init);
    
    void operator=(Cinteger const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_xmlschema_Cinteger); }
	void operator= (const __int64& value) 
	{
		conforme::XmlFormatter* Formatter = static_cast<conforme::XmlFormatter*>(conforme::IntegerFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator __int64()
	{
		return CastAs<__int64 >::Do(GetNode(), 0);
	}
};



} // namespace xs

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CINTEGER_H_
