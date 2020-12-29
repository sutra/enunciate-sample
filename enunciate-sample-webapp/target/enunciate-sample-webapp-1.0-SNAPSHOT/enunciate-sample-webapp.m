#import "enunciate-sample-webapp.h"
#ifndef DEF_ENUNCIATE_SAMPLE_WEBAPPMODELPerson_M
#define DEF_ENUNCIATE_SAMPLE_WEBAPPMODELPerson_M

/**
 *  @author Ryan Heaton
 */
@implementation ENUNCIATE_SAMPLE_WEBAPPMODELPerson

/**
 * (no documentation provided)
 */
- (NSString *) identifier
{
  return _identifier;
}

/**
 * (no documentation provided)
 */
- (void) setIdentifier: (NSString *) newIdentifier
{
  [newIdentifier retain];
  [_identifier release];
  _identifier = newIdentifier;
}

/**
 * (no documentation provided)
 */
- (NSString *) email
{
  return _email;
}

/**
 * (no documentation provided)
 */
- (void) setEmail: (NSString *) newEmail
{
  [newEmail retain];
  [_email release];
  _email = newEmail;
}

/**
 * (no documentation provided)
 */
- (NSString *) alias
{
  return _alias;
}

/**
 * (no documentation provided)
 */
- (void) setAlias: (NSString *) newAlias
{
  [newAlias retain];
  [_alias release];
  _alias = newAlias;
}

/**
 * (no documentation provided)
 */
- (ENUNCIATE_SAMPLE_WEBAPPMODELName *) name
{
  return _name;
}

/**
 * (no documentation provided)
 */
- (void) setName: (ENUNCIATE_SAMPLE_WEBAPPMODELName *) newName
{
  [newName retain];
  [_name release];
  _name = newName;
}

/**
 * (no documentation provided)
 */
- (NSData *) picture
{
  return _picture;
}

/**
 * (no documentation provided)
 */
- (void) setPicture: (NSData *) newPicture
{
  [newPicture retain];
  [_picture release];
  _picture = newPicture;
}

- (void) dealloc
{
  [self setIdentifier: nil];
  [self setEmail: nil];
  [self setAlias: nil];
  [self setName: nil];
  [self setPicture: nil];
  [super dealloc];
}

//documentation inherited.
+ (id<EnunciateXML>) readFromXML: (NSData *) xml
{
  ENUNCIATE_SAMPLE_WEBAPPMODELPerson *_eNUNCIATE_SAMPLE_WEBAPPMODELPerson;
  xmlTextReaderPtr reader = xmlReaderForMemory([xml bytes], [xml length], NULL, NULL, 0);
  if (reader == NULL) {
    [NSException raise: @"XMLReadError"
                 format: @"Error instantiating an XML reader."];
    return nil;
  }

  _eNUNCIATE_SAMPLE_WEBAPPMODELPerson = (ENUNCIATE_SAMPLE_WEBAPPMODELPerson *) [ENUNCIATE_SAMPLE_WEBAPPMODELPerson readXMLElement: reader];
  xmlFreeTextReader(reader); //free the reader
  return _eNUNCIATE_SAMPLE_WEBAPPMODELPerson;
}

//documentation inherited.
- (NSData *) writeToXML
{
  xmlBufferPtr buf;
  xmlTextWriterPtr writer;
  int rc;
  NSData *data;

  buf = xmlBufferCreate();
  if (buf == NULL) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML buffer."];
    return nil;
  }

  writer = xmlNewTextWriterMemory(buf, 0);
  if (writer == NULL) {
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error creating an XML writer."];
    return nil;
  }

  rc = xmlTextWriterStartDocument(writer, NULL, "utf-8", NULL);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML start document."];
    return nil;
  }

  NS_DURING
  {
    [self writeXMLElement: writer];
  }
  NS_HANDLER
  {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [localException raise];
  }
  NS_ENDHANDLER

  rc = xmlTextWriterEndDocument(writer);
  if (rc < 0) {
    xmlFreeTextWriter(writer);
    xmlBufferFree(buf);
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing XML end document."];
    return nil;
  }

  xmlFreeTextWriter(writer);
  data = [NSData dataWithBytes: buf->content length: buf->use];
  xmlBufferFree(buf);
  return data;
}
@end /* implementation ENUNCIATE_SAMPLE_WEBAPPMODELPerson */

