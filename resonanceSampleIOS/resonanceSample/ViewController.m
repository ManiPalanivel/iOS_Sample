//
//  ViewController.m
//  resonanceSample
//
//  Created by ManiPalanivel on 12/06/18.
//  Copyright © 2018 ManiPalanivel. All rights reserved.
//

#import "ViewController.h"
#import <AVFoundation/AVFoundation.h>
#import <Resonance/Resonance.h>

@interface ViewController (){
    BOOL isSearchable;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    isSearchable = false;
    // Do any additional setup after loading the view, typically from a nib.
}

-(void) viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    [self setupAudioPermission];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) setupAudioPermission{
    AVAudioSessionRecordPermission permissionStatus = [[AVAudioSession sharedInstance] recordPermission];
    if  (permissionStatus == AVAudioSessionRecordPermissionGranted){
        // permission has been granted earlier
        // you can start search
        isSearchable = true;
        [self promptAlert:@"Success" withMessage:@"Now app is ready to search for resonance"];
    }
    else {
        [[AVAudioSession sharedInstance] requestRecordPermission:^(BOOL granted) {
            if (granted) {
                // permission granted
                // you can start search
                self->isSearchable = true;
                [self promptAlert:@"Success" withMessage:@"Now app is ready to search for resonance"];
            }
            else {
                // user denied microphone access
                self->isSearchable = false;
                [self promptAlert:@"User Denied" withMessage:@"Please re-enable the permission"];
            }
        }];
    }
}

-(void) promptAlert: (NSString *)title withMessage:(NSString *)msg{
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:title message:msg preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleCancel handler:nil];
    [alertController addAction:okAction];
    [self presentViewController:alertController animated:YES completion:nil];
}

-(void) startSearching{
    [RSNResonance startSearchingWithPayload: @"ManiPalanivel Phone"
               onSearchStartedBlock: ^(){
                   [self promptAlert:@"Search Started" withMessage:@"Payload as ManiPalanivel Phone"];
                   NSLog(@"Search started");
               }
                 onClientFoundBlock: ^(RSNClient *client){
                     NSLog(@"Nearby found with payload: %@", client.payload);
                     [self promptAlert:@"Client Found" withMessage:[NSString stringWithFormat:@"Nearby found with payload: %@", client.payload]];
                 }
                    onClientLost: ^(RSNClient *client){
                       NSLog(@"Nearby lost with payload: %@", client.payload);
                        [self promptAlert:@"Client Lost" withMessage:[NSString stringWithFormat:@"Nearby lost with payload: %@", client.payload]];
                    }
                       onSearchStoppedBlock: ^(NSError * _Nullable error){
                          NSLog(@"Search stopped with error: %@", error);
                           [self promptAlert:@"Error" withMessage:[NSString stringWithFormat:@"Search stopped"]];
                       }];
}

-(void) stopSearching{
    [RSNResonance stopSearch];
}

- (IBAction)setupAudioButtonTapped:(id)sender {
    [self setupAudioPermission];
}

- (IBAction)startSearchButtonTapped:(id)sender {
    [self startSearching];
    
}
- (IBAction)stopSearchButtonTapped:(id)sender {
    [self stopSearching];
}
@end
