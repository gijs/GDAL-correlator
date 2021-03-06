/******************************************************************************
 * Project:  GDAL
 * Purpose:  Correlator
 * Author:   Andrew Migal, migal.drew@gmail.com
 *
 ******************************************************************************
 * Copyright (c) 2012, Andrew Migal
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ****************************************************************************/

/**
 * @file
 * @author Andrew Migal migal.drew@gmail.com
 * @brief Collection of matched feature points.
 */

#ifndef GDALMATCHEDPOINTSCOLLECTION_H_
#define GDALMATCHEDPOINTSCOLLECTION_H_

#include "gdal.h"
#include "GDALFeaturePoint.h"
#include "GDALFeaturePointsCollection.h"

/**
 * @author Andrew Migal migal.drew@gmail.com
 * @brief Collection of matched feature points.
 * @details Class stores matched (corresponding) points,
 * which was detected on couple of images.
 * Doesn't copy objects and only contains pointers to actual instances.
 */
class GDALMatchedPointsCollection
{
public:
	GDALMatchedPointsCollection();
	virtual ~GDALMatchedPointsCollection();

	/**
	 * Add pair of feature points to collection. Doesn't copy objects.
	 *
	 * @param poFirstPoint Pointer to first feature point
	 * @param poSecondPoint Pointer to second feature point
	 */
	void AddPoints(GDALFeaturePoint *poFirstPoint, GDALFeaturePoint *poSecondPoint);

	/**
	 * Get pair of corresponding feature points. Method copies data into provided objects.
	 * If pointers are NULL or index isn't valid, does nothing.
	 *
	 * @param nIndex Index of pair. Should start from zero.
	 * @param poFirstPoint First feature point instance
	 * @param poSecondPoint Second feature point instance
	 */
	void GetPoints(int nIndex,
			GDALFeaturePoint *poFirstPoint, GDALFeaturePoint *poSecondPoint);

	/**
	 * Fetch number of corresponding pairs.
	 *
	 * @return Number of corresponding pairs.
	 */
	int GetSize() const;

	/**
	 * Empty collection and delete all stored objects.
	 */
	void Clear();

private:
	GDALFeaturePointsCollection *poCollect_1;
	GDALFeaturePointsCollection *poCollect_2;
};

#endif /* GDALMATCHEDPOINTSCOLLECTION_H_ */
