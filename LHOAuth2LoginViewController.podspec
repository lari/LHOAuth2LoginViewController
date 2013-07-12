Pod::Spec.new do |s|
  s.name     = 'LHOAuth2LoginViewController'
  s.version  = '0.1'
  s.license  = 'MIT'
  s.summary  = 'A modal view controller to handle OAuth2 login without needing to redirect the user to Safari.app'
  s.homepage = 'https://github.com/lari/LHOAuth2LoginViewController'
  s.author   = { 'Lari Haataja' => 'lari.haataja@gmail.com' }
  s.source   = { :git => 'https://github.com/lari/LHOAuth2LoginViewController.git',
                 :tag => '0.1' }
  s.source_files = 'LHOAuth2LoginViewController'
  s.requires_arc = true
end
