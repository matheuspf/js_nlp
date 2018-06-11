#include <nlpp/GradientDescent/GradientDescent.h>
#include "Helpers/Optimizer.h"


namespace js_nlp
{

struct GD : public nlpp::GradientDescent<nlpp::Goldstein, out::Optimizer>,
            public Optimizer<GD>
{
    using Base = nlpp::GradientDescent<nlpp::Goldstein, out::Optimizer>;

    GD();
    GD(emscripten::val);

    using Optimizer<GD>::optimize;
    using Optimizer<GD>::getMaxIterations;
    using Optimizer<GD>::setMaxIterations;
};

}