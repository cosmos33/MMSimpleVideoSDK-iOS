Pod::Spec.new do |s|
  s.name             = 'MMSimpleVideoSDK'
  s.version          = '1.0.0'
  s.summary          = 'MMSimpleVideoSDK'

  s.description      = <<-DESC
  MMSimpleVideoSDK short videos
                       DESC

  s.homepage         = 'https://www.baidu.com/'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'bi.s_fish' => 'sunfeifish@gmail.com' }
  s.source           = { :git => 'https://github.com/cosmos33/MMSimpleVideoSDK-iOS.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'

  s.frameworks = 'AVFoundation', 'CoreVideo', 'CoreMedia', 'CoreAudio', 'AssetsLibrary', 'CoreGraphics', 'Photos'

  s.vendored_frameworks = 'Frameworks/**/*.framework'
  s.pod_target_xcconfig = { 'ENABLE_BITCODE' => '$(inherited) NO', 'OTHER_LDFLAGS' => '$(inherited) -ObjC'}

  s.dependency 'MMMedia', '1.0.0'
  s.dependency 'GPUImage'
  s.dependency 'MetalPetal', '1.1.2'
  
end