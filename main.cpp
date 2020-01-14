#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Student{
public:
    void setFirst(string f){first=f;}
    void setLast(string l){last=l;}
    void setID(string i){id=i;}
    void setCourse(int c){courses=c;}
    string getFirst()const{return first;}
    string getLast()const{return last;}
    string getID()const{return id;}
    int getCourse()const{return courses;}
    void getData(ifstream &indata, Student st[],int size);
    void print(ofstream &outfile,Student st[],int size);
private:
    string first;
    string last;
    string id;
    int courses;
};
void Student::getData(ifstream &indata, Student st[], int size){
    string fname,lname,id;
    int noCourse;
    for(int i=0;i<size;i++){
        indata>>fname;
        st[size].setFirst(fname);
        indata>>lname;
        st[size].setLast(lname);
        indata>>id;
        st[size].setID(id);
        indata>>noCourse;
        st[size].setCourse(noCourse);
    }
}
void Student::print(ofstream &out, Student st[],int size){
    for(int i=0;i<size;i++){
        out<<"student Name: "<<st[i].getFirst()<<' '<<st[i].getLast()<<endl;
        out<<"student ID: "<<st[i].getID()<<endl;
        out<<"number of courses: "<<st[i].getCourse()<<endl;
    }
}
int main(){
    ifstream infile;
    ofstream outfile;
    string in,out;
    cout<<"Enter file name: ";
    cin>>in;
    infile.open(in);
    if(!infile){
        cout<<"Cannot open file";
        return -1;
    }
    int size=2;
    Student s[size];
    cout<<"Enter output file: ";
    cin>>out;
    outfile.open(out);
    for(int i=0;i<size;i++)
           s[i].getData(infile,s,size);

    for(int i=0;i<size;i++)
        s[i].print(outfile, s, size);
    
    
}
