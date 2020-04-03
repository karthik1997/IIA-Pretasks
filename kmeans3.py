import random
import math

#Euclidian Distance between two d-dimensional points
def euclidian_distance(p0,p1):
    dist = 0.0
    for i in range(0,len(p0)):
        dist += (p0[i] - p1[i])**2
    return math.sqrt(dist)


    
#K-Means Algorithm
def kmeans(k,dataset):

    # d - Dimensionality of dataset
    d = len(dataset[0]) 
    
    
    cluster = [0] * len(dataset)
    previous_cluster = [-1] * len(dataset)
    cluster_centers = []
    for i in range(0,k):
        new_cluster = []
        cluster_centers += [random.choice(dataset)]
    
    while (cluster != previous_cluster):
        
        previous_cluster = list(cluster)
    
        for p in range(0,len(dataset)):
            min_dist = float("inf")
            
            for c in range(0,len(cluster_centers)):
                
                dist = euclidian_distance(dataset[p],cluster_centers[c])
                
                if (dist < min_dist):
                    min_dist = dist  
                    cluster[p] = c   # Reassign Point to new Cluster
        
        
        #Update Cluster's Position
        for k in range(0,len(cluster_centers)):
            new_center = [0] * d
            cluster_members = 0
            for p in range(0,len(dataset)):
                if (cluster[p] == k): #If this point belongs to the cluster
                    for q in range(0,d):
                        new_center[q] += dataset[p][q]
                    cluster_members += 1
            
            for q in range(0,d):
                if cluster_members != 0:
                    new_center[q] = new_center[q] / float(cluster_members) 
                                            
            cluster_centers[k] = new_center
         
    print ("Clusters", cluster_centers)
    print ("Assignments", cluster)
    
    
if __name__ == "__main__":
    dataset = [(3,2),(2,2),(1,2),(0,1),(1,0),(1,1),(5,6),(7,7),(9,10),(11,13),(12,12),(12,13),(13,13)]

    k = 2 
      
    kmeans(k,dataset) 