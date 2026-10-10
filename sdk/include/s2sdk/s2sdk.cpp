#include "s2sdk.hpp"

s2sdk::_Kv1Create __s2sdk_Kv1Create = nullptr;

s2sdk::_Kv1Destroy __s2sdk_Kv1Destroy = nullptr;

s2sdk::_Kv1GetName __s2sdk_Kv1GetName = nullptr;

s2sdk::_Kv1SetName __s2sdk_Kv1SetName = nullptr;

s2sdk::_Kv1FindKey __s2sdk_Kv1FindKey = nullptr;

s2sdk::_Kv1FindOrCreateKey __s2sdk_Kv1FindOrCreateKey = nullptr;

s2sdk::_Kv1CreateKey __s2sdk_Kv1CreateKey = nullptr;

s2sdk::_Kv1CreateNewKey __s2sdk_Kv1CreateNewKey = nullptr;

s2sdk::_Kv1AddSubKey __s2sdk_Kv1AddSubKey = nullptr;

s2sdk::_Kv1GetFirstSubKey __s2sdk_Kv1GetFirstSubKey = nullptr;

s2sdk::_Kv1GetNextKey __s2sdk_Kv1GetNextKey = nullptr;

s2sdk::_Kv1GetColor __s2sdk_Kv1GetColor = nullptr;

s2sdk::_Kv1SetColor __s2sdk_Kv1SetColor = nullptr;

s2sdk::_Kv1GetInt __s2sdk_Kv1GetInt = nullptr;

s2sdk::_Kv1SetInt __s2sdk_Kv1SetInt = nullptr;

s2sdk::_Kv1GetFloat __s2sdk_Kv1GetFloat = nullptr;

s2sdk::_Kv1SetFloat __s2sdk_Kv1SetFloat = nullptr;

s2sdk::_Kv1GetString __s2sdk_Kv1GetString = nullptr;

s2sdk::_Kv1SetString __s2sdk_Kv1SetString = nullptr;

s2sdk::_Kv1GetPtr __s2sdk_Kv1GetPtr = nullptr;

s2sdk::_Kv1SetPtr __s2sdk_Kv1SetPtr = nullptr;

s2sdk::_Kv1GetBool __s2sdk_Kv1GetBool = nullptr;

s2sdk::_Kv1SetBool __s2sdk_Kv1SetBool = nullptr;

s2sdk::_Kv1MakeCopy __s2sdk_Kv1MakeCopy = nullptr;

s2sdk::_Kv1Clear __s2sdk_Kv1Clear = nullptr;

s2sdk::_Kv1IsEmpty __s2sdk_Kv1IsEmpty = nullptr;

s2sdk::_Kv3Create __s2sdk_Kv3Create = nullptr;

s2sdk::_Kv3CreateWithCluster __s2sdk_Kv3CreateWithCluster = nullptr;

s2sdk::_Kv3CreateCopy __s2sdk_Kv3CreateCopy = nullptr;

s2sdk::_Kv3Destroy __s2sdk_Kv3Destroy = nullptr;

s2sdk::_Kv3CopyFrom __s2sdk_Kv3CopyFrom = nullptr;

s2sdk::_Kv3OverlayKeysFrom __s2sdk_Kv3OverlayKeysFrom = nullptr;

s2sdk::_Kv3GetContext __s2sdk_Kv3GetContext = nullptr;

s2sdk::_Kv3GetMetaData __s2sdk_Kv3GetMetaData = nullptr;

s2sdk::_Kv3HasFlag __s2sdk_Kv3HasFlag = nullptr;

s2sdk::_Kv3HasAnyFlags __s2sdk_Kv3HasAnyFlags = nullptr;

s2sdk::_Kv3GetAllFlags __s2sdk_Kv3GetAllFlags = nullptr;

s2sdk::_Kv3SetAllFlags __s2sdk_Kv3SetAllFlags = nullptr;

s2sdk::_Kv3SetFlag __s2sdk_Kv3SetFlag = nullptr;

s2sdk::_Kv3GetType __s2sdk_Kv3GetType = nullptr;

s2sdk::_Kv3GetTypeEx __s2sdk_Kv3GetTypeEx = nullptr;

s2sdk::_Kv3GetSubType __s2sdk_Kv3GetSubType = nullptr;

s2sdk::_Kv3HasInvalidMemberNames __s2sdk_Kv3HasInvalidMemberNames = nullptr;

s2sdk::_Kv3SetHasInvalidMemberNames __s2sdk_Kv3SetHasInvalidMemberNames = nullptr;

s2sdk::_Kv3GetTypeAsString __s2sdk_Kv3GetTypeAsString = nullptr;

s2sdk::_Kv3GetSubTypeAsString __s2sdk_Kv3GetSubTypeAsString = nullptr;

s2sdk::_Kv3ToString __s2sdk_Kv3ToString = nullptr;

s2sdk::_Kv3IsNull __s2sdk_Kv3IsNull = nullptr;

s2sdk::_Kv3SetToNull __s2sdk_Kv3SetToNull = nullptr;

s2sdk::_Kv3IsArray __s2sdk_Kv3IsArray = nullptr;

s2sdk::_Kv3IsKV3Array __s2sdk_Kv3IsKV3Array = nullptr;

s2sdk::_Kv3IsTable __s2sdk_Kv3IsTable = nullptr;

s2sdk::_Kv3IsString __s2sdk_Kv3IsString = nullptr;

s2sdk::_Kv3GetBool __s2sdk_Kv3GetBool = nullptr;

s2sdk::_Kv3GetChar __s2sdk_Kv3GetChar = nullptr;

s2sdk::_Kv3GetUChar32 __s2sdk_Kv3GetUChar32 = nullptr;

s2sdk::_Kv3GetInt8 __s2sdk_Kv3GetInt8 = nullptr;

s2sdk::_Kv3GetUInt8 __s2sdk_Kv3GetUInt8 = nullptr;

s2sdk::_Kv3GetShort __s2sdk_Kv3GetShort = nullptr;

s2sdk::_Kv3GetUShort __s2sdk_Kv3GetUShort = nullptr;

s2sdk::_Kv3GetInt __s2sdk_Kv3GetInt = nullptr;

s2sdk::_Kv3GetUInt __s2sdk_Kv3GetUInt = nullptr;

s2sdk::_Kv3GetInt64 __s2sdk_Kv3GetInt64 = nullptr;

s2sdk::_Kv3GetUInt64 __s2sdk_Kv3GetUInt64 = nullptr;

s2sdk::_Kv3GetFloat __s2sdk_Kv3GetFloat = nullptr;

s2sdk::_Kv3GetDouble __s2sdk_Kv3GetDouble = nullptr;

s2sdk::_Kv3SetBool __s2sdk_Kv3SetBool = nullptr;

s2sdk::_Kv3SetChar __s2sdk_Kv3SetChar = nullptr;

s2sdk::_Kv3SetUChar32 __s2sdk_Kv3SetUChar32 = nullptr;

s2sdk::_Kv3SetInt8 __s2sdk_Kv3SetInt8 = nullptr;

s2sdk::_Kv3SetUInt8 __s2sdk_Kv3SetUInt8 = nullptr;

s2sdk::_Kv3SetShort __s2sdk_Kv3SetShort = nullptr;

s2sdk::_Kv3SetUShort __s2sdk_Kv3SetUShort = nullptr;

s2sdk::_Kv3SetInt __s2sdk_Kv3SetInt = nullptr;

s2sdk::_Kv3SetUInt __s2sdk_Kv3SetUInt = nullptr;

s2sdk::_Kv3SetInt64 __s2sdk_Kv3SetInt64 = nullptr;

s2sdk::_Kv3SetUInt64 __s2sdk_Kv3SetUInt64 = nullptr;

s2sdk::_Kv3SetFloat __s2sdk_Kv3SetFloat = nullptr;

s2sdk::_Kv3SetDouble __s2sdk_Kv3SetDouble = nullptr;

s2sdk::_Kv3GetPointer __s2sdk_Kv3GetPointer = nullptr;

s2sdk::_Kv3SetPointer __s2sdk_Kv3SetPointer = nullptr;

s2sdk::_Kv3GetStringToken __s2sdk_Kv3GetStringToken = nullptr;

s2sdk::_Kv3SetStringToken __s2sdk_Kv3SetStringToken = nullptr;

s2sdk::_Kv3GetEHandle __s2sdk_Kv3GetEHandle = nullptr;

s2sdk::_Kv3SetEHandle __s2sdk_Kv3SetEHandle = nullptr;

s2sdk::_Kv3GetString __s2sdk_Kv3GetString = nullptr;

s2sdk::_Kv3SetString __s2sdk_Kv3SetString = nullptr;

s2sdk::_Kv3SetStringExternal __s2sdk_Kv3SetStringExternal = nullptr;

s2sdk::_Kv3GetBinaryBlob __s2sdk_Kv3GetBinaryBlob = nullptr;

s2sdk::_Kv3GetBinaryBlobSize __s2sdk_Kv3GetBinaryBlobSize = nullptr;

s2sdk::_Kv3SetToBinaryBlob __s2sdk_Kv3SetToBinaryBlob = nullptr;

s2sdk::_Kv3SetToBinaryBlobExternal __s2sdk_Kv3SetToBinaryBlobExternal = nullptr;

s2sdk::_Kv3GetColor __s2sdk_Kv3GetColor = nullptr;

s2sdk::_Kv3SetColor __s2sdk_Kv3SetColor = nullptr;

s2sdk::_Kv3GetVector __s2sdk_Kv3GetVector = nullptr;

s2sdk::_Kv3GetVector2D __s2sdk_Kv3GetVector2D = nullptr;

s2sdk::_Kv3GetVector4D __s2sdk_Kv3GetVector4D = nullptr;

s2sdk::_Kv3GetQuaternion __s2sdk_Kv3GetQuaternion = nullptr;

s2sdk::_Kv3GetQAngle __s2sdk_Kv3GetQAngle = nullptr;

s2sdk::_Kv3GetMatrix3x4 __s2sdk_Kv3GetMatrix3x4 = nullptr;

s2sdk::_Kv3SetVector __s2sdk_Kv3SetVector = nullptr;

s2sdk::_Kv3SetVector2D __s2sdk_Kv3SetVector2D = nullptr;

s2sdk::_Kv3SetVector4D __s2sdk_Kv3SetVector4D = nullptr;

s2sdk::_Kv3SetQuaternion __s2sdk_Kv3SetQuaternion = nullptr;

s2sdk::_Kv3SetQAngle __s2sdk_Kv3SetQAngle = nullptr;

s2sdk::_Kv3SetMatrix3x4 __s2sdk_Kv3SetMatrix3x4 = nullptr;

s2sdk::_Kv3GetArrayElementCount __s2sdk_Kv3GetArrayElementCount = nullptr;

s2sdk::_Kv3SetArrayElementCount __s2sdk_Kv3SetArrayElementCount = nullptr;

s2sdk::_Kv3SetToEmptyKV3Array __s2sdk_Kv3SetToEmptyKV3Array = nullptr;

s2sdk::_Kv3GetArrayElement __s2sdk_Kv3GetArrayElement = nullptr;

s2sdk::_Kv3ArrayInsertElementBefore __s2sdk_Kv3ArrayInsertElementBefore = nullptr;

s2sdk::_Kv3ArrayInsertElementAfter __s2sdk_Kv3ArrayInsertElementAfter = nullptr;

s2sdk::_Kv3ArrayAddElementToTail __s2sdk_Kv3ArrayAddElementToTail = nullptr;

s2sdk::_Kv3ArraySwapItems __s2sdk_Kv3ArraySwapItems = nullptr;

s2sdk::_Kv3ArrayRemoveElement __s2sdk_Kv3ArrayRemoveElement = nullptr;

s2sdk::_Kv3SetToEmptyTable __s2sdk_Kv3SetToEmptyTable = nullptr;

s2sdk::_Kv3GetMemberCount __s2sdk_Kv3GetMemberCount = nullptr;

s2sdk::_Kv3HasMember __s2sdk_Kv3HasMember = nullptr;

s2sdk::_Kv3FindMember __s2sdk_Kv3FindMember = nullptr;

s2sdk::_Kv3FindOrCreateMember __s2sdk_Kv3FindOrCreateMember = nullptr;

s2sdk::_Kv3RemoveMember __s2sdk_Kv3RemoveMember = nullptr;

s2sdk::_Kv3GetMemberName __s2sdk_Kv3GetMemberName = nullptr;

s2sdk::_Kv3GetMemberByIndex __s2sdk_Kv3GetMemberByIndex = nullptr;

s2sdk::_Kv3GetMemberBool __s2sdk_Kv3GetMemberBool = nullptr;

s2sdk::_Kv3GetMemberChar __s2sdk_Kv3GetMemberChar = nullptr;

s2sdk::_Kv3GetMemberUChar32 __s2sdk_Kv3GetMemberUChar32 = nullptr;

s2sdk::_Kv3GetMemberInt8 __s2sdk_Kv3GetMemberInt8 = nullptr;

s2sdk::_Kv3GetMemberUInt8 __s2sdk_Kv3GetMemberUInt8 = nullptr;

s2sdk::_Kv3GetMemberShort __s2sdk_Kv3GetMemberShort = nullptr;

s2sdk::_Kv3GetMemberUShort __s2sdk_Kv3GetMemberUShort = nullptr;

s2sdk::_Kv3GetMemberInt __s2sdk_Kv3GetMemberInt = nullptr;

s2sdk::_Kv3GetMemberUInt __s2sdk_Kv3GetMemberUInt = nullptr;

