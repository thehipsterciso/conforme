////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CDatatypeType3.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDATATYPETYPE3_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDATATYPETYPE3_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CdatatypeType3 : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CdatatypeType3(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CdatatypeType3(CdatatypeType3 const& init);
    
    void operator=(CdatatypeType3 const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_def_CdatatypeType3); }

	enum EnumValues {
		Invalid =static_cast<unsigned int>(-1),
		k_ios_version = 0, // ios_version
		k_string = 1, // string
		EnumValueCount
	};
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

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDATATYPETYPE3_H_
