import numpy as np


def main():

    something = np.array([1,2,3,4])
    print something
    
    something2 = something
    
    output = something*something2
    print output
    

#make sure X is a numpy array
#COMPUTECOST Compute cost for linear regression
#   J = COMPUTECOST(X, y, theta) computes the cost of using theta as the
#   parameter for linear regression to fit the data points in X and y
def computeCost(X, y, theta):

    J = 0
    
    #returns the size of the dimension of X specified by scalar dim (1)
    #m is the one we want
    #maybe: m = size(X)
    m, discard = size(X,1)
    
    y_hat = X*theta #prediction of y
    
    #compute the cost
    #need to do an element-wise ^2
    J = (1/(2*m))*sum((y_hat-y)*(y_hat-y))


#COMPUTECOSTMULTI Compute cost for linear regression with multiple variables   
def computeCostMulti(X, y, theta):
    
   J = 0
   m, discard = size(X,1)
   y_hat = X*theta
   #this is a 'vectorised form:
   #(y_hat-y)'*(y_hat-y) in matlab (takes the transpose of the first of the vectors to multiply them
   J = (1/(2*m))*(y_hat-y)^2


#   FEATURENORMALIZE(X) returns a normalized version of X where
#   the mean value of each feature is 0 and the standard deviation
#   is 1. This is often a good preprocessing step to do when
#   working with learning algorithms.   
def featureNormalise():
    n_cols = size(X,2)
    X_norm = X
    mu = zeros(1,n_cols)
    sigma = zeros(1,n_cols)
    
    #TODO check that this axis thing is right [axis = 0 is the vertical axis]
    mu = np.mean(X, axis=0)
    sigma = np.std(X, axis=0)
    
    #X_norm = (X - repmat(mu, size(X,1),1))./repmat(sigma, size(X,1),1)
    #element wise divide 
    X_norm = (X - tile(mu, (size(X),1) 


if __name__ == "__main__": main()


