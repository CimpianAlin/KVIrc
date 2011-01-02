#ifndef _OPTW_IRCVIEW_H_
#define _OPTW_IRCVIEW_H_

//=============================================================================
//
//   File : OptionsWidget_ircView.h
//   Creation date : Sat Aug 11 2001 03:28:19 CEST by Szymon Stefanek
//
//   This file is part of the KVIrc irc client distribution
//   Copyright (C) 2001 Szymon Stefanek (pragma at kvirc dot net)
//   Copyright (C) 2008 Elvio Basello (hellvis69 at netsons dot org)
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
//   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
//
//=============================================================================


#include "KviOptionsWidget.h"

#include <QComboBox>


#define KVI_OPTIONS_WIDGET_ICON_KviIrcViewThemeOptionsWidget KVI_SMALLICON_IRCVIEW
#define KVI_OPTIONS_WIDGET_NAME_KviIrcViewThemeOptionsWidget __tr2qs_no_lookup("Output")
#define KVI_OPTIONS_WIDGET_KEYWORDS_KviIrcViewThemeOptionsWidget __tr2qs_no_lookup("theme,colors,output")
#define KVI_OPTIONS_WIDGET_GROUP_KviIrcViewThemeOptionsWidget "theme"
#define KVI_OPTIONS_WIDGET_CONTAINER_KviIrcViewThemeOptionsWidget true

class OptionsWidget_ircViewTheme : public KviOptionsWidget
{
	Q_OBJECT
public:
	OptionsWidget_ircViewTheme(QWidget * pParent);
	~OptionsWidget_ircViewTheme();
};

#define KVI_OPTIONS_WIDGET_ICON_KviIrcViewLookOptionsWidget KVI_SMALLICON_IRCVIEW
#define KVI_OPTIONS_WIDGET_NAME_KviIrcViewLookOptionsWidget __tr2qs_no_lookup("Look")
#define KVI_OPTIONS_WIDGET_KEYWORDS_KviIrcViewLookOptionsWidget __tr2qs_no_lookup("theme,colors,output")
#define KVI_OPTIONS_WIDGET_GROUP_KviIrcViewLookOptionsWidget "theme"
#define KVI_OPTIONS_WIDGET_PARENT_KviIrcViewLookOptionsWidget OptionsWidget_ircViewTheme
#define KVI_OPTIONS_WIDGET_PRIORITY_KviIrcViewLookOptionsWidget 30

class OptionsWidget_ircViewLook : public KviOptionsWidget
{
	Q_OBJECT
private:
	QComboBox * m_pHorizontalAlign;
	QComboBox * m_pVerticalAlign;
public:
	OptionsWidget_ircViewLook(QWidget * parent);
	~OptionsWidget_ircViewLook();
public:
	virtual void commit();
};

#define KVI_OPTIONS_WIDGET_ICON_KviIrcViewFeaturesOptionsWidget KVI_SMALLICON_IRCVIEW
#define KVI_OPTIONS_WIDGET_NAME_KviIrcViewFeaturesOptionsWidget __tr2qs_no_lookup("Features")
#define KVI_OPTIONS_WIDGET_GROUP_KviIrcViewFeaturesOptionsWidget "theme"
#define KVI_OPTIONS_WIDGET_PARENT_KviIrcViewFeaturesOptionsWidget OptionsWidget_ircViewTheme
#define KVI_OPTIONS_WIDGET_PRIORITY_KviIrcViewFeaturesOptionsWidget 20

class OptionsWidget_ircViewFeatures : public KviOptionsWidget
{
	Q_OBJECT
public:
	OptionsWidget_ircViewFeatures(QWidget * parent);
	~OptionsWidget_ircViewFeatures();
};

#define KVI_OPTIONS_WIDGET_ICON_KviIrcViewMarkerOptionsWidget KVI_SMALLICON_IRCVIEW
#define KVI_OPTIONS_WIDGET_NAME_KviIrcViewMarkerOptionsWidget __tr2qs_no_lookup("Marker")
#define KVI_OPTIONS_WIDGET_GROUP_KviIrcViewMarkerOptionsWidget "theme"
#define KVI_OPTIONS_WIDGET_PARENT_KviIrcViewMarkerOptionsWidget OptionsWidget_ircViewTheme
#define KVI_OPTIONS_WIDGET_PRIORITY_KviIrcViewMarkerOptionsWidget 10

class OptionsWidget_ircViewMarker : public KviOptionsWidget
{
	Q_OBJECT
public:
	OptionsWidget_ircViewMarker(QWidget * pParent);
	~OptionsWidget_ircViewMarker();
	virtual void commit();
private:
	QComboBox * m_pMarkerStyle;
};


#endif //!_OPTW_IRCVIEW_H_