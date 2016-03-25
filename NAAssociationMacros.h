//
//  NAAssociationMacros.h
//  NAFakeWeChat
//
//  Created by zuopengl on 3/17/16.
//  Copyright © 2016 Apple. All rights reserved.
//

#ifndef NAAssociationMacros_h
#define NAAssociationMacros_h
#import <Foundation/Foundation.h>

inline id keyObjectFromDictionaryByValue(NSDictionary *dic, id value) {
    if (value) {
        __block id targetKey = nil;
        [dic enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
            if ([obj isEqual:value]) {
                *stop = YES;
                targetKey = key;
            }
        }];
        return targetKey;
    }
    return nil;
}

// array
#define safeArrayAddObject(array, obj)                 if (obj) { [array addObject:obj]; }
#define safeArrayAddObjects(array, objs)               if ([objs count] > 0) { [array addObjectsFromArray:objs]; } 
#define safeObjectFromArray(array, index)              (index < [array count] ? array[index] : nil)
#define safeSubObjectFromArray(array, index, subIndex) (index < [array count] ? safeArrayObject(array[index], subIndex) : nil)

// dictionary
#define safeDictionaryAddObject(dic, key, value)       if (key && value) { dic[key] = value; }
#define safeValueFromDictionaryByKey(dic, key)         (key ? dic[key] : nil)
#define safeKeyFromDictionaryByValue(dic, value)       keyObjectFromDictionaryByValue(dic, value)

// dictionary->[key, array]
#define safeObjectFromDictionaryArray(dic, key, index) (safeObjectFromArray(safeValueFromDictionaryByKey(dic, key), index))

// array -> dictionary

#endif /* NAAssociationMacros_h */
