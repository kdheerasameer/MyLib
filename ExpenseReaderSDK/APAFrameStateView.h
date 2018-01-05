//
//  APAFrameStateView.h
//  Algorithm Prototypes
//
//  Created by Dheerasameer KOTTAPALLI on 31/10/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface APAFrameStateView : UIView

/*!
 * Use this property to adjust text display
 */
@property (nonatomic, nonnull, readonly) UILabel *label;

/*!
 * Animation to show/hide the frame state view
 * @param hidden flag to show or hide
 * @param animated flag to whether animate or not
 */
- (void)changeToHidden:(BOOL)hidden animated:(BOOL)animated;

/*!
 * Change text of frame state view with animation
 * @param newText new text to be shown
 * @param newBGImage background image of the state view
 * @param animated flag to whether animate or not
 */
- (void)changeToText:(nullable NSString *)newText backgroundImage:(nullable UIImage *)newBGImage animated:(BOOL)animated;
@end
