#import "enunciate-common.h"

@class ENUNCIATE_SAMPLE_WEBAPPMODELPerson;
@class ENUNCIATE_SAMPLE_WEBAPPMODELName;

#ifndef DEF_ENUNCIATE_SAMPLE_WEBAPPMODELPerson_H
#define DEF_ENUNCIATE_SAMPLE_WEBAPPMODELPerson_H

/**
 *  @author Ryan Heaton
 */
@interface ENUNCIATE_SAMPLE_WEBAPPMODELPerson : NSObject <EnunciateXML>
{
  @private
    NSString *_identifier;
    NSString *_email;
    NSString *_alias;
    ENUNCIATE_SAMPLE_WEBAPPMODELName *_name;
    NSData *_picture;
}

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
- (NSString *) email;

/**
 * (no documentation provided)
 */
- (void) setEmail: (NSString *) newEmail;

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
- (ENUNCIATE_SAMPLE_WEBAPPMODELName *) name;

/**
 * (no documentation provided)
 */
- (void) setName: (ENUNCIATE_SAMPLE_WEBAPPMODELName *) newName;

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
 *  A name of a persona.
 * 
 *  @author Ryan Heaton
 */
@interface ENUNCIATE_SAMPLE_WEBAPPMODELName : NSObject
{
  @private
    NSString *_givenName;
    NSString *_surname;
}

/**
 * The given name.
 */
- (NSString *) givenName;

/**
 * The given name.
 */
- (void) setGivenName: (NSString *) newGivenName;

/**
 * The surname.
 */
- (NSString *) surname;

/**
 * The surname.
 */
- (void) setSurname: (NSString *) newSurname;
@end /* interface ENUNCIATE_SAMPLE_WEBAPPMODELName */

#endif /* DEF_ENUNCIATE_SAMPLE_WEBAPPMODELName_H */
