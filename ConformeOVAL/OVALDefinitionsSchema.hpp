//
//  OVALDefinitionsSchema.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_H_

#include <Conforme/XSDatatypes.hpp>
#include <Conforme/Node.hpp>
#include "OVALDefinitionsSchemaTypeinfo.hpp"

#if !defined( __GNUC__ )
#ifdef OVAL_DEFINITIONS_SCHEMA_EXPORTS
#define OVAL_DEFINITIONS_SCHEMA_EXPORT    __declspec(dllexport)
#else
#define OVAL_DEFINITIONS_SCHEMA_EXPORT    __declspec(dllimport)
#endif
#else
#define OVAL_DEFINITIONS_SCHEMA_EXPORT
#endif

namespace oval_definitions_schema
{
    
    class TypeBase
    {
    protected:
        xercesc::DOMNode* m_node;
    public:
        TypeBase(xercesc::DOMNode* const& node) : m_node(node) {}
        xercesc::DOMNode* GetNode() const { return m_node; }
        
        OVAL_DEFINITIONS_SCHEMA_EXPORT xercesc::DOMNode* GetElementNth(const conforme::MemberInfo* member, unsigned index);
        OVAL_DEFINITIONS_SCHEMA_EXPORT xercesc::DOMNode* GetElementLast(const conforme::MemberInfo* member);
        OVAL_DEFINITIONS_SCHEMA_EXPORT unsigned CountElement(const conforme::MemberInfo* member);
        OVAL_DEFINITIONS_SCHEMA_EXPORT void RemoveElement(const conforme::MemberInfo* member);
        OVAL_DEFINITIONS_SCHEMA_EXPORT static int GetEnumerationIndex( const string_type sValue, const unsigned enumOffset, const unsigned enumCount);
        OVAL_DEFINITIONS_SCHEMA_EXPORT static string_type GetEnumerationValue( const int index, const unsigned enumOffset, const unsigned enumCount);
    };
    
    template <typename MemberType, unsigned MemberIndex, unsigned EnumOffset, unsigned EnumCount>
    class MemberAttribute
    {
        TypeBase& m_owner;
    public:
        typedef const MemberType& argument_type;
        typedef MemberType return_type;
        
        MemberAttribute(TypeBase& owner) : m_owner(owner) {}
        
        void operator=(argument_type value);
        operator return_type();
        bool exists();
        void remove();
        int GetEnumerationValue();
        void SetEnumerationValue(const int index);
        
        conforme::meta::Attribute info() const { return conforme::meta::Attribute(members + MemberIndex); }
    };
    
    template <typename MemberType>
    class CastAs
    {
    public:
        static MemberType Do(xercesc::DOMNode* const& node, const conforme::MemberInfo* pMember);
    };
    
    template <>
    inline bool CastAs<bool>::Do(xercesc::DOMNode* const& node, const conforme::MemberInfo* pMember)
    {
        return XercesTreeOperations::CastToBool(node, pMember);
    }
    
    template <>
    inline double CastAs<double>::Do(xercesc::DOMNode* const& node, const conforme::MemberInfo* pMember)
    {
        return XercesTreeOperations::CastToDouble(node, pMember);
    }
    
    template <>
    inline int CastAs<int>::Do(xercesc::DOMNode* const& node, const conforme::MemberInfo* pMember)
    {
        return XercesTreeOperations::CastToInt(node, pMember);
    }
    
    template <>
    inline unsigned CastAs<unsigned>::Do(xercesc::DOMNode* const& node, const conforme::MemberInfo* pMember)
    {
        return XercesTreeOperations::CastToUInt(node, pMember);
    }
    
    template <>
    inline __int64 CastAs<__int64>::Do(xercesc::DOMNode* const& node, const conforme::MemberInfo* pMember)
    {
        return XercesTreeOperations::CastToInt64(node, pMember);
    }
    
    template <>
    inline unsigned __int64 CastAs<unsigned __int64>::Do(xercesc::DOMNode* const& node, const conforme::MemberInfo* pMember)
    {
        return XercesTreeOperations::CastToUInt64(node, pMember);
    }
    
    template <>
    inline string_type CastAs<string_type>::Do(xercesc::DOMNode* const& node, const conforme::MemberInfo* pMember)
    {
        return XercesTreeOperations::CastToString(node, pMember);
    }
    