s2sdk::_Kv3GetMemberInt64 __s2sdk_Kv3GetMemberInt64 = nullptr;

s2sdk::_Kv3GetMemberUInt64 __s2sdk_Kv3GetMemberUInt64 = nullptr;

s2sdk::_Kv3GetMemberFloat __s2sdk_Kv3GetMemberFloat = nullptr;

s2sdk::_Kv3GetMemberDouble __s2sdk_Kv3GetMemberDouble = nullptr;

s2sdk::_Kv3GetMemberPointer __s2sdk_Kv3GetMemberPointer = nullptr;

s2sdk::_Kv3GetMemberStringToken __s2sdk_Kv3GetMemberStringToken = nullptr;

s2sdk::_Kv3GetMemberEHandle __s2sdk_Kv3GetMemberEHandle = nullptr;

s2sdk::_Kv3GetMemberString __s2sdk_Kv3GetMemberString = nullptr;

s2sdk::_Kv3GetMemberColor __s2sdk_Kv3GetMemberColor = nullptr;

s2sdk::_Kv3GetMemberVector __s2sdk_Kv3GetMemberVector = nullptr;

s2sdk::_Kv3GetMemberVector2D __s2sdk_Kv3GetMemberVector2D = nullptr;

s2sdk::_Kv3GetMemberVector4D __s2sdk_Kv3GetMemberVector4D = nullptr;

s2sdk::_Kv3GetMemberQuaternion __s2sdk_Kv3GetMemberQuaternion = nullptr;

s2sdk::_Kv3GetMemberQAngle __s2sdk_Kv3GetMemberQAngle = nullptr;

s2sdk::_Kv3GetMemberMatrix3x4 __s2sdk_Kv3GetMemberMatrix3x4 = nullptr;

s2sdk::_Kv3SetMemberToNull __s2sdk_Kv3SetMemberToNull = nullptr;

s2sdk::_Kv3SetMemberToEmptyArray __s2sdk_Kv3SetMemberToEmptyArray = nullptr;

s2sdk::_Kv3SetMemberToEmptyTable __s2sdk_Kv3SetMemberToEmptyTable = nullptr;

s2sdk::_Kv3SetMemberToBinaryBlob __s2sdk_Kv3SetMemberToBinaryBlob = nullptr;

s2sdk::_Kv3SetMemberToBinaryBlobExternal __s2sdk_Kv3SetMemberToBinaryBlobExternal = nullptr;

s2sdk::_Kv3SetMemberToCopyOfValue __s2sdk_Kv3SetMemberToCopyOfValue = nullptr;

s2sdk::_Kv3SetMemberBool __s2sdk_Kv3SetMemberBool = nullptr;

s2sdk::_Kv3SetMemberChar __s2sdk_Kv3SetMemberChar = nullptr;

s2sdk::_Kv3SetMemberUChar32 __s2sdk_Kv3SetMemberUChar32 = nullptr;

s2sdk::_Kv3SetMemberInt8 __s2sdk_Kv3SetMemberInt8 = nullptr;

s2sdk::_Kv3SetMemberUInt8 __s2sdk_Kv3SetMemberUInt8 = nullptr;

s2sdk::_Kv3SetMemberShort __s2sdk_Kv3SetMemberShort = nullptr;

s2sdk::_Kv3SetMemberUShort __s2sdk_Kv3SetMemberUShort = nullptr;

s2sdk::_Kv3SetMemberInt __s2sdk_Kv3SetMemberInt = nullptr;

s2sdk::_Kv3SetMemberUInt __s2sdk_Kv3SetMemberUInt = nullptr;

s2sdk::_Kv3SetMemberInt64 __s2sdk_Kv3SetMemberInt64 = nullptr;

s2sdk::_Kv3SetMemberUInt64 __s2sdk_Kv3SetMemberUInt64 = nullptr;

s2sdk::_Kv3SetMemberFloat __s2sdk_Kv3SetMemberFloat = nullptr;

s2sdk::_Kv3SetMemberDouble __s2sdk_Kv3SetMemberDouble = nullptr;

s2sdk::_Kv3SetMemberPointer __s2sdk_Kv3SetMemberPointer = nullptr;

s2sdk::_Kv3SetMemberStringToken __s2sdk_Kv3SetMemberStringToken = nullptr;

s2sdk::_Kv3SetMemberEHandle __s2sdk_Kv3SetMemberEHandle = nullptr;

s2sdk::_Kv3SetMemberString __s2sdk_Kv3SetMemberString = nullptr;

s2sdk::_Kv3SetMemberStringExternal __s2sdk_Kv3SetMemberStringExternal = nullptr;

s2sdk::_Kv3SetMemberColor __s2sdk_Kv3SetMemberColor = nullptr;

s2sdk::_Kv3SetMemberVector __s2sdk_Kv3SetMemberVector = nullptr;

s2sdk::_Kv3SetMemberVector2D __s2sdk_Kv3SetMemberVector2D = nullptr;

s2sdk::_Kv3SetMemberVector4D __s2sdk_Kv3SetMemberVector4D = nullptr;

s2sdk::_Kv3SetMemberQuaternion __s2sdk_Kv3SetMemberQuaternion = nullptr;

s2sdk::_Kv3SetMemberQAngle __s2sdk_Kv3SetMemberQAngle = nullptr;

s2sdk::_Kv3SetMemberMatrix3x4 __s2sdk_Kv3SetMemberMatrix3x4 = nullptr;

s2sdk::_Kv3DebugPrint __s2sdk_Kv3DebugPrint = nullptr;

s2sdk::_Kv3LoadFromBuffer __s2sdk_Kv3LoadFromBuffer = nullptr;

s2sdk::_Kv3Load __s2sdk_Kv3Load = nullptr;

s2sdk::_Kv3LoadFromText __s2sdk_Kv3LoadFromText = nullptr;

s2sdk::_Kv3LoadFromFileToContext __s2sdk_Kv3LoadFromFileToContext = nullptr;

s2sdk::_Kv3LoadFromFile __s2sdk_Kv3LoadFromFile = nullptr;

s2sdk::_Kv3LoadFromJSON __s2sdk_Kv3LoadFromJSON = nullptr;

s2sdk::_Kv3LoadFromJSONFile __s2sdk_Kv3LoadFromJSONFile = nullptr;

s2sdk::_Kv3LoadFromKV1File __s2sdk_Kv3LoadFromKV1File = nullptr;

s2sdk::_Kv3LoadFromKV1Text __s2sdk_Kv3LoadFromKV1Text = nullptr;

s2sdk::_Kv3LoadFromKV1TextTranslated __s2sdk_Kv3LoadFromKV1TextTranslated = nullptr;

s2sdk::_Kv3LoadFromKV3OrKV1 __s2sdk_Kv3LoadFromKV3OrKV1 = nullptr;

s2sdk::_Kv3LoadFromOldSchemaText __s2sdk_Kv3LoadFromOldSchemaText = nullptr;

s2sdk::_Kv3LoadTextNoHeader __s2sdk_Kv3LoadTextNoHeader = nullptr;

s2sdk::_Kv3Save __s2sdk_Kv3Save = nullptr;

s2sdk::_Kv3SaveAsJSON __s2sdk_Kv3SaveAsJSON = nullptr;

s2sdk::_Kv3SaveAsJSONString __s2sdk_Kv3SaveAsJSONString = nullptr;

s2sdk::_Kv3SaveAsKV1Text __s2sdk_Kv3SaveAsKV1Text = nullptr;

s2sdk::_Kv3SaveAsKV1TextTranslated __s2sdk_Kv3SaveAsKV1TextTranslated = nullptr;

s2sdk::_Kv3SaveTextNoHeaderToBuffer __s2sdk_Kv3SaveTextNoHeaderToBuffer = nullptr;

s2sdk::_Kv3SaveTextNoHeader __s2sdk_Kv3SaveTextNoHeader = nullptr;

s2sdk::_Kv3SaveTextToString __s2sdk_Kv3SaveTextToString = nullptr;

s2sdk::_Kv3SaveToFile __s2sdk_Kv3SaveToFile = nullptr;

s2sdk::_DebugBreak __s2sdk_DebugBreak = nullptr;

s2sdk::_DebugDrawBox __s2sdk_DebugDrawBox = nullptr;

s2sdk::_DebugDrawBoxDirection __s2sdk_DebugDrawBoxDirection = nullptr;

s2sdk::_DebugDrawCircle __s2sdk_DebugDrawCircle = nullptr;

s2sdk::_DebugDrawClear __s2sdk_DebugDrawClear = nullptr;

s2sdk::_DebugDrawLine __s2sdk_DebugDrawLine = nullptr;

s2sdk::_DebugDrawLine_vCol __s2sdk_DebugDrawLine_vCol = nullptr;

s2sdk::_DebugDrawScreenTextLine __s2sdk_DebugDrawScreenTextLine = nullptr;

s2sdk::_DebugDrawSphere __s2sdk_DebugDrawSphere = nullptr;

s2sdk::_DebugDrawText __s2sdk_DebugDrawText = nullptr;

s2sdk::_DebugScreenTextPretty __s2sdk_DebugScreenTextPretty = nullptr;

s2sdk::_DebugScriptAssert __s2sdk_DebugScriptAssert = nullptr;

s2sdk::_AnglesDiff __s2sdk_AnglesDiff = nullptr;

s2sdk::_AnglesToVector __s2sdk_AnglesToVector = nullptr;

s2sdk::_AxisAngleToQuaternion __s2sdk_AxisAngleToQuaternion = nullptr;

s2sdk::_CalcClosestPointOnEntityOBB __s2sdk_CalcClosestPointOnEntityOBB = nullptr;

s2sdk::_CalcDistanceBetweenEntityOBB __s2sdk_CalcDistanceBetweenEntityOBB = nullptr;

s2sdk::_CalcDistanceToLineSegment2D __s2sdk_CalcDistanceToLineSegment2D = nullptr;

s2sdk::_CrossVectors __s2sdk_CrossVectors = nullptr;

s2sdk::_ExponentDecay __s2sdk_ExponentDecay = nullptr;

s2sdk::_LerpVectors __s2sdk_LerpVectors = nullptr;

s2sdk::_QSlerp __s2sdk_QSlerp = nullptr;

s2sdk::_RotateOrientation __s2sdk_RotateOrientation = nullptr;

s2sdk::_RotatePosition __s2sdk_RotatePosition = nullptr;

s2sdk::_RotateQuaternionByAxisAngle __s2sdk_RotateQuaternionByAxisAngle = nullptr;

s2sdk::_RotationDelta __s2sdk_RotationDelta = nullptr;

s2sdk::_RotationDeltaAsAngularVelocity __s2sdk_RotationDeltaAsAngularVelocity = nullptr;

s2sdk::_SplineQuaternions __s2sdk_SplineQuaternions = nullptr;

s2sdk::_SplineVectors __s2sdk_SplineVectors = nullptr;

s2sdk::_VectorToAngles __s2sdk_VectorToAngles = nullptr;

s2sdk::_RandomFlt __s2sdk_RandomFlt = nullptr;

s2sdk::_RandomInt __s2sdk_RandomInt = nullptr;

s2sdk::_TraceCollideable __s2sdk_TraceCollideable = nullptr;

s2sdk::_TraceCollideable2 __s2sdk_TraceCollideable2 = nullptr;

s2sdk::_TraceHull __s2sdk_TraceHull = nullptr;

s2sdk::_TraceLine __s2sdk_TraceLine = nullptr;

s2sdk::_SetTransmitInfoEntity __s2sdk_SetTransmitInfoEntity = nullptr;

s2sdk::_ClearTransmitInfoEntity __s2sdk_ClearTransmitInfoEntity = nullptr;

s2sdk::_IsTransmitInfoEntitySet __s2sdk_IsTransmitInfoEntitySet = nullptr;

s2sdk::_SetTransmitInfoEntityAll __s2sdk_SetTransmitInfoEntityAll = nullptr;

s2sdk::_ClearTransmitInfoEntityAll __s2sdk_ClearTransmitInfoEntityAll = nullptr;

s2sdk::_SetTransmitInfoNonPlayer __s2sdk_SetTransmitInfoNonPlayer = nullptr;

s2sdk::_ClearTransmitInfoNonPlayer __s2sdk_ClearTransmitInfoNonPlayer = nullptr;

s2sdk::_IsTransmitInfoNonPlayerSet __s2sdk_IsTransmitInfoNonPlayerSet = nullptr;

s2sdk::_SetTransmitInfoNonPlayerAll __s2sdk_SetTransmitInfoNonPlayerAll = nullptr;

s2sdk::_ClearTransmitInfoNonPlayerAll __s2sdk_ClearTransmitInfoNonPlayerAll = nullptr;

s2sdk::_SetTransmitInfoOutOfPVS __s2sdk_SetTransmitInfoOutOfPVS = nullptr;

s2sdk::_ClearTransmitInfoOutOfPVS __s2sdk_ClearTransmitInfoOutOfPVS = nullptr;

s2sdk::_IsTransmitInfoOutOfPVSSet __s2sdk_IsTransmitInfoOutOfPVSSet = nullptr;

s2sdk::_SetTransmitInfoOutOfPVSAll __s2sdk_SetTransmitInfoOutOfPVSAll = nullptr;

s2sdk::_ClearTransmitInfoOutOfPVSAll __s2sdk_ClearTransmitInfoOutOfPVSAll = nullptr;

s2sdk::_SetTransmitInfoAlways __s2sdk_SetTransmitInfoAlways = nullptr;

