#-------------------------------------------------
#
# Project created by QtCreator 2012-09-26T12:33:15
#
#-------------------------------------------------

QT       += core gui network

lessThan(QT_MAJOR_VERSION, 5): QT += webkit
greaterThan(QT_MAJOR_VERSION, 4): QT += webkitwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

CONFIG += c++11

LIBS += -lpdfviewd
LIBS += -L./

ORGNAME = "mksIngenieria"
APPNAME = "Computos"

TARGET = Computos
TEMPLATE = app

TRANSLATIONS = computos_es.ts \
    computos_en.ts

SOURCES += main.cpp\
    elemento.cpp \
    unit.cpp \
    elementocomputo.cpp \
    cantidad.cpp \
    cantidadlineal.cpp \
    superficietrapecial.cpp \
    circularsurface.cpp \
    rectangularsurface.cpp \
    materiallibrary.cpp \
    datastore.cpp \
    unitlibrary.cpp \
    proyecto.cpp \
    elementoconstructivo.cpp \
    computometrico.cpp \
    materialdockwindow.cpp \
    dlgnuevoelementoconstructivo.cpp \
    cantidadeslibrary.cpp \
    dlgcircularsurface.cpp \
    dlgcantidadlineal.cpp \
    dlgrectangularsurface.cpp \
    dlgsuperficietrapecial.cpp \
    mainwindowapplication.cpp \
    author.cpp \
    wndmateriales.cpp \
    superficiepoligonal.cpp \
    dlgsuperficiepoligonal.cpp \
    cantidadunitaria.cpp \
    perimetrocircular.cpp \
    prismatrapecial.cpp \
    cilindro.cpp \
    dlgcomponente.cpp \
    projectwindow.cpp \
    dlgprismavolume.cpp \
    listaprecios.cpp \
    proveedor.cpp \
    precio.cpp \
    dlgproveedor.cpp \
    wndproveedores.cpp \
    providerslibrary.cpp \
    dlglistaprecios.cpp \
    dlgselectproviderpricelist.cpp \
    wndpricelist.cpp \
    dlgpriceitem.cpp \
    dlgcheckmaterialupdates.cpp \
    wndcostanalysis.cpp \
    dlgsetproject.cpp \
    analysis.cpp \
    analysisprovider.cpp \
    analysispricelist.cpp \
    analysispriceitem.cpp \
    analysiselement.cpp \
    printablewindow.cpp \
    fileheader.cpp \
    updatevalidator.cpp \
    htmlhelper.cpp \
    csvreader.cpp \
    dlgimportpricelist.cpp \
    dlgnewelement.cpp \
    wndbrowser.cpp \
    dlgrawvalue.cpp \
    xmlhelper.cpp \
    xmlnode.cpp \
    xmlkeynotfoundexception.cpp \
    wndpdfviewer.cpp \
    pdfredlining.cpp \
    redline.cpp \
    dlglinkredlinewithconstructiveelement.cpp \
    dlglistselector.cpp

HEADERS  += \
    elemento.h \
    unit.h \
    elementocomputo.h \
    cantidad.h \
    Dimension.h \
    cantidadlineal.h \
    superficietrapecial.h \
    circularsurface.h \
    rectangularsurface.h \
    materiallibrary.h \
    datastore.h \
    unitlibrary.h \
    proyecto.h \
    elementoconstructivo.h \
    computometrico.h \
    materialdockwindow.h \
    dlgnuevoelementoconstructivo.h \
    cantidadeslibrary.h \
    dlgcircularsurface.h \
    dlgcantidadlineal.h \
    dlgrectangularsurface.h \
    dlgsuperficietrapecial.h \
    mainwindowapplication.h \
    author.h \
    wndmateriales.h \
    superficiepoligonal.h \
    dlgsuperficiepoligonal.h \
    cantidadunitaria.h \
    perimetrocircular.h \
    prismatrapecial.h \
    cilindro.h \
    dlgcomponente.h \
    projectwindow.h \
    dlgprismavolume.h \
    listaprecios.h \
    proveedor.h \
    precio.h \
    dlgproveedor.h \
    wndproveedores.h \
    providerslibrary.h \
    dlglistaprecios.h \
    dlgselectproviderpricelist.h \
    wndpricelist.h \
    dlgpriceitem.h \
    dlgcheckmaterialupdates.h \
    wndcostanalysis.h \
    dlgsetproject.h \
    analysis.h \
    analysisprovider.h \
    analysispricelist.h \
    analysispriceitem.h \
    analysiselement.h \
    printablewindow.h \
    fileheader.h \
    updatevalidator.h \
    htmlhelper.h \
    csvreader.h \
    dlgimportpricelist.h \
    dlgnewelement.h \
    wndbrowser.h \
    rawvalue.h \
    dlgrawvalue.h \
    IValidator.h \
    xmlhelper.h \
    xmlnode.h \
    xmlkeynotfoundexception.h \
    wndpdfviewer.h \
    pdfredlining.h \
    redline.h \
    dlglinkredlinewithconstructiveelement.h \
    dlglistselector.h

FORMS    += \
    materialdockwindow.ui \
    dlgnuevoelementoconstructivo.ui \
    dlgcircularsurface.ui \
    dlgcantidadlineal.ui \
    dlgrectangularsurface.ui \
    dlgsuperficietrapecial.ui \
    projectwindow.ui \
    mainwindowapplication.ui \
    wndmateriales.ui \
    dlgsuperficiepoligonal.ui \
    dlgcomponente.ui \
    dlgprismavolume.ui \
    dlgproveedor.ui \
    wndproveedores.ui \
    dlglistaprecios.ui \
    dlgselectproviderpricelist.ui \
    wndpricelist.ui \
    dlgpriceitem.ui \
    dlgcheckmaterialupdates.ui \
    wndcostanalysis.ui \
    dlgsetproject.ui \
    dlgimportpricelist.ui \
    dlgnewelement.ui \
    wndbrowser.ui \
    dlgrawvalue.ui \
    wndpdfviewer.ui \
    dlglinkredlinewithconstructiveelement.ui \
    dlglistselector.ui

RESOURCES += \
    recursos.qrc
