//=============================================================================
//
//   Creation date : Fri Aug 08 18:00:00 2008 GMT by Fabio Bas
//
//   This file is part of the KVirc irc client distribution
//   Copyright (C) 2008 Szymon Stefanek (pragma at kvirc dot net)
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
//   Original Copyright follows:
//=============================================================================

/***************************************************************************
                          rootservice.h -  description
                             -------------------
    begin                : Mon Jul 25 2005
    copyright            : (C) 2005 by Diederik van der Boor
    email                : vdboor --at-- codingdomain.com
 ***************************************************************************/

#ifndef UPNP_ROOTSERVICE_H
#define UPNP_ROOTSERVICE_H

#include "service.h"


namespace UPnP
{

/**
 * The services of a device can be retrieved using the device root service.
 * The URL of the root service is returned by an SSDP broadcast.
 * The root service returns the meta information and list of services the device supports.
 *
 * @author Diederik van der Boor
 * @ingroup NetworkUPnP
 */
class RootService : public Service
{
public:  // public methods

	// The constructor
	RootService(const QString &hostname, int port, const QString &rootUrl);
	// The destructor
	virtual             ~RootService();

	// Return the device type
	QString              getDeviceType() const;

	// Return a service from the cached root device entry
	ServiceParameters    getServiceById(const QString &serviceId) const;
	// Return a service from a cached embedded device entry
	ServiceParameters    getServiceById(const QString &serviceId, const QString &deviceUdn) const;
	// Return a service from the cached root device entry
	ServiceParameters    getServiceByType(const QString &serviceType) const;
	// Return a service from a cached embedded device entry
	ServiceParameters    getServiceByType(const QString &serviceType, const QString &deviceUdn) const;

	// Query the device for its service list
	void                 queryDevice();


protected:  // Protected methods
	// The control point received a response to callInformationUrl()
	virtual void         gotInformationResponse(const QDomNode &response);


private:  // Private methods
	// Recursively add all devices and embedded devices to the deviceServices_ map
	void                 addDeviceServices(const QDomNode &device);


private:
	// The device type
	QString                     m_szDeviceType;
	// A collection of all services provided by the device
	QMap<QString,QDomNodeList>  m_deviceServices;
	// The hostname of the device
	QString                     m_szHostname;
	// The port of the device
	int                         m_iPort;
	// The udn of the root device
	QString                     m_szRootUdn;
};

}

#endif