s2sdk::_ClearTransmitInfoAlways __s2sdk_ClearTransmitInfoAlways = nullptr;

s2sdk::_IsTransmitInfoAlwaysSet __s2sdk_IsTransmitInfoAlwaysSet = nullptr;

s2sdk::_SetTransmitInfoAlwaysAll __s2sdk_SetTransmitInfoAlwaysAll = nullptr;

s2sdk::_ClearTransmitInfoAlwaysAll __s2sdk_ClearTransmitInfoAlwaysAll = nullptr;

s2sdk::_GetTransmitInfoTargetSlotsCount __s2sdk_GetTransmitInfoTargetSlotsCount = nullptr;

s2sdk::_GetTransmitInfoTargetSlot __s2sdk_GetTransmitInfoTargetSlot = nullptr;

s2sdk::_AddTransmitInfoTargetSlot __s2sdk_AddTransmitInfoTargetSlot = nullptr;

s2sdk::_RemoveTransmitInfoTargetSlot __s2sdk_RemoveTransmitInfoTargetSlot = nullptr;

s2sdk::_GetTransmitInfoTargetSlotsAll __s2sdk_GetTransmitInfoTargetSlotsAll = nullptr;

s2sdk::_RemoveTransmitInfoTargetSlotsAll __s2sdk_RemoveTransmitInfoTargetSlotsAll = nullptr;

s2sdk::_GetTransmitInfoPlayerSlot __s2sdk_GetTransmitInfoPlayerSlot = nullptr;

s2sdk::_SetTransmitInfoPlayerSlot __s2sdk_SetTransmitInfoPlayerSlot = nullptr;

s2sdk::_GetTransmitInfoFullUpdate __s2sdk_GetTransmitInfoFullUpdate = nullptr;

s2sdk::_SetTransmitInfoFullUpdate __s2sdk_SetTransmitInfoFullUpdate = nullptr;

s2sdk::_HideTransmitEntities __s2sdk_HideTransmitEntities = nullptr;

s2sdk::_ShowTransmitEntities __s2sdk_ShowTransmitEntities = nullptr;

s2sdk::_GetHiddenTransmitEntities __s2sdk_GetHiddenTransmitEntities = nullptr;

s2sdk::_HideTransmitEntity __s2sdk_HideTransmitEntity = nullptr;

s2sdk::_ShowTransmitEntity __s2sdk_ShowTransmitEntity = nullptr;

s2sdk::_HideTransmitEntityFromOtherPlayers __s2sdk_HideTransmitEntityFromOtherPlayers = nullptr;

s2sdk::_ShowTransmitEntityToOtherPlayers __s2sdk_ShowTransmitEntityToOtherPlayers = nullptr;

s2sdk::_AddBodyImpulseAtPosition __s2sdk_AddBodyImpulseAtPosition = nullptr;

s2sdk::_AddBodyVelocity __s2sdk_AddBodyVelocity = nullptr;

s2sdk::_DetachBodyFromParent __s2sdk_DetachBodyFromParent = nullptr;

s2sdk::_GetBodySequence __s2sdk_GetBodySequence = nullptr;

s2sdk::_IsBodyAttachedToParent __s2sdk_IsBodyAttachedToParent = nullptr;

s2sdk::_LookupBodySequence __s2sdk_LookupBodySequence = nullptr;

s2sdk::_SetBodySequenceDuration __s2sdk_SetBodySequenceDuration = nullptr;

s2sdk::_SetBodyAngularVelocity __s2sdk_SetBodyAngularVelocity = nullptr;

s2sdk::_SetBodyMaterialGroup __s2sdk_SetBodyMaterialGroup = nullptr;

s2sdk::_SetBodyVelocity __s2sdk_SetBodyVelocity = nullptr;

s2sdk::_EntPointerToPlayerSlot __s2sdk_EntPointerToPlayerSlot = nullptr;

s2sdk::_PlayerSlotToEntPointer __s2sdk_PlayerSlotToEntPointer = nullptr;

s2sdk::_PlayerSlotToEntHandle __s2sdk_PlayerSlotToEntHandle = nullptr;

s2sdk::_PlayerSlotToClientPtr __s2sdk_PlayerSlotToClientPtr = nullptr;

s2sdk::_ClientPtrToPlayerSlot __s2sdk_ClientPtrToPlayerSlot = nullptr;

s2sdk::_PlayerSlotToClientIndex __s2sdk_PlayerSlotToClientIndex = nullptr;

s2sdk::_ClientIndexToPlayerSlot __s2sdk_ClientIndexToPlayerSlot = nullptr;

s2sdk::_PlayerServicesToPlayerSlot __s2sdk_PlayerServicesToPlayerSlot = nullptr;

s2sdk::_GetClientAuthId __s2sdk_GetClientAuthId = nullptr;

s2sdk::_GetClientAccountId __s2sdk_GetClientAccountId = nullptr;

s2sdk::_GetClientSteamID64 __s2sdk_GetClientSteamID64 = nullptr;

s2sdk::_GetClientIp __s2sdk_GetClientIp = nullptr;

s2sdk::_GetClientLanguage __s2sdk_GetClientLanguage = nullptr;

s2sdk::_GetClientLanguageCode __s2sdk_GetClientLanguageCode = nullptr;

s2sdk::_GetClientOS __s2sdk_GetClientOS = nullptr;

s2sdk::_GetClientName __s2sdk_GetClientName = nullptr;

s2sdk::_SetClientName __s2sdk_SetClientName = nullptr;

s2sdk::_GetClientTime __s2sdk_GetClientTime = nullptr;

s2sdk::_GetClientLatency __s2sdk_GetClientLatency = nullptr;

s2sdk::_GetUserFlagBits __s2sdk_GetUserFlagBits = nullptr;

s2sdk::_SetUserFlagBits __s2sdk_SetUserFlagBits = nullptr;

s2sdk::_AddUserFlags __s2sdk_AddUserFlags = nullptr;

s2sdk::_RemoveUserFlags __s2sdk_RemoveUserFlags = nullptr;

s2sdk::_IsClientAuthorized __s2sdk_IsClientAuthorized = nullptr;

s2sdk::_IsClientConnected __s2sdk_IsClientConnected = nullptr;

s2sdk::_IsClientInGame __s2sdk_IsClientInGame = nullptr;

s2sdk::_IsClientSourceTV __s2sdk_IsClientSourceTV = nullptr;

s2sdk::_IsClientAlive __s2sdk_IsClientAlive = nullptr;

s2sdk::_IsFakeClient __s2sdk_IsFakeClient = nullptr;

s2sdk::_GetClientMoveType __s2sdk_GetClientMoveType = nullptr;

s2sdk::_SetClientMoveType __s2sdk_SetClientMoveType = nullptr;

s2sdk::_GetClientGravity __s2sdk_GetClientGravity = nullptr;

s2sdk::_SetClientGravity __s2sdk_SetClientGravity = nullptr;

s2sdk::_GetClientFlags __s2sdk_GetClientFlags = nullptr;

s2sdk::_SetClientFlags __s2sdk_SetClientFlags = nullptr;

s2sdk::_GetClientRenderColor __s2sdk_GetClientRenderColor = nullptr;

s2sdk::_SetClientRenderColor __s2sdk_SetClientRenderColor = nullptr;

s2sdk::_GetClientRenderMode __s2sdk_GetClientRenderMode = nullptr;

s2sdk::_SetClientRenderMode __s2sdk_SetClientRenderMode = nullptr;

s2sdk::_GetClientMass __s2sdk_GetClientMass = nullptr;

s2sdk::_SetClientMass __s2sdk_SetClientMass = nullptr;

s2sdk::_GetClientFriction __s2sdk_GetClientFriction = nullptr;

s2sdk::_SetClientFriction __s2sdk_SetClientFriction = nullptr;

s2sdk::_GetClientHealth __s2sdk_GetClientHealth = nullptr;

s2sdk::_SetClientHealth __s2sdk_SetClientHealth = nullptr;

s2sdk::_GetClientMaxHealth __s2sdk_GetClientMaxHealth = nullptr;

s2sdk::_SetClientMaxHealth __s2sdk_SetClientMaxHealth = nullptr;

s2sdk::_GetClientTeam __s2sdk_GetClientTeam = nullptr;

s2sdk::_SetClientTeam __s2sdk_SetClientTeam = nullptr;

s2sdk::_GetClientAbsOrigin __s2sdk_GetClientAbsOrigin = nullptr;

s2sdk::_SetClientAbsOrigin __s2sdk_SetClientAbsOrigin = nullptr;

s2sdk::_GetClientAbsScale __s2sdk_GetClientAbsScale = nullptr;

s2sdk::_SetClientAbsScale __s2sdk_SetClientAbsScale = nullptr;

s2sdk::_GetClientAbsAngles __s2sdk_GetClientAbsAngles = nullptr;

s2sdk::_SetClientAbsAngles __s2sdk_SetClientAbsAngles = nullptr;

s2sdk::_GetClientLocalOrigin __s2sdk_GetClientLocalOrigin = nullptr;

s2sdk::_SetClientLocalOrigin __s2sdk_SetClientLocalOrigin = nullptr;

s2sdk::_GetClientLocalScale __s2sdk_GetClientLocalScale = nullptr;

s2sdk::_SetClientLocalScale __s2sdk_SetClientLocalScale = nullptr;

s2sdk::_GetClientLocalAngles __s2sdk_GetClientLocalAngles = nullptr;

s2sdk::_SetClientLocalAngles __s2sdk_SetClientLocalAngles = nullptr;

s2sdk::_GetClientAbsVelocity __s2sdk_GetClientAbsVelocity = nullptr;

s2sdk::_SetClientAbsVelocity __s2sdk_SetClientAbsVelocity = nullptr;

s2sdk::_GetClientBaseVelocity __s2sdk_GetClientBaseVelocity = nullptr;

s2sdk::_GetClientLocalAngVelocity __s2sdk_GetClientLocalAngVelocity = nullptr;

s2sdk::_GetClientAngVelocity __s2sdk_GetClientAngVelocity = nullptr;

s2sdk::_SetClientAngVelocity __s2sdk_SetClientAngVelocity = nullptr;

s2sdk::_GetClientLocalVelocity __s2sdk_GetClientLocalVelocity = nullptr;

s2sdk::_GetClientAngRotation __s2sdk_GetClientAngRotation = nullptr;

s2sdk::_SetClientAngRotation __s2sdk_SetClientAngRotation = nullptr;

s2sdk::_TransformPointClientToWorld __s2sdk_TransformPointClientToWorld = nullptr;

s2sdk::_TransformPointWorldToClient __s2sdk_TransformPointWorldToClient = nullptr;

s2sdk::_GetClientEyePosition __s2sdk_GetClientEyePosition = nullptr;

s2sdk::_GetClientEyeAngles __s2sdk_GetClientEyeAngles = nullptr;

s2sdk::_SetClientForwardVector __s2sdk_SetClientForwardVector = nullptr;

s2sdk::_GetClientForwardVector __s2sdk_GetClientForwardVector = nullptr;

s2sdk::_GetClientLeftVector __s2sdk_GetClientLeftVector = nullptr;

s2sdk::_GetClientRightVector __s2sdk_GetClientRightVector = nullptr;

s2sdk::_GetClientUpVector __s2sdk_GetClientUpVector = nullptr;

s2sdk::_GetClientTransform __s2sdk_GetClientTransform = nullptr;

s2sdk::_GetClientModel __s2sdk_GetClientModel = nullptr;

s2sdk::_SetClientModel __s2sdk_SetClientModel = nullptr;

s2sdk::_GetClientWaterLevel __s2sdk_GetClientWaterLevel = nullptr;

s2sdk::_GetClientGroundEntity __s2sdk_GetClientGroundEntity = nullptr;

s2sdk::_GetClientEffects __s2sdk_GetClientEffects = nullptr;

s2sdk::_AddClientEffects __s2sdk_AddClientEffects = nullptr;

s2sdk::_RemoveClientEffects __s2sdk_RemoveClientEffects = nullptr;

s2sdk::_GetClientBoundingMaxs __s2sdk_GetClientBoundingMaxs = nullptr;

s2sdk::_GetClientBoundingMins __s2sdk_GetClientBoundingMins = nullptr;

s2sdk::_GetClientCenter __s2sdk_GetClientCenter = nullptr;

s2sdk::_TeleportClient __s2sdk_TeleportClient = nullptr;

s2sdk::_ApplyAbsVelocityImpulseToClient __s2sdk_ApplyAbsVelocityImpulseToClient = nullptr;

s2sdk::_ApplyLocalAngularVelocityImpulseToClient __s2sdk_ApplyLocalAngularVelocityImpulseToClient = nullptr;

s2sdk::_AcceptClientInput __s2sdk_AcceptClientInput = nullptr;

s2sdk::_ConnectClientOutput __s2sdk_ConnectClientOutput = nullptr;

s2sdk::_DisconnectClientOutput __s2sdk_DisconnectClientOutput = nullptr;

s2sdk::_DisconnectClientRedirectedOutput __s2sdk_DisconnectClientRedirectedOutput = nullptr;

s2sdk::_FireClientOutput __s2sdk_FireClientOutput = nullptr;

s2sdk::_RedirectClientOutput __s2sdk_RedirectClientOutput = nullptr;

s2sdk::_FollowClient __s2sdk_FollowClient = nullptr;

s2sdk::_FollowClientMerge __s2sdk_FollowClientMerge = nullptr;

s2sdk::_TakeClientDamage __s2sdk_TakeClientDamage = nullptr;

