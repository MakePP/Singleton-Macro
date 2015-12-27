//
//  main.m
//  SingletonMacro
//
//  Created by pp on 15/12/25.
//  Copyright © 2015 pp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DataStorageTool.h"
#import "NetworkManager.h"

int main(int argc, const char * argv[]) {
    
    @autoreleasepool {
        DataStorageTool *data1 = [DataStorageTool sharedData];
        DataStorageTool *data2 = [[DataStorageTool alloc] init];
        DataStorageTool *data3 = [data2 copy];
        DataStorageTool *data4 = [DataStorageTool new];
        
        NSLog(@"%@ \n %@ \n %@ \n %@", data1, data2, data3, data4);
        
#if !__has_feature(objc_arc)
        NetworkManager *manager1 = [NetworkManager shared];
        NetworkManager *manager2 = [[NetworkManager alloc] init];
        NetworkManager *manager3 = [[[NetworkManager alloc] init] autorelease];
        NetworkManager *manager4 = [manager1 retain];
        
        [manager1 release];
        [manager2 release];
        [manager3 release];
        
        NSLog(@"%ld", [manager4 retainCount]);
        
        NSLog(@"%@ \n %@ \n %@ \n %@", manager1, manager2, manager3, manager4);
#endif
    }
    return 0;
}
