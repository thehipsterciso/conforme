////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CObjectsType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COBJECTSTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COBJECTSTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CObjectsType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CObjectsType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CObjectsType(CObjectsType const& init);
    
    void operator=(CObjectsType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CObjectsType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COBJECTSTYPE_H_