/**
 * Internal, private interface for JAXB reading and writing.
 */
@interface ENUNCIATE_SAMPLE_WEBAPPMODELPerson (JAXB) <JAXBReading, JAXBWriting, JAXBType, JAXBElement>

@end /*interface ENUNCIATE_SAMPLE_WEBAPPMODELPerson (JAXB)*/

/**
 * Internal, private implementation for JAXB reading and writing.
 */
@implementation ENUNCIATE_SAMPLE_WEBAPPMODELPerson (JAXB)

/**
 * Read an instance of ENUNCIATE_SAMPLE_WEBAPPMODELPerson from an XML reader.
 *
 * @param reader The reader.
 * @return An instance of ENUNCIATE_SAMPLE_WEBAPPMODELPerson defined by the XML reader.
 */
+ (id<JAXBType>) readXMLType: (xmlTextReaderPtr) reader
{
  ENUNCIATE_SAMPLE_WEBAPPMODELPerson *_eNUNCIATE_SAMPLE_WEBAPPMODELPerson = [[ENUNCIATE_SAMPLE_WEBAPPMODELPerson alloc] init];
  NS_DURING
  {
    [_eNUNCIATE_SAMPLE_WEBAPPMODELPerson initWithReader: reader];
  }
  NS_HANDLER
  {
    _eNUNCIATE_SAMPLE_WEBAPPMODELPerson = nil;
    [localException raise];
  }
  NS_ENDHANDLER

  [_eNUNCIATE_SAMPLE_WEBAPPMODELPerson autorelease];
  return _eNUNCIATE_SAMPLE_WEBAPPMODELPerson;
}

/**
 * Initialize this instance of ENUNCIATE_SAMPLE_WEBAPPMODELPerson according to
 * the XML being read from the reader.
 *
 * @param reader The reader.
 */
- (id) initWithReader: (xmlTextReaderPtr) reader
{
  return [super initWithReader: reader];
}

/**
 * Write the XML for this instance of ENUNCIATE_SAMPLE_WEBAPPMODELPerson to the writer.
 * Note that since we're only writing the XML type,
 * No start/end element will be written.
 *
 * @param reader The reader.
 */
- (void) writeXMLType: (xmlTextWriterPtr) writer
{
  [super writeXMLType:writer];
}

/**
 * Reads a ENUNCIATE_SAMPLE_WEBAPPMODELPerson from an XML reader. The element to be read is
 * "{http://webcohesion.com/enunciate/samples/model/}person".
 *
 * @param reader The XML reader.
 * @return The ENUNCIATE_SAMPLE_WEBAPPMODELPerson.
 */
+ (id<JAXBElement>) readXMLElement: (xmlTextReaderPtr) reader {
  int status;
  ENUNCIATE_SAMPLE_WEBAPPMODELPerson *_person = nil;

  if (xmlTextReaderNodeType(reader) != XML_READER_TYPE_ELEMENT) {
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
    if (status < 1) {
      [NSException raise: @"XMLReadError"
                   format: @"Error advancing the reader to start element {http://webcohesion.com/enunciate/samples/model/}person."];
    }
  }

  if (xmlStrcmp(BAD_CAST "person", xmlTextReaderConstLocalName(reader)) == 0
      && xmlStrcmp(BAD_CAST "http://webcohesion.com/enunciate/samples/model/", xmlTextReaderConstNamespaceUri(reader)) == 0) {
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read root element {http://webcohesion.com/enunciate/samples/model/}person.");
#endif
    _person = (ENUNCIATE_SAMPLE_WEBAPPMODELPerson *)[ENUNCIATE_SAMPLE_WEBAPPMODELPerson readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"Successfully read root element {http://webcohesion.com/enunciate/samples/model/}person.");
#endif
  }
  else {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read ENUNCIATE_SAMPLE_WEBAPPMODELPerson. Expected element {http://webcohesion.com/enunciate/samples/model/}person. Current element: {}%s", xmlTextReaderConstLocalName(reader)];
    }
    else {
      [NSException raise: @"XMLReadError"
                   format: @"Unable to read ENUNCIATE_SAMPLE_WEBAPPMODELPerson. Expected element {http://webcohesion.com/enunciate/samples/model/}person. Current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader)];
    }
  }

  return _person;
}

/**
 * Writes this ENUNCIATE_SAMPLE_WEBAPPMODELPerson to XML under element name "{http://webcohesion.com/enunciate/samples/model/}person".
 * The namespace declarations for the element will be written.
 *
 * @param writer The XML writer.
 * @param _person The Person to write.
 * @return 1 if successful, 0 otherwise.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer
{
  [self writeXMLElement: writer writeNamespaces: YES];
}

/**
 * Writes this ENUNCIATE_SAMPLE_WEBAPPMODELPerson to an XML writer.
 *
 * @param writer The writer.
 * @param writeNs Whether to write the namespaces for this element to the xml writer.
 */
- (void) writeXMLElement: (xmlTextWriterPtr) writer writeNamespaces: (BOOL) writeNs
{
  int rc = xmlTextWriterStartElementNS(writer, BAD_CAST "model", BAD_CAST "person", NULL);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing start element {http://webcohesion.com/enunciate/samples/model/}person. XML writer status: %i\n", rc];
  }

  if (writeNs) {
#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing namespaces for start element {http://webcohesion.com/enunciate/samples/model/}person...");
#endif

    rc = xmlTextWriterWriteAttribute(writer, BAD_CAST "xmlns:model", BAD_CAST "http://webcohesion.com/enunciate/samples/model/");
    if (rc < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing attribute 'xmlns:model' on '{http://webcohesion.com/enunciate/samples/model/}person'. XML writer status: %i\n", rc];
    }
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote namespaces for start element {http://webcohesion.com/enunciate/samples/model/}person...");
#endif
  }

#if DEBUG_ENUNCIATE > 1
  NSLog(@"writing type {http://webcohesion.com/enunciate/samples/model/}person for root element {http://webcohesion.com/enunciate/samples/model/}person...");
#endif
  [self writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
  NSLog(@"successfully wrote type {http://webcohesion.com/enunciate/samples/model/}person for root element {http://webcohesion.com/enunciate/samples/model/}person...");
#endif
  rc = xmlTextWriterEndElement(writer);
  if (rc < 0) {
    [NSException raise: @"XMLWriteError"
                 format: @"Error writing end element {http://webcohesion.com/enunciate/samples/model/}person. XML writer status: %i\n", rc];
  }
}

//documentation inherited.
- (BOOL) readJAXBAttribute: (xmlTextReaderPtr) reader
{
  void *_child_accessor;

  if ([super readJAXBAttribute: reader]) {
    return YES;
  }

  return NO;
}

//documentation inherited.
- (BOOL) readJAXBValue: (xmlTextReaderPtr) reader
{
  return [super readJAXBValue: reader];
}

//documentation inherited.
- (BOOL) readJAXBChildElement: (xmlTextReaderPtr) reader
{
  id __child;
  void *_child_accessor;
  int status, depth;

  if ([super readJAXBChildElement: reader]) {
    return YES;
  }
  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "id", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}id of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}id of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setIdentifier: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "email", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}email of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}email of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setEmail: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "alias", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}alias of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}alias of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setAlias: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "name", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}name of type {http://webcohesion.com/enunciate/samples/model/}name.");
#endif
    __child = [ENUNCIATE_SAMPLE_WEBAPPMODELName readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}name of type {http://webcohesion.com/enunciate/samples/model/}name.");
#endif

    [self setName: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "picture", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}picture of type {http://www.w3.org/2001/XMLSchema}base64Binary.");
#endif
    __child = [NSData readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}picture of type {http://www.w3.org/2001/XMLSchema}base64Binary.");
#endif

    [self setPicture: __child];
    return YES;
  } //end "if choice"


  return NO;
}

//documentation inherited.
- (int) readUnknownJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readUnknownJAXBChildElement: reader];
}

//documentation inherited.
- (void) readUnknownJAXBAttribute: (xmlTextReaderPtr) reader
{
  [super readUnknownJAXBAttribute: reader];
}

//documentation inherited.
- (void) writeJAXBAttributes: (xmlTextWriterPtr) writer
{
  int status;

  [super writeJAXBAttributes: writer];

}

//documentation inherited.
- (void) writeJAXBValue: (xmlTextWriterPtr) writer
{
  [super writeJAXBValue: writer];
}

/**
 * Method for writing the child elements.
 *
 * @param writer The writer.
 */
- (void) writeJAXBChildElements: (xmlTextWriterPtr) writer
{
  int status;
  id __item;
  id __item_copy;
  NSEnumerator *__enumerator;

  [super writeJAXBChildElements: writer];

  if ([self identifier]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "id", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}id."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}id...");
#endif
    [[self identifier] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}id...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}id."];
    }
  }
  if ([self email]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "email", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}email."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}email...");
#endif
    [[self email] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}email...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}email."];
    }
  }
  if ([self alias]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "alias", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}alias."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}alias...");
#endif
    [[self alias] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}alias...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}alias."];
    }
  }
  if ([self name]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "name", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}name."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}name...");
#endif
    [[self name] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}name...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}name."];
    }
  }
  if ([self picture]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "picture", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}picture."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}picture...");
#endif
    [[self picture] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}picture...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}picture."];
    }
  }
}
@end /* implementation ENUNCIATE_SAMPLE_WEBAPPMODELPerson (JAXB) */

#endif /* DEF_ENUNCIATE_SAMPLE_WEBAPPMODELPerson_M */
#ifndef DEF_ENUNCIATE_SAMPLE_WEBAPPMODELName_M
#define DEF_ENUNCIATE_SAMPLE_WEBAPPMODELName_M

/**
 *  A name of a persona.
 * 
 *  @author Ryan Heaton
 */
@implementation ENUNCIATE_SAMPLE_WEBAPPMODELName

/**
 * The given name.
 */
- (NSString *) givenName
{
  return _givenName;
}

/**
 * The given name.
 */
- (void) setGivenName: (NSString *) newGivenName
{
  [newGivenName retain];
  [_givenName release];
  _givenName = newGivenName;
}

/**
 * The surname.
 */
- (NSString *) surname
{
  return _surname;
}

/**
 * The surname.
 */
- (void) setSurname: (NSString *) newSurname
{
  [newSurname retain];
  [_surname release];
  _surname = newSurname;
}

- (void) dealloc
{
  [self setGivenName: nil];
  [self setSurname: nil];
  [super dealloc];
}
@end /* implementation ENUNCIATE_SAMPLE_WEBAPPMODELName */

/**
 * Internal, private interface for JAXB reading and writing.
 */
@interface ENUNCIATE_SAMPLE_WEBAPPMODELName (JAXB) <JAXBReading, JAXBWriting, JAXBType>

@end /*interface ENUNCIATE_SAMPLE_WEBAPPMODELName (JAXB)*/

/**
 * Internal, private implementation for JAXB reading and writing.
 */
@implementation ENUNCIATE_SAMPLE_WEBAPPMODELName (JAXB)

/**
 * Read an instance of ENUNCIATE_SAMPLE_WEBAPPMODELName from an XML reader.
 *
 * @param reader The reader.
 * @return An instance of ENUNCIATE_SAMPLE_WEBAPPMODELName defined by the XML reader.
 */
