#ifndef IX_PIM_H
#define IX_PIM_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* Each contact commonly includes a name and one or more phone numbers.
* May also include a street address and an email address.
*/
/** @ingroup PIMAPI */
#define MA_PIM_CONTACTS 1

/** @ingroup PIMAPI */
#define MA_PIM_EVENTS 2
/** @ingroup PIMAPI */
#define MA_PIM_TODOS 3
/// bytes
/// the bytes are not null-terminated.
/** @ingroup PIMConsts */
#define MA_PIM_TYPE_BINARY 0

/// int
/** @ingroup PIMConsts */
#define MA_PIM_TYPE_BOOLEAN 1

/// int
/// unix time.
/** @ingroup PIMConsts */
#define MA_PIM_TYPE_DATE 2

/// int
/** @ingroup PIMConsts */
#define MA_PIM_TYPE_INT 3

/// wide-string '\\0'
/** @ingroup PIMConsts */
#define MA_PIM_TYPE_STRING 4

/// int (wide-string '\\0')*
/// the int specifies the number of strings.
/// there is no extra null terminator at the end of the list.
/** @ingroup PIMConsts */
#define MA_PIM_TYPE_STRING_ARRAY 5
/**
* @brief The addresses of the contact. Multiple string arrays. Has \link #MA_PIM_CONTACT_ADDR_POBOX MA_PIM_CONTACT_ADDR \endlink indices.
*
* @validvalue #MA_PIM_TYPE_STRING_ARRAY.
*
* @addsetget
*
* @attributes MA_PIM_ATTR_ADDR_HOME, MA_PIM_ATTR_ADDR_WORK, MA_PIM_ATTR_ADDR_OTHER, MA_PIM_ATTR_ADDR_CUSTOM.
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_ADDR 100

/**
* @brief The birthday of the contact. Single date.
*
* @validvalue #MA_PIM_TYPE_DATE.
*
* @addsetget
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_BIRTHDAY 101

/**
* @brief Access class. Single integer. May be one of #MA_PIM_CONTACT_CLASS_CONFIDENTIAL, #MA_PIM_CONTACT_CLASS_PRIVATE, or #MA_PIM_CONTACT_CLASS_PUBLIC.
*
* @validvalue #MA_PIM_TYPE_INT.
*
* @addsetget
*
* @platforms Symbian.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_CLASS 102

/**
* @brief The email addresses of the contact. Multiple strings.
*
* @validvalue #MA_PIM_TYPE_STRING.
*
* @addsetget
*
* @attributes MA_PIM_ATTR_EMAIL_HOME, MA_PIM_ATTR_EMAIL_WORK, MA_PIM_ATTR_EMAIL_MOBILE, MA_PIM_ATTR_EMAIL_OTHER, MA_PIM_ATTR_EMAIL_CUSTOM.
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_EMAIL 103

/**
* @brief The formatted addresses of the contact. Single string.
*
* @validvalue #MA_PIM_TYPE_STRING.
*
* @getonly
*
* @attributes MA_PIM_ATTR_FORMATTED_ADDR_HOME, MA_PIM_ATTR_FORMATTED_ADDR_WORK, MA_PIM_ATTR_FORMATTED_ADDR_OTHER, MA_PIM_ATTR_FORMATTED_ADDR_CUSTOM.
*
* @platforms Android.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_FORMATTED_ADDR 104

/**
* @brief The formatted name of the contact. Single string.
*
* @validvalue #MA_PIM_TYPE_STRING.
*
* @getonly
*
* @platforms Symbian.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_FORMATTED_NAME 105

/**
* @brief The name of the contact. Single string array containing Family name, Given name, Middle name, Prefix,
* Suffix, Phonetic family name, Phonetic given name, Phonetic middle name. Has \link #MA_PIM_CONTACT_NAME_FAMILY MA_PIM_CONTACT_NAME \endlink indices.
*
* @validvalue #MA_PIM_TYPE_STRING_ARRAY.
*
* @getonly
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_NAME 106

/**
* @brief The nickname of the contact. Single string.
*
* @validvalue #MA_PIM_TYPE_STRING.
*
* @addsetget
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_NICKNAME 107

/**
* @brief Supplementary information, or a comment. Multiple string.
*
* @validvalue #MA_PIM_TYPE_STRING.
*
* @addsetget
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_NOTE 108

/**
* @brief The organization name of the contact. Multiple string.
*
* @validvalue #MA_PIM_TYPE_STRING.
*
* @addsetget
*
* @attributes MA_PIM_ATTR_ORG_WORK, MA_PIM_ATTR_ORG_OTHER, MA_PIM_ATTR_ORG_CUSTOM.
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_ORG 109

/**
* @brief The contact's photo. A single int representing a data handle. Connected with PHOTO_URL.
*
* @validvalue #MA_PIM_TYPE_INT.
*
* @addsetget
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_PHOTO 110

/**
* @brief The contact's photo url. A single string representing the URL of a photo. Connected with PHOTO.
*
* @validvalue #MA_PIM_TYPE_STRING.
*
* @setonly
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_PHOTO_URL 111

/**
* @brief The public key of the contact. Connected with PUBLIC_KEY_STRING.
*
* @validvalue #MA_PIM_TYPE_BINARY.
*
* @addsetget
*
* @platforms Symbian.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_PUBLIC_KEY 112

/**
* @brief A string representation of the contact's public key. Connected with PUBLIC_KEY.
*
* @validvalue #MA_PIM_TYPE_STRING.
*
* @addsetget
*
* @platforms Symbian.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_PUBLIC_KEY_STRING 113

/**
* @brief The revision date of the field. Single date.
*
* @validvalue #MA_PIM_TYPE_DATE.
*
* @getonly
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_REVISION 114

/**
* @brief The telephone numbers of the contact. Multiple strings.
*
* @validvalue #MA_PIM_TYPE_STRING.
*
* @addsetget
*
* @attributes MA_PIM_ATTR_PHONE_HOME, MA_PIM_ATTR_PHONE_MOBILE, MA_PIM_ATTR_PHONE_HOME_FAX, MA_PIM_ATTR_PHONE_WORK_FAX, MA_PIM_ATTR_PHONE_PAGER, MA_PIM_ATTR_PHONE_IPHONE, MA_PIM_ATTR_PHONE_WORK, MA_PIM_ATTR_PHONE_CALLBACK, MA_PIM_ATTR_PHONE_CAR, MA_PIM_ATTR_PHONE_COMPANY_MAIN, MA_PIM_ATTR_PHONE_ISDN, MA_PIM_ATTR_PHONE_OTHER_FAX, MA_PIM_ATTR_PHONE_RADIO, MA_PIM_ATTR_PHONE_TELEX, MA_PIM_ATTR_PHONE_TTY_TDD, MA_PIM_ATTR_PHONE_WORK_MOBILE, MA_PIM_ATTR_PHONE_WORK_PAGER, MA_PIM_ATTR_PHONE_ASSISTANT, MA_PIM_ATTR_PHONE_MMS, MA_PIM_ATTR_PHONE_OTHER, MA_PIM_ATTR_PHONE_CUSTOM.
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_TEL 115

/**
* @brief The professional title of the contact inside the organization. Multiple strings.
*
* @validvalue #MA_PIM_TYPE_STRING.
*
* @addsetget
*
* @attributes MA_PIM_ATTR_TITLE_WORK, MA_PIM_ATTR_TITLE_OTHER, MA_PIM_ATTR_TITLE_CUSTOM.
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_TITLE 116

/**
* @brief The unique identifier of the contact on the current device. Single string.
*
* @validvalue Single #MA_PIM_TYPE_STRING.
*
* @getonly
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_UID 117

/**
* @brief Uniform Resource Locators associated with the contact. Multiple strings.
*
* @validvalue #MA_PIM_TYPE_STRING.
*
* @addsetget
*
* @attributes MA_PIM_ATTR_WEBSITE_HOMEPAGE, MA_PIM_ATTR_WEBSITE_BLOG, MA_PIM_ATTR_WEBSITE_PROFILE, MA_PIM_ATTR_WEBSITE_HOME, MA_PIM_ATTR_WEBSITE_WORK, MA_PIM_ATTR_WEBSITE_FTP, MA_PIM_ATTR_WEBSITE_OTHER, MA_PIM_ATTR_WEBSITE_CUSTOM.
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_URL 118

/**
* @brief The IM addresses of the contact. Multiple arrays. Has \link #MA_PIM_CONTACT_IM_USERNAME MA_PIM_CONTACT_IM \endlink indices.
*
* @validvalue #MA_PIM_TYPE_STRING_ARRAY.
*
* @addsetget
*
* @attributes MA_PIM_ATTR_IM_HOME, MA_PIM_ATTR_IM_WORK, MA_PIM_ATTR_IM_OTHER, MA_PIM_ATTR_IM_CUSTOM.
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_IM 119

/**
* @brief A relation of the contact.
*
* @validvalue #MA_PIM_TYPE_STRING.
*
* @addsetget
*
* @attributes MA_PIM_ATTR_RELATION_MOTHER, MA_PIM_ATTR_RELATION_FATHER, MA_PIM_ATTR_RELATION_PARENT, MA_PIM_ATTR_RELATION_SISTER, MA_PIM_ATTR_RELATION_BROTHER, MA_PIM_ATTR_RELATION_CHILD, MA_PIM_ATTR_RELATION_FRIEND, MA_PIM_ATTR_RELATION_SPOUSE, MA_PIM_ATTR_RELATION_PARTNER, MA_PIM_ATTR_RELATION_MANAGER, MA_PIM_ATTR_RELATION_ASSISTANT, MA_PIM_ATTR_RELATION_DOMESTIC_PARTNER, MA_PIM_ATTR_RELATION_REFERRED_BY, MA_PIM_ATTR_RELATION_RELATIVE, MA_PIM_ATTR_RELATION_CUSTOM.
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_RELATION 120

/**
* @brief Information about the organization. Has \link #MA_PIM_CONTACT_ORG_INFO_DEPARTMENT MA_PIM_CONTACT_ORG_INFO \endlink indices.
*
* @validvalue #MA_PIM_TYPE_STRING_ARRAY.
*
* @addsetget
*
* @attributes MA_PIM_ATTR_ORG_INFO_WORK, MA_PIM_ATTR_ORG_INFO_OTHER, MA_PIM_ATTR_ORG_INFO_CUSTOM.
*
* @platforms Android, iOS.
*
*/
/** @ingroup PIMConsts */
#define MA_PIM_FIELD_CONTACT_ORG_INFO 121
/// Index for #MA_PIM_FIELD_CONTACT_ADDR. Post office box number.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_ADDR_POBOX 0

