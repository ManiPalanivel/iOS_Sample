//
//  RSNResonance.h
//  Resonance
//
//  Copyright © 2016 ADEX INNOVATION. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RSNResonance;
@class RSNResonanceConfiguration;
@class RSNClient;

typedef enum
{
    ResonanceErrorMicAccessDenited = 101,
    ResonanceErrorAuthFailed = 102,
    ResonanceErrorConnectionFailed = 103,
    ResonanceErrorApiLimitExceeded = 801,
    ResonanceErrorMaximumSearchTimeExceeded = 802,
    ResonanceErrorUnknow = 1000,
} ResonanceErrorType;


static NSString *_Nonnull const kResonanceWillStartSearchNotification = @"ResonanceWillStartSearchNotification";
static NSString *_Nonnull const kResonanceDidStartSearchNotification = @"ResonanceDidStartSearchNotification";
static NSString *_Nonnull const kResonanceSearchWillStopNotification = @"ResonanceSearchWillStopNotification";
static NSString *_Nonnull const kResonanceSearchStopNotification = @"ResonanceSearchStopNotification";
static NSString *_Nonnull const kResonanceClientFound = @"ResonanceClientFoundNotification";
static NSString *_Nonnull const kResonanceClientLost = @"ResonanceClientLostNotification";
static NSString *_Nonnull const kRSNResonanceNetworkSpeedStatusChanged = @"RSNResonanceNetworkSpeedStatusChanged";

#define RSNRESONANCE_ERROR_DOMAIN @"com.resonance.adexinnovation.ErrorDomain"


@interface RSNResonance : NSObject

@property (copy, nonatomic, readonly) NSString *_Nullable payload;
@property (strong, nonatomic, readonly)NSString *_Nullable clientID;
@property (nonatomic, readonly) BOOL isSearching;

#pragma mark - initialization

+ (instancetype _Nonnull) sharedInstance;

+ (void) setupWithApiKey: (NSString *_Nonnull) apiKey;
+ (void) setupWithCustomConfiguration: (RSNResonanceConfiguration *_Nonnull) configuration;

#pragma mark start search

+ (void) startSearchingWithPayload: (NSString *_Nonnull)payload
              onSearchStartedBlock: (void(^_Nullable)()) onSearchStartedBlock
                onClientFoundBlock: (void(^_Nonnull)(RSNClient *_Nonnull client)) clientFoundBlock
                      onClientLost: (void(^_Nullable)(RSNClient *_Nonnull client)) clientLostBlock
              onSearchStoppedBlock: (void(^_Nonnull)(NSError *_Nullable error)) onSearchStopedBlock;

#pragma mark stop search

+ (void)stopSearch;
+ (void)stopSearchingWithStoppedBlock: (void(^_Nullable)()) opnSearchStopedBlock; //альтернативный блок, не заменяет инициализированный в startSearch
+ (void)disconnect;

@end
