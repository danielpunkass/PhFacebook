//
//  WebView+PhFacebook.h
//  PhFacebook
//
//  Created by Jörg Jacobsen on 07.05.13.
//
//

#import <WebKit/WebKit.h>

@interface WebView (PhFacebook)

// Tweaks the original user agent so it pretends to being Safari web browser
// (By appending "Safari" and the webview version)
//
- (void) poseAsSafari;

@end
