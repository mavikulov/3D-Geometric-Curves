#ifndef CURVE_TYPE_H_
#define CURVE_TYPE_H_

enum class CurveType {
    Circle,
    Ellipse,
    Helix,
    Unknown
};

CurveType ParseCurveType(char type) {
    switch (type) {
    case 'C':
        return CurveType::Circle;
    case 'E':
        return CurveType::Ellipse;
    case 'H':
        return CurveType::Helix;
    default:
        return CurveType::Unknown;
    }
}

#endif // CURVE_TYPE_H_
