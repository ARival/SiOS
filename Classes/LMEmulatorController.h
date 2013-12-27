//
//  LMViewController.h
//  SiOS
//
//  Created by Lucas Menge on 1/2/12.
//  Copyright (c) 2012 Lucas Menge. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "../SNES9XBridge/SIScreenDelegate.h"

@class GCController;
@class GCExtendedGamepad;
@class LMEmulatorControllerView;

@interface LMEmulatorController : UIViewController
{
  LMEmulatorControllerView* _customView;
  
  UIActionSheet* _actionSheet;
  
  volatile NSThread* _emulationThread;
  
  NSString* _romFileName;
  NSString* _initialSaveFileName;
  
  // handling external screens
  BOOL _isMirror;
  UIWindow* _externalWindow;
  LMEmulatorController* _externalEmulator;
}

@property (copy) NSString* romFileName;
@property (copy) NSString* initialSaveFileName;
@property (strong) GCController* myController;
@property (strong) GCExtendedGamepad *profile;

- (void)startWithROM:(NSString*)romFileName;

- (id)initMirrorOf:(LMEmulatorController*)mainController;

@end
