#include "stdafx.h"
#pragma once

#include "Funcs.h"

double Funcs::KE(Body* body) {
    return 0.5 * std::pow(body->getDerivative(1).size(), 2) * (1 / body->getAttributes().compliance);
}

    
double Funcs::PE(Body* body) {
    return (1 / body->getAttributes().compliance) * 1000 * (1080 - body->getDerivative(0).get(1));
}

double Funcs::ME(Body* body) {
    return KE(body) + PE(body);
}

template <typename T>
bool Funcs::vector_contains(std::vector<T> vector, T obj) {
    auto it = std::find(vector.begin(), vector.end(), obj);

    return it != vector.end();
}
