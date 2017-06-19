//
//  PhFacebook_URLs.h
//  PhFacebook
//
//  URLs used by the Facebook Graph API
//
//  Created by Philippe on 10-08-28.
//  Copyright 2010 Philippe Casgrain. All rights reserved.
//

#define GRAPH_API_VERSION "v2.9"        // Supported until July 2019

#define kFBAuthorizeURL @"https://graph.facebook.com/" GRAPH_API_VERSION "/oauth/authorize?client_id=%@&redirect_uri=%@&type=user_agent&display=popup"

#define kFBAuthorizeWithScopeURL @"https://graph.facebook.com/" GRAPH_API_VERSION "/oauth/authorize?client_id=%@&redirect_uri=%@&scope=%@&type=user_agent&display=popup"

#define kFBLoginSuccessURL @"https://www.facebook.com/connect/login_success.html"

#define kFBUIServerURL @"http://www.facebook.com/connect/uiserver.php"

#define kFBAccessToken @"access_token="
#define kFBExpiresIn   @"expires_in="
#define kFBErrorReason @"error_description="

#define kFBGraphApiGetURL @"https://graph.facebook.com/" GRAPH_API_VERSION "/%@?access_token=%@"
#define kFBGraphApiGetURLWithParams @"https://graph.facebook.com/" GRAPH_API_VERSION "/%@&access_token=%@"

#define kFBGraphApiPostURL @"https://graph.facebook.com/" GRAPH_API_VERSION "/%@"

#define kFBGraphApiFqlURL @"https://api.facebook.com/method/fql.query?query=%@&access_token=%@&format=json"

#define kFBURL @"http://facebook.com"
#define kFBSecureURL @"https://facebook.com"
