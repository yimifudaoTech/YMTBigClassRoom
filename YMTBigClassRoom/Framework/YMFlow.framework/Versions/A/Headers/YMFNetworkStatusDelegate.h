//
//  YMFNetworkStatusDelegate.h
//  YMFlow
//
//  Created by Yimi on 19/11/28.
//  Copyright © 2019 Yimi. All rights reserved.
//

#ifndef YMFNetworkStatusDelegate_h
#define YMFNetworkStatusDelegate_h

@protocol YMFNetworkStatusDelegate

@required
- (void)ReachabilityChange:(UInt32)uiFlags;

@end

#endif /* YMFNetworkStatusDelegate_h */
