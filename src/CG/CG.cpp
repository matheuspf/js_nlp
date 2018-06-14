#include "CG/CG.h"


namespace js_nlp
{

CG::CG ()
{
}

CG::CG(emscripten::val js_out) : Base(nlpp::DynamicLineSearch<JS_Function>{}, 
                                      nlpp::stop::GradientOptimizer{}, 
                                      js_nlp::out::Optimizer(js_out))
{
}

CG::CG(std::string ls, emscripten::val js_out) : Base(nlpp::DynamicLineSearch<JS_Function>(ls), 
                                                      nlpp::stop::GradientOptimizer{}, 
                                                      js_nlp::out::Optimizer(js_out))
{
}


} // namespace js_nlp


EMSCRIPTEN_BINDINGS(CG) {
    emscripten::class_<js_nlp::CG>("CG")
        .constructor<>()
        .constructor<emscripten::val>()
        .constructor<std::string, emscripten::val>()
        .function("optimize", static_cast<emscripten::val (js_nlp::CG::*)(emscripten::val, emscripten::val)>
                              (&js_nlp::CG::optimize))
        .property("lineSearch", &js_nlp::CG::getLineSearch, &js_nlp::CG::setLineSearch)
        .property("maxIterations", &js_nlp::CG::getMaxIterations, &js_nlp::CG::setMaxIterations)
        .property("fTol", &js_nlp::CG::getFTol, &js_nlp::CG::setFTol)
        .property("gTol", &js_nlp::CG::getGTol, &js_nlp::CG::setGTol)
        .property("xTol", &js_nlp::CG::getXTol, &js_nlp::CG::setXTol);
}