/// Index for #MA_PIM_FIELD_CONTACT_ADDR. Extra info.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_ADDR_EXTRA 1

/// Index for #MA_PIM_FIELD_CONTACT_ADDR. Street name and number.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_ADDR_STREET 2

/// Index for #MA_PIM_FIELD_CONTACT_ADDR. Locality name. (ex. city)
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_ADDR_LOCALITY 3

/// Index for #MA_PIM_FIELD_CONTACT_ADDR. Region name. (ex. province, state or territory)
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_ADDR_REGION 4

/// Index for #MA_PIM_FIELD_CONTACT_ADDR. Postal code.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_ADDR_POSTALCODE 5

/// Index for #MA_PIM_FIELD_CONTACT_ADDR. Country name.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_ADDR_COUNTRY 6

/// Index for #MA_PIM_FIELD_CONTACT_ADDR. Neighborhood.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_ADDR_NEIGHBORHOOD 7
/// Index for #MA_PIM_FIELD_CONTACT_NAME. Family name.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_NAME_FAMILY 0

/// Index for #MA_PIM_FIELD_CONTACT_NAME. Given name.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_NAME_GIVEN 1

/// Index for #MA_PIM_FIELD_CONTACT_NAME. Alternate/secondary names, if any.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_NAME_OTHER 2

