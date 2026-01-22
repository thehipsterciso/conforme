////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CCriteriaType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CCRITERIATYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CCRITERIATYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CCriteriaType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CCriteriaType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CCriteriaType(CCriteriaType const& init);
    
    void operator=(CCriteriaType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CCriteriaType); }

	MemberAttribute<bool,conforme_mi_oval_def_CCriteriaType_applicability_check, 0, 0> applicability_check;	// applicability_check Cboolean
	MemberAttribute<string_type,conforme_mi_oval_def_CCriteriaType_operator2, 1, 4> operator2;	// operator COperatorEnumeration

	MemberAttribute<bool,conforme_mi_oval_def_CCriteriaType_negate, 0, 0> negate;	// negate Cboolean

	MemberAttribute<string_type,conforme_mi_oval_def_CCriteriaType_comment, 0, 0> comment;	// comment CNonEmptyStringType
	MemberElement<oval_def::CCriteriaType, conforme_mi_oval_def_CCriteriaType_criteria> criteria;
	struct criteria { typedef Iterator<oval_def::CCriteriaType> iterator; };
    
	MemberElement<oval_def::CCriterionType, conforme_mi_oval_def_CCriteriaType_criterion> criterion;
	struct criterion { typedef Iterator<oval_def::CCriterionType> iterator; };
    
	MemberElement<oval_def::CExtendDefinitionType, conforme_mi_oval_def_CCriteriaType_extend_definition> extend_definition;
	struct extend_definition { typedef Iterator<oval_def::CExtendDefinitionType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CCRITERIATYPE_H_
