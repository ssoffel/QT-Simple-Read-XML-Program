#include <QCoreApplication>
#include <QDebug>
#include <QtXml>
#include <QFile>
#include <QTextStream>


//DOM method of reading XML

void ListElements(QDomElement root, QString tagName1, QString tagName2, QString tagName3, QString tagName4)
{
    QDomNodeList item1 = root.elementsByTagName(tagName1);
    QDomNodeList item2 = root.elementsByTagName(tagName2);
    QDomNodeList item3 = root.elementsByTagName(tagName3);
    QDomNodeList item4 = root.elementsByTagName(tagName4);


    for(int i = 0; i < item1.count(); i++)
    {
        QDomNode itemNode1 = item1.at(i);
        QDomNode itemNode2 = item2.at(i);
        QDomNode itemNode3 = item3.at(i);
        QDomNode itemNode4 = item4.at(i);


        //convert to element
        if(itemNode1.isElement())
        {
            QDomElement itemElement1 = itemNode1.toElement();
            qDebug() << itemElement1.text();
        }
        if(itemNode2.isElement())
        {
            QDomElement itemElement2 = itemNode2.toElement();
            qDebug() << itemElement2.text();
        }
        if(itemNode3.isElement())
        {
            QDomElement itemElement3 = itemNode3.toElement();
            qDebug() << itemElement3.text();
        }
        if(itemNode4.isElement())
        {
            QDomElement itemElement4 = itemNode4.toElement();
            qDebug() << itemElement4.text();
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Create a XML document
    QDomDocument document;

    //Load file
    QFile file("C:/Users/Scott/MyFolder/practXML.xml");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() <<"Error opening file...";
        return -1;
    }
    else
    {
        //This function parses the XML document from the byte array data and sets it as the content of the document.
        //It tries to detect the encoding of the document as required by the XML specification.
        if(!document.setContent(&file))
        {
            qDebug() <<"Failed to load document...";
            return -1;
        }
        file.close();
    }

    //Get the root element
    QDomElement root = document.firstChildElement();

    ListElements(root, "title", "author", "year", "price");

    qDebug() <<"Finished";
    return a.exec();
}
