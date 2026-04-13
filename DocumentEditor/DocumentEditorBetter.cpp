#include<bits/stdc++.h>
using namespace std;

class DocumentElement{
public:
    virtual string render()=0;
};

// implementation for text elements
class TextElement: public DocumentElement{
private:
    string text;

public:
    TextElement(string text){
        this->text = text;
    }

    string render() override{
        return text;
    }
};

// implementation for image elements
class ImageElement: public DocumentElement{
private:
    string imagePath;

public:
    ImageElement(string imagePath){
        this->imagePath = imagePath;
    }

    string render() override{
        return "[Image : "+ imagePath + "]";
    }
};

// newline element represents a line break
class NewLineElement : public DocumentElement{
public:
    string render() override{
        return "\n";
    }
};

// tabspace elememt represents a tab
class TabSpaceElement : public DocumentElement{
public:
    string render() override{
        return "\t";
    }
};

// document class is responsible for holding a collection of elements
class Document {
private:
    vector<DocumentElement*> documentElements;

public:
    void addElement(DocumentElement* element){
        documentElements.push_back(element);
    }

    string render(){
        string result;
        for(auto element: documentElements){
            result += element->render();
        }
        return result;
    }

};

// Persistence interface
class Persistence{
    public:
    virtual void save(string data) = 0;
};

// file storage implementation of persistence
class FileStorage: public Persistence{
public:
    void save(string data) override{
        ofstream outFile("documentNew.txt");
        if(outFile){
            outFile<< data;
            outFile.close();
            cout<<"The final document has beeen saved to document.txt"<<endl;
        }else{
            cout<<"Error: there is some issue regarding opeming the file for writing"<<endl;
        }
    }
};

// Placeholder DBStorage implementation
class DBStorage: public Persistence{
public:
    void save(string data) override{
        cout<<"Here the data is being saved to the DB"<<endl;
    }
};

// document editor class managing the cliend interactiosn
class DocumentEditor{
private:
    Document* document;
    Persistence* storage;
    string renderedDocument;

public:
    DocumentEditor(Document* document, Persistence* storage){
        this->document = document;
        this->storage = storage;
    }

    void addText(string text){
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath){
        document->addElement(new ImageElement(imagePath));
    }

    // adds a new line to the document
    void addNewLine(){
        document->addElement(new NewLineElement());
    }

    // adds a tab space to the document.
    void addTabSpace(){
        document->addElement(new TabSpaceElement());
    }

    string renderDocument(){
        if(renderedDocument.empty()){
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void saveDocument(){
        storage->save(renderDocument());
    }
};

int main() {
    Document* document = new Document();
    Persistence* persistence = new FileStorage();
    DocumentEditor* editor = new DocumentEditor(document, persistence);

    editor->addText("Title of the assingment");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addImage("picture.jpg");

    cout<<editor->renderDocument() << endl;

    editor->saveDocument();
    return 0;
}
//by ad73prem