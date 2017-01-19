//
//  PhWebViewController.h
//  PhFacebook
//
//  Created by Philippe on 10-08-27.
//  Copyright 2010 Philippe Casgrain. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>


@class PhFacebook;

@interface PhWebViewController : NSViewController <NSWindowDelegate, NSFileManagerDelegate, WebEditingDelegate, NSPopoverDelegate>
{
    IBOutlet NSWindow *window;
    IBOutlet WebView *webView;
    NSUndoManager *_undoManager;
    IBOutlet NSProgressIndicator *progressIndicator;
    NSPopover *_popover;
    IBOutlet NSButton *cancelButton;

    PhFacebook *parent;
    NSString *permissions;
    
    // View positioning (only when using NSPopover for login)
    NSRect _relativeToRect;
    NSView *_rectParentView;
}

@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet WebView *webView;
@property (assign) IBOutlet NSButton *cancelButton;
@property (assign) IBOutlet NSProgressIndicator *progressIndicator;
@property (assign) PhFacebook *parent;
@property (nonatomic, retain) NSString *permissions;

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;
- (void) setRelativeToRect:(NSRect)relativeToRect ofView:(NSView *)view;
- (IBAction) cancel: (id) sender;

@end
