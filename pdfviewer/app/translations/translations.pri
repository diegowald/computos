defineReplace(tsFilesInDir) { # this macro returns a list containing the .ts files with their path (as specified in the first argument)
	dir = $$member(ARGS, 0) # first argument is the directory name
	languages = $$replace(ARGS, $${dir}, "") # remove first argument and keep only the languages
	tsfiles =

	for(lang, languages) {
		tsName = $${dir}/pdfviewer_$${lang}.ts # this assumes that names the .ts files are of the form pdfviewer_fr.ts
#		exists($$tsName) {
			tsfiles += $$tsName
#		}
	}
	return($$tsfiles)
}

defineReplace(qmFiles) { # this macro returns for the list of .ts files the corresponding list of .qm files
	names = $$ARGS
	qmfiles =

	for(name, names) {
		baseName = $$replace(name, "\\.ts", "") # remove extension
		baseName = $$replace(baseName, ".*\\/", "") # remove path
		qmName = $${OUT_PWD}/$${baseName}.qm # qm files are stored in the build directory
		qmfiles += $$qmName
	}
	return($$qmfiles)
}

LANGUAGES = fr # list all the languages here
TRANSLATIONS += $$tsFilesInDir($${PWD} $${LANGUAGES}) # list of .ts files in this directory with their full path
!isEmpty(TRANSLATIONS) {
	### Create or update .ts files
	ts.commands = lupdate $${PWD}/../src -ts $${TRANSLATIONS}
	QMAKE_EXTRA_TARGETS += ts

	### Create .qm files
	updateqm.name = lrelease ${QMAKE_FILE_IN}
	updateqm.input = TRANSLATIONS
	updateqm.output = $${OUT_PWD}/${QMAKE_FILE_BASE}.qm
	updateqm.commands = lrelease -silent ${QMAKE_FILE_IN} -qm ${QMAKE_FILE_OUT}
	updateqm.CONFIG = no_link target_predeps
	QMAKE_EXTRA_COMPILERS += updateqm

	### Install .qm files
	translations.files = $$qmFiles($${TRANSLATIONS})
	translations.path = $$PDFVIEWER_TRANSLATIONS_INSTALL_DIR
	translations.CONFIG += no_check_exist
	INSTALLS += translations
}
