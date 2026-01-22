////////////////////////////////////////////////////////////////////////
//
//  Type_XS.ChexBinary.hpp
//  ConformeOVAL
//
//  Created by Thomas on 7/3/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CHEXBINARY_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CHEXBINARY_H_



namespace oval_definitions_schema
{

namespace xs
{	

class ChexBinary : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT ChexBinary(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT ChexBinary(ChexBinary const& init);
    
    void operator=(ChexBinary const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_xmlschema_ChexBinary); }
	void operator= (const std::vector<unsigned char>& value) 
	{
		conforme::XmlFormatter* Formatter = static_cast<conforme::XmlFormatter*>(conforme::HexBinaryFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator std::vector<unsigned char>()
	{
		return CastAs<std::vector<unsigned char> >::Do(GetNode(), 0);
	}
};



} // namespace xs

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CHEXBINARY_H_
