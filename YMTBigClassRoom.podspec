#
# Be sure to run `pod lib lint YMTBigClassRoom.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'YMTBigClassRoom'
  s.version          = '0.1.9'
  s.summary          = 'YMT BigClass Room.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = '溢米辅导 大班课 SDK'

  s.homepage         = 'http://gerrit.ymfd.corp/#/admin/projects/ios-BigClass'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'zhangqian' => 'qian.zhang@yimifudao.com' }
  s.source           = { :git => 'ssh://zhangqian@gerrit.ymfd.corp:29418/ios-BigClass', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'

  s.resources = "YMTBigClassRoom/Framework/YMTBigClassRoom.framework/Versions/A/Resources/**"
  s.vendored_frameworks = "YMTBigClassRoom/Framework/YMTBigClassRoom.framework"
  s.public_header_files = 'YMTBigClassRoom/Framework/YMTBigClassRoom.framework/**/*.h'
  
  s.static_framework = true
   
  # s.resource_bundles = {
  #   'YMTBigClassRoom' => ['YMTBigClassRoom/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
  
  s.dependency 'YMTCloudClassroom'
  s.dependency 'YYModel'
  s.dependency 'AFNetworking'
  s.dependency 'Masonry'
  s.dependency 'YYCache'
  s.dependency 'ZFPlayer', '2.1.3'
  s.dependency 'SDWebImage'
  
  s.user_target_xcconfig = { 
    'ARCHS[sdk=iphonesimulator*]' => '$(ARCHS_STANDARD_64_BIT)',
    'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/YMTCloudClassroom/YMTCloudClassroom/YMTCloudClassroom.framework/Headers/',
    'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES'
  }

end