/// Index for #MA_PIM_FIELD_CONTACT_NAME. Prefix. (ex. "Dr.")
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_NAME_PREFIX 3

/// Index for #MA_PIM_FIELD_CONTACT_NAME. Suffix. (ex. "M.D.")
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_NAME_SUFFIX 4

/// Index for #MA_PIM_FIELD_CONTACT_NAME. Phonetic last name.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_NAME_PHONETIC_FAMILY 5

/// Index for #MA_PIM_FIELD_CONTACT_NAME. Phonetic first name.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_NAME_PHONETIC_GIVEN 6

/// Index for #MA_PIM_FIELD_CONTACT_NAME. Phonetic middle name.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_NAME_PHONETIC_OTHER 7

/// Index for #MA_PIM_FIELD_CONTACT_NAME. Display name.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_NAME_DISPLAY 8
/// #MA_PIM_TYPE_STRING.
/// Only for Android and iOS devices.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_ORG_INFO_DEPARTMENT 0

/// #MA_PIM_TYPE_STRING.
/// Only for Android devices.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_ORG_INFO_JOB_DESCRIPTION 1

/// #MA_PIM_TYPE_STRING.
/// Only for Android devices.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_ORG_INFO_SYMBOL 2

/// #MA_PIM_TYPE_STRING.
/// Only for Android devices.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_ORG_INFO_PHONETIC_NAME 3

/// #MA_PIM_TYPE_STRING.
/// Only for Android devices.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_ORG_INFO_OFFICE_LOCATION 4

/// #MA_PIM_TYPE_STRING.
/// Only for Android devices.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_ORG_INFO_PHONETIC_NAME_STYLE 5
/// #MA_PIM_TYPE_STRING.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_IM_USERNAME 0

/// #MA_PIM_TYPE_STRING.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_IM_PROTOCOL 1
/// Value for #MA_PIM_FIELD_CONTACT_CLASS.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_CLASS_CONFIDENTIAL 200

/// Value for #MA_PIM_FIELD_CONTACT_CLASS.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_CLASS_PRIVATE 201

/// Value for #MA_PIM_FIELD_CONTACT_CLASS.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_CLASS_PUBLIC 202
/// This constant describes an AIM protocol.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_IM_PROTOCOL_AIM "AIM"

/// This constant describes a MSN protocol.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_IM_PROTOCOL_MSN "MSN"

/// This constant describes a Yahoo protocol.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_IM_PROTOCOL_YAHOO "Yahoo"

/// This constant describes a Skype protocol.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_IM_PROTOCOL_SKYPE "Skype"

/// This constant describes a QQ protocol.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_IM_PROTOCOL_QQ "QQ"

/// This constant describes a Google Talk protocol.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_IM_PROTOCOL_GOOGLE_TALK "GoogleTalk"

