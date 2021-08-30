import cv2 
import matplotlib.pyplot as plt
import glob
import sys

orb = cv2.ORB_create(nfeatures=1500)

# read images
source_path = sys.argv[1]+"/Source_Images/*"
#print(sys.argv[2])
img1 = cv2.imread(sys.argv[2])
img1 = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)

max_similar = 0
for filename in glob.glob(source_path):
    img2 = cv2.imread(filename)

    img2 = cv2.cvtColor(img2, cv2.COLOR_BGR2GRAY)

    keypoints_1, descriptors_1 = orb.detectAndCompute(img1,None)
    keypoints_2, descriptors_2 = orb.detectAndCompute(img2,None)

    #feature matching
    bf = cv2.BFMatcher(cv2.NORM_L1, crossCheck=True)

    matches = bf.match(descriptors_1,descriptors_2)

    no_features_matched = len(matches)
    if no_features_matched > max_similar :
        max_similar = len(matches)
        matching_image = filename

print(matching_image)
