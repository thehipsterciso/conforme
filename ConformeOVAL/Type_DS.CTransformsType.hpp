////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CTransformsType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CTRANSFORMSTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CTRANSFORMSTYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CTransformsType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CTransformsType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CTransformsType(CTransformsType const& init);
    
    void operator=(CTransformsType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CTransformsType); }
	MemberElement<ds::CTransformType, conforme_mi_xmldsig_CTransformsType_Transform> Transform;
	struct Transform { typedef Iterator<ds::CTransformType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CTRANSFORMSTYPE_H_
