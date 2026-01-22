////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CManifestType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CMANIFESTTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CMANIFESTTYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CManifestType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CManifestType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CManifestType(CManifestType const& init);
    
    void operator=(CManifestType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CManifestType); }

	MemberAttribute<string_type,conforme_mi_xmldsig_CManifestType_Id, 0, 0> Id;	// Id CID
	MemberElement<ds::CReferenceType, conforme_mi_xmldsig_CManifestType_Reference> Reference;
	struct Reference { typedef Iterator<ds::CReferenceType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CMANIFESTTYPE_H_
