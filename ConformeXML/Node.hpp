//
//  Node.hpp
//  conformexml
//
//  Created by Thomas on 1/15/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#pragma once
#ifndef CONFORMEXML_NODE_HPP
#define CONFORMEXML_NODE_HPP

#include "ConformeXMLAPI.hpp"
#include <Conforme/XSDatatypes.hpp>
#include <Conforme/SchemaTypes.hpp>

CONFORMEXML_DECLSPECIFIER string_type FindPrefixForNamespace(xercesc::DOMNode* node, const string_type& uri);
CONFORMEXML_DECLSPECIFIER string_type GetUnusedPrefix(xercesc::DOMNode* node, const string_type& prefixHint);

class CONFORMEXML_DECLSPECIFIER XercesTreeOperations
{
public:
    
    static void CopyAll(const xercesc::DOMNode* src, xercesc::DOMNode* tgt);
    
    class AllIterator
    {
        xercesc::DOMNode* m_Current;
    public:
        operator bool() const { return m_Current != 0; }
        bool operator++() { m_Current = m_Current->getNextSibling(); return m_Current != 0; }
        bool operator--() { m_Current = m_Current->getPreviousSibling(); return m_Current != 0; }
        xercesc::DOMNode* operator*() const { return m_Current; }
        
        AllIterator( xercesc::DOMNode* start ) : m_Current( start ) {}
    };
    
    class MemberIterator
    {
        AllIterator m_AllIterator;
        const conforme::MemberInfo* m_MemberInfo;
        
    public:
        operator bool() const { return m_AllIterator; }
        
        bool operator++()
        {
            while (++m_AllIterator)
            {
                if (IsMember(*m_AllIterator, m_MemberInfo))
                    return true;
            }
            return false;
        }
        
        bool operator--()
        {
            while (--m_AllIterator)
            {
                if (IsMember(*m_AllIterator, m_MemberInfo))
                    return true;
            }
            return false;
        }
        
        xercesc::DOMNode* operator*() const { return *m_AllIterator; }
        
        MemberIterator(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo)
        : m_AllIterator( pNode ), m_MemberInfo( pMemberInfo )
        {
            while (m_AllIterator && !IsMember(*m_AllIterator, m_MemberInfo))
                ++m_AllIterator;
        }
    };
    
    static bool IsEqualString(const XMLCh* a, const char_type* b);
    static bool IsMember(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMember);
    static bool IsValid(xercesc::DOMNode*  pNode);
    static AllIterator GetElements(xercesc::DOMNode* pNode);
    static MemberIterator GetElements(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo);
    static void SetTextValue(xercesc::DOMNode* pNode, const string_type& sText);
    static string_type GetTextValue(xercesc::DOMNode* pNode);
    static void SetValue(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo, const XMLCh* sValue);
    static void SetValue(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo, const string_type& sValue);
    static void SetValue(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo, bool b);
    static void SetValue(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo, int b);
    static void SetValue(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo, unsigned b);
    static void SetValue(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo, __int64 b);
    static void SetValue(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo, unsigned __int64 b);
    static void SetValue(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo, double b);
    static void SetValue(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo, conforme::DateTime b);
    static void SetValue(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo, conforme::Duration b);
    static void SetValue(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo, const std::vector<unsigned char>& b);
    static void SetValue(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo, const xercesc::DOMNode* b);
    static void SetValue(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo, const conforme::QName& qn);
    static xercesc::DOMNode* AddElement(xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo);
    
    static double CastToDouble(const xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo);
    static string_type CastToString(const xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo);
    static __int64 CastToInt64(const xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo);
    static unsigned __int64 CastToUInt64(const xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo);
    static unsigned CastToUInt(const xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo);
    static int CastToInt(const xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo);
    static bool CastToBool(const xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo);
    static conforme::DateTime CastToDateTime(const xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo);
    static conforme::Duration CastToDuration(const xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo);
    static std::vector<unsigned char> CastToBinary(const xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo);
    static conforme::QName CastToQName(const xercesc::DOMNode* pNode, const conforme::MemberInfo* pMemberInfo);
    static xercesc::DOMNode* FindAttribute(xercesc::DOMNode* pNode, const conforme::MemberInfo* member);
    
    static xercesc::DOMNode* GetParent(xercesc::DOMNode* pNode);
    static void SetValue(xercesc::DOMNode* pNode, const string_type& sValue);
    static void RemoveAttribute(xercesc::DOMNode* pNode, const conforme::MemberInfo* member);
    static void RemoveElements(xercesc::DOMNode* pNode, const conforme::MemberInfo* member);
    static void RemoveElement(xercesc::DOMNode* pNode, const conforme::MemberInfo* member, unsigned index);
    
    typedef xercesc::DOMDocument* DocumentType;
    
    static DocumentType LoadDocument(const string_type& filename);
    static void FreeDocument(DocumentType& document);
    static void FreeDocument(xercesc::DOMNode*& document);
    static void SaveDocument( const DocumentType& document, const string_type& filename, bool prettyPrint, const string_type& lineend );
    static void SaveDocument( const DocumentType& document, const string_type& filename, bool prettyPrint, bool omitXmlDecl, const string_type& lineend );
    static void SaveDocument( const DocumentType& document, const string_type& filename, bool prettyPrint, const string_type& encoding, bool bBigEndian, bool bBOM, const string_type& lineend );
    static void SaveDocument( const DocumentType& document, const string_type& filename, bool prettyPrint, bool omitXmlDecl, const string_type& encoding, bool bBigEndian, bool bBOM, const string_type& lineend );
    
    static DocumentType LoadXml(const string_type& xml);
    static DocumentType LoadFromBinary(const std::vector<unsigned char>& binary);
    static string_type SaveXml(const DocumentType& document, bool prettyPrint, const string_type& lineend);
    static string_type SaveXml(const DocumentType& document, bool prettyPrint, bool omitXmlDecl, const string_type& lineend);
    static std::vector<unsigned char> SaveToBinary(const DocumentType& document, bool prettyPrint, const string_type& lineend);
    static std::vector<unsigned char> SaveToBinary(const DocumentType& document, bool prettyPrint, bool omitXmlDecl, const string_type& lineend);
    static void SaveToBinary( std::vector<unsigned char>& result, const DocumentType& document, bool prettyPrint, const string_type& encoding, bool bBigEndian, bool bBOM, const string_type& lineend, bool bIncludeEncoding = true );
    
    static DocumentType CreateDocument();
    
    static void AddProcessingInstruction(xercesc::DOMNode* node, const string_type& target, const string_type& value);
    
    static void SetAttribute(xercesc::DOMNode* node, const string_type& localName, const string_type& namespaceURI, const string_type& value);
    static void SetAttribute(xercesc::DOMNode* node, const string_type& localName, const string_type& namespaceURI, const string_type& valueLocalName, const string_type& valueURI);
    
protected:
    static void CorrectByteOrderAndBOM( std::vector<unsigned char>& bytes, const string_type& encoding, bool bBigEndian, bool bBOM );
    static int GetEncodingAndByteOrderFromXml( std::vector<unsigned char>& sourceBytes );
    static int GetEncodingAndByteOrderFromXml( unsigned char* sourceBytes, int sourceLength );
    static int GetUnicodeSizeFromEncodingName( const string_type& encodingIn );
    static string_type Uppercase( const string_type& str );
};


#endif /* CONFORMEXML_NODE_HPP */

