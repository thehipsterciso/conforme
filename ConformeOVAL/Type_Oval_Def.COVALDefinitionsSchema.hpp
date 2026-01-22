////////////////////////////////////////////////////////////////////////
//
//  Type_Oval_Def.Coval_definitions_schema.hpp
//  ConformeOVAL
//
//  Created by Thomas on 11/10/19.
//  Copyright © 2019 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COVAL_DEFINITIONS_SCHEMA_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COVAL_DEFINITIONS_SCHEMA_H_



namespace oval_definitions_schema
{

namespace oval_def
{	

class Coval_definitions_schema : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT Coval_definitions_schema(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT Coval_definitions_schema(Coval_definitions_schema const& init);
    
    void operator=(Coval_definitions_schema const& other) { m_node = other.m_node; }
    
	static conforme::meta::ComplexType StaticInfo() { return conforme::meta::ComplexType(types + conforme_ti_oval_def_Coval_definitions_schema); }
	MemberElement<oval::CDeprecatedInfoType, conforme_mi_oval_def_Coval_definitions_schema_deprecated_info> deprecated_info;
	struct deprecated_info { typedef Iterator<oval::CDeprecatedInfoType> iterator; };
    
	MemberElement<oval::CElementMapType, conforme_mi_oval_def_Coval_definitions_schema_element_mapping> element_mapping;
	struct element_mapping { typedef Iterator<oval::CElementMapType> iterator; };
    
	MemberElement<oval::CNotesType, conforme_mi_oval_def_Coval_definitions_schema_notes> notes;
	struct notes { typedef Iterator<oval::CNotesType> iterator; };
    
	MemberElement<oval_def::Cconstant_variableType, conforme_mi_oval_def_Coval_definitions_schema_constant_variable> constant_variable;
	struct constant_variable { typedef Iterator<oval_def::Cconstant_variableType> iterator; };
    
	MemberElement<oval_def::CDefinitionType, conforme_mi_oval_def_Coval_definitions_schema_definition> definition;
	struct definition { typedef Iterator<oval_def::CDefinitionType> iterator; };
    
	MemberElement<oval_def::Cexternal_variableType, conforme_mi_oval_def_Coval_definitions_schema_external_variable> external_variable;
	struct external_variable { typedef Iterator<oval_def::Cexternal_variableType> iterator; };
    
	MemberElement<oval_def::CfilterType, conforme_mi_oval_def_Coval_definitions_schema_filter> filter;
	struct filter { typedef Iterator<oval_def::CfilterType> iterator; };
    
	MemberElement<oval_def::Clocal_variableType, conforme_mi_oval_def_Coval_definitions_schema_local_variable> local_variable;
	struct local_variable { typedef Iterator<oval_def::Clocal_variableType> iterator; };
    
	MemberElement<oval_def::CnotesType, conforme_mi_oval_def_Coval_definitions_schema_notes2> notes2;
	struct notes2 { typedef Iterator<oval_def::CnotesType> iterator; };
    
	MemberElement<oval_def::CObjectType, conforme_mi_oval_def_Coval_definitions_schema_object> object;
	struct object { typedef Iterator<oval_def::CObjectType> iterator; };
    
	MemberElement<oval_def::Coval_definitionsType, conforme_mi_oval_def_Coval_definitions_schema_oval_definitions> oval_definitions;
	struct oval_definitions { typedef Iterator<oval_def::Coval_definitionsType> iterator; };
    
	MemberElement<oval_def::CsetType, conforme_mi_oval_def_Coval_definitions_schema_set> set;
	struct set { typedef Iterator<oval_def::CsetType> iterator; };
    
	MemberElement<oval_def::CStateType, conforme_mi_oval_def_Coval_definitions_schema_state> state;
	struct state { typedef Iterator<oval_def::CStateType> iterator; };
    
	MemberElement<oval_def::CTestType, conforme_mi_oval_def_Coval_definitions_schema_test> test;
	struct test { typedef Iterator<oval_def::CTestType> iterator; };
    
	MemberElement<oval_def::CVariableType, conforme_mi_oval_def_Coval_definitions_schema_variable> variable;
	struct variable { typedef Iterator<oval_def::CVariableType> iterator; };
    
	MemberElement<ds::CCanonicalizationMethodType, conforme_mi_oval_def_Coval_definitions_schema_CanonicalizationMethod> CanonicalizationMethod;
	struct CanonicalizationMethod { typedef Iterator<ds::CCanonicalizationMethodType> iterator; };
    
	MemberElement<ds::CDSAKeyValueType, conforme_mi_oval_def_Coval_definitions_schema_DSAKeyValue> DSAKeyValue;
	struct DSAKeyValue { typedef Iterator<ds::CDSAKeyValueType> iterator; };
    
	MemberElement<ds::CDigestMethodType, conforme_mi_oval_def_Coval_definitions_schema_DigestMethod> DigestMethod;
	struct DigestMethod { typedef Iterator<ds::CDigestMethodType> iterator; };
    
	MemberElement<ds::CDigestValueTypeType, conforme_mi_oval_def_Coval_definitions_schema_DigestValue> DigestValue;
	struct DigestValue { typedef Iterator<ds::CDigestValueTypeType> iterator; };
    
	MemberElement<ds::CKeyInfoType, conforme_mi_oval_def_Coval_definitions_schema_KeyInfo> KeyInfo;
	struct KeyInfo { typedef Iterator<ds::CKeyInfoType> iterator; };
    
	MemberElement<xs::CstringType, conforme_mi_oval_def_Coval_definitions_schema_KeyName> KeyName;
	struct KeyName { typedef Iterator<xs::CstringType> iterator; };
    
	MemberElement<ds::CKeyValueType, conforme_mi_oval_def_Coval_definitions_schema_KeyValue> KeyValue;
	struct KeyValue { typedef Iterator<ds::CKeyValueType> iterator; };
    
	MemberElement<ds::CManifestType, conforme_mi_oval_def_Coval_definitions_schema_Manifest> Manifest;
	struct Manifest { typedef Iterator<ds::CManifestType> iterator; };
    
	MemberElement<xs::CstringType, conforme_mi_oval_def_Coval_definitions_schema_MgmtData> MgmtData;
	struct MgmtData { typedef Iterator<xs::CstringType> iterator; };
    
	MemberElement<ds::CObjectType, conforme_mi_oval_def_Coval_definitions_schema_Object2> Object2;
	struct Object2 { typedef Iterator<ds::CObjectType> iterator; };
    
	MemberElement<ds::CPGPDataType, conforme_mi_oval_def_Coval_definitions_schema_PGPData> PGPData;
	struct PGPData { typedef Iterator<ds::CPGPDataType> iterator; };
    
	MemberElement<ds::CRSAKeyValueType, conforme_mi_oval_def_Coval_definitions_schema_RSAKeyValue> RSAKeyValue;
	struct RSAKeyValue { typedef Iterator<ds::CRSAKeyValueType> iterator; };
    
	MemberElement<ds::CReferenceType, conforme_mi_oval_def_Coval_definitions_schema_Reference> Reference;
	struct Reference { typedef Iterator<ds::CReferenceType> iterator; };
    
	MemberElement<ds::CRetrievalMethodType, conforme_mi_oval_def_Coval_definitions_schema_RetrievalMethod> RetrievalMethod;
	struct RetrievalMethod { typedef Iterator<ds::CRetrievalMethodType> iterator; };
    
	MemberElement<ds::CSPKIDataType, conforme_mi_oval_def_Coval_definitions_schema_SPKIData> SPKIData;
	struct SPKIData { typedef Iterator<ds::CSPKIDataType> iterator; };
    
	MemberElement<ds::CSignatureType, conforme_mi_oval_def_Coval_definitions_schema_Signature> Signature;
	struct Signature { typedef Iterator<ds::CSignatureType> iterator; };
    
	MemberElement<ds::CSignatureMethodType, conforme_mi_oval_def_Coval_definitions_schema_SignatureMethod> SignatureMethod;
	struct SignatureMethod { typedef Iterator<ds::CSignatureMethodType> iterator; };
    
	MemberElement<ds::CSignaturePropertiesType, conforme_mi_oval_def_Coval_definitions_schema_SignatureProperties> SignatureProperties;
	struct SignatureProperties { typedef Iterator<ds::CSignaturePropertiesType> iterator; };
    
	MemberElement<ds::CSignaturePropertyType, conforme_mi_oval_def_Coval_definitions_schema_SignatureProperty> SignatureProperty;
	struct SignatureProperty { typedef Iterator<ds::CSignaturePropertyType> iterator; };
    
	MemberElement<ds::CSignatureValueType, conforme_mi_oval_def_Coval_definitions_schema_SignatureValue> SignatureValue;
	struct SignatureValue { typedef Iterator<ds::CSignatureValueType> iterator; };
    
	MemberElement<ds::CSignedInfoType, conforme_mi_oval_def_Coval_definitions_schema_SignedInfo> SignedInfo;
	struct SignedInfo { typedef Iterator<ds::CSignedInfoType> iterator; };
    
	MemberElement<ds::CTransformType, conforme_mi_oval_def_Coval_definitions_schema_Transform> Transform;
	struct Transform { typedef Iterator<ds::CTransformType> iterator; };
    
	MemberElement<ds::CTransformsType, conforme_mi_oval_def_Coval_definitions_schema_Transforms> Transforms;
	struct Transforms { typedef Iterator<ds::CTransformsType> iterator; };
    
	MemberElement<ds::CX509DataType, conforme_mi_oval_def_Coval_definitions_schema_X509Data> X509Data;
	struct X509Data { typedef Iterator<ds::CX509DataType> iterator; };
    
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetXsiType();

	// document functions
	OVAL_DEFINITIONS_SCHEMA_EXPORT static Coval_definitions_schema LoadFromFile(const string_type& fileName);
	OVAL_DEFINITIONS_SCHEMA_EXPORT static Coval_definitions_schema LoadFromString(const string_type& xml);
	OVAL_DEFINITIONS_SCHEMA_EXPORT static Coval_definitions_schema LoadFromBinary(const std::vector<unsigned char>& data);
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SaveToFile( const string_type& fileName, bool prettyPrint);
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SaveToFile( const string_type& fileName, bool prettyPrint, bool omitXmlDecl);
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SaveToFile( const string_type& fileName, bool prettyPrint, const string_type& encoding);
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SaveToFile( const string_type& fileName, bool prettyPrint, bool omitXmlDecl, const string_type& encoding);
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SaveToFile( const string_type& fileName, bool prettyPrint, const string_type& encoding, bool bBigEndian, bool bBOM);
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SaveToFile( const string_type& fileName, bool prettyPrint, bool omitXmlDecl, const string_type& encoding, bool bBigEndian, bool bBOM);

	OVAL_DEFINITIONS_SCHEMA_EXPORT void SaveToFile( const string_type& fileName, bool prettyPrint, const string_type& encoding, const string_type& lineend);
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SaveToFile( const string_type& fileName, bool prettyPrint, bool omitXmlDecl, const string_type& encoding, const string_type& lineend);
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SaveToFile( const string_type& fileName, bool prettyPrint, const string_type& encoding, bool bBigEndian, bool bBOM, const string_type& lineend);
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SaveToFile( const string_type& fileName, bool prettyPrint, bool omitXmlDecl, const string_type& encoding, bool bBigEndian, bool bBOM, const string_type& lineend);

	OVAL_DEFINITIONS_SCHEMA_EXPORT string_type SaveToString(bool prettyPrint);
	OVAL_DEFINITIONS_SCHEMA_EXPORT string_type SaveToString(bool prettyPrint, bool omitXmlDecl);
	OVAL_DEFINITIONS_SCHEMA_EXPORT std::vector<unsigned char> SaveToBinary(bool prettyPrint);
	OVAL_DEFINITIONS_SCHEMA_EXPORT std::vector<unsigned char> SaveToBinary(bool prettyPrint, const string_type& encoding);
	OVAL_DEFINITIONS_SCHEMA_EXPORT std::vector<unsigned char> SaveToBinary(bool prettyPrint, const string_type& encoding, bool bBigEndian, bool bBOM);

	OVAL_DEFINITIONS_SCHEMA_EXPORT std::vector<unsigned char> SaveToBinary(bool prettyPrint, const string_type& encoding, const string_type& lineend);
	OVAL_DEFINITIONS_SCHEMA_EXPORT std::vector<unsigned char> SaveToBinary(bool prettyPrint, bool omitXmlDecl, const string_type& encoding, const string_type& lineend);
	OVAL_DEFINITIONS_SCHEMA_EXPORT std::vector<unsigned char> SaveToBinary(bool prettyPrint, const string_type& encoding, bool bBigEndian, bool bBOM, const string_type& lineend);
	OVAL_DEFINITIONS_SCHEMA_EXPORT std::vector<unsigned char> SaveToBinary(bool prettyPrint, bool omitXmlDecl, const string_type& encoding, bool bBigEndian, bool bBOM, const string_type& lineend);

 	OVAL_DEFINITIONS_SCHEMA_EXPORT static Coval_definitions_schema CreateDocument();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void DestroyDocument();
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetDTDLocation(const string_type& dtdLocation);
	OVAL_DEFINITIONS_SCHEMA_EXPORT void SetSchemaLocation(const string_type& schemaLocation);
protected:
	XercesTreeOperations::DocumentType GetDocumentNode() { return (XercesTreeOperations::DocumentType)m_node; }
    
};



} // namespace oval_def

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_OVAL_DEF_COVAL_DEFINITIONS_SCHEMA_H_
