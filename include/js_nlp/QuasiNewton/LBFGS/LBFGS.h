#pragma once

#include <nlpp/QuasiNewton/LBFGS/LBFGS.h>

#include <nlpp/LineSearch/Dynamic/Dynamic.h>

#include "Helpers/Optimizer.h"


namespace js_nlp
{

struct LBFGS : public nlpp::LBFGS<nlpp::BFGS_Diagonal, nlpp::DynamicLineSearch<JS_Function>, 
                                  stop::GradientOptimizer, out::Optimizer>,
               public Optimizer<LBFGS>
{
    using Base = nlpp::LBFGS<nlpp::BFGS_Diagonal, nlpp::DynamicLineSearch<JS_Function>, 
                             stop::GradientOptimizer, out::Optimizer>;

    LBFGS();
    LBFGS(emscripten::val);

    LBFGS(std::string, emscripten::val);

    using Optimizer<LBFGS>::optimize;
};

}