s2sdk::_GetClientPawn __s2sdk_GetClientPawn = nullptr;

s2sdk::_ProcessTargetString __s2sdk_ProcessTargetString = nullptr;

s2sdk::_SwitchClientTeam __s2sdk_SwitchClientTeam = nullptr;

s2sdk::_ChangeClientTeam __s2sdk_ChangeClientTeam = nullptr;

s2sdk::_RespawnClient __s2sdk_RespawnClient = nullptr;

s2sdk::_ForcePlayerSuicide __s2sdk_ForcePlayerSuicide = nullptr;

s2sdk::_KickClient __s2sdk_KickClient = nullptr;

s2sdk::_BanClient __s2sdk_BanClient = nullptr;

s2sdk::_BanIdentity __s2sdk_BanIdentity = nullptr;

s2sdk::_GetClientActiveWeapon __s2sdk_GetClientActiveWeapon = nullptr;

s2sdk::_GetClientWeapons __s2sdk_GetClientWeapons = nullptr;

s2sdk::_RemoveWeapons __s2sdk_RemoveWeapons = nullptr;

s2sdk::_DropWeapon __s2sdk_DropWeapon = nullptr;

s2sdk::_SelectWeapon __s2sdk_SelectWeapon = nullptr;

s2sdk::_SwitchWeapon __s2sdk_SwitchWeapon = nullptr;

s2sdk::_RemoveWeapon __s2sdk_RemoveWeapon = nullptr;

s2sdk::_GiveNamedItem __s2sdk_GiveNamedItem = nullptr;

s2sdk::_GetClientButtons __s2sdk_GetClientButtons = nullptr;

s2sdk::_GetClientArmor __s2sdk_GetClientArmor = nullptr;

s2sdk::_SetClientArmor __s2sdk_SetClientArmor = nullptr;

s2sdk::_GetClientSpeed __s2sdk_GetClientSpeed = nullptr;

s2sdk::_SetClientSpeed __s2sdk_SetClientSpeed = nullptr;

s2sdk::_GetClientMoney __s2sdk_GetClientMoney = nullptr;

s2sdk::_SetClientMoney __s2sdk_SetClientMoney = nullptr;

s2sdk::_GetClientKills __s2sdk_GetClientKills = nullptr;

s2sdk::_SetClientKills __s2sdk_SetClientKills = nullptr;

s2sdk::_GetClientDeaths __s2sdk_GetClientDeaths = nullptr;

s2sdk::_SetClientDeaths __s2sdk_SetClientDeaths = nullptr;

s2sdk::_GetClientAssists __s2sdk_GetClientAssists = nullptr;

s2sdk::_SetClientAssists __s2sdk_SetClientAssists = nullptr;

s2sdk::_GetClientDamage __s2sdk_GetClientDamage = nullptr;

s2sdk::_SetClientDamage __s2sdk_SetClientDamage = nullptr;

s2sdk::_AddAdminCommand __s2sdk_AddAdminCommand = nullptr;

s2sdk::_AddConsoleCommand __s2sdk_AddConsoleCommand = nullptr;

s2sdk::_RemoveCommand __s2sdk_RemoveCommand = nullptr;

s2sdk::_AddCommandListener __s2sdk_AddCommandListener = nullptr;

s2sdk::_RemoveCommandListener __s2sdk_RemoveCommandListener = nullptr;

s2sdk::_ServerCommand __s2sdk_ServerCommand = nullptr;

s2sdk::_ServerCommandEx __s2sdk_ServerCommandEx = nullptr;

s2sdk::_ClientCommand __s2sdk_ClientCommand = nullptr;

s2sdk::_FakeClientCommand __s2sdk_FakeClientCommand = nullptr;

s2sdk::_GetAllConCommands __s2sdk_GetAllConCommands = nullptr;

s2sdk::_GetAllCommands __s2sdk_GetAllCommands = nullptr;

s2sdk::_PrintToServer __s2sdk_PrintToServer = nullptr;

s2sdk::_PrintToConsole __s2sdk_PrintToConsole = nullptr;

s2sdk::_PrintToChat __s2sdk_PrintToChat = nullptr;

s2sdk::_PrintCenterText __s2sdk_PrintCenterText = nullptr;

s2sdk::_PrintAlertText __s2sdk_PrintAlertText = nullptr;

s2sdk::_PrintCentreHtml __s2sdk_PrintCentreHtml = nullptr;

s2sdk::_PrintToConsoleAll __s2sdk_PrintToConsoleAll = nullptr;

s2sdk::_PrintToChatAll __s2sdk_PrintToChatAll = nullptr;

s2sdk::_PrintCenterTextAll __s2sdk_PrintCenterTextAll = nullptr;

s2sdk::_PrintAlertTextAll __s2sdk_PrintAlertTextAll = nullptr;

s2sdk::_PrintCentreHtmlAll __s2sdk_PrintCentreHtmlAll = nullptr;

s2sdk::_PrintToChatColored __s2sdk_PrintToChatColored = nullptr;

s2sdk::_PrintToChatColoredAll __s2sdk_PrintToChatColoredAll = nullptr;

s2sdk::_ReplyToCommand __s2sdk_ReplyToCommand = nullptr;

s2sdk::_CreateConVar __s2sdk_CreateConVar = nullptr;

s2sdk::_CreateConVarBool __s2sdk_CreateConVarBool = nullptr;

s2sdk::_CreateConVarInt16 __s2sdk_CreateConVarInt16 = nullptr;

s2sdk::_CreateConVarUInt16 __s2sdk_CreateConVarUInt16 = nullptr;

s2sdk::_CreateConVarInt32 __s2sdk_CreateConVarInt32 = nullptr;

s2sdk::_CreateConVarUInt32 __s2sdk_CreateConVarUInt32 = nullptr;

s2sdk::_CreateConVarInt64 __s2sdk_CreateConVarInt64 = nullptr;

s2sdk::_CreateConVarUInt64 __s2sdk_CreateConVarUInt64 = nullptr;

s2sdk::_CreateConVarFloat __s2sdk_CreateConVarFloat = nullptr;

s2sdk::_CreateConVarDouble __s2sdk_CreateConVarDouble = nullptr;

s2sdk::_CreateConVarColor __s2sdk_CreateConVarColor = nullptr;

s2sdk::_CreateConVarVector2 __s2sdk_CreateConVarVector2 = nullptr;

s2sdk::_CreateConVarVector3 __s2sdk_CreateConVarVector3 = nullptr;

s2sdk::_CreateConVarVector4 __s2sdk_CreateConVarVector4 = nullptr;

s2sdk::_CreateConVarQAngle __s2sdk_CreateConVarQAngle = nullptr;

s2sdk::_CreateConVarString __s2sdk_CreateConVarString = nullptr;

s2sdk::_FindConVar __s2sdk_FindConVar = nullptr;

s2sdk::_FindConVar2 __s2sdk_FindConVar2 = nullptr;

s2sdk::_HookConVarChange __s2sdk_HookConVarChange = nullptr;

s2sdk::_UnhookConVarChange __s2sdk_UnhookConVarChange = nullptr;

s2sdk::_IsConVarFlagSet __s2sdk_IsConVarFlagSet = nullptr;

s2sdk::_AddConVarFlags __s2sdk_AddConVarFlags = nullptr;

s2sdk::_RemoveConVarFlags __s2sdk_RemoveConVarFlags = nullptr;

s2sdk::_GetConVarFlags __s2sdk_GetConVarFlags = nullptr;

s2sdk::_GetConVarBounds __s2sdk_GetConVarBounds = nullptr;

s2sdk::_SetConVarBounds __s2sdk_SetConVarBounds = nullptr;

s2sdk::_GetConVarDefault __s2sdk_GetConVarDefault = nullptr;

s2sdk::_SetConVarDefault __s2sdk_SetConVarDefault = nullptr;

s2sdk::_GetConVarValue __s2sdk_GetConVarValue = nullptr;

s2sdk::_GetConVar __s2sdk_GetConVar = nullptr;

s2sdk::_GetConVarBool __s2sdk_GetConVarBool = nullptr;

s2sdk::_GetConVarInt16 __s2sdk_GetConVarInt16 = nullptr;

s2sdk::_GetConVarUInt16 __s2sdk_GetConVarUInt16 = nullptr;

s2sdk::_GetConVarInt32 __s2sdk_GetConVarInt32 = nullptr;

s2sdk::_GetConVarUInt32 __s2sdk_GetConVarUInt32 = nullptr;

s2sdk::_GetConVarInt64 __s2sdk_GetConVarInt64 = nullptr;

s2sdk::_GetConVarUInt64 __s2sdk_GetConVarUInt64 = nullptr;

s2sdk::_GetConVarFloat __s2sdk_GetConVarFloat = nullptr;

s2sdk::_GetConVarDouble __s2sdk_GetConVarDouble = nullptr;

s2sdk::_GetConVarString __s2sdk_GetConVarString = nullptr;

s2sdk::_GetConVarColor __s2sdk_GetConVarColor = nullptr;

s2sdk::_GetConVarVector2 __s2sdk_GetConVarVector2 = nullptr;

s2sdk::_GetConVarVector __s2sdk_GetConVarVector = nullptr;

s2sdk::_GetConVarVector4 __s2sdk_GetConVarVector4 = nullptr;

s2sdk::_GetConVarQAngle __s2sdk_GetConVarQAngle = nullptr;

s2sdk::_SetConVarValue __s2sdk_SetConVarValue = nullptr;

s2sdk::_SetConVar __s2sdk_SetConVar = nullptr;

s2sdk::_SetConVarBool __s2sdk_SetConVarBool = nullptr;

s2sdk::_SetConVarInt16 __s2sdk_SetConVarInt16 = nullptr;

s2sdk::_SetConVarUInt16 __s2sdk_SetConVarUInt16 = nullptr;

s2sdk::_SetConVarInt32 __s2sdk_SetConVarInt32 = nullptr;

s2sdk::_SetConVarUInt32 __s2sdk_SetConVarUInt32 = nullptr;

s2sdk::_SetConVarInt64 __s2sdk_SetConVarInt64 = nullptr;

s2sdk::_SetConVarUInt64 __s2sdk_SetConVarUInt64 = nullptr;

s2sdk::_SetConVarFloat __s2sdk_SetConVarFloat = nullptr;

s2sdk::_SetConVarDouble __s2sdk_SetConVarDouble = nullptr;

s2sdk::_SetConVarString __s2sdk_SetConVarString = nullptr;

s2sdk::_SetConVarColor __s2sdk_SetConVarColor = nullptr;

s2sdk::_SetConVarVector2 __s2sdk_SetConVarVector2 = nullptr;

s2sdk::_SetConVarVector3 __s2sdk_SetConVarVector3 = nullptr;

s2sdk::_SetConVarVector4 __s2sdk_SetConVarVector4 = nullptr;

s2sdk::_SetConVarQAngle __s2sdk_SetConVarQAngle = nullptr;

s2sdk::_SendConVarValue __s2sdk_SendConVarValue = nullptr;

s2sdk::_SendConVarValue2 __s2sdk_SendConVarValue2 = nullptr;

s2sdk::_GetClientConVarValue __s2sdk_GetClientConVarValue = nullptr;

s2sdk::_SetFakeClientConVarValue __s2sdk_SetFakeClientConVarValue = nullptr;

s2sdk::_QueryClientConVar __s2sdk_QueryClientConVar = nullptr;

s2sdk::_AutoExecConfig __s2sdk_AutoExecConfig = nullptr;

s2sdk::_GetServerLanguage __s2sdk_GetServerLanguage = nullptr;

s2sdk::_GetAllConVars __s2sdk_GetAllConVars = nullptr;

s2sdk::_QueryInterface __s2sdk_QueryInterface = nullptr;

s2sdk::_GetGameDirectory __s2sdk_GetGameDirectory = nullptr;

s2sdk::_ReadFileVPK __s2sdk_ReadFileVPK = nullptr;

s2sdk::_FindFileAbsoluteList __s2sdk_FindFileAbsoluteList = nullptr;

s2sdk::_GetCurrentMap __s2sdk_GetCurrentMap = nullptr;

s2sdk::_IsMapValid __s2sdk_IsMapValid = nullptr;

s2sdk::_GetGameTime __s2sdk_GetGameTime = nullptr;

s2sdk::_GetGameTickCount __s2sdk_GetGameTickCount = nullptr;

s2sdk::_GetGameFrameTime __s2sdk_GetGameFrameTime = nullptr;

s2sdk::_GetEngineTime __s2sdk_GetEngineTime = nullptr;

s2sdk::_GetMaxClients __s2sdk_GetMaxClients = nullptr;

s2sdk::_Precache __s2sdk_Precache = nullptr;

s2sdk::_IsPrecached __s2sdk_IsPrecached = nullptr;

s2sdk::_GetEconItemSystem __s2sdk_GetEconItemSystem = nullptr;

s2sdk::_IsServerPaused __s2sdk_IsServerPaused = nullptr;

s2sdk::_QueueTaskForNextFrame __s2sdk_QueueTaskForNextFrame = nullptr;

s2sdk::_QueueTaskForNextWorldUpdate __s2sdk_QueueTaskForNextWorldUpdate = nullptr;

s2sdk::_GetSoundDuration __s2sdk_GetSoundDuration = nullptr;

s2sdk::_EmitSound __s2sdk_EmitSound = nullptr;

s2sdk::_StopSound __s2sdk_StopSound = nullptr;

s2sdk::_EmitSoundToClient __s2sdk_EmitSoundToClient = nullptr;

