#ifndef _KVI_SELECTORS_H_
#define _KVI_SELECTORS_H_

//=============================================================================
//
//   File : kvi_selectors.h
//   Creation date : Mon Now 13 2000 15:21:10 CEST by Szymon Stefanek
//
//   This file is part of the KVirc irc client distribution
//   Copyright (C) 2000 Szymon Stefanek (pragma at kvirc dot net)
//
//   This program is FREE software. You can redistribute it and/or
//   modify it under the terms of the GNU General Public License
//   as published by the Free Software Foundation; either version 2
//   of the License, or (at your opinion) any later version.
//
//   This program is distributed in the HOPE that it will be USEFUL,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//   See the GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program. If not, write to the Free Software Foundation,
//   Inc. ,59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
//=============================================================================


#include "kvi_settings.h"
#include "kvi_string.h"
#include "kvi_pixmap.h"
#include "kvi_styled_controls.h"
#include "kvi_tal_hbox.h"
#include "kvi_tal_vbox.h"
#include "kvi_tal_scrollview.h"
#include "kvi_tal_listbox.h"
#include "kvi_tal_listview.h"

#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QColor>
#include <QFont>
#include <QSpinBox>
#include <QStringList>
#include <QValidator>

//#ifndef _KVI_SELECTORS_CPP_
//	extern void commitAllSelectors(QWidget * par,const char * classname);
//#endif


//
// This is the common KviSelectorInterface
//
//     Note: I'm always learning
//           Today I have discovered that:
//              QObject * o = new KviBoolSelector(...)
//              ((KviSelectorInterface *)o)->commit()
//           Does not work (SIGSEGV when jumping into commit(): bad vtable entry)
//           But the following works fine:
//              KviBoolSelector * b = new KviBoolSelector(...)
//              ((KviSelectorInterface *)b)->commit();
//           Mmmmmh.... the assembler generated by gcc
//           uses two different vtable offsets in the two cases
//           why ?
//

class KVIRC_API KviSelectorInterface
{
public:
	KviSelectorInterface(){};
	virtual ~KviSelectorInterface(){};
public:
	virtual void commit(){};
};

class KVIRC_API KviBoolSelector : public KviStyledCheckBox, public KviSelectorInterface
{
	Q_OBJECT
public:
	KviBoolSelector(QWidget * par,const QString & txt,bool *pOption,bool bEnabled);
	~KviBoolSelector(){};
private:
	bool * m_pOption;
public:
	virtual void commit();
public slots:
	void setNotEnabled(bool bNotEnabled);
};

class KVIRC_API KviStringSelector : public KviTalHBox, public KviSelectorInterface
{
	Q_OBJECT
public:
	KviStringSelector(QWidget * par,const QString & txt,QString * pOption,bool bEnabled);
	~KviStringSelector();
protected:
	QLabel    * m_pLabel;
	QLineEdit * m_pLineEdit;
	QString    * m_pOption;
public:
	void setValidator(QValidator * v){ m_pLineEdit->setValidator(v); };
	void setMinimumLabelWidth(unsigned int uWidth){ m_pLabel->setMinimumWidth(uWidth); };
	virtual void commit();
	virtual void setEnabled(bool bEnabled);
	void setText(const QString& text);
};


class KVIRC_API KviPasswordSelector : public KviStringSelector
{
	Q_OBJECT
public:
	KviPasswordSelector(QWidget * par,const QString & txt,QString * pOption,bool bEnabled);
	~KviPasswordSelector(){};
};

class KVIRC_API KviPixmapPreview : public KviTalScrollView
{
	Q_OBJECT
public:
	KviPixmapPreview(QWidget * par);
	~KviPixmapPreview();
protected:
	KviPixmap * m_pPixmap;
public:
	void setPixmap(KviPixmap * pix);
protected:
	virtual void drawContents(QPainter * p, int clipx, int clipy, int clipw, int cliph);

};

class KVIRC_API KviPixmapSelector : public QWidget, public KviSelectorInterface
{
	Q_OBJECT
public:
	KviPixmapSelector(QWidget * par,const QString & txt,KviPixmap * pOption,bool bEnabled);
	~KviPixmapSelector();
private:
	KviStyledCheckBox        * m_pCheckBox;
	QLabel           * m_pFileNameLabel;
	KviPixmapPreview * m_pPreview;
	QPushButton      * m_pChooseButton;
	KviPixmap        * m_pOption;
	KviPixmap          m_localPixmap;
public:
	void setImagePath(const char * path);
	virtual void commit();
	virtual void setEnabled(bool bEnabled);
protected slots:
	void checkBoxToggled(bool bEnabled);
	void choosePixmap();
};

class KVIRC_API KviUIntSelector : public KviTalHBox, public KviSelectorInterface
{
	Q_OBJECT
public:
	KviUIntSelector(QWidget * par,const QString & txt,unsigned int *pOption,
		unsigned int uLowBound,unsigned int uHighBound,unsigned int uDefault,bool bEnabled,bool bShortInt = false);
	~KviUIntSelector(){};
private:
	QLabel    * m_pLabel;
	QSpinBox  * m_pSpinBox;
	unsigned int * m_pOption;
	unsigned int m_uLowBound;
	unsigned int m_uHighBound;
	unsigned int m_uDefault;
	bool         m_bIsShortInt;
public:
	virtual void setPrefix(const QString & txt);
	virtual void setSuffix(const QString & txt);
	virtual void commit();
	virtual void setEnabled(bool bEnabled);
};


