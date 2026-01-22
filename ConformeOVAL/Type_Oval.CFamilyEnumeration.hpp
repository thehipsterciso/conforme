////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CFamilyEnumeration.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CFAMILYENUMERATION_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CFAMILYENUMERATION_H_



namespace oval_definitions_schema
{

namespace oval
{	

class CFamilyEnumeration : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CFamilyEnumeration(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CFamilyEnumeration(CFamilyEnumeration const& init);
    
    void operator=(CFamilyEnumeration const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_CFamilyEnumeration); }

	enum EnumValues {
		Invalid =static_cast<unsigned int>(-1),
		k_android = 0, // android
		k_asa = 1, // asa
		k_apple_ios = 2, // apple_ios
		k_catos = 3, // catos
		k_ios = 4, // ios
		k_iosxe = 5, // iosxe
		k_junos = 6, // junos
		k_macos = 7, // macos
		k_pixos = 8, // pixos
		k_undefined = 9, // undefined
		k_unix = 10, // unix
		k_vmware_infrastructure = 11, // vmware_infrastructure
		k_windows = 12, // windows
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



} // namespace oval

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CFAMILYENUMERATION_H_
