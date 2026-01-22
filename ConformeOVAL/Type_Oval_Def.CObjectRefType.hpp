////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CObjectRefType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COBJECTREFTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COBJECTREFTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CObjectRefType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CObjectRefType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CObjectRefType(CObjectRefType const& init);
    
    void operator=(CObjectRefType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CObjectRefType); }

	MemberAttribute<string_type,conforme_mi_oval_def_CObjectRefType_object_ref, 0, 0> object_ref;	// object_ref CObjectIDPattern
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COBJECTREFTYPE_H_
