////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CfilterType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CFILTERTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CFILTERTYPE_H_

#include "Type_Oval.CStateIDPatternType.hpp"



namespace oval_definitions_schema
{

namespace oval_def
{	

class CfilterType : public ::oval_definitions_schema::oval::CStateIDPatternType
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CfilterType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CfilterType(CfilterType const& init);
    
    void operator=(CfilterType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CfilterType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);
	MemberAttribute<string_type,conforme_mi_oval_def_CfilterType_action, 1, 2> action;	// action CFilterActionEnumeration
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CFILTERTYPE_H_
