// Parameter.h

#pragma once

template <typename T>
class Parameter {
public:
    Parameter() : data(nullptr) {}

    explicit Parameter(T paramT) : data(paramT) {}

    T data;
};

template <typename T>
class ParameterDesc {
public:
    ParameterDesc(T paramT, int paramInteger) : value(paramT), level(paramInteger) {}

    int level;
    T value;
};