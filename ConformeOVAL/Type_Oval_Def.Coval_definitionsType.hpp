////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.Coval_definitionsType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COVAL_DEFINITIONSTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COVAL_DEFINITIONSTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class Coval_definitionsType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT Coval_definitionsType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT Coval_definitionsType(Coval_definitionsType const& init);
    
    void operator=(Coval_definitionsType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_Coval_definitionsType); }
	MemberElement<oval::CGeneratorType, conforme_mi_oval_def_Coval_definitionsType_generator> generator;
	struct generator { typedef Iterator<oval::CGeneratorType> iterator; };
    
	MemberElement<oval_def::CDefinitionsType, conforme_mi_oval_def_Coval_definitionsType_definitions> definitions;
	struct definitions { typedef Iterator<oval_def::CDefinitionsType> iterator; };
    
	MemberElement<oval_def::CTestsType, conforme_mi_oval_def_Coval_definitionsType_tests> tests;
	struct tests { typedef Iterator<oval_def::CTestsType> iterator; };
    
	MemberElement<oval_def::CObjectsType, conforme_mi_oval_def_Coval_definitionsType_objects> objects;
	struct objects { typedef Iterator<oval_def::CObjectsType> iterator; };
    
	MemberElement<oval_def::CStatesType, conforme_mi_oval_def_Coval_definitionsType_states> states;
	struct states { typedef Iterator<oval_def::CStatesType> iterator; };
    
	MemberElement<oval_def::CVariablesType, conforme_mi_oval_def_Coval_definitionsType_variables> variables;
	struct variables { typedef Iterator<oval_def::CVariablesType> iterator; };
    
	MemberElement<ds::CSignatureType, conforme_mi_oval_def_Coval_definitionsType_Signature> Signature;
	struct Signature { typedef Iterator<ds::CSignatureType> iterator; };
    
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COVAL_DEFINITIONSTYPE_H_
