#include "Helpers/JS_Function.h"


namespace js_nlp
{

JS_Function::JS_Function (emscripten::val f) : f(f) {}

double JS_Function::operator () (const nlpp::Vec& x)
{
    return f(emscripten::val(emscripten::typed_memory_view(x.size(), x.data()))).template as<double>();
}

} // namespace js_nlp


EMSCRIPTEN_BINDINGS(Function) {
    emscripten::class_<js_nlp::JS_Function>("Function")
        .constructor<emscripten::val>();
}