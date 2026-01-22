////////////////////////////////////////////////////////////////////////
//
//  Type_XS.CdateTimeType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 7/3/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CDATETIMETYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CDATETIMETYPE_H_



namespace oval_definitions_schema
{

namespace xs
{	

class CdateTimeType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CdateTimeType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CdateTimeType(CdateTimeType const& init);
    
    void operator=(CdateTimeType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmlschema_CdateTimeType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const conforme::DateTime& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator conforme::DateTime();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace xs

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CDATETIMETYPE_H_
