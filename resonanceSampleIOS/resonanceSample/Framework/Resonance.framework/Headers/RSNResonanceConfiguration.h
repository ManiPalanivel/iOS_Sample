//
//  RSNResonanceConfiguration.h
//  Resonance
//
//  Created by Ruslan on 18.03.16.
//  Copyright © 2016 ADEX INNOVATION. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RSNResonanceConfiguration : NSObject

@property (copy, nonatomic) NSString *registrationServerURL;
@property (copy, nonatomic) NSString *websocketServerURL;
@property (nonatomic) int appID;
@property (copy, nonatomic) NSString *appSecret;

@end
