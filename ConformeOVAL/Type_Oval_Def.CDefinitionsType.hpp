////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CDefinitionsType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDEFINITIONSTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDEFINITIONSTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CDefinitionsType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDefinitionsType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CDefinitionsType(CDefinitionsType const& init);
    
    void operator=(CDefinitionsType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CDefinitionsType); }
	MemberElement<oval_def::CDefinitionType, conforme_mi_oval_def_CDefinitionsType_definition> definition;
	struct definition { typedef Iterator<oval_def::CDefinitionType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CDEFINITIONSTYPE_H_
