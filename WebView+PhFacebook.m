//
//  WebView+PhFacebook.m
//  PhFacebook
//
//  Created by Jörg Jacobsen on 07.05.13.
//
//

#import "WebView+PhFacebook.h"

@implementation WebView (PhFacebook)

// Tweaks the original user agent so it pretends to being Safari web browser
// (By appending "Safari" and the webview version)
//
- (void) poseAsSafari
{
    // Safari user agent string looks like this (version numbers may vary):
    // @"Mozilla/5.0 (Macintosh; Intel Mac OS X) AppleWebKit/536.29.13 (KHTML, like Gecko) Version/6.0.4 Safari/536.29.13"
    
    NSString *webViewUserAgent = [self userAgentForURL:[NSURL URLWithString:@"http://www.apple.com"]];
    
    NSScanner *userAgentScanner = [NSScanner scannerWithString:webViewUserAgent];
    NSString *scanResult = nil;
    [userAgentScanner scanUpToString:@"AppleWebKit" intoString:&scanResult];
    [userAgentScanner scanString:@"AppleWebKit" intoString:&scanResult];
    NSString *match = nil;
    [userAgentScanner scanCharactersFromSet:[NSCharacterSet characterSetWithCharactersInString:@"/0123456789."] intoString:&match];
    
    /* No NSRegularExpression in 10.6
     
    NSString *pattern = @"(/[0-9]+\\.[0-9]+\\.[0-9]+)";         // E.g. "/536.28.10"
    NSRegularExpressionOptions options = 0;
    NSError *error = NULL;
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:pattern options:options error:&error];
    if (!regex) {
        NSString *errMsg = [NSString stringWithFormat:@"Unable to compile regular expression from pattern '%@' due to: %@", pattern, [error localizedFailureReason]];
        NSLog(@"%@", errMsg);
        [[NSException exceptionWithName:@"PhProgrammerError" reason:errMsg userInfo:nil] raise];
    }
    void (^captureMatch)(NSTextCheckingResult* result, NSMatchingFlags flags, BOOL *stop) = ^(NSTextCheckingResult* result, NSMatchingFlags flags, BOOL *stop) {
        match = [webViewUserAgent substringWithRange:result.range];
    };
    NSRange range = NSMakeRange(0, [webViewUserAgent length]);
    [regex enumerateMatchesInString:webViewUserAgent options:options range:range usingBlock:captureMatch];   // Should only match once

    */
    
    [self setCustomUserAgent:[NSString stringWithFormat:@"%@ Safari%@", webViewUserAgent, match]];

    NSLog(@"HTTP User Agent posing as Safari: %@", [self customUserAgent]);
    
}


@end
