////////////////////////////////////////////////////////////////////////
//
//  Type_XS.Cbase64BinaryType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 7/3/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CBASE64BINARYTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CBASE64BINARYTYPE_H_



namespace oval_definitions_schema
{

namespace xs
{	

class Cbase64BinaryType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT Cbase64BinaryType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT Cbase64BinaryType(Cbase64BinaryType const& init);
    
    void operator=(Cbase64BinaryType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmlschema_Cbase64BinaryType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const std::vector<unsigned char>& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator std::vector<unsigned char>();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace xs

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CBASE64BINARYTYPE_H_
