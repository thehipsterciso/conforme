//
//  OVALDefinitionsSchema.cpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#include "StdAfx.hpp"
#include <string.h>
#include "OVALDefinitionsSchema.hpp"
#include <algorithm>
#include <Conforme/XercesString.hpp>

// turn off warning: "this" used in base initializer list
#pragma warning(disable:4355)

namespace oval_definitions_schema
{
    xercesc::DOMNode* TypeBase::GetElementNth(const conforme::MemberInfo* member, unsigned index)
    {
        for (XercesTreeOperations::MemberIterator it = XercesTreeOperations::GetElements(m_node, member); it; ++it)
        {
            if (index-- == 0)
                return *it;
        }
        return 0;
    }
    
    xercesc::DOMNode* TypeBase::GetElementLast(const conforme::MemberInfo* member)
    {
        xercesc::DOMNode* p = NULL;
        
        for (XercesTreeOperations::MemberIterator it = XercesTreeOperations::GetElements(m_node, member); it; ++it)
        {
            p = *it;
        }
        
        return p;
    }
    
    unsigned TypeBase::CountElement(const conforme::MemberInfo* member)
    {
        unsigned count = 0;
        
        for (XercesTreeOperations::MemberIterator it = XercesTreeOperations::GetElements(m_node, member); it; ++it)
        {
            ++count;
        }
        return count;
    }
    
    void TypeBase::RemoveElement(const conforme::MemberInfo* member)
    {
        XercesTreeOperations::RemoveElements(m_node, member);
    }
    
    int TypeBase::GetEnumerationIndex( const string_type sValue, const unsigned enumOffset, const unsigned enumCount)
    {
        unsigned enumIndex = enumOffset;
        
        while( enumIndex < (enumOffset + enumCount) )
        {
            const FacetInfo* facet = GetTableEntry(facets, enumIndex);
            
            if( facet->StringValue == sValue)
                return enumIndex - enumOffset;
            enumIndex++;
        }
        return static_cast<unsigned int>(-1); //Invalid
    }
    
    string_type TypeBase::GetEnumerationValue( const int index, const unsigned enumOffset, const unsigned enumCount)
    {
        unsigned enumIndex = enumOffset + index;
        
        if( enumIndex >= enumOffset && enumIndex < (enumOffset + enumCount) )
        {
            const FacetInfo* facet = GetTableEntry(facets, enumIndex);
            return facet->StringValue;
        }
        else
            throw conforme::ConversionException( _T("Enumeration index out of range.") );
    }
    
    
    namespace oval
    {
        
        CCheckEnumeration::CCheckEnumeration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CCheckEnumeration::CCheckEnumeration(CCheckEnumeration const& other) : TypeBase(other.GetNode()) {}
        
        
        CClassEnumeration::CClassEnumeration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CClassEnumeration::CClassEnumeration(CClassEnumeration const& other) : TypeBase(other.GetNode()) {}
        
        
        CComplexDatatypeEnumeration::CComplexDatatypeEnumeration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CComplexDatatypeEnumeration::CComplexDatatypeEnumeration(CComplexDatatypeEnumeration const& other) : TypeBase(other.GetNode()) {}
        
        
        CDatatypeEnumeration::CDatatypeEnumeration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CDatatypeEnumeration::CDatatypeEnumeration(CDatatypeEnumeration const& other) : TypeBase(other.GetNode()) {}
        
        
        CDefinitionIDPattern::CDefinitionIDPattern(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CDefinitionIDPattern::CDefinitionIDPattern(CDefinitionIDPattern const& other) : TypeBase(other.GetNode()) {}
        
        
        CDeprecatedInfoType::CDeprecatedInfoType(xercesc::DOMNode* const& node) : TypeBase(node)
        , version(*this)    // "version"
        , reason(*this)    // "reason"
        , comment(*this)    // "comment"
        {}
        
        CDeprecatedInfoType::CDeprecatedInfoType(CDeprecatedInfoType const& other) : TypeBase(other.GetNode())
        , version(*this)    // "version"
        , reason(*this)    // "reason"
        , comment(*this)    // "comment"
        {}
        
        void CDeprecatedInfoType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                _T("DeprecatedInfoType"), _T("http://oval.mitre.org/XMLSchema/oval-common-5"));
        }
        
        CElementMapItemType::CElementMapItemType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::xs::CNCNameType(node)
        , target_namespace(*this)    // "@target_namespace"
        {}
        
        CElementMapItemType::CElementMapItemType(CElementMapItemType const& other)
        : ::oval_definitions_schema::xs::CNCNameType(other.GetNode())
        , target_namespace(*this)    // "@target_namespace"
        {}
        
