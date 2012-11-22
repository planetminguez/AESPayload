//
//  AppDelegate.m
//  AESPayload
//
//  Created by Dylan Laws on 11/21/12.
//  Copyright (c) 2012 WeAmDev / Haifisch. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate
@synthesize gobutton, status, task;
- (void)dealloc
{
    [super dealloc];
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application
}
- (IBAction)doCommand:(id)sender
{

    NSString *execPath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:@"AESPayload"];
    [gobutton setEnabled:NO];
    task = [[NSTask alloc] init];
    [task setArguments:[NSArray arrayWithObject:@"-go"]];
    [task setLaunchPath: execPath];
    [task launch];
    [task waitUntilExit];
    [task release];
    [status setStringValue:@"DONE; Should see blue screen, If not try again."];
    
}
@end
