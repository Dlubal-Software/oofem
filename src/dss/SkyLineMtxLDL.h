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
/*
 * Author: Richard Vondracek, <richard.vondracek@seznam.cz>
 */


#ifndef skylinemtxldl_h
#define skylinemtxldl_h

#include "SkyLineMtx.h"

DSS_NAMESPASE_BEGIN

/// <summary>
/// Summary description for SkyLineMtxLDL.
/// </summary>
class SkyLineMtxLDL :
    public SkyLineMtx
{
public:
    SkyLineMtxLDL(SparseMatrixF &sm, Ordering *order, MathTracer *eMT);
    virtual ~SkyLineMtxLDL();

    void LoadMatrixData(SparseMatrixF &sm);


public:
    virtual void Solve(double *b, double *x) { };

    //ILargeMatrix
    virtual double &ElementAt(int i, int j);
    virtual void LoadZeros();
    virtual void LoadMatrixNumbers(SparseMatrixF &sm);
    virtual void SolveLV(const LargeVector &b, LargeVector &x);
    virtual void Factorize();
    virtual void MultiplyByVector(const LargeVectorAttach &x, LargeVectorAttach &y);

public:
    virtual void SchurComplementFactorization(int fixed_blocks);
    virtual void SolveA11(double *x, long fixed_blocks);
    virtual void Sub_A21_A11inv(double *x, long fixed_blocks);
    virtual void Sub_A11inv_A12(double *x, long fixed_blocks);
    virtual void WriteCondensedMatrixA22(double *a, Ordering *mcn, IntArrayList *lncn);
}; //class SkyLineMtxLDL

DSS_NAMESPASE_END

#endif