/// This constant describes an ICQ protocol.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_IM_PROTOCOL_ICQ "ICQ"

/// This constant describes a Jabber protocol.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_IM_PROTOCOL_JABBER "Jabber"

/// This constant describes a NetMeeting protocol.
/** @ingroup PIMConsts */
#define MA_PIM_CONTACT_IM_PROTOCOL_NETMEETING "Netmeeting"
/// The value describes an assistant.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_ASST 1

/// Unknown.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_AUTO 2

/// The value describes a fax number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_FAX 4

/// The value describes a home phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_HOME 8

/// The value describes a mobile phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_MOBILE 16

/// Unknown.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_OTHER 32

/// The value describes a pager number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PAGER 64

/// In a field with multiple values, this one is preferred before the others.
/// Only one value per field may be marked PREFERRED. Marking a value PREFERRED
/// causes any other PREFERRED value in the field to become unmarked.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PREFERRED 128

/// The value describes an SMS number?
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_SMS 256

/// The value describes a work phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_WORK 512
/// The constant describes a home address.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_ADDR_HOME 101

/// The constant describes a work address.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_ADDR_WORK 102

/// The constant describes a different address type.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_ADDR_OTHER 103

/// The constant describes a custom address type.
/// The field's label can be set.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_ADDR_CUSTOM 104
/// The constant describes a home e-mail address.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_EMAIL_HOME 201

/// The constant describes a work e-mail address.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_EMAIL_WORK 202

/// The constant describes a mobile e-mail address.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_EMAIL_MOBILE 203

/// The constant describes a different e-mail address type.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_EMAIL_OTHER 204

/// The constant describes a custom e-mail address type.
/// The field's label can be set.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_EMAIL_CUSTOM 205
/// The constant describes a home formatted address.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_FORMATTED_ADDR_HOME 301

/// The constant describes a work formatted address.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_FORMATTED_ADDR_WORK 302

/// The constant describes a different formatted address type.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_FORMATTED_ADDR_OTHER 303

/// The constant describes a custom formatted address type.
/// The field's label can be set.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_FORMATTED_ADDR_CUSTOM 304
/// The constant describes a work organization.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_ORG_WORK 401

/// The constant describes a different organization type.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_ORG_OTHER 402

/// The constant describes a custom organization type.
/// The field's label can be set.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_ORG_CUSTOM 403
/// The constant describes a home phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_HOME 501

/// The constant describes a mobile phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_MOBILE 502

/// The constant describes a home fax phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_HOME_FAX 503

/// The constant describes a work fax phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_WORK_FAX 504

/// The constant describes a pager phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_PAGER 505

/// The constant describes an iPhone phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_IPHONE 506

/// The constant describes a work phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_WORK 507

/// The constant describes a callback phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_CALLBACK 508

/// The constant describes a car phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_CAR 509

/// The constant describes a company main phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_COMPANY_MAIN 510

/// The constant describes a ISDN phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_ISDN 511

/// The constant describes a other fax type phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_OTHER_FAX 512

/// The constant describes a radio phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_RADIO 513

/// The constant describes a telex phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_TELEX 514

/// The constant describes a TTY TDD phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_TTY_TDD 515

/// The constant describes a work mobile phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_WORK_MOBILE 516

/// The constant describes a work pager phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_WORK_PAGER 517

/// The constant describes an assistant phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_ASSISTANT 518

/// The constant describes a MMS phone number.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_MMS 519

/// The constant describes a different phone number type.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_OTHER 520

/// The constant describes a custom phone number type.
/// The field's label can be set.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_PHONE_CUSTOM 521
/// The constant describes a work title.
/// Not available on iOS.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_TITLE_WORK 601

/// The constant describes a different title type.
/// Not available on iOS.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_TITLE_OTHER 602

/// The constant describes a custom title type.
/// The field's label can be set.
/// Not available on iOS.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_TITLE_CUSTOM 603
/// The constant describes a homepage website.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_WEBSITE_HOMEPAGE 701

/// The constant describes a blog website.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_WEBSITE_BLOG 702

/// The constant describes a profile website.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_WEBSITE_PROFILE 703

/// The constant describes a home website.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_WEBSITE_HOME 704

/// The constant describes a work website.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_WEBSITE_WORK 705

/// The constant describes a FTP website.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_WEBSITE_FTP 706

/// The constant describes a different website type.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_WEBSITE_OTHER 707

/// The constant describes a custom website type.
/// The field's label can be set.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_WEBSITE_CUSTOM 708
/// The constant describes a home IM address.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_IM_HOME 801

/// The constant describes a work IM address.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_IM_WORK 802

/// The constant describes a different IM address type.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_IM_OTHER 803

/// The constant describes a custom IM address type.
/// The field's label can be set.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_IM_CUSTOM 804
/// The constant describes a mother relation.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_MOTHER 901

/// The constant describes a father relation.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_FATHER 902

