////////////////////////////////////////////////////////////////////////
//
//  Type_XS.CgMonthDay.hpp
//  ConformeOVAL
//
//  Created by Thomas on 7/3/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CGMONTHDAY_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CGMONTHDAY_H_



namespace oval_definitions_schema
{

namespace xs
{	

class CgMonthDay : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CgMonthDay(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CgMonthDay(CgMonthDay const& init);
    
    void operator=(CgMonthDay const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_xmlschema_CgMonthDay); }
	void operator= (const conforme::DateTime& value) 
	{
		conforme::XmlFormatter* Formatter = static_cast<conforme::XmlFormatter*>(conforme::GMonthDayFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator conforme::DateTime()
	{
		return CastAs<conforme::DateTime >::Do(GetNode(), 0);
	}
};



} // namespace xs

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CGMONTHDAY_H_
