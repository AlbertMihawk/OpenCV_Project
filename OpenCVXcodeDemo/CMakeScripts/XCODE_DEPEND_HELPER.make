# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.OpenCVDemo.Debug:
/Users/xiaoxu/Documents/code_develop/OpenCVMacDemo/Debug/OpenCVDemo:\
	/usr/local/lib/libopencv_highgui.4.1.1.dylib\
	/usr/local/lib/libopencv_video.4.1.1.dylib\
	/usr/local/lib/libopencv_videoio.4.1.1.dylib\
	/usr/local/lib/libopencv_imgcodecs.4.1.1.dylib\
	/usr/local/lib/libopencv_calib3d.4.1.1.dylib\
	/usr/local/lib/libopencv_features2d.4.1.1.dylib\
	/usr/local/lib/libopencv_imgproc.4.1.1.dylib\
	/usr/local/lib/libopencv_flann.4.1.1.dylib\
	/usr/local/lib/libopencv_core.4.1.1.dylib
	/bin/rm -f /Users/xiaoxu/Documents/code_develop/OpenCVMacDemo/Debug/OpenCVDemo


PostBuild.OpenCVDemo.Release:
/Users/xiaoxu/Documents/code_develop/OpenCVMacDemo/Release/OpenCVDemo:\
	/usr/local/lib/libopencv_highgui.4.1.1.dylib\
	/usr/local/lib/libopencv_video.4.1.1.dylib\
	/usr/local/lib/libopencv_videoio.4.1.1.dylib\
	/usr/local/lib/libopencv_imgcodecs.4.1.1.dylib\
	/usr/local/lib/libopencv_calib3d.4.1.1.dylib\
	/usr/local/lib/libopencv_features2d.4.1.1.dylib\
	/usr/local/lib/libopencv_imgproc.4.1.1.dylib\
	/usr/local/lib/libopencv_flann.4.1.1.dylib\
	/usr/local/lib/libopencv_core.4.1.1.dylib
	/bin/rm -f /Users/xiaoxu/Documents/code_develop/OpenCVMacDemo/Release/OpenCVDemo


PostBuild.OpenCVDemo.MinSizeRel:
/Users/xiaoxu/Documents/code_develop/OpenCVMacDemo/MinSizeRel/OpenCVDemo:\
	/usr/local/lib/libopencv_highgui.4.1.1.dylib\
	/usr/local/lib/libopencv_video.4.1.1.dylib\
	/usr/local/lib/libopencv_videoio.4.1.1.dylib\
	/usr/local/lib/libopencv_imgcodecs.4.1.1.dylib\
	/usr/local/lib/libopencv_calib3d.4.1.1.dylib\
	/usr/local/lib/libopencv_features2d.4.1.1.dylib\
	/usr/local/lib/libopencv_imgproc.4.1.1.dylib\
	/usr/local/lib/libopencv_flann.4.1.1.dylib\
	/usr/local/lib/libopencv_core.4.1.1.dylib
	/bin/rm -f /Users/xiaoxu/Documents/code_develop/OpenCVMacDemo/MinSizeRel/OpenCVDemo


PostBuild.OpenCVDemo.RelWithDebInfo:
/Users/xiaoxu/Documents/code_develop/OpenCVMacDemo/RelWithDebInfo/OpenCVDemo:\
	/usr/local/lib/libopencv_highgui.4.1.1.dylib\
	/usr/local/lib/libopencv_video.4.1.1.dylib\
	/usr/local/lib/libopencv_videoio.4.1.1.dylib\
	/usr/local/lib/libopencv_imgcodecs.4.1.1.dylib\
	/usr/local/lib/libopencv_calib3d.4.1.1.dylib\
	/usr/local/lib/libopencv_features2d.4.1.1.dylib\
	/usr/local/lib/libopencv_imgproc.4.1.1.dylib\
	/usr/local/lib/libopencv_flann.4.1.1.dylib\
	/usr/local/lib/libopencv_core.4.1.1.dylib
	/bin/rm -f /Users/xiaoxu/Documents/code_develop/OpenCVMacDemo/RelWithDebInfo/OpenCVDemo




# For each target create a dummy ruleso the target does not have to exist
/usr/local/lib/libopencv_calib3d.4.1.1.dylib:
/usr/local/lib/libopencv_core.4.1.1.dylib:
/usr/local/lib/libopencv_features2d.4.1.1.dylib:
/usr/local/lib/libopencv_flann.4.1.1.dylib:
/usr/local/lib/libopencv_highgui.4.1.1.dylib:
/usr/local/lib/libopencv_imgcodecs.4.1.1.dylib:
/usr/local/lib/libopencv_imgproc.4.1.1.dylib:
/usr/local/lib/libopencv_video.4.1.1.dylib:
/usr/local/lib/libopencv_videoio.4.1.1.dylib:
