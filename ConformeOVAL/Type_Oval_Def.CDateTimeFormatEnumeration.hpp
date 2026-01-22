////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CDateTimeFormatEnumeration.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDATETIMEFORMATENUMERATION_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDATETIMEFORMATENUMERATION_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CDateTimeFormatEnumeration : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDateTimeFormatEnumeration(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDateTimeFormatEnumeration(CDateTimeFormatEnumeration const& init);
    
    void operator=(CDateTimeFormatEnumeration const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_oval_def_CDateTimeFormatEnumeration); }

	enum EnumValues {
		Invalid =static_cast<unsigned int>(-1),
		k_year_month_day = 0, // year_month_day
		k_month_day_year = 1, // month_day_year
		k_day_month_year = 2, // day_month_year
		k_win_filetime = 3, // win_filetime
		k_seconds_since_epoch = 4, // seconds_since_epoch
		k_cim_datetime = 5, // cim_datetime
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

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDATETIMEFORMATENUMERATION_H_
