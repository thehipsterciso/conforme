////////////////////////////////////////////////////////////////////////
//
//  Type_Oval.CGeneratorType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CGENERATORTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CGENERATORTYPE_H_



namespace oval_definitions_schema
{

namespace oval
{	

class CGeneratorType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CGeneratorType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CGeneratorType(CGeneratorType const& init);
    
    void operator=(CGeneratorType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_CGeneratorType); }
	MemberElement<xs::CstringType, conforme_mi_oval_CGeneratorType_product_name> product_name;
	struct product_name { typedef Iterator<xs::CstringType> iterator; };
    
	MemberElement<xs::CstringType, conforme_mi_oval_CGeneratorType_product_version> product_version;
	struct product_version { typedef Iterator<xs::CstringType> iterator; };
    
	MemberElement<oval::CSchemaVersionType, conforme_mi_oval_CGeneratorType_schema_version> schema_version;
	struct schema_version { typedef Iterator<oval::CSchemaVersionType> iterator; };
    
	MemberElement<xs::CdateTimeType, conforme_mi_oval_CGeneratorType_timestamp> timestamp;
	struct timestamp { typedef Iterator<xs::CdateTimeType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace oval

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_CGENERATORTYPE_H_
