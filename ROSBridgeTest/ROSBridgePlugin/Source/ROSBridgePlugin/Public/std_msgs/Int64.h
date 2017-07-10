#pragma once
#include "ROSBridgeMsg.h"

class FROSBridgeMsgStdmsgsInt64 : public FROSBridgeMsg
{
    int64 data;

public:
    FROSBridgeMsgStdmsgsInt64()
    {
        Type = "std_msgs/Int64";
    }

    FROSBridgeMsgStdmsgsInt64(int64 data_)
    {
        Type = "std_msgs/Int64";
        data = data_;
    }

    int64 GetData()
    {
        return data;
    }

    void SetData(int64 data_)
    {
        data = data_;
    }

    virtual void FromJson(FJsonObject* JsonObject) override {
        data = (int64)(JsonObject->GetNumberField("data"));
    }

    virtual FString ToString () override
    {
        char CharData[21];
        sprintf(CharData, "%lld", data);
        FString StringData(UTF8_TO_TCHAR(CharData));

        return TEXT("Int64 { data = \"" + StringData + "\" }");
    }

    virtual FString ToYamlString() override {
        FString OutputString;
        FJsonObject Object;
        Object.SetNumberField(TEXT("data"), data);

        TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
        FJsonSerializer::Serialize(Object.ToSharedRef(), Writer);
        return OutputString;
    }
};