/// The constant describes a parent relation.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_PARENT 903

/// The constant describes a sister relation.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_SISTER 904

/// The constant describes a brother relation.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_BROTHER 905

/// The constant describes a child relation.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_CHILD 906

/// The constant describes a friend relation.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_FRIEND 907

/// The constant describes a spouse relation.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_SPOUSE 908

/// The constant describes a partner relation.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_PARTNER 909

/// The constant describes a manager relation.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_MANAGER 910

/// The constant describes a assistant relation.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_ASSISTANT 911

/// The constant describes a domestic partner relation.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_DOMESTIC_PARTNER 912

/// The constant describes a referred by relation.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_REFERRED_BY 913

/// The constant describes a relative relation.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_RELATIVE 914

/// The constant describes a custom relation type.
/// The field's label can be set.
/// Not available on iOS.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_RELATION_CUSTOM 915
/// The constant describes a work organization.
/// Not available on iOS.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_ORG_INFO_WORK 1001

/// The constant describes a different organization type.
/// Not available on iOS.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_ORG_INFO_OTHER 1002

/// The constant describes a custom organization type.
/// The field's label can be set.
/// Not available on iOS.
/** @ingroup PIMConsts */
#define MA_PIM_ATTR_ORG_INFO_CUSTOM 1003
/// The constant describes a preferred field.
/** @ingroup PIMConsts */
#define MA_PIM_ATTRPREFERRED 0x10000
/// No error. The operation completed successfully.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_NONE 0

/// This function is unavailable on the current platform.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_UNAVAILABLE -1

/// The native database's data type for the given field did not match the MoSync API.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_NATIVE_TYPE_MISMATCH -2

/// The specified list type is invalid.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_LIST_TYPE_INVALID -3

/// The specified pim list is not available on the current platform.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_LIST_UNAVAILABLE -4

/// The specified list is already opened.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_LIST_ALREADY_OPENED -5

/// The specified field is invalid.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_FIELD_INVALID -6

/// The field type is not supported.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_FIELD_UNSUPPORTED -7

/// The requested field doesn't have a value.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_FIELD_EMPTY -8

/// More values in this field are not supported.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_FIELD_COUNT_MAX -9

/// The field is read-only.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_FIELD_READ_ONLY -10

/// The field is write-only.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_FIELD_WRITE_ONLY -11

/// The given index is not valid.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_INDEX_INVALID -12

/// Invalid handle.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_HANDLE_INVALID -13

/// The field/attribute combination is not supported.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_ATTRIBUTE_COMBO_UNSUPPORTED -14

/// The values's attribute is not set to custom.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_ATTRIBUTE_CUSTOM -15

/// Invalid buffer structure.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_BUFFER_INVALID -16

/// The value does not have a custom label.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_NO_LABEL -17

/// The operation is not allowed by the Address Book database.
/** @ingroup PIMConsts */
#define MA_PIM_ERR_OPERATION_NOT_PERMITTED -18
/**
* \brief Arguments for PIM functions.
*/
/** @ingroup PIMFunctions */
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MA_PIM_ARGS {
	/// Opened by maPimListNext().
	MAHandle item;

	/// One of the \link #MA_PIM_FIELD_CONTACT_ADDR MA_PIM_FIELD \endlink constants.
	int field;

	/// The address to a buffer, where a value is or will be stored.
	MAAddress buf;

	/// The size of the buffer, in bytes.
	int bufSize;
} MA_PIM_ARGS;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief Opens a PimList. Use maPimListNext() to open the list's items.
* \param listType One of the \link #MA_PIM_CONTACTS MA_PIM \endlink constants.
* \returns \>= 0 A PimList handle.
*          \<  0 on error:
*                    #MA_PIM_ERR_LIST_ALREADY_OPENED if the list is already opened.
*                    #MA_PIM_ERR_LIST_UNAVAILABLE if the list is not available on the current platform.
*                    #MA_PIM_ERR_LIST_TYPE_INVALID if the given list type is invalid.
*/
/** @ingroup PIMFunctions */
IOCTLDEF MAHandle maPimListOpen(int listType) {
	return (MAHandle) maIOCtl(98, listType, 0, 0);
}

/**
* \brief Returns a handle to the next PimItem in the \a list, or 0 if there are no more items,
* or \< 0 on error.
* You must use maPimItemClose() on every item to prevent memory leaks.
* \param list List handle provided by maPimListOpen(int listType).
* Calling this you can only get the name and the phone number when using maPimItemGetValue().
* \returns \> 0 a PimItem handle.
*          \= 0 if there are no more items.
*          \< 0 on error:
*                    #MA_PIM_ERR_HANDLE_INVALID if the list handle is invalid.
*/
/** @ingroup PIMFunctions */
IOCTLDEF MAHandle maPimListNextSummary(MAHandle list) {
	return (MAHandle) maIOCtl(99, list, 0, 0);
}

