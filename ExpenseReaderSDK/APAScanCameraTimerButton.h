//
//
//

#import <UIKit/UIKit.h>

typedef void(^APAScanCameraTimerButtonCompletionBlock)();


/// Button with line.
/// Also, performs task of a timer.
@interface APAScanCameraTimerButton : UIButton

/// start main animation
- (void)startTimerWithCompletion:(nullable APAScanCameraTimerButtonCompletionBlock)completion;

/// break main animation
- (void)stopTimer;

/// stop timer and reset all states
- (void)resetState;

/// This will change color of button and not disable it. If timer is running - nothing will happen.
- (void)animateToGrey;

/// This will change color of button and not disable it. If timer is running - nothing will happen
- (void)animateToNormal;

/// @param outerLineWidth width of outer line
/// @param outerLineGap gap between outer line and inner circle
/// @param colorActiveLine color for when timer is ticking
/// @param colorActiveCenter color for center, when timer is ticking
/// @param steps arrays of strings for center label (counter of sorts)
/// @param stepDuration duration of each single step. Do not forget, that there is an additional step "fade in". See it's duration in separate property.
- (void)setupOuterLineWidth:(CGFloat)outerLineWidth
               outerLineGap:(CGFloat)outerLineGap
          colorNormalCenter:(nullable UIColor *)colorNormalCenter
            colorNormalLine:(nullable UIColor *)colorNormalLine
          colorGrayedCenter:(nullable UIColor *)colorGrayedCenter
            colorGrayedLine:(nullable UIColor *)colorGrayedLine
            colorActiveLine:(nullable UIColor *)colorActiveLine
          colorActiveCenter:(nullable UIColor *)colorActiveCenter
                      steps:(nonnull NSArray<NSString *> *)steps
               stepDuration:(NSTimeInterval)stepDuration;

- (void)setLabelFont:(nullable UIFont *)newFont
           textColor:(nullable UIColor *)newTextColor;

@property (nonatomic, assign, readonly) CGFloat outerLineWidth;
@property (nonatomic, assign, readonly) CGFloat outerLineGap;
@property (nonatomic, strong, readonly, nonnull) UIColor *colorNormalLine;
@property (nonatomic, strong, readonly, nonnull) UIColor *colorNormalCenter;
@property (nonatomic, strong, readonly, nonnull) UIColor *colorGrayedLine;
@property (nonatomic, strong, readonly, nonnull) UIColor *colorGrayedCenter;
@property (nonatomic, strong, readonly, nonnull) UIColor *colorActiveLine;
@property (nonatomic, strong, readonly, nonnull) UIColor *colorActiveCenter;
@property (nonatomic, assign, readonly) NSTimeInterval animationStepDuration;
@property (nonatomic, assign, readwrite) NSTimeInterval animationFadeInDuration; // duration of step, that go before any normal steps.

@end
