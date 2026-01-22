////////////////////////////////////////////////////////////////////////
//
//  Type_XS.CintegerType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 7/3/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CINTEGERTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CINTEGERTYPE_H_



namespace oval_definitions_schema
{

namespace xs
{	

class CintegerType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CintegerType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CintegerType(CintegerType const& init);
    
    void operator=(CintegerType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmlschema_CintegerType); }
	OVAL_DEFINITIONS_SCHEMA_EXPORT void operator=(const __int64& value);
	OVAL_DEFINITIONS_SCHEMA_EXPORT operator __int64();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace xs

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_XS_CINTEGERTYPE_H_
