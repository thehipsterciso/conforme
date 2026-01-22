////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CSubstringFunctionType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSUBSTRINGFUNCTIONTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSUBSTRINGFUNCTIONTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CSubstringFunctionType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSubstringFunctionType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CSubstringFunctionType(CSubstringFunctionType const& init);
    
    void operator=(CSubstringFunctionType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CSubstringFunctionType); }

	MemberAttribute<int,conforme_mi_oval_def_CSubstringFunctionType_substring_start, 0, 0> substring_start;	// substring_start Cint

	MemberAttribute<int,conforme_mi_oval_def_CSubstringFunctionType_substring_length, 0, 0> substring_length;	// substring_length Cint
	MemberElement<oval_def::CObjectComponentType, conforme_mi_oval_def_CSubstringFunctionType_object_component> object_component;
	struct object_component { typedef Iterator<oval_def::CObjectComponentType> iterator; };
    
	MemberElement<oval_def::CVariableComponentType, conforme_mi_oval_def_CSubstringFunctionType_variable_component> variable_component;
	struct variable_component { typedef Iterator<oval_def::CVariableComponentType> iterator; };
    
	MemberElement<oval_def::CLiteralComponentType, conforme_mi_oval_def_CSubstringFunctionType_literal_component> literal_component;
	struct literal_component { typedef Iterator<oval_def::CLiteralComponentType> iterator; };
    
	MemberElement<oval_def::CArithmeticFunctionType, conforme_mi_oval_def_CSubstringFunctionType_arithmetic> arithmetic;
	struct arithmetic { typedef Iterator<oval_def::CArithmeticFunctionType> iterator; };
    
	MemberElement<oval_def::CBeginFunctionType, conforme_mi_oval_def_CSubstringFunctionType_begin> begin;
	struct begin { typedef Iterator<oval_def::CBeginFunctionType> iterator; };
    
	MemberElement<oval_def::CConcatFunctionType, conforme_mi_oval_def_CSubstringFunctionType_concat> concat;
	struct concat { typedef Iterator<oval_def::CConcatFunctionType> iterator; };
    
	MemberElement<oval_def::CEndFunctionType, conforme_mi_oval_def_CSubstringFunctionType_end> end;
	struct end { typedef Iterator<oval_def::CEndFunctionType> iterator; };
    
	MemberElement<oval_def::CEscapeRegexFunctionType, conforme_mi_oval_def_CSubstringFunctionType_escape_regex> escape_regex;
	struct escape_regex { typedef Iterator<oval_def::CEscapeRegexFunctionType> iterator; };
    
	MemberElement<oval_def::CSplitFunctionType, conforme_mi_oval_def_CSubstringFunctionType_split> split;
	struct split { typedef Iterator<oval_def::CSplitFunctionType> iterator; };
    
	MemberElement<oval_def::CSubstringFunctionType, conforme_mi_oval_def_CSubstringFunctionType_substring> substring;
	struct substring { typedef Iterator<oval_def::CSubstringFunctionType> iterator; };
    
	MemberElement<oval_def::CTimeDifferenceFunctionType, conforme_mi_oval_def_CSubstringFunctionType_time_difference> time_difference;
	struct time_difference { typedef Iterator<oval_def::CTimeDifferenceFunctionType> iterator; };
    
	MemberElement<oval_def::CRegexCaptureFunctionType, conforme_mi_oval_def_CSubstringFunctionType_regex_capture> regex_capture;
	struct regex_capture { typedef Iterator<oval_def::CRegexCaptureFunctionType> iterator; };
    
	MemberElement<oval_def::CUniqueFunctionType, conforme_mi_oval_def_CSubstringFunctionType_unique> unique;
	struct unique { typedef Iterator<oval_def::CUniqueFunctionType> iterator; };
    
	MemberElement<oval_def::CCountFunctionType, conforme_mi_oval_def_CSubstringFunctionType_count> count;
	struct count { typedef Iterator<oval_def::CCountFunctionType> iterator; };
    
	MemberElement<oval_def::CGlobToRegexFunctionType, conforme_mi_oval_def_CSubstringFunctionType_glob_to_regex> glob_to_regex;
	struct glob_to_regex { typedef Iterator<oval_def::CGlobToRegexFunctionType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CSUBSTRINGFUNCTIONTYPE_H_
