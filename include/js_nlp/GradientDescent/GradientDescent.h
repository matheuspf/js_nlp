#pragma once

#include <nlpp/GradientDescent/GradientDescent.h>
#include <nlpp/LineSearch/Dynamic/Dynamic.h>

#include "Helpers/Optimizer.h"


namespace js_nlp
{

struct GD : public nlpp::GradientDescent<nlpp::DynamicLineSearch<JS_Function>, out::Optimizer>,
            public Optimizer<GD>
{
    using Base = nlpp::GradientDescent<nlpp::DynamicLineSearch<JS_Function>, out::Optimizer>;

    GD();
    GD(emscripten::val);

    GD(std::string, emscripten::val);

    using Optimizer<GD>::optimize;
};

}