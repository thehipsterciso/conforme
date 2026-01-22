////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CPGPDataType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CPGPDATATYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CPGPDATATYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CPGPDataType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CPGPDataType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CPGPDataType(CPGPDataType const& init);
    
	void operator=(CPGPDataType const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_xmldsig_CPGPDataType); }
	MemberElement<xs::Cbase64BinaryType, conforme_mi_xmldsig_CPGPDataType_PGPKeyID> PGPKeyID;
	struct PGPKeyID { typedef Iterator<xs::Cbase64BinaryType> iterator; };
    
	MemberElement<xs::Cbase64BinaryType, conforme_mi_xmldsig_CPGPDataType_PGPKeyPacket> PGPKeyPacket;
	struct PGPKeyPacket { typedef Iterator<xs::Cbase64BinaryType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CPGPDATATYPE_H_
