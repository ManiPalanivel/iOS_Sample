//
//  RSNClient.h
//  Resonance
//
//  Created by Ruslan on 18.03.16.
//  Copyright © 2016 ADEX INNOVATION. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RSNClient : NSObject
@property (copy, nonatomic, readonly)NSString *payload;

-(instancetype)initWithClientID:(NSString *)clientID
                     andPayload:(NSString *)payload;
@end
