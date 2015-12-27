//
//  SingletonMacro.h
//
//  Created by pp on 15/12/25.
//  Copyright © 2015 pp. All rights reserved.
//

#ifndef SingletonMacro_h
#define SingletonMacro_h

#define SingletonH(name)    + (instancetype)shared##name

#if __has_feature(objc_arc)

    #define SingletonM(name)                            \
                                                        \
    static id instance;                                 \
                                                        \
    + (instancetype)shared##name                        \
    {                                                   \
        static dispatch_once_t onceToken;               \
        dispatch_once(&onceToken, ^{                    \
            instance = [[self alloc] init];             \
        });                                             \
                                                        \
        return instance;                                \
    }                                                   \
                                                        \
    + (instancetype)allocWithZone:(NSZone *)zone        \
    {                                                   \
        static dispatch_once_t onceToken;               \
        dispatch_once(&onceToken, ^{                    \
            instance = [super allocWithZone:zone];      \
        });                                             \
        return instance;                                \
    }                                                   \
                                                        \
    - (id)copyWithZone:(NSZone *)zone                   \
    {                                                   \
        return self;                                    \
    }

#else
    #define SingletonM(name)                            \
                                                        \
    static id instance;                                 \
                                                        \
    + (instancetype)shared##name                        \
    {                                                   \
        static dispatch_once_t onceToken;               \
        dispatch_once(&onceToken, ^{                    \
            instance = [[self alloc] init];             \
        });                                             \
                                                        \
        return instance;                                \
    }                                                   \
                                                        \
    + (instancetype)allocWithZone:(NSZone *)zone        \
    {                                                   \
        static dispatch_once_t onceToken;               \
        dispatch_once(&onceToken, ^{                    \
            instance = [super allocWithZone:zone];      \
        });                                             \
        return instance;                                \
    }                                                   \
                                                        \
    - (id)copyWithZone:(NSZone *)zone                   \
    {                                                   \
        return self;                                    \
    }                                                   \
                                                        \
    - (instancetype)autorelease                         \
    {                                                   \
        return self;                                    \
    }                                                   \
                                                        \
    - (instancetype)retain                              \
    {                                                   \
        return self;                                    \
    }                                                   \
                                                        \
    - (NSUInteger)retainCount                           \
    {                                                   \
        return 1;                                       \
    }                                                   \
                                                        \
    - (oneway void)release                              \
    {                                                   \
                                                        \
    }
#endif

#endif
