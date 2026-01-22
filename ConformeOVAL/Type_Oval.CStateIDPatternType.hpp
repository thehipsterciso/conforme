////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CStateIDPatternType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CSTATEIDPATTERNTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CSTATEIDPATTERNTYPE_H_



namespace oval_definitions_schema
{

namespace oval
{	

class CStateIDPatternType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CStateIDPatternType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CStateIDPatternType(CStateIDPatternType const& init);
    
    void operator=(CStateIDPatternType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_CStateIDPatternType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const string_type& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator string_type();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CSTATEIDPATTERNTYPE_H_
