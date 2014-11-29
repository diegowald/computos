TEMPLATE = subdirs
#SUBDIRS = lib app
SUBDIRS = sub_computos sub_pdfviewer

sub_pdfviewer.subdir = pdfviewer/lib
sub_computos.subdir = Computos
sub_computos.depends = sub_pdfviewer
