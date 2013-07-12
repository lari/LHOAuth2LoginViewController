// LHOAuth2LoginViewController.h
//
// Copyright (c) 2013 Lari Haataja (http://larihaataja.fi)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <UIKit/UIKit.h>

@class LHOAuth2LoginViewController;

@protocol LHOAuth2LoginViewControllerDelegate <NSObject>

@optional
- (void)oAuthViewController:(LHOAuth2LoginViewController *)viewController didSucceedWithCredential:(NSDictionary *)credential;
- (void)oAuthViewController:(LHOAuth2LoginViewController *)viewController didFailWithError:(NSError *)error;

@end

@interface LHOAuth2LoginViewController : UIViewController <UIWebViewDelegate>

@property (nonatomic,assign) id<LHOAuth2LoginViewControllerDelegate> delegate;

/**
 Init view controller
 
 @param baseURL         the api's base url (e.g. https://googleapis.com/ )
 @param authPath        path for authorization request
 @param clientID        OAuth2 client id
 @param scope           Requested scope (e.g. "read" or "read+write")
 @param redirectURL     url where the user is redirected after authorization
*/
- (id)initWithBaseURL:(NSString *)baseURL
   authenticationPath:(NSString *)authPath
             clientID:(NSString *)clientID
                scope:(NSString *)scope
          redirectURL:(NSString *)redirectURL
             delegate:(id<LHOAuth2LoginViewControllerDelegate>)delegate;

/*
 * Load the authorization page
 */
- (void)authorize;

@end