    template <>
    inline std::vector<unsigned char> CastAs<std::vector<unsigned char> >::Do(xercesc::DOMNode* const& node, const conforme::MemberInfo* pMember)
    {
        return XercesTreeOperations::CastToBinary(node, pMember);
    }
    
    template <>
    inline conforme::DateTime CastAs<conforme::DateTime>::Do(xercesc::DOMNode* const& node, const conforme::MemberInfo* pMember)
    {
        return XercesTreeOperations::CastToDateTime(node, pMember);
    }
    
    template <>
    inline conforme::Duration CastAs<conforme::Duration>::Do(xercesc::DOMNode* const& node, const conforme::MemberInfo* pMember)
    {
        return XercesTreeOperations::CastToDuration(node, pMember);
    }
    
    template <typename DataType>
    class Iterator : public DataType
    {
        XercesTreeOperations::MemberIterator m_it;
    public:
        Iterator(const XercesTreeOperations::MemberIterator& it) : DataType(0), m_it(it) { if (m_it) this->m_node = *m_it; }
        
        bool operator++() { if (++m_it) { this->m_node = *m_it; return true; } return false; }
        operator bool() const { return m_it; }
        
        DataType& operator*() { return *this; }
        DataType* operator->() { return this; }
    };
    
    template <typename MemberType, unsigned MemberIndex>
    class MemberElement
    {
        TypeBase& m_owner;
    public:
        MemberElement(TypeBase& owner) : m_owner(owner) {}
        MemberType operator[](unsigned index);
        MemberType first();
        MemberType last();
        MemberType append();
        
        bool exists();
        unsigned count();
        void remove();
        void remove(unsigned index);
        
        conforme::meta::Element info() const { return conforme::meta::Element(members + MemberIndex); }
        Iterator<MemberType> all() { return XercesTreeOperations::GetElements(m_owner.GetNode(), members + MemberIndex); }
    };
    
    template <typename MemberType, unsigned MemberIndex, unsigned EnumOffset, unsigned EnumCount>
    void MemberAttribute<MemberType, MemberIndex, EnumOffset, EnumCount>::operator=(argument_type value)
    {
        XercesTreeOperations::SetValue(m_owner.GetNode(), members + MemberIndex, value);
    }
    
    template <typename MemberType, unsigned MemberIndex, unsigned EnumOffset, unsigned EnumCount>
    MemberAttribute<MemberType, MemberIndex, EnumOffset, EnumCount>::operator typename MemberAttribute<MemberType, MemberIndex, EnumOffset, EnumCount>::return_type()
    {
        xercesc::DOMNode* att = XercesTreeOperations::FindAttribute(m_owner.GetNode(), members + MemberIndex);
        
        if (!XercesTreeOperations::IsValid(att))
            throw conforme::InvalidOperationException(_T("Cannot read value of non-existent attribute."));
        return CastAs<MemberType>::Do(att, members + MemberIndex);
    }
    
    template <typename MemberType, unsigned MemberIndex, unsigned EnumOffset, unsigned EnumCount>
    bool MemberAttribute<MemberType, MemberIndex, EnumOffset, EnumCount>::exists()
    {
        xercesc::DOMNode* att = XercesTreeOperations::FindAttribute(m_owner.GetNode(), members + MemberIndex);
        return XercesTreeOperations::IsValid(att);
    }
    
    template <typename MemberType, unsigned MemberIndex, unsigned EnumOffset, unsigned EnumCount>
    void MemberAttribute<MemberType, MemberIndex, EnumOffset, EnumCount>::remove()
    {
        XercesTreeOperations::RemoveAttribute(m_owner.GetNode(), members + MemberIndex);
    }
    
    template <typename MemberType, unsigned MemberIndex, unsigned EnumOffset, unsigned EnumCount>
    int MemberAttribute<MemberType, MemberIndex, EnumOffset, EnumCount>::GetEnumerationValue() {
        xercesc::DOMNode* att = XercesTreeOperations::FindAttribute(m_owner.GetNode(), members + MemberIndex);
        
        if (!XercesTreeOperations::IsValid(att))
            throw conforme::InvalidOperationException(_T("Cannot read value of non-existent attribute."));
        string_type sValue = CastAs<string_type>::Do(att, members + MemberIndex);
        return TypeBase::GetEnumerationIndex( sValue, types[members[MemberIndex].DataType].Facets + EnumOffset, EnumCount);
    }
    
    template <typename MemberType, unsigned MemberIndex, unsigned EnumOffset, unsigned EnumCount>
    void MemberAttribute<MemberType, MemberIndex, EnumOffset, EnumCount>::SetEnumerationValue(const int index)
    {
        XercesTreeOperations::SetValue(m_owner.GetNode(), members + MemberIndex, TypeBase::GetEnumerationValue(index, types[members[MemberIndex].DataType].Facets + EnumOffset, EnumCount) );
    }
    
    template <typename MemberType, unsigned MemberIndex>
    MemberType MemberElement<MemberType, MemberIndex>::operator[](unsigned index)
    {
        return m_owner.GetElementNth(members + MemberIndex, index);
    }
    
    template <typename MemberType, unsigned MemberIndex>
    MemberType MemberElement<MemberType, MemberIndex>::first()
    {
        return m_owner.GetElementNth(members + MemberIndex, 0);
    }
    
    template <typename MemberType, unsigned MemberIndex>
    MemberType MemberElement<MemberType, MemberIndex>::last()
    {
        return m_owner.GetElementLast(members + MemberIndex);
    }
    
    template <typename MemberType, unsigned MemberIndex>
    MemberType MemberElement<MemberType, MemberIndex>::append()
    {
        return XercesTreeOperations::AddElement(m_owner.GetNode(), members + MemberIndex);
    }
    
    template <typename MemberType, unsigned MemberIndex>
    bool MemberElement<MemberType, MemberIndex>::exists()
    {
        return m_owner.GetElementNth(members + MemberIndex, 0) != 0;
    }
    
    template <typename MemberType, unsigned MemberIndex>
    unsigned MemberElement<MemberType, MemberIndex>::count()
    {
        return m_owner.CountElement(members + MemberIndex);
    }
    
    template <typename MemberType, unsigned MemberIndex>
    void MemberElement<MemberType, MemberIndex>::remove()
    {
        m_owner.RemoveElement(members + MemberIndex);
    }
    
    template <typename MemberType, unsigned MemberIndex>
    void MemberElement<MemberType, MemberIndex>::remove(unsigned index)
    {
        XercesTreeOperations::RemoveElement(m_owner.GetNode(), members + MemberIndex, index);
    }
    
}

namespace oval_definitions_schema
{
    // Namespace: http://oval.mitre.org/XMLSchema/oval-common-5
    // SchemaPrefix: oval
    
    namespace oval
    {
        class CCheckEnumeration;
        class CClassEnumeration;
        class CComplexDatatypeEnumeration;
        class CDatatypeEnumeration;
        class CDefinitionIDPattern;
        class CDeprecatedInfoType;
        class CElementMapItemType;
        class CElementMapType;
        class CEmptyStringType;
        class CExistenceEnumeration;
        class CFamilyEnumeration;
        class CGeneratorType;
        class CItemIDPattern;
        class CMessageLevelEnumeration;
        class CMessageType;
        class CNonEmptyStringType;
        class CNotesType;
        class CObjectIDPattern;
        class COperationEnumeration;
        class COperatorEnumeration;
        class CSchemaVersionPattern;
        class CSchemaVersionType;
        class CSimpleDatatypeEnumeration;
        class CStateIDPattern;
        class CTestIDPattern;
        class CVariableIDPattern;
        class CStateIDPatternType;
        class CObjectIDPatternType;
        class CversionType;
        class CversionType2;
        class CSchemaVersionPatternType;
        
    } // namespace oval
    
    // Namespace: http://oval.mitre.org/XMLSchema/oval-definitions-5
    // SchemaPrefix: oval-def
    
