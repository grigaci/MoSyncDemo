//
//  ViewController.mm
//  iOSDemo
//
//  Created by Bogdan Iusco on 6/4/13.
//
//

#import "NativeScreen.h"

@implementation NativeScreen

@synthesize delegate;

-(IBAction)btnClicked:(id)sender {

	[self.delegate showMoSyncScreen];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end