s2sdk::_GetPublicAddress __s2sdk_GetPublicAddress = nullptr;

s2sdk::_GetLocalAddress __s2sdk_GetLocalAddress = nullptr;

s2sdk::_EntIndexToEntPointer __s2sdk_EntIndexToEntPointer = nullptr;

s2sdk::_EntPointerToEntIndex __s2sdk_EntPointerToEntIndex = nullptr;

s2sdk::_EntPointerToEntHandle __s2sdk_EntPointerToEntHandle = nullptr;

s2sdk::_EntHandleToEntPointer __s2sdk_EntHandleToEntPointer = nullptr;

s2sdk::_EntIndexToEntHandle __s2sdk_EntIndexToEntHandle = nullptr;

s2sdk::_EntHandleToEntIndex __s2sdk_EntHandleToEntIndex = nullptr;

s2sdk::_IsValidEntHandle __s2sdk_IsValidEntHandle = nullptr;

s2sdk::_IsValidEntPointer __s2sdk_IsValidEntPointer = nullptr;

s2sdk::_GetFirstActiveEntity __s2sdk_GetFirstActiveEntity = nullptr;

s2sdk::_GetPrevActiveEntity __s2sdk_GetPrevActiveEntity = nullptr;

s2sdk::_GetNextActiveEntity __s2sdk_GetNextActiveEntity = nullptr;

s2sdk::_GetPointScriptHandle __s2sdk_GetPointScriptHandle = nullptr;

s2sdk::_HookEntityOutput __s2sdk_HookEntityOutput = nullptr;

s2sdk::_UnhookEntityOutput __s2sdk_UnhookEntityOutput = nullptr;

s2sdk::_FindEntityByClassname __s2sdk_FindEntityByClassname = nullptr;

s2sdk::_FindEntityByClassnameNearest __s2sdk_FindEntityByClassnameNearest = nullptr;

s2sdk::_FindEntityByClassnameWithin __s2sdk_FindEntityByClassnameWithin = nullptr;

s2sdk::_FindEntityByName __s2sdk_FindEntityByName = nullptr;

s2sdk::_FindEntityByNameNearest __s2sdk_FindEntityByNameNearest = nullptr;

s2sdk::_FindEntityByNameWithin __s2sdk_FindEntityByNameWithin = nullptr;

s2sdk::_FindEntityByTarget __s2sdk_FindEntityByTarget = nullptr;

s2sdk::_FindEntityInSphere __s2sdk_FindEntityInSphere = nullptr;

s2sdk::_SpawnEntityByName __s2sdk_SpawnEntityByName = nullptr;

s2sdk::_CreateEntityByName __s2sdk_CreateEntityByName = nullptr;

s2sdk::_DispatchSpawn __s2sdk_DispatchSpawn = nullptr;

s2sdk::_DispatchSpawn2 __s2sdk_DispatchSpawn2 = nullptr;

s2sdk::_RemoveEntity __s2sdk_RemoveEntity = nullptr;

s2sdk::_IsEntityPlayerController __s2sdk_IsEntityPlayerController = nullptr;

s2sdk::_IsEntityPlayerPawn __s2sdk_IsEntityPlayerPawn = nullptr;

s2sdk::_GetEntityClassname __s2sdk_GetEntityClassname = nullptr;

s2sdk::_GetEntityName __s2sdk_GetEntityName = nullptr;

s2sdk::_SetEntityName __s2sdk_SetEntityName = nullptr;

s2sdk::_GetEntityMoveType __s2sdk_GetEntityMoveType = nullptr;

s2sdk::_SetEntityMoveType __s2sdk_SetEntityMoveType = nullptr;

s2sdk::_GetEntityGravity __s2sdk_GetEntityGravity = nullptr;

s2sdk::_SetEntityGravity __s2sdk_SetEntityGravity = nullptr;

s2sdk::_GetEntityFlags __s2sdk_GetEntityFlags = nullptr;

s2sdk::_SetEntityFlags __s2sdk_SetEntityFlags = nullptr;

s2sdk::_GetEntityRenderColor __s2sdk_GetEntityRenderColor = nullptr;

s2sdk::_SetEntityRenderColor __s2sdk_SetEntityRenderColor = nullptr;

s2sdk::_GetEntityRenderMode __s2sdk_GetEntityRenderMode = nullptr;

s2sdk::_SetEntityRenderMode __s2sdk_SetEntityRenderMode = nullptr;

s2sdk::_GetEntityMass __s2sdk_GetEntityMass = nullptr;

s2sdk::_SetEntityMass __s2sdk_SetEntityMass = nullptr;

s2sdk::_GetEntityFriction __s2sdk_GetEntityFriction = nullptr;

s2sdk::_SetEntityFriction __s2sdk_SetEntityFriction = nullptr;

s2sdk::_GetEntityHealth __s2sdk_GetEntityHealth = nullptr;

s2sdk::_SetEntityHealth __s2sdk_SetEntityHealth = nullptr;

s2sdk::_GetEntityMaxHealth __s2sdk_GetEntityMaxHealth = nullptr;

s2sdk::_SetEntityMaxHealth __s2sdk_SetEntityMaxHealth = nullptr;

s2sdk::_GetEntityTeam __s2sdk_GetEntityTeam = nullptr;

s2sdk::_SetEntityTeam __s2sdk_SetEntityTeam = nullptr;

s2sdk::_GetEntityOwner __s2sdk_GetEntityOwner = nullptr;

s2sdk::_SetEntityOwner __s2sdk_SetEntityOwner = nullptr;

s2sdk::_GetEntityParent __s2sdk_GetEntityParent = nullptr;

s2sdk::_SetEntityParent __s2sdk_SetEntityParent = nullptr;

s2sdk::_SetEntityParentAttachment __s2sdk_SetEntityParentAttachment = nullptr;

s2sdk::_GetEntityAbsOrigin __s2sdk_GetEntityAbsOrigin = nullptr;

s2sdk::_SetEntityAbsOrigin __s2sdk_SetEntityAbsOrigin = nullptr;

s2sdk::_GetEntityAbsScale __s2sdk_GetEntityAbsScale = nullptr;

s2sdk::_SetEntityAbsScale __s2sdk_SetEntityAbsScale = nullptr;

s2sdk::_GetEntityAbsAngles __s2sdk_GetEntityAbsAngles = nullptr;

s2sdk::_SetEntityAbsAngles __s2sdk_SetEntityAbsAngles = nullptr;

s2sdk::_GetEntityLocalOrigin __s2sdk_GetEntityLocalOrigin = nullptr;

s2sdk::_SetEntityLocalOrigin __s2sdk_SetEntityLocalOrigin = nullptr;

s2sdk::_GetEntityLocalScale __s2sdk_GetEntityLocalScale = nullptr;

s2sdk::_SetEntityLocalScale __s2sdk_SetEntityLocalScale = nullptr;

s2sdk::_GetEntityLocalAngles __s2sdk_GetEntityLocalAngles = nullptr;

s2sdk::_SetEntityLocalAngles __s2sdk_SetEntityLocalAngles = nullptr;

s2sdk::_GetEntityAbsVelocity __s2sdk_GetEntityAbsVelocity = nullptr;

s2sdk::_SetEntityAbsVelocity __s2sdk_SetEntityAbsVelocity = nullptr;

s2sdk::_GetEntityBaseVelocity __s2sdk_GetEntityBaseVelocity = nullptr;

s2sdk::_GetEntityLocalAngVelocity __s2sdk_GetEntityLocalAngVelocity = nullptr;

s2sdk::_GetEntityAngVelocity __s2sdk_GetEntityAngVelocity = nullptr;

s2sdk::_SetEntityAngVelocity __s2sdk_SetEntityAngVelocity = nullptr;

s2sdk::_GetEntityLocalVelocity __s2sdk_GetEntityLocalVelocity = nullptr;

s2sdk::_GetEntityAngRotation __s2sdk_GetEntityAngRotation = nullptr;

s2sdk::_SetEntityAngRotation __s2sdk_SetEntityAngRotation = nullptr;

s2sdk::_TransformPointEntityToWorld __s2sdk_TransformPointEntityToWorld = nullptr;

s2sdk::_TransformPointWorldToEntity __s2sdk_TransformPointWorldToEntity = nullptr;

s2sdk::_GetEntityEyePosition __s2sdk_GetEntityEyePosition = nullptr;

s2sdk::_GetEntityEyeAngles __s2sdk_GetEntityEyeAngles = nullptr;

s2sdk::_SetEntityForwardVector __s2sdk_SetEntityForwardVector = nullptr;

s2sdk::_GetEntityForwardVector __s2sdk_GetEntityForwardVector = nullptr;

s2sdk::_GetEntityLeftVector __s2sdk_GetEntityLeftVector = nullptr;

s2sdk::_GetEntityRightVector __s2sdk_GetEntityRightVector = nullptr;

s2sdk::_GetEntityUpVector __s2sdk_GetEntityUpVector = nullptr;

s2sdk::_GetEntityTransform __s2sdk_GetEntityTransform = nullptr;

s2sdk::_GetEntityModel __s2sdk_GetEntityModel = nullptr;

s2sdk::_SetEntityModel __s2sdk_SetEntityModel = nullptr;

s2sdk::_GetEntityWaterLevel __s2sdk_GetEntityWaterLevel = nullptr;

s2sdk::_GetEntityGroundEntity __s2sdk_GetEntityGroundEntity = nullptr;

s2sdk::_GetEntityEffects __s2sdk_GetEntityEffects = nullptr;

s2sdk::_AddEntityEffects __s2sdk_AddEntityEffects = nullptr;

s2sdk::_RemoveEntityEffects __s2sdk_RemoveEntityEffects = nullptr;

s2sdk::_GetEntityBoundingMaxs __s2sdk_GetEntityBoundingMaxs = nullptr;

s2sdk::_GetEntityBoundingMins __s2sdk_GetEntityBoundingMins = nullptr;

s2sdk::_GetEntityCenter __s2sdk_GetEntityCenter = nullptr;

s2sdk::_TeleportEntity __s2sdk_TeleportEntity = nullptr;

s2sdk::_ApplyAbsVelocityImpulseToEntity __s2sdk_ApplyAbsVelocityImpulseToEntity = nullptr;

s2sdk::_ApplyLocalAngularVelocityImpulseToEntity __s2sdk_ApplyLocalAngularVelocityImpulseToEntity = nullptr;

s2sdk::_AcceptEntityInput __s2sdk_AcceptEntityInput = nullptr;

s2sdk::_ConnectEntityOutput __s2sdk_ConnectEntityOutput = nullptr;

s2sdk::_DisconnectEntityOutput __s2sdk_DisconnectEntityOutput = nullptr;

s2sdk::_DisconnectEntityRedirectedOutput __s2sdk_DisconnectEntityRedirectedOutput = nullptr;

s2sdk::_FireEntityOutput __s2sdk_FireEntityOutput = nullptr;

s2sdk::_RedirectEntityOutput __s2sdk_RedirectEntityOutput = nullptr;

s2sdk::_FollowEntity __s2sdk_FollowEntity = nullptr;

s2sdk::_FollowEntityMerge __s2sdk_FollowEntityMerge = nullptr;

s2sdk::_TakeEntityDamage __s2sdk_TakeEntityDamage = nullptr;

s2sdk::_GetEntityAttributeFloatValue __s2sdk_GetEntityAttributeFloatValue = nullptr;

s2sdk::_GetEntityAttributeIntValue __s2sdk_GetEntityAttributeIntValue = nullptr;

s2sdk::_SetEntityAttributeFloatValue __s2sdk_SetEntityAttributeFloatValue = nullptr;

s2sdk::_SetEntityAttributeIntValue __s2sdk_SetEntityAttributeIntValue = nullptr;

s2sdk::_DeleteEntityAttribute __s2sdk_DeleteEntityAttribute = nullptr;

s2sdk::_HasEntityAttribute __s2sdk_HasEntityAttribute = nullptr;

s2sdk::_HookEvent __s2sdk_HookEvent = nullptr;

s2sdk::_UnhookEvent __s2sdk_UnhookEvent = nullptr;

s2sdk::_CreateEvent __s2sdk_CreateEvent = nullptr;

s2sdk::_FireEvent __s2sdk_FireEvent = nullptr;

s2sdk::_FireEventToClient __s2sdk_FireEventToClient = nullptr;

s2sdk::_CancelCreatedEvent __s2sdk_CancelCreatedEvent = nullptr;

s2sdk::_GetEventBool __s2sdk_GetEventBool = nullptr;

s2sdk::_GetEventFloat __s2sdk_GetEventFloat = nullptr;

s2sdk::_GetEventInt __s2sdk_GetEventInt = nullptr;

s2sdk::_GetEventUInt64 __s2sdk_GetEventUInt64 = nullptr;

s2sdk::_GetEventString __s2sdk_GetEventString = nullptr;

s2sdk::_GetEventPtr __s2sdk_GetEventPtr = nullptr;

s2sdk::_GetEventPlayerController __s2sdk_GetEventPlayerController = nullptr;

s2sdk::_GetEventPlayerIndex __s2sdk_GetEventPlayerIndex = nullptr;

s2sdk::_GetEventPlayerSlot __s2sdk_GetEventPlayerSlot = nullptr;

s2sdk::_GetEventPlayerPawn __s2sdk_GetEventPlayerPawn = nullptr;

s2sdk::_GetEventEntity __s2sdk_GetEventEntity = nullptr;

s2sdk::_GetEventEntityIndex __s2sdk_GetEventEntityIndex = nullptr;

