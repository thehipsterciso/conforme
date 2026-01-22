////////////////////////////////////////////////////////////////////////
//
//  Type_XS.CunsignedByte.hpp
//  ConformeOVAL
//
//  Created by Thomas on 7/3/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CUNSIGNEDBYTE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CUNSIGNEDBYTE_H_



namespace oval_definitions_schema
{

namespace xs
{	

class CunsignedByte : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CunsignedByte(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CunsignedByte(CunsignedByte const& init);
    
    void operator=(CunsignedByte const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_xmlschema_CunsignedByte); }
	void operator= (const unsigned& value) 
	{
		conforme::XmlFormatter* Formatter = static_cast<conforme::XmlFormatter*>(conforme::IntegerFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator unsigned()
	{
		return CastAs<unsigned >::Do(GetNode(), 0);
	}
};



} // namespace xs

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CUNSIGNEDBYTE_H_
