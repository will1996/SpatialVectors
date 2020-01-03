#include<glm/glm.hpp>
#include<string> 
#include<vector>



//class implementing the spatial vectors as made popular by roy Featherstone
//in his book rigid body dynamics algorithms
//
//
//
//a spatial vector is a non-euclidian 6Vector which marries the cannocnical pair 
//of equations for linear forces, and torques into a more compact form, 
//which allows shorter and probably faster code. 
//
//
//This library defines full SpatialVectors, PlanarVectors, 
//SpatialOperators, and PlanarOperators, extending the RigidBody namespace.
//
//SpatialVector defines operations on two glm::vec3's;
//one for orientation (the corrdinate of the body in rotation space), and 
//one for position (the coordinate of the body in position space)

//finally in the 
namespace FeatherStone{

namespace Spatial{
  class Vector{
    public: 
    Vector();
    Vector(glm::vec3 , glm::vec3);
    Vector(double,double,double,double,double,double);
    Vector(std::vector<double>);
    glm::vec3 getPosition();
    glm::vec3 getOrientation();
    std::string stringify();      
    double & operator[] (int);
    private:
      glm::vec3 orientation;
      glm::vec3 position;
      
  };

  //spatialOperators are transforms in M6, they are convinently block 
  //matricies, and so are a collection of four transforms in M3. Here, 
  //they are numbered by coordiantes 00, 01,10,11 
  class Operator{
    public: 
    std::string stringify();      
    Vector & operator[] (int);
    private:
    glm::mat3 d_00;
    glm::mat3 d_01;
    glm::mat3 d_10;
    glm::mat3 d_11;
  };

    //Spatial Vector arithmetic Operators
    double operator *(const Spatial::Vector& lhs, const Spatial::Vector& rhs);
    Vector operator *(const double& lhs, const Spatial::Vector & rhs);
    Vector operator *(const Spatial::Vector &lhs, const double & rhs);
    Vector operator +(const Spatial::Vector& lhs, const Spatial::Vector& rhs);
    Vector operator -(const Spatial::Vector& lhs, const Spatial::Vector& rhs);
    //transformation
    Operator operator *( const Spatial::Operator &lhs, const Spatial::Vector & rhs);
    //scale matrix
    Operator operator *( const double &lhs, const Spatial::Operator & rhs);
    //Spatial Operator arithmetic Operators 
    Operator operator +( const Spatial::Operator &lhs, const Spatial::Operator & rhs);
    Operator operator -( const Spatial::Operator &lhs, const Spatial::Operator & rhs);
    Operator operator *( const Spatial::Operator &lhs, const Spatial::Operator & rhs);
    
    //Linear algebra operations
    Operator Inverse( const Spatial::Operator &arg);
    Operator Det( const Spatial::Operator &arg);
    Operator Transpose( const Spatial::Operator &arg);

 };  
};
