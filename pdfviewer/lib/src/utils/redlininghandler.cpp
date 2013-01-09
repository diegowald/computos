
/***************************************************************************
 *   Copyright (C) 2012 by Diego Ignacio Wald                              *
 *     <diego.wald@gmail.com>                                              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.  *
 ***************************************************************************/

#include "redlininghandler.h"

#include <QMenu>
#include "filesettings.h"
//#include "icon.h"
//#include "../shortcuthandler/shortcuthandler.h"
#include "../dlgredline.h"

RedliningHandler::RedliningHandler(RedliningWidget *parent)
    : QObject(parent->widget())
    , m_redlinesMenuAction(0)
{
    m_redlinesWidget = parent;

    m_redlinesMenu = new QMenu(tr("&Redlining", "Menu title"), parent->widget());

//	QAction *setBookmarkAction = new QAction(Icon("bookmark-new"), tr("Set &Bookmark", "Action"), m_bookmarksMenu);
    QAction *setredlineAction = new QAction(tr("Set redline", "Action"), m_redlinesMenu);
    setredlineAction->setObjectName(QLatin1String("pdfview_redlines_set"));
#ifndef QT_NO_SHORTCUT
    setredlineAction->setShortcut(tr("Ctrl+R", "Redlines|Set"));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_STATUSTIP
    setredlineAction->setStatusTip(tr("Set or unset a redline at the current position"));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
    setredlineAction->setWhatsThis(tr("<p>Set or unset a redline at the current line.</p>"));
#endif // QT_NO_WHATSTHIS
    connect(setredlineAction, SIGNAL(triggered()), this, SLOT(toggleRedline()));
    m_redlinesMenu->addAction(setredlineAction);
//#ifndef QT_NO_SHORTCUT
//	ShortcutHandler::instance()->addAction(setBookmarkAction);
//#endif // QT_NO_SHORTCUT

//	QAction *previousBookmarkAction = new QAction(Icon("go-up"), tr("&Previous Bookmark", "Action"), m_bookmarksMenu);
    QAction *previousRedlineAction = new QAction(tr("&Previous redline", "Action"), m_redlinesMenu);
    previousRedlineAction->setObjectName(QLatin1String("pdfview_redlines_prev"));
#ifndef QT_NO_SHORTCUT
    previousRedlineAction->setShortcut(tr("Alt+Up", "Redlines|Previous"));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_STATUSTIP
    previousRedlineAction->setStatusTip(tr("Go to the previous redline"));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
    previousRedlineAction->setWhatsThis(tr("<p>Go to the previous redline.</p>"));
#endif // QT_NO_WHATSTHIS
    previousRedlineAction->setEnabled(false);
    connect(previousRedlineAction, SIGNAL(triggered()), this, SLOT(goToPreviuousRedline()));
    m_redlinesMenu->addAction(previousRedlineAction);
//#ifndef QT_NO_SHORTCUT
//	ShortcutHandler::instance()->addAction(previousBookmarkAction);
//#endif // QT_NO_SHORTCUT

//	QAction *nextBookmarkAction = new QAction(Icon("go-down"), tr("&Next Bookmark", "Action"), m_bookmarksMenu);
    QAction *nextRedlineAction = new QAction(tr("&Next Redline", "Action"), m_redlinesMenu);
    nextRedlineAction->setObjectName(QLatin1String("pdfview_redline_next"));
#ifndef QT_NO_SHORTCUT
    nextRedlineAction->setShortcut(tr("Alt+Down", "Redlines|Next"));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_STATUSTIP
    nextRedlineAction->setStatusTip(tr("Go to the next redline"));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
    nextRedlineAction->setWhatsThis(tr("<p>Go to the next redline.</p>"));
#endif // QT_NO_WHATSTHIS
    nextRedlineAction->setEnabled(false);
    connect(nextRedlineAction, SIGNAL(triggered()), this, SLOT(goToNextRedline()));
    m_redlinesMenu->addAction(nextRedlineAction);
//#ifndef QT_NO_SHORTCUT
//	ShortcutHandler::instance()->addAction(nextBookmarkAction);
//#endif // QT_NO_SHORTCUT

    m_redlinesMenu->addSeparator();
    displayRedliningDialog = true;
    emitRedliningSignals = false;
}

RedliningHandler::~RedliningHandler()
{
    delete m_redlinesMenu;
}

QAction *RedliningHandler::menuAction()
{
    if (!m_redlinesMenuAction)
    {
        m_redlinesMenuAction = new QAction(parent());
        m_redlinesMenuAction->setText(m_redlinesMenu->title());
        m_redlinesMenuAction->setMenu(m_redlinesMenu);
    }
    return m_redlinesMenuAction;
}

