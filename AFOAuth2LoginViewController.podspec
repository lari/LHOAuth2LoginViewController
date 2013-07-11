Pod::Spec.new do |s|
  s.name     = 'AFOAuth2LoginViewController'
  s.version  = '0.1'
  s.license  = 'MIT'
  s.summary  = 'AFNetworking / OAuth2Client Extension for a modal view controller.'
  s.homepage = 'https://github.com/lari/AFOAuth2LoginViewController'
  s.author   = { 'Lari Haataja' => 'lari.haataja@gmail.com' }
  s.source   = { :git => 'https://github.com/lari/AFOAuth2LoginViewController.git',
                 :tag => '0.1' }
  s.source_files = 'AFOAuth2LoginViewController'
  s.requires_arc = true

  s.dependency 'AFOAuth2Client', '~>0.1.1'
end
