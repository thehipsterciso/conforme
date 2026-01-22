////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CUniqueFunctionType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CUNIQUEFUNCTIONTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CUNIQUEFUNCTIONTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CUniqueFunctionType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CUniqueFunctionType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CUniqueFunctionType(CUniqueFunctionType const& init);
    
    void operator=(CUniqueFunctionType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CUniqueFunctionType); }
	MemberElement<oval_def::CObjectComponentType, conforme_mi_oval_def_CUniqueFunctionType_object_component> object_component;
	struct object_component { typedef Iterator<oval_def::CObjectComponentType> iterator; };
    
	MemberElement<oval_def::CVariableComponentType, conforme_mi_oval_def_CUniqueFunctionType_variable_component> variable_component;
	struct variable_component { typedef Iterator<oval_def::CVariableComponentType> iterator; };
    
	MemberElement<oval_def::CLiteralComponentType, conforme_mi_oval_def_CUniqueFunctionType_literal_component> literal_component;
	struct literal_component { typedef Iterator<oval_def::CLiteralComponentType> iterator; };
    
	MemberElement<oval_def::CArithmeticFunctionType, conforme_mi_oval_def_CUniqueFunctionType_arithmetic> arithmetic;
	struct arithmetic { typedef Iterator<oval_def::CArithmeticFunctionType> iterator; };
    
	MemberElement<oval_def::CBeginFunctionType, conforme_mi_oval_def_CUniqueFunctionType_begin> begin;
	struct begin { typedef Iterator<oval_def::CBeginFunctionType> iterator; };
    
	MemberElement<oval_def::CConcatFunctionType, conforme_mi_oval_def_CUniqueFunctionType_concat> concat;
	struct concat { typedef Iterator<oval_def::CConcatFunctionType> iterator; };
    
	MemberElement<oval_def::CEndFunctionType, conforme_mi_oval_def_CUniqueFunctionType_end> end;
	struct end { typedef Iterator<oval_def::CEndFunctionType> iterator; };
    
	MemberElement<oval_def::CEscapeRegexFunctionType, conforme_mi_oval_def_CUniqueFunctionType_escape_regex> escape_regex;
	struct escape_regex { typedef Iterator<oval_def::CEscapeRegexFunctionType> iterator; };
    
	MemberElement<oval_def::CSplitFunctionType, conforme_mi_oval_def_CUniqueFunctionType_split> split;
	struct split { typedef Iterator<oval_def::CSplitFunctionType> iterator; };
    
	MemberElement<oval_def::CSubstringFunctionType, conforme_mi_oval_def_CUniqueFunctionType_substring> substring;
	struct substring { typedef Iterator<oval_def::CSubstringFunctionType> iterator; };
    
	MemberElement<oval_def::CTimeDifferenceFunctionType, conforme_mi_oval_def_CUniqueFunctionType_time_difference> time_difference;
	struct time_difference { typedef Iterator<oval_def::CTimeDifferenceFunctionType> iterator; };
    
	MemberElement<oval_def::CRegexCaptureFunctionType, conforme_mi_oval_def_CUniqueFunctionType_regex_capture> regex_capture;
	struct regex_capture { typedef Iterator<oval_def::CRegexCaptureFunctionType> iterator; };
    
	MemberElement<oval_def::CUniqueFunctionType, conforme_mi_oval_def_CUniqueFunctionType_unique> unique;
	struct unique { typedef Iterator<oval_def::CUniqueFunctionType> iterator; };
    
	MemberElement<oval_def::CCountFunctionType, conforme_mi_oval_def_CUniqueFunctionType_count> count;
	struct count { typedef Iterator<oval_def::CCountFunctionType> iterator; };
    
	MemberElement<oval_def::CGlobToRegexFunctionType, conforme_mi_oval_def_CUniqueFunctionType_glob_to_regex> glob_to_regex;
	struct glob_to_regex { typedef Iterator<oval_def::CGlobToRegexFunctionType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CUNIQUEFUNCTIONTYPE_H_
