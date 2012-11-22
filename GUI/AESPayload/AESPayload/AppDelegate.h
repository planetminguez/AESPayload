//
//  AppDelegate.h
//  AESPayload
//
//  Created by Dylan Laws on 11/21/12.
//  Copyright (c) 2012 WeAmDev / Haifisch. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>

@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet NSButton *gobutton;
@property (assign) IBOutlet NSTextField *status;
@property (assign) IBOutlet NSTask *task;
- (IBAction)doCommand:(id)sender;
@end
