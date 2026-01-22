////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CElementMapItemType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CELEMENTMAPITEMTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CELEMENTMAPITEMTYPE_H_

#include "Type_XS.CNCNameType.hpp"



namespace oval_definitions_schema
{

namespace oval
{	

class CElementMapItemType : public ::oval_definitions_schema::xs::CNCNameType
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CElementMapItemType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CElementMapItemType(CElementMapItemType const& init);
    
    void operator=(CElementMapItemType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_CElementMapItemType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);

	MemberAttribute<string_type,conforme_mi_oval_CElementMapItemType_target_namespace, 0, 0> target_namespace;	// target_namespace CanyURI
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CELEMENTMAPITEMTYPE_H_
