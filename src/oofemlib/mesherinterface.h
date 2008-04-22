/* $Header: /home/cvs/bp/oofem/oofemlib/src/mesherinterface.h,v 1.5 2003/04/06 14:08:25 bp Exp $ */
/*
 *
 *                 #####    #####   ######  ######  ###   ###
 *               ##   ##  ##   ##  ##      ##      ## ### ##
 *              ##   ##  ##   ##  ####    ####    ##  #  ##
 *             ##   ##  ##   ##  ##      ##      ##     ##
 *            ##   ##  ##   ##  ##      ##      ##     ##
 *            #####    #####   ##      ######  ##     ##
 *
 *
 *             OOFEM : Object Oriented Finite Element Code
 *
 *               Copyright (C) 1993 - 2008   Borek Patzak
 *
 *
 *
 *       Czech Technical University, Faculty of Civil Engineering,
 *   Department of Structural Mechanics, 166 29 Prague, Czech Republic
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

//   ******************************
//   *** CLASS MESHER INTERFACE ***
//   ******************************

#ifndef mesherinterface_h
#define mesherinterface_h


class Domain;
class TimeStep;

/**
 * The base class representing the interface to mesh generation package.
 * This interface is rimarly responsible for two main tasks:
 * - to create input mesher file, containing all informations including the mesh density informations
 * based on informations from remeshing criteria.
 * - possibly to launch the mesher and transform its output to oofem input
 */
class MesherInterface
{
public:
    /// Constructor
    MesherInterface() { }
    /// Destructor
    virtual ~MesherInterface() { }

    /**
     * Runs the mesh generation, mesh will be written to corresponding domain din file
     * @param d the "old" domain containing the mesh density informations
     * @param time step
     * @param domainNumber new domain number
     * @param domainSerNum new domain serial number
     */
    virtual int createMesh(Domain *d, TimeStep *, int domainNumber, int domainSerNum) = 0;
};

#endif // mesherinterface_h
