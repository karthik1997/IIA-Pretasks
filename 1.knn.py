import math 

def PointPredictor(Sample_Data,p,k=3): 

	distance_recorder=[] 
	for label in 	Sample_Data: 
		for feature in 	Sample_Data[label]: 

			euclidean_distance = math.sqrt((feature[0]-p[0])**2 +(feature[1]-p[1])**2) 

			# Add a tuple of form (distance,group) in the distance list 
			distance_recorder.append((euclidean_distance,label)) 
	# sort the distance list in ascending order 
	# select first k distances 
	distance_recorder = sorted(distance_recorder)[:k] 
	print(distance_recorder)
	


	freq1 = 0 #frequency of group 0 
	freq2 = 0 #frequency og group 1 

	for dist in distance_recorder: 
		if dist[1] == 0: 
			freq1 += 1
		elif dist[1] == 1: 
			freq2 += 1

	return 0 if freq1>freq2 else 1
 
def main(): 

	Sample_Data = {0:[(1,12),(2,5),(3,6),(3,10),(3.5,8),(2,11),(2,9),(1,7)], 
			1:[(5,3),(3,2),(1.5,9),(7,2),(6,1),(3.8,1),(5.6,4),(4,2),(2,5)]} 

	# testing point p(x,y) 
	p = (5,1) 

	k = 3

	print("The Label classified to unknown data is: {}".format(PointPredictor(	Sample_Data,p,k)))

if __name__ == '__main__': 
	main() 
	