/**
* \brief Returns a handle to the next PimItem in the \a list, or 0 if there are no more items,
* or \< 0 on error.
* You must use maPimItemClose() on every item to prevent memory leaks.
* \param list List handle provided by maPimListOpen(int listType).
* \returns \> 0 a PimItem handle.
*          \= 0 if there are no more items.
*          \< 0 on error:
*                    #MA_PIM_ERR_HANDLE_INVALID if the list handle is invalid.
*/
/** @ingroup PIMFunctions */
IOCTLDEF MAHandle maPimListNext(MAHandle list) {
	return (MAHandle) maIOCtl(100, list, 0, 0);
}

/**
* \brief Closes a PimList.
* \param list List handle provided by maPimListOpen(int listType).
* \returns #MA_PIM_ERR_NONE on success, or \< 0 on error.
* #MA_PIM_ERR_LIST_NOT_OPENED if the list is not opened.
* #MA_PIM_ERR_UNAVAILABLE_LIST if the list is unavailable.
* #MA_PIM_ERR_INVALID_HANDLE if the list handle is invalid.
* \note This does not close the list's items, but it does invalidate them,
* so that maPimItemClose() is the only function you can safely use on them.
*/
/** @ingroup PIMFunctions */
IOCTLDEF int maPimListClose(MAHandle list) {
	return (int) maIOCtl(101, list, 0, 0);
}

/**
* \brief Returns the number of fields in the \a item.
* \param item Item handle provided by maPimListNext(MAHandle list).
* \returns \>= 0 the number of fields in the item.
*          \<  0 on error:
*                    #MA_PIM_ERR_HANDLE_INVALID if the item handle is invalid.
*/
/** @ingroup PIMFunctions */
IOCTLDEF int maPimItemCount(MAHandle item) {
	return (int) maIOCtl(102, item, 0, 0);
}

/**
* \brief Returns the field id of the item's n:th field.
* Panics on invalid indices.
* \param item Opened by maPimListNext().
* \param n \>= 0 and \< maPimItemCount().
* \returns \> 0 one of the \link #MA_PIM_FIELD_CONTACT_ADDR MA_PIM_FIELD \endlink constants.
*          \< 0 on error:
*                    #MA_PIM_ERR_HANDLE_INVALID if the item handle is invalid.
*                    #MA_PIM_ERR_INDEX_INVALID if the param n is not valid.
* \note On Android and iOS the panic system can be disabled so you'll get error codes instead.
*/
/** @ingroup PIMFunctions */
IOCTLDEF int maPimItemGetField(MAHandle item, int n) {
	return (int) maIOCtl(103, item, n, 0);
}

/**
* \brief Returns the number of values in the field for a given item.
* \param item Opened by maPimListNext().
* \param field One of the \link #MA_PIM_FIELD_CONTACT_ADDR MA_PIM_FIELD \endlink constants.
* \returns \> 0 the number of values in the field.
*          \= 0 if the item field has no values.
*          \< 0 on error:
*                    #MA_PIM_ERR_HANDLE_INVALID if the item handle is invalid.
*                    #MA_PIM_ERR_FIELD_UNSUPPORTED if the field is unsupported.
*                    #MA_PIM_ERR_FIELD_INVALID if the field is invalid.
*/
/** @ingroup PIMFunctions */
IOCTLDEF int maPimItemFieldCount(MAHandle item, int field) {
	return (int) maIOCtl(104, item, field, 0);
}

/**
* \brief Returns the attribute for the specified value in a field and item.
* Panics on field/index combinations that don't exist in this item.
* \param item Opened by maPimListNext().
* \param field One of the \link #MA_PIM_FIELD_CONTACT_ADDR MA_PIM_FIELD \endlink constants.
* \param index \>= 0 and \< maPimItemFieldCount().
* \returns \> 0 the attribute for the specified field.
*          \= 0 if the field doesn't have attributes.
*          \< 0 on error:
*                    #MA_PIM_ERR_HANDLE_INVALID if the item handle is invalid.
*                    #MA_PIM_ERR_FIELD_INVALID if the field is invalid.
*                    #MA_PIM_ERR_FIELD_UNSUPPORTED if the field type is unsupported.
*                    #MA_PIM_ERR_FIELD_EMPTY if the given field doesn't have values.
*                    #MA_PIM_ERR_INDEX_INVALID if the index is invalid.
* \note On Android and iOS the panic system can be disabled so you'll get error codes instead.
*/
/** @ingroup PIMFunctions */
IOCTLDEF int maPimItemGetAttributes(MAHandle item, int field, int index) {
	return (int) maIOCtl(105, item, field, index);
}