s2sdk::_GetEventEntityHandle __s2sdk_GetEventEntityHandle = nullptr;

s2sdk::_GetEventName __s2sdk_GetEventName = nullptr;

s2sdk::_SetEventBool __s2sdk_SetEventBool = nullptr;

s2sdk::_SetEventFloat __s2sdk_SetEventFloat = nullptr;

s2sdk::_SetEventInt __s2sdk_SetEventInt = nullptr;

s2sdk::_SetEventUInt64 __s2sdk_SetEventUInt64 = nullptr;

s2sdk::_SetEventString __s2sdk_SetEventString = nullptr;

s2sdk::_SetEventPtr __s2sdk_SetEventPtr = nullptr;

s2sdk::_SetEventPlayerController __s2sdk_SetEventPlayerController = nullptr;

s2sdk::_SetEventPlayerIndex __s2sdk_SetEventPlayerIndex = nullptr;

s2sdk::_SetEventPlayerSlot __s2sdk_SetEventPlayerSlot = nullptr;

s2sdk::_SetEventEntity __s2sdk_SetEventEntity = nullptr;

s2sdk::_SetEventEntityIndex __s2sdk_SetEventEntityIndex = nullptr;

s2sdk::_SetEventEntityHandle __s2sdk_SetEventEntityHandle = nullptr;

s2sdk::_SetEventBroadcast __s2sdk_SetEventBroadcast = nullptr;

s2sdk::_LoadEventsFromFile __s2sdk_LoadEventsFromFile = nullptr;

s2sdk::_CloseGameConfigFile __s2sdk_CloseGameConfigFile = nullptr;

s2sdk::_LoadGameConfigFile __s2sdk_LoadGameConfigFile = nullptr;

s2sdk::_GetGameConfigPatch __s2sdk_GetGameConfigPatch = nullptr;

s2sdk::_GetGameConfigOffset __s2sdk_GetGameConfigOffset = nullptr;

s2sdk::_GetGameConfigAddress __s2sdk_GetGameConfigAddress = nullptr;

s2sdk::_GetGameConfigVTable __s2sdk_GetGameConfigVTable = nullptr;

s2sdk::_GetGameConfigSignature __s2sdk_GetGameConfigSignature = nullptr;

s2sdk::_GetGameConfigPatchAll __s2sdk_GetGameConfigPatchAll = nullptr;

s2sdk::_GetGameConfigOffsetAll __s2sdk_GetGameConfigOffsetAll = nullptr;

s2sdk::_GetGameConfigAddressAll __s2sdk_GetGameConfigAddressAll = nullptr;

s2sdk::_GetGameConfigVTableAll __s2sdk_GetGameConfigVTableAll = nullptr;

s2sdk::_GetGameConfigSignatureAll __s2sdk_GetGameConfigSignatureAll = nullptr;

s2sdk::_RegisterLoggingChannel __s2sdk_RegisterLoggingChannel = nullptr;

s2sdk::_AddLoggerTagToChannel __s2sdk_AddLoggerTagToChannel = nullptr;

s2sdk::_HasLoggerTag __s2sdk_HasLoggerTag = nullptr;

s2sdk::_IsLoggerChannelEnabledBySeverity __s2sdk_IsLoggerChannelEnabledBySeverity = nullptr;

s2sdk::_IsLoggerChannelEnabledByVerbosity __s2sdk_IsLoggerChannelEnabledByVerbosity = nullptr;

s2sdk::_GetLoggerChannelVerbosity __s2sdk_GetLoggerChannelVerbosity = nullptr;

s2sdk::_SetLoggerChannelVerbosity __s2sdk_SetLoggerChannelVerbosity = nullptr;

s2sdk::_SetLoggerChannelVerbosityByName __s2sdk_SetLoggerChannelVerbosityByName = nullptr;

s2sdk::_SetLoggerChannelVerbosityByTag __s2sdk_SetLoggerChannelVerbosityByTag = nullptr;

s2sdk::_GetLoggerChannelColor __s2sdk_GetLoggerChannelColor = nullptr;

s2sdk::_SetLoggerChannelColor __s2sdk_SetLoggerChannelColor = nullptr;

s2sdk::_GetLoggerChannelFlags __s2sdk_GetLoggerChannelFlags = nullptr;

s2sdk::_SetLoggerChannelFlags __s2sdk_SetLoggerChannelFlags = nullptr;

s2sdk::_Log __s2sdk_Log = nullptr;

s2sdk::_LogColored __s2sdk_LogColored = nullptr;

s2sdk::_LogFull __s2sdk_LogFull = nullptr;

s2sdk::_LogFullColored __s2sdk_LogFullColored = nullptr;

s2sdk::_RegisterMenuType __s2sdk_RegisterMenuType = nullptr;

s2sdk::_UnregisterMenuType __s2sdk_UnregisterMenuType = nullptr;

s2sdk::_IsMenuTypeRegistered __s2sdk_IsMenuTypeRegistered = nullptr;

s2sdk::_GetMenuTypes __s2sdk_GetMenuTypes = nullptr;

s2sdk::_SetDefaultMenuType __s2sdk_SetDefaultMenuType = nullptr;

s2sdk::_GetDefaultMenuType __s2sdk_GetDefaultMenuType = nullptr;

s2sdk::_CreateMenu __s2sdk_CreateMenu = nullptr;

s2sdk::_DestroyMenu __s2sdk_DestroyMenu = nullptr;

s2sdk::_IsValidMenu __s2sdk_IsValidMenu = nullptr;

s2sdk::_SetMenuTitle __s2sdk_SetMenuTitle = nullptr;

s2sdk::_GetMenuTitle __s2sdk_GetMenuTitle = nullptr;

s2sdk::_SetMenuType __s2sdk_SetMenuType = nullptr;

s2sdk::_GetMenuType __s2sdk_GetMenuType = nullptr;

s2sdk::_SetMenuPagination __s2sdk_SetMenuPagination = nullptr;

s2sdk::_GetMenuPagination __s2sdk_GetMenuPagination = nullptr;

s2sdk::_SetMenuExitButton __s2sdk_SetMenuExitButton = nullptr;

s2sdk::_GetMenuExitButton __s2sdk_GetMenuExitButton = nullptr;

s2sdk::_SetMenuExitBackButton __s2sdk_SetMenuExitBackButton = nullptr;

s2sdk::_GetMenuExitBackButton __s2sdk_GetMenuExitBackButton = nullptr;

s2sdk::_SetMenuCloseOnSelect __s2sdk_SetMenuCloseOnSelect = nullptr;

s2sdk::_GetMenuCloseOnSelect __s2sdk_GetMenuCloseOnSelect = nullptr;

s2sdk::_AddMenuItem __s2sdk_AddMenuItem = nullptr;

s2sdk::_InsertMenuItemAt __s2sdk_InsertMenuItemAt = nullptr;

s2sdk::_RemoveMenuItem __s2sdk_RemoveMenuItem = nullptr;

s2sdk::_RemoveAllMenuItems __s2sdk_RemoveAllMenuItems = nullptr;

s2sdk::_GetMenuItemsCount __s2sdk_GetMenuItemsCount = nullptr;

s2sdk::_GetMenuItemInfoText __s2sdk_GetMenuItemInfoText = nullptr;

s2sdk::_GetMenuItemDisplay __s2sdk_GetMenuItemDisplay = nullptr;

s2sdk::_GetMenuItemStyle __s2sdk_GetMenuItemStyle = nullptr;

s2sdk::_IsMenuItemSelectable __s2sdk_IsMenuItemSelectable = nullptr;

s2sdk::_SetMenuItemDisplay __s2sdk_SetMenuItemDisplay = nullptr;

s2sdk::_SetMenuItemStyle __s2sdk_SetMenuItemStyle = nullptr;

s2sdk::_DisplayMenu __s2sdk_DisplayMenu = nullptr;

s2sdk::_DisplayMenuAtItem __s2sdk_DisplayMenuAtItem = nullptr;

s2sdk::_CancelClientMenu __s2sdk_CancelClientMenu = nullptr;

s2sdk::_GetClientMenu __s2sdk_GetClientMenu = nullptr;

s2sdk::_GetClientMenuOffset __s2sdk_GetClientMenuOffset = nullptr;

s2sdk::_GetClientMenuTime __s2sdk_GetClientMenuTime = nullptr;

s2sdk::_GetClientMenuCursor __s2sdk_GetClientMenuCursor = nullptr;

s2sdk::_SetClientMenuCursor __s2sdk_SetClientMenuCursor = nullptr;

s2sdk::_ClientMenuHasPrevPage __s2sdk_ClientMenuHasPrevPage = nullptr;

s2sdk::_ClientMenuHasNextPage __s2sdk_ClientMenuHasNextPage = nullptr;

s2sdk::_MenuNextPage __s2sdk_MenuNextPage = nullptr;

s2sdk::_MenuPrevPage __s2sdk_MenuPrevPage = nullptr;

s2sdk::_SelectMenuItem __s2sdk_SelectMenuItem = nullptr;

s2sdk::_HandleDigitInput __s2sdk_HandleDigitInput = nullptr;

s2sdk::_GetEntityAttachmentAngles __s2sdk_GetEntityAttachmentAngles = nullptr;

s2sdk::_GetEntityAttachmentForward __s2sdk_GetEntityAttachmentForward = nullptr;

s2sdk::_GetEntityAttachmentOrigin __s2sdk_GetEntityAttachmentOrigin = nullptr;

s2sdk::_GetEntityMaterialGroupHash __s2sdk_GetEntityMaterialGroupHash = nullptr;

s2sdk::_GetEntityMaterialGroupMask __s2sdk_GetEntityMaterialGroupMask = nullptr;

s2sdk::_GetEntityModelScale __s2sdk_GetEntityModelScale = nullptr;

s2sdk::_GetEntityRenderAlpha __s2sdk_GetEntityRenderAlpha = nullptr;

s2sdk::_GetEntityRenderColor2 __s2sdk_GetEntityRenderColor2 = nullptr;

s2sdk::_ScriptLookupAttachment __s2sdk_ScriptLookupAttachment = nullptr;

s2sdk::_SetEntityBodygroup __s2sdk_SetEntityBodygroup = nullptr;

s2sdk::_SetEntityBodygroupByName __s2sdk_SetEntityBodygroupByName = nullptr;

s2sdk::_SetEntityLightGroup __s2sdk_SetEntityLightGroup = nullptr;

s2sdk::_SetEntityMaterialGroup __s2sdk_SetEntityMaterialGroup = nullptr;

s2sdk::_SetEntityMaterialGroupHash __s2sdk_SetEntityMaterialGroupHash = nullptr;

s2sdk::_SetEntityMaterialGroupMask __s2sdk_SetEntityMaterialGroupMask = nullptr;

s2sdk::_SetEntityModelScale __s2sdk_SetEntityModelScale = nullptr;

s2sdk::_SetEntityRenderAlpha __s2sdk_SetEntityRenderAlpha = nullptr;

s2sdk::_SetEntityRenderColor2 __s2sdk_SetEntityRenderColor2 = nullptr;

s2sdk::_SetEntityRenderMode2 __s2sdk_SetEntityRenderMode2 = nullptr;

s2sdk::_SetEntitySingleMeshGroup __s2sdk_SetEntitySingleMeshGroup = nullptr;

s2sdk::_SetEntitySize __s2sdk_SetEntitySize = nullptr;

s2sdk::_SetEntitySkin __s2sdk_SetEntitySkin = nullptr;

s2sdk::_PanoramaSendYesNoVote __s2sdk_PanoramaSendYesNoVote = nullptr;

s2sdk::_PanoramaSendYesNoVoteToAll __s2sdk_PanoramaSendYesNoVoteToAll = nullptr;

s2sdk::_PanoramaRemovePlayerFromVote __s2sdk_PanoramaRemovePlayerFromVote = nullptr;

s2sdk::_PanoramaIsPlayerInVotePool __s2sdk_PanoramaIsPlayerInVotePool = nullptr;

s2sdk::_PanoramaRedrawVoteToClient __s2sdk_PanoramaRedrawVoteToClient = nullptr;

s2sdk::_PanoramaIsVoteInProgress __s2sdk_PanoramaIsVoteInProgress = nullptr;

s2sdk::_PanoramaEndVote __s2sdk_PanoramaEndVote = nullptr;

s2sdk::_GetSchemaOffset __s2sdk_GetSchemaOffset = nullptr;

s2sdk::_GetSchemaChainOffset __s2sdk_GetSchemaChainOffset = nullptr;

s2sdk::_IsSchemaFieldNetworked __s2sdk_IsSchemaFieldNetworked = nullptr;

s2sdk::_GetSchemaClassSize __s2sdk_GetSchemaClassSize = nullptr;

s2sdk::_GetEntData2 __s2sdk_GetEntData2 = nullptr;

s2sdk::_SetEntData2 __s2sdk_SetEntData2 = nullptr;

s2sdk::_GetEntDataFloat2 __s2sdk_GetEntDataFloat2 = nullptr;

s2sdk::_SetEntDataFloat2 __s2sdk_SetEntDataFloat2 = nullptr;

s2sdk::_GetEntDataColor2 __s2sdk_GetEntDataColor2 = nullptr;

s2sdk::_SetEntDataColor2 __s2sdk_SetEntDataColor2 = nullptr;

s2sdk::_GetEntDataString2 __s2sdk_GetEntDataString2 = nullptr;

s2sdk::_SetEntDataString2 __s2sdk_SetEntDataString2 = nullptr;

