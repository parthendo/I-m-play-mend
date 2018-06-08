# -*- coding: utf-8 -*-
"""
Created on Fri Jun  8 13:58:34 2018

@author: parth
"""
import os
from skimage import filters
from skimage import io
from skimage.color import rgb2grey
'''
* Read all images in jpg format
* Make collection of images in one folder
* Evaluates the edges using the sobel features
* Evaluates the threshold of the color intensity of image
* Makes the dataset by saving the features along with the label 
'''
def build_feature(output,path,fileformat,label,n,mode):

    filewriter = open(output,mode)
    for i in range(1,n+1):
        #Making filepath dynamically
        filename = os.path.join(path,str(i)+fileformat)
        img = io.imread(filename)
        row = len(img)
        col = len(img[0])
        #Calculates the threshold level
        threshold = filters.threshold_otsu(img)
        #Sets the pixel having value greater than threshold, 1 else 0
        thresh_img = img>threshold
        #Covert image to grey as sobel filter works on 2D image
        img = rgb2grey(img)
        edges = filters.sobel(img)
        temp_edge_img = edges > 0.1
        tempa = (thresh_img.sum()*1.0)/(row*col)
        tempb = (temp_edge_img.sum()*1.0)/(row*col)
        #Making a new line to be written in CSV format
        line = str(tempa)+','+str(tempb)+','+str(label)+'\n'
        filewriter.write(line)
    filewriter.close()