/**
* \brief Sets a custom label for a value in a field and item.
* Panics on field/index combinations that don't exist in this item.
* The value's attribute must be set to custom.
* The label has #MA_PIM_TYPE_STRING and is stored in \a args.buf.
* \a args.bufSize must be valid.
* \param args Common arguments.
* \param index An index into the field's value array.
* This is a number \>= 0 and \< the return value of maPimItemFieldCount().
* \returns           #MA_PIM_ERR_NONE on success.
*                    #MA_PIM_ERR_HANDLE_INVALID if the item handle is invalid.
*                    #MA_PIM_ERR_FIELD_INVALID if the field is invalid.
*                    #MA_PIM_ERR_FIELD_UNSUPPORTED if the field type is unsupported.
*                    #MA_PIM_ERR_FIELD_EMPTY if the given field doesn't have values.
*                    #MA_PIM_ERR_FIELD_READ_ONLY if the field is read-only.
*                    #MA_PIM_ERR_INDEX_INVALID if the index is invalid.
*                    #MA_PIM_ERR_NO_LABEL if the attribute is not set to custom.
* \note This function is available only on Android or iOS.
* \note On Android and iOS the panic system can be disabled so you'll get error codes instead.
*/
/** @ingroup PIMFunctions */
IOCTLDEF int maPimItemSetLabel(const MA_PIM_ARGS* args, int index) {
	return (int) maIOCtl(106, (int)args, index, 0);
}

/**
* Retrieves the custom label for a value in a field and item,
* if the value has a custom label.
* The label has #MA_PIM_TYPE_STRING and is stored in \a args.buf.
* \a args.bufSize must be valid.
* \param args Common arguments.
* \param index An index into the field's value array.
* This is a number \>= 0 and \< the return value of maPimItemFieldCount().
* \returns \>= 0 the number of bytes occupied by the value.
*          \<  0 on error:
*                    #MA_PIM_ERR_HANDLE_INVALID if the item handle is invalid.
*                    #MA_PIM_ERR_FIELD_INVALID if the field is invalid.
*                    #MA_PIM_ERR_FIELD_UNSUPPORTED if the field type is unsupported.
*                    #MA_PIM_ERR_FIELD_EMPTY if the given field doesn't have values.
*                    #MA_PIM_ERR_INDEX_INVALID if the index is invalid.
*                    #MA_PIM_ERR_NO_LABEL if the attribute type is not set to custom.
*                    #MA_PIM_ERR_BUFFER_TOO_SMALL if the size of the value is greaten than bufSize.
* \note This function is available on Android or iOS.
*/
/** @ingroup PIMFunctions */
IOCTLDEF int maPimItemGetLabel(const MA_PIM_ARGS* args, int index) {
	return (int) maIOCtl(107, (int)args, index, 0);
}

/**
* Returns one of the type of the field.
* \param list Opened by maPimListOpen().
* \param field One of the \link #MA_PIM_FIELD_CONTACT_ADDR MA_PIM_FIELD \endlink constants.
* \returns \>= 0 any of the \link #MA_PIM_TYPE_BINARY MA_PIM_TYPE \endlink constants.
*          \<  0 on error:
*                    #MA_PIM_ERR_HANDLE_INVALID if the list handle is invalid.
*                    #MA_PIM_ERR_FIELD_INVALID if the field is invalid.
*                    #MA_PIM_ERR_FIELD_UNSUPPORTED if the field type is unsupported.
*/
/** @ingroup PIMFunctions */
IOCTLDEF int maPimFieldType(MAHandle list, int field) {
	return (int) maIOCtl(108, list, field, 0);
}

/**
* Copies the specified value from a field and item to \a args.buf.
* \param args Common arguments.
* \param index An index into the field's value array.
* This is a number \>= 0 and \< the return value of maPimItemFieldCount().
* \returns \>= 0 The number of bytes occupied by the value.
*          \<  0 on error:
*                    #MA_PIM_ERR_HANDLE_INVALID if the item handle is invalid.
*                    #MA_PIM_ERR_FIELD_INVALID if the field is invalid.
*                    #MA_PIM_ERR_FIELD_UNSUPPORTED if the field type is unsupported.
*                    #MA_PIM_ERR_FIELD_EMPTY if the given field doesn't have values.
*                    #MA_PIM_ERR_INDEX_INVALID if the index is invalid.
*                    #MA_PIM_ERR_FIELD_WRITE_ONLY if the field is write-only.
*/
/** @ingroup PIMFunctions */
IOCTLDEF int maPimItemGetValue(const MA_PIM_ARGS* args, int index) {
	return (int) maIOCtl(109, (int)args, index, 0);
}

