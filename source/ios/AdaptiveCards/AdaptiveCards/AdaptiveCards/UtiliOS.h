//
//  UtiliOS
//
//  Copyfight © 2019 Microsoft. All rights reserved.
//

#import "ACRErrors.h"
#import "ACRSeparator.h"
#import "ACRViewPrivate.h"
#import "BaseCardElement.h"
#import "CollectionTypeElement.h"
#import "RichTextElementProperties.h"
#import "TextBlock.h"
#import "TextRun.h"
#import <UIKit/UIKit.h>

using namespace AdaptiveCards;

void configVisibility(UIView *view, std::shared_ptr<BaseCardElement> const &visibilityInfo);

void configSeparatorVisibility(ACRSeparator *view,
                               std::shared_ptr<BaseCardElement> const &visibilityInfo);

void configBleed(ACRView *rootView, std::shared_ptr<BaseCardElement> const &elem,
                 ACRContentStackView *container, ACOHostConfig *acoConfig);

void renderBackgroundImage(const std::shared_ptr<BackgroundImage> backgroundImageProperties,
                           UIView *containerView, ACRView *rootView);

void renderBackgroundImage(const BackgroundImage *backgroundImageProperties, UIImageView *imageView,
                           UIImage *img);

void applyBackgroundImageConstraints(const BackgroundImage *backgroundImageProperties,
                                     UIImageView *imageView, UIImage *img);

ObserverActionBlock generateBackgroundImageObserverAction(
    std::shared_ptr<BackgroundImage> backgroundImageProperties, ACRView *observer,
    std::shared_ptr<BaseCardElement> const &context);

UIFontDescriptor *getItalicFontDescriptor(UIFontDescriptor *descriptor, bool isItalic);

void handleFallbackException(ACOFallbackException *exception, UIView<ACRIContentHoldingView> *view,
                             ACRView *rootView, NSMutableArray *inputs,
                             std::shared_ptr<BaseCardElement> const &elem, ACOHostConfig *config);
void handleActionFallbackException(ACOFallbackException *exception,
                                   UIView<ACRIContentHoldingView> *view, ACRView *rootView,
                                   NSMutableArray *inputs, ACOBaseActionElement *acoElem,
                                   ACOHostConfig *config,
                                   UIView<ACRIContentHoldingView> *actionSet);

void removeLastViewFromCollectionView(const CardElementType elemType,
                                      UIView<ACRIContentHoldingView> *view);

ACRRenderingStatus buildTargetForButton(ACRTargetBuilderDirector *director,
                                        std::shared_ptr<BaseActionElement> const &action,
                                        UIButton *button, NSObject **target);

ACRRenderingStatus buildTarget(ACRTargetBuilderDirector *director,
                               std::shared_ptr<BaseActionElement> const &action, NSObject **target);

void TextBlockToRichTextElementProperties(const std::shared_ptr<TextBlock> &textBlock, RichTextElementProperties &textProp);

void TextRunToRichTextElementProperties(const std::shared_ptr<TextRun> &textRun, RichTextElementProperties &textProp);

void buildIntermediateResultForText(ACRView *rootView, ACOHostConfig *hostConfig, RichTextElementProperties const &textProperties, NSString *elementId);
