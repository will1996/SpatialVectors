# SpatialVectors



basic in-progress implementation of a spatial vector library for use in computer graphics, physics simulations and whatever else your heart desires. This library is constructed with information from: 

RigidBody Dynamics Algorithms, by Roy Featherstone.



This library defines four main classes: 

SpatialVector: 
A vector of six elements, the first three correspond to orientation, the latter three correspond to position. 



SpatialOperator: 
block matrix with four sub-matricies, each a 3x3 transform. 

PlanarVector:
a three element vector, defining the spatial-transofmations of an object confined to a plane. 
The first element corresponds to rotationa angle about the normal to the plane, the latter two are the 
x and y coordinates of the center of mass.

PlanarOperator:
a 3x3 matrix 