/**
* Changes a value and its attributes in a field and item.
* This function cannot be used to add a new value.
* \param args Common arguments.
* \param index An index into the field's value array.
* This is a number \>= 0 and \< the return value of maPimItemFieldCount().
* \param attributes The value's new attributes.
* \returns           #MA_PIM_ERR_NONE on success.
*                    #MA_PIM_ERR_HANDLE_INVALID if the item handle is invalid.
*                    #MA_PIM_ERR_FIELD_INVALID if the field is invalid.
*                    #MA_PIM_ERR_FIELD_UNSUPPORTED if the field type is unsupported.
*                    #MA_PIM_ERR_FIELD_READ_ONLY if the field is read-only.
*                    #MA_PIM_ERR_FIELD_EMPTY if the given field doesn't have values.
*                    #MA_PIM_ERR_INDEX_INVALID if the index is invalid.
*                    #MA_PIM_ERR_ATTRIBUTE_COMBO_UNSUPPORTED if the field/attribute combination is not supported.
*                    #MA_PIM_ERR_BUFFER_INVALID if the buffer is not valid.
* \note The new value is not actually written to disk until
* the item is closed with maPimItemClose(). If the program exits before then,
* the changes are lost.
* \note When setting a value with #MA_PIM_TYPE_STRING_ARRAY, at least one
* string must be present and have a length greater than zero.
* Any surplus strings are ignored.
*/
/** @ingroup PIMFunctions */
IOCTLDEF int maPimItemSetValue(const MA_PIM_ARGS* args, int index, int attributes) {
	return (int) maIOCtl(110, (int)args, index, attributes);
}

/**
* Adds a new value to a field and item.
* \param args Common arguments.
* \param attributes The new value's attributes.
* \returns />= 0 the index of the new added value.
*          /<  0 on error:
*                    #MA_PIM_ERR_HANDLE_INVALID if the item handle is invalid.
*                    #MA_PIM_ERR_FIELD_INVALID if the field is invalid.
*                    #MA_PIM_ERR_FIELD_UNSUPPORTED if the field type is unsupported.
*                    #MA_PIM_ERR_FIELD_READ_ONLY if the field is read-only.
*                    #MA_PIM_ERR_FIELD_COUNT_MAX if more values cannot be added to this field.
*                    #MA_PIM_ERR_ATTRIBUTE_COMBO_UNSUPPORTED if the field/attribute combination is not supported.
*                    #MA_PIM_ERR_BUFFER_INVALID if the buffer is not valid.
* \note The new value is not actually written to disk until
* the item is closed with maPimItemClose(). If the program exits before then,
* the changes are lost.
*/
/** @ingroup PIMFunctions */
IOCTLDEF int maPimItemAddValue(const MA_PIM_ARGS* args, int attributes) {
	return (int) maIOCtl(111, (int)args, attributes, 0);
}

/**
* Removes a value from a field and item.
* \param item Opened by maPimListNext().
* \param field One of the \link #MA_PIM_FIELD_CONTACT_ADDR MA_PIM_FIELD \endlink constants.
* \param index \>= 0 and \< maPimItemFieldCount().
* \returns #MA_PIM_ERR_NONE on success.
*          #MA_PIM_ERR_HANDLE_INVALID if the item handle is invalid.
*          #MA_PIM_ERR_FIELD_INVALID if the field is invalid.
*          #MA_PIM_ERR_FIELD_UNSUPPORTED if the field type is unsupported.
*          #MA_PIM_ERR_FIELD_READ_ONLY if the field is read-only.
*          #MA_PIM_ERR_FIELD_EMPTY if the given field doesn't have values.
*          #MA_PIM_ERR_INDEX_INVALID if the index is invalid.
* \note The changes is not actually written to disk until
* the item is closed with maPimItemClose(). If the program exits before then,
* the changes are lost.
*/
/** @ingroup PIMFunctions */
IOCTLDEF int maPimItemRemoveValue(MAHandle item, int field, int index) {
	return (int) maIOCtl(112, item, field, index);
}

/**
* Closes the handle to a PimItem, releasing resources used by the system.
* Writes any changes to disk.
* \returns #MA_PIM_ERR_NONE on success.
*          #MA_PIM_ERR_HANDLE_INVALID if the item handle is invalid, or if the item's list is closed.
* \note An item can also be closed by maPimItemRemove().
* \warning Does not write changes to disk if the item's List is closed.
* Make sure to keep the List open while editing items.
*/
/** @ingroup PIMFunctions */
IOCTLDEF int maPimItemClose(MAHandle item) {
	return (int) maIOCtl(113, item, 0, 0);
}

/**
* Creates a new empty item in the specified list.
* \returns \>= 0 A handle to the new item.
*          \<  0 on error:
*                    #MA_PIM_ERR_HANDLE_INVALID if the list handle is invalid.
* \note The handle must be closed with maPimItemClose() to avoid memory leaks.
*/
/** @ingroup PIMFunctions */
IOCTLDEF MAHandle maPimItemCreate(MAHandle list) {
	return (MAHandle) maIOCtl(114, list, 0, 0);
}

/**
* Removes an item from a list. This also has the effect of closing the item.
* \see maPimItemClose()
* \returns #MA_PIM_ERR_NONE on success.
*          #MA_PIM_ERR_HANDLE_INVALID if the list handle or item handle are invalid.
* \note If this function fails, the item is not closed.
*/
/** @ingroup PIMFunctions */
IOCTLDEF int maPimItemRemove(MAHandle list, MAHandle item) {
	return (int) maIOCtl(115, list, item, 0);
}

#ifdef __cplusplus
}
#endif

#endif	//IX_PIM_H