QMenu *RedliningHandler::menu()
{
    return m_redlinesMenu;
}

QAction *RedliningHandler::action(int which)
{
    QList<QAction*> redlineActions = m_redlinesMenu->actions();
    if (which < 0 || which >= redlineActions.size())
        return 0;
    return redlineActions.at(which);
}

/***************************************************************************/

void RedliningHandler::setRedlines(const QList<Redline> &redlines)
{
    m_redlines = redlines;
}

QList<Redline> RedliningHandler::redlines() const
{
    return m_redlines;
}

void RedliningHandler::setPageLabels(const QStringList &labels)
{
    m_pageLabels = labels;
}

void RedliningHandler::updateActions()
{
    const Redline redline = m_redlinesWidget->redline();
    int which = -1;
    QList<QAction*> redlineActions = m_redlinesMenu->actions();
    for (int i = 0; i < m_redlines.size(); ++i)
    {
        if (m_redlines.at(i).name == redline.name)
/*        if (qFuzzyCompare(m_redlines.at(i), redline))*/
        {
            which = i;
            break;
        }
    }
    redlineActions.at(0)->setText(which >= 0 ? tr("Unset &Redline", "Action") : tr("Set &Redline", "Action"));
    // XXX disabling the following causes Alt+Up and Alt+Down not to be caught anymore :(
    //redlineActions.at(1)->setEnabled(m_redlines.size() > 0 && pos > m_redlines.at(0) && !qFuzzyCompare(pos, m_redlines.at(0)));
    //redlineActions.at(2)->setEnabled(m_redlines.size() > 0 && pos < m_redlines.at(m_redlines.size() - 1) && !qFuzzyCompare(pos, m_redlines.at(m_redlines.size() - 1)));
}

/***************************************************************************/
// Adding and removing redlines

void RedliningHandler::insertRedline(int index, Redline redline)
{
//	QAction *action = new QAction(tr("Page %1").arg(QString::number(int(pos))), m_bookmarksMenu);

    if (displayRedliningDialog)
    {
        dlgRedline dlg;
        if (dlg.exec() == QDialog::Accepted)
        {
            redline.name = dlg.Name();
            redline.color = dlg.Color();
        }
    }

    Q_ASSERT_X(redline.pageNumber < m_pageLabels.size(), "RedliningHandler", "make sure to call setPageLabels() before inserting redlines with insertRedline(), appendRedline(), toggleRedline() or loadRedlines()");
    QAction *action = new QAction(tr("Page %1, %2").arg(m_pageLabels.at(redline.pageNumber)).arg(redline.name), m_redlinesMenu);
    action->setData(redline.name);
    connect(action, SIGNAL(triggered()), this, SLOT(goToActionRedline()));
    if (index >= 0 && index < m_redlines.size())
    {
        m_redlines.insert(index, redline);
        m_redlinesMenu->insertAction(m_redlinesMenu->actions().at(index+4), action);
    }
    else // append at the end
    {
        m_redlines.append(redline);
        m_redlinesMenu->addAction(action);
    }
    updateActions();
    emit redlineUpdated(redline);

    if (emitRedliningSignals)
        emit redlineCreated(redline);
}

void RedliningHandler::appendRedline(Redline redline)
{
    if (redline.pageNumber < 0)
        return;
    insertRedline(-1, redline); // using -1 as index ensures that pos will be appended at the end of the bookmarks list
}

void RedliningHandler::removeRedline(int index)
{
    if (index >= 0 && index < m_redlines.size())
    {
        const Redline redline = m_redlines.at(index);
        m_redlines.removeAt(index);
        m_redlinesMenu->removeAction(m_redlinesMenu->actions().at(index+4)); // 4 is the number of actions defined in the constructor
        updateActions();
        Q_EMIT redlineUpdated(redline);
        if (emitRedliningSignals)
            emit redlineDeleted(redline);
    }
}

void RedliningHandler::setDisplayRedlineDialog(bool displayDialog)
{
    displayRedliningDialog = displayDialog;
}

void RedliningHandler::setEmitRedliningSignals(bool emitSignals)
{
    emitRedliningSignals = emitSignals;
}

/*void RedliningHandler::removeRedlineAtPosition(double pos)
{
    removeRedline(m_redlines.indexOf(pos));
}*/
void RedliningHandler::removeRedline(Redline redline)
{
    //removeRedline(m_redlines.indexOf(redline));
}

