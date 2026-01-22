////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CNotesType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CNOTESTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CNOTESTYPE_H_



namespace oval_definitions_schema
{

namespace oval
{	

class CNotesType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CNotesType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CNotesType(CNotesType const& init);
    
    void operator=(CNotesType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_CNotesType); }
	MemberElement<xs::CstringType, conforme_mi_oval_CNotesType_note> note;
	struct note { typedef Iterator<xs::CstringType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CNOTESTYPE_H_
