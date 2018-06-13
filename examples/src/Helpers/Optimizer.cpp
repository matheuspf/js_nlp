#include "Helpers/Optimizer.h"

#include <nlpp/Helpers/FiniteDifference.h>



int main ()
{
    js_nlp::JS_Function js_func(emscripten::val(0));

    auto grad = nlpp::fd::gradient(js_func);




    return 0;
}