/**************************************************************************************
Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
***************************************************************************************
$Id: OdV3_Results.h 4095 2019-04-04 13:49:12Z Sven $:

Description:
  OdV3_Results.h
**************************************************************************************/

#ifndef __ODV3_RESULTS_H
#define __ODV3_RESULTS_H

#include<stdint.h>

/////////////////////////////////////////////////////////////////////////////////////
// Object Dictionary (revised) error codes
// 0x0000-0x7FFF are used for error codes directly mappable to SDO abort codes by using a translation table
// 0x8000-0xFFFF are used for additional error codes which relate to specific functions within the ObjDict
/////////////////////////////////////////////////////////////////////////////////////
//
// MessageId: ERR_ODV3_PROTOCOL_TIMEOUT
//
// MessageText:
//
// SDO Protocol Timeout.
//
#define ERR_ODV3_PROTOCOL_TIMEOUT        ((uint32_t)0xC09B0001L)

//
// MessageId: ERR_ODV3_UNSUPPORTED_ACCESS
//
// MessageText:
//
// Unsupported access.
//
#define ERR_ODV3_UNSUPPORTED_ACCESS      ((uint32_t)0xC09B0002L)

//
// MessageId: ERR_ODV3_OBJECT_IS_WRITE_ONLY
//
// MessageText:
//
// Object is write only.
//
#define ERR_ODV3_OBJECT_IS_WRITE_ONLY    ((uint32_t)0xC09B0003L)

//
// MessageId: ERR_ODV3_OBJECT_IS_READ_ONLY
//
// MessageText:
//
// Object is read only.
//
#define ERR_ODV3_OBJECT_IS_READ_ONLY     ((uint32_t)0xC09B0004L)

//
// MessageId: ERR_ODV3_OBJECT_DOES_NOT_EXIST
//
// MessageText:
//
// Object does not exist.
//
#define ERR_ODV3_OBJECT_DOES_NOT_EXIST   ((uint32_t)0xC09B0005L)

//
// MessageId: ERR_ODV3_OBJECT_CANNOT_BE_PDO_MAPPED
//
// MessageText:
//
// Object cannot be mapped into PDO.
//
#define ERR_ODV3_OBJECT_CANNOT_BE_PDO_MAPPED ((uint32_t)0xC09B0006L)

//
// MessageId: ERR_ODV3_OBJECTS_WOULD_EXCEED_PDO_LENGTH
//
// MessageText:
//
// The number and length of the objects to be mapped would exceed the PDO length.
//
#define ERR_ODV3_OBJECTS_WOULD_EXCEED_PDO_LENGTH ((uint32_t)0xC09B0007L)

//
// MessageId: ERR_ODV3_GENERAL_PARAMETER_INCOMPATIBILITY
//
// MessageText:
//
// General parameter incompatibility.
//
#define ERR_ODV3_GENERAL_PARAMETER_INCOMPATIBILITY ((uint32_t)0xC09B0008L)

//
// MessageId: ERR_ODV3_ACCESS_FAILED_DUE_TO_HW_ERROR
//
// MessageText:
//
// Access failed due to hardware error.
//
#define ERR_ODV3_ACCESS_FAILED_DUE_TO_HW_ERROR ((uint32_t)0xC09B0009L)

//
// MessageId: ERR_ODV3_DATATYPE_DOES_NOT_MATCH
//
// MessageText:
//
// Data type does not match, length of service parameter does not match.
//
#define ERR_ODV3_DATATYPE_DOES_NOT_MATCH ((uint32_t)0xC09B000AL)

//
// MessageId: ERR_ODV3_DATATYPE_LENGTH_IS_TOO_LONG
//
// MessageText:
//
// Data type does not match, length of service parameter too high.
//
#define ERR_ODV3_DATATYPE_LENGTH_IS_TOO_LONG ((uint32_t)0xC09B000BL)

//
// MessageId: ERR_ODV3_DATATYPE_LENGTH_IS_TOO_SHORT
//
// MessageText:
//
// Data type does not match, length of service parameter too short.
//
#define ERR_ODV3_DATATYPE_LENGTH_IS_TOO_SHORT ((uint32_t)0xC09B000CL)

//
// MessageId: ERR_ODV3_SUBINDEX_DOES_NOT_EXIST
//
// MessageText:
//
// Subindex does not exist.
//
#define ERR_ODV3_SUBINDEX_DOES_NOT_EXIST ((uint32_t)0xC09B000DL)

//
// MessageId: ERR_ODV3_RANGE_OF_PARAMETER_EXCEEDED
//
// MessageText:
//
// Value range of parameter exceeded.
//
#define ERR_ODV3_RANGE_OF_PARAMETER_EXCEEDED ((uint32_t)0xC09B000EL)

//
// MessageId: ERR_ODV3_VALUE_OF_PARAMETER_WRITTEN_TOO_HIGH
//
// MessageText:
//
// Value of parameter written too high.
//
#define ERR_ODV3_VALUE_OF_PARAMETER_WRITTEN_TOO_HIGH ((uint32_t)0xC09B000FL)

//
// MessageId: ERR_ODV3_VALUE_OF_PARAMETER_WRITTEN_TOO_LOW
//
// MessageText:
//
// Value of parameter written too low.
//
#define ERR_ODV3_VALUE_OF_PARAMETER_WRITTEN_TOO_LOW ((uint32_t)0xC09B0010L)

//
// MessageId: ERR_ODV3_MAXIMUM_VALUE_IS_LESS_THAN_MINIMUM_VALUE
//
// MessageText:
//
// Maximum value is less than minimum value.
//
#define ERR_ODV3_MAXIMUM_VALUE_IS_LESS_THAN_MINIMUM_VALUE ((uint32_t)0xC09B0011L)

//
// MessageId: ERR_ODV3_GENERAL_ERROR
//
// MessageText:
//
// General error.
//
#define ERR_ODV3_GENERAL_ERROR           ((uint32_t)0xC09B0012L)

//
// MessageId: ERR_ODV3_DATA_CANNOT_BE_TRANSFERRED_OR_STORED_TO_THE_APP
//
// MessageText:
//
// Data cannot be transferred or stored to the application.
//
#define ERR_ODV3_DATA_CANNOT_BE_TRANSFERRED_OR_STORED_TO_THE_APP ((uint32_t)0xC09B0013L)

//
// MessageId: ERR_ODV3_DATA_NO_TRANSFER_DUE_TO_LOCAL_CONTROL
//
// MessageText:
//
// Data cannot be transferred or stored to the application because of local control.
//
#define ERR_ODV3_DATA_NO_TRANSFER_DUE_TO_LOCAL_CONTROL ((uint32_t)0xC09B0014L)

//
// MessageId: ERR_ODV3_DATA_NO_TRANSFER_DUE_TO_PRESENT_DEVICE_STATE
//
// MessageText:
//
// Data cannot be transferred or stored to the application because of present device state.
//
#define ERR_ODV3_DATA_NO_TRANSFER_DUE_TO_PRESENT_DEVICE_STATE ((uint32_t)0xC09B0015L)

//
// MessageId: ERR_ODV3_NO_OBJECT_DICTIONARY_PRESENT
//
// MessageText:
//
// Object dictionary dynamic generation fails or no object dictionary present.
//
#define ERR_ODV3_NO_OBJECT_DICTIONARY_PRESENT ((uint32_t)0xC09B0016L)

//
// MessageId: ERR_ODV3_GENERAL_INTERNAL_INCOMPATIBILITY
//
// MessageText:
//
// General internal incompatibility.
//
#define ERR_ODV3_GENERAL_INTERNAL_INCOMPATIBILITY ((uint32_t)0xC09B0017L)

//
// MessageId: ERR_ODV3_ALL_BY_INDEX_UNSUPPORTED
//
// MessageText:
//
// Access via AllByIndex unsupported.
//
#define ERR_ODV3_ALL_BY_INDEX_UNSUPPORTED ((uint32_t)0xC09B0018L)

// 0x8000-0xFFFF ObjDict range
//
// MessageId: ERR_ODV3_DELETION_LOCKED
//
// MessageText:
//
// Deletion is locked.
//
#define ERR_ODV3_DELETION_LOCKED         ((uint32_t)0xC09B8000L)

//
// MessageId: ERR_ODV3_OTHER_TASK_HAS_LOCKED_DELETION
//
// MessageText:
//
// Other task has locked deletion.
//
#define ERR_ODV3_OTHER_TASK_HAS_LOCKED_DELETION ((uint32_t)0xC09B8001L)

//
// MessageId: ERR_ODV3_ONLY_ONE_READ_NOTIFY_ALLOWED
//
// MessageText:
//
// Only one read notify allowed.
//
#define ERR_ODV3_ONLY_ONE_READ_NOTIFY_ALLOWED ((uint32_t)0xC09B8002L)

//
// MessageId: ERR_ODV3_APPLICATION_NOT_REGISTERED
//
// MessageText:
//
// Application task is not registered.
//
#define ERR_ODV3_APPLICATION_NOT_REGISTERED ((uint32_t)0xC09B8003L)

//
// MessageId: ERR_ODV3_UNFRAGMENTABLE_PART_DOES_NOT_MATCH_SRCID
//
// MessageText:
//
// Unfragmentable part of packet does not match SrcId.
//
#define ERR_ODV3_UNFRAGMENTABLE_PART_DOES_NOT_MATCH_SRCID ((uint32_t)0xC09B8004L)

//
// MessageId: ERR_ODV3_UNFRAGMENTABLE_PART_DOES_NOT_MATCH_DESTID
//
// MessageText:
//
// Unfragmentable part of packet does not match DestId.
//
#define ERR_ODV3_UNFRAGMENTABLE_PART_DOES_NOT_MATCH_DESTID ((uint32_t)0xC09B8005L)

//
// MessageId: ERR_ODV3_SRCID_DOES_NOT_MATCH_ANY_FRAGMENTATION_BUFFER
//
// MessageText:
//
// SrcId does not match any fragmentation buffer.
//
#define ERR_ODV3_SRCID_DOES_NOT_MATCH_ANY_FRAGMENTATION_BUFFER ((uint32_t)0xC09B8006L)

//
// MessageId: ERR_ODV3_DESTID_DOES_NOT_MATCH_ANY_FRAGMENTATION_BUFFER
//
// MessageText:
//
// DestId does not match any fragmentation buffer.
//
#define ERR_ODV3_DESTID_DOES_NOT_MATCH_ANY_FRAGMENTATION_BUFFER ((uint32_t)0xC09B8007L)

//
// MessageId: ERR_ODV3_OBJECT_WAS_DELETED_IN_ACTION
//
// MessageText:
//
// Object was deleted in action.
//
#define ERR_ODV3_OBJECT_WAS_DELETED_IN_ACTION ((uint32_t)0xC09B8008L)

//
// MessageId: ERR_ODV3_SUBOBJECT_WAS_DELETED_IN_ACTION
//
// MessageText:
//
// Subobject was deleted in action.
//
#define ERR_ODV3_SUBOBJECT_WAS_DELETED_IN_ACTION ((uint32_t)0xC09B8009L)

//
// MessageId: ERR_ODV3_REQUEST_ABORTED
//
// MessageText:
//
// Request aborted.
//
#define ERR_ODV3_REQUEST_ABORTED         ((uint32_t)0xC09B800AL)

//
// MessageId: ERR_ODV3_VALUE_INFO_ONLY_SUPPORTED_ON_SIMPLE_VAR
//
// MessageText:
//
// Given bValueInfo is only supported on SimpleVar.
//
#define ERR_ODV3_VALUE_INFO_ONLY_SUPPORTED_ON_SIMPLE_VAR ((uint32_t)0xC09B800BL)

//
// MessageId: ERR_ODV3_DATATYPE_UNDEFINED
//
// MessageText:
//
// Data type is undefined.
//
#define ERR_ODV3_DATATYPE_UNDEFINED      ((uint32_t)0xC09B800CL)

//
// MessageId: ERR_ODV3_OTHER_APPLICATION_REGISTERED
//
// MessageText:
//
// Other application is already registered.
//
#define ERR_ODV3_OTHER_APPLICATION_REGISTERED ((uint32_t)0xC09B800DL)

//
// MessageId: ERR_ODV3_DATATYPE_ALREADY_EXISTS
//
// MessageText:
//
// CANopen data type already exists.
//
#define ERR_ODV3_DATATYPE_ALREADY_EXISTS ((uint32_t)0xC09B800EL)

//
// MessageId: ERR_ODV3_DATATYPE_DOES_NOT_EXIST
//
// MessageText:
//
// CANopen data type does not exist.
//
#define ERR_ODV3_DATATYPE_DOES_NOT_EXIST ((uint32_t)0xC09B800FL)

//
// MessageId: ERR_ODV3_VIRTUAL_OBJECT_CANNOT_BE_ACCESSED_WITHOUT_INDICATION
//
// MessageText:
//
// Virtual object cannot be accessed without indication.
//
#define ERR_ODV3_VIRTUAL_OBJECT_CANNOT_BE_ACCESSED_WITHOUT_INDICATION ((uint32_t)0xC09B8010L)

//
// MessageId: ERR_ODV3_FRAGMENTATION_IMPOSSIBLE
//
// MessageText:
//
// Fragmentation impossible.
//
#define ERR_ODV3_FRAGMENTATION_IMPOSSIBLE ((uint32_t)0xC09B8011L)

//
// MessageId: ERR_ODV3_ACCESS_VIA_UNDEFINED_NOTIFY_DENIED
//
// MessageText:
//
// Access via undefined notify denied.
//
#define ERR_ODV3_ACCESS_VIA_UNDEFINED_NOTIFY_DENIED ((uint32_t)0xC09B8012L)

//
// MessageId: ERR_ODV3_OBJECT_ALREADY_EXISTS
//
// MessageText:
//
// Object already exists.
//
#define ERR_ODV3_OBJECT_ALREADY_EXISTS   ((uint32_t)0xC09B8013L)

//
// MessageId: ERR_ODV3_SUBOBJECT_ALREADY_EXISTS
//
// MessageText:
//
// Subobject already exists.
//
#define ERR_ODV3_SUBOBJECT_ALREADY_EXISTS ((uint32_t)0xC09B8014L)

//
// MessageId: ERR_ODV3_CANNOT_BE_DELETED_NOT_OWNER
//
// MessageText:
//
// Object/Subobject cannot be deleted. Requester is not owner.
//
#define ERR_ODV3_CANNOT_BE_DELETED_NOT_OWNER ((uint32_t)0xC09B8015L)

//
// MessageId: ERR_ODV3_MAX_NUMBER_OF_SUBOBJECTS_EXCEEDED
//
// MessageText:
//
// Maximum number of subobjects exceeded.
//
#define ERR_ODV3_MAX_NUMBER_OF_SUBOBJECTS_EXCEEDED ((uint32_t)0xC09B8016L)

//
// MessageId: ERR_ODV3_HAS_NO_DEFAULT_VALUE
//
// MessageText:
//
// Has no default value.
//
#define ERR_ODV3_HAS_NO_DEFAULT_VALUE    ((uint32_t)0xC09B8017L)

//
// MessageId: ERR_ODV3_INDICATION_FLAGS_NOT_ALLOWED
//
// MessageText:
//
// Indication flags not allowed.
//
#define ERR_ODV3_INDICATION_FLAGS_NOT_ALLOWED ((uint32_t)0xC09B8018L)

//
// MessageId: ERR_ODV3_INDICATION_FLAGS_NOT_SUPPORTED
//
// MessageText:
//
// Indication flags not supported.
//
#define ERR_ODV3_INDICATION_FLAGS_NOT_SUPPORTED ((uint32_t)0xC09B8019L)

//
// MessageId: ERR_ODV3_ONLY_ONE_RW_UNDEFINED_SUBOBJ_NOTIFY_ALLOWED
//
// MessageText:
//
// Only one read/write notify for non-existing subobject notify allowed.
//
#define ERR_ODV3_ONLY_ONE_RW_UNDEFINED_SUBOBJ_NOTIFY_ALLOWED ((uint32_t)0xC09B801AL)

//
// MessageId: ERR_ODV3_ONLY_ONE_INFO_UNDEFINED_SUBOBJ_NOTIFY_ALLOWED
//
// MessageText:
//
// Only one info notify for non-existing subobject notify allowed.
//
#define ERR_ODV3_ONLY_ONE_INFO_UNDEFINED_SUBOBJ_NOTIFY_ALLOWED ((uint32_t)0xC09B801BL)

//
// MessageId: ERR_ODV3_CREATION_NOT_COMPLETED
//
// MessageText:
//
// Running creation of object/subobjects not yet completed.
//
#define ERR_ODV3_CREATION_NOT_COMPLETED  ((uint32_t)0xC09B801CL)

//
// MessageId: ERR_ODV3_TOTAL_DATA_BYTES_AND_PKT_LEN_MISMATCH
//
// MessageText:
//
// Dependency of total data bytes and packet length not fulfilled.
//
#define ERR_ODV3_TOTAL_DATA_BYTES_AND_PKT_LEN_MISMATCH ((uint32_t)0xC09B801DL)

//
// MessageId: ERR_ODV3_NO_MORE_SUBINDEXES
//
// MessageText:
//
// No more subindex.
//
#define ERR_ODV3_NO_MORE_SUBINDEXES      ((uint32_t)0xC09B801EL)

//
// MessageId: ERR_ODV3_VIRTUAL_CANNOT_BE_COMBINED_WITH_INITIAL_VALUE
//
// MessageText:
//
// Virtual cannot be combined with initial value.
//
#define ERR_ODV3_VIRTUAL_CANNOT_BE_COMBINED_WITH_INITIAL_VALUE ((uint32_t)0xC09B801FL)

//
// MessageId: ERR_ODV3_ALL_BY_INDEX_NOT_POSSIBLE_DUE_ACCESS_RIGHTS
//
// MessageText:
//
// AllByIndex not possible due access rights.
//
#define ERR_ODV3_ALL_BY_INDEX_NOT_POSSIBLE_DUE_ACCESS_RIGHTS ((uint32_t)0xC09B8020L)

//
// MessageId: ERR_ODV3_GET_OBJECT_LIST_INDICATION_NOT_SORTED
//
// MessageText:
//
// GetObjectList indication not sorted.
//
#define ERR_ODV3_GET_OBJECT_LIST_INDICATION_NOT_SORTED ((uint32_t)0xC09B8021L)

//
// MessageId: ERR_ODV3_GET_OBJECT_LIST_DOUBLE_OBJECT_PRESENTED
//
// MessageText:
//
// GetObjectList double object presented.
//
#define ERR_ODV3_GET_OBJECT_LIST_DOUBLE_OBJECT_PRESENTED ((uint32_t)0xC09B8022L)

//
// MessageId: ERR_ODV3_MUTEX_INIT_ERROR
//
// MessageText:
//
// Mutex init error.
//
#define ERR_ODV3_MUTEX_INIT_ERROR        ((uint32_t)0xC09BE000L)

//
// MessageId: ERR_ODV3_SEMAPHORE_INIT_ERROR
//
// MessageText:
//
// Semaphore init error.
//
#define ERR_ODV3_SEMAPHORE_INIT_ERROR    ((uint32_t)0xC09BE001L)

//
// MessageId: ERR_ODV3_TASK_INIT_ERROR
//
// MessageText:
//
// Task init error.
//
#define ERR_ODV3_TASK_INIT_ERROR         ((uint32_t)0xC09BE002L)

//
// MessageId: ERR_ODV3_IS_SHUTTING_DOWN
//
// MessageText:
//
// Is Shutting Down.
//
#define ERR_ODV3_IS_SHUTTING_DOWN        ((uint32_t)0xC09BE003L)

//
// MessageId: ERR_ODV3_REQUEST_DESTINATION_PROBLEM
//
// MessageText:
//
// Request destination problem.
//
#define ERR_ODV3_REQUEST_DESTINATION_PROBLEM ((uint32_t)0xC09BE004L)

//
// MessageId: ERR_ODV3_UNALLOWED_CALLBACK_COMBINATION
//
// MessageText:
//
// Unallowed callback combination.
//
#define ERR_ODV3_UNALLOWED_CALLBACK_COMBINATION ((uint32_t)0xC09BE005L)

//
// MessageId: ERR_ODV3_INVALID_TRANSFER_HANDLE
//
// MessageText:
//
// Invalid transfer handle.
//
#define ERR_ODV3_INVALID_TRANSFER_HANDLE ((uint32_t)0xC09BE006L)

//
// MessageId: ERR_ODV3_MAX_FIELD_LENGTH_EXCEEDS_LIMITS
//
// MessageText:
//
// Max field length exceeds limits.
//
#define ERR_ODV3_MAX_FIELD_LENGTH_EXCEEDS_LIMITS ((uint32_t)0xC09BE800L)

//
// MessageId: ERR_ODV3_INVALID_DATATYPE_SPECIFIED
//
// MessageText:
//
// Invalid datatype specified.
//
#define ERR_ODV3_INVALID_DATATYPE_SPECIFIED ((uint32_t)0xC09BE801L)

//
// MessageId: ERR_ODV3_NOT_ALLOWED_VALUE_INFO_COMBINATION
//
// MessageText:
//
// Not allowed value info combination.
//
#define ERR_ODV3_NOT_ALLOWED_VALUE_INFO_COMBINATION ((uint32_t)0xC09BE802L)

//
// MessageId: ERR_ODV3_EXTRA_PADDING_NOT_ALLOWED_IN_DATA
//
// MessageText:
//
// Extra padding not allowed in data.
//
#define ERR_ODV3_EXTRA_PADDING_NOT_ALLOWED_IN_DATA ((uint32_t)0xC09BE803L)

//
// MessageId: ERR_ODV3_INVALID_PARAMETER_MINIMUM_VALUE
//
// MessageText:
//
// Invalid parameter: Minimum value.
//
#define ERR_ODV3_INVALID_PARAMETER_MINIMUM_VALUE ((uint32_t)0xC09BE804L)

//
// MessageId: ERR_ODV3_INVALID_PARAMETER_MAXIMUM_VALUE
//
// MessageText:
//
// Invalid parameter: Maximum value.
//
#define ERR_ODV3_INVALID_PARAMETER_MAXIMUM_VALUE ((uint32_t)0xC09BE805L)

//
// MessageId: ERR_ODV3_INVALID_PARAMETER_INITIAL_VALUE
//
// MessageText:
//
// Invalid parameter: Initial value.
//
#define ERR_ODV3_INVALID_PARAMETER_INITIAL_VALUE ((uint32_t)0xC09BE806L)

//
// MessageId: ERR_ODV3_INVALID_PARAMETER_DEFAULT_VALUE
//
// MessageText:
//
// Invalid parameter: Default value.
//
#define ERR_ODV3_INVALID_PARAMETER_DEFAULT_VALUE ((uint32_t)0xC09BE807L)

//
// MessageId: ERR_ODV3_MISSING_DATA
//
// MessageText:
//
// Missing data.
//
#define ERR_ODV3_MISSING_DATA            ((uint32_t)0xC09BE808L)

//
// MessageId: ERR_ODV3_MAX_SUBINDEX_SMALLER_ACTUAL_SUBINDEX
//
// MessageText:
//
// Maximum subindex is smaller than actual subindex.
//
#define ERR_ODV3_MAX_SUBINDEX_SMALLER_ACTUAL_SUBINDEX ((uint32_t)0xC09BE809L)

//
// MessageId: ERR_ODV3_DATA_SEGMENT_EXCEEDS_REMAINING_EXPECTED_BYTES
//
// MessageText:
//
// Data segment exceeds remaining expected bytes.
//
#define ERR_ODV3_DATA_SEGMENT_EXCEEDS_REMAINING_EXPECTED_BYTES ((uint32_t)0xC09BE80AL)

//
// MessageId: ERR_ODV3_INVALID_PARAMETER_NAME
//
// MessageText:
//
// Invalid parameter: Name.
//
#define ERR_ODV3_INVALID_PARAMETER_NAME  ((uint32_t)0xC09BE80BL)

//
// MessageId: ERR_ODV3_INVALID_PARAMETER_ECAT_UNIT
//
// MessageText:
//
// Invalid parameter: EtherCAT Unit.
//
#define ERR_ODV3_INVALID_PARAMETER_ECAT_UNIT ((uint32_t)0xC09BE80CL)

//
// MessageId: ERR_ODV3_MISSING_PARAMETER_MINIMUM_VALUE
//
// MessageText:
//
// Missing parameter: Minimum value.
//
#define ERR_ODV3_MISSING_PARAMETER_MINIMUM_VALUE ((uint32_t)0xC09BE80DL)

//
// MessageId: ERR_ODV3_MISSING_PARAMETER_MAXIMUM_VALUE
//
// MessageText:
//
// Missing parameter: Maximum value.
//
#define ERR_ODV3_MISSING_PARAMETER_MAXIMUM_VALUE ((uint32_t)0xC09BE80EL)

//
// MessageId: ERR_ODV3_MISSING_PARAMETER_INITIAL_VALUE
//
// MessageText:
//
// Missing parameter: Initial value.
//
#define ERR_ODV3_MISSING_PARAMETER_INITIAL_VALUE ((uint32_t)0xC09BE80FL)

//
// MessageId: ERR_ODV3_MISSING_PARAMETER_DEFAULT_VALUE
//
// MessageText:
//
// Missing parameter: Default value.
//
#define ERR_ODV3_MISSING_PARAMETER_DEFAULT_VALUE ((uint32_t)0xC09BE810L)

//
// MessageId: ERR_ODV3_MISSING_PARAMETER_NAME
//
// MessageText:
//
// Missing parameter: Name.
//
#define ERR_ODV3_MISSING_PARAMETER_NAME  ((uint32_t)0xC09BE811L)

//
// MessageId: ERR_ODV3_MISSING_PARAMETER_ECAT_UNIT
//
// MessageText:
//
// Missing parameter: EtherCAT Unit.
//
#define ERR_ODV3_MISSING_PARAMETER_ECAT_UNIT ((uint32_t)0xC09BE812L)

//
// MessageId: ERR_ODV3_BUSY_WITH_PREVIOUS_SEGMENT
//
// MessageText:
//
// Busy with previous segment.
//
#define ERR_ODV3_BUSY_WITH_PREVIOUS_SEGMENT ((uint32_t)0xC09BE813L)

//
// MessageId: ERR_ODV3_TRANSFER_ABORTED
//
// MessageText:
//
// Transfer aborted.
//
#define ERR_ODV3_TRANSFER_ABORTED        ((uint32_t)0xC09BE814L)

//
// MessageId: ERR_ODV3_MAX_TOTAL_DATA_BYTES_SMALLER_THAN_ACTUAL_TOTAL_DATA_BYTES
//
// MessageText:
//
// Max total data bytes smaller than actual total data bytes.
//
#define ERR_ODV3_MAX_TOTAL_DATA_BYTES_SMALLER_THAN_ACTUAL_TOTAL_DATA_BYTES ((uint32_t)0xC09BE815L)

//
// MessageId: ERR_ODV3_INDICATION_DESTINATION_PROBLEM
//
// MessageText:
//
// Indication destination problem.
//
#define ERR_ODV3_INDICATION_DESTINATION_PROBLEM ((uint32_t)0xC09BE816L)

//
// MessageId: ERR_ODV3_START_SUBINDEX_OUT_OF_RANGE
//
// MessageText:
//
// Start subindex out of range.
//
#define ERR_ODV3_START_SUBINDEX_OUT_OF_RANGE ((uint32_t)0xC09BE817L)

//
// MessageId: ERR_ODV3_POOL_OUT_OF_PACKET
//
// MessageText:
//
// Pool out of packet.
//
#define ERR_ODV3_POOL_OUT_OF_PACKET      ((uint32_t)0xC09BE818L)

 /* Unexpected Errors (if happening, notify support) */
//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_000
//
// MessageText:
//
// Unexpected Error (0xF000)
//
#define ERR_ODV3_UNEXPECTED_ERROR_000    ((uint32_t)0xC09BF000L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_001
//
// MessageText:
//
// Unexpected Error (0xF001)
//
#define ERR_ODV3_UNEXPECTED_ERROR_001    ((uint32_t)0xC09BF001L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_002
//
// MessageText:
//
// Unexpected Error (0xF002)
//
#define ERR_ODV3_UNEXPECTED_ERROR_002    ((uint32_t)0xC09BF002L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_003
//
// MessageText:
//
// Unexpected Error (0xF003)
//
#define ERR_ODV3_UNEXPECTED_ERROR_003    ((uint32_t)0xC09BF003L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_004
//
// MessageText:
//
// Unexpected Error (0xF004)
//
#define ERR_ODV3_UNEXPECTED_ERROR_004    ((uint32_t)0xC09BF004L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_005
//
// MessageText:
//
// Unexpected Error (0xF005)
//
#define ERR_ODV3_UNEXPECTED_ERROR_005    ((uint32_t)0xC09BF005L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_006
//
// MessageText:
//
// Unexpected Error (0xF006)
//
#define ERR_ODV3_UNEXPECTED_ERROR_006    ((uint32_t)0xC09BF006L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_007
//
// MessageText:
//
// Unexpected Error (0xF007)
//
#define ERR_ODV3_UNEXPECTED_ERROR_007    ((uint32_t)0xC09BF007L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_008
//
// MessageText:
//
// Unexpected Error (0xF008)
//
#define ERR_ODV3_UNEXPECTED_ERROR_008    ((uint32_t)0xC09BF008L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_009
//
// MessageText:
//
// Unexpected Error (0xF009)
//
#define ERR_ODV3_UNEXPECTED_ERROR_009    ((uint32_t)0xC09BF009L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_00A
//
// MessageText:
//
// Unexpected Error (0xF00A)
//
#define ERR_ODV3_UNEXPECTED_ERROR_00A    ((uint32_t)0xC09BF00AL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_00B
//
// MessageText:
//
// Unexpected Error (0xF00B)
//
#define ERR_ODV3_UNEXPECTED_ERROR_00B    ((uint32_t)0xC09BF00BL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_00C
//
// MessageText:
//
// Unexpected Error (0xF00C)
//
#define ERR_ODV3_UNEXPECTED_ERROR_00C    ((uint32_t)0xC09BF00CL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_00D
//
// MessageText:
//
// Unexpected Error (0xF00D)
//
#define ERR_ODV3_UNEXPECTED_ERROR_00D    ((uint32_t)0xC09BF00DL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_00E
//
// MessageText:
//
// Unexpected Error (0xF00E)
//
#define ERR_ODV3_UNEXPECTED_ERROR_00E    ((uint32_t)0xC09BF00EL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_00F
//
// MessageText:
//
// Unexpected Error (0xF00F)
//
#define ERR_ODV3_UNEXPECTED_ERROR_00F    ((uint32_t)0xC09BF00FL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_010
//
// MessageText:
//
// Unexpected Error (0xF010)
//
#define ERR_ODV3_UNEXPECTED_ERROR_010    ((uint32_t)0xC09BF010L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_011
//
// MessageText:
//
// Unexpected Error (0xF011)
//
#define ERR_ODV3_UNEXPECTED_ERROR_011    ((uint32_t)0xC09BF011L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_012
//
// MessageText:
//
// Unexpected Error (0xF012)
//
#define ERR_ODV3_UNEXPECTED_ERROR_012    ((uint32_t)0xC09BF012L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_013
//
// MessageText:
//
// Unexpected Error (0xF013)
//
#define ERR_ODV3_UNEXPECTED_ERROR_013    ((uint32_t)0xC09BF013L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_014
//
// MessageText:
//
// Unexpected Error (0xF014)
//
#define ERR_ODV3_UNEXPECTED_ERROR_014    ((uint32_t)0xC09BF014L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_015
//
// MessageText:
//
// Unexpected Error (0xF015)
//
#define ERR_ODV3_UNEXPECTED_ERROR_015    ((uint32_t)0xC09BF015L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_016
//
// MessageText:
//
// Unexpected Error (0xF016)
//
#define ERR_ODV3_UNEXPECTED_ERROR_016    ((uint32_t)0xC09BF016L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_017
//
// MessageText:
//
// Unexpected Error (0xF017)
//
#define ERR_ODV3_UNEXPECTED_ERROR_017    ((uint32_t)0xC09BF017L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_018
//
// MessageText:
//
// Unexpected Error (0xF018)
//
#define ERR_ODV3_UNEXPECTED_ERROR_018    ((uint32_t)0xC09BF018L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_019
//
// MessageText:
//
// Unexpected Error (0xF019)
//
#define ERR_ODV3_UNEXPECTED_ERROR_019    ((uint32_t)0xC09BF019L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_01A
//
// MessageText:
//
// Unexpected Error (0xF01A)
//
#define ERR_ODV3_UNEXPECTED_ERROR_01A    ((uint32_t)0xC09BF01AL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_01B
//
// MessageText:
//
// Unexpected Error (0xF01B)
//
#define ERR_ODV3_UNEXPECTED_ERROR_01B    ((uint32_t)0xC09BF01BL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_01C
//
// MessageText:
//
// Unexpected Error (0xF01C)
//
#define ERR_ODV3_UNEXPECTED_ERROR_01C    ((uint32_t)0xC09BF01CL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_01D
//
// MessageText:
//
// Unexpected Error (0xF01D)
//
#define ERR_ODV3_UNEXPECTED_ERROR_01D    ((uint32_t)0xC09BF01DL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_01E
//
// MessageText:
//
// Unexpected Error (0xF01E)
//
#define ERR_ODV3_UNEXPECTED_ERROR_01E    ((uint32_t)0xC09BF01EL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_01F
//
// MessageText:
//
// Unexpected Error (0xF01F)
//
#define ERR_ODV3_UNEXPECTED_ERROR_01F    ((uint32_t)0xC09BF01FL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_020
//
// MessageText:
//
// Unexpected Error (0xF020)
//
#define ERR_ODV3_UNEXPECTED_ERROR_020    ((uint32_t)0xC09BF020L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_021
//
// MessageText:
//
// Unexpected Error (0xF021)
//
#define ERR_ODV3_UNEXPECTED_ERROR_021    ((uint32_t)0xC09BF021L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_022
//
// MessageText:
//
// Unexpected Error (0xF022)
//
#define ERR_ODV3_UNEXPECTED_ERROR_022    ((uint32_t)0xC09BF022L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_023
//
// MessageText:
//
// Unexpected Error (0xF023)
//
#define ERR_ODV3_UNEXPECTED_ERROR_023    ((uint32_t)0xC09BF023L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_024
//
// MessageText:
//
// Unexpected Error (0xF024)
//
#define ERR_ODV3_UNEXPECTED_ERROR_024    ((uint32_t)0xC09BF024L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_025
//
// MessageText:
//
// Unexpected Error (0xF025)
//
#define ERR_ODV3_UNEXPECTED_ERROR_025    ((uint32_t)0xC09BF025L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_026
//
// MessageText:
//
// Unexpected Error (0xF026)
//
#define ERR_ODV3_UNEXPECTED_ERROR_026    ((uint32_t)0xC09BF026L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_027
//
// MessageText:
//
// Unexpected Error (0xF027)
//
#define ERR_ODV3_UNEXPECTED_ERROR_027    ((uint32_t)0xC09BF027L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_028
//
// MessageText:
//
// Unexpected Error (0xF028)
//
#define ERR_ODV3_UNEXPECTED_ERROR_028    ((uint32_t)0xC09BF028L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_029
//
// MessageText:
//
// Unexpected Error (0xF029)
//
#define ERR_ODV3_UNEXPECTED_ERROR_029    ((uint32_t)0xC09BF029L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_02A
//
// MessageText:
//
// Unexpected Error (0xF02A)
//
#define ERR_ODV3_UNEXPECTED_ERROR_02A    ((uint32_t)0xC09BF02AL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_02B
//
// MessageText:
//
// Unexpected Error (0xF02B)
//
#define ERR_ODV3_UNEXPECTED_ERROR_02B    ((uint32_t)0xC09BF02BL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_02C
//
// MessageText:
//
// Unexpected Error (0xF02C)
//
#define ERR_ODV3_UNEXPECTED_ERROR_02C    ((uint32_t)0xC09BF02CL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_02D
//
// MessageText:
//
// Unexpected Error (0xF02D)
//
#define ERR_ODV3_UNEXPECTED_ERROR_02D    ((uint32_t)0xC09BF02DL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_02E
//
// MessageText:
//
// Unexpected Error (0xF02E)
//
#define ERR_ODV3_UNEXPECTED_ERROR_02E    ((uint32_t)0xC09BF02EL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_02F
//
// MessageText:
//
// Unexpected Error (0xF02F)
//
#define ERR_ODV3_UNEXPECTED_ERROR_02F    ((uint32_t)0xC09BF02FL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_030
//
// MessageText:
//
// Unexpected Error (0xF030)
//
#define ERR_ODV3_UNEXPECTED_ERROR_030    ((uint32_t)0xC09BF030L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_031
//
// MessageText:
//
// Unexpected Error (0xF031)
//
#define ERR_ODV3_UNEXPECTED_ERROR_031    ((uint32_t)0xC09BF031L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_032
//
// MessageText:
//
// Unexpected Error (0xF032)
//
#define ERR_ODV3_UNEXPECTED_ERROR_032    ((uint32_t)0xC09BF032L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_033
//
// MessageText:
//
// Unexpected Error (0xF033)
//
#define ERR_ODV3_UNEXPECTED_ERROR_033    ((uint32_t)0xC09BF033L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_034
//
// MessageText:
//
// Unexpected Error (0xF034)
//
#define ERR_ODV3_UNEXPECTED_ERROR_034    ((uint32_t)0xC09BF034L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_035
//
// MessageText:
//
// Unexpected Error (0xF035)
//
#define ERR_ODV3_UNEXPECTED_ERROR_035    ((uint32_t)0xC09BF035L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_036
//
// MessageText:
//
// Unexpected Error (0xF036)
//
#define ERR_ODV3_UNEXPECTED_ERROR_036    ((uint32_t)0xC09BF036L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_037
//
// MessageText:
//
// Unexpected Error (0xF037)
//
#define ERR_ODV3_UNEXPECTED_ERROR_037    ((uint32_t)0xC09BF037L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_038
//
// MessageText:
//
// Unexpected Error (0xF038)
//
#define ERR_ODV3_UNEXPECTED_ERROR_038    ((uint32_t)0xC09BF038L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_039
//
// MessageText:
//
// Unexpected Error (0xF039)
//
#define ERR_ODV3_UNEXPECTED_ERROR_039    ((uint32_t)0xC09BF039L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_03A
//
// MessageText:
//
// Unexpected Error (0xF03A)
//
#define ERR_ODV3_UNEXPECTED_ERROR_03A    ((uint32_t)0xC09BF03AL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_03B
//
// MessageText:
//
// Unexpected Error (0xF03B)
//
#define ERR_ODV3_UNEXPECTED_ERROR_03B    ((uint32_t)0xC09BF03BL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_03C
//
// MessageText:
//
// Unexpected Error (0xF03C)
//
#define ERR_ODV3_UNEXPECTED_ERROR_03C    ((uint32_t)0xC09BF03CL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_03D
//
// MessageText:
//
// Unexpected Error (0xF03D)
//
#define ERR_ODV3_UNEXPECTED_ERROR_03D    ((uint32_t)0xC09BF03DL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_03E
//
// MessageText:
//
// Unexpected Error (0xF03E)
//
#define ERR_ODV3_UNEXPECTED_ERROR_03E    ((uint32_t)0xC09BF03EL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_03F
//
// MessageText:
//
// Unexpected Error (0xF03F)
//
#define ERR_ODV3_UNEXPECTED_ERROR_03F    ((uint32_t)0xC09BF03FL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_040
//
// MessageText:
//
// Unexpected Error (0xF040)
//
#define ERR_ODV3_UNEXPECTED_ERROR_040    ((uint32_t)0xC09BF040L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_041
//
// MessageText:
//
// Unexpected Error (0xF041)
//
#define ERR_ODV3_UNEXPECTED_ERROR_041    ((uint32_t)0xC09BF041L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_042
//
// MessageText:
//
// Unexpected Error (0xF042)
//
#define ERR_ODV3_UNEXPECTED_ERROR_042    ((uint32_t)0xC09BF042L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_043
//
// MessageText:
//
// Unexpected Error (0xF043)
//
#define ERR_ODV3_UNEXPECTED_ERROR_043    ((uint32_t)0xC09BF043L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_044
//
// MessageText:
//
// Unexpected Error (0xF044)
//
#define ERR_ODV3_UNEXPECTED_ERROR_044    ((uint32_t)0xC09BF044L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_045
//
// MessageText:
//
// Unexpected Error (0xF045)
//
#define ERR_ODV3_UNEXPECTED_ERROR_045    ((uint32_t)0xC09BF045L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_046
//
// MessageText:
//
// Unexpected Error (0xF046)
//
#define ERR_ODV3_UNEXPECTED_ERROR_046    ((uint32_t)0xC09BF046L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_047
//
// MessageText:
//
// Unexpected Error (0xF047)
//
#define ERR_ODV3_UNEXPECTED_ERROR_047    ((uint32_t)0xC09BF047L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_048
//
// MessageText:
//
// Unexpected Error (0xF048)
//
#define ERR_ODV3_UNEXPECTED_ERROR_048    ((uint32_t)0xC09BF048L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_049
//
// MessageText:
//
// Unexpected Error (0xF049)
//
#define ERR_ODV3_UNEXPECTED_ERROR_049    ((uint32_t)0xC09BF049L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_04A
//
// MessageText:
//
// Unexpected Error (0xF04A)
//
#define ERR_ODV3_UNEXPECTED_ERROR_04A    ((uint32_t)0xC09BF04AL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_04B
//
// MessageText:
//
// Unexpected Error (0xF04B)
//
#define ERR_ODV3_UNEXPECTED_ERROR_04B    ((uint32_t)0xC09BF04BL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_04C
//
// MessageText:
//
// Unexpected Error (0xF04C)
//
#define ERR_ODV3_UNEXPECTED_ERROR_04C    ((uint32_t)0xC09BF04CL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_04D
//
// MessageText:
//
// Unexpected Error (0xF04D)
//
#define ERR_ODV3_UNEXPECTED_ERROR_04D    ((uint32_t)0xC09BF04DL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_04E
//
// MessageText:
//
// Unexpected Error (0xF04E)
//
#define ERR_ODV3_UNEXPECTED_ERROR_04E    ((uint32_t)0xC09BF04EL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_04F
//
// MessageText:
//
// Unexpected Error (0xF04F)
//
#define ERR_ODV3_UNEXPECTED_ERROR_04F    ((uint32_t)0xC09BF04FL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_050
//
// MessageText:
//
// Unexpected Error (0xF050)
//
#define ERR_ODV3_UNEXPECTED_ERROR_050    ((uint32_t)0xC09BF050L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_051
//
// MessageText:
//
// Unexpected Error (0xF051)
//
#define ERR_ODV3_UNEXPECTED_ERROR_051    ((uint32_t)0xC09BF051L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_052
//
// MessageText:
//
// Unexpected Error (0xF052)
//
#define ERR_ODV3_UNEXPECTED_ERROR_052    ((uint32_t)0xC09BF052L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_053
//
// MessageText:
//
// Unexpected Error (0xF053)
//
#define ERR_ODV3_UNEXPECTED_ERROR_053    ((uint32_t)0xC09BF053L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_054
//
// MessageText:
//
// Unexpected Error (0xF054)
//
#define ERR_ODV3_UNEXPECTED_ERROR_054    ((uint32_t)0xC09BF054L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_055
//
// MessageText:
//
// Unexpected Error (0xF055)
//
#define ERR_ODV3_UNEXPECTED_ERROR_055    ((uint32_t)0xC09BF055L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_056
//
// MessageText:
//
// Unexpected Error (0xF056)
//
#define ERR_ODV3_UNEXPECTED_ERROR_056    ((uint32_t)0xC09BF056L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_057
//
// MessageText:
//
// Unexpected Error (0xF057)
//
#define ERR_ODV3_UNEXPECTED_ERROR_057    ((uint32_t)0xC09BF057L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_058
//
// MessageText:
//
// Unexpected Error (0xF058)
//
#define ERR_ODV3_UNEXPECTED_ERROR_058    ((uint32_t)0xC09BF058L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_059
//
// MessageText:
//
// Unexpected Error (0xF059)
//
#define ERR_ODV3_UNEXPECTED_ERROR_059    ((uint32_t)0xC09BF059L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_05A
//
// MessageText:
//
// Unexpected Error (0xF05A)
//
#define ERR_ODV3_UNEXPECTED_ERROR_05A    ((uint32_t)0xC09BF05AL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_05B
//
// MessageText:
//
// Unexpected Error (0xF05B)
//
#define ERR_ODV3_UNEXPECTED_ERROR_05B    ((uint32_t)0xC09BF05BL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_05C
//
// MessageText:
//
// Unexpected Error (0xF05C)
//
#define ERR_ODV3_UNEXPECTED_ERROR_05C    ((uint32_t)0xC09BF05CL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_05D
//
// MessageText:
//
// Unexpected Error (0xF05D)
//
#define ERR_ODV3_UNEXPECTED_ERROR_05D    ((uint32_t)0xC09BF05DL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_05E
//
// MessageText:
//
// Unexpected Error (0xF05E)
//
#define ERR_ODV3_UNEXPECTED_ERROR_05E    ((uint32_t)0xC09BF05EL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_05F
//
// MessageText:
//
// Unexpected Error (0xF05F)
//
#define ERR_ODV3_UNEXPECTED_ERROR_05F    ((uint32_t)0xC09BF05FL)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_060
//
// MessageText:
//
// Unexpected Error (0xF060)
//
#define ERR_ODV3_UNEXPECTED_ERROR_060    ((uint32_t)0xC09BF060L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_061
//
// MessageText:
//
// Unexpected Error (0xF061)
//
#define ERR_ODV3_UNEXPECTED_ERROR_061    ((uint32_t)0xC09BF061L)

//
// MessageId: ERR_ODV3_UNEXPECTED_ERROR_062
//
// MessageText:
//
// Unexpected Error (0xF062)
//
#define ERR_ODV3_UNEXPECTED_ERROR_062    ((uint32_t)0xC09BF062L)

#endif  /* __ODV3_RESULTS_H */
