#pragma once

#include "enums.hpp"
#include "aliases.hpp"
#include "delegates.hpp"
#include <plugin_export.h>

// Generated from s2sdk.pplugin (group: protobuf)

namespace s2sdk {

  using _HookUserMessage = bool (*)(int16_t, UserMessageCallback, HookMode);
}
extern "C" PLUGIN_API s2sdk::_HookUserMessage __s2sdk_HookUserMessage;
namespace s2sdk {
  /**
   * @brief Hooks a user message with a callback.
   * @param messageId (int16): The ID of the message to hook.
   * @param callback (function): The callback function to invoke when the message is received.
   * @param mode (uint8): Whether to hook the message in the post mode (after processing) or pre mode (before processing).
   * @return bool: True if the hook was successfully added, false otherwise.
   */
  inline bool HookUserMessage(int16_t messageId, UserMessageCallback callback, HookMode mode) {
    return __s2sdk_HookUserMessage(messageId, callback, mode);
  }

  using _UnhookUserMessage = bool (*)(int16_t, UserMessageCallback, HookMode);
}
extern "C" PLUGIN_API s2sdk::_UnhookUserMessage __s2sdk_UnhookUserMessage;
namespace s2sdk {
  /**
   * @brief Unhooks a previously hooked user message.
   * @param messageId (int16): The ID of the message to unhook.
   * @param callback (function): The callback function to remove.
   * @param mode (uint8): Whether the hook was in post mode (after processing) or pre mode (before processing).
   * @return bool: True if the hook was successfully removed, false otherwise.
   */
  inline bool UnhookUserMessage(int16_t messageId, UserMessageCallback callback, HookMode mode) {
    return __s2sdk_UnhookUserMessage(messageId, callback, mode);
  }

