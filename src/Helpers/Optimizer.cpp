#include "Helpers/Optimizer.h"




EMSCRIPTEN_BINDINGS(OptimizerBase) {

    emscripten::class_<js_nlp::stop::GradientOptimizer>("Stop")
        .constructor<>()
        .constructor<int, double, double, double>()
        .property("maxIterations", &js_nlp::stop::GradientOptimizer::getMaxIterations, &js_nlp::stop::GradientOptimizer::setMaxIterations)
        .property("fTol", &js_nlp::stop::GradientOptimizer::getFTol, &js_nlp::stop::GradientOptimizer::setFTol)
        .property("gTol", &js_nlp::stop::GradientOptimizer::getGTol, &js_nlp::stop::GradientOptimizer::setGTol)
        .property("xTol", &js_nlp::stop::GradientOptimizer::getXTol, &js_nlp::stop::GradientOptimizer::setXTol);



    emscripten::class_<js_nlp::out::Optimizer>("Output")
        .constructor<>()
        .constructor<emscripten::val>()
        .constructor<emscripten::val, emscripten::val>()
        .constructor<emscripten::val, emscripten::val, emscripten::val>()
        .property("init", &js_nlp::out::Optimizer::getInit, &js_nlp::out::Optimizer::setInit)
        .property("op", &js_nlp::out::Optimizer::getOp, &js_nlp::out::Optimizer::setOp)
        .property("finish", &js_nlp::out::Optimizer::getFinish, &js_nlp::out::Optimizer::setFinish);
}