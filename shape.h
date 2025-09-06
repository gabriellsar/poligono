#pragma once
#include <memory>
class Shape;
using ShapePtr = std::shared_ptr<Shape>; 

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
protected:
  Shape () = default;
public:
  virtual ~Shape () = default;
  virtual void Draw () = 0;
};

#endif
