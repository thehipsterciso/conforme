////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CCriterionType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CCRITERIONTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CCRITERIONTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CCriterionType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CCriterionType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CCriterionType(CCriterionType const& init);
    
    void operator=(CCriterionType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CCriterionType); }

	MemberAttribute<bool,conforme_mi_oval_def_CCriterionType_applicability_check, 0, 0> applicability_check;	// applicability_check Cboolean

	MemberAttribute<string_type,conforme_mi_oval_def_CCriterionType_test_ref, 0, 0> test_ref;	// test_ref CTestIDPattern

	MemberAttribute<bool,conforme_mi_oval_def_CCriterionType_negate, 0, 0> negate;	// negate Cboolean

	MemberAttribute<string_type,conforme_mi_oval_def_CCriterionType_comment, 0, 0> comment;	// comment CNonEmptyStringType
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CCRITERIONTYPE_H_
