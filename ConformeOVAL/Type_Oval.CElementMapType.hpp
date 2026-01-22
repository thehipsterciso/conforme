////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CElementMapType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CELEMENTMAPTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CELEMENTMAPTYPE_H_



namespace oval_definitions_schema
{

namespace oval
{	

class CElementMapType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CElementMapType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CElementMapType(CElementMapType const& init);
    
    void operator=(CElementMapType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_CElementMapType); }
	MemberElement<oval::CElementMapItemType, conforme_mi_oval_CElementMapType_test> test;
	struct test { typedef Iterator<oval::CElementMapItemType> iterator; };
    
	MemberElement<oval::CElementMapItemType, conforme_mi_oval_CElementMapType_object> object;
	struct object { typedef Iterator<oval::CElementMapItemType> iterator; };
    
	MemberElement<oval::CElementMapItemType, conforme_mi_oval_CElementMapType_state> state;
	struct state { typedef Iterator<oval::CElementMapItemType> iterator; };
    
	MemberElement<oval::CElementMapItemType, conforme_mi_oval_CElementMapType_item> item;
	struct item { typedef Iterator<oval::CElementMapItemType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CELEMENTMAPTYPE_H_
