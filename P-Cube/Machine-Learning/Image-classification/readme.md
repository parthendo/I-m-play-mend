# Image-Classification

### Method
This in an elementary implementation of classification of an image using concepts of image processing. Features of image, such as _edge-detection_ and _color-threshold_ have been evaluated and their percentage along with the labels are saved. Then after using the _K-NN classification algorithm_, images are classified and the labels are written on the image.

### Dependency
* skimage
* PIL (pillow)

### How to run

* Paste the two class labels in the _Imageset/Trainset_ folder in separate folders already made(sample files are present. Rename your files as 1,2,3..)
* Paste the testing images in the _Imageset/Testset_ folder following the same naming convention
* Run the code using the command: **python -W ignore main.py** or refer the image below
  ![How to run?](URL)

### Results

After the program runs, check the images, predicted class labels shall be written on the image. Results are shown below:

![Outdoor Picture Result]()

![Indoor Picture Result]()

Note: Delete all the files in folder _Imageset/Testset_ and file _trainset.csv_ in the home folder and run the program to generate fresh results
