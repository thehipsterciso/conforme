//
//  ConformeDefinitions.hpp
//  conforme
//
//  Created by Thomas on 1/15/18.
//  Copyright © 2018 Thomas Jones. All rights reserved.
//

#pragma once
#ifndef CONFORMEDEFINITIONS_HPP
#define CONFORMEDEFINITIONS_HPP

#if !defined( __GNUC__ )
#ifdef CONFORME_EXPORTS
#define CONFORME_DECLSPECIFIER __declspec(dllexport)
#else
#define CONFORME_DECLSPECIFIER __declspec(dllimport)
#endif
#else
#define CONFORME_DECLSPECIFIER
#endif

#endif /* CONFORMEDEFINITIONS_H */
