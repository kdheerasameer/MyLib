Pod::Spec.new do |s|

  s.name         = "MyLib"
  s.version      = "0.0.1"
  s.summary      = "A library for expense reader."

  s.description  = "This is to test the sample pods distribution of lib"
  s.homepage     = "http://www.amadeus.de/"

  s.license      = { :type => 'MIT' }

  s.author             = { "Dheerasameer KOTTAPALLI" => "dheerasameer.kottapalli@amadeus.com" }
  s.platform     = :ios, "5.0"

  s.source       = { :git => "git@github.com:kdheerasameer/MyLib.git", :tag => "#{s.version}" }

  s.source_files  = "ExpenseReaderSDK", "ExpenseReaderSDK/*.h"
  s.public_header_files = "ExpenseReaderSDK/*.h"

  s.preserve_paths = "libExpenseReaderSDK.a"
  s.ios.vendored_libraries  = "libExpenseReaderSDK.a"

  s.framework  = "EventKit", "Accelerate", "CoreMotion", "CoreLocation", "AddressBook"

  s.requires_arc = true

  s.xcconfig = { "OTHER_LDFLAGS" => "-ObjC -lz" }

end