    namespace oval_def
    {
        class CAffectedType;
        class CArithmeticEnumeration;
        class CArithmeticFunctionType;
        class CBeginFunctionType;
        class CConcatFunctionType;
        class CCountFunctionType;
        class CCriteriaType;
        class CCriterionType;
        class CDateTimeFormatEnumeration;
        class CDefinitionType;
        class CDefinitionsType;
        class CEndFunctionType;
        class CEntityComplexBaseType;
        class CEntityObjectAnySimpleType;
        class CEntityObjectBinaryType;
        class CEntityObjectBoolType;
        class CEntityObjectFieldType;
        class CEntityObjectFloatType;
        class CEntityObjectIPAddressStringType;
        class CEntityObjectIPAddressType;
        class CEntityObjectIntType;
        class CEntityObjectRecordType;
        class CEntityObjectStringType;
        class CEntityObjectVersionType;
        class CEntitySimpleBaseType;
        class CEntityStateAnySimpleType;
        class CEntityStateBinaryType;
        class CEntityStateBoolType;
        class CEntityStateComplexBaseType;
        class CEntityStateDebianEVRStringType;
        class CEntityStateEVRStringType;
        class CEntityStateFieldType;
        class CEntityStateFileSetRevisionType;
        class CEntityStateFloatType;
        class CEntityStateIOSVersionType;
        class CEntityStateIPAddressStringType;
        class CEntityStateIPAddressType;
        class CEntityStateIntType;
        class CEntityStateRecordType;
        class CEntityStateSimpleBaseType;
        class CEntityStateStringType;
        class CEntityStateVersionType;
        class CEscapeRegexFunctionType;
        class CExtendDefinitionType;
        class CFilterActionEnumeration;
        class CGlobToRegexFunctionType;
        class CLiteralComponentType;
        class CMetadataType;
        class CObjectComponentType;
        class CObjectRefType;
        class CObjectType;
        class CObjectsType;
        class CPossibleRestrictionType;
        class CPossibleValueType;
        class CReferenceType;
        class CRegexCaptureFunctionType;
        class CRestrictionType;
        class CSetOperatorEnumeration;
        class CSplitFunctionType;
        class CStateRefType;
        class CStateType;
        class CStatesType;
        class CSubstringFunctionType;
        class CTestType;
        class CTestsType;
        class CTimeDifferenceFunctionType;
        class CUniqueFunctionType;
        class CValueType;
        class CVariableComponentType;
        class CVariableType;
        class CVariablesType;
        class Coval_definitions_schema;
        class Cconstant_variableType;
        class CnotesType;
        class Cexternal_variableType;
        class CfilterType;
        class Clocal_variableType;
        class Coval_definitionsType;
        class CsetType;
        class CnameType;
        class CdatatypeType;
        class CdatatypeType2;
        class CnameType2;
        class CdatatypeType3;
        class CdatatypeType4;
        class CdatatypeType5;
        
    } // namespace oval_def
    
    // Namespace: http://www.w3.org/2000/09/xmldsig#
    // SchemaPrefix: ds
    
    namespace ds
    {
        class CCanonicalizationMethodType;
        class CCryptoBinary;
        class CDSAKeyValueType;
        class CDigestMethodType;
        class CDigestValueType;
        class CHMACOutputLengthType;
        class CKeyInfoType;
        class CKeyValueType;
        class CManifestType;
        class CObjectType;
        class CPGPDataType;
        class CRSAKeyValueType;
        class CReferenceType;
        class CRetrievalMethodType;
        class CSPKIDataType;
        class CSignatureMethodType;
        class CSignaturePropertiesType;
        class CSignaturePropertyType;
        class CSignatureType;
        class CSignatureValueType;
        class CSignedInfoType;
        class CTransformType;
        class CTransformsType;
        class CX509DataType;
        class CX509IssuerSerialType;
        class CDigestValueTypeType;
        class CCryptoBinaryType;
        class CHMACOutputLengthTypeType;
        
    } // namespace ds
    
    // Namespace: http://www.w3.org/2001/XMLSchema
    // SchemaPrefix: xs
    
    namespace xs
    {
        class CENTITIES;
        class CENTITY;
        class CID;
        class CIDREF;
        class CIDREFS;
        class CNCName;
        class CNMTOKEN;
        class CNMTOKENS;
        class CNOTATION;
        class CName;
        class CQName;
        class CanySimpleType;
        class CanyType;
        class CanyURI;
        class Cbase64Binary;
        class Cboolean;
        class Cbyte;
        class Cdate;
        class CdateTime;
        class Cdecimal;
        class Cdouble;
        class Cduration;
        class Cfloat;
        class CgDay;
        class CgMonth;
        class CgMonthDay;
        class CgYear;
        class CgYearMonth;
        class ChexBinary;
        class Cint;
        class Cinteger;
        class Clanguage;
        class Clong;
        class CnegativeInteger;
        class CnonNegativeInteger;
        class CnonPositiveInteger;
        class CnormalizedString;
        class CpositiveInteger;
        class Cshort;
        class Cstring;
        class Ctime;
        class Ctoken;
        class CunsignedByte;
        class CunsignedInt;
        class CunsignedLong;
        class CunsignedShort;
        class CstringType;
        class CNCNameType;
        class CdateTimeType;
        class CanySimpleTypeType;
        class Cbase64BinaryType;
        class CintegerType;
        
    } // namespace xs
    
    
}

// include individual types

// namespace "http://oval.mitre.org/XMLSchema/oval-common-5"
#include "Type_Oval.CCheckEnumeration.hpp"
#include "Type_Oval.CClassEnumeration.hpp"
#include "Type_Oval.CComplexDatatypeEnumeration.hpp"
#include "Type_Oval.CDatatypeEnumeration.hpp"
#include "Type_Oval.CDefinitionIDPattern.hpp"
#include "Type_Oval.CDeprecatedInfoType.hpp"
#include "Type_Oval.CElementMapItemType.hpp"
#include "Type_Oval.CElementMapType.hpp"
#include "Type_Oval.CEmptyStringType.hpp"
#include "Type_Oval.CExistenceEnumeration.hpp"
#include "Type_Oval.CFamilyEnumeration.hpp"
#include "Type_Oval.CGeneratorType.hpp"
#include "Type_Oval.CItemIDPattern.hpp"
#include "Type_Oval.CMessageLevelEnumeration.hpp"
#include "Type_Oval.CMessageType.hpp"
#include "Type_Oval.CNonEmptyStringType.hpp"
#include "Type_Oval.CNotesType.hpp"
#include "Type_Oval.CObjectIDPattern.hpp"
#include "Type_Oval.COperationEnumeration.hpp"
#include "Type_Oval.COperatorEnumeration.hpp"
#include "Type_Oval.CSchemaVersionPattern.hpp"
#include "Type_Oval.CSchemaVersionType.hpp"
#include "Type_Oval.CSimpleDatatypeEnumeration.hpp"
#include "Type_Oval.CStateIDPattern.hpp"
#include "Type_Oval.CTestIDPattern.hpp"
#include "Type_Oval.CVariableIDPattern.hpp"
#include "Type_Oval.CStateIDPatternType.hpp"
#include "Type_Oval.CObjectIDPatternType.hpp"
#include "Type_Oval.CversionType.hpp"
#include "Type_Oval.CversionType2.hpp"
#include "Type_Oval.CSchemaVersionPatternType.hpp"

