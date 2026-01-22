////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CExtendDefinitionType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CEXTENDDEFINITIONTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CEXTENDDEFINITIONTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CExtendDefinitionType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CExtendDefinitionType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CExtendDefinitionType(CExtendDefinitionType const& init);
    
    void operator=(CExtendDefinitionType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CExtendDefinitionType); }

	MemberAttribute<bool,conforme_mi_oval_def_CExtendDefinitionType_applicability_check, 0, 0> applicability_check;	// applicability_check Cboolean

	MemberAttribute<string_type,conforme_mi_oval_def_CExtendDefinitionType_definition_ref, 0, 0> definition_ref;	// definition_ref CDefinitionIDPattern

	MemberAttribute<bool,conforme_mi_oval_def_CExtendDefinitionType_negate, 0, 0> negate;	// negate Cboolean

	MemberAttribute<string_type,conforme_mi_oval_def_CExtendDefinitionType_comment, 0, 0> comment;	// comment CNonEmptyStringType
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CEXTENDDEFINITIONTYPE_H_
