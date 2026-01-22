////////////////////////////////////////////////////////////////////////
//
//  Type_DS.CHMACOutputLengthType.hpp
//  ConformeOVAL
//
//  Created by Thomas on 1/30/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#ifndef _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CHMACOUTPUTLENGTHTYPE_H_
#define _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CHMACOUTPUTLENGTHTYPE_H_



namespace oval_definitions_schema
{

namespace ds
{	

class CHMACOutputLengthType : public TypeBase
{
public:
	OVAL_DEFINITIONS_SCHEMA_EXPORT CHMACOutputLengthType(xercesc::DOMNode* const& init);
	OVAL_DEFINITIONS_SCHEMA_EXPORT CHMACOutputLengthType(CHMACOutputLengthType const& init);
    
    void operator=(CHMACOutputLengthType const& other) { m_node = other.m_node; }
    
	static conforme::meta::SimpleType StaticInfo() { return conforme::meta::SimpleType(types + conforme_ti_xmldsig_CHMACOutputLengthType); }
	void operator= (const __int64& value) 
	{
		conforme::XmlFormatter* Formatter = static_cast<conforme::XmlFormatter*>(conforme::IntegerFormatter);
		XercesTreeOperations::SetValue(GetNode(), Formatter->Format(value));
	}	
		
	operator __int64()
	{
		return CastAs<__int64 >::Do(GetNode(), 0);
	}
};



} // namespace ds

}	// namespace oval_definitions_schema

#endif // _CONFORME_INCLUDED_OVAL_DEFINITIONS_SCHEMA_DS_CHMACOUTPUTLENGTHTYPE_H_