// namespace "http://oval.mitre.org/XMLSchema/oval-definitions-5"
#include "Type_Oval_Def.CAffectedType.hpp"
#include "Type_Oval_Def.CArithmeticEnumeration.hpp"
#include "Type_Oval_Def.CArithmeticFunctionType.hpp"
#include "Type_Oval_Def.CBeginFunctionType.hpp"
#include "Type_Oval_Def.CConcatFunctionType.hpp"
#include "Type_Oval_Def.CCountFunctionType.hpp"
#include "Type_Oval_Def.CCriteriaType.hpp"
#include "Type_Oval_Def.CCriterionType.hpp"
#include "Type_Oval_Def.CDateTimeFormatEnumeration.hpp"
#include "Type_Oval_Def.CDefinitionType.hpp"
#include "Type_Oval_Def.CDefinitionsType.hpp"
#include "Type_Oval_Def.CEndFunctionType.hpp"
#include "Type_Oval_Def.CEntityComplexBaseType.hpp"
#include "Type_Oval_Def.CEntityObjectAnySimpleType.hpp"
#include "Type_Oval_Def.CEntityObjectBinaryType.hpp"
#include "Type_Oval_Def.CEntityObjectBoolType.hpp"
#include "Type_Oval_Def.CEntityObjectFieldType.hpp"
#include "Type_Oval_Def.CEntityObjectFloatType.hpp"
#include "Type_Oval_Def.CEntityObjectIPAddressStringType.hpp"
#include "Type_Oval_Def.CEntityObjectIPAddressType.hpp"
#include "Type_Oval_Def.CEntityObjectIntType.hpp"
#include "Type_Oval_Def.CEntityObjectRecordType.hpp"
#include "Type_Oval_Def.CEntityObjectStringType.hpp"
#include "Type_Oval_Def.CEntityObjectVersionType.hpp"
#include "Type_Oval_Def.CEntitySimpleBaseType.hpp"
#include "Type_Oval_Def.CEntityStateAnySimpleType.hpp"
#include "Type_Oval_Def.CEntityStateBinaryType.hpp"
#include "Type_Oval_Def.CEntityStateBoolType.hpp"
#include "Type_Oval_Def.CEntityStateComplexBaseType.hpp"
#include "Type_Oval_Def.CEntityStateDebianEVRStringType.hpp"
#include "Type_Oval_Def.CEntityStateEVRStringType.hpp"
#include "Type_Oval_Def.CEntityStateFieldType.hpp"
#include "Type_Oval_Def.CEntityStateFileSetRevisionType.hpp"
#include "Type_Oval_Def.CEntityStateFloatType.hpp"
#include "Type_Oval_Def.CEntityStateIOSVersionType.hpp"
#include "Type_Oval_Def.CEntityStateIPAddressStringType.hpp"
#include "Type_Oval_Def.CEntityStateIPAddressType.hpp"
#include "Type_Oval_Def.CEntityStateIntType.hpp"
#include "Type_Oval_Def.CEntityStateRecordType.hpp"
#include "Type_Oval_Def.CEntityStateSimpleBaseType.hpp"
#include "Type_Oval_Def.CEntityStateStringType.hpp"
#include "Type_Oval_Def.CEntityStateVersionType.hpp"
#include "Type_Oval_Def.CEscapeRegexFunctionType.hpp"
#include "Type_Oval_Def.CExtendDefinitionType.hpp"
#include "Type_Oval_Def.CFilterActionEnumeration.hpp"
#include "Type_Oval_Def.CGlobToRegexFunctionType.hpp"
#include "Type_Oval_Def.CLiteralComponentType.hpp"
#include "Type_Oval_Def.CMetadataType.hpp"
#include "Type_Oval_Def.CObjectComponentType.hpp"
#include "Type_Oval_Def.CObjectRefType.hpp"
#include "Type_Oval_Def.CObjectType.hpp"
#include "Type_Oval_Def.CObjectsType.hpp"
#include "Type_Oval_Def.CPossibleRestrictionType.hpp"
#include "Type_Oval_Def.CPossibleValueType.hpp"
#include "Type_Oval_Def.CReferenceType.hpp"
#include "Type_Oval_Def.CRegexCaptureFunctionType.hpp"
#include "Type_Oval_Def.CRestrictionType.hpp"
#include "Type_Oval_Def.CSetOperatorEnumeration.hpp"
#include "Type_Oval_Def.CSplitFunctionType.hpp"
#include "Type_Oval_Def.CStateRefType.hpp"
#include "Type_Oval_Def.CStateType.hpp"
#include "Type_Oval_Def.CStatesType.hpp"
#include "Type_Oval_Def.CSubstringFunctionType.hpp"
#include "Type_Oval_Def.CTestType.hpp"
#include "Type_Oval_Def.CTestsType.hpp"
#include "Type_Oval_Def.CTimeDifferenceFunctionType.hpp"
#include "Type_Oval_Def.CUniqueFunctionType.hpp"
#include "Type_Oval_Def.CValueType.hpp"
#include "Type_Oval_Def.CVariableComponentType.hpp"
#include "Type_Oval_Def.CVariableType.hpp"
#include "Type_Oval_Def.CVariablesType.hpp"
#include "Type_Oval_Def.COVALDefinitionsSchema.hpp"
#include "Type_Oval_Def.Cconstant_variableType.hpp"
#include "Type_Oval_Def.CnotesType.hpp"
#include "Type_Oval_Def.Cexternal_variableType.hpp"
#include "Type_Oval_Def.CfilterType.hpp"
#include "Type_Oval_Def.Clocal_variableType.hpp"
#include "Type_Oval_Def.Coval_definitionsType.hpp"
#include "Type_Oval_Def.CsetType.hpp"
#include "Type_Oval_Def.CnameType.hpp"
#include "Type_Oval_Def.CdatatypeType.hpp"
#include "Type_Oval_Def.CdatatypeType2.hpp"
#include "Type_Oval_Def.CnameType2.hpp"
#include "Type_Oval_Def.CdatatypeType3.hpp"
#include "Type_Oval_Def.CdatatypeType4.hpp"
#include "Type_Oval_Def.CdatatypeType5.hpp"

