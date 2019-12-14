#include<glm/glm.hpp>
#include<string> 



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

//finally in the R
namespace RigidBody{



  class SpatialVector{
    public: 
    std::string stringify();      
    private:
      glm::vec3 orientation;
      glm::vec3 position;

  };

  //spatialOperators are transforms in M6, they are convinently block 
  //matricies, and so are a collection of four transforms in M3. Here, 
  //they are numbered by coordiantes 00, 01,10,11 
  class SpatialOperator{
    public: 
    std::string stringify();      
    private:
    glm::mat3 d_00;
    glm::mat3 d_01;
    glm::mat3 d_10;
    glm::mat3 d_11;
  };
  //since Planar vectors are defined in M3, PlanarVectors are a wrapper for
  //glm::vec3's
  class PlanarVector: public glm::vec3{
    
    public: 
    std::string stringify();      
  };
  //since Planar Operators are defined in M3, PlanarOperators are a wrapper
  //for glm::mat3's 
  class PlanarOperator: public glm::mat3{
    public: 
    std::string stringify();      
    };

    //Spatial Vector arithmetic Operators
    double operator *(const SpatialVector& lhs, const SpatialVector& rhs);
    SpatialVector operator *(const double& lhs, const SpatialVector & rhs);
    SpatialVector operator *( const SpatialVector &lhs, const double & rhs);
    SpatialVector operator +(const SpatialVector& lhs, const SpatialVector& rhs);
    SpatialVector operator -(const SpatialVector& lhs, const SpatialVector& rhs);
    //transformation
    SpatialOperator operator *( const SpatialOperator &lhs, const SpatialVector & rhs);
    //scale matrix
    SpatialOperator operator *( const double &lhs, const SpatialOperator & rhs);
    //Spatial Operator arithmetic Operators 
    SpatialOperator operator +( const SpatialOperator &lhs, const SpatialOperator & rhs);
    SpatialOperator operator -( const SpatialOperator &lhs, const SpatialOperator & rhs);
    SpatialOperator operator *( const SpatialOperator &lhs, const SpatialOperator & rhs);
    
    //Linear algebra operations
    SpatialOperator Inverse( const SpatialOperator &arg);
    SpatialOperator Det( const SpatialOperator &arg);
    SpatialOperator Transpose( const SpatialOperator &arg);
    //Spatial Operator indexing operators
    
};
