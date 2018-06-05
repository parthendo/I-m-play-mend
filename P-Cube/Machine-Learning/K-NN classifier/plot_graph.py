import matplotlib.pyplot as plt
import sys
import csv
import Image

def main():
	mode = sys.argv[1];
	filename = sys.argv[2];
	print filename
	x = []
	y = []
	if mode == "1":
	
		file=open(filename,"r")
		str=file.readline()
		while(str):
			list1=str.split(",")
			x.append(int(list1[0]))
			y.append(float(list1[1].rstrip()))
			str=file.readline()
	else:
		file = open(filename,"r")
		str = file.readline()
		while(str):
			list1 = str.split(",")
			str = file.readline()

	plt.plot(x,y)
	plt.show()
	newpngfile = filename[0:-4]+"graph.png"
	newjpgfile = filename[0:-4]+"graph.jpg"
	plt.savefig(newpngfile)
	Image.open(newpngfile).save(newjpgfile,'JPEG')
if __name__ == "__main__":
	main()