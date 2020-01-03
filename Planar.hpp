#include<glm/glm.hpp>
#include<string> 
#include<vector>
namespace FeatherStone{
  //implementation for the planar vectors, also described in rigidbody 
  //dynamics algorithms by Roy Featherstone. 
  //Planar vectors are 3vectors which can represent vectors from 
  //E3, F3, and M3. Inheritance is used to differentated the kinds of vectors


  namespace Planar{

  class Vector{
   
    public: 
    Vector();
    Vector(double, double, double);
    Vector(glm::vec3);
    std::string stringify();      
    glm::vec2 getPosition();
    double getOrinetation();
    double & operator[] (int);
    private:
    glm::vec3 self;
  };
  //since Planar Operators are defined in M3, PlanarOperators are a wrapper
  //for glm::mat3's 
  class Operator{
    public: 
    Operator(glm::mat3);
    Operator(Vector,Vector,Vector);
    Vector & operator[] (int);
    std::string stringify();      
    private:
    glm::mat3 self;
    };

  class Motion: Vector{};
  class Euclidian: Vector{};
  class Force:Vector{};
  
  
    double operator *(const Vector& lhs, const Vector& rhs);
    Vector operator *(const double& lhs, const Vector & rhs);
    Vector operator *(const Vector &lhs, const double & rhs);
    Vector operator +(const Vector& lhs, const Vector& rhs);
    Vector operator -(const Vector& lhs, const Vector& rhs);
    //transformation
    Operator operator *( const Operator &lhs, const Vector & rhs);
    //scale matrix
    Operator operator *( const double &lhs, const Operator & rhs);
    //Spatial Operator arithmetic Operators 
    Operator operator +( const Operator &lhs, const Operator & rhs);
    Operator operator -( const Operator &lhs, const Operator & rhs);
    Operator operator *( const Operator &lhs, const Operator & rhs);
    
    //Linear algebra operations
    Operator Inverse( const Operator &arg);
    Operator Det( const Operator &arg);
    Operator Transpose( const Operator &arg);
  };
};
