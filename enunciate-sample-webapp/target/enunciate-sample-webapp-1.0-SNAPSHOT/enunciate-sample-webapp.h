#import "enunciate-common.h"

@class ENUNCIATE_SAMPLE_WEBAPPMODELPerson;
@class ENUNCIATE_SAMPLE_WEBAPPMODELName;

#ifndef DEF_ENUNCIATE_SAMPLE_WEBAPPMODELPerson_H
#define DEF_ENUNCIATE_SAMPLE_WEBAPPMODELPerson_H

/**
 * (no documentation provided)
 */
@interface ENUNCIATE_SAMPLE_WEBAPPMODELPerson : NSObject <EnunciateXML>
{
  @private
    ENUNCIATE_SAMPLE_WEBAPPMODELName *_name;
    NSString *_email;
    NSString *_identifier;
    NSString *_alias;
    NSData *_picture;
}

/**
 * (no documentation provided)
 */
- (ENUNCIATE_SAMPLE_WEBAPPMODELName *) name;

/**
 * (no documentation provided)
 */
- (void) setName: (ENUNCIATE_SAMPLE_WEBAPPMODELName *) newName;

/**
 * (no documentation provided)
 */
- (NSString *) email;

/**
 * (no documentation provided)
 */
- (void) setEmail: (NSString *) newEmail;

/**
 * (no documentation provided)
 */
- (NSString *) identifier;

/**
 * (no documentation provided)
 */
- (void) setIdentifier: (NSString *) newIdentifier;

/**
 * (no documentation provided)
 */
- (NSString *) alias;

/**
 * (no documentation provided)
 */
- (void) setAlias: (NSString *) newAlias;

/**
 * (no documentation provided)
 */
- (NSData *) picture;

/**
 * (no documentation provided)
 */
- (void) setPicture: (NSData *) newPicture;
@end /* interface ENUNCIATE_SAMPLE_WEBAPPMODELPerson */

#endif /* DEF_ENUNCIATE_SAMPLE_WEBAPPMODELPerson_H */
#ifndef DEF_ENUNCIATE_SAMPLE_WEBAPPMODELName_H
#define DEF_ENUNCIATE_SAMPLE_WEBAPPMODELName_H

/**
 * (no documentation provided)
 */
@interface ENUNCIATE_SAMPLE_WEBAPPMODELName : NSObject
{
  @private
    NSString *_givenName;
    NSString *_fullName;
    NSString *_surname;
}

/**
 * (no documentation provided)
 */
- (NSString *) givenName;

/**
 * (no documentation provided)
 */
- (void) setGivenName: (NSString *) newGivenName;

/**
 * (no documentation provided)
 */
- (NSString *) fullName;

/**
 * (no documentation provided)
 */
- (void) setFullName: (NSString *) newFullName;

/**
 * (no documentation provided)
 */
- (NSString *) surname;

/**
 * (no documentation provided)
 */
- (void) setSurname: (NSString *) newSurname;
@end /* interface ENUNCIATE_SAMPLE_WEBAPPMODELName */

#endif /* DEF_ENUNCIATE_SAMPLE_WEBAPPMODELName_H */
