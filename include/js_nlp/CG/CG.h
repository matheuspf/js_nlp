#pragma once

#include <nlpp/CG/CG.h>
#include <nlpp/LineSearch/Dynamic/Dynamic.h>

#include "Helpers/Optimizer.h"


namespace js_nlp
{

struct CG : public nlpp::CG<nlpp::FR_PR, nlpp::DynamicLineSearch<JS_Function>, stop::GradientOptimizer, out::Optimizer>,
            public Optimizer<CG>
{
    using Base = nlpp::CG<nlpp::FR_PR, nlpp::DynamicLineSearch<JS_Function>, stop::GradientOptimizer, out::Optimizer>;

    CG();
    CG(emscripten::val);

    CG(std::string, emscripten::val);

    using Optimizer<CG>::optimize;
};

}