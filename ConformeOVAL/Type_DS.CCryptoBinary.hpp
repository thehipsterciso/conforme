////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CCryptoBinary.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CCRYPTOBINARY_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CCRYPTOBINARY_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CCryptoBinary : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CCryptoBinary(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CCryptoBinary(CCryptoBinary const& init);
    
    void operator=(CCryptoBinary const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_xmldsig_CCryptoBinary); }
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



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CCRYPTOBINARY_H_
