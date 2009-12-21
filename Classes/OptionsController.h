#import <UIKit/UIKit.h>


@interface OptionsController : UIViewController 
{
	IBOutlet UISegmentedControl*	segmentedSkin;
	IBOutlet UISwitch*				switchScaling;
	IBOutlet UISwitch*				switchAutosave;
	IBOutlet UISwitch*				switchSmoothScaling;
	IBOutlet UISwitch*				switchFramerate;
	IBOutlet UISwitch*				switchWiiMote;
	NSMutableArray*					optionsArray;
}

- (void)optionChanged:(id)sender;
- (NSString*)getDocumentsDirectory;
- (void)getOptions;
- (int)getCurrentSkin;
- (int)getCurrentScaling;
- (int)getCurrentSmoothScaling;

@end
