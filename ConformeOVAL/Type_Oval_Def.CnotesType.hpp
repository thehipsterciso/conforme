////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.CnotesType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CNOTESTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CNOTESTYPE_H_

#include "Type_Oval.CNotesType.hpp"



namespace oval_definitions_schema
{

namespace oval_def
{	

class CnotesType : public ::oval_definitions_schema::oval::CNotesType
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CnotesType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CnotesType(CnotesType const& init);
    
    void operator=(CnotesType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_CnotesType); }
	MemberElement<xs::CstringType, conforme_mi_oval_def_CnotesType_note2> note2;
	struct note2 { typedef Iterator<xs::CstringType> iterator; };
    
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_CNOTESTYPE_H_