// namespace "http://www.w3.org/2000/09/xmldsig#"
#include "Type_DS.CCanonicalizationMethodType.hpp"
#include "Type_DS.CCryptoBinary.hpp"
#include "Type_DS.CDSAKeyValueType.hpp"
#include "Type_DS.CDigestMethodType.hpp"
#include "Type_DS.CDigestValueType.hpp"
#include "Type_DS.CHMACOutputLengthType.hpp"
#include "Type_DS.CKeyInfoType.hpp"
#include "Type_DS.CKeyValueType.hpp"
#include "Type_DS.CManifestType.hpp"
#include "Type_DS.CObjectType.hpp"
#include "Type_DS.CPGPDataType.hpp"
#include "Type_DS.CRSAKeyValueType.hpp"
#include "Type_DS.CReferenceType.hpp"
#include "Type_DS.CRetrievalMethodType.hpp"
#include "Type_DS.CSPKIDataType.hpp"
#include "Type_DS.CSignatureMethodType.hpp"
#include "Type_DS.CSignaturePropertiesType.hpp"
#include "Type_DS.CSignaturePropertyType.hpp"
#include "Type_DS.CSignatureType.hpp"
#include "Type_DS.CSignatureValueType.hpp"
#include "Type_DS.CSignedInfoType.hpp"
#include "Type_DS.CTransformType.hpp"
#include "Type_DS.CTransformsType.hpp"
#include "Type_DS.CX509DataType.hpp"
#include "Type_DS.CX509IssuerSerialType.hpp"
#include "Type_DS.CDigestValueTypeType.hpp"
#include "Type_DS.CCryptoBinaryType.hpp"
#include "Type_DS.CHMACOutputLengthTypeType.hpp"

// namespace "http://www.w3.org/2001/XMLSchema"
#include "Type_XS.CENTITIES.hpp"
#include "Type_XS.CENTITY.hpp"
#include "Type_XS.CID.hpp"
#include "Type_XS.CIDREF.hpp"
#include "Type_XS.CIDREFS.hpp"
#include "Type_XS.CNCName.hpp"
#include "Type_XS.CNMTOKEN.hpp"
#include "Type_XS.CNMTOKENS.hpp"
#include "Type_XS.CNOTATION.hpp"
#include "Type_XS.CName.hpp"
#include "Type_XS.CQName.hpp"
#include "Type_XS.CanySimpleType.hpp"
#include "Type_XS.CanyType.hpp"
#include "Type_XS.CanyURI.hpp"
#include "Type_XS.Cbase64Binary.hpp"
#include "Type_XS.Cboolean.hpp"
#include "Type_XS.Cbyte.hpp"
#include "Type_XS.Cdate.hpp"
#include "Type_XS.CdateTime.hpp"
#include "Type_XS.Cdecimal.hpp"
#include "Type_XS.Cdouble.hpp"
#include "Type_XS.Cduration.hpp"
#include "Type_XS.Cfloat.hpp"
#include "Type_XS.CgDay.hpp"
#include "Type_XS.CgMonth.hpp"
#include "Type_XS.CgMonthDay.hpp"
#include "Type_XS.CgYear.hpp"
#include "Type_XS.CgYearMonth.hpp"
#include "Type_XS.ChexBinary.hpp"
#include "Type_XS.Cint.hpp"
#include "Type_XS.Cinteger.hpp"
#include "Type_XS.Clanguage.hpp"
#include "Type_XS.Clong.hpp"
#include "Type_XS.CnegativeInteger.hpp"
#include "Type_XS.CnonNegativeInteger.hpp"
#include "Type_XS.CnonPositiveInteger.hpp"
#include "Type_XS.CnormalizedString.hpp"
#include "Type_XS.CpositiveInteger.hpp"
#include "Type_XS.Cshort.hpp"
#include "Type_XS.Cstring.hpp"
#include "Type_XS.Ctime.hpp"
#include "Type_XS.Ctoken.hpp"
#include "Type_XS.CunsignedByte.hpp"
#include "Type_XS.CunsignedInt.hpp"
#include "Type_XS.CunsignedLong.hpp"
#include "Type_XS.CunsignedShort.hpp"
#include "Type_XS.CstringType.hpp"
#include "Type_XS.CNCNameType.hpp"
#include "Type_XS.CdateTimeType.hpp"
#include "Type_XS.CanySimpleTypeType.hpp"
#include "Type_XS.Cbase64BinaryType.hpp"
#include "Type_XS.CintegerType.hpp"

// finished

#endif //_CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_H_