s2sdk::_GetEntDataCString2 __s2sdk_GetEntDataCString2 = nullptr;

s2sdk::_SetEntDataCString2 __s2sdk_SetEntDataCString2 = nullptr;

s2sdk::_GetEntDataVector3D2 __s2sdk_GetEntDataVector3D2 = nullptr;

s2sdk::_SetEntDataVector3D2 __s2sdk_SetEntDataVector3D2 = nullptr;

s2sdk::_GetEntDataVector4D2 __s2sdk_GetEntDataVector4D2 = nullptr;

s2sdk::_SetEntDataVector4D2 __s2sdk_SetEntDataVector4D2 = nullptr;

s2sdk::_GetEntDataVector2D2 __s2sdk_GetEntDataVector2D2 = nullptr;

s2sdk::_SetEntDataVector2D2 __s2sdk_SetEntDataVector2D2 = nullptr;

s2sdk::_GetEntDataEnt2 __s2sdk_GetEntDataEnt2 = nullptr;

s2sdk::_SetEntDataEnt2 __s2sdk_SetEntDataEnt2 = nullptr;

s2sdk::_GetEntDataPtr2 __s2sdk_GetEntDataPtr2 = nullptr;

s2sdk::_ChangeEntityState2 __s2sdk_ChangeEntityState2 = nullptr;

s2sdk::_GetEntData __s2sdk_GetEntData = nullptr;

s2sdk::_SetEntData __s2sdk_SetEntData = nullptr;

s2sdk::_GetEntDataFloat __s2sdk_GetEntDataFloat = nullptr;

s2sdk::_SetEntDataFloat __s2sdk_SetEntDataFloat = nullptr;

s2sdk::_GetEntDataColor __s2sdk_GetEntDataColor = nullptr;

s2sdk::_SetEntDataColor __s2sdk_SetEntDataColor = nullptr;

s2sdk::_GetEntDataString __s2sdk_GetEntDataString = nullptr;

s2sdk::_SetEntDataString __s2sdk_SetEntDataString = nullptr;

s2sdk::_GetEntDataCString __s2sdk_GetEntDataCString = nullptr;

s2sdk::_SetEntDataCString __s2sdk_SetEntDataCString = nullptr;

s2sdk::_GetEntDataVector3D __s2sdk_GetEntDataVector3D = nullptr;

s2sdk::_SetEntDataVector3D __s2sdk_SetEntDataVector3D = nullptr;

s2sdk::_GetEntDataVector4D __s2sdk_GetEntDataVector4D = nullptr;

s2sdk::_SetEntDataVector4D __s2sdk_SetEntDataVector4D = nullptr;

s2sdk::_GetEntDataVector2D __s2sdk_GetEntDataVector2D = nullptr;

s2sdk::_SetEntDataVector2D __s2sdk_SetEntDataVector2D = nullptr;

s2sdk::_GetEntDataEnt __s2sdk_GetEntDataEnt = nullptr;

s2sdk::_SetEntDataEnt __s2sdk_SetEntDataEnt = nullptr;

s2sdk::_GetEntDataPtr __s2sdk_GetEntDataPtr = nullptr;

s2sdk::_ChangeEntityState __s2sdk_ChangeEntityState = nullptr;

s2sdk::_GetEntSchemaArraySize2 __s2sdk_GetEntSchemaArraySize2 = nullptr;

s2sdk::_GetEntSchemaPtr2 __s2sdk_GetEntSchemaPtr2 = nullptr;

s2sdk::_GetEntSchema2 __s2sdk_GetEntSchema2 = nullptr;

s2sdk::_SetEntSchema2 __s2sdk_SetEntSchema2 = nullptr;

s2sdk::_GetEntSchemaFloat2 __s2sdk_GetEntSchemaFloat2 = nullptr;

s2sdk::_SetEntSchemaFloat2 __s2sdk_SetEntSchemaFloat2 = nullptr;

s2sdk::_GetEntSchemaColor2 __s2sdk_GetEntSchemaColor2 = nullptr;

s2sdk::_SetEntSchemaColor2 __s2sdk_SetEntSchemaColor2 = nullptr;

s2sdk::_GetEntSchemaString2 __s2sdk_GetEntSchemaString2 = nullptr;

s2sdk::_SetEntSchemaString2 __s2sdk_SetEntSchemaString2 = nullptr;

s2sdk::_GetEntSchemaVector3D2 __s2sdk_GetEntSchemaVector3D2 = nullptr;

s2sdk::_SetEntSchemaVector3D2 __s2sdk_SetEntSchemaVector3D2 = nullptr;

s2sdk::_GetEntSchemaVector2D2 __s2sdk_GetEntSchemaVector2D2 = nullptr;

s2sdk::_SetEntSchemaVector2D2 __s2sdk_SetEntSchemaVector2D2 = nullptr;

s2sdk::_GetEntSchemaVector4D2 __s2sdk_GetEntSchemaVector4D2 = nullptr;

s2sdk::_SetEntSchemaVector4D2 __s2sdk_SetEntSchemaVector4D2 = nullptr;

s2sdk::_GetEntSchemaEnt2 __s2sdk_GetEntSchemaEnt2 = nullptr;

s2sdk::_SetEntSchemaEnt2 __s2sdk_SetEntSchemaEnt2 = nullptr;

s2sdk::_PushEntSchemaEnt2 __s2sdk_PushEntSchemaEnt2 = nullptr;

s2sdk::_EraseEntSchemaEnt2 __s2sdk_EraseEntSchemaEnt2 = nullptr;

s2sdk::_NetworkStateChanged2 __s2sdk_NetworkStateChanged2 = nullptr;

s2sdk::_GetEntSchemaArraySize __s2sdk_GetEntSchemaArraySize = nullptr;

s2sdk::_GetEntSchemaPtr __s2sdk_GetEntSchemaPtr = nullptr;

s2sdk::_GetEntSchema __s2sdk_GetEntSchema = nullptr;

s2sdk::_SetEntSchema __s2sdk_SetEntSchema = nullptr;

s2sdk::_GetEntSchemaFloat __s2sdk_GetEntSchemaFloat = nullptr;

s2sdk::_SetEntSchemaFloat __s2sdk_SetEntSchemaFloat = nullptr;

s2sdk::_GetEntSchemaColor __s2sdk_GetEntSchemaColor = nullptr;

s2sdk::_SetEntSchemaColor __s2sdk_SetEntSchemaColor = nullptr;

s2sdk::_GetEntSchemaString __s2sdk_GetEntSchemaString = nullptr;

s2sdk::_SetEntSchemaString __s2sdk_SetEntSchemaString = nullptr;

s2sdk::_GetEntSchemaVector3D __s2sdk_GetEntSchemaVector3D = nullptr;

s2sdk::_SetEntSchemaVector3D __s2sdk_SetEntSchemaVector3D = nullptr;

s2sdk::_GetEntSchemaVector2D __s2sdk_GetEntSchemaVector2D = nullptr;

s2sdk::_SetEntSchemaVector2D __s2sdk_SetEntSchemaVector2D = nullptr;

s2sdk::_GetEntSchemaVector4D __s2sdk_GetEntSchemaVector4D = nullptr;

s2sdk::_SetEntSchemaVector4D __s2sdk_SetEntSchemaVector4D = nullptr;

s2sdk::_GetEntSchemaEnt __s2sdk_GetEntSchemaEnt = nullptr;

s2sdk::_SetEntSchemaEnt __s2sdk_SetEntSchemaEnt = nullptr;

s2sdk::_PushEntSchemaEnt __s2sdk_PushEntSchemaEnt = nullptr;

s2sdk::_EraseEntSchemaEnt __s2sdk_EraseEntSchemaEnt = nullptr;

s2sdk::_NetworkStateChanged __s2sdk_NetworkStateChanged = nullptr;

s2sdk::_CreateTimer __s2sdk_CreateTimer = nullptr;

s2sdk::_KillsTimer __s2sdk_KillsTimer = nullptr;

s2sdk::_RescheduleTimer __s2sdk_RescheduleTimer = nullptr;

s2sdk::_GetTickInterval __s2sdk_GetTickInterval = nullptr;

s2sdk::_GetTickedTime __s2sdk_GetTickedTime = nullptr;

s2sdk::_OnClientConnect_Register __s2sdk_OnClientConnect_Register = nullptr;

s2sdk::_OnClientConnect_Unregister __s2sdk_OnClientConnect_Unregister = nullptr;

s2sdk::_OnClientConnect_Post_Register __s2sdk_OnClientConnect_Post_Register = nullptr;

s2sdk::_OnClientConnect_Post_Unregister __s2sdk_OnClientConnect_Post_Unregister = nullptr;

s2sdk::_OnClientConnected_Register __s2sdk_OnClientConnected_Register = nullptr;

s2sdk::_OnClientConnected_Unregister __s2sdk_OnClientConnected_Unregister = nullptr;

s2sdk::_OnClientPutInServer_Register __s2sdk_OnClientPutInServer_Register = nullptr;

s2sdk::_OnClientPutInServer_Unregister __s2sdk_OnClientPutInServer_Unregister = nullptr;

s2sdk::_OnClientDisconnect_Register __s2sdk_OnClientDisconnect_Register = nullptr;

s2sdk::_OnClientDisconnect_Unregister __s2sdk_OnClientDisconnect_Unregister = nullptr;

s2sdk::_OnClientDisconnect_Post_Register __s2sdk_OnClientDisconnect_Post_Register = nullptr;

s2sdk::_OnClientDisconnect_Post_Unregister __s2sdk_OnClientDisconnect_Post_Unregister = nullptr;

s2sdk::_OnClientActive_Register __s2sdk_OnClientActive_Register = nullptr;

s2sdk::_OnClientActive_Unregister __s2sdk_OnClientActive_Unregister = nullptr;

s2sdk::_OnClientFullyConnect_Register __s2sdk_OnClientFullyConnect_Register = nullptr;

s2sdk::_OnClientFullyConnect_Unregister __s2sdk_OnClientFullyConnect_Unregister = nullptr;

s2sdk::_OnClientSettingsChanged_Register __s2sdk_OnClientSettingsChanged_Register = nullptr;

s2sdk::_OnClientSettingsChanged_Unregister __s2sdk_OnClientSettingsChanged_Unregister = nullptr;

s2sdk::_OnClientAuthenticated_Register __s2sdk_OnClientAuthenticated_Register = nullptr;

s2sdk::_OnClientAuthenticated_Unregister __s2sdk_OnClientAuthenticated_Unregister = nullptr;

s2sdk::_OnRoundTerminated_Register __s2sdk_OnRoundTerminated_Register = nullptr;

s2sdk::_OnRoundTerminated_Unregister __s2sdk_OnRoundTerminated_Unregister = nullptr;

s2sdk::_OnEntityCreated_Register __s2sdk_OnEntityCreated_Register = nullptr;

s2sdk::_OnEntityCreated_Unregister __s2sdk_OnEntityCreated_Unregister = nullptr;

s2sdk::_OnEntitySpawned_Register __s2sdk_OnEntitySpawned_Register = nullptr;

s2sdk::_OnEntitySpawned_Unregister __s2sdk_OnEntitySpawned_Unregister = nullptr;

s2sdk::_OnEntityDeleted_Register __s2sdk_OnEntityDeleted_Register = nullptr;

s2sdk::_OnEntityDeleted_Unregister __s2sdk_OnEntityDeleted_Unregister = nullptr;

s2sdk::_OnEntityParentChanged_Register __s2sdk_OnEntityParentChanged_Register = nullptr;

s2sdk::_OnEntityParentChanged_Unregister __s2sdk_OnEntityParentChanged_Unregister = nullptr;

s2sdk::_OnServerCheckTransmit_Register __s2sdk_OnServerCheckTransmit_Register = nullptr;

s2sdk::_OnServerCheckTransmit_Unregister __s2sdk_OnServerCheckTransmit_Unregister = nullptr;

s2sdk::_OnServerStartup_Register __s2sdk_OnServerStartup_Register = nullptr;

s2sdk::_OnServerStartup_Unregister __s2sdk_OnServerStartup_Unregister = nullptr;

s2sdk::_OnBuildGameSessionManifest_Register __s2sdk_OnBuildGameSessionManifest_Register = nullptr;

s2sdk::_OnBuildGameSessionManifest_Unregister __s2sdk_OnBuildGameSessionManifest_Unregister = nullptr;

s2sdk::_OnServerActivate_Register __s2sdk_OnServerActivate_Register = nullptr;

s2sdk::_OnServerActivate_Unregister __s2sdk_OnServerActivate_Unregister = nullptr;

s2sdk::_OnServerSpawn_Register __s2sdk_OnServerSpawn_Register = nullptr;

s2sdk::_OnServerSpawn_Unregister __s2sdk_OnServerSpawn_Unregister = nullptr;

s2sdk::_OnServerStarted_Register __s2sdk_OnServerStarted_Register = nullptr;

s2sdk::_OnServerStarted_Unregister __s2sdk_OnServerStarted_Unregister = nullptr;

s2sdk::_OnMapStart_Register __s2sdk_OnMapStart_Register = nullptr;

s2sdk::_OnMapStart_Unregister __s2sdk_OnMapStart_Unregister = nullptr;

s2sdk::_OnMapEnd_Register __s2sdk_OnMapEnd_Register = nullptr;

s2sdk::_OnMapEnd_Unregister __s2sdk_OnMapEnd_Unregister = nullptr;

s2sdk::_OnGameFrame_Register __s2sdk_OnGameFrame_Register = nullptr;

