/***************************************************************************
 *   Copyright (C) 2007, 2009 by Marcelo Francis Maduar, maduar@gmail.com                                                      *
 *                                                                         *
 *   This file is part of OpenGamma.                                       *
 *                                                                         *
 *   OpenGamma is free software; you can redistribute it and/or modify     *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   OpenGamma is distributed in the hope that it will be useful,          *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with OpenGamma. If not, see <http://www.gnu.org/licenses/>.     *
 ***************************************************************************/


#include "energypicker.h"

void EnergyPicker::setPickerEnCal( Doblst a )
{
    // enCal->fitType = POLY;
    enCal->setParms( a );
}

void EnergyPicker::setPickerEnCalDefault()
{
    enCal->setDefaultCalibration();
}

QwtText EnergyPicker::trackerText( const QPointF &pos ) const
{
    QString ret;
    if ( enCal->isCalib() )
        ret = QString("%1 keV\ncounts: %2")
                 .arg( enCal->y( pos.x() ) )
                 .arg( pos.y());
    else
        ret = "uncalib.";
    return QwtText( ret );
}