  using _UserMessageCreateFromSerializable = void* (*)(void*, void*, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_UserMessageCreateFromSerializable __s2sdk_UserMessageCreateFromSerializable;
namespace s2sdk {
  /**
   * @brief Creates a UserMessage from a serializable message.
   * @param msgSerializable (ptr64): The serializable message.
   * @param message (ptr64): The network message.
   * @param recipientMask (uint64): The recipient mask.
   * @return ptr64: A pointer to the newly created UserMessage.
   */
  inline void* UserMessageCreateFromSerializable(void* msgSerializable, void* message, uint64_t recipientMask) {
    return __s2sdk_UserMessageCreateFromSerializable(msgSerializable, message, recipientMask);
  }

  using _UserMessageCreateFromName = void* (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_UserMessageCreateFromName __s2sdk_UserMessageCreateFromName;
namespace s2sdk {
  /**
   * @brief Creates a UserMessage from a message name.
   * @param messageName (string): The name of the message.
   * @return ptr64: A pointer to the newly created UserMessage.
   */
  inline void* UserMessageCreateFromName(const plg::string& messageName) {
    return __s2sdk_UserMessageCreateFromName(messageName);
  }

  using _UserMessageCreateFromId = void* (*)(int16_t);
}
extern "C" PLUGIN_API s2sdk::_UserMessageCreateFromId __s2sdk_UserMessageCreateFromId;
namespace s2sdk {
  /**
   * @brief Creates a UserMessage from a message ID.
   * @param messageId (int16): The ID of the message.
   * @return ptr64: A pointer to the newly created UserMessage.
   */
  inline void* UserMessageCreateFromId(int16_t messageId) {
    return __s2sdk_UserMessageCreateFromId(messageId);
  }

  using _UserMessageDestroy = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_UserMessageDestroy __s2sdk_UserMessageDestroy;
namespace s2sdk {
  /**
   * @brief Destroys a UserMessage and frees its memory.
   * @param userMessage (ptr64): The UserMessage to destroy.
   */
  inline void UserMessageDestroy(void* userMessage) {
    return __s2sdk_UserMessageDestroy(userMessage);
  }

  using _UserMessageSend = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_UserMessageSend __s2sdk_UserMessageSend;
namespace s2sdk {
  /**
   * @brief Sends a UserMessage to the specified recipients.
   * @param userMessage (ptr64): The UserMessage to send.
   */
  inline void UserMessageSend(void* userMessage) {
    return __s2sdk_UserMessageSend(userMessage);
  }

  using _UserMessageGetMessageName = plg::string (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_UserMessageGetMessageName __s2sdk_UserMessageGetMessageName;
namespace s2sdk {
  /**
   * @brief Gets the name of the message.
   * @param userMessage (ptr64): The UserMessage instance.
   * @return string: The name of the message as a string.
   */
  inline plg::string UserMessageGetMessageName(void* userMessage) {
    return __s2sdk_UserMessageGetMessageName(userMessage);
  }

  using _UserMessageGetMessageID = int16_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_UserMessageGetMessageID __s2sdk_UserMessageGetMessageID;
namespace s2sdk {
  /**
   * @brief Gets the ID of the message.
   * @param userMessage (ptr64): The UserMessage instance.
   * @return int16: The ID of the message.
   */
  inline int16_t UserMessageGetMessageID(void* userMessage) {
    return __s2sdk_UserMessageGetMessageID(userMessage);
  }

  using _UserMessageHasField = bool (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_UserMessageHasField __s2sdk_UserMessageHasField;
namespace s2sdk {
  /**
   * @brief Checks if the message has a specific field.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field to check.
   * @return bool: True if the field exists, false otherwise.
   */
  inline bool UserMessageHasField(void* userMessage, const plg::string& fieldName) {
    return __s2sdk_UserMessageHasField(userMessage, fieldName);
  }

  using _UserMessageGetProtobufMessage = void* (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_UserMessageGetProtobufMessage __s2sdk_UserMessageGetProtobufMessage;
namespace s2sdk {
  /**
   * @brief Gets the protobuf message associated with the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @return ptr64: A pointer to the protobuf message.
   */
  inline void* UserMessageGetProtobufMessage(void* userMessage) {
    return __s2sdk_UserMessageGetProtobufMessage(userMessage);
  }

  using _UserMessageGetSerializableMessage = void* (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_UserMessageGetSerializableMessage __s2sdk_UserMessageGetSerializableMessage;
namespace s2sdk {
  /**
   * @brief Gets the serializable message associated with the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @return ptr64: A pointer to the serializable message.
   */
  inline void* UserMessageGetSerializableMessage(void* userMessage) {
    return __s2sdk_UserMessageGetSerializableMessage(userMessage);
  }

  using _UserMessageFindMessageIdByName = int16_t (*)(const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_UserMessageFindMessageIdByName __s2sdk_UserMessageFindMessageIdByName;
namespace s2sdk {
  /**
   * @brief Finds a message ID by its name.
   * @param messageName (string): The name of the message.
   * @return int16: The ID of the message, or 0 if the message was not found.
   */
  inline int16_t UserMessageFindMessageIdByName(const plg::string& messageName) {
    return __s2sdk_UserMessageFindMessageIdByName(messageName);
  }

  using _UserMessageGetRecipientMask = uint64_t (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_UserMessageGetRecipientMask __s2sdk_UserMessageGetRecipientMask;
namespace s2sdk {
  /**
   * @brief Gets the recipient mask for the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @return uint64: The recipient mask.
   */
  inline uint64_t UserMessageGetRecipientMask(void* userMessage) {
    return __s2sdk_UserMessageGetRecipientMask(userMessage);
  }

  using _UserMessageAddRecipient = void (*)(void*, int32_t);
}
extern "C" PLUGIN_API s2sdk::_UserMessageAddRecipient __s2sdk_UserMessageAddRecipient;
namespace s2sdk {
  /**
   * @brief Adds a single recipient (player) to the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param playerSlot (int32): The slot index of the player to add as a recipient.
   */
  inline void UserMessageAddRecipient(void* userMessage, int32_t playerSlot) {
    return __s2sdk_UserMessageAddRecipient(userMessage, playerSlot);
  }

  using _UserMessageAddAllPlayers = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_UserMessageAddAllPlayers __s2sdk_UserMessageAddAllPlayers;
namespace s2sdk {
  /**
   * @brief Adds all connected players as recipients to the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   */
  inline void UserMessageAddAllPlayers(void* userMessage) {
    return __s2sdk_UserMessageAddAllPlayers(userMessage);
  }

  using _UserMessageSetRecipientMask = void (*)(void*, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_UserMessageSetRecipientMask __s2sdk_UserMessageSetRecipientMask;
namespace s2sdk {
  /**
   * @brief Sets the recipient mask for the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param mask (uint64): The recipient mask to set.
   */
  inline void UserMessageSetRecipientMask(void* userMessage, uint64_t mask) {
    return __s2sdk_UserMessageSetRecipientMask(userMessage, mask);
  }

  using _UserMessageRemoveAllRecipient = void (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_UserMessageRemoveAllRecipient __s2sdk_UserMessageRemoveAllRecipient;
namespace s2sdk {
  /**
   * @brief Remove all players UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   */
  inline void UserMessageRemoveAllRecipient(void* userMessage) {
    return __s2sdk_UserMessageRemoveAllRecipient(userMessage);
  }

  using _UserMessageGetRepeatedFieldCount = int32_t (*)(void*, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_UserMessageGetRepeatedFieldCount __s2sdk_UserMessageGetRepeatedFieldCount;
namespace s2sdk {
  /**
   * @brief Gets the count of repeated fields in a field of the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @return int32: The count of repeated fields, or -1 if the field is not repeated or does not exist.
   */
  inline int32_t UserMessageGetRepeatedFieldCount(void* userMessage, const plg::string& fieldName) {
    return __s2sdk_UserMessageGetRepeatedFieldCount(userMessage, fieldName);
  }

  using _UserMessageRemoveRepeatedFieldValue = bool (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_UserMessageRemoveRepeatedFieldValue __s2sdk_UserMessageRemoveRepeatedFieldValue;
namespace s2sdk {
  /**
   * @brief Removes a value from a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the value to remove.
   * @return bool: True if the value was successfully removed, false otherwise.
   */
  inline bool UserMessageRemoveRepeatedFieldValue(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_UserMessageRemoveRepeatedFieldValue(userMessage, fieldName, index);
  }

  using _UserMessageGetDebugString = plg::string (*)(void*);
}
extern "C" PLUGIN_API s2sdk::_UserMessageGetDebugString __s2sdk_UserMessageGetDebugString;
namespace s2sdk {
  /**
   * @brief Gets the debug string representation of the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @return string: The debug string as a string.
   */
  inline plg::string UserMessageGetDebugString(void* userMessage) {
    return __s2sdk_UserMessageGetDebugString(userMessage);
  }

  using _PbReadEnum = int32_t (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadEnum __s2sdk_PbReadEnum;
namespace s2sdk {
  /**
   * @brief Reads an enum value from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return int32: The integer representation of the enum value, or 0 if invalid.
   */
  inline int32_t PbReadEnum(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadEnum(userMessage, fieldName, index);
  }

  using _PbReadInt32 = int32_t (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadInt32 __s2sdk_PbReadInt32;
namespace s2sdk {
  /**
   * @brief Reads a 32-bit integer from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return int32: The int32_t value read, or 0 if invalid.
   */
  inline int32_t PbReadInt32(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadInt32(userMessage, fieldName, index);
  }

  using _PbReadInt64 = int64_t (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadInt64 __s2sdk_PbReadInt64;
namespace s2sdk {
  /**
   * @brief Reads a 64-bit integer from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return int64: The int64_t value read, or 0 if invalid.
   */
  inline int64_t PbReadInt64(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadInt64(userMessage, fieldName, index);
  }

  using _PbReadUInt32 = uint32_t (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadUInt32 __s2sdk_PbReadUInt32;
namespace s2sdk {
  /**
   * @brief Reads an unsigned 32-bit integer from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return uint32: The uint32_t value read, or 0 if invalid.
   */
  inline uint32_t PbReadUInt32(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadUInt32(userMessage, fieldName, index);
  }

  using _PbReadUInt64 = uint64_t (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadUInt64 __s2sdk_PbReadUInt64;
namespace s2sdk {
  /**
   * @brief Reads an unsigned 64-bit integer from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return uint64: The uint64_t value read, or 0 if invalid.
   */
  inline uint64_t PbReadUInt64(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadUInt64(userMessage, fieldName, index);
  }

  using _PbReadFloat = float (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadFloat __s2sdk_PbReadFloat;
namespace s2sdk {
  /**
   * @brief Reads a floating-point value from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return float: The float value read, or 0.0 if invalid.
   */
  inline float PbReadFloat(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadFloat(userMessage, fieldName, index);
  }

  using _PbReadDouble = double (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadDouble __s2sdk_PbReadDouble;
namespace s2sdk {
  /**
   * @brief Reads a double-precision floating-point value from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return double: The double value read, or 0.0 if invalid.
   */
  inline double PbReadDouble(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadDouble(userMessage, fieldName, index);
  }

  using _PbReadBool = bool (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadBool __s2sdk_PbReadBool;
namespace s2sdk {
  /**
   * @brief Reads a boolean value from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return bool: The boolean value read, or false if invalid.
   */
  inline bool PbReadBool(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadBool(userMessage, fieldName, index);
  }

  using _PbReadString = plg::string (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadString __s2sdk_PbReadString;
namespace s2sdk {
  /**
   * @brief Reads a string from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return string: The string value read, or an empty string if invalid.
   */
  inline plg::string PbReadString(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadString(userMessage, fieldName, index);
  }

  using _PbReadColor = plg::vec4 (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadColor __s2sdk_PbReadColor;
namespace s2sdk {
  /**
   * @brief Reads a color value from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return vec4: The color value read, or an empty value if invalid.
   */
  inline plg::vec4 PbReadColor(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadColor(userMessage, fieldName, index);
  }

  using _PbReadVector2 = plg::vec2 (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadVector2 __s2sdk_PbReadVector2;
namespace s2sdk {
  /**
   * @brief Reads a 2D vector from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return vec2: The 2D vector value read, or an empty value if invalid.
   */
  inline plg::vec2 PbReadVector2(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadVector2(userMessage, fieldName, index);
  }

  using _PbReadVector3 = plg::vec3 (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadVector3 __s2sdk_PbReadVector3;
namespace s2sdk {
  /**
   * @brief Reads a 3D vector from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return vec3: The 3D vector value read, or an empty value if invalid.
   */
  inline plg::vec3 PbReadVector3(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadVector3(userMessage, fieldName, index);
  }

  using _PbReadVector4 = plg::vec4 (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadVector4 __s2sdk_PbReadVector4;
namespace s2sdk {
  /**
   * @brief Reads a 4D vector from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return vec4: The 4D vector value read, or an empty value if invalid.
   */
  inline plg::vec4 PbReadVector4(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadVector4(userMessage, fieldName, index);
  }

  using _PbReadQAngle = plg::vec3 (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadQAngle __s2sdk_PbReadQAngle;
namespace s2sdk {
  /**
   * @brief Reads a QAngle (rotation vector) from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return vec3: The QAngle value read, or an empty value if invalid.
   */
  inline plg::vec3 PbReadQAngle(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadQAngle(userMessage, fieldName, index);
  }

  using _PbReadMessage = void* (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbReadMessage __s2sdk_PbReadMessage;
namespace s2sdk {
  /**
   * @brief Reads a Message from a UserMessage.
   * @param userMessage (ptr64): Pointer to the UserMessage object.
   * @param fieldName (string): Name of the field to read.
   * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
   * @return ptr64: The Message value read, or an empty value if invalid.
   */
  inline void* PbReadMessage(void* userMessage, const plg::string& fieldName, int32_t index) {
    return __s2sdk_PbReadMessage(userMessage, fieldName, index);
  }

  using _PbGetEnum = bool (*)(void*, const plg::string&, int32_t&);
}
extern "C" PLUGIN_API s2sdk::_PbGetEnum __s2sdk_PbGetEnum;
namespace s2sdk {
  /**
   * @brief Gets a enum value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (int32&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetEnum(void* userMessage, const plg::string& fieldName, int32_t& out) {
    return __s2sdk_PbGetEnum(userMessage, fieldName, out);
  }

  using _PbSetEnum = bool (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbSetEnum __s2sdk_PbSetEnum;
namespace s2sdk {
  /**
   * @brief Sets a enum value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (int32): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetEnum(void* userMessage, const plg::string& fieldName, int32_t value) {
    return __s2sdk_PbSetEnum(userMessage, fieldName, value);
  }

  using _PbGetInt32 = bool (*)(void*, const plg::string&, int32_t&);
}
extern "C" PLUGIN_API s2sdk::_PbGetInt32 __s2sdk_PbGetInt32;
namespace s2sdk {
  /**
   * @brief Gets a 32-bit integer value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (int32&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetInt32(void* userMessage, const plg::string& fieldName, int32_t& out) {
    return __s2sdk_PbGetInt32(userMessage, fieldName, out);
  }

  using _PbSetInt32 = bool (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbSetInt32 __s2sdk_PbSetInt32;
namespace s2sdk {
  /**
   * @brief Sets a 32-bit integer value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (int32): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetInt32(void* userMessage, const plg::string& fieldName, int32_t value) {
    return __s2sdk_PbSetInt32(userMessage, fieldName, value);
  }

  using _PbGetInt64 = bool (*)(void*, const plg::string&, int64_t&);
}
extern "C" PLUGIN_API s2sdk::_PbGetInt64 __s2sdk_PbGetInt64;
namespace s2sdk {
  /**
   * @brief Gets a 64-bit integer value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (int64&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetInt64(void* userMessage, const plg::string& fieldName, int64_t& out) {
    return __s2sdk_PbGetInt64(userMessage, fieldName, out);
  }

  using _PbSetInt64 = bool (*)(void*, const plg::string&, int64_t);
}
extern "C" PLUGIN_API s2sdk::_PbSetInt64 __s2sdk_PbSetInt64;
namespace s2sdk {
  /**
   * @brief Sets a 64-bit integer value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (int64): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetInt64(void* userMessage, const plg::string& fieldName, int64_t value) {
    return __s2sdk_PbSetInt64(userMessage, fieldName, value);
  }

  using _PbGetUInt32 = bool (*)(void*, const plg::string&, uint32_t&);
}
extern "C" PLUGIN_API s2sdk::_PbGetUInt32 __s2sdk_PbGetUInt32;
namespace s2sdk {
  /**
   * @brief Gets an unsigned 32-bit integer value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (uint32&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetUInt32(void* userMessage, const plg::string& fieldName, uint32_t& out) {
    return __s2sdk_PbGetUInt32(userMessage, fieldName, out);
  }

  using _PbSetUInt32 = bool (*)(void*, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_PbSetUInt32 __s2sdk_PbSetUInt32;
namespace s2sdk {
  /**
   * @brief Sets an unsigned 32-bit integer value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (uint32): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetUInt32(void* userMessage, const plg::string& fieldName, uint32_t value) {
    return __s2sdk_PbSetUInt32(userMessage, fieldName, value);
  }

  using _PbGetUInt64 = bool (*)(void*, const plg::string&, uint64_t&);
}
extern "C" PLUGIN_API s2sdk::_PbGetUInt64 __s2sdk_PbGetUInt64;
namespace s2sdk {
  /**
   * @brief Gets an unsigned 64-bit integer value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (uint64&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetUInt64(void* userMessage, const plg::string& fieldName, uint64_t& out) {
    return __s2sdk_PbGetUInt64(userMessage, fieldName, out);
  }

  using _PbSetUInt64 = bool (*)(void*, const plg::string&, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_PbSetUInt64 __s2sdk_PbSetUInt64;
namespace s2sdk {
  /**
   * @brief Sets an unsigned 64-bit integer value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (uint64): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetUInt64(void* userMessage, const plg::string& fieldName, uint64_t value) {
    return __s2sdk_PbSetUInt64(userMessage, fieldName, value);
  }

  using _PbGetBool = bool (*)(void*, const plg::string&, bool&);
}
extern "C" PLUGIN_API s2sdk::_PbGetBool __s2sdk_PbGetBool;
namespace s2sdk {
  /**
   * @brief Gets a bool value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (bool&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetBool(void* userMessage, const plg::string& fieldName, bool& out) {
    return __s2sdk_PbGetBool(userMessage, fieldName, out);
  }

  using _PbSetBool = bool (*)(void*, const plg::string&, bool);
}
extern "C" PLUGIN_API s2sdk::_PbSetBool __s2sdk_PbSetBool;
namespace s2sdk {
  /**
   * @brief Sets a bool value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (bool): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetBool(void* userMessage, const plg::string& fieldName, bool value) {
    return __s2sdk_PbSetBool(userMessage, fieldName, value);
  }

  using _PbGetFloat = bool (*)(void*, const plg::string&, float&);
}
extern "C" PLUGIN_API s2sdk::_PbGetFloat __s2sdk_PbGetFloat;
namespace s2sdk {
  /**
   * @brief Gets a float value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (float&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetFloat(void* userMessage, const plg::string& fieldName, float& out) {
    return __s2sdk_PbGetFloat(userMessage, fieldName, out);
  }

  using _PbSetFloat = bool (*)(void*, const plg::string&, float);
}
extern "C" PLUGIN_API s2sdk::_PbSetFloat __s2sdk_PbSetFloat;
namespace s2sdk {
  /**
   * @brief Sets a float value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (float): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetFloat(void* userMessage, const plg::string& fieldName, float value) {
    return __s2sdk_PbSetFloat(userMessage, fieldName, value);
  }

  using _PbGetDouble = bool (*)(void*, const plg::string&, double&);
}
extern "C" PLUGIN_API s2sdk::_PbGetDouble __s2sdk_PbGetDouble;
namespace s2sdk {
  /**
   * @brief Gets a double value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (double&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetDouble(void* userMessage, const plg::string& fieldName, double& out) {
    return __s2sdk_PbGetDouble(userMessage, fieldName, out);
  }

  using _PbSetDouble = bool (*)(void*, const plg::string&, double);
}
extern "C" PLUGIN_API s2sdk::_PbSetDouble __s2sdk_PbSetDouble;
namespace s2sdk {
  /**
   * @brief Sets a double value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (double): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetDouble(void* userMessage, const plg::string& fieldName, double value) {
    return __s2sdk_PbSetDouble(userMessage, fieldName, value);
  }

  using _PbGetString = bool (*)(void*, const plg::string&, plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PbGetString __s2sdk_PbGetString;
namespace s2sdk {
  /**
   * @brief Gets a string value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (string&): The output string.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetString(void* userMessage, const plg::string& fieldName, plg::string& out) {
    return __s2sdk_PbGetString(userMessage, fieldName, out);
  }

  using _PbSetString = bool (*)(void*, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PbSetString __s2sdk_PbSetString;
namespace s2sdk {
  /**
   * @brief Sets a string value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (string): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetString(void* userMessage, const plg::string& fieldName, const plg::string& value) {
    return __s2sdk_PbSetString(userMessage, fieldName, value);
  }

  using _PbGetColor = bool (*)(void*, const plg::string&, plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_PbGetColor __s2sdk_PbGetColor;
namespace s2sdk {
  /**
   * @brief Gets a color value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (vec4&): The output string.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetColor(void* userMessage, const plg::string& fieldName, plg::vec4& out) {
    return __s2sdk_PbGetColor(userMessage, fieldName, out);
  }

  using _PbSetColor = bool (*)(void*, const plg::string&, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_PbSetColor __s2sdk_PbSetColor;
namespace s2sdk {
  /**
   * @brief Sets a color value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (vec4): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetColor(void* userMessage, const plg::string& fieldName, const plg::vec4& value) {
    return __s2sdk_PbSetColor(userMessage, fieldName, value);
  }

  using _PbGetVector2 = bool (*)(void*, const plg::string&, plg::vec2&);
}
extern "C" PLUGIN_API s2sdk::_PbGetVector2 __s2sdk_PbGetVector2;
namespace s2sdk {
  /**
   * @brief Gets a Vector2 value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (vec2&): The output string.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetVector2(void* userMessage, const plg::string& fieldName, plg::vec2& out) {
    return __s2sdk_PbGetVector2(userMessage, fieldName, out);
  }

  using _PbSetVector2 = bool (*)(void*, const plg::string&, const plg::vec2&);
}
extern "C" PLUGIN_API s2sdk::_PbSetVector2 __s2sdk_PbSetVector2;
namespace s2sdk {
  /**
   * @brief Sets a Vector2 value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (vec2): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetVector2(void* userMessage, const plg::string& fieldName, const plg::vec2& value) {
    return __s2sdk_PbSetVector2(userMessage, fieldName, value);
  }

  using _PbGetVector3 = bool (*)(void*, const plg::string&, plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_PbGetVector3 __s2sdk_PbGetVector3;
namespace s2sdk {
  /**
   * @brief Gets a Vector3 value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (vec3&): The output string.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetVector3(void* userMessage, const plg::string& fieldName, plg::vec3& out) {
    return __s2sdk_PbGetVector3(userMessage, fieldName, out);
  }

  using _PbSetVector3 = bool (*)(void*, const plg::string&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_PbSetVector3 __s2sdk_PbSetVector3;
namespace s2sdk {
  /**
   * @brief Sets a Vector3 value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (vec3): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetVector3(void* userMessage, const plg::string& fieldName, const plg::vec3& value) {
    return __s2sdk_PbSetVector3(userMessage, fieldName, value);
  }

  using _PbGetVector4 = bool (*)(void*, const plg::string&, plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_PbGetVector4 __s2sdk_PbGetVector4;
namespace s2sdk {
  /**
   * @brief Gets a Vector4 value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (vec4&): The output string.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetVector4(void* userMessage, const plg::string& fieldName, plg::vec4& out) {
    return __s2sdk_PbGetVector4(userMessage, fieldName, out);
  }

  using _PbSetVector4 = bool (*)(void*, const plg::string&, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_PbSetVector4 __s2sdk_PbSetVector4;
namespace s2sdk {
  /**
   * @brief Sets a Vector3 value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (vec4): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetVector4(void* userMessage, const plg::string& fieldName, const plg::vec4& value) {
    return __s2sdk_PbSetVector4(userMessage, fieldName, value);
  }

  using _PbGetQAngle = bool (*)(void*, const plg::string&, plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_PbGetQAngle __s2sdk_PbGetQAngle;
namespace s2sdk {
  /**
   * @brief Gets a QAngle value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (vec3&): The output vector.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetQAngle(void* userMessage, const plg::string& fieldName, plg::vec3& out) {
    return __s2sdk_PbGetQAngle(userMessage, fieldName, out);
  }

  using _PbSetQAngle = bool (*)(void*, const plg::string&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_PbSetQAngle __s2sdk_PbSetQAngle;
namespace s2sdk {
  /**
   * @brief Sets a QAngle value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (vec3): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetQAngle(void* userMessage, const plg::string& fieldName, const plg::vec3& value) {
    return __s2sdk_PbSetQAngle(userMessage, fieldName, value);
  }

  using _PbGetMessage = bool (*)(void*, const plg::string&, void*&);
}
extern "C" PLUGIN_API s2sdk::_PbGetMessage __s2sdk_PbGetMessage;
namespace s2sdk {
  /**
   * @brief Gets a Message value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param out (ptr64&): The output message.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetMessage(void* userMessage, const plg::string& fieldName, void*& out) {
    return __s2sdk_PbGetMessage(userMessage, fieldName, out);
  }

  using _PbSetMessage = bool (*)(void*, const plg::string&, void*);
}
extern "C" PLUGIN_API s2sdk::_PbSetMessage __s2sdk_PbSetMessage;
namespace s2sdk {
  /**
   * @brief Sets a Message value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (ptr64): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetMessage(void* userMessage, const plg::string& fieldName, void* value) {
    return __s2sdk_PbSetMessage(userMessage, fieldName, value);
  }

  using _PbGetRepeatedEnum = bool (*)(void*, const plg::string&, int32_t, int32_t&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedEnum __s2sdk_PbGetRepeatedEnum;
namespace s2sdk {
  /**
   * @brief Gets a repeated enum value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (int32&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedEnum(void* userMessage, const plg::string& fieldName, int32_t index, int32_t& out) {
    return __s2sdk_PbGetRepeatedEnum(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedEnum = bool (*)(void*, const plg::string&, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedEnum __s2sdk_PbSetRepeatedEnum;
namespace s2sdk {
  /**
   * @brief Sets a repeated enum value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (int32): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedEnum(void* userMessage, const plg::string& fieldName, int32_t index, int32_t value) {
    return __s2sdk_PbSetRepeatedEnum(userMessage, fieldName, index, value);
  }

  using _PbAddEnum = bool (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbAddEnum __s2sdk_PbAddEnum;
namespace s2sdk {
  /**
   * @brief Adds a enum value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (int32): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddEnum(void* userMessage, const plg::string& fieldName, int32_t value) {
    return __s2sdk_PbAddEnum(userMessage, fieldName, value);
  }

  using _PbGetRepeatedInt32 = bool (*)(void*, const plg::string&, int32_t, int32_t&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedInt32 __s2sdk_PbGetRepeatedInt32;
namespace s2sdk {
  /**
   * @brief Gets a repeated int32_t value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (int32&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedInt32(void* userMessage, const plg::string& fieldName, int32_t index, int32_t& out) {
    return __s2sdk_PbGetRepeatedInt32(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedInt32 = bool (*)(void*, const plg::string&, int32_t, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedInt32 __s2sdk_PbSetRepeatedInt32;
namespace s2sdk {
  /**
   * @brief Sets a repeated int32_t value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (int32): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedInt32(void* userMessage, const plg::string& fieldName, int32_t index, int32_t value) {
    return __s2sdk_PbSetRepeatedInt32(userMessage, fieldName, index, value);
  }

  using _PbAddInt32 = bool (*)(void*, const plg::string&, int32_t);
}
extern "C" PLUGIN_API s2sdk::_PbAddInt32 __s2sdk_PbAddInt32;
namespace s2sdk {
  /**
   * @brief Adds a 32-bit integer value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (int32): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddInt32(void* userMessage, const plg::string& fieldName, int32_t value) {
    return __s2sdk_PbAddInt32(userMessage, fieldName, value);
  }

  using _PbGetRepeatedInt64 = bool (*)(void*, const plg::string&, int32_t, int64_t&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedInt64 __s2sdk_PbGetRepeatedInt64;
namespace s2sdk {
  /**
   * @brief Gets a repeated int64_t value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (int64&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedInt64(void* userMessage, const plg::string& fieldName, int32_t index, int64_t& out) {
    return __s2sdk_PbGetRepeatedInt64(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedInt64 = bool (*)(void*, const plg::string&, int32_t, int64_t);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedInt64 __s2sdk_PbSetRepeatedInt64;
namespace s2sdk {
  /**
   * @brief Sets a repeated int64_t value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (int64): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedInt64(void* userMessage, const plg::string& fieldName, int32_t index, int64_t value) {
    return __s2sdk_PbSetRepeatedInt64(userMessage, fieldName, index, value);
  }

  using _PbAddInt64 = bool (*)(void*, const plg::string&, int64_t);
}
extern "C" PLUGIN_API s2sdk::_PbAddInt64 __s2sdk_PbAddInt64;
namespace s2sdk {
  /**
   * @brief Adds a 64-bit integer value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (int64): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddInt64(void* userMessage, const plg::string& fieldName, int64_t value) {
    return __s2sdk_PbAddInt64(userMessage, fieldName, value);
  }

  using _PbGetRepeatedUInt32 = bool (*)(void*, const plg::string&, int32_t, uint32_t&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedUInt32 __s2sdk_PbGetRepeatedUInt32;
namespace s2sdk {
  /**
   * @brief Gets a repeated uint32_t value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (uint32&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedUInt32(void* userMessage, const plg::string& fieldName, int32_t index, uint32_t& out) {
    return __s2sdk_PbGetRepeatedUInt32(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedUInt32 = bool (*)(void*, const plg::string&, int32_t, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedUInt32 __s2sdk_PbSetRepeatedUInt32;
namespace s2sdk {
  /**
   * @brief Sets a repeated uint32_t value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (uint32): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedUInt32(void* userMessage, const plg::string& fieldName, int32_t index, uint32_t value) {
    return __s2sdk_PbSetRepeatedUInt32(userMessage, fieldName, index, value);
  }

  using _PbAddUInt32 = bool (*)(void*, const plg::string&, uint32_t);
}
extern "C" PLUGIN_API s2sdk::_PbAddUInt32 __s2sdk_PbAddUInt32;
namespace s2sdk {
  /**
   * @brief Adds an unsigned 32-bit integer value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (uint32): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddUInt32(void* userMessage, const plg::string& fieldName, uint32_t value) {
    return __s2sdk_PbAddUInt32(userMessage, fieldName, value);
  }

  using _PbGetRepeatedUInt64 = bool (*)(void*, const plg::string&, int32_t, uint64_t&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedUInt64 __s2sdk_PbGetRepeatedUInt64;
namespace s2sdk {
  /**
   * @brief Gets a repeated uint64_t value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (uint64&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedUInt64(void* userMessage, const plg::string& fieldName, int32_t index, uint64_t& out) {
    return __s2sdk_PbGetRepeatedUInt64(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedUInt64 = bool (*)(void*, const plg::string&, int32_t, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedUInt64 __s2sdk_PbSetRepeatedUInt64;
namespace s2sdk {
  /**
   * @brief Sets a repeated uint64_t value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (uint64): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedUInt64(void* userMessage, const plg::string& fieldName, int32_t index, uint64_t value) {
    return __s2sdk_PbSetRepeatedUInt64(userMessage, fieldName, index, value);
  }

  using _PbAddUInt64 = bool (*)(void*, const plg::string&, uint64_t);
}
extern "C" PLUGIN_API s2sdk::_PbAddUInt64 __s2sdk_PbAddUInt64;
namespace s2sdk {
  /**
   * @brief Adds an unsigned 64-bit integer value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (uint64): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddUInt64(void* userMessage, const plg::string& fieldName, uint64_t value) {
    return __s2sdk_PbAddUInt64(userMessage, fieldName, value);
  }

  using _PbGetRepeatedBool = bool (*)(void*, const plg::string&, int32_t, bool&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedBool __s2sdk_PbGetRepeatedBool;
namespace s2sdk {
  /**
   * @brief Gets a repeated bool value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (bool&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedBool(void* userMessage, const plg::string& fieldName, int32_t index, bool& out) {
    return __s2sdk_PbGetRepeatedBool(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedBool = bool (*)(void*, const plg::string&, int32_t, bool);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedBool __s2sdk_PbSetRepeatedBool;
namespace s2sdk {
  /**
   * @brief Sets a repeated bool value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (bool): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedBool(void* userMessage, const plg::string& fieldName, int32_t index, bool value) {
    return __s2sdk_PbSetRepeatedBool(userMessage, fieldName, index, value);
  }

  using _PbAddBool = bool (*)(void*, const plg::string&, bool);
}
extern "C" PLUGIN_API s2sdk::_PbAddBool __s2sdk_PbAddBool;
namespace s2sdk {
  /**
   * @brief Adds a bool value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (bool): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddBool(void* userMessage, const plg::string& fieldName, bool value) {
    return __s2sdk_PbAddBool(userMessage, fieldName, value);
  }

  using _PbGetRepeatedFloat = bool (*)(void*, const plg::string&, int32_t, float&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedFloat __s2sdk_PbGetRepeatedFloat;
namespace s2sdk {
  /**
   * @brief Gets a repeated float value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (float&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedFloat(void* userMessage, const plg::string& fieldName, int32_t index, float& out) {
    return __s2sdk_PbGetRepeatedFloat(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedFloat = bool (*)(void*, const plg::string&, int32_t, float);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedFloat __s2sdk_PbSetRepeatedFloat;
namespace s2sdk {
  /**
   * @brief Sets a repeated float value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (float): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedFloat(void* userMessage, const plg::string& fieldName, int32_t index, float value) {
    return __s2sdk_PbSetRepeatedFloat(userMessage, fieldName, index, value);
  }

  using _PbAddFloat = bool (*)(void*, const plg::string&, float);
}
extern "C" PLUGIN_API s2sdk::_PbAddFloat __s2sdk_PbAddFloat;
namespace s2sdk {
  /**
   * @brief Adds a float value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (float): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddFloat(void* userMessage, const plg::string& fieldName, float value) {
    return __s2sdk_PbAddFloat(userMessage, fieldName, value);
  }

  using _PbGetRepeatedDouble = bool (*)(void*, const plg::string&, int32_t, double&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedDouble __s2sdk_PbGetRepeatedDouble;
namespace s2sdk {
  /**
   * @brief Gets a repeated double value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (double&): The output value.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedDouble(void* userMessage, const plg::string& fieldName, int32_t index, double& out) {
    return __s2sdk_PbGetRepeatedDouble(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedDouble = bool (*)(void*, const plg::string&, int32_t, double);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedDouble __s2sdk_PbSetRepeatedDouble;
namespace s2sdk {
  /**
   * @brief Sets a repeated double value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (double): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedDouble(void* userMessage, const plg::string& fieldName, int32_t index, double value) {
    return __s2sdk_PbSetRepeatedDouble(userMessage, fieldName, index, value);
  }

  using _PbAddDouble = bool (*)(void*, const plg::string&, double);
}
extern "C" PLUGIN_API s2sdk::_PbAddDouble __s2sdk_PbAddDouble;
namespace s2sdk {
  /**
   * @brief Adds a double value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (double): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddDouble(void* userMessage, const plg::string& fieldName, double value) {
    return __s2sdk_PbAddDouble(userMessage, fieldName, value);
  }

  using _PbGetRepeatedString = bool (*)(void*, const plg::string&, int32_t, plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedString __s2sdk_PbGetRepeatedString;
namespace s2sdk {
  /**
   * @brief Gets a repeated string value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (string&): The output string.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedString(void* userMessage, const plg::string& fieldName, int32_t index, plg::string& out) {
    return __s2sdk_PbGetRepeatedString(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedString = bool (*)(void*, const plg::string&, int32_t, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedString __s2sdk_PbSetRepeatedString;
namespace s2sdk {
  /**
   * @brief Sets a repeated string value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (string): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedString(void* userMessage, const plg::string& fieldName, int32_t index, const plg::string& value) {
    return __s2sdk_PbSetRepeatedString(userMessage, fieldName, index, value);
  }

  using _PbAddString = bool (*)(void*, const plg::string&, const plg::string&);
}
extern "C" PLUGIN_API s2sdk::_PbAddString __s2sdk_PbAddString;
namespace s2sdk {
  /**
   * @brief Adds a string value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (string): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddString(void* userMessage, const plg::string& fieldName, const plg::string& value) {
    return __s2sdk_PbAddString(userMessage, fieldName, value);
  }

  using _PbGetRepeatedColor = bool (*)(void*, const plg::string&, int32_t, plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedColor __s2sdk_PbGetRepeatedColor;
namespace s2sdk {
  /**
   * @brief Gets a repeated color value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (vec4&): The output color.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedColor(void* userMessage, const plg::string& fieldName, int32_t index, plg::vec4& out) {
    return __s2sdk_PbGetRepeatedColor(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedColor = bool (*)(void*, const plg::string&, int32_t, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedColor __s2sdk_PbSetRepeatedColor;
namespace s2sdk {
  /**
   * @brief Sets a repeated color value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (vec4): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedColor(void* userMessage, const plg::string& fieldName, int32_t index, const plg::vec4& value) {
    return __s2sdk_PbSetRepeatedColor(userMessage, fieldName, index, value);
  }

  using _PbAddColor = bool (*)(void*, const plg::string&, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_PbAddColor __s2sdk_PbAddColor;
namespace s2sdk {
  /**
   * @brief Adds a color value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (vec4): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddColor(void* userMessage, const plg::string& fieldName, const plg::vec4& value) {
    return __s2sdk_PbAddColor(userMessage, fieldName, value);
  }

  using _PbGetRepeatedVector2 = bool (*)(void*, const plg::string&, int32_t, plg::vec2&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedVector2 __s2sdk_PbGetRepeatedVector2;
namespace s2sdk {
  /**
   * @brief Gets a repeated Vector2 value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (vec2&): The output vector.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedVector2(void* userMessage, const plg::string& fieldName, int32_t index, plg::vec2& out) {
    return __s2sdk_PbGetRepeatedVector2(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedVector2 = bool (*)(void*, const plg::string&, int32_t, const plg::vec2&);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedVector2 __s2sdk_PbSetRepeatedVector2;
namespace s2sdk {
  /**
   * @brief Sets a repeated Vector2 value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (vec2): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedVector2(void* userMessage, const plg::string& fieldName, int32_t index, const plg::vec2& value) {
    return __s2sdk_PbSetRepeatedVector2(userMessage, fieldName, index, value);
  }

  using _PbAddVector2 = bool (*)(void*, const plg::string&, const plg::vec2&);
}
extern "C" PLUGIN_API s2sdk::_PbAddVector2 __s2sdk_PbAddVector2;
namespace s2sdk {
  /**
   * @brief Adds a Vector2 value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (vec2): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddVector2(void* userMessage, const plg::string& fieldName, const plg::vec2& value) {
    return __s2sdk_PbAddVector2(userMessage, fieldName, value);
  }

  using _PbGetRepeatedVector3 = bool (*)(void*, const plg::string&, int32_t, plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedVector3 __s2sdk_PbGetRepeatedVector3;
namespace s2sdk {
  /**
   * @brief Gets a repeated Vector3 value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (vec3&): The output vector.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedVector3(void* userMessage, const plg::string& fieldName, int32_t index, plg::vec3& out) {
    return __s2sdk_PbGetRepeatedVector3(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedVector3 = bool (*)(void*, const plg::string&, int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedVector3 __s2sdk_PbSetRepeatedVector3;
namespace s2sdk {
  /**
   * @brief Sets a repeated Vector3 value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (vec3): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedVector3(void* userMessage, const plg::string& fieldName, int32_t index, const plg::vec3& value) {
    return __s2sdk_PbSetRepeatedVector3(userMessage, fieldName, index, value);
  }

  using _PbAddVector3 = bool (*)(void*, const plg::string&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_PbAddVector3 __s2sdk_PbAddVector3;
namespace s2sdk {
  /**
   * @brief Adds a Vector3 value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (vec3): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddVector3(void* userMessage, const plg::string& fieldName, const plg::vec3& value) {
    return __s2sdk_PbAddVector3(userMessage, fieldName, value);
  }

  using _PbGetRepeatedVector4 = bool (*)(void*, const plg::string&, int32_t, plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedVector4 __s2sdk_PbGetRepeatedVector4;
namespace s2sdk {
  /**
   * @brief Gets a repeated Vector4 value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (vec4&): The output vector.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedVector4(void* userMessage, const plg::string& fieldName, int32_t index, plg::vec4& out) {
    return __s2sdk_PbGetRepeatedVector4(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedVector4 = bool (*)(void*, const plg::string&, int32_t, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedVector4 __s2sdk_PbSetRepeatedVector4;
namespace s2sdk {
  /**
   * @brief Sets a repeated Vector4 value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (vec4): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedVector4(void* userMessage, const plg::string& fieldName, int32_t index, const plg::vec4& value) {
    return __s2sdk_PbSetRepeatedVector4(userMessage, fieldName, index, value);
  }

  using _PbAddVector4 = bool (*)(void*, const plg::string&, const plg::vec4&);
}
extern "C" PLUGIN_API s2sdk::_PbAddVector4 __s2sdk_PbAddVector4;
namespace s2sdk {
  /**
   * @brief Adds a Vector4 value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (vec4): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddVector4(void* userMessage, const plg::string& fieldName, const plg::vec4& value) {
    return __s2sdk_PbAddVector4(userMessage, fieldName, value);
  }

  using _PbGetRepeatedQAngle = bool (*)(void*, const plg::string&, int32_t, plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedQAngle __s2sdk_PbGetRepeatedQAngle;
namespace s2sdk {
  /**
   * @brief Gets a repeated QAngle value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (vec3&): The output vector.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedQAngle(void* userMessage, const plg::string& fieldName, int32_t index, plg::vec3& out) {
    return __s2sdk_PbGetRepeatedQAngle(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedQAngle = bool (*)(void*, const plg::string&, int32_t, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedQAngle __s2sdk_PbSetRepeatedQAngle;
namespace s2sdk {
  /**
   * @brief Sets a repeated QAngle value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (vec3): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedQAngle(void* userMessage, const plg::string& fieldName, int32_t index, const plg::vec3& value) {
    return __s2sdk_PbSetRepeatedQAngle(userMessage, fieldName, index, value);
  }

  using _PbAddQAngle = bool (*)(void*, const plg::string&, const plg::vec3&);
}
extern "C" PLUGIN_API s2sdk::_PbAddQAngle __s2sdk_PbAddQAngle;
namespace s2sdk {
  /**
   * @brief Adds a QAngle value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (vec3): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddQAngle(void* userMessage, const plg::string& fieldName, const plg::vec3& value) {
    return __s2sdk_PbAddQAngle(userMessage, fieldName, value);
  }

  using _PbGetRepeatedMessage = bool (*)(void*, const plg::string&, int32_t, void*&);
}
extern "C" PLUGIN_API s2sdk::_PbGetRepeatedMessage __s2sdk_PbGetRepeatedMessage;
namespace s2sdk {
  /**
   * @brief Gets a repeated Message value from a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param out (ptr64&): The output message.
   * @return bool: True if the field was successfully retrieved, false otherwise.
   */
  inline bool PbGetRepeatedMessage(void* userMessage, const plg::string& fieldName, int32_t index, void*& out) {
    return __s2sdk_PbGetRepeatedMessage(userMessage, fieldName, index, out);
  }

  using _PbSetRepeatedMessage = bool (*)(void*, const plg::string&, int32_t, void*);
}
extern "C" PLUGIN_API s2sdk::_PbSetRepeatedMessage __s2sdk_PbSetRepeatedMessage;
namespace s2sdk {
  /**
   * @brief Sets a repeated Message value for a field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param index (int32): The index of the repeated field.
   * @param value (ptr64): The value to set.
   * @return bool: True if the field was successfully set, false otherwise.
   */
  inline bool PbSetRepeatedMessage(void* userMessage, const plg::string& fieldName, int32_t index, void* value) {
    return __s2sdk_PbSetRepeatedMessage(userMessage, fieldName, index, value);
  }

  using _PbAddMessage = bool (*)(void*, const plg::string&, void*);
}
extern "C" PLUGIN_API s2sdk::_PbAddMessage __s2sdk_PbAddMessage;
namespace s2sdk {
  /**
   * @brief Adds a Message value to a repeated field in the UserMessage.
   * @param userMessage (ptr64): The UserMessage instance.
   * @param fieldName (string): The name of the field.
   * @param value (ptr64): The value to add.
   * @return bool: True if the value was successfully added, false otherwise.
   */
  inline bool PbAddMessage(void* userMessage, const plg::string& fieldName, void* value) {
    return __s2sdk_PbAddMessage(userMessage, fieldName, value);
  }

  /**
   * @brief RAII wrapper for UserMessage pointer.
   * @return 
   */
  class UserMessage final {
  public:
    UserMessage() = default;

    /**
     * @brief Creates a UserMessage from a serializable message.
     * @param msgSerializable (ptr64): The serializable message.
     * @param message (ptr64): The network message.
     * @param recipientMask (uint64): The recipient mask.
     * @return 
     */
    explicit UserMessage(void* msgSerializable, void* message, uint64_t recipientMask)
      : UserMessage(UserMessageCreateFromSerializable(msgSerializable, message, recipientMask), Ownership::Owned) {}

    /**
     * @brief Creates a UserMessage from a message name.
     * @param messageName (string): The name of the message.
     * @return 
     */
    explicit UserMessage(const plg::string& messageName)
      : UserMessage(UserMessageCreateFromName(messageName), Ownership::Owned) {}

    /**
     * @brief Creates a UserMessage from a message ID.
     * @param messageId (int16): The ID of the message.
     * @return 
     */
    explicit UserMessage(int16_t messageId)
      : UserMessage(UserMessageCreateFromId(messageId), Ownership::Owned) {}

    ~UserMessage() {
      destroy();
    }

    UserMessage(const UserMessage&) = delete;
    UserMessage& operator=(const UserMessage&) = delete;

    UserMessage(UserMessage&& other) noexcept
      : _handle(other._handle)
      , _ownership(other._ownership) {
      other.nullify();
    }

    UserMessage& operator=(UserMessage&& other) noexcept {
      if (this != &other) {
        destroy();
        _handle = other._handle;
        _ownership = other._ownership;
        other.nullify();
      }
      return *this;
    }

    UserMessage(void* handle, Ownership ownership = Ownership::Borrowed) : _handle(handle), _ownership(ownership) {}

    [[nodiscard]] auto get() const noexcept { return _handle; }

    [[nodiscard]] auto release() noexcept {
      auto handle = _handle;
      nullify();
      return handle;
    }

    void reset() noexcept {
      destroy();
      nullify();
    }

    void swap(UserMessage& other) noexcept {
      using std::swap;
      swap(_handle, other._handle);
      swap(_ownership, other._ownership);
    }

    friend void swap(UserMessage& lhs, UserMessage& rhs) noexcept { lhs.swap(rhs); }

    explicit operator bool() const noexcept { return _handle != nullptr; }
    [[nodiscard]] auto operator<=>(const UserMessage& other) const noexcept { return _handle <=> other._handle; }
    [[nodiscard]] bool operator==(const UserMessage& other) const noexcept { return _handle == other._handle; }

    /**
     * @brief Sends a UserMessage to the specified recipients.
     */
    void Send() {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      s2sdk::UserMessageSend(_handle);
    }

    /**
     * @brief Gets the name of the message.
     * @return string: The name of the message as a string.
     */
    plg::string GetMessageName() {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::UserMessageGetMessageName(_handle);
    }

    /**
     * @brief Gets the ID of the message.
     * @return int16: The ID of the message.
     */
    int16_t GetMessageID() {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::UserMessageGetMessageID(_handle);
    }

    /**
     * @brief Checks if the message has a specific field.
     * @param fieldName (string): The name of the field to check.
     * @return bool: True if the field exists, false otherwise.
     */
    bool HasField(const plg::string& fieldName) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::UserMessageHasField(_handle, fieldName);
    }

    /**
     * @brief Gets the protobuf message associated with the UserMessage.
     * @return ptr64: A pointer to the protobuf message.
     */
    void* GetProtobufMessage() {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::UserMessageGetProtobufMessage(_handle);
    }

    /**
     * @brief Gets the serializable message associated with the UserMessage.
     * @return ptr64: A pointer to the serializable message.
     */
    void* GetSerializableMessage() {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::UserMessageGetSerializableMessage(_handle);
    }

    /**
     * @brief Finds a message ID by its name.
     * @param messageName (string): The name of the message.
     * @return int16: The ID of the message, or 0 if the message was not found.
     */
    static int16_t FindMessageIdByName(const plg::string& messageName) {
      return s2sdk::UserMessageFindMessageIdByName(messageName);
    }

    /**
     * @brief Gets the recipient mask for the UserMessage.
     * @return uint64: The recipient mask.
     */
    uint64_t GetRecipientMask() {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::UserMessageGetRecipientMask(_handle);
    }

    /**
     * @brief Adds a single recipient (player) to the UserMessage.
     * @param playerSlot (int32): The slot index of the player to add as a recipient.
     */
    void AddRecipient(int32_t playerSlot) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      s2sdk::UserMessageAddRecipient(_handle, playerSlot);
    }

    /**
     * @brief Adds all connected players as recipients to the UserMessage.
     */
    void AddAllPlayers() {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      s2sdk::UserMessageAddAllPlayers(_handle);
    }

    /**
     * @brief Sets the recipient mask for the UserMessage.
     * @param mask (uint64): The recipient mask to set.
     */
    void SetRecipientMask(uint64_t mask) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      s2sdk::UserMessageSetRecipientMask(_handle, mask);
    }

    /**
     * @brief Gets the count of repeated fields in a field of the UserMessage.
     * @param fieldName (string): The name of the field.
     * @return int32: The count of repeated fields, or -1 if the field is not repeated or does not exist.
     */
    int32_t GetRepeatedFieldCount(const plg::string& fieldName) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::UserMessageGetRepeatedFieldCount(_handle, fieldName);
    }

    /**
     * @brief Removes a value from a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the value to remove.
     * @return bool: True if the value was successfully removed, false otherwise.
     */
    bool RemoveRepeatedFieldValue(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::UserMessageRemoveRepeatedFieldValue(_handle, fieldName, index);
    }

    /**
     * @brief Gets the debug string representation of the UserMessage.
     * @return string: The debug string as a string.
     */
    plg::string GetDebugString() {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::UserMessageGetDebugString(_handle);
    }

    /**
     * @brief Reads an enum value from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return int32: The integer representation of the enum value, or 0 if invalid.
     */
    int32_t ReadEnum(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadEnum(_handle, fieldName, index);
    }

    /**
     * @brief Reads a 32-bit integer from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return int32: The int32_t value read, or 0 if invalid.
     */
    int32_t ReadInt32(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadInt32(_handle, fieldName, index);
    }

    /**
     * @brief Reads a 64-bit integer from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return int64: The int64_t value read, or 0 if invalid.
     */
    int64_t ReadInt64(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadInt64(_handle, fieldName, index);
    }

    /**
     * @brief Reads an unsigned 32-bit integer from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return uint32: The uint32_t value read, or 0 if invalid.
     */
    uint32_t ReadUInt32(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadUInt32(_handle, fieldName, index);
    }

    /**
     * @brief Reads an unsigned 64-bit integer from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return uint64: The uint64_t value read, or 0 if invalid.
     */
    uint64_t ReadUInt64(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadUInt64(_handle, fieldName, index);
    }

    /**
     * @brief Reads a floating-point value from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return float: The float value read, or 0.0 if invalid.
     */
    float ReadFloat(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadFloat(_handle, fieldName, index);
    }

    /**
     * @brief Reads a double-precision floating-point value from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return double: The double value read, or 0.0 if invalid.
     */
    double ReadDouble(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadDouble(_handle, fieldName, index);
    }

    /**
     * @brief Reads a boolean value from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return bool: The boolean value read, or false if invalid.
     */
    bool ReadBool(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadBool(_handle, fieldName, index);
    }

    /**
     * @brief Reads a string from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return string: The string value read, or an empty string if invalid.
     */
    plg::string ReadString(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadString(_handle, fieldName, index);
    }

    /**
     * @brief Reads a color value from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return vec4: The color value read, or an empty value if invalid.
     */
    plg::vec4 ReadColor(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadColor(_handle, fieldName, index);
    }

    /**
     * @brief Reads a 2D vector from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return vec2: The 2D vector value read, or an empty value if invalid.
     */
    plg::vec2 ReadVector2(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadVector2(_handle, fieldName, index);
    }

    /**
     * @brief Reads a 3D vector from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return vec3: The 3D vector value read, or an empty value if invalid.
     */
    plg::vec3 ReadVector3(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadVector3(_handle, fieldName, index);
    }

    /**
     * @brief Reads a 4D vector from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return vec4: The 4D vector value read, or an empty value if invalid.
     */
    plg::vec4 ReadVector4(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadVector4(_handle, fieldName, index);
    }

    /**
     * @brief Reads a QAngle (rotation vector) from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return vec3: The QAngle value read, or an empty value if invalid.
     */
    plg::vec3 ReadQAngle(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadQAngle(_handle, fieldName, index);
    }

    /**
     * @brief Reads a Message from a UserMessage.
     * @param fieldName (string): Name of the field to read.
     * @param index (int32): Index of the repeated field (use -1 for non-repeated fields).
     * @return ptr64: The Message value read, or an empty value if invalid.
     */
    void* ReadMessage(const plg::string& fieldName, int32_t index) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbReadMessage(_handle, fieldName, index);
    }

    /**
     * @brief Gets a enum value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (int32&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetEnum(const plg::string& fieldName, int32_t& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetEnum(_handle, fieldName, out);
    }

    /**
     * @brief Sets a enum value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (int32): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetEnum(const plg::string& fieldName, int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetEnum(_handle, fieldName, value);
    }

    /**
     * @brief Gets a 32-bit integer value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (int32&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetInt32(const plg::string& fieldName, int32_t& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetInt32(_handle, fieldName, out);
    }

    /**
     * @brief Sets a 32-bit integer value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (int32): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetInt32(const plg::string& fieldName, int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetInt32(_handle, fieldName, value);
    }

    /**
     * @brief Gets a 64-bit integer value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (int64&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetInt64(const plg::string& fieldName, int64_t& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetInt64(_handle, fieldName, out);
    }

    /**
     * @brief Sets a 64-bit integer value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (int64): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetInt64(const plg::string& fieldName, int64_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetInt64(_handle, fieldName, value);
    }

    /**
     * @brief Gets an unsigned 32-bit integer value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (uint32&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetUInt32(const plg::string& fieldName, uint32_t& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetUInt32(_handle, fieldName, out);
    }

    /**
     * @brief Sets an unsigned 32-bit integer value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (uint32): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetUInt32(const plg::string& fieldName, uint32_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetUInt32(_handle, fieldName, value);
    }

    /**
     * @brief Gets an unsigned 64-bit integer value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (uint64&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetUInt64(const plg::string& fieldName, uint64_t& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetUInt64(_handle, fieldName, out);
    }

    /**
     * @brief Sets an unsigned 64-bit integer value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (uint64): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetUInt64(const plg::string& fieldName, uint64_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetUInt64(_handle, fieldName, value);
    }

    /**
     * @brief Gets a bool value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (bool&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetBool(const plg::string& fieldName, bool& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetBool(_handle, fieldName, out);
    }

    /**
     * @brief Sets a bool value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (bool): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetBool(const plg::string& fieldName, bool value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetBool(_handle, fieldName, value);
    }

    /**
     * @brief Gets a float value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (float&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetFloat(const plg::string& fieldName, float& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetFloat(_handle, fieldName, out);
    }

    /**
     * @brief Sets a float value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (float): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetFloat(const plg::string& fieldName, float value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetFloat(_handle, fieldName, value);
    }

    /**
     * @brief Gets a double value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (double&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetDouble(const plg::string& fieldName, double& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetDouble(_handle, fieldName, out);
    }

    /**
     * @brief Sets a double value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (double): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetDouble(const plg::string& fieldName, double value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetDouble(_handle, fieldName, value);
    }

    /**
     * @brief Gets a string value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (string&): The output string.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetString(const plg::string& fieldName, plg::string& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetString(_handle, fieldName, out);
    }

    /**
     * @brief Sets a string value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (string): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetString(const plg::string& fieldName, const plg::string& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetString(_handle, fieldName, value);
    }

    /**
     * @brief Gets a color value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (vec4&): The output string.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetColor(const plg::string& fieldName, plg::vec4& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetColor(_handle, fieldName, out);
    }

    /**
     * @brief Sets a color value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (vec4): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetColor(const plg::string& fieldName, const plg::vec4& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetColor(_handle, fieldName, value);
    }

    /**
     * @brief Gets a Vector2 value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (vec2&): The output string.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetVector2(const plg::string& fieldName, plg::vec2& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetVector2(_handle, fieldName, out);
    }

    /**
     * @brief Sets a Vector2 value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (vec2): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetVector2(const plg::string& fieldName, const plg::vec2& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetVector2(_handle, fieldName, value);
    }

    /**
     * @brief Gets a Vector3 value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (vec3&): The output string.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetVector3(const plg::string& fieldName, plg::vec3& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetVector3(_handle, fieldName, out);
    }

    /**
     * @brief Sets a Vector3 value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (vec3): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetVector3(const plg::string& fieldName, const plg::vec3& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetVector3(_handle, fieldName, value);
    }

    /**
     * @brief Gets a Vector4 value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (vec4&): The output string.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetVector4(const plg::string& fieldName, plg::vec4& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetVector4(_handle, fieldName, out);
    }

    /**
     * @brief Sets a Vector3 value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (vec4): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetVector4(const plg::string& fieldName, const plg::vec4& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetVector4(_handle, fieldName, value);
    }

    /**
     * @brief Gets a QAngle value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (vec3&): The output vector.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetQAngle(const plg::string& fieldName, plg::vec3& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetQAngle(_handle, fieldName, out);
    }

    /**
     * @brief Sets a QAngle value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (vec3): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetQAngle(const plg::string& fieldName, const plg::vec3& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetQAngle(_handle, fieldName, value);
    }

    /**
     * @brief Gets a Message value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param out (ptr64&): The output message.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetMessage(const plg::string& fieldName, void*& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetMessage(_handle, fieldName, out);
    }

    /**
     * @brief Sets a Message value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (ptr64): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetMessage(const plg::string& fieldName, void* value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetMessage(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated enum value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (int32&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedEnum(const plg::string& fieldName, int32_t index, int32_t& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedEnum(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated enum value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (int32): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedEnum(const plg::string& fieldName, int32_t index, int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedEnum(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds a enum value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (int32): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddEnum(const plg::string& fieldName, int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddEnum(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated int32_t value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (int32&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedInt32(const plg::string& fieldName, int32_t index, int32_t& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedInt32(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated int32_t value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (int32): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedInt32(const plg::string& fieldName, int32_t index, int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedInt32(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds a 32-bit integer value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (int32): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddInt32(const plg::string& fieldName, int32_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddInt32(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated int64_t value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (int64&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedInt64(const plg::string& fieldName, int32_t index, int64_t& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedInt64(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated int64_t value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (int64): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedInt64(const plg::string& fieldName, int32_t index, int64_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedInt64(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds a 64-bit integer value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (int64): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddInt64(const plg::string& fieldName, int64_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddInt64(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated uint32_t value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (uint32&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedUInt32(const plg::string& fieldName, int32_t index, uint32_t& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedUInt32(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated uint32_t value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (uint32): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedUInt32(const plg::string& fieldName, int32_t index, uint32_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedUInt32(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds an unsigned 32-bit integer value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (uint32): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddUInt32(const plg::string& fieldName, uint32_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddUInt32(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated uint64_t value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (uint64&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedUInt64(const plg::string& fieldName, int32_t index, uint64_t& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedUInt64(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated uint64_t value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (uint64): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedUInt64(const plg::string& fieldName, int32_t index, uint64_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedUInt64(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds an unsigned 64-bit integer value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (uint64): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddUInt64(const plg::string& fieldName, uint64_t value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddUInt64(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated bool value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (bool&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedBool(const plg::string& fieldName, int32_t index, bool& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedBool(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated bool value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (bool): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedBool(const plg::string& fieldName, int32_t index, bool value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedBool(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds a bool value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (bool): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddBool(const plg::string& fieldName, bool value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddBool(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated float value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (float&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedFloat(const plg::string& fieldName, int32_t index, float& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedFloat(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated float value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (float): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedFloat(const plg::string& fieldName, int32_t index, float value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedFloat(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds a float value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (float): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddFloat(const plg::string& fieldName, float value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddFloat(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated double value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (double&): The output value.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedDouble(const plg::string& fieldName, int32_t index, double& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedDouble(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated double value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (double): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedDouble(const plg::string& fieldName, int32_t index, double value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedDouble(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds a double value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (double): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddDouble(const plg::string& fieldName, double value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddDouble(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated string value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (string&): The output string.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedString(const plg::string& fieldName, int32_t index, plg::string& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedString(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated string value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (string): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedString(const plg::string& fieldName, int32_t index, const plg::string& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedString(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds a string value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (string): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddString(const plg::string& fieldName, const plg::string& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddString(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated color value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (vec4&): The output color.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedColor(const plg::string& fieldName, int32_t index, plg::vec4& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedColor(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated color value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (vec4): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedColor(const plg::string& fieldName, int32_t index, const plg::vec4& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedColor(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds a color value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (vec4): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddColor(const plg::string& fieldName, const plg::vec4& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddColor(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated Vector2 value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (vec2&): The output vector.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedVector2(const plg::string& fieldName, int32_t index, plg::vec2& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedVector2(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated Vector2 value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (vec2): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedVector2(const plg::string& fieldName, int32_t index, const plg::vec2& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedVector2(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds a Vector2 value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (vec2): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddVector2(const plg::string& fieldName, const plg::vec2& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddVector2(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated Vector3 value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (vec3&): The output vector.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedVector3(const plg::string& fieldName, int32_t index, plg::vec3& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedVector3(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated Vector3 value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (vec3): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedVector3(const plg::string& fieldName, int32_t index, const plg::vec3& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedVector3(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds a Vector3 value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (vec3): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddVector3(const plg::string& fieldName, const plg::vec3& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddVector3(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated Vector4 value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (vec4&): The output vector.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedVector4(const plg::string& fieldName, int32_t index, plg::vec4& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedVector4(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated Vector4 value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (vec4): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedVector4(const plg::string& fieldName, int32_t index, const plg::vec4& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedVector4(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds a Vector4 value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (vec4): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddVector4(const plg::string& fieldName, const plg::vec4& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddVector4(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated QAngle value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (vec3&): The output vector.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedQAngle(const plg::string& fieldName, int32_t index, plg::vec3& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedQAngle(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated QAngle value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (vec3): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedQAngle(const plg::string& fieldName, int32_t index, const plg::vec3& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedQAngle(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds a QAngle value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (vec3): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddQAngle(const plg::string& fieldName, const plg::vec3& value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddQAngle(_handle, fieldName, value);
    }

    /**
     * @brief Gets a repeated Message value from a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param out (ptr64&): The output message.
     * @return bool: True if the field was successfully retrieved, false otherwise.
     */
    bool GetRepeatedMessage(const plg::string& fieldName, int32_t index, void*& out) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbGetRepeatedMessage(_handle, fieldName, index, out);
    }

    /**
     * @brief Sets a repeated Message value for a field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param index (int32): The index of the repeated field.
     * @param value (ptr64): The value to set.
     * @return bool: True if the field was successfully set, false otherwise.
     */
    bool SetRepeatedMessage(const plg::string& fieldName, int32_t index, void* value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbSetRepeatedMessage(_handle, fieldName, index, value);
    }

    /**
     * @brief Adds a Message value to a repeated field in the UserMessage.
     * @param fieldName (string): The name of the field.
     * @param value (ptr64): The value to add.
     * @return bool: True if the value was successfully added, false otherwise.
     */
    bool AddMessage(const plg::string& fieldName, void* value) {
      if (_handle == nullptr) throw std::runtime_error("UserMessage: empty handle");
      return s2sdk::PbAddMessage(_handle, fieldName, value);
    }

  private:
    void destroy() const noexcept {
      if (_handle != nullptr && _ownership == Ownership::Owned) {
        UserMessageDestroy(_handle);
      }
    }

    void nullify() noexcept {
      _handle = nullptr;
      _ownership = Ownership::Borrowed;
    }

    void* _handle{nullptr};
    Ownership _ownership{Ownership::Borrowed};
  };


} // namespace s2sdk
