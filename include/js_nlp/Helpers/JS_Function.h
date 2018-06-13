#pragma once

#include "Helpers.h"


namespace js_nlp
{

struct JS_Function
{
    JS_Function (emscripten::val);

    double operator () (const nlpp::Vec&);


    emscripten::val f;
};

} // namespace js_nlp