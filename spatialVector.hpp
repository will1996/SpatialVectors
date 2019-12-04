#include<glm/glm.hpp>



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

namespace RigidBody{



  class SpatialVector{
    private:
      glm::vec3 orientation;
      glm::vec3 position;

  };

  //spatialOperators are transforms in M6, they are convinently block 
  //matricies, and so are a collection of four transforms in M3. Here, 
  //they are numbered by coordiantes 00, 01,10,11 
  class SpatialOperator{
    private:
    glm::mat3 d_00;
    glm::mat3 d_01;
    glm::mat3 d_10;
    glm::mat3 d_11;
  };
  //since Planar vectors are defined in M3, PlanarVectors are a wrapper for
  //glm::vec3's
  class PlanarVector: public glm::vec3{
    
  };
  //since Planar Operators are defined in M3, PlanarOperators are a wrapper
  //for glm::mat3's 
  class PlanarOperator: public glm::mat3{
    };




};
