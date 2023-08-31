//
// Created by Nghia Huynh on 14/01/2023.
//
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//This function will return a frame flush left texts
string flush_left(int length, string file) {
    ifstream in_str(file); // this will read the file
    string output;
    string w;
    int count;
    count = 0;
    for (int i = 0; i < length + 4; i++) { // This will print the top line frame
        output += "-";
    }
    output +=  "\n| ";
    while (in_str >> w) { // this while loop will get each word in the file
        w = w + " ";
        int lenw = w.size();
        count = count + lenw;
        if (count <= length + 1) {
            output += w;
        }
        if (count > length + 1) {
            for (int i = 0; i <= (length - count + lenw); i++) {
                output += " ";
            }
            output += "|";
            output +=  "\n| " + w;
            count = lenw;

        }
    }
    for (int i = 0; i <= (length - count); i++) { //This code will print the amount of space for the last line.
        output += " ";
    }
    output += "|";
    output += "\n";
    for (int i = 0; i < length + 4; i++) { // This will print the bottom line frame
        output += "-";
    }
    return output;
}

//This function will return a frame flush right texts
string flush_right(int length, string file) {
        ifstream in_str(file);
        string output;
    for (int i = 0; i < length + 4; i++) { // This will print the top line frame
        output += "-";
    }
    string w;
    int count;
    count = 0;
    output +=  "\n| ";
    string list;
    while (in_str >> w) {
        w = w + " ";
        int lenw = w.size();
        count = count + lenw; //This count is use to keep track on the amount of word can be on 1 line
        //This will return when the amount of word on 1 line is enough its will print the word on that line with format
        // and end the line
        if (count > length + 1) {
            for (int i = 0; i <= (length - count + lenw); i++) {
                output += " ";
            }
            output += list;
            output += "|\n| ";
            list = "";
            count = lenw;
        }
        //This will add the word into a string if the count is still good for the length of 1 line.
        if (count <= length + 1) {
            list = list + w;
        }
    }
    //This will print the space for last line
    for (int i = 0; i <= (length - count); i++) {
        output += " ";
    }

    output += list; //This print the last line of words.
    output += "|";
    output += "\n";
    for (int i = 0; i < length + 4; i++) { // This will print the bottom line frame
        output += "-";
    }
    return output;
}

//This function will return a frame full justify texts including long word.
string full_justify(int length, string file) {
        ifstream in_str(file);
        string output;
        for (int i = 0; i < length + 4; i++) { // This will print the top line frame
            output += "-";
        }
        string w;
        int count;
        count = 0;
        output += "\n| ";
        int space = 0;
        vector<string> list_word;
        while (in_str >> w) {
            int lenw = w.size();
            count = count + lenw; //This count is use to keep track on the amount of word can be on 1 line
            //This if statement is use to execute if there is a word go before the long word
            if (lenw > length + 1 and list_word.size() > 0) {
                output += list_word[0];
                for (int i = 0; i <= (length - list_word[0].size()); i++) {
                    output += " ";
                }
                output += "|";
                output += "\n| ";
                vector<string> lastw_list;
                for (int i = 0; i < w.length(); i += (length - 1)) {
                    lastw_list.push_back(w.substr(i, (length - 1)));
                    count = lastw_list[0].size();
                    if (lastw_list[0].size() == (length - 1)) {
                        output += lastw_list[0] + "- " + "|" + "\n| ";
                        lastw_list.clear();
                    }
                }
                list_word.clear();
                list_word.push_back(lastw_list[0]);


            } else {
                //This if statement is use to execute if the long word start from the beginning
                if (lenw > (length - 1) and list_word.size() == 0) {
                    vector<string> longw_list;
                    for (int i = 0; i < w.length(); i += (length - 1)) {
                        longw_list.push_back(w.substr(i, (length - 1)));
                        count = longw_list[0].size();
                        if (longw_list[0].size() == (length - 1)) {
                            output += longw_list[0] + "- " + "|" + "\n| ";
                            longw_list.clear();
                        }
                    }

                    list_word.push_back(longw_list[0]);
                } else {
                    //This if statement is use to push all the word if the count doesn't go off the limit length
                    if (count + list_word.size() <= length) {
                        list_word.push_back(w);
                    } else {
                        //This if statement is use to print out the line of word if the count go off the limit length
                        if (count + list_word.size() > length) {
                            int blank = list_word.size() - 1;
                            space = (length - (count - lenw));
                            string space1 = "";

                            for (int i = 0; i <= (space / blank) - 1; i++) {
                                space1 += " ";
                            }
                            //This is the way of doing full justify if the amount of space divided by the blank is even
                            if (space % blank == 0) {
                                int index = list_word.size();
                                for (int i = 0; i < blank; i++) {
                                    output += list_word[i] + space1;
                                }
                                output += list_word[index - 1] + " ";

                            } else {
                                //This is the way of doing full justify if the amount of space is odd
                                while (space != 0) {
                                    for (int i = 0; i < blank; i++) {
                                        list_word[i] += " ";
                                        space = space - 1;
                                        if (space == 0) {
                                            break;
                                        }
                                    }
                                }
                                for (int i = 0; i < list_word.size() - 1; i++) {
                                    output += list_word[i];
                                }
                                output += list_word[list_word.size() - 1] + " ";
                            }
                            output += "|";
                            output += "\n| ";
                            count = lenw;
                            list_word.clear();
                            list_word.push_back(w); // reset the list begining will the word that start in the next line
                        }
                    }
                }
            }
        }

        //This will print out the last line
        for (int i = 0; i < list_word.size(); i++) {
            output += list_word[i] + " ";
        }
        //This will print the amount of space for the last line
        for (int i = 0; i <= (length - count - list_word.size()); i++) {
            output += " ";
        }
        output += "|";
        output += "\n";
        for (int i = 0; i < length + 4; i++) { // This will print the bottom line frame
            output += "-";
        }
        return output;
    }
//Main body
int main(int argc, char* argv[]) {

    string file = argv[1];
    ifstream in_str(file);
    int length = stoi(argv[3]);
    string flush = argv[4];

    if (!in_str.good()) {
        cerr << "Can't open " << file << " to read.\n";
        exit(1);
    }
    ofstream out_str(argv[2]);
    if (!out_str.good()) {
        cerr << "Can't open " << argv[2] << " to write.\n";
        exit(1);
    }

    if (flush == "flush_left"){
        out_str << flush_left(length, file) << endl;
    }
    else if (flush == "flush_right"){
        out_str << flush_right(length, file) << endl;
    }
    else if (flush == "full_justify"){
        out_str << full_justify(length, file) << endl;
    }

    return 0;
}