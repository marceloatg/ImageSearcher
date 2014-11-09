ImageSearcher
=============

A  image searcher based in three components: color, texture and form.

The color engine divides an image in 4 parts and then a HSV histogram is generated for each part.
This histogram containing 256 levels is stored as a feature vector.

The texture engine divides an image in 4 parts and then the LBP algorithm is applied into the image.
For each part of the image, a 256 level histogram is generated and stored as a feature vector.

In order to search an image, the Euclidean distance is applied considering the selected feature vectors.
