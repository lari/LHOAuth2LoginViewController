# LHOAuth2LoginViewController

LHOAuth2LoginViewController lets the user do an OAuth2 authentication against a web service without without redirecting the user to Safari.app, but instead using a web view inside a modal view controller.

## Example Usage

``` objective-c
LHOAuth2LoginViewController *vc =
        [[LHOAuth2LoginViewController alloc] initWithBaseURL:@"http://localhost:8001"
                                          authenticationPath:@"/api/oauth2/authorize/"
                                                    clientID:kOAuthClientID
                                                       scope:@"read+write"
                                                 redirectURL:@"http://com.holvi/oauth"
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
    
    [[HolviApiClient sharedClient] setAuthorizationHeaderWithToken:[credential objectForKey:@"access_token"]
                                                            ofType:[credential objectForKey:@"token_type"]
                                                           expires:[credential objectForKey:@"expires"]];
    
    [[HolviApiClient sharedClient] getPath:@"/logout" parameters:nil success:^(AFHTTPRequestOperation *opreation, NSError *error) {
        
        [self performSegueWithIdentifier:@"loggedIn" sender:self];
    } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
    
    }];

}
```

## Contact

Lari Haataja

- http://github.com/lari
- http://twitter.com/lhaataja
- http://larihaataja.fi

## License

LHOAuth2LoginViewController is available under the MIT license. See the LICENSE file for more info.