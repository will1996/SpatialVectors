#include"Spatial.hpp"
#include<stdexcept>
using namespace FeatherStone;
using namespace Spatial;
Vector::Vector(){
   position = glm::vec3{0,0,0} ;
   orientation = glm::vec3{0,0,0} ;
}
Vector::Vector(glm::vec3 inPos , glm::vec3 inOrien){
   position = inPos;
   orientation = inOrien;
}
Vector::Vector(double p0,double p1,double p2,double o0,double o1,double o2){
   position = glm::vec3{p0,p1,p2};
   orientation = glm::vec3{o0,o1,o2};
}
Vector::Vector(std::vector<double> Coords){
  if(Coords.size()!=6){
   throw std::logic_error("abstract coordinate vector must be of length six");
  }
  position = glm::vec3(Coords[0],Coords[1],Coords[2]);
  orientation= glm::vec3(Coords[3],Coords[4],Coords[5]);
}

glm::vec3 Vector::getPosition(){
  throw std::runtime_error("unimplemented");

}
glm::vec3 Vector::getOrientation(){
  throw std::runtime_error("unimplemented");
}
std::string Vector::stringify(){
  throw std::runtime_error("unimplemented");
}
double & Vector::operator[] (int){
  throw std::runtime_error("unimplemented");
}


double operator *(const Vector& lhs, const Vector& rhs){
  throw std::runtime_error("unimplemented");
}
Vector operator *(const double& lhs, const Vector & rhs){
  throw std::runtime_error("unimplemented");
}
Vector operator *(const Vector &lhs, const double & rhs){
  throw std::runtime_error("unimplemented");
}
Vector operator +(const Vector& lhs, const Vector& rhs){
  throw std::runtime_error("unimplemented");
}
Vector operator -(const Vector& lhs, const Vector& rhs){
  throw std::runtime_error("unimplemented");
}
//transformation
Operator operator *( const Operator &lhs, const Vector & rhs){
  throw std::runtime_error("unimplemented");
}
  //scale matrix
Operator operator *( const double &lhs, const Operator & rhs){
  throw std::runtime_error("unimplemented");
}
  //Spatial Operator arithmetic Operators 
Operator operator +( const Operator &lhs, const Operator & rhs){
  throw std::runtime_error("unimplemented");
}
Operator operator -( const Operator &lhs, const Operator & rhs){
  throw std::runtime_error("unimplemented");
}
Operator operator *( const Operator &lhs, const Operator & rhs){
  throw std::runtime_error("unimplemented");
}
  
//Linear algebra operations
Operator Inverse( const Operator &arg){

  throw std::runtime_error("unimplemented");
}
Operator Det( const Operator &arg){

  throw std::runtime_error("unimplemented");
}
Operator Transpose( const Operator &arg){

  throw std::runtime_error("unimplemented");
}