class KVIRC_API KviFileSelector : public KviTalHBox, public KviSelectorInterface
{
	Q_OBJECT
public:
	KviFileSelector(QWidget * par,const QString & txt,QString * pOption,bool bEnabled,unsigned int uFlags = 0,const QString &szFilter = QString::null);
	~KviFileSelector(){};
public:
	enum Flags {
		ChooseSaveFileName = 1,
		DontConfirmOverwrite = 2
	};
protected:
	QLabel      * m_pLabel;
	QLineEdit   * m_pLineEdit;
	QPushButton * m_pButton;
	QString     * m_pOption;
	unsigned int  m_uFlags;
	QString       m_szFilter;
public:
	virtual void commit();
	virtual void setEnabled(bool bEnabled);
	void setSelection(const QString &szSelection);
signals:
	void selectionChanged(const QString &szNewValue);
private slots:
	void browseClicked();
protected:
	virtual void select();
};

class KVIRC_API KviDirectorySelector : public KviFileSelector
{
	Q_OBJECT
public:
	KviDirectorySelector(QWidget * par,const QString & txt,QString * pOption,bool bEnabled);
	~KviDirectorySelector(){};
protected:
	virtual void select();
};


class KVIRC_API KviColorSelector : public KviTalHBox, public KviSelectorInterface
{
	Q_OBJECT
public:
	KviColorSelector(QWidget * par,const QString & txt,QColor * pOption,bool bEnabled);
	~KviColorSelector(){};
private:
	QLabel      * m_pLabel;
	QColor      * m_pOption;
	QColor        m_memColor;
	QPushButton * m_pButton;
public:
	virtual void commit();
	virtual void setEnabled(bool bEnabled);
	QColor getColor(){ return m_memColor; };
	void forceColor(QColor clr);
private:
	void setButtonPalette(QColor * pOption);
private slots:
	void changeClicked();
};

class KVIRC_API KviFontSelector : public KviTalHBox, public KviSelectorInterface
{
	Q_OBJECT
public:
	KviFontSelector(QWidget * par,const QString & txt,QFont * pOption,bool bEnabled);
	~KviFontSelector(){};
private:
	QLabel      * m_pLabel;
	QFont       * m_pOption;
	QPushButton * m_pButton;
public:
	virtual void commit();
	virtual void setEnabled(bool bEnabled);
private:
	void setButtonFont(QFont * pOption);
private slots:
	void changeClicked();
};

class KVIRC_API KviStringListSelector : public KviTalVBox, public KviSelectorInterface
{
	Q_OBJECT
public:
	KviStringListSelector(QWidget * par,const QString & txt,QStringList * pOption,bool bEnabled);
	~KviStringListSelector();
private:
	QLabel      * m_pLabel;
	KviTalListBox    * m_pListBox;
	QLineEdit   * m_pLineEdit;
	QPushButton * m_pAddButton;
	QPushButton * m_pRemoveButton;
	QStringList * m_pOption;
public:
	virtual void commit();
	virtual void setEnabled(bool bEnabled);
private slots:
	void textChanged(const QString &str);
	void selectionChanged();
	void addClicked();
	void removeClicked();
};

class KviTalPopupMenu;

class KVIRC_API KviMircTextColorSelector : public KviTalHBox, public KviSelectorInterface
{
	Q_OBJECT
public:
	KviMircTextColorSelector(QWidget * par,const QString &txt,unsigned int * uFore,unsigned int * uBack,bool bEnabled);
	~KviMircTextColorSelector();
private:
	QLabel *m_pLabel;
	QPushButton * m_pButton;
	unsigned int * m_pUFore;
	unsigned int * m_pUBack;
	unsigned int m_uFore;
	unsigned int m_uBack;
	KviTalPopupMenu * m_pContextPopup;
	KviTalPopupMenu * m_pForePopup;
	KviTalPopupMenu * m_pBackPopup;
public:
	virtual void commit();
	virtual void setEnabled(bool bEnabled);
protected slots:
	void buttonClicked();
	void foreSelected(int);
	void backSelected(int);
protected:
	void setButtonPalette();
};


class KVIRC_API KviSoundSelector : public KviFileSelector
{
	Q_OBJECT
public:
	KviSoundSelector(QWidget * par,const QString & txt,QString * pOption,bool bEnabled);
	~KviSoundSelector();
protected:
	QPushButton	*m_pPlayButton;
private slots:
	void playSound();
public:
	virtual void setEnabled(bool bEnabled);
};

class KVIRC_API KviChanListViewItem : public KviTalListViewItem
{
private:
	QString m_szPass;
public:
	KviChanListViewItem(KviTalListView* pList,QString szChan,QString szPass);
	~KviChanListViewItem() {};
	
	const QString& pass() { return m_szPass; }
};

class KVIRC_API KviCahnnelListSelector : public KviTalVBox, public KviSelectorInterface
{
	Q_OBJECT
public:
	KviCahnnelListSelector(QWidget * par,const QString & txt,QStringList * pOption,bool bEnabled);
	~KviCahnnelListSelector();
private:
	QLabel       * m_pLabel;
	KviTalListView    * m_pListView;
	QLineEdit    * m_pChanLineEdit;
	QLineEdit    * m_pPassLineEdit;
	QPushButton  * m_pAddButton;
	QPushButton  * m_pRemoveButton;
	QStringList  * m_pOption;
public:
	virtual void commit();
	virtual void setEnabled(bool bEnabled);
private slots:
	void textChanged(const QString &str);
	void selectionChanged();
	void addClicked();
	void removeClicked();
};

#endif //!_KVI_SELECTORS_H_
