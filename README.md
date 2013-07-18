# LHOAuth2LoginViewController

LHOAuth2LoginViewController lets the user do an OAuth2 authentication against a web service without without redirecting the user to Safari.app, but instead using a web view inside a modal view controller.

## Example Usage

``` objective-c
LHOAuth2LoginViewController *vc =
        [[LHOAuth2LoginViewController alloc] initWithBaseURL:@"https://myoauth2server"
                                          authenticationPath:@"/oauth2/authorize/"
                                                    clientID:kOAuthClientID
                                                       scope:@"read+write"
                                                 redirectURL:@"myapp://oauth2"
                                                    delegate:self];
        
// Wrap it in a nav controller to get navigation bar
UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:vc];
navController.modalTransitionStyle = UIModalTransitionStyleCoverVertical;
        
// Present view controller
[self presentViewController:navController animated:YES completion:^() {}];
```

Then implement the delegate method:

``` objective-c
- (void)oAuthViewController:(LHOAuth2LoginViewController *)viewController didSucceedWithCredential:(NSDictionary *)credential {
 
// Add the credentials to your favourite http client
[[MyHTTPClient sharedClient] setAuthorizationHeaderWithToken:[credential objectForKey:@"access_token"]
                                                            ofType:[credential objectForKey:@"token_type"]
                                                           expires:[credential objectForKey:@"expires"]];
    
// Now you can use the client to connect your api

}
```

## Contact

Lari Haataja

- http://github.com/lari
- http://twitter.com/lhaataja
- http://larihaataja.fi

## License

LHOAuth2LoginViewController is available under the MIT license. See the LICENSE file for more info.