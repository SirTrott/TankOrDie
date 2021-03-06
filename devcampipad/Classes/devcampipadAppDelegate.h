//
//  devcampipadAppDelegate.h
//  devcampipad
//
//  Created by Brad Smith on 4/16/10.
//  Copyright Clixtr 2010. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GameKit/GameKit.h>
#import "ClientModeSessionHandler.h"
#import "SlaveBoard.h"


@class PlayerView;
@class Bullet;


@interface devcampipadAppDelegate : NSObject <UIApplicationDelegate, GKPeerPickerControllerDelegate, GKSessionDelegate> {
	IBOutlet UILabel *peerCountLabel;
	IBOutlet UILabel *boardCountLabel;
	IBOutlet UIButton *newButton;
	IBOutlet UIButton *stopButton;
	
	UIImageView *defaultView;
	UIImageView *loadingView;
	NSString *serverPeerID;
	GKPeerPickerController *peerPicker;
	NSMutableDictionary *connectedPeers;
	NSMutableDictionary *connectedBoards;
	SlaveBoard *lastBoard;
	UIWindow *window;
	
	GKSession *service;
	GKSession *client;
	
	ClientModeSessionHandler *clientModeSessionHandler;
	NSMutableArray *bullets;
	NSDate *lastTicked;
	BOOL actingAsServer;
}


-(IBAction) joinButtonPressed:(id)sender;
-(IBAction) newButtonPressed:(id)sender;
-(IBAction) stopButtonPressed:(id)sender;
-(void) requestConnectingClientIdentity:(NSString *)thePeerId;
-(void)player:(PlayerView *)thePlayer didFire:(Bullet *)theBullet;
-(void)confirmiPad:(NSString *)peerId;
- (void) spawnPortal:(NSString *)args;
- (void) relocatePlayer:(PlayerView *)ply inDir:(int)dir;
- (void) updateLabels;
-(void) confirmiPhone:(NSString *)peerID withTankID:(NSString *)tankID;
- (void) spawnPlayer:(NSString *)args;
-(void)sendID:(NSString *)serverPeerID;


@property (nonatomic, retain) NSString *serverPeerID;
@property (nonatomic, retain) IBOutlet UIWindow *window;

@property (nonatomic, retain) GKSession *service;
@property (nonatomic, retain) GKSession *client;

@property (nonatomic, retain) NSMutableArray *bullets;
@property (nonatomic, retain) NSDate *lastTicked;


@end  