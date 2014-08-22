//
//  PhFacebook.h
//  PhFacebook
//
//  Created by Philippe on 10-08-25.
//  Copyright 2010 Philippe Casgrain. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PhWebViewController;
@class PhAuthenticationToken;

// Block parameter must match -facebook:tokenResult: last parameter
typedef void (^PhTokenRequestCompletionHandler)(NSDictionary *result);

@interface PhFacebook : NSObject <NSCoding>
{
@private
    NSString *_appID;
    id _delegate;
    PhWebViewController *_webViewController;
    PhAuthenticationToken *_authToken;
    NSString *_permissions;
    PhTokenRequestCompletionHandler _tokenRequestCompletionHandler;
    NSError *_loginError;
}

// The Completion handler to be invoked when web view will be closed
@property (copy) PhTokenRequestCompletionHandler tokenRequestCompletionHandler;

// Any error that has been encountered attempting to login
@property (retain) NSError *loginError;

- (id) initWithApplicationID: (NSString*) appID delegate: (id) delegate;

// permissions: an array of required permissions
//              see http://developers.facebook.com/docs/authentication/permissions
// canCache: save and retrieve token locally if not expired
- (void) getAccessTokenForPermissions:(NSArray *)permissions
                               cached:(BOOL)canCache
                       relativeToRect:(NSRect)rect
                               ofView:(NSView *)view
                           completion:(PhTokenRequestCompletionHandler)completion;

- (void) setAccessToken: (NSString*) accessToken expires: (NSTimeInterval) tokenExpires permissions: (NSString*) perms;

// request: the short version of the Facebook Graph API, e.g. "me/feed"
// see http://developers.facebook.com/docs/api
- (void) sendRequest: (NSString*) request;
- (NSDictionary *)sendSynchronousRequest:(NSString *)request HTTPMethod:(NSString *)method params:(NSDictionary *)params;

// Method is GET
- (NSDictionary *)sendSynchronousRequest:(NSString *)request params:(NSDictionary *)params;
- (NSDictionary *)sendSynchronousRequest:(NSString *)request;

// query: the query to send to FQL API, e.g. "SELECT uid, sex, name from user WHERE uid = me()"
// see http://developers.facebook.com/docs/reference/fql/
- (void) sendFQLRequest: (NSString*) query;

/**
 Sends an FQL query synchronously
 
 @returns Dictionary containing the following keys: request (string), sender, result (as string), resultDict, raw (raw result data), Error
 */
- (NSDictionary *)sendSynchronousFQLRequest:(NSString *)query;

- (void) invalidateCachedToken;

- (id) delegate;
- (void) setDelegate:(id)delegate;

// To be called when web view is done (either with or without having successfully logged in).
// Will call completion handler that was provided earlier
- (void) completeTokenRequestWithError:(NSError *)error;
- (NSString*) accessToken;

- (void) webViewWillShowUI;
- (void) didDismissUI;
@end

@protocol PhFacebookDelegate

@required
- (void) requestResult: (NSDictionary*) result;

@optional
// needsAuthentication is called before showing the authentication WebView.
// If it returns YES, the default login window will not be shown and
// your application is responsible for the authentication UI.
- (BOOL) needsAuthentication: (NSString*) authenticationURL forPermissions: (NSString*) permissions; 
- (void) willShowUINotification: (PhFacebook*) sender;
- (void) didDismissUI: (PhFacebook*) sender;
@end