        void CElementMapItemType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ElementMapItemType"), _T("http://oval.mitre.org/XMLSchema/oval-common-5"));
        }
        
        CElementMapType::CElementMapType(xercesc::DOMNode* const& node) : TypeBase(node)
        , test(*this)    // "test"
        , object(*this)    // "object"
        , state(*this)    // "state"
        , item(*this)    // "item"
        {}
        
        CElementMapType::CElementMapType(CElementMapType const& other) : TypeBase(other.GetNode())
        , test(*this)    // "test"
        , object(*this)    // "object"
        , state(*this)    // "state"
        , item(*this)    // "item"
        {}
        
        void CElementMapType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ElementMapType"), _T("http://oval.mitre.org/XMLSchema/oval-common-5"));
        }
        
        CEmptyStringType::CEmptyStringType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CEmptyStringType::CEmptyStringType(CEmptyStringType const& other) : TypeBase(other.GetNode()) {}
        
        
        CExistenceEnumeration::CExistenceEnumeration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CExistenceEnumeration::CExistenceEnumeration(CExistenceEnumeration const& other) : TypeBase(other.GetNode()) {}
        
        
        CFamilyEnumeration::CFamilyEnumeration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CFamilyEnumeration::CFamilyEnumeration(CFamilyEnumeration const& other) : TypeBase(other.GetNode()) {}
        
        
        CGeneratorType::CGeneratorType(xercesc::DOMNode* const& node) : TypeBase(node)
        , product_name(*this)    // "product_name"
        , product_version(*this)    // "product_version"
        , schema_version(*this)    // "schema_version"
        , timestamp(*this)    // "timestamp"
        {}
        
        CGeneratorType::CGeneratorType(CGeneratorType const& other) : TypeBase(other.GetNode())
        , product_name(*this)    // "product_name"
        , product_version(*this)    // "product_version"
        , schema_version(*this)    // "schema_version"
        , timestamp(*this)    // "timestamp"
        {}
        
        void CGeneratorType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("GeneratorType"), _T("http://oval.mitre.org/XMLSchema/oval-common-5"));
        }
        
        CItemIDPattern::CItemIDPattern(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CItemIDPattern::CItemIDPattern(CItemIDPattern const& other) : TypeBase(other.GetNode()) {}
        
        
        CMessageLevelEnumeration::CMessageLevelEnumeration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CMessageLevelEnumeration::CMessageLevelEnumeration(CMessageLevelEnumeration const& other) : TypeBase(other.GetNode()) {}
        
        
        CMessageType::CMessageType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::xs::CstringType(node)
        , level(*this)    // "@level"
        {}
        
        CMessageType::CMessageType(CMessageType const& other)
        : ::oval_definitions_schema::xs::CstringType(other.GetNode())
        , level(*this)    // "@level"
        {}
        
        void CMessageType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("MessageType"), _T("http://oval.mitre.org/XMLSchema/oval-common-5"));
        }
        
        CNonEmptyStringType::CNonEmptyStringType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CNonEmptyStringType::CNonEmptyStringType(CNonEmptyStringType const& other) : TypeBase(other.GetNode()) {}
        
        
        CNotesType::CNotesType(xercesc::DOMNode* const& node) : TypeBase(node)
        , note(*this)    // "note"
        {}
        
        CNotesType::CNotesType(CNotesType const& other) : TypeBase(other.GetNode())
        , note(*this)    // "note"
        {}
        
        void CNotesType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("NotesType"), _T("http://oval.mitre.org/XMLSchema/oval-common-5"));
        }
        
        CObjectIDPattern::CObjectIDPattern(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CObjectIDPattern::CObjectIDPattern(CObjectIDPattern const& other) : TypeBase(other.GetNode()) {}
        
        
        COperationEnumeration::COperationEnumeration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        COperationEnumeration::COperationEnumeration(COperationEnumeration const& other) : TypeBase(other.GetNode()) {}
        
        
        COperatorEnumeration::COperatorEnumeration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        COperatorEnumeration::COperatorEnumeration(COperatorEnumeration const& other) : TypeBase(other.GetNode()) {}
        
        
        CSchemaVersionPattern::CSchemaVersionPattern(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CSchemaVersionPattern::CSchemaVersionPattern(CSchemaVersionPattern const& other) : TypeBase(other.GetNode()) {}
        
        
        CSchemaVersionType::CSchemaVersionType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::oval::CSchemaVersionPatternType(node)
        , platform(*this)    // "@platform"
        {}
        
        CSchemaVersionType::CSchemaVersionType(CSchemaVersionType const& other)
        : ::oval_definitions_schema::oval::CSchemaVersionPatternType(other.GetNode())
        , platform(*this)    // "@platform"
        {}
        
        void CSchemaVersionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("SchemaVersionType"), _T("http://oval.mitre.org/XMLSchema/oval-common-5"));
        }
        
        CSimpleDatatypeEnumeration::CSimpleDatatypeEnumeration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CSimpleDatatypeEnumeration::CSimpleDatatypeEnumeration(CSimpleDatatypeEnumeration const& other) : TypeBase(other.GetNode()) {}
        
        
        CStateIDPattern::CStateIDPattern(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CStateIDPattern::CStateIDPattern(CStateIDPattern const& other) : TypeBase(other.GetNode()) {}
        
        
        CTestIDPattern::CTestIDPattern(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CTestIDPattern::CTestIDPattern(CTestIDPattern const& other) : TypeBase(other.GetNode()) {}
        
        
        CVariableIDPattern::CVariableIDPattern(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CVariableIDPattern::CVariableIDPattern(CVariableIDPattern const& other) : TypeBase(other.GetNode()) {}
        
        
        CStateIDPatternType::CStateIDPatternType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CStateIDPatternType::CStateIDPatternType(CStateIDPatternType const& other) : TypeBase(other.GetNode()) {}
        
        void CStateIDPatternType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("StateIDPattern"), _T("http://oval.mitre.org/XMLSchema/oval-common-5"));
        }
        
        CObjectIDPatternType::CObjectIDPatternType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CObjectIDPatternType::CObjectIDPatternType(CObjectIDPatternType const& other) : TypeBase(other.GetNode()) {}
        
        void CObjectIDPatternType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ObjectIDPattern"), _T("http://oval.mitre.org/XMLSchema/oval-common-5"));
        }
        
        CversionType::CversionType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CversionType::CversionType(CversionType const& other) : TypeBase(other.GetNode()) {}
        
        
        CversionType2::CversionType2(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CversionType2::CversionType2(CversionType2 const& other) : TypeBase(other.GetNode()) {}
        
        
        CSchemaVersionPatternType::CSchemaVersionPatternType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CSchemaVersionPatternType::CSchemaVersionPatternType(CSchemaVersionPatternType const& other) : TypeBase(other.GetNode()) {}
        
        void CSchemaVersionPatternType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("SchemaVersionPattern"), _T("http://oval.mitre.org/XMLSchema/oval-common-5"));
        }
        
    } // namespace oval
    
    
    namespace oval_def
    {
        
        CAffectedType::CAffectedType(xercesc::DOMNode* const& node) : TypeBase(node)
        , family(*this)    // "@family"
        , platform(*this)    // "platform"
        , product(*this)    // "product"
        {}
        
        CAffectedType::CAffectedType(CAffectedType const& other) : TypeBase(other.GetNode())
        , family(*this)    // "@family"
        , platform(*this)    // "platform"
        , product(*this)    // "product"
        {}
        
        void CAffectedType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("AffectedType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CArithmeticEnumeration::CArithmeticEnumeration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CArithmeticEnumeration::CArithmeticEnumeration(CArithmeticEnumeration const& other) : TypeBase(other.GetNode()) {}
        
        
        CArithmeticFunctionType::CArithmeticFunctionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , arithmetic_operation(*this)    // "@arithmetic_operation"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        CArithmeticFunctionType::CArithmeticFunctionType(CArithmeticFunctionType const& other) : TypeBase(other.GetNode())
        , arithmetic_operation(*this)    // "@arithmetic_operation"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        void CArithmeticFunctionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ArithmeticFunctionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CBeginFunctionType::CBeginFunctionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , character(*this)    // "@character"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        CBeginFunctionType::CBeginFunctionType(CBeginFunctionType const& other) : TypeBase(other.GetNode())
        , character(*this)    // "@character"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        void CBeginFunctionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("BeginFunctionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CConcatFunctionType::CConcatFunctionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        CConcatFunctionType::CConcatFunctionType(CConcatFunctionType const& other) : TypeBase(other.GetNode())
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        void CConcatFunctionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ConcatFunctionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CCountFunctionType::CCountFunctionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        CCountFunctionType::CCountFunctionType(CCountFunctionType const& other) : TypeBase(other.GetNode())
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        void CCountFunctionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("CountFunctionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CCriteriaType::CCriteriaType(xercesc::DOMNode* const& node) : TypeBase(node)
        , applicability_check(*this)    // "@applicability_check"
        , operator2(*this)    // "@operator"
        , negate(*this)    // "@negate"
        , comment(*this)    // "@comment"
        , criteria(*this)    // "criteria"
        , criterion(*this)    // "criterion"
        , extend_definition(*this)    // "extend_definition"
        {}
        
        CCriteriaType::CCriteriaType(CCriteriaType const& other) : TypeBase(other.GetNode())
        , applicability_check(*this)    // "@applicability_check"
        , operator2(*this)    // "@operator"
        , negate(*this)    // "@negate"
        , comment(*this)    // "@comment"
        , criteria(*this)    // "criteria"
        , criterion(*this)    // "criterion"
        , extend_definition(*this)    // "extend_definition"
        {}
        
        void CCriteriaType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("CriteriaType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CCriterionType::CCriterionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , applicability_check(*this)    // "@applicability_check"
        , test_ref(*this)    // "@test_ref"
        , negate(*this)    // "@negate"
        , comment(*this)    // "@comment"
        {}
        
        CCriterionType::CCriterionType(CCriterionType const& other) : TypeBase(other.GetNode())
        , applicability_check(*this)    // "@applicability_check"
        , test_ref(*this)    // "@test_ref"
        , negate(*this)    // "@negate"
        , comment(*this)    // "@comment"
        {}
        
        void CCriterionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("CriterionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CDateTimeFormatEnumeration::CDateTimeFormatEnumeration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CDateTimeFormatEnumeration::CDateTimeFormatEnumeration(CDateTimeFormatEnumeration const& other) : TypeBase(other.GetNode()) {}
        
        
        CDefinitionType::CDefinitionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , id(*this)    // "@id"
        , version(*this)    // "@version"
        , class2(*this)    // "@class"
        , deprecated(*this)    // "@deprecated"
        , Signature(*this)    // "Signature"
        , metadata(*this)    // "metadata"
        , notes(*this)    // "notes"
        , notes2(*this)    // "notes"
        , criteria(*this)    // "criteria"
        {}
        
        CDefinitionType::CDefinitionType(CDefinitionType const& other) : TypeBase(other.GetNode())
        , id(*this)    // "@id"
        , version(*this)    // "@version"
        , class2(*this)    // "@class"
        , deprecated(*this)    // "@deprecated"
        , Signature(*this)    // "Signature"
        , metadata(*this)    // "metadata"
        , notes(*this)    // "notes"
        , notes2(*this)    // "notes"
        , criteria(*this)    // "criteria"
        {}
        
        void CDefinitionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("DefinitionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CDefinitionsType::CDefinitionsType(xercesc::DOMNode* const& node) : TypeBase(node)
        , definition(*this)    // "definition"
        {}
        
        CDefinitionsType::CDefinitionsType(CDefinitionsType const& other) : TypeBase(other.GetNode())
        , definition(*this)    // "definition"
        {}
        
        void CDefinitionsType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("DefinitionsType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEndFunctionType::CEndFunctionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , character(*this)    // "@character"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        CEndFunctionType::CEndFunctionType(CEndFunctionType const& other) : TypeBase(other.GetNode())
        , character(*this)    // "@character"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        void CEndFunctionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EndFunctionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityComplexBaseType::CEntityComplexBaseType(xercesc::DOMNode* const& node) : TypeBase(node)
        , datatype(*this)    // "@datatype"
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        {}
        
        CEntityComplexBaseType::CEntityComplexBaseType(CEntityComplexBaseType const& other) : TypeBase(other.GetNode())
        , datatype(*this)    // "@datatype"
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        {}
        
        void CEntityComplexBaseType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityComplexBaseType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityObjectAnySimpleType::CEntityObjectAnySimpleType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityObjectAnySimpleType::CEntityObjectAnySimpleType(CEntityObjectAnySimpleType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityObjectAnySimpleType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityObjectAnySimpleType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityObjectBinaryType::CEntityObjectBinaryType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityObjectBinaryType::CEntityObjectBinaryType(CEntityObjectBinaryType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityObjectBinaryType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityObjectBinaryType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityObjectBoolType::CEntityObjectBoolType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityObjectBoolType::CEntityObjectBoolType(CEntityObjectBoolType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityObjectBoolType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityObjectBoolType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityObjectFieldType::CEntityObjectFieldType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::xs::CanySimpleTypeType(node)
        , name(*this)    // "@name"
        , datatype(*this)    // "@datatype"
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        {}
        
        CEntityObjectFieldType::CEntityObjectFieldType(CEntityObjectFieldType const& other)
        : ::oval_definitions_schema::xs::CanySimpleTypeType(other.GetNode())
        , name(*this)    // "@name"
        , datatype(*this)    // "@datatype"
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        {}
        
        void CEntityObjectFieldType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityObjectFieldType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityObjectFloatType::CEntityObjectFloatType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityObjectFloatType::CEntityObjectFloatType(CEntityObjectFloatType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityObjectFloatType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityObjectFloatType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityObjectIPAddressStringType::CEntityObjectIPAddressStringType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityObjectIPAddressStringType::CEntityObjectIPAddressStringType(CEntityObjectIPAddressStringType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityObjectIPAddressStringType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityObjectIPAddressStringType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityObjectIPAddressType::CEntityObjectIPAddressType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityObjectIPAddressType::CEntityObjectIPAddressType(CEntityObjectIPAddressType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityObjectIPAddressType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityObjectIPAddressType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityObjectIntType::CEntityObjectIntType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityObjectIntType::CEntityObjectIntType(CEntityObjectIntType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityObjectIntType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityObjectIntType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityObjectRecordType::CEntityObjectRecordType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::oval_def::CEntityComplexBaseType(node)
        , field(*this)    // "field"
        {}
        
        CEntityObjectRecordType::CEntityObjectRecordType(CEntityObjectRecordType const& other)
        : ::oval_definitions_schema::oval_def::CEntityComplexBaseType(other.GetNode())
        , field(*this)    // "field"
        {}
        
        void CEntityObjectRecordType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityObjectRecordType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityObjectStringType::CEntityObjectStringType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityObjectStringType::CEntityObjectStringType(CEntityObjectStringType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityObjectStringType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityObjectStringType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityObjectVersionType::CEntityObjectVersionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityObjectVersionType::CEntityObjectVersionType(CEntityObjectVersionType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityObjectVersionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityObjectVersionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntitySimpleBaseType::CEntitySimpleBaseType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::xs::CanySimpleTypeType(node)
        , datatype(*this)    // "@datatype"
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        {}
        
        CEntitySimpleBaseType::CEntitySimpleBaseType(CEntitySimpleBaseType const& other)
        : ::oval_definitions_schema::xs::CanySimpleTypeType(other.GetNode())
        , datatype(*this)    // "@datatype"
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        {}
        
        void CEntitySimpleBaseType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntitySimpleBaseType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateAnySimpleType::CEntityStateAnySimpleType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityStateAnySimpleType::CEntityStateAnySimpleType(CEntityStateAnySimpleType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityStateAnySimpleType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateAnySimpleType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateBinaryType::CEntityStateBinaryType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityStateBinaryType::CEntityStateBinaryType(CEntityStateBinaryType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityStateBinaryType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateBinaryType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateBoolType::CEntityStateBoolType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityStateBoolType::CEntityStateBoolType(CEntityStateBoolType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityStateBoolType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateBoolType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateComplexBaseType::CEntityStateComplexBaseType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::oval_def::CEntityComplexBaseType(node)
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        {}
        
        CEntityStateComplexBaseType::CEntityStateComplexBaseType(CEntityStateComplexBaseType const& other)
        : ::oval_definitions_schema::oval_def::CEntityComplexBaseType(other.GetNode())
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        {}
        
        void CEntityStateComplexBaseType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateComplexBaseType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateDebianEVRStringType::CEntityStateDebianEVRStringType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityStateDebianEVRStringType::CEntityStateDebianEVRStringType(CEntityStateDebianEVRStringType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityStateDebianEVRStringType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateDebianEVRStringType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateEVRStringType::CEntityStateEVRStringType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityStateEVRStringType::CEntityStateEVRStringType(CEntityStateEVRStringType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityStateEVRStringType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateEVRStringType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateFieldType::CEntityStateFieldType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::xs::CanySimpleTypeType(node)
        , name(*this)    // "@name"
        , datatype(*this)    // "@datatype"
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        {}
        
        CEntityStateFieldType::CEntityStateFieldType(CEntityStateFieldType const& other)
        : ::oval_definitions_schema::xs::CanySimpleTypeType(other.GetNode())
        , name(*this)    // "@name"
        , datatype(*this)    // "@datatype"
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        {}
        
        void CEntityStateFieldType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateFieldType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateFileSetRevisionType::CEntityStateFileSetRevisionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityStateFileSetRevisionType::CEntityStateFileSetRevisionType(CEntityStateFileSetRevisionType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityStateFileSetRevisionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateFileSetRevisionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateFloatType::CEntityStateFloatType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityStateFloatType::CEntityStateFloatType(CEntityStateFloatType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityStateFloatType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateFloatType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateIOSVersionType::CEntityStateIOSVersionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityStateIOSVersionType::CEntityStateIOSVersionType(CEntityStateIOSVersionType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityStateIOSVersionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateIOSVersionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateIPAddressStringType::CEntityStateIPAddressStringType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityStateIPAddressStringType::CEntityStateIPAddressStringType(CEntityStateIPAddressStringType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityStateIPAddressStringType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateIPAddressStringType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateIPAddressType::CEntityStateIPAddressType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityStateIPAddressType::CEntityStateIPAddressType(CEntityStateIPAddressType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityStateIPAddressType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateIPAddressType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateIntType::CEntityStateIntType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityStateIntType::CEntityStateIntType(CEntityStateIntType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityStateIntType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateIntType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateRecordType::CEntityStateRecordType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::oval_def::CEntityStateComplexBaseType(node)
        , field(*this)    // "field"
        {}
        
        CEntityStateRecordType::CEntityStateRecordType(CEntityStateRecordType const& other)
        : ::oval_definitions_schema::oval_def::CEntityStateComplexBaseType(other.GetNode())
        , field(*this)    // "field"
        {}
        
        void CEntityStateRecordType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateRecordType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateSimpleBaseType::CEntityStateSimpleBaseType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::oval_def::CEntitySimpleBaseType(node)
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        {}
        
        CEntityStateSimpleBaseType::CEntityStateSimpleBaseType(CEntityStateSimpleBaseType const& other)
        : ::oval_definitions_schema::oval_def::CEntitySimpleBaseType(other.GetNode())
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        {}
        
        void CEntityStateSimpleBaseType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateSimpleBaseType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateStringType::CEntityStateStringType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityStateStringType::CEntityStateStringType(CEntityStateStringType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityStateStringType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateStringType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEntityStateVersionType::CEntityStateVersionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        CEntityStateVersionType::CEntityStateVersionType(CEntityStateVersionType const& other) : TypeBase(other.GetNode())
        , operation(*this)    // "@operation"
        , mask(*this)    // "@mask"
        , var_ref(*this)    // "@var_ref"
        , var_check(*this)    // "@var_check"
        , entity_check(*this)    // "@entity_check"
        , check_existence(*this)    // "@check_existence"
        , datatype(*this)    // "@datatype"
        {}
        
        void CEntityStateVersionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EntityStateVersionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CEscapeRegexFunctionType::CEscapeRegexFunctionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        CEscapeRegexFunctionType::CEscapeRegexFunctionType(CEscapeRegexFunctionType const& other) : TypeBase(other.GetNode())
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        void CEscapeRegexFunctionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("EscapeRegexFunctionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CExtendDefinitionType::CExtendDefinitionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , applicability_check(*this)    // "@applicability_check"
        , definition_ref(*this)    // "@definition_ref"
        , negate(*this)    // "@negate"
        , comment(*this)    // "@comment"
        {}
        
        CExtendDefinitionType::CExtendDefinitionType(CExtendDefinitionType const& other) : TypeBase(other.GetNode())
        , applicability_check(*this)    // "@applicability_check"
        , definition_ref(*this)    // "@definition_ref"
        , negate(*this)    // "@negate"
        , comment(*this)    // "@comment"
        {}
        
        void CExtendDefinitionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ExtendDefinitionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CFilterActionEnumeration::CFilterActionEnumeration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CFilterActionEnumeration::CFilterActionEnumeration(CFilterActionEnumeration const& other) : TypeBase(other.GetNode()) {}
        
        
        CGlobToRegexFunctionType::CGlobToRegexFunctionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , glob_noescape(*this)    // "@glob_noescape"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        CGlobToRegexFunctionType::CGlobToRegexFunctionType(CGlobToRegexFunctionType const& other) : TypeBase(other.GetNode())
        , glob_noescape(*this)    // "@glob_noescape"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        void CGlobToRegexFunctionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("GlobToRegexFunctionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CLiteralComponentType::CLiteralComponentType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::xs::CanySimpleTypeType(node)
        , datatype(*this)    // "@datatype"
        {}
        
        CLiteralComponentType::CLiteralComponentType(CLiteralComponentType const& other)
        : ::oval_definitions_schema::xs::CanySimpleTypeType(other.GetNode())
        , datatype(*this)    // "@datatype"
        {}
        
        void CLiteralComponentType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("LiteralComponentType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CMetadataType::CMetadataType(xercesc::DOMNode* const& node) : TypeBase(node)
        , title(*this)    // "title"
        , affected(*this)    // "affected"
        , reference(*this)    // "reference"
        , description(*this)    // "description"
        {}
        
        CMetadataType::CMetadataType(CMetadataType const& other) : TypeBase(other.GetNode())
        , title(*this)    // "title"
        , affected(*this)    // "affected"
        , reference(*this)    // "reference"
        , description(*this)    // "description"
        {}
        
        void CMetadataType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("MetadataType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CObjectComponentType::CObjectComponentType(xercesc::DOMNode* const& node) : TypeBase(node)
        , object_ref(*this)    // "@object_ref"
        , item_field(*this)    // "@item_field"
        , record_field(*this)    // "@record_field"
        {}
        
        CObjectComponentType::CObjectComponentType(CObjectComponentType const& other) : TypeBase(other.GetNode())
        , object_ref(*this)    // "@object_ref"
        , item_field(*this)    // "@item_field"
        , record_field(*this)    // "@record_field"
        {}
        
        void CObjectComponentType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ObjectComponentType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CObjectRefType::CObjectRefType(xercesc::DOMNode* const& node) : TypeBase(node)
        , object_ref(*this)    // "@object_ref"
        {}
        
        CObjectRefType::CObjectRefType(CObjectRefType const& other) : TypeBase(other.GetNode())
        , object_ref(*this)    // "@object_ref"
        {}
        
        void CObjectRefType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ObjectRefType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CObjectType::CObjectType(xercesc::DOMNode* const& node) : TypeBase(node)
        , id(*this)    // "@id"
        , version(*this)    // "@version"
        , comment(*this)    // "@comment"
        , deprecated(*this)    // "@deprecated"
        , Signature(*this)    // "Signature"
        , notes(*this)    // "notes"
        , notes2(*this)    // "notes"
        {}
        
        CObjectType::CObjectType(CObjectType const& other) : TypeBase(other.GetNode())
        , id(*this)    // "@id"
        , version(*this)    // "@version"
        , comment(*this)    // "@comment"
        , deprecated(*this)    // "@deprecated"
        , Signature(*this)    // "Signature"
        , notes(*this)    // "notes"
        , notes2(*this)    // "notes"
        {}
        
        void CObjectType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ObjectType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CObjectsType::CObjectsType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CObjectsType::CObjectsType(CObjectsType const& other) : TypeBase(other.GetNode()) {}
        
        void CObjectsType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ObjectsType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CPossibleRestrictionType::CPossibleRestrictionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , operator2(*this)    // "@operator"
        , hint(*this)    // "@hint"
        , restriction(*this)    // "restriction"
        {}
        
        CPossibleRestrictionType::CPossibleRestrictionType(CPossibleRestrictionType const& other) : TypeBase(other.GetNode())
        , operator2(*this)    // "@operator"
        , hint(*this)    // "@hint"
        , restriction(*this)    // "restriction"
        {}
        
        void CPossibleRestrictionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("PossibleRestrictionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CPossibleValueType::CPossibleValueType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::xs::CanySimpleTypeType(node)
        , hint(*this)    // "@hint"
        {}
        
        CPossibleValueType::CPossibleValueType(CPossibleValueType const& other)
        : ::oval_definitions_schema::xs::CanySimpleTypeType(other.GetNode())
        , hint(*this)    // "@hint"
        {}
        
        void CPossibleValueType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("PossibleValueType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CReferenceType::CReferenceType(xercesc::DOMNode* const& node) : TypeBase(node)
        , source(*this)    // "@source"
        , ref_id(*this)    // "@ref_id"
        , ref_url(*this)    // "@ref_url"
        {}
        
        CReferenceType::CReferenceType(CReferenceType const& other) : TypeBase(other.GetNode())
        , source(*this)    // "@source"
        , ref_id(*this)    // "@ref_id"
        , ref_url(*this)    // "@ref_url"
        {}
        
        void CReferenceType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ReferenceType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CRegexCaptureFunctionType::CRegexCaptureFunctionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , pattern(*this)    // "@pattern"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        CRegexCaptureFunctionType::CRegexCaptureFunctionType(CRegexCaptureFunctionType const& other) : TypeBase(other.GetNode())
        , pattern(*this)    // "@pattern"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        void CRegexCaptureFunctionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("RegexCaptureFunctionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CRestrictionType::CRestrictionType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::xs::CanySimpleTypeType(node)
        , operation(*this)    // "@operation"
        {}
        
        CRestrictionType::CRestrictionType(CRestrictionType const& other)
        : ::oval_definitions_schema::xs::CanySimpleTypeType(other.GetNode())
        , operation(*this)    // "@operation"
        {}
        
        void CRestrictionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("RestrictionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CSetOperatorEnumeration::CSetOperatorEnumeration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CSetOperatorEnumeration::CSetOperatorEnumeration(CSetOperatorEnumeration const& other) : TypeBase(other.GetNode()) {}
        
        
        CSplitFunctionType::CSplitFunctionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , delimiter(*this)    // "@delimiter"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        CSplitFunctionType::CSplitFunctionType(CSplitFunctionType const& other) : TypeBase(other.GetNode())
        , delimiter(*this)    // "@delimiter"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        void CSplitFunctionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("SplitFunctionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CStateRefType::CStateRefType(xercesc::DOMNode* const& node) : TypeBase(node)
        , state_ref(*this)    // "@state_ref"
        {}
        
        CStateRefType::CStateRefType(CStateRefType const& other) : TypeBase(other.GetNode())
        , state_ref(*this)    // "@state_ref"
        {}
        
        void CStateRefType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("StateRefType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CStateType::CStateType(xercesc::DOMNode* const& node) : TypeBase(node)
        , id(*this)    // "@id"
        , version(*this)    // "@version"
        , operator2(*this)    // "@operator"
        , comment(*this)    // "@comment"
        , deprecated(*this)    // "@deprecated"
        , Signature(*this)    // "Signature"
        , notes(*this)    // "notes"
        , notes2(*this)    // "notes"
        {}
        
        CStateType::CStateType(CStateType const& other) : TypeBase(other.GetNode())
        , id(*this)    // "@id"
        , version(*this)    // "@version"
        , operator2(*this)    // "@operator"
        , comment(*this)    // "@comment"
        , deprecated(*this)    // "@deprecated"
        , Signature(*this)    // "Signature"
        , notes(*this)    // "notes"
        , notes2(*this)    // "notes"
        {}
        
        void CStateType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("StateType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CStatesType::CStatesType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CStatesType::CStatesType(CStatesType const& other) : TypeBase(other.GetNode()) {}
        
        void CStatesType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("StatesType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CSubstringFunctionType::CSubstringFunctionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , substring_start(*this)    // "@substring_start"
        , substring_length(*this)    // "@substring_length"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        CSubstringFunctionType::CSubstringFunctionType(CSubstringFunctionType const& other) : TypeBase(other.GetNode())
        , substring_start(*this)    // "@substring_start"
        , substring_length(*this)    // "@substring_length"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        void CSubstringFunctionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("SubstringFunctionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CTestType::CTestType(xercesc::DOMNode* const& node) : TypeBase(node)
        , id(*this)    // "@id"
        , version(*this)    // "@version"
        , check_existence(*this)    // "@check_existence"
        , check(*this)    // "@check"
        , state_operator(*this)    // "@state_operator"
        , comment(*this)    // "@comment"
        , deprecated(*this)    // "@deprecated"
        , Signature(*this)    // "Signature"
        , notes(*this)    // "notes"
        , notes2(*this)    // "notes"
        {}
        
        CTestType::CTestType(CTestType const& other) : TypeBase(other.GetNode())
        , id(*this)    // "@id"
        , version(*this)    // "@version"
        , check_existence(*this)    // "@check_existence"
        , check(*this)    // "@check"
        , state_operator(*this)    // "@state_operator"
        , comment(*this)    // "@comment"
        , deprecated(*this)    // "@deprecated"
        , Signature(*this)    // "Signature"
        , notes(*this)    // "notes"
        , notes2(*this)    // "notes"
        {}
        
        void CTestType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("TestType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CTestsType::CTestsType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CTestsType::CTestsType(CTestsType const& other) : TypeBase(other.GetNode()) {}
        
        void CTestsType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("TestsType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CTimeDifferenceFunctionType::CTimeDifferenceFunctionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , format_1(*this)    // "@format_1"
        , format_2(*this)    // "@format_2"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        CTimeDifferenceFunctionType::CTimeDifferenceFunctionType(CTimeDifferenceFunctionType const& other) : TypeBase(other.GetNode())
        , format_1(*this)    // "@format_1"
        , format_2(*this)    // "@format_2"
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        void CTimeDifferenceFunctionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("TimeDifferenceFunctionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CUniqueFunctionType::CUniqueFunctionType(xercesc::DOMNode* const& node) : TypeBase(node)
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        CUniqueFunctionType::CUniqueFunctionType(CUniqueFunctionType const& other) : TypeBase(other.GetNode())
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        void CUniqueFunctionType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("UniqueFunctionType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CValueType::CValueType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::xs::CanySimpleTypeType(node) {}
        
        CValueType::CValueType(CValueType const& other)
        : ::oval_definitions_schema::xs::CanySimpleTypeType(other.GetNode()) {}
        
        void CValueType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ValueType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CVariableComponentType::CVariableComponentType(xercesc::DOMNode* const& node) : TypeBase(node)
        , var_ref(*this)    // "@var_ref"
        {}
        
        CVariableComponentType::CVariableComponentType(CVariableComponentType const& other) : TypeBase(other.GetNode())
        , var_ref(*this)    // "@var_ref"
        {}
        
        void CVariableComponentType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("VariableComponentType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CVariableType::CVariableType(xercesc::DOMNode* const& node) : TypeBase(node)
        , id(*this)    // "@id"
        , version(*this)    // "@version"
        , datatype(*this)    // "@datatype"
        , comment(*this)    // "@comment"
        , deprecated(*this)    // "@deprecated"
        , Signature(*this)    // "Signature"
        , notes(*this)    // "notes"
        , notes2(*this)    // "notes"
        {}
        
        CVariableType::CVariableType(CVariableType const& other) : TypeBase(other.GetNode())
        , id(*this)    // "@id"
        , version(*this)    // "@version"
        , datatype(*this)    // "@datatype"
        , comment(*this)    // "@comment"
        , deprecated(*this)    // "@deprecated"
        , Signature(*this)    // "Signature"
        , notes(*this)    // "notes"
        , notes2(*this)    // "notes"
        {}
        
        void CVariableType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("VariableType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        CVariablesType::CVariablesType(xercesc::DOMNode* const& node) : TypeBase(node)
        , constant_variable(*this)    // "constant_variable"
        , external_variable(*this)    // "external_variable"
        , local_variable(*this)    // "local_variable"
        {}
        
        CVariablesType::CVariablesType(CVariablesType const& other) : TypeBase(other.GetNode())
        , constant_variable(*this)    // "constant_variable"
        , external_variable(*this)    // "external_variable"
        , local_variable(*this)    // "local_variable"
        {}
        
        void CVariablesType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("VariablesType"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        Coval_definitions_schema::Coval_definitions_schema(xercesc::DOMNode* const& node) : TypeBase(node)
        , deprecated_info(*this)    // "deprecated_info"
        , element_mapping(*this)    // "element_mapping"
        , notes(*this)    // "notes"
        , constant_variable(*this)    // "constant_variable"
        , definition(*this)    // "definition"
        , external_variable(*this)    // "external_variable"
        , filter(*this)    // "filter"
        , local_variable(*this)    // "local_variable"
        , notes2(*this)    // "notes"
        , object(*this)    // "object"
        , oval_definitions(*this)    // "oval_definitions"
        , set(*this)    // "set"
        , state(*this)    // "state"
        , test(*this)    // "test"
        , variable(*this)    // "variable"
        , CanonicalizationMethod(*this)    // "CanonicalizationMethod"
        , DSAKeyValue(*this)    // "DSAKeyValue"
        , DigestMethod(*this)    // "DigestMethod"
        , DigestValue(*this)    // "DigestValue"
        , KeyInfo(*this)    // "KeyInfo"
        , KeyName(*this)    // "KeyName"
        , KeyValue(*this)    // "KeyValue"
        , Manifest(*this)    // "Manifest"
        , MgmtData(*this)    // "MgmtData"
        , Object2(*this)    // "Object"
        , PGPData(*this)    // "PGPData"
        , RSAKeyValue(*this)    // "RSAKeyValue"
        , Reference(*this)    // "Reference"
        , RetrievalMethod(*this)    // "RetrievalMethod"
        , SPKIData(*this)    // "SPKIData"
        , Signature(*this)    // "Signature"
        , SignatureMethod(*this)    // "SignatureMethod"
        , SignatureProperties(*this)    // "SignatureProperties"
        , SignatureProperty(*this)    // "SignatureProperty"
        , SignatureValue(*this)    // "SignatureValue"
        , SignedInfo(*this)    // "SignedInfo"
        , Transform(*this)    // "Transform"
        , Transforms(*this)    // "Transforms"
        , X509Data(*this)    // "X509Data"
        {}
        
        Coval_definitions_schema::Coval_definitions_schema(Coval_definitions_schema const& other) : TypeBase(other.GetNode())
        , deprecated_info(*this)    // "deprecated_info"
        , element_mapping(*this)    // "element_mapping"
        , notes(*this)    // "notes"
        , constant_variable(*this)    // "constant_variable"
        , definition(*this)    // "definition"
        , external_variable(*this)    // "external_variable"
        , filter(*this)    // "filter"
        , local_variable(*this)    // "local_variable"
        , notes2(*this)    // "notes"
        , object(*this)    // "object"
        , oval_definitions(*this)    // "oval_definitions"
        , set(*this)    // "set"
        , state(*this)    // "state"
        , test(*this)    // "test"
        , variable(*this)    // "variable"
        , CanonicalizationMethod(*this)    // "CanonicalizationMethod"
        , DSAKeyValue(*this)    // "DSAKeyValue"
        , DigestMethod(*this)    // "DigestMethod"
        , DigestValue(*this)    // "DigestValue"
        , KeyInfo(*this)    // "KeyInfo"
        , KeyName(*this)    // "KeyName"
        , KeyValue(*this)    // "KeyValue"
        , Manifest(*this)    // "Manifest"
        , MgmtData(*this)    // "MgmtData"
        , Object2(*this)    // "Object"
        , PGPData(*this)    // "PGPData"
        , RSAKeyValue(*this)    // "RSAKeyValue"
        , Reference(*this)    // "Reference"
        , RetrievalMethod(*this)    // "RetrievalMethod"
        , SPKIData(*this)    // "SPKIData"
        , Signature(*this)    // "Signature"
        , SignatureMethod(*this)    // "SignatureMethod"
        , SignatureProperties(*this)    // "SignatureProperties"
        , SignatureProperty(*this)    // "SignatureProperty"
        , SignatureValue(*this)    // "SignatureValue"
        , SignedInfo(*this)    // "SignedInfo"
        , Transform(*this)    // "Transform"
        , Transforms(*this)    // "Transforms"
        , X509Data(*this)    // "X509Data"
        {}
        
        void Coval_definitions_schema::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("oval-definitions-schema"), _T("http://oval.mitre.org/XMLSchema/oval-definitions-5"));
        }
        
        Coval_definitions_schema Coval_definitions_schema::LoadFromFile(const string_type& fileName)
        {
            return Coval_definitions_schema(XercesTreeOperations::LoadDocument(fileName));
        }
        
        Coval_definitions_schema Coval_definitions_schema::LoadFromString(const string_type& text)
        {
            return Coval_definitions_schema(XercesTreeOperations::LoadXml(text));
        }
        
        void Coval_definitions_schema::SaveToFile(const string_type& fileName, bool prettyPrint)
        {
            SaveToFile(fileName, prettyPrint, false);
        }
        
        void Coval_definitions_schema::SaveToFile(const string_type& fileName, bool prettyPrint, bool omitXmlDecl)
        {
            XercesTreeOperations::SaveDocument(GetDocumentNode(), fileName, prettyPrint, omitXmlDecl, _T("UTF-8"), false, false, _T("\r\n"));
        }
        
        void Coval_definitions_schema::SaveToFile(const string_type& fileName, bool prettyPrint, const string_type& encoding)
        {
            std::vector<unsigned char> result;
            string_type sTmpEnc( encoding);
            std::transform( sTmpEnc.begin(), sTmpEnc.end(), sTmpEnc.begin(), _totupper);
            XercesTreeOperations::SaveDocument(GetDocumentNode(), fileName, prettyPrint, encoding, _tcscmp(sTmpEnc.c_str(), _T("UTF-16BE")) == 0, _tcscmp(sTmpEnc.c_str(), _T("UTF-16")) == 0, _T("\r\n"));
        }
        
        void Coval_definitions_schema::SaveToFile(const string_type& fileName, bool prettyPrint, bool omitXmlDecl, const string_type& encoding)
        {
            std::vector<unsigned char> result;
            string_type sTmpEnc( encoding);
            std::transform( sTmpEnc.begin(), sTmpEnc.end(), sTmpEnc.begin(), _totupper);
            XercesTreeOperations::SaveDocument(GetDocumentNode(), fileName, prettyPrint, omitXmlDecl, encoding, _tcscmp(sTmpEnc.c_str(), _T("UTF-16BE")) == 0, _tcscmp(sTmpEnc.c_str(), _T("UTF-16")) == 0, _T("\r\n"));
        }
        
        void Coval_definitions_schema::SaveToFile(const string_type& fileName, bool prettyPrint, const string_type& encoding, bool bBigEndian, bool bBOM)
        {
            XercesTreeOperations::SaveDocument(GetDocumentNode(), fileName, prettyPrint, encoding, bBigEndian, bBOM, _T("\r\n"));
        }
        
        
        void Coval_definitions_schema::SaveToFile(const string_type& fileName, bool prettyPrint, const string_type& encoding, const string_type& lineend)
        {
            SaveToFile(fileName, prettyPrint, false, encoding, lineend);
        }
        
        void Coval_definitions_schema::SaveToFile(const string_type& fileName, bool prettyPrint, bool omitXmlDecl, const string_type& encoding, const string_type& lineend)
        {
            std::vector<unsigned char> result;
            string_type sTmpEnc( encoding);
            std::transform( sTmpEnc.begin(), sTmpEnc.end(), sTmpEnc.begin(), _totupper);
            XercesTreeOperations::SaveDocument(GetDocumentNode(), fileName, prettyPrint, omitXmlDecl, encoding, _tcscmp(sTmpEnc.c_str(), _T("UTF-16BE")) == 0, _tcscmp(sTmpEnc.c_str(), _T("UTF-16")) == 0, lineend);
        }
        
        void Coval_definitions_schema::SaveToFile(const string_type& fileName, bool prettyPrint, const string_type& encoding, bool bBigEndian, bool bBOM, const string_type& lineend)
        {
            SaveToFile(fileName, prettyPrint, false, encoding, bBigEndian, bBOM, lineend);
        }
        
        void Coval_definitions_schema::SaveToFile(const string_type& fileName, bool prettyPrint, bool omitXmlDecl, const string_type& encoding, bool bBigEndian, bool bBOM, const string_type& lineend)
        {
            XercesTreeOperations::SaveDocument(GetDocumentNode(), fileName, prettyPrint, omitXmlDecl, encoding, bBigEndian, bBOM, lineend);
        }
        
        string_type Coval_definitions_schema::SaveToString(bool prettyPrint, bool omitXmlDecl)
        {
            return XercesTreeOperations::SaveXml(GetDocumentNode(), prettyPrint, omitXmlDecl, _T("\r\n"));
        }
        
        
        
        string_type Coval_definitions_schema::SaveToString(bool prettyPrint)
        {
            return SaveToString(prettyPrint,false);
        }
        
        Coval_definitions_schema Coval_definitions_schema::CreateDocument()
        {
            return XercesTreeOperations::CreateDocument();
        }
        
        void Coval_definitions_schema::DestroyDocument()
        {
            XercesTreeOperations::DocumentType doc = GetDocumentNode();
            XercesTreeOperations::FreeDocument(doc);
            m_node = 0;
        }
        
        void Coval_definitions_schema::SetDTDLocation(const string_type& dtdLocation)
        {
            
            xercesc::DOMDocument* document = (xercesc::DOMDocument*)GetNode();
            xercesc::DOMDocumentType* doctype = document->getDoctype();
            if (doctype != 0)
            {
                document->removeChild(doctype);
            }
            
            xercesc::DOMElement* rootElement = document->getDocumentElement();
            if (rootElement == 0)
                throw conforme::InvalidOperationException(_T("You have to add a root element before setting DTD location."));
            
            doctype = document->createDocumentType(rootElement->getNodeName(), XercesStringTemp(_T("")), XercesStringTemp(dtdLocation));
            document->insertBefore(doctype, rootElement);
            
        }
        
        void Coval_definitions_schema::SetSchemaLocation(const string_type& schemaLocation)
        {
            
            xercesc::DOMDocument* document = (xercesc::DOMDocument*)GetNode();
            xercesc::DOMElement* rootElement = document->getDocumentElement();
            if (rootElement == 0)
                throw conforme::InvalidOperationException(_T("You have to add a root element before setting schema location."));
            
            string_type namespaceURI = XercesUnstringTemp(rootElement->getNamespaceURI());
            
            
            if (namespaceURI.empty())
                XercesTreeOperations::SetAttribute(rootElement, _T("xsi:noNamespaceSchemaLocation"), _T("http://www.w3.org/2001/XMLSchema-instance"), schemaLocation);
            else
                XercesTreeOperations::SetAttribute(rootElement, _T("xsi:schemaLocation"), _T("http://www.w3.org/2001/XMLSchema-instance"), namespaceURI + _T(" ") + schemaLocation);
            
        }
        
        Coval_definitions_schema Coval_definitions_schema::LoadFromBinary(const std::vector<unsigned char>& data)
        {
            return XercesTreeOperations::LoadFromBinary(data);
        }
        
        
        std::vector<unsigned char> Coval_definitions_schema::SaveToBinary(bool prettyPrint)
        {
            return XercesTreeOperations::SaveToBinary((XercesTreeOperations::DocumentType)GetNode(), prettyPrint, _T("\r\n"));
        }
        
        std::vector<unsigned char> Coval_definitions_schema::SaveToBinary(bool prettyPrint, const string_type& encoding)
        {
            std::vector<unsigned char> result;
            string_type sTmpEnc( encoding);
            std::transform( sTmpEnc.begin(), sTmpEnc.end(), sTmpEnc.begin(), _totupper);
            XercesTreeOperations::SaveToBinary(result, (XercesTreeOperations::DocumentType)GetNode(), prettyPrint, encoding, _tcscmp(sTmpEnc.c_str(), _T("UTF-16BE")) == 0, _tcscmp(sTmpEnc.c_str(), _T("UTF-16")) == 0, _T("\r\n"));
            return result;
        }
        
        std::vector<unsigned char> Coval_definitions_schema::SaveToBinary(bool prettyPrint, const string_type& encoding, bool bBigEndian, bool bBOM)
        {
            std::vector<unsigned char> result;
            XercesTreeOperations::SaveToBinary(result, (XercesTreeOperations::DocumentType)GetNode(), prettyPrint, encoding, bBigEndian, bBOM, _T("\r\n"));
            return result;
        }
        
        std::vector<unsigned char> Coval_definitions_schema::SaveToBinary(bool prettyPrint, const string_type& encoding, const string_type& lineend)
        {
            return SaveToBinary(prettyPrint, false, encoding, lineend);
        }
        
        std::vector<unsigned char> Coval_definitions_schema::SaveToBinary(bool prettyPrint, bool omitXmlDecl, const string_type& encoding, const string_type& lineend)
        {
            std::vector<unsigned char> result;
            string_type sTmpEnc( encoding);
            std::transform( sTmpEnc.begin(), sTmpEnc.end(), sTmpEnc.begin(), _totupper);
            XercesTreeOperations::SaveToBinary(result, (XercesTreeOperations::DocumentType)GetNode(), prettyPrint, encoding, _tcscmp(sTmpEnc.c_str(), _T("UTF-16BE")) == 0, _tcscmp(sTmpEnc.c_str(), _T("UTF-16")) == 0, lineend, !omitXmlDecl);
            return result;
        }
        
        std::vector<unsigned char> Coval_definitions_schema::SaveToBinary(bool prettyPrint, const string_type& encoding, bool bBigEndian, bool bBOM, const string_type& lineend)
        {
            return SaveToBinary(prettyPrint, false, encoding, bBigEndian, bBOM, lineend );
        }
        
        std::vector<unsigned char> Coval_definitions_schema::SaveToBinary(bool prettyPrint, bool omitXmlDecl, const string_type& encoding, bool bBigEndian, bool bBOM, const string_type& lineend)
        {
            std::vector<unsigned char> result;
            XercesTreeOperations::SaveToBinary(result, (XercesTreeOperations::DocumentType)GetNode(), prettyPrint, encoding, bBigEndian, bBOM, lineend, !omitXmlDecl);
            return result;
        }
        
        
        
        Cconstant_variableType::Cconstant_variableType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::oval_def::CVariableType(node)
        , value2(*this)    // "value"
        {}
        
        Cconstant_variableType::Cconstant_variableType(Cconstant_variableType const& other)
        : ::oval_definitions_schema::oval_def::CVariableType(other.GetNode())
        , value2(*this)    // "value"
        {}
        
        
        CnotesType::CnotesType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::oval::CNotesType(node)
        , note2(*this)    // "note"
        {}
        
        CnotesType::CnotesType(CnotesType const& other)
        : ::oval_definitions_schema::oval::CNotesType(other.GetNode())
        , note2(*this)    // "note"
        {}
        
        
        Cexternal_variableType::Cexternal_variableType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::oval_def::CVariableType(node)
        , possible_value(*this)    // "possible_value"
        , possible_restriction(*this)    // "possible_restriction"
        {}
        
        Cexternal_variableType::Cexternal_variableType(Cexternal_variableType const& other)
        : ::oval_definitions_schema::oval_def::CVariableType(other.GetNode())
        , possible_value(*this)    // "possible_value"
        , possible_restriction(*this)    // "possible_restriction"
        {}
        
        
        CfilterType::CfilterType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::oval::CStateIDPatternType(node)
        , action(*this)    // "@action"
        {}
        
        CfilterType::CfilterType(CfilterType const& other)
        : ::oval_definitions_schema::oval::CStateIDPatternType(other.GetNode())
        , action(*this)    // "@action"
        {}
        
        void CfilterType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("StateIDPattern"), _T("http://oval.mitre.org/XMLSchema/oval-common-5"));
        }
        
        Clocal_variableType::Clocal_variableType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::oval_def::CVariableType(node)
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        Clocal_variableType::Clocal_variableType(Clocal_variableType const& other)
        : ::oval_definitions_schema::oval_def::CVariableType(other.GetNode())
        , object_component(*this)    // "object_component"
        , variable_component(*this)    // "variable_component"
        , literal_component(*this)    // "literal_component"
        , arithmetic(*this)    // "arithmetic"
        , begin(*this)    // "begin"
        , concat(*this)    // "concat"
        , end(*this)    // "end"
        , escape_regex(*this)    // "escape_regex"
        , split(*this)    // "split"
        , substring(*this)    // "substring"
        , time_difference(*this)    // "time_difference"
        , regex_capture(*this)    // "regex_capture"
        , unique(*this)    // "unique"
        , count(*this)    // "count"
        , glob_to_regex(*this)    // "glob_to_regex"
        {}
        
        
        Coval_definitionsType::Coval_definitionsType(xercesc::DOMNode* const& node) : TypeBase(node)
        , generator(*this)    // "generator"
        , definitions(*this)    // "definitions"
        , tests(*this)    // "tests"
        , objects(*this)    // "objects"
        , states(*this)    // "states"
        , variables(*this)    // "variables"
        , Signature(*this)    // "Signature"
        {}
        
        Coval_definitionsType::Coval_definitionsType(Coval_definitionsType const& other) : TypeBase(other.GetNode())
        , generator(*this)    // "generator"
        , definitions(*this)    // "definitions"
        , tests(*this)    // "tests"
        , objects(*this)    // "objects"
        , states(*this)    // "states"
        , variables(*this)    // "variables"
        , Signature(*this)    // "Signature"
        {}
        
        
        CsetType::CsetType(xercesc::DOMNode* const& node) : TypeBase(node)
        , set_operator(*this)    // "@set_operator"
        , set(*this)    // "set"
        , object_reference(*this)    // "object_reference"
        , filter(*this)    // "filter"
        {}
        
        CsetType::CsetType(CsetType const& other) : TypeBase(other.GetNode())
        , set_operator(*this)    // "@set_operator"
        , set(*this)    // "set"
        , object_reference(*this)    // "object_reference"
        , filter(*this)    // "filter"
        {}
        
        
        CnameType::CnameType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CnameType::CnameType(CnameType const& other) : TypeBase(other.GetNode()) {}
        
        
        CdatatypeType::CdatatypeType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CdatatypeType::CdatatypeType(CdatatypeType const& other) : TypeBase(other.GetNode()) {}
        
        
        CdatatypeType2::CdatatypeType2(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CdatatypeType2::CdatatypeType2(CdatatypeType2 const& other) : TypeBase(other.GetNode()) {}
        
        
        CnameType2::CnameType2(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CnameType2::CnameType2(CnameType2 const& other) : TypeBase(other.GetNode()) {}
        
        
        CdatatypeType3::CdatatypeType3(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CdatatypeType3::CdatatypeType3(CdatatypeType3 const& other) : TypeBase(other.GetNode()) {}
        
        
        CdatatypeType4::CdatatypeType4(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CdatatypeType4::CdatatypeType4(CdatatypeType4 const& other) : TypeBase(other.GetNode()) {}
        
        
        CdatatypeType5::CdatatypeType5(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CdatatypeType5::CdatatypeType5(CdatatypeType5 const& other) : TypeBase(other.GetNode()) {}
        
        
    } // namespace oval_def
    
    
    namespace ds
    {
        
        CCanonicalizationMethodType::CCanonicalizationMethodType(xercesc::DOMNode* const& node) : TypeBase(node)
        , Algorithm(*this)    // "@Algorithm"
        {}
        
        CCanonicalizationMethodType::CCanonicalizationMethodType(CCanonicalizationMethodType const& other) : TypeBase(other.GetNode())
        , Algorithm(*this)    // "@Algorithm"
        {}
        
        void CCanonicalizationMethodType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("CanonicalizationMethodType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CCryptoBinary::CCryptoBinary(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CCryptoBinary::CCryptoBinary(CCryptoBinary const& other) : TypeBase(other.GetNode()) {}
        
        
        CDSAKeyValueType::CDSAKeyValueType(xercesc::DOMNode* const& node) : TypeBase(node)
        , P(*this)    // "P"
        , Q(*this)    // "Q"
        , G(*this)    // "G"
        , Y(*this)    // "Y"
        , J(*this)    // "J"
        , Seed(*this)    // "Seed"
        , PgenCounter(*this)    // "PgenCounter"
        {}
        
        CDSAKeyValueType::CDSAKeyValueType(CDSAKeyValueType const& other) : TypeBase(other.GetNode())
        , P(*this)    // "P"
        , Q(*this)    // "Q"
        , G(*this)    // "G"
        , Y(*this)    // "Y"
        , J(*this)    // "J"
        , Seed(*this)    // "Seed"
        , PgenCounter(*this)    // "PgenCounter"
        {}
        
        void CDSAKeyValueType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("DSAKeyValueType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CDigestMethodType::CDigestMethodType(xercesc::DOMNode* const& node) : TypeBase(node)
        , Algorithm(*this)    // "@Algorithm"
        {}
        
        CDigestMethodType::CDigestMethodType(CDigestMethodType const& other) : TypeBase(other.GetNode())
        , Algorithm(*this)    // "@Algorithm"
        {}
        
        void CDigestMethodType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("DigestMethodType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CDigestValueType::CDigestValueType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CDigestValueType::CDigestValueType(CDigestValueType const& other) : TypeBase(other.GetNode()) {}
        
        
        CHMACOutputLengthType::CHMACOutputLengthType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CHMACOutputLengthType::CHMACOutputLengthType(CHMACOutputLengthType const& other) : TypeBase(other.GetNode()) {}
        
        
        CKeyInfoType::CKeyInfoType(xercesc::DOMNode* const& node) : TypeBase(node)
        , Id(*this)    // "@Id"
        , KeyName(*this)    // "KeyName"
        , KeyValue(*this)    // "KeyValue"
        , RetrievalMethod(*this)    // "RetrievalMethod"
        , X509Data(*this)    // "X509Data"
        , PGPData(*this)    // "PGPData"
        , SPKIData(*this)    // "SPKIData"
        , MgmtData(*this)    // "MgmtData"
        {}
        
        CKeyInfoType::CKeyInfoType(CKeyInfoType const& other) : TypeBase(other.GetNode())
        , Id(*this)    // "@Id"
        , KeyName(*this)    // "KeyName"
        , KeyValue(*this)    // "KeyValue"
        , RetrievalMethod(*this)    // "RetrievalMethod"
        , X509Data(*this)    // "X509Data"
        , PGPData(*this)    // "PGPData"
        , SPKIData(*this)    // "SPKIData"
        , MgmtData(*this)    // "MgmtData"
        {}
        
        void CKeyInfoType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("KeyInfoType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CKeyValueType::CKeyValueType(xercesc::DOMNode* const& node) : TypeBase(node)
        , DSAKeyValue(*this)    // "DSAKeyValue"
        , RSAKeyValue(*this)    // "RSAKeyValue"
        {}
        
        CKeyValueType::CKeyValueType(CKeyValueType const& other) : TypeBase(other.GetNode())
        , DSAKeyValue(*this)    // "DSAKeyValue"
        , RSAKeyValue(*this)    // "RSAKeyValue"
        {}
        
        void CKeyValueType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("KeyValueType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CManifestType::CManifestType(xercesc::DOMNode* const& node) : TypeBase(node)
        , Id(*this)    // "@Id"
        , Reference(*this)    // "Reference"
        {}
        
        CManifestType::CManifestType(CManifestType const& other) : TypeBase(other.GetNode())
        , Id(*this)    // "@Id"
        , Reference(*this)    // "Reference"
        {}
        
        void CManifestType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ManifestType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CObjectType::CObjectType(xercesc::DOMNode* const& node) : TypeBase(node)
        , Id(*this)    // "@Id"
        , MimeType(*this)    // "@MimeType"
        , Encoding(*this)    // "@Encoding"
        {}
        
        CObjectType::CObjectType(CObjectType const& other) : TypeBase(other.GetNode())
        , Id(*this)    // "@Id"
        , MimeType(*this)    // "@MimeType"
        , Encoding(*this)    // "@Encoding"
        {}
        
        void CObjectType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ObjectType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CPGPDataType::CPGPDataType(xercesc::DOMNode* const& node) : TypeBase(node)
        , PGPKeyID(*this)    // "PGPKeyID"
        , PGPKeyPacket(*this)    // "PGPKeyPacket"
        {}
        
        CPGPDataType::CPGPDataType(CPGPDataType const& other) : TypeBase(other.GetNode())
        , PGPKeyID(*this)    // "PGPKeyID"
        , PGPKeyPacket(*this)    // "PGPKeyPacket"
        {}
        
        void CPGPDataType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("PGPDataType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CRSAKeyValueType::CRSAKeyValueType(xercesc::DOMNode* const& node) : TypeBase(node)
        , Modulus(*this)    // "Modulus"
        , Exponent(*this)    // "Exponent"
        {}
        
        CRSAKeyValueType::CRSAKeyValueType(CRSAKeyValueType const& other) : TypeBase(other.GetNode())
        , Modulus(*this)    // "Modulus"
        , Exponent(*this)    // "Exponent"
        {}
        
        void CRSAKeyValueType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("RSAKeyValueType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CReferenceType::CReferenceType(xercesc::DOMNode* const& node) : TypeBase(node)
        , Id(*this)    // "@Id"
        , URI(*this)    // "@URI"
        , Type(*this)    // "@Type"
        , Transforms(*this)    // "Transforms"
        , DigestMethod(*this)    // "DigestMethod"
        , DigestValue(*this)    // "DigestValue"
        {}
        
        CReferenceType::CReferenceType(CReferenceType const& other) : TypeBase(other.GetNode())
        , Id(*this)    // "@Id"
        , URI(*this)    // "@URI"
        , Type(*this)    // "@Type"
        , Transforms(*this)    // "Transforms"
        , DigestMethod(*this)    // "DigestMethod"
        , DigestValue(*this)    // "DigestValue"
        {}
        
        void CReferenceType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("ReferenceType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CRetrievalMethodType::CRetrievalMethodType(xercesc::DOMNode* const& node) : TypeBase(node)
        , URI(*this)    // "@URI"
        , Type(*this)    // "@Type"
        , Transforms(*this)    // "Transforms"
        {}
        
        CRetrievalMethodType::CRetrievalMethodType(CRetrievalMethodType const& other) : TypeBase(other.GetNode())
        , URI(*this)    // "@URI"
        , Type(*this)    // "@Type"
        , Transforms(*this)    // "Transforms"
        {}
        
        void CRetrievalMethodType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("RetrievalMethodType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CSPKIDataType::CSPKIDataType(xercesc::DOMNode* const& node) : TypeBase(node)
        , SPKISexp(*this)    // "SPKISexp"
        {}
        
        CSPKIDataType::CSPKIDataType(CSPKIDataType const& other) : TypeBase(other.GetNode())
        , SPKISexp(*this)    // "SPKISexp"
        {}
        
        void CSPKIDataType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("SPKIDataType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CSignatureMethodType::CSignatureMethodType(xercesc::DOMNode* const& node) : TypeBase(node)
        , Algorithm(*this)    // "@Algorithm"
        , HMACOutputLength(*this)    // "HMACOutputLength"
        {}
        
        CSignatureMethodType::CSignatureMethodType(CSignatureMethodType const& other) : TypeBase(other.GetNode())
        , Algorithm(*this)    // "@Algorithm"
        , HMACOutputLength(*this)    // "HMACOutputLength"
        {}
        
        void CSignatureMethodType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("SignatureMethodType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CSignaturePropertiesType::CSignaturePropertiesType(xercesc::DOMNode* const& node) : TypeBase(node)
        , Id(*this)    // "@Id"
        , SignatureProperty(*this)    // "SignatureProperty"
        {}
        
        CSignaturePropertiesType::CSignaturePropertiesType(CSignaturePropertiesType const& other) : TypeBase(other.GetNode())
        , Id(*this)    // "@Id"
        , SignatureProperty(*this)    // "SignatureProperty"
        {}
        
        void CSignaturePropertiesType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("SignaturePropertiesType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CSignaturePropertyType::CSignaturePropertyType(xercesc::DOMNode* const& node) : TypeBase(node)
        , Target(*this)    // "@Target"
        , Id(*this)    // "@Id"
        {}
        
        CSignaturePropertyType::CSignaturePropertyType(CSignaturePropertyType const& other) : TypeBase(other.GetNode())
        , Target(*this)    // "@Target"
        , Id(*this)    // "@Id"
        {}
        
        void CSignaturePropertyType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("SignaturePropertyType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CSignatureType::CSignatureType(xercesc::DOMNode* const& node) : TypeBase(node)
        , Id(*this)    // "@Id"
        , SignedInfo(*this)    // "SignedInfo"
        , SignatureValue(*this)    // "SignatureValue"
        , KeyInfo(*this)    // "KeyInfo"
        , Object(*this)    // "Object"
        {}
        
        CSignatureType::CSignatureType(CSignatureType const& other) : TypeBase(other.GetNode())
        , Id(*this)    // "@Id"
        , SignedInfo(*this)    // "SignedInfo"
        , SignatureValue(*this)    // "SignatureValue"
        , KeyInfo(*this)    // "KeyInfo"
        , Object(*this)    // "Object"
        {}
        
        void CSignatureType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("SignatureType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CSignatureValueType::CSignatureValueType(xercesc::DOMNode* const& node)
        : ::oval_definitions_schema::xs::Cbase64BinaryType(node)
        , Id(*this)    // "@Id"
        {}
        
        CSignatureValueType::CSignatureValueType(CSignatureValueType const& other)
        : ::oval_definitions_schema::xs::Cbase64BinaryType(other.GetNode())
        , Id(*this)    // "@Id"
        {}
        
        void CSignatureValueType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("SignatureValueType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CSignedInfoType::CSignedInfoType(xercesc::DOMNode* const& node) : TypeBase(node)
        , Id(*this)    // "@Id"
        , CanonicalizationMethod(*this)    // "CanonicalizationMethod"
        , SignatureMethod(*this)    // "SignatureMethod"
        , Reference(*this)    // "Reference"
        {}
        
        CSignedInfoType::CSignedInfoType(CSignedInfoType const& other) : TypeBase(other.GetNode())
        , Id(*this)    // "@Id"
        , CanonicalizationMethod(*this)    // "CanonicalizationMethod"
        , SignatureMethod(*this)    // "SignatureMethod"
        , Reference(*this)    // "Reference"
        {}
        
        void CSignedInfoType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("SignedInfoType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CTransformType::CTransformType(xercesc::DOMNode* const& node) : TypeBase(node)
        , Algorithm(*this)    // "@Algorithm"
        , XPath(*this)    // "XPath"
        {}
        
        CTransformType::CTransformType(CTransformType const& other) : TypeBase(other.GetNode())
        , Algorithm(*this)    // "@Algorithm"
        , XPath(*this)    // "XPath"
        {}
        
        void CTransformType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("TransformType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CTransformsType::CTransformsType(xercesc::DOMNode* const& node) : TypeBase(node)
        , Transform(*this)    // "Transform"
        {}
        
        CTransformsType::CTransformsType(CTransformsType const& other) : TypeBase(other.GetNode())
        , Transform(*this)    // "Transform"
        {}
        
        void CTransformsType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("TransformsType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CX509DataType::CX509DataType(xercesc::DOMNode* const& node) : TypeBase(node)
        , X509IssuerSerial(*this)    // "X509IssuerSerial"
        , X509SKI(*this)    // "X509SKI"
        , X509SubjectName(*this)    // "X509SubjectName"
        , X509Certificate(*this)    // "X509Certificate"
        , X509CRL(*this)    // "X509CRL"
        {}
        
        CX509DataType::CX509DataType(CX509DataType const& other) : TypeBase(other.GetNode())
        , X509IssuerSerial(*this)    // "X509IssuerSerial"
        , X509SKI(*this)    // "X509SKI"
        , X509SubjectName(*this)    // "X509SubjectName"
        , X509Certificate(*this)    // "X509Certificate"
        , X509CRL(*this)    // "X509CRL"
        {}
        
        void CX509DataType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("X509DataType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CX509IssuerSerialType::CX509IssuerSerialType(xercesc::DOMNode* const& node) : TypeBase(node)
        , X509IssuerName(*this)    // "X509IssuerName"
        , X509SerialNumber(*this)    // "X509SerialNumber"
        {}
        
        CX509IssuerSerialType::CX509IssuerSerialType(CX509IssuerSerialType const& other) : TypeBase(other.GetNode())
        , X509IssuerName(*this)    // "X509IssuerName"
        , X509SerialNumber(*this)    // "X509SerialNumber"
        {}
        
        void CX509IssuerSerialType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("X509IssuerSerialType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CDigestValueTypeType::CDigestValueTypeType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CDigestValueTypeType::CDigestValueTypeType(CDigestValueTypeType const& other) : TypeBase(other.GetNode()) {}
        
        void CDigestValueTypeType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("DigestValueType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CCryptoBinaryType::CCryptoBinaryType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CCryptoBinaryType::CCryptoBinaryType(CCryptoBinaryType const& other) : TypeBase(other.GetNode()) {}
        
        void CCryptoBinaryType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("CryptoBinary"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
        CHMACOutputLengthTypeType::CHMACOutputLengthTypeType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CHMACOutputLengthTypeType::CHMACOutputLengthTypeType(CHMACOutputLengthTypeType const& other) : TypeBase(other.GetNode()) {}
        
        void CHMACOutputLengthTypeType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("HMACOutputLengthType"), _T("http://www.w3.org/2000/09/xmldsig#"));
        }
        
    } // namespace ds
    
    
    namespace xs
    {
        
        CENTITIES::CENTITIES(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CENTITIES::CENTITIES(CENTITIES const& other) : TypeBase(other.GetNode()) {}
        
        
        CENTITY::CENTITY(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CENTITY::CENTITY(CENTITY const& other) : TypeBase(other.GetNode()) {}
        
        
        CID::CID(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CID::CID(CID const& other) : TypeBase(other.GetNode()) {}
        
        
        CIDREF::CIDREF(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CIDREF::CIDREF(CIDREF const& other) : TypeBase(other.GetNode()) {}
        
        
        CIDREFS::CIDREFS(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CIDREFS::CIDREFS(CIDREFS const& other) : TypeBase(other.GetNode()) {}
        
        
        CNCName::CNCName(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CNCName::CNCName(CNCName const& other) : TypeBase(other.GetNode()) {}
        
        
        CNMTOKEN::CNMTOKEN(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CNMTOKEN::CNMTOKEN(CNMTOKEN const& other) : TypeBase(other.GetNode()) {}
        
        
        CNMTOKENS::CNMTOKENS(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CNMTOKENS::CNMTOKENS(CNMTOKENS const& other) : TypeBase(other.GetNode()) {}
        
        
        CNOTATION::CNOTATION(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CNOTATION::CNOTATION(CNOTATION const& other) : TypeBase(other.GetNode()) {}
        
        
        CName::CName(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CName::CName(CName const& other) : TypeBase(other.GetNode()) {}
        
        
        CQName::CQName(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CQName::CQName(CQName const& other) : TypeBase(other.GetNode()) {}
        
        
        CanySimpleType::CanySimpleType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CanySimpleType::CanySimpleType(CanySimpleType const& other) : TypeBase(other.GetNode()) {}
        
        
        CanyType::CanyType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CanyType::CanyType(CanyType const& other) : TypeBase(other.GetNode()) {}
        
        void CanyType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("anyType"), _T("http://www.w3.org/2001/XMLSchema"));
        }
        
        CanyURI::CanyURI(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CanyURI::CanyURI(CanyURI const& other) : TypeBase(other.GetNode()) {}
        
        
        Cbase64Binary::Cbase64Binary(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Cbase64Binary::Cbase64Binary(Cbase64Binary const& other) : TypeBase(other.GetNode()) {}
        
        
        Cboolean::Cboolean(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Cboolean::Cboolean(Cboolean const& other) : TypeBase(other.GetNode()) {}
        
        
        Cbyte::Cbyte(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Cbyte::Cbyte(Cbyte const& other) : TypeBase(other.GetNode()) {}
        
        
        Cdate::Cdate(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Cdate::Cdate(Cdate const& other) : TypeBase(other.GetNode()) {}
        
        
        CdateTime::CdateTime(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CdateTime::CdateTime(CdateTime const& other) : TypeBase(other.GetNode()) {}
        
        
        Cdecimal::Cdecimal(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Cdecimal::Cdecimal(Cdecimal const& other) : TypeBase(other.GetNode()) {}
        
        
        Cdouble::Cdouble(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Cdouble::Cdouble(Cdouble const& other) : TypeBase(other.GetNode()) {}
        
        
        Cduration::Cduration(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Cduration::Cduration(Cduration const& other) : TypeBase(other.GetNode()) {}
        
        
        Cfloat::Cfloat(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Cfloat::Cfloat(Cfloat const& other) : TypeBase(other.GetNode()) {}
        
        
        CgDay::CgDay(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CgDay::CgDay(CgDay const& other) : TypeBase(other.GetNode()) {}
        
        
        CgMonth::CgMonth(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CgMonth::CgMonth(CgMonth const& other) : TypeBase(other.GetNode()) {}
        
        
        CgMonthDay::CgMonthDay(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CgMonthDay::CgMonthDay(CgMonthDay const& other) : TypeBase(other.GetNode()) {}
        
        
        CgYear::CgYear(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CgYear::CgYear(CgYear const& other) : TypeBase(other.GetNode()) {}
        
        
        CgYearMonth::CgYearMonth(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CgYearMonth::CgYearMonth(CgYearMonth const& other) : TypeBase(other.GetNode()) {}
        
        
        ChexBinary::ChexBinary(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        ChexBinary::ChexBinary(ChexBinary const& other) : TypeBase(other.GetNode()) {}
        
        
        Cint::Cint(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Cint::Cint(Cint const& other) : TypeBase(other.GetNode()) {}
        
        
        Cinteger::Cinteger(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Cinteger::Cinteger(Cinteger const& other) : TypeBase(other.GetNode()) {}
        
        
        Clanguage::Clanguage(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Clanguage::Clanguage(Clanguage const& other) : TypeBase(other.GetNode()) {}
        
        
        Clong::Clong(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Clong::Clong(Clong const& other) : TypeBase(other.GetNode()) {}
        
        
        CnegativeInteger::CnegativeInteger(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CnegativeInteger::CnegativeInteger(CnegativeInteger const& other) : TypeBase(other.GetNode()) {}
        
        
        CnonNegativeInteger::CnonNegativeInteger(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CnonNegativeInteger::CnonNegativeInteger(CnonNegativeInteger const& other) : TypeBase(other.GetNode()) {}
        
        
        CnonPositiveInteger::CnonPositiveInteger(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CnonPositiveInteger::CnonPositiveInteger(CnonPositiveInteger const& other) : TypeBase(other.GetNode()) {}
        
        
        CnormalizedString::CnormalizedString(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CnormalizedString::CnormalizedString(CnormalizedString const& other) : TypeBase(other.GetNode()) {}
        
        
        CpositiveInteger::CpositiveInteger(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CpositiveInteger::CpositiveInteger(CpositiveInteger const& other) : TypeBase(other.GetNode()) {}
        
        
        Cshort::Cshort(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Cshort::Cshort(Cshort const& other) : TypeBase(other.GetNode()) {}
        
        
        Cstring::Cstring(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Cstring::Cstring(Cstring const& other) : TypeBase(other.GetNode()) {}
        
        
        Ctime::Ctime(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Ctime::Ctime(Ctime const& other) : TypeBase(other.GetNode()) {}
        
        
        Ctoken::Ctoken(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Ctoken::Ctoken(Ctoken const& other) : TypeBase(other.GetNode()) {}
        
        
        CunsignedByte::CunsignedByte(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CunsignedByte::CunsignedByte(CunsignedByte const& other) : TypeBase(other.GetNode()) {}
        
        
        CunsignedInt::CunsignedInt(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CunsignedInt::CunsignedInt(CunsignedInt const& other) : TypeBase(other.GetNode()) {}
        
        
        CunsignedLong::CunsignedLong(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CunsignedLong::CunsignedLong(CunsignedLong const& other) : TypeBase(other.GetNode()) {}
        
        
        CunsignedShort::CunsignedShort(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CunsignedShort::CunsignedShort(CunsignedShort const& other) : TypeBase(other.GetNode()) {}
        
        
        CstringType::CstringType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CstringType::CstringType(CstringType const& other) : TypeBase(other.GetNode()) {}
        
        void CstringType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("string"), _T("http://www.w3.org/2001/XMLSchema"));
        }
        
        CNCNameType::CNCNameType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CNCNameType::CNCNameType(CNCNameType const& other) : TypeBase(other.GetNode()) {}
        
        void CNCNameType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("NCName"), _T("http://www.w3.org/2001/XMLSchema"));
        }
        
        CdateTimeType::CdateTimeType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CdateTimeType::CdateTimeType(CdateTimeType const& other) : TypeBase(other.GetNode()) {}
        
        void CdateTimeType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("dateTime"), _T("http://www.w3.org/2001/XMLSchema"));
        }
        
        CanySimpleTypeType::CanySimpleTypeType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CanySimpleTypeType::CanySimpleTypeType(CanySimpleTypeType const& other) : TypeBase(other.GetNode()) {}
        
        void CanySimpleTypeType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("anySimpleType"), _T("http://www.w3.org/2001/XMLSchema"));
        }
        
        Cbase64BinaryType::Cbase64BinaryType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        Cbase64BinaryType::Cbase64BinaryType(Cbase64BinaryType const& other) : TypeBase(other.GetNode()) {}
        
        void Cbase64BinaryType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("base64Binary"), _T("http://www.w3.org/2001/XMLSchema"));
        }
        
        CintegerType::CintegerType(xercesc::DOMNode* const& node) : TypeBase(node) {}
        
        CintegerType::CintegerType(CintegerType const& other) : TypeBase(other.GetNode()) {}
        
        void CintegerType::SetXsiType()
        {
            XercesTreeOperations::SetAttribute(m_node, _T("xsi:type"), _T("http://www.w3.org/2001/XMLSchema-instance"),
                                               _T("integer"), _T("http://www.w3.org/2001/XMLSchema"));
        }
        
    } // namespace xs
    
    
    namespace oval
    {
        
        void CElementMapItemType::operator=(const string_type& value) {
            CNCNameType::operator=(value);
        }
        
        void CMessageType::operator=(const string_type& value) {
            CstringType::operator=(value);
        }
        
        void CSchemaVersionType::operator=(const string_type& value) {
            CSchemaVersionPatternType::operator=(value);
        }
        
        void CStateIDPatternType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_CStateIDPatternType_unnamed, value);
        }
        
        CStateIDPatternType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_CStateIDPatternType_unnamed);
        }
        
        void CObjectIDPatternType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_CObjectIDPatternType_unnamed, value);
        }
        
        CObjectIDPatternType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_CObjectIDPatternType_unnamed);
        }
        
        void CversionType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_CversionType_unnamed, value);
        }
        
        CversionType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_CversionType_unnamed);
        }
        
        void CSchemaVersionPatternType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_CSchemaVersionPatternType_unnamed, value);
        }
        
        CSchemaVersionPatternType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_CSchemaVersionPatternType_unnamed);
        }
        
    } // namespace oval
    
    
    namespace oval_def
    {
        
        void CEntityObjectAnySimpleType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityObjectAnySimpleType_unnamed, value);
        }
        
        CEntityObjectAnySimpleType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityObjectAnySimpleType_unnamed);
        }
        
        void CEntityObjectBinaryType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityObjectBinaryType_unnamed, value);
        }
        
        CEntityObjectBinaryType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityObjectBinaryType_unnamed);
        }
        
        void CEntityObjectBoolType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityObjectBoolType_unnamed, value);
        }
        
        CEntityObjectBoolType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityObjectBoolType_unnamed);
        }
        
        void CEntityObjectFieldType::operator=(const string_type& value) {
            CanySimpleTypeType::operator=(value);
        }
        
        void CEntityObjectFloatType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityObjectFloatType_unnamed, value);
        }
        
        CEntityObjectFloatType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityObjectFloatType_unnamed);
        }
        
        void CEntityObjectIPAddressStringType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityObjectIPAddressStringType_unnamed, value);
        }
        
        CEntityObjectIPAddressStringType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityObjectIPAddressStringType_unnamed);
        }
        
        void CEntityObjectIPAddressType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityObjectIPAddressType_unnamed, value);
        }
        
        CEntityObjectIPAddressType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityObjectIPAddressType_unnamed);
        }
        
        void CEntityObjectIntType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityObjectIntType_unnamed, value);
        }
        
        CEntityObjectIntType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityObjectIntType_unnamed);
        }
        
        void CEntityObjectStringType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityObjectStringType_unnamed, value);
        }
        
        CEntityObjectStringType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityObjectStringType_unnamed);
        }
        
        void CEntityObjectVersionType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityObjectVersionType_unnamed, value);
        }
        
        CEntityObjectVersionType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityObjectVersionType_unnamed);
        }
        
        void CEntitySimpleBaseType::operator=(const string_type& value) {
            CanySimpleTypeType::operator=(value);
        }
        
        void CEntityStateAnySimpleType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityStateAnySimpleType_unnamed, value);
        }
        
        CEntityStateAnySimpleType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityStateAnySimpleType_unnamed);
        }
        
        void CEntityStateBinaryType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityStateBinaryType_unnamed, value);
        }
        
        CEntityStateBinaryType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityStateBinaryType_unnamed);
        }
        
        void CEntityStateBoolType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityStateBoolType_unnamed, value);
        }
        
        CEntityStateBoolType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityStateBoolType_unnamed);
        }
        
        void CEntityStateDebianEVRStringType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityStateDebianEVRStringType_unnamed, value);
        }
        
        CEntityStateDebianEVRStringType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityStateDebianEVRStringType_unnamed);
        }
        
        void CEntityStateEVRStringType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityStateEVRStringType_unnamed, value);
        }
        
        CEntityStateEVRStringType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityStateEVRStringType_unnamed);
        }
        
        void CEntityStateFieldType::operator=(const string_type& value) {
            CanySimpleTypeType::operator=(value);
        }
        
        void CEntityStateFileSetRevisionType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityStateFileSetRevisionType_unnamed, value);
        }
        
        CEntityStateFileSetRevisionType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityStateFileSetRevisionType_unnamed);
        }
        
        void CEntityStateFloatType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityStateFloatType_unnamed, value);
        }
        
        CEntityStateFloatType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityStateFloatType_unnamed);
        }
        
        void CEntityStateIOSVersionType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityStateIOSVersionType_unnamed, value);
        }
        
        CEntityStateIOSVersionType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityStateIOSVersionType_unnamed);
        }
        
        void CEntityStateIPAddressStringType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityStateIPAddressStringType_unnamed, value);
        }
        
        CEntityStateIPAddressStringType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityStateIPAddressStringType_unnamed);
        }
        
        void CEntityStateIPAddressType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityStateIPAddressType_unnamed, value);
        }
        
        CEntityStateIPAddressType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityStateIPAddressType_unnamed);
        }
        
        void CEntityStateIntType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityStateIntType_unnamed, value);
        }
        
        CEntityStateIntType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityStateIntType_unnamed);
        }
        
        void CEntityStateSimpleBaseType::operator=(const string_type& value) {
            CEntitySimpleBaseType::operator=(value);
        }
        
        void CEntityStateStringType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityStateStringType_unnamed, value);
        }
        
        CEntityStateStringType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityStateStringType_unnamed);
        }
        
        void CEntityStateVersionType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_oval_def_CEntityStateVersionType_unnamed, value);
        }
        
        CEntityStateVersionType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_oval_def_CEntityStateVersionType_unnamed);
        }
        
        void CLiteralComponentType::operator=(const string_type& value) {
            CanySimpleTypeType::operator=(value);
        }
        
        void CPossibleValueType::operator=(const string_type& value) {
            CanySimpleTypeType::operator=(value);
        }
        
        void CRestrictionType::operator=(const string_type& value) {
            CanySimpleTypeType::operator=(value);
        }
        
        void CValueType::operator=(const string_type& value) {
            CanySimpleTypeType::operator=(value);
        }
        
        void CfilterType::operator=(const string_type& value) {
            CStateIDPatternType::operator=(value);
        }
        
    } // namespace oval_def
    
    
    namespace ds
    {
        
        void CCanonicalizationMethodType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmldsig_CCanonicalizationMethodType_unnamed, value);
        }
        
        CCanonicalizationMethodType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_xmldsig_CCanonicalizationMethodType_unnamed);
        }
        
        void CDigestMethodType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmldsig_CDigestMethodType_unnamed, value);
        }
        
        CDigestMethodType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_xmldsig_CDigestMethodType_unnamed);
        }
        
        void CKeyInfoType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmldsig_CKeyInfoType_unnamed, value);
        }
        
        CKeyInfoType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_xmldsig_CKeyInfoType_unnamed);
        }
        
        void CKeyValueType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmldsig_CKeyValueType_unnamed, value);
        }
        
        CKeyValueType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_xmldsig_CKeyValueType_unnamed);
        }
        
        void CObjectType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmldsig_CObjectType_unnamed, value);
        }
        
        CObjectType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_xmldsig_CObjectType_unnamed);
        }
        
        void CSignatureMethodType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmldsig_CSignatureMethodType_unnamed, value);
        }
        
        CSignatureMethodType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_xmldsig_CSignatureMethodType_unnamed);
        }
        
        void CSignaturePropertyType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmldsig_CSignaturePropertyType_unnamed, value);
        }
        
        CSignaturePropertyType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_xmldsig_CSignaturePropertyType_unnamed);
        }
        
        void CSignatureValueType::operator=(const std::vector<unsigned char>& value) {
            Cbase64BinaryType::operator=(value);
        }
        
        void CTransformType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmldsig_CTransformType_unnamed, value);
        }
        
        CTransformType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_xmldsig_CTransformType_unnamed);
        }
        
        void CDigestValueTypeType::operator=(const std::vector<unsigned char>& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmldsig_CDigestValueTypeType_unnamed, value);
        }
        
        CDigestValueTypeType::operator std::vector<unsigned char>() {
            return CastAs<std::vector<unsigned char> >::Do(GetNode(), members + conforme_mi_xmldsig_CDigestValueTypeType_unnamed);
        }
        
        void CCryptoBinaryType::operator=(const std::vector<unsigned char>& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmldsig_CCryptoBinaryType_unnamed, value);
        }
        
        CCryptoBinaryType::operator std::vector<unsigned char>() {
            return CastAs<std::vector<unsigned char> >::Do(GetNode(), members + conforme_mi_xmldsig_CCryptoBinaryType_unnamed);
        }
        
        void CHMACOutputLengthTypeType::operator=(const __int64& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmldsig_CHMACOutputLengthTypeType_unnamed, value);
        }
        
        CHMACOutputLengthTypeType::operator __int64() {
            return CastAs<__int64 >::Do(GetNode(), members + conforme_mi_xmldsig_CHMACOutputLengthTypeType_unnamed);
        }
        
    } // namespace ds
    
    
    namespace xs
    {
        
        void CanyType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmlschema_CanyType_unnamed, value);
        }
        
        CanyType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_xmlschema_CanyType_unnamed);
        }
        
        void CstringType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmlschema_CstringType_unnamed, value);
        }
        
        CstringType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_xmlschema_CstringType_unnamed);
        }
        
        void CNCNameType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmlschema_CNCNameType_unnamed, value);
        }
        
        CNCNameType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_xmlschema_CNCNameType_unnamed);
        }
        
        void CdateTimeType::operator=(const conforme::DateTime& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmlschema_CdateTimeType_unnamed, value);
        }
        
        CdateTimeType::operator conforme::DateTime() {
            return CastAs<conforme::DateTime >::Do(GetNode(), members + conforme_mi_xmlschema_CdateTimeType_unnamed);
        }
        
        void CanySimpleTypeType::operator=(const string_type& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmlschema_CanySimpleTypeType_unnamed, value);
        }
        
        CanySimpleTypeType::operator string_type() {
            return CastAs<string_type >::Do(GetNode(), members + conforme_mi_xmlschema_CanySimpleTypeType_unnamed);
        }
        
        void Cbase64BinaryType::operator=(const std::vector<unsigned char>& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmlschema_Cbase64BinaryType_unnamed, value);
        }
        
        Cbase64BinaryType::operator std::vector<unsigned char>() {
            return CastAs<std::vector<unsigned char> >::Do(GetNode(), members + conforme_mi_xmlschema_Cbase64BinaryType_unnamed);
        }
        
        void CintegerType::operator=(const __int64& value) {
            XercesTreeOperations::SetValue(GetNode(), members + conforme_mi_xmlschema_CintegerType_unnamed, value);
        }
        
        CintegerType::operator __int64() {
            return CastAs<__int64 >::Do(GetNode(), members + conforme_mi_xmlschema_CintegerType_unnamed);
        }
        
    } // namespace xs
    
    
}
