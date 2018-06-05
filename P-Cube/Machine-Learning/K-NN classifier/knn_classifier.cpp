#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
#define MAX 100
using namespace std;

int attribute_count;

/*Method that splits dataset into two files, training and testing set as per classified by the user*/
void split(string dataset, string train_path, int train_size, string test_path, int test_size, const char mode[MAX]) {

	float attr1, attr2, attr3, attr4;
	char class_label[MAX];
	char temp_address[MAX];
	strcpy(temp_address,train_path.c_str());
	FILE *fp = fopen(temp_address,mode);
	strcpy(temp_address,dataset.c_str());
	FILE *file = fopen(temp_address,"r");
	/*Writitng into training dataset file*/
	while(train_size-- && fscanf(file,"%f,%f,%f,%f,%s",&attr1,&attr2,&attr3,&attr4,class_label)!=EOF)
		fprintf(fp,"%f,%f,%f,%f,%s\n",attr1,attr2,attr3,attr4,class_label);
	fclose(fp);
	strcpy(temp_address,test_path.c_str());
	fp = fopen(temp_address,mode);
	/*Writing into testing dataset file*/
	while(test_size-- && fscanf(file,"%f,%f,%f,%f,%s",&attr1,&attr2,&attr3,&attr4,class_label)!=EOF) 
		fprintf(fp,"%f,%f,%f,%f,%s\n",attr1,attr2,attr3,attr4,class_label);
	fclose(fp);
}
/*Reads data and puts it into classifier*/
vector<vector<float>> read_data(string filename, map<string,int> classlabels) {

	vector<vector<float> > data;
	char temp_address[MAX];
	strcpy(temp_address,filename.c_str());
	FILE *fp = fopen(temp_address,"r");
	float attr1, attr2, attr3, attr4;
	char class_label[MAX];
	while(fscanf(fp,"%f,%f,%f,%f,%s",&attr1,&attr2,&attr3,&attr4,class_label)!=EOF) {

		vector<float> temp;
		string label = class_label;
		temp.push_back(attr1);
		temp.push_back(attr2);
		temp.push_back(attr3);
		temp.push_back(attr4);
		temp.push_back(classlabels[label]);
		data.push_back(temp);
	}
	return data;
}
/*Returns a map of identifier and index values*/
map<string,int> set_label(string filename) {

	char temp_address[MAX];
	strcpy(temp_address,filename.c_str());
	FILE *fp = fopen(temp_address,"r");
	map<string,int> mem;
	set<string> labellist;
	set<string> :: iterator it;
	int counter = 0;
	float attr1, attr2, attr3, attr4;
	char class_label[MAX];
	while(fscanf(fp,"%f,%f,%f,%f,%s",&attr1,&attr2,&attr3,&attr4,class_label)!=EOF) {

		string temp_label(class_label);
		labellist.insert(temp_label);
	}
	for(it = labellist.begin();it!=labellist.end();it++){

		mem[*it] = counter;
		counter++;
	}
	mem["size"] = labellist.size();
	return mem;
}
float run_knn(vector<vector<float> > testset, vector<vector<float> > trainset, int K) {

	int n = attribute_count;
	int arr[n+5];
	int train_length = trainset.size();
	int test_length = testset.size();
	int correct_guess = 0;
	int len;

	for(int i=0;i<test_length;i++) {

		memset(arr,0,sizeof(arr));
		vector<pair<float,int> > templist;
		for(int j=0;j<train_length;j++) {

			float distance = 0;
			int attr_len = trainset[j].size();
			for(int k=0; k<attr_len-1;k++) {	

					distance += (pow(testset[i][k]-trainset[j][k],2));
				}
				distance = sqrt(distance);
				/*Saving details for each train example for each test example*/
				templist.push_back({distance,j});
			}
			sort(templist.begin(),templist.end());
			/*Evaluating k neighbors*/
			for(int j=0;j<K;j++){

				len = trainset[templist[j].second].size();
				//Updating the count of arr based on class label
				arr[int(trainset[templist[j].second][len-1])]++;
			}

			int label = -1, label_count = -1;
			for(int j=0;j<n;j++){
				if(label_count < arr[j]){
					label = j;
					label_count = arr[j];
				}
			}
			len = testset[i].size();
			if(label == testset[i][len-1])
				correct_guess++;
		}
		return float(correct_guess)/float(test_length);
	}

int main(){

	clock_t t;
	/*########################################
	 *			HUMAN PARAMETERS
	 */

	string filename[5] = {"Iris-setosa.csv","Iris-vercicolor.csv","Iris-verginica.csv"};
	attribute_count = 150;
	int class_count = 3;
	int maximum_size_trainset = 40;
	int minimum_size_trainset = 10;
	int difference = 8;
	string trainset_file = "trn.csv";
	string testset_file =  "tst.csv";
	//#######################################

	t = clock();
	cout << "Number of classes: " << class_count << endl;
	FILE *fp = fopen("change_k_result.txt","w");
	FILE *fp1 = fopen("change_size_result.txt","w");
	for(int sp = maximum_size_trainset;sp >= minimum_size_trainset;sp-=difference){

		for(int i=0;i<class_count;i++){
			int n = sp;
			if(i == 0)
				split(filename[i],trainset_file ,n, testset_file,50-n,"w");
			else
				split(filename[i],trainset_file ,n, testset_file,50-n,"a");
		}
		double sum = 0;
		float Temp;
		for(int i=1;i<=sp*class_count;i+=2){

			fprintf(fp,"%d,",i);
			map<string,int> mem = set_label(trainset_file);
			vector<vector<float> > trainset = read_data(trainset_file,mem);
			mem = set_label(testset_file);
			vector<vector<float> > testset = read_data(testset_file,mem);
			Temp = run_knn(testset,trainset,i);
			fprintf(fp,"%f\n",Temp*100);
			sum += (Temp*100);
		}
		fprintf(fp,"\n");
		float fin = (float)sum/(float)(sp*class_count);
		fprintf(fp1,"%d,%f\n",sp,fin);
	}
	t = clock()-t;
	double time = ((double)t)/CLOCKS_PER_SEC;
	cout<<"Time elapsed "<<time<<" s"<<endl;
	//system("/home/parth/Desktop/Implement/I-m-play-mend/P-Cube/Machine-Learning/K-NN classifier/script.sh");
	return 0;
}
