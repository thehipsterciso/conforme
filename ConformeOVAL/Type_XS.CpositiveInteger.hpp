////////////////////////////////////////////////////////////////////////
//
//  Type_XS.CpositiveInteger.hpp
//  ConformeOVAL
//
//  Created by Thomas on 7/3/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CPOSITIVEINTEGER_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CPOSITIVEINTEGER_H_



namespace oval_definitions_schema
{

namespace xs
{	

class CpositiveInteger : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CpositiveInteger(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CpositiveInteger(CpositiveInteger const& init);
    
    void operator=(CpositiveInteger const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_xmlschema_CpositiveInteger); }
	void operator= (const unsigned __int64& value) 
	{
		conforme::XmlFormatter* Formatter = static_cast<conforme::XmlFormatter*>(conforme::IntegerFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator unsigned __int64()
	{
		return CastAs<unsigned __int64 >::Do(GetNode(), 0);
	}
};



} // namespace xs

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CPOSITIVEINTEGER_H_
