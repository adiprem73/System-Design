#include<bits/stdc++.h>
using namespace std;

class DocumentEditor{
private:
    vector<string> documentElements;
    string renderedDocument;


public:

    // Adds test as a plain string
    void addText (string text){
        documentElements.push_back(text);
    }

    // Adds an image represented by its file path
    void addImage(string imagePath){
        documentElements.push_back(imagePath);
    }

    // Renders the document by checking the type of each element at the runtime
    string renderDocument(){
        if(renderedDocument.empty()){
            string result;
            for(auto element: documentElements){
                if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" || element.substr(element.size() - 4) == ".png")){
                    result += "[Image : "+element+"]\n";
                }else{
                    result += element+"\n";
                }
            }
            renderedDocument = result;
        }
        return renderedDocument;
    }

    void saveToFile(){
        ofstream file("document.txt");
        if(file.is_open()){
            file << renderDocument();
            file.close();
            cout<< "Document saved to Document.txt"<<endl;
        }else{
            cout<<"error"<<endl;
        }
    }
};

int main() {
    DocumentEditor editor;
    editor.addText("Hi this is the first line");
    editor.addImage("photo.jpg");
    editor.addText("Thsi is a document editor.");

    cout<<editor.renderDocument()<<endl;
    editor.saveToFile();
    return 0;
}
//by ad73prem