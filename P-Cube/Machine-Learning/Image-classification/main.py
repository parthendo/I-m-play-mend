# -*- coding: utf-8 -*-
"""
Created on Fri Jun  8 13:57:46 2018

@author: parth
"""

import build_feature as bf
import os
import sys
from skimage import io
import math
from PIL import Image, ImageDraw, ImageFont

'''
* Classifies images of test set by comparing the features using K-NN
* Saving the classified labels
'''
def classify(testfile,trainfile,label,k):
    trainset = []
    dict = {}
    #Read trainset CSV and store in a list
    file = open(trainfile,'r')
    filereader = file.readline()
    while(filereader):
        temp_list = filereader.split(",")
        trainset.append(temp_list)
        filereader = file.readline()
    #Read testset CSV file
    file = open(testfile,'r')
    ans = []
    filereader = file.readline()
    while(filereader):
        result = []
        temp_list = filereader.split(",")
        l = len(trainset)
        #Calculate distance using K-NN
        for i in range(l):
            distance = math.sqrt((float(trainset[i][0])-float(temp_list[0]))**2 + (float(trainset[i][1])-float(temp_list[1]))**2)
            result.append((distance,trainset[i][2]))
        result.sort()
        dict[label[0]] = 0
        dict[label[1]] = 0
        for i in range(k):
            dict[label[int(result[i][1])]]+=1
        if dict[label[0]] > dict[label[1]]:
            ans.append(label[0])
        else:
            ans.append(label[1])
        filereader = file.readline()
    return ans

'''
* Writes the classified labels on the image.
'''
def write_on_image(list, test_path, fileformat, n):

    for i in range(1,n+1):
        filename = os.path.join(test_path,str(i)+fileformat)
        image = Image.open(filename)
        draw = ImageDraw.Draw(image)
        font = ImageFont.truetype(font="Roboto-Light.ttf",size=45)
        (x,y) = (50,100)
        message = list[i-1]
        color = 'rgb(0,0,0)'
        draw.text((x,y),message,fill=color,font=font)
        image.save(filename)

'''
* This method takes in the label and the details of the image
* Takes the testing and training classes and evaluates the features
* 
'''
def main():
    sys.stdout.write("Welcome to two-class image classifier\n")
    #--------------------------Human Parameters--------------------------------
    lbl0 = str(raw_input("Enter the name of first class: "))
    lbl1 = str(raw_input("Enter the name of second class: "))
    label = []
    label.append(lbl0)
    label.append(lbl1)
    path_class1 = "Imageset/Trainset/Indoor"
    path_class2 = "Imageset/Trainset/Outdoor"
    fileformat_class1 = str(raw_input("Enter the file format of images of class 1: "))
    n_class1 = int(input("Enter the number of examples present in class 1: "))
    fileformat_class2 = str(raw_input("Enter the file format of images of class 2: "))
    n_class2 = int(input("Enter the number of examples present in class 2: "))
    output_filename = "trainset.csv"
    bf.build_feature(output_filename,path_class1,"."+fileformat_class1,0,n_class1,'w')
    bf.build_feature(output_filename,path_class2,"."+fileformat_class2,1,n_class2,'a')    
    #------------------------Testing image prediction---------------------------
    test_path = "Imageset/Testset"
    fileformat = str(raw_input("Enter the file format of images: "))
    n_test = int(raw_input("Enter the number of images: "))
    outputfile = "Imageset/Testset/residue.csv"
    bf.build_feature(outputfile,test_path,"."+fileformat,-1,n_test,'w')
    list = classify(outputfile,output_filename,label,int((n_class2+n_class1)/2))
    write_on_image(list,test_path,"."+fileformat,n_test)
    print('Run was successful!')

if __name__ == "__main__":
    main()