s2sdk::_OnGameFrame_Unregister __s2sdk_OnGameFrame_Unregister = nullptr;

s2sdk::_OnUpdateWhenNotInGame_Register __s2sdk_OnUpdateWhenNotInGame_Register = nullptr;

s2sdk::_OnUpdateWhenNotInGame_Unregister __s2sdk_OnUpdateWhenNotInGame_Unregister = nullptr;

s2sdk::_OnPreWorldUpdate_Register __s2sdk_OnPreWorldUpdate_Register = nullptr;

s2sdk::_OnPreWorldUpdate_Unregister __s2sdk_OnPreWorldUpdate_Unregister = nullptr;

s2sdk::_OnSendNetMessage_Register __s2sdk_OnSendNetMessage_Register = nullptr;

s2sdk::_OnSendNetMessage_Unregister __s2sdk_OnSendNetMessage_Unregister = nullptr;

s2sdk::_OnSerializeMessage_Register __s2sdk_OnSerializeMessage_Register = nullptr;

s2sdk::_OnSerializeMessage_Unregister __s2sdk_OnSerializeMessage_Unregister = nullptr;

s2sdk::_GetGameRulesProxy __s2sdk_GetGameRulesProxy = nullptr;

s2sdk::_GetGameRules __s2sdk_GetGameRules = nullptr;

s2sdk::_GetGameTeamManager __s2sdk_GetGameTeamManager = nullptr;

s2sdk::_GetGameTeamScore __s2sdk_GetGameTeamScore = nullptr;

s2sdk::_GetGamePlayerCount __s2sdk_GetGamePlayerCount = nullptr;

s2sdk::_GetGameTotalRoundsPlayed __s2sdk_GetGameTotalRoundsPlayed = nullptr;

s2sdk::_TerminateRound __s2sdk_TerminateRound = nullptr;

s2sdk::_HookUserMessage __s2sdk_HookUserMessage = nullptr;

s2sdk::_UnhookUserMessage __s2sdk_UnhookUserMessage = nullptr;

s2sdk::_UserMessageCreateFromSerializable __s2sdk_UserMessageCreateFromSerializable = nullptr;

s2sdk::_UserMessageCreateFromName __s2sdk_UserMessageCreateFromName = nullptr;

s2sdk::_UserMessageCreateFromId __s2sdk_UserMessageCreateFromId = nullptr;

s2sdk::_UserMessageDestroy __s2sdk_UserMessageDestroy = nullptr;

s2sdk::_UserMessageSend __s2sdk_UserMessageSend = nullptr;

s2sdk::_UserMessageGetMessageName __s2sdk_UserMessageGetMessageName = nullptr;

s2sdk::_UserMessageGetMessageID __s2sdk_UserMessageGetMessageID = nullptr;

s2sdk::_UserMessageHasField __s2sdk_UserMessageHasField = nullptr;

s2sdk::_UserMessageGetProtobufMessage __s2sdk_UserMessageGetProtobufMessage = nullptr;

s2sdk::_UserMessageGetSerializableMessage __s2sdk_UserMessageGetSerializableMessage = nullptr;

s2sdk::_UserMessageFindMessageIdByName __s2sdk_UserMessageFindMessageIdByName = nullptr;

s2sdk::_UserMessageGetRecipientMask __s2sdk_UserMessageGetRecipientMask = nullptr;

s2sdk::_UserMessageAddRecipient __s2sdk_UserMessageAddRecipient = nullptr;

s2sdk::_UserMessageAddAllPlayers __s2sdk_UserMessageAddAllPlayers = nullptr;

s2sdk::_UserMessageSetRecipientMask __s2sdk_UserMessageSetRecipientMask = nullptr;

s2sdk::_UserMessageRemoveAllRecipient __s2sdk_UserMessageRemoveAllRecipient = nullptr;

s2sdk::_UserMessageGetRepeatedFieldCount __s2sdk_UserMessageGetRepeatedFieldCount = nullptr;

s2sdk::_UserMessageRemoveRepeatedFieldValue __s2sdk_UserMessageRemoveRepeatedFieldValue = nullptr;

s2sdk::_UserMessageGetDebugString __s2sdk_UserMessageGetDebugString = nullptr;

s2sdk::_PbReadEnum __s2sdk_PbReadEnum = nullptr;

s2sdk::_PbReadInt32 __s2sdk_PbReadInt32 = nullptr;

s2sdk::_PbReadInt64 __s2sdk_PbReadInt64 = nullptr;

s2sdk::_PbReadUInt32 __s2sdk_PbReadUInt32 = nullptr;

s2sdk::_PbReadUInt64 __s2sdk_PbReadUInt64 = nullptr;

s2sdk::_PbReadFloat __s2sdk_PbReadFloat = nullptr;

s2sdk::_PbReadDouble __s2sdk_PbReadDouble = nullptr;

s2sdk::_PbReadBool __s2sdk_PbReadBool = nullptr;

s2sdk::_PbReadString __s2sdk_PbReadString = nullptr;

s2sdk::_PbReadColor __s2sdk_PbReadColor = nullptr;

s2sdk::_PbReadVector2 __s2sdk_PbReadVector2 = nullptr;

s2sdk::_PbReadVector3 __s2sdk_PbReadVector3 = nullptr;

s2sdk::_PbReadVector4 __s2sdk_PbReadVector4 = nullptr;

s2sdk::_PbReadQAngle __s2sdk_PbReadQAngle = nullptr;

s2sdk::_PbReadMessage __s2sdk_PbReadMessage = nullptr;

s2sdk::_PbGetEnum __s2sdk_PbGetEnum = nullptr;

s2sdk::_PbSetEnum __s2sdk_PbSetEnum = nullptr;

s2sdk::_PbGetInt32 __s2sdk_PbGetInt32 = nullptr;

s2sdk::_PbSetInt32 __s2sdk_PbSetInt32 = nullptr;

s2sdk::_PbGetInt64 __s2sdk_PbGetInt64 = nullptr;

s2sdk::_PbSetInt64 __s2sdk_PbSetInt64 = nullptr;

s2sdk::_PbGetUInt32 __s2sdk_PbGetUInt32 = nullptr;

s2sdk::_PbSetUInt32 __s2sdk_PbSetUInt32 = nullptr;

s2sdk::_PbGetUInt64 __s2sdk_PbGetUInt64 = nullptr;

s2sdk::_PbSetUInt64 __s2sdk_PbSetUInt64 = nullptr;

s2sdk::_PbGetBool __s2sdk_PbGetBool = nullptr;

s2sdk::_PbSetBool __s2sdk_PbSetBool = nullptr;

s2sdk::_PbGetFloat __s2sdk_PbGetFloat = nullptr;

s2sdk::_PbSetFloat __s2sdk_PbSetFloat = nullptr;

s2sdk::_PbGetDouble __s2sdk_PbGetDouble = nullptr;

s2sdk::_PbSetDouble __s2sdk_PbSetDouble = nullptr;

s2sdk::_PbGetString __s2sdk_PbGetString = nullptr;

s2sdk::_PbSetString __s2sdk_PbSetString = nullptr;

s2sdk::_PbGetColor __s2sdk_PbGetColor = nullptr;

s2sdk::_PbSetColor __s2sdk_PbSetColor = nullptr;

s2sdk::_PbGetVector2 __s2sdk_PbGetVector2 = nullptr;

s2sdk::_PbSetVector2 __s2sdk_PbSetVector2 = nullptr;

s2sdk::_PbGetVector3 __s2sdk_PbGetVector3 = nullptr;

s2sdk::_PbSetVector3 __s2sdk_PbSetVector3 = nullptr;

s2sdk::_PbGetVector4 __s2sdk_PbGetVector4 = nullptr;

s2sdk::_PbSetVector4 __s2sdk_PbSetVector4 = nullptr;

s2sdk::_PbGetQAngle __s2sdk_PbGetQAngle = nullptr;

s2sdk::_PbSetQAngle __s2sdk_PbSetQAngle = nullptr;

s2sdk::_PbGetMessage __s2sdk_PbGetMessage = nullptr;

s2sdk::_PbSetMessage __s2sdk_PbSetMessage = nullptr;

s2sdk::_PbGetRepeatedEnum __s2sdk_PbGetRepeatedEnum = nullptr;

s2sdk::_PbSetRepeatedEnum __s2sdk_PbSetRepeatedEnum = nullptr;

s2sdk::_PbAddEnum __s2sdk_PbAddEnum = nullptr;

s2sdk::_PbGetRepeatedInt32 __s2sdk_PbGetRepeatedInt32 = nullptr;

s2sdk::_PbSetRepeatedInt32 __s2sdk_PbSetRepeatedInt32 = nullptr;

s2sdk::_PbAddInt32 __s2sdk_PbAddInt32 = nullptr;

s2sdk::_PbGetRepeatedInt64 __s2sdk_PbGetRepeatedInt64 = nullptr;

s2sdk::_PbSetRepeatedInt64 __s2sdk_PbSetRepeatedInt64 = nullptr;

s2sdk::_PbAddInt64 __s2sdk_PbAddInt64 = nullptr;

s2sdk::_PbGetRepeatedUInt32 __s2sdk_PbGetRepeatedUInt32 = nullptr;

s2sdk::_PbSetRepeatedUInt32 __s2sdk_PbSetRepeatedUInt32 = nullptr;

s2sdk::_PbAddUInt32 __s2sdk_PbAddUInt32 = nullptr;

s2sdk::_PbGetRepeatedUInt64 __s2sdk_PbGetRepeatedUInt64 = nullptr;

s2sdk::_PbSetRepeatedUInt64 __s2sdk_PbSetRepeatedUInt64 = nullptr;

s2sdk::_PbAddUInt64 __s2sdk_PbAddUInt64 = nullptr;

s2sdk::_PbGetRepeatedBool __s2sdk_PbGetRepeatedBool = nullptr;

s2sdk::_PbSetRepeatedBool __s2sdk_PbSetRepeatedBool = nullptr;

s2sdk::_PbAddBool __s2sdk_PbAddBool = nullptr;

s2sdk::_PbGetRepeatedFloat __s2sdk_PbGetRepeatedFloat = nullptr;

s2sdk::_PbSetRepeatedFloat __s2sdk_PbSetRepeatedFloat = nullptr;

s2sdk::_PbAddFloat __s2sdk_PbAddFloat = nullptr;

s2sdk::_PbGetRepeatedDouble __s2sdk_PbGetRepeatedDouble = nullptr;

s2sdk::_PbSetRepeatedDouble __s2sdk_PbSetRepeatedDouble = nullptr;

s2sdk::_PbAddDouble __s2sdk_PbAddDouble = nullptr;

s2sdk::_PbGetRepeatedString __s2sdk_PbGetRepeatedString = nullptr;

s2sdk::_PbSetRepeatedString __s2sdk_PbSetRepeatedString = nullptr;

s2sdk::_PbAddString __s2sdk_PbAddString = nullptr;

s2sdk::_PbGetRepeatedColor __s2sdk_PbGetRepeatedColor = nullptr;

s2sdk::_PbSetRepeatedColor __s2sdk_PbSetRepeatedColor = nullptr;

s2sdk::_PbAddColor __s2sdk_PbAddColor = nullptr;

s2sdk::_PbGetRepeatedVector2 __s2sdk_PbGetRepeatedVector2 = nullptr;

s2sdk::_PbSetRepeatedVector2 __s2sdk_PbSetRepeatedVector2 = nullptr;

s2sdk::_PbAddVector2 __s2sdk_PbAddVector2 = nullptr;

s2sdk::_PbGetRepeatedVector3 __s2sdk_PbGetRepeatedVector3 = nullptr;

s2sdk::_PbSetRepeatedVector3 __s2sdk_PbSetRepeatedVector3 = nullptr;

s2sdk::_PbAddVector3 __s2sdk_PbAddVector3 = nullptr;

s2sdk::_PbGetRepeatedVector4 __s2sdk_PbGetRepeatedVector4 = nullptr;

s2sdk::_PbSetRepeatedVector4 __s2sdk_PbSetRepeatedVector4 = nullptr;

s2sdk::_PbAddVector4 __s2sdk_PbAddVector4 = nullptr;

s2sdk::_PbGetRepeatedQAngle __s2sdk_PbGetRepeatedQAngle = nullptr;

s2sdk::_PbSetRepeatedQAngle __s2sdk_PbSetRepeatedQAngle = nullptr;

s2sdk::_PbAddQAngle __s2sdk_PbAddQAngle = nullptr;

s2sdk::_PbGetRepeatedMessage __s2sdk_PbGetRepeatedMessage = nullptr;

s2sdk::_PbSetRepeatedMessage __s2sdk_PbSetRepeatedMessage = nullptr;

s2sdk::_PbAddMessage __s2sdk_PbAddMessage = nullptr;

s2sdk::_GetWeaponVDataFromKey __s2sdk_GetWeaponVDataFromKey = nullptr;

s2sdk::_GetWeaponVData __s2sdk_GetWeaponVData = nullptr;

s2sdk::_GetWeaponType __s2sdk_GetWeaponType = nullptr;

s2sdk::_GetWeaponCategory __s2sdk_GetWeaponCategory = nullptr;

s2sdk::_GetWeaponGearSlot __s2sdk_GetWeaponGearSlot = nullptr;

s2sdk::_GetWeaponItemDefinition __s2sdk_GetWeaponItemDefinition = nullptr;

s2sdk::_GetWeaponItemDefinitionByName __s2sdk_GetWeaponItemDefinitionByName = nullptr;

