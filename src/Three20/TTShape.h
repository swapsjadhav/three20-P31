/**
 * Copyright 2009 Facebook
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "Three20/TTGlobal.h"

@interface TTShape : NSObject

- (void)openPath:(CGRect)rect;
- (void)closePath:(CGRect)rect;

- (void)addTopEdgeToPath:(CGRect)rect lightSource:(NSInteger)lightSource;
- (void)addRightEdgeToPath:(CGRect)rect lightSource:(NSInteger)lightSource;
- (void)addBottomEdgeToPath:(CGRect)rect lightSource:(NSInteger)lightSource;
- (void)addLeftEdgeToPath:(CGRect)rect lightSource:(NSInteger)lightSource;

/**
 * Opens the path, adds all edges, and closes the path.
 */
- (void)addToPath:(CGRect)rect;

- (void)addInverseToPath:(CGRect)rect;

- (UIEdgeInsets)insetsForSize:(CGSize)size;

@end

///////////////////////////////////////////////////////////////////////////////////////////////////

@interface TTRectangleShape : TTShape

+ (TTRectangleShape*)shape;

@end

///////////////////////////////////////////////////////////////////////////////////////////////////

@interface TTRoundedRectangleShape : TTShape {
  CGFloat _topLeftRadius;
  CGFloat _topRightRadius;
  CGFloat _bottomRightRadius;
  CGFloat _bottomLeftRadius;
}

@property(nonatomic) CGFloat topLeftRadius;
@property(nonatomic) CGFloat topRightRadius;
@property(nonatomic) CGFloat bottomRightRadius;
@property(nonatomic) CGFloat bottomLeftRadius;

+ (TTRoundedRectangleShape*)shapeWithRadius:(CGFloat)radius;

+ (TTRoundedRectangleShape*)shapeWithTopLeft:(CGFloat)topLeft topRight:(CGFloat)topRight
      bottomRight:(CGFloat)bottomRight bottomLeft:(CGFloat)bottomLeft;

@end

///////////////////////////////////////////////////////////////////////////////////////////////////

@interface TTRoundedRightArrowShape : TTShape {
  CGFloat _radius;
}

@property(nonatomic) CGFloat radius;

+ (TTRoundedRightArrowShape*)shapeWithRadius:(CGFloat)radius;

@end

///////////////////////////////////////////////////////////////////////////////////////////////////

@interface TTRoundedLeftArrowShape : TTShape {
  CGFloat _radius;
}

@property(nonatomic) CGFloat radius;

+ (TTRoundedLeftArrowShape*)shapeWithRadius:(CGFloat)radius;

@end

///////////////////////////////////////////////////////////////////////////////////////////////////

@interface TTSpeechBubbleShape : TTShape {
  CGFloat _radius;
  CGFloat _pointLocation;
  CGFloat _pointAngle;
  CGSize _pointSize;
}

@property(nonatomic) CGFloat radius;
@property(nonatomic) CGFloat pointLocation;
@property(nonatomic) CGFloat pointAngle;
@property(nonatomic) CGSize pointSize;

+ (TTSpeechBubbleShape*)shapeWithRadius:(CGFloat)radius pointLocation:(CGFloat)pointLocation
                        pointAngle:(CGFloat)pointAngle pointSize:(CGSize)pointSize;

@end
