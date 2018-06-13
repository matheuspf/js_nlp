#pragma once


#include <nlpp/LineSearch/Dynamic/Dynamic.h>

#include "Helpers/JS_Function.h"


namespace js_nlp
{

struct DynamicLineSearch : public nlpp::DynamicLineSearch<JS_Function>
{
    using Base = nlpp::DynamicLineSearch<JS_Function>;
    // using Base::Base;

    DynamicLineSearch ();
    DynamicLineSearch (const nlpp::DynamicLineSearch<JS_Function>&);
    DynamicLineSearch (std::string);
};

}