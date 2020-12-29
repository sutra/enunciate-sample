#include <enunciate-common.c>
#ifndef DEF_enunciate_sample_webapp_model_name_H
#define DEF_enunciate_sample_webapp_model_name_H

/**
 * (no documentation provided)
 */
struct enunciate_sample_webapp_model_name {


  /**
   * (no documentation provided)
   */
  xmlChar *givenName;

  /**
   * (no documentation provided)
   */
  xmlChar *fullName;

  /**
   * (no documentation provided)
   */
  xmlChar *surname;
};

/**
 * Reads a Name from XML. The reader is assumed to be at the start element.
 *
 * @param reader The XML reader.
 * @return The Name, or NULL in case of error.
 */
static struct enunciate_sample_webapp_model_name *xmlTextReaderReadModelNameType(xmlTextReaderPtr reader);

/**
 * Writes a Name to XML.
 *
 * @param writer The XML writer.
 * @param _name The Name to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteModelNameType(xmlTextWriterPtr writer, struct enunciate_sample_webapp_model_name *_name);

/**
 * Frees the elements of a Name.
 *
 * @param _name The Name to free.
 */
static void freeModelNameType(struct enunciate_sample_webapp_model_name *_name);

#endif /* DEF_enunciate_sample_webapp_model_name_H */
#ifndef DEF_enunciate_sample_webapp_model_person_H
#define DEF_enunciate_sample_webapp_model_person_H

/**
 * (no documentation provided)
 */
struct enunciate_sample_webapp_model_person {


  /**
   * (no documentation provided)
   */
  struct enunciate_sample_webapp_model_name *name;

  /**
   * (no documentation provided)
   */
  xmlChar *email;

  /**
   * (no documentation provided)
   */
  xmlChar *id;

  /**
   * (no documentation provided)
   */
  xmlChar *alias;

  /**
   * (no documentation provided)
   */
  unsigned char *picture;

  /**
   * Size of the picture data.
   */
  int _sizeof_picture;
};

/**
 * Reads a Person element from XML. The element to be read is "{http://webcohesion.com/enunciate/samples/model/}person", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Person, or NULL in case of error.
 */
struct enunciate_sample_webapp_model_person *xml_read_enunciate_sample_webapp_model_person(xmlTextReaderPtr reader);

/**
 * Writes a Person to XML under element name "{http://webcohesion.com/enunciate/samples/model/}person".
 *
 * @param writer The XML writer.
 * @param _person The Person to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
int xml_write_enunciate_sample_webapp_model_person(xmlTextWriterPtr writer, struct enunciate_sample_webapp_model_person *_person);

/**
 * Frees a Person.
 *
 * @param _person The Person to free.
 */
void free_enunciate_sample_webapp_model_person(struct enunciate_sample_webapp_model_person *_person);

/**
 * Reads a Person element from XML. The element to be read is "{http://webcohesion.com/enunciate/samples/model/}person", and
 * it is assumed that the reader is already pointing to the element.
 *
 * @param reader The XML reader.
 * @return The Person, or NULL in case of error.
 */
struct enunciate_sample_webapp_model_person *xmlTextReaderReadModelPersonElement(xmlTextReaderPtr reader);

/**
 * Writes a Person to XML under element name "{http://webcohesion.com/enunciate/samples/model/}person".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _person The Person to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteModelPersonElement(xmlTextWriterPtr writer, struct enunciate_sample_webapp_model_person *_person);

/**
 * Writes a Person to XML under element name "{http://webcohesion.com/enunciate/samples/model/}person".
 *
 * @param writer The XML writer.
 * @param _person The Person to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteModelPersonElementNS(xmlTextWriterPtr writer, struct enunciate_sample_webapp_model_person *_person, int writeNamespaces);

/**
 * Frees the children of a Person.
 *
 * @param _person The Person whose children are to be free.
 */
static void freeModelPersonElement(struct enunciate_sample_webapp_model_person *_person);

/**
 * Reads a Person from XML. The reader is assumed to be at the start element.
 *
 * @param reader The XML reader.
 * @return The Person, or NULL in case of error.
 */
static struct enunciate_sample_webapp_model_person *xmlTextReaderReadModelPersonType(xmlTextReaderPtr reader);

/**
 * Writes a Person to XML.
 *
 * @param writer The XML writer.
 * @param _person The Person to write.
 * @return The bytes written (may be 0 in case of buffering) or -1 in case of error.
 */
static int xmlTextWriterWriteModelPersonType(xmlTextWriterPtr writer, struct enunciate_sample_webapp_model_person *_person);

/**
 * Frees the elements of a Person.
 *
 * @param _person The Person to free.
 */
static void freeModelPersonType(struct enunciate_sample_webapp_model_person *_person);

#endif /* DEF_enunciate_sample_webapp_model_person_H */
#ifndef DEF_enunciate_sample_webapp_model_name_M
#define DEF_enunciate_sample_webapp_model_name_M

/**
 * Reads a Name from XML. The reader is assumed to be at the start element.
 *
 * @return the Name, or NULL in case of error.
 */
static struct enunciate_sample_webapp_model_name *xmlTextReaderReadModelNameType(xmlTextReaderPtr reader) {
  int status, depth;
  void *_child_accessor;
  struct enunciate_sample_webapp_model_name *_name = calloc(1, sizeof(struct enunciate_sample_webapp_model_name));



  if (xmlTextReaderIsEmptyElement(reader) == 0) {
    depth = xmlTextReaderDepth(reader);//track the depth.
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);

    while (xmlTextReaderDepth(reader) > depth) {
      if (status < 1) {
        //panic: XML read error.
#if DEBUG_ENUNCIATE
        printf("Failure to advance to next child element.\n");
#endif
        freeModelNameType(_name);
        free(_name);
        return NULL;
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "givenName", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}givenName of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}givenName of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeModelNameType(_name);
          free(_name);
          return NULL;
        }

        _name->givenName = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "fullName", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}fullName of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}fullName of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeModelNameType(_name);
          free(_name);
          return NULL;
        }

        _name->fullName = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "surname", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}surname of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}surname of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeModelNameType(_name);
          free(_name);
          return NULL;
        }

        _name->surname = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else {
#if DEBUG_ENUNCIATE > 1
        if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
          printf("unknown child element {}%s for type {http://webcohesion.com/enunciate/samples/model/}name.  Skipping...\n",  xmlTextReaderConstLocalName(reader));
        }
        else {
          printf("unknown child element {%s}%s for type {http://webcohesion.com/enunciate/samples/model/}name. Skipping...\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
        }
#endif
        status = xmlTextReaderSkipElement(reader);
      }
    }
  }

  return _name;
}

/**
 * Writes a Name to XML.
 *
 * @param writer The XML writer.
 * @param _name The Name to write.
 * @return The total bytes written, or -1 on error;
 */
static int xmlTextWriterWriteModelNameType(xmlTextWriterPtr writer, struct enunciate_sample_webapp_model_name *_name) {
  int status, totalBytes = 0, i;
  xmlChar *binaryData;
  if (_name->givenName != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "givenName", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}givenName. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}givenName...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_name->givenName));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}givenName. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}givenName. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_name->fullName != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "fullName", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}fullName. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}fullName...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_name->fullName));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}fullName. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}fullName. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_name->surname != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "surname", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}surname. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}surname...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_name->surname));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}surname. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}surname. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }

  return totalBytes;
}

/**
 * Frees the elements of a Name.
 *
 * @param _name The Name to free.
 */
static void freeModelNameType(struct enunciate_sample_webapp_model_name *_name) {
  int i;
  if (_name->givenName != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor givenName of type enunciate_sample_webapp_model_name...\n");
#endif
    freeXsStringType(_name->givenName);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor givenName of type enunciate_sample_webapp_model_name...\n");
#endif
    free(_name->givenName);
  }
  if (_name->fullName != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor fullName of type enunciate_sample_webapp_model_name...\n");
#endif
    freeXsStringType(_name->fullName);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor fullName of type enunciate_sample_webapp_model_name...\n");
#endif
    free(_name->fullName);
  }
  if (_name->surname != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor surname of type enunciate_sample_webapp_model_name...\n");
#endif
    freeXsStringType(_name->surname);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor surname of type enunciate_sample_webapp_model_name...\n");
#endif
    free(_name->surname);
  }
}
#endif /* DEF_enunciate_sample_webapp_model_name_M */
#ifndef DEF_enunciate_sample_webapp_model_person_M
#define DEF_enunciate_sample_webapp_model_person_M

/**
 * Reads a Person element from XML. The element to be read is "{http://webcohesion.com/enunciate/samples/model/}person", and
 * it is assumed that the reader is pointing to the XML document (not the element).
 *
 * @param reader The XML reader.
 * @return The Person, or NULL in case of error.
 */
struct enunciate_sample_webapp_model_person *xml_read_enunciate_sample_webapp_model_person(xmlTextReaderPtr reader) {
  int status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
  return xmlTextReaderReadModelPersonElement(reader);
}

/**
 * Writes a Person to XML under element name "{http://webcohesion.com/enunciate/samples/model/}person".
 *
 * @param writer The XML writer.
 * @param _person The Person to write.
 * @return 1 if successful, 0 otherwise.
 */
int xml_write_enunciate_sample_webapp_model_person(xmlTextWriterPtr writer, struct enunciate_sample_webapp_model_person *_person) {
  return xmlTextWriterWriteModelPersonElementNS(writer, _person, 1);
}

/**
 * Frees a Person.
 *
 * @param _person The Person to free.
 */
void free_enunciate_sample_webapp_model_person(struct enunciate_sample_webapp_model_person *_person) {
  freeModelPersonType(_person);
  free(_person);
}

/**
 * Reads a Person element from XML. The element to be read is "{http://webcohesion.com/enunciate/samples/model/}person", and
 * it is assumed that the reader is pointing to that element.
 *
 * @param reader The XML reader.
 * @return The Person, or NULL in case of error.
 */
struct enunciate_sample_webapp_model_person *xmlTextReaderReadModelPersonElement(xmlTextReaderPtr reader) {
  struct enunciate_sample_webapp_model_person *_person = NULL;

  if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
    && xmlStrcmp(BAD_CAST "person", xmlTextReaderConstLocalName(reader)) == 0
    && xmlStrcmp(BAD_CAST "http://webcohesion.com/enunciate/samples/model/", xmlTextReaderConstNamespaceUri(reader)) == 0) {
#if DEBUG_ENUNCIATE > 1
    printf("Attempting to read root element {http://webcohesion.com/enunciate/samples/model/}person.\n");
#endif
    _person = xmlTextReaderReadModelPersonType(reader);
  }
#if DEBUG_ENUNCIATE
  if (_person == NULL) {
    if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
      printf("attempt to read {http://webcohesion.com/enunciate/samples/model/}person failed. current element: {}%s\n",  xmlTextReaderConstLocalName(reader));
    }
    else {
      printf("attempt to read {http://webcohesion.com/enunciate/samples/model/}person failed. current element: {%s}%s\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
    }
  }
#endif

  return _person;
}

/**
 * Writes a Person to XML under element name "{http://webcohesion.com/enunciate/samples/model/}person".
 * Does NOT write the namespace prefixes.
 *
 * @param writer The XML writer.
 * @param _person The Person to write.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteModelPersonElement(xmlTextWriterPtr writer, struct enunciate_sample_webapp_model_person *_person) {
  return xmlTextWriterWriteModelPersonElementNS(writer, _person, 0);
}

/**
 * Writes a Person to XML under element name "{http://webcohesion.com/enunciate/samples/model/}person".
 *
 * @param writer The XML writer.
 * @param _person The Person to write.
 * @param writeNamespaces Whether to write the namespace prefixes.
 * @return 1 if successful, 0 otherwise.
 */
static int xmlTextWriterWriteModelPersonElementNS(xmlTextWriterPtr writer, struct enunciate_sample_webapp_model_person *_person, int writeNamespaces) {
  int totalBytes = 0;
  int status;

  status = xmlTextWriterStartElementNS(writer, BAD_CAST "model", BAD_CAST "person", NULL);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write start element {http://webcohesion.com/enunciate/samples/model/}person. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  if (writeNamespaces) {
#if DEBUG_ENUNCIATE > 1
    printf("writing namespaces for start element {http://webcohesion.com/enunciate/samples/model/}person...\n");
#endif

    status = xmlTextWriterWriteAttribute(writer, BAD_CAST "xmlns:model", BAD_CAST "http://webcohesion.com/enunciate/samples/model/");
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("unable to write namespace attribute xmlns:model. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }

#if DEBUG_ENUNCIATE > 1
  printf("writing type {http://webcohesion.com/enunciate/samples/model/}person for root element {http://webcohesion.com/enunciate/samples/model/}person...\n");
#endif
  status = xmlTextWriterWriteModelPersonType(writer, _person);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to write type for start element {http://webcohesion.com/enunciate/samples/model/}person. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  status = xmlTextWriterEndElement(writer);
  if (status < 0) {
#if DEBUG_ENUNCIATE
    printf("unable to end element {http://webcohesion.com/enunciate/samples/model/}person. status: %i\n", status);
#endif
    return status;
  }
  totalBytes += status;

  return totalBytes;
}

/**
 * Frees the children of a Person.
 *
 * @param _person The Person whose children are to be free.
 */
static void freeModelPersonElement(struct enunciate_sample_webapp_model_person *_person) {
  freeModelPersonType(_person);
}

/**
 * Reads a Person from XML. The reader is assumed to be at the start element.
 *
 * @return the Person, or NULL in case of error.
 */
static struct enunciate_sample_webapp_model_person *xmlTextReaderReadModelPersonType(xmlTextReaderPtr reader) {
  int status, depth;
  void *_child_accessor;
  struct enunciate_sample_webapp_model_person *_person = calloc(1, sizeof(struct enunciate_sample_webapp_model_person));



  if (xmlTextReaderIsEmptyElement(reader) == 0) {
    depth = xmlTextReaderDepth(reader);//track the depth.
    status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);

    while (xmlTextReaderDepth(reader) > depth) {
      if (status < 1) {
        //panic: XML read error.
#if DEBUG_ENUNCIATE
        printf("Failure to advance to next child element.\n");
#endif
        freeModelPersonType(_person);
        free(_person);
        return NULL;
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "name", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}name of type {http://webcohesion.com/enunciate/samples/model/}name.\n");
#endif
        _child_accessor = xmlTextReaderReadModelNameType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}name of type {http://webcohesion.com/enunciate/samples/model/}name.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeModelPersonType(_person);
          free(_person);
          return NULL;
        }

        _person->name = ((struct enunciate_sample_webapp_model_name*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "email", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}email of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}email of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeModelPersonType(_person);
          free(_person);
          return NULL;
        }

        _person->email = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "id", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}id of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}id of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeModelPersonType(_person);
          free(_person);
          return NULL;
        }

        _person->id = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "alias", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read choice {}alias of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
        _child_accessor = xmlTextReaderReadXsStringType(reader);
        if (_child_accessor == NULL) {
#if DEBUG_ENUNCIATE
          printf("Failed to read choice {}alias of type {http://www.w3.org/2001/XMLSchema}string.\n");
#endif
          //panic: unable to read the child element for some reason.
          freeModelPersonType(_person);
          free(_person);
          return NULL;
        }

        _person->alias = ((xmlChar*)_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else if (xmlTextReaderNodeType(reader) == XML_READER_TYPE_ELEMENT
        && xmlStrcmp(BAD_CAST "picture", xmlTextReaderConstLocalName(reader)) == 0
        && xmlTextReaderConstNamespaceUri(reader) == NULL) {

#if DEBUG_ENUNCIATE > 1
        printf("Attempting to read binary data of choice {}picture.\n");
#endif
        _child_accessor = xmlTextReaderReadEntireNodeValue(reader);
        _person->picture = _decode_base64((xmlChar *) _child_accessor, &(_person->_sizeof_picture));
        free(_child_accessor);
        status = xmlTextReaderAdvanceToNextStartOrEndElement(reader);
      }
      else {
#if DEBUG_ENUNCIATE > 1
        if (xmlTextReaderConstNamespaceUri(reader) == NULL) {
          printf("unknown child element {}%s for type {http://webcohesion.com/enunciate/samples/model/}person.  Skipping...\n",  xmlTextReaderConstLocalName(reader));
        }
        else {
          printf("unknown child element {%s}%s for type {http://webcohesion.com/enunciate/samples/model/}person. Skipping...\n", xmlTextReaderConstNamespaceUri(reader), xmlTextReaderConstLocalName(reader));
        }
#endif
        status = xmlTextReaderSkipElement(reader);
      }
    }
  }

  return _person;
}

/**
 * Writes a Person to XML.
 *
 * @param writer The XML writer.
 * @param _person The Person to write.
 * @return The total bytes written, or -1 on error;
 */
static int xmlTextWriterWriteModelPersonType(xmlTextWriterPtr writer, struct enunciate_sample_webapp_model_person *_person) {
  int status, totalBytes = 0, i;
  xmlChar *binaryData;
  if (_person->name != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "name", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}name. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://webcohesion.com/enunciate/samples/model/}name for element {}name...\n");
#endif
    status = xmlTextWriterWriteModelNameType(writer, (_person->name));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://webcohesion.com/enunciate/samples/model/}name for element {}name. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}name. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_person->email != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "email", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}email. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}email...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_person->email));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}email. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}email. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_person->id != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "id", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}id. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}id...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_person->id));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}id. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}id. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_person->alias != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "alias", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}alias. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
#if DEBUG_ENUNCIATE > 1
    printf("writing type {http://www.w3.org/2001/XMLSchema}string for element {}alias...\n");
#endif
    status = xmlTextWriterWriteXsStringType(writer, (_person->alias));
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write type {http://www.w3.org/2001/XMLSchema}string for element {}alias. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}alias. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }
  if (_person->picture != NULL) {
    status = xmlTextWriterStartElementNS(writer, NULL, BAD_CAST "picture", NULL);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write start element {}picture. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

#if DEBUG_ENUNCIATE > 1
    printf("writing binary data for element {}picture...\n");
#endif
    binaryData = _encode_base64(_person->picture, _person->_sizeof_picture);
    status = xmlTextWriterWriteString(writer, binaryData);
    free(binaryData);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write binary data for element {}picture. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;

    status = xmlTextWriterEndElement(writer);
    if (status < 0) {
#if DEBUG_ENUNCIATE
      printf("Failed to write end element {}picture. status: %i\n", status);
#endif
      return status;
    }
    totalBytes += status;
  }

  return totalBytes;
}

/**
 * Frees the elements of a Person.
 *
 * @param _person The Person to free.
 */
static void freeModelPersonType(struct enunciate_sample_webapp_model_person *_person) {
  int i;
  if (_person->name != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor name of type enunciate_sample_webapp_model_person...\n");
#endif
    freeModelNameType(_person->name);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor name of type enunciate_sample_webapp_model_person...\n");
#endif
    free(_person->name);
  }
  if (_person->email != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor email of type enunciate_sample_webapp_model_person...\n");
#endif
    freeXsStringType(_person->email);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor email of type enunciate_sample_webapp_model_person...\n");
#endif
    free(_person->email);
  }
  if (_person->id != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor id of type enunciate_sample_webapp_model_person...\n");
#endif
    freeXsStringType(_person->id);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor id of type enunciate_sample_webapp_model_person...\n");
#endif
    free(_person->id);
  }
  if (_person->alias != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing type of accessor alias of type enunciate_sample_webapp_model_person...\n");
#endif
    freeXsStringType(_person->alias);
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor alias of type enunciate_sample_webapp_model_person...\n");
#endif
    free(_person->alias);
  }
  if (_person->picture != NULL) {
#if DEBUG_ENUNCIATE > 1
    printf("Freeing accessor picture of type enunciate_sample_webapp_model_person...\n");
#endif
    free(_person->picture);
  }
}
#endif /* DEF_enunciate_sample_webapp_model_person_M */
