//
//  APAScanFeebackView.h
//  Algorithm Prototypes
//
//  Created by Dheerasameer KOTTAPALLI on 29/11/17.
//  Copyright © 2017 Amadeus IT Group. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface APAScanFeebackView : UIView

/*!
 * Setup method for feedback view
 * @param feedbackImage image for the feedback
 * @param feedbackMessage message for the feedback
 */
- (void)setupFeedbackViewWithImage:(UIImage *)feedbackImage message:(NSString *)feedbackMessage;

@end