+ (id<JAXBType>) readXMLType: (xmlTextReaderPtr) reader
{
  ENUNCIATE_SAMPLE_WEBAPPMODELName *_eNUNCIATE_SAMPLE_WEBAPPMODELName = [[ENUNCIATE_SAMPLE_WEBAPPMODELName alloc] init];
  NS_DURING
  {
    [_eNUNCIATE_SAMPLE_WEBAPPMODELName initWithReader: reader];
  }
  NS_HANDLER
  {
    _eNUNCIATE_SAMPLE_WEBAPPMODELName = nil;
    [localException raise];
  }
  NS_ENDHANDLER

  [_eNUNCIATE_SAMPLE_WEBAPPMODELName autorelease];
  return _eNUNCIATE_SAMPLE_WEBAPPMODELName;
}

/**
 * Initialize this instance of ENUNCIATE_SAMPLE_WEBAPPMODELName according to
 * the XML being read from the reader.
 *
 * @param reader The reader.
 */
- (id) initWithReader: (xmlTextReaderPtr) reader
{
  return [super initWithReader: reader];
}

/**
 * Write the XML for this instance of ENUNCIATE_SAMPLE_WEBAPPMODELName to the writer.
 * Note that since we're only writing the XML type,
 * No start/end element will be written.
 *
 * @param reader The reader.
 */
- (void) writeXMLType: (xmlTextWriterPtr) writer
{
  [super writeXMLType:writer];
}

//documentation inherited.
- (BOOL) readJAXBAttribute: (xmlTextReaderPtr) reader
{
  void *_child_accessor;

  if ([super readJAXBAttribute: reader]) {
    return YES;
  }

  return NO;
}

//documentation inherited.
- (BOOL) readJAXBValue: (xmlTextReaderPtr) reader
{
  return [super readJAXBValue: reader];
}

//documentation inherited.
- (BOOL) readJAXBChildElement: (xmlTextReaderPtr) reader
{
  id __child;
  void *_child_accessor;
  int status, depth;

  if ([super readJAXBChildElement: reader]) {
    return YES;
  }
  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "givenName", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}givenName of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}givenName of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setGivenName: __child];
    return YES;
  } //end "if choice"

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "surname", xmlTextReaderConstLocalName(reader)) == 0
    && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
    NSLog(@"Attempting to read choice {}surname of type {http://www.w3.org/2001/XMLSchema}string.");
#endif
    __child = [NSString readXMLType: reader];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully read choice {}surname of type {http://www.w3.org/2001/XMLSchema}string.");
#endif

    [self setSurname: __child];
    return YES;
  } //end "if choice"


  return NO;
}

//documentation inherited.
- (int) readUnknownJAXBChildElement: (xmlTextReaderPtr) reader
{
  return [super readUnknownJAXBChildElement: reader];
}

//documentation inherited.
- (void) readUnknownJAXBAttribute: (xmlTextReaderPtr) reader
{
  [super readUnknownJAXBAttribute: reader];
}

//documentation inherited.
- (void) writeJAXBAttributes: (xmlTextWriterPtr) writer
{
  int status;

  [super writeJAXBAttributes: writer];

}

//documentation inherited.
- (void) writeJAXBValue: (xmlTextWriterPtr) writer
{
  [super writeJAXBValue: writer];
}

/**
 * Method for writing the child elements.
 *
 * @param writer The writer.
 */
- (void) writeJAXBChildElements: (xmlTextWriterPtr) writer
{
  int status;
  id __item;
  id __item_copy;
  NSEnumerator *__enumerator;

  [super writeJAXBChildElements: writer];

  if ([self givenName]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "givenName", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}givenName."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}givenName...");
#endif
    [[self givenName] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}givenName...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}givenName."];
    }
  }
  if ([self surname]) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "surname", NULL);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing start child element {}surname."];
    }

#if DEBUG_ENUNCIATE > 1
    NSLog(@"writing element {}surname...");
#endif
    [[self surname] writeXMLType: writer];
#if DEBUG_ENUNCIATE > 1
    NSLog(@"successfully wrote element {}surname...");
#endif

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
      [NSException raise: @"XMLWriteError"
                   format: @"Error writing end child element {}surname."];
    }
  }
}
@end /* implementation ENUNCIATE_SAMPLE_WEBAPPMODELName (JAXB) */

#endif /* DEF_ENUNCIATE_SAMPLE_WEBAPPMODELName_M */