void RedliningHandler::toggleRedline()
{
    const Redline redline = m_redlinesWidget->redline();
    for (int i = 0; i < m_redlines.size(); ++i)
    {
        if (m_redlines.at(i).name == redline.name)
        {
            removeRedline(i);
            return;
        }
        /*else if (m_redlines.at(i) > pos)
        {
            insertRedline(i, pos);
            return;
        }*/
    }
    appendRedline(redline); // if pos is larger than any number in the list, then we insert pos at the end of the list
}

void RedliningHandler::clear()
{
    while (!m_redlines.isEmpty())
        removeRedline(0);
}

/***************************************************************************/
// Going to a bookmark

void RedliningHandler::goToActionRedline()
{
    QAction *action = qobject_cast<QAction*>(sender());
    Q_EMIT goToPosition(action->data().toDouble());
}

void RedliningHandler::goToPreviuousRedline()
{
/*    const Redline redline = m_redlinesWidget->redline();
    for (int i = m_bookmarks.size() - 1; i >= 0; --i)
    {
        if ()
        if (qFuzzyCompare(pos, m_bookmarks.at(i)) && i > 0) // when the bookmarks are saved and reloaded on the next startup, they are not exact anymore, so we must use qFuzzyCompare() to test whether we are on a bookmark; this must happen before the else-part to avoid staying on the current bookmark
        {
            Q_EMIT goToPosition(m_bookmarks.at(i-1));
            return;
        }
        else if (pos > m_bookmarks.at(i))
        {
            Q_EMIT goToPosition(m_bookmarks.at(i));
            return;
        }
    }*/
}

void RedliningHandler::goToNextRedline()
{
/*    const double pos = m_bookmarksWidget->position();
    for (int i = 0; i < m_bookmarks.size(); ++i)
    {
        if (qFuzzyCompare(pos, m_bookmarks.at(i)) && i < m_bookmarks.size() - 1) // when the bookmarks are saved and reloaded on the next startup, they are not exact anymore, so we must use qFuzzyCompare() to test whether we are on a bookmark; this must happen before the else-part to avoid staying on the current bookmark
        {
            Q_EMIT goToPosition(m_bookmarks.at(i+1));
            return;
        }
        else if (pos < m_bookmarks.at(i))
        {
            Q_EMIT goToPosition(m_bookmarks.at(i));
            return;
        }
    }*/
}

/***************************************************************************/
// Recalculate the positions of the bookmarks. If in a text editor some lines are added or removed, then the bookmarks below it must be moved along with the corresponding lines and the bookmarks in the removed area must be removed themselves too.

void RedliningHandler::recalculateRedlines(double pos, double offset)
{
    if (offset == 0)
        return;
/*
    for (int i = 0; i < m_bookmarks.size(); ++i)
    {
        // if an area containing a bookmark is removed, then the bookmark itself must also be removed
        if (offset < 0 && pos <= m_bookmarks.at(i) && pos - offset > m_bookmarks.at(i))
        {
            m_bookmarks.removeAt(i);
            --i;
        }
        else if (pos <= m_bookmarks.at(i)) // shift all bookmarks that come after the insertion or deletion
            m_bookmarks[i] += offset;
    }*/
}

/***************************************************************************/
// Load and save bookmarks from disk

void RedliningHandler::loadRedlines(const QString &filename)
{
/*    m_fileName = fileName;
    while (!m_bookmarks.isEmpty())
        removeBookmark(0);

    // Load file specific bookmarks
    FileSettings fileSettings(m_fileName);
    QList<QVariant> bookmarksVariantList = fileSettings.value(QLatin1String("Bookmarks")).toList();
    for (int i = 0; i < bookmarksVariantList.size(); ++i)
        appendBookmark(bookmarksVariantList.at(i).toDouble());*/
}

void RedliningHandler::saveRedlines()
{/*
    QList<double> bookmarksList = bookmarks();
//	if (bookmarksList.isEmpty())
//	{
//		const QString fileSettingsFile = fileSettingsPath(m_fileName);
//		if (QFile::exists(fileSettingsFile))
//			QFile::remove(fileSettingsFile);
//	}
    FileSettings fileSettings(m_fileName);
    if (!bookmarksList.isEmpty())
    {
        QList<QVariant> bookmarksVariantList; // cannot use QStringList because QString::number() loses precision, QVariant() also loses precision :( but less
        for (int i = 0; i < bookmarksList.size(); ++i)
            bookmarksVariantList << QVariant(bookmarksList.at(i));
        fileSettings.setValue(QLatin1String("Bookmarks"), bookmarksVariantList);
    }
    else
        fileSettings.remove(QLatin1String("Bookmarks"));*/
}
