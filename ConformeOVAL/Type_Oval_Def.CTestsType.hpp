////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CTestsType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CTESTSTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CTESTSTYPE_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class CTestsType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CTestsType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CTestsType(CTestsType const& init);
    
    void operator=(CTestsType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CTestsType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CTESTSTYPE_H_
