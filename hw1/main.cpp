/////////////////////////////////////////////////////////////
//
// Programmer: Peter Knipper
// Date: 01/30/2024
// Name: main.cpp
// Description: Creates a visual representation of data acquired from a Peloton
//
/////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    //file input
    ifstream fin("ride_data.txt");
    //ifstream fin("ride_data2.txt");
    //ifstream fin("ride_data3.txt");
    //ifstream fin("ride_data4.txt");
    //ifstream fin("ride_data5.txt");

    //check if file opened correctly
    if (fin.fail()){
        return -1;
    }

    //variable declaration for data intake and analysis
    string wattageIn = "", tempStr = "";
    int bracketCheck = 0;
    double wattageListSum = 0, wattageListMean = 0, standDevSum = 0, standDev = 0, wattageMin = 999999, wattageMax = 0;
    vector<double> wattageList;

    //iterate until second instance of '[' character
    while (bracketCheck < 2){
        fin >> wattageIn;
        if (wattageIn.at(0) == '['){
            bracketCheck++;
        }
    }

    //add first value to list
    for (char digit:wattageIn){
        //find only the numbers and add them to temp string
        if (digit>47 && digit<58){
            tempStr.push_back(digit);
        }
    }

    //turn temp string into an integer and add to the list
    wattageList.push_back(stoi(tempStr));

    //iterate through majority of values
    do{
        //take in value from file
        fin >> wattageIn;
        tempStr = "";

        //find only the numbers and add them to temp string
        for (auto digit:wattageIn){
            if (digit>47 && digit<58){
                tempStr.push_back(digit);
            }
        }

        //turn temp string to and integer and add to the list
        wattageList.push_back(stoi(tempStr));
    }while (wattageIn.find(']') == string::npos);

    //close file
    fin.close();

    //sum wattageList and find bounds
    for (auto wattage:wattageList){
        if (wattage < wattageMin){
            wattageMin = wattage;
        }
        if (wattage > wattageMax){
            wattageMax = wattage;
        }
        wattageListSum += wattage;
    }

    //compute mean
    wattageListMean = wattageListSum/wattageList.size();

    //compute standard deviation
    for (double wattage:wattageList){
        standDevSum += pow((wattage - wattageListMean),2);
    }

    standDev = sqrt(standDevSum/wattageList.size());

    //create file
    ofstream fout;
    fout.open("output_graph.svg");

    //check if file opened correctly
    if (!fout.is_open()){
        return -1;
    }


    //declare image size and margins
    int width = 4096, height = 512, upper = 64, lower = 64, left = 64, right = 64;


    //write to file
    //file header
    fout<<R"(<svg version="1.1" width=")"<<width<<R"(" height=")"<<height<<R"(" xmlns="http://www.w3.org/2000/svg">)"<<endl;

    //create axis
    fout<<"<polyline"<<endl<<R"(fill="none")"<<endl<<R"(stroke="#000000")"<<endl<<R"(stroke-width="2")"<<endl<<R"(points=")"<<width-right<<","<<height-lower<<" "<<left<<","<<height-lower<<" "<<left<<","<<upper<<R"("/>)"<<endl;

    //add relevant numbers to graph

    //mean and std dev
    fout<<R"(<text x="0" y="10" font-family="Verdana" font-size="12" fill="black">)"<<"mean ="<<wattageListMean<<"</text>"<<endl;
    fout<<R"(<text x="0" y="20" font-family="Verdana" font-size="12" fill="black">)"<<"std dev ="<<standDev<<"</text>"<<endl;

    //axis numbers
    fout<<R"(<text x="0" y=")"<<upper<<R"(" font-family="Verdana" font-size="12" fill="black">)"<<wattageMax<<R"(</text>)"<<endl;
    fout<<R"(<text x="0" y=")"<<height-lower<<R"(" font-family="Verdana" font-size="12" fill="black">)"<<wattageMin<<R"(</text>)"<<endl;
    fout<<R"(<text x=")"<<left<<R"(" y=")"<<height-(lower/2)<<R"(" font-family="Verdana" font-size="12" fill="black">0</text>)"<<endl;
    fout<<R"(<text x=")"<<width-right<<R"(" y=")"<<height-(lower/2)<<R"(" font-family="Verdana" font-size="12" fill="black">)"<<wattageList.size()/60<<R"(</text>)"<<endl;


    //creat variables to scale the data to the axis
    double xScaleToAxis = static_cast<double>(width-right-left)/static_cast<double>(wattageList.size());
    double yScaleToAxis = static_cast<double>(height-upper-lower)/(wattageMax-wattageMin);

    //plot points on graph
    fout<<"<polyline"<<endl<<R"(fill="none")"<<endl<<R"(stroke="#0000aa")"<<endl<<R"(stroke-width="2")"<<endl<<R"(points=")";

    //iterate through list, scale the values, and output the points into the file
    for(double iterator=0; iterator<wattageList.size(); iterator++){
      fout<<static_cast<double>(iterator)*xScaleToAxis+left<<","<<height-lower-(wattageList.at(iterator)-wattageMin) * yScaleToAxis<<endl;
    }
    fout<<R"("/>)"<<endl;


    fout<<"</svg>"<<endl;
    //close file
    fout.close();

    return 0;
}
