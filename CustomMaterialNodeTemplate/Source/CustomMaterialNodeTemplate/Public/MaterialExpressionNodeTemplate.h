// Copyright 2025 Andrew Laptev. All Rights Reserved.
// Fill out your own copyright notice.

#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialExpression.h"
#include "MaterialExpressionNodeTemplate.generated.h"

UCLASS(CollapseCategories, HideCategories = Object, MinimalAPI)
class UMaterialExpressionNodeTemplate : public UMaterialExpression
{
    GENERATED_UCLASS_BODY()

public:

    UPROPERTY()
    FExpressionInput ColorInner;

    UPROPERTY()
    FExpressionInput ColorOuter;

    UPROPERTY()
    FExpressionInput Exponent;

    UPROPERTY(EditAnywhere, Category = "MaterialExpressionTemplate", meta = (UIMin = "0.0", UIMax = "10.0"))
    float ConstExponent = 2.0f;

    /*Rebuilds the node's outputs: resets to a single output, hides the output name on the pin, and adds an unnamed output.*/
    virtual void RebuildOutputs();

#if WITH_EDITOR
    /*Compiling the material. Called when the material is being compiled.
    Compiler - the object responsible for material compilation.
    OutputIndex - the index of the output being compiled.
    Returns the index of the compiled expression in the material graph.*/
    virtual int32 Compile(class FMaterialCompiler* Compiler, int32 OutputIndex) override;

    /*Retrieving the node's caption, which is displayed in the material editor.
    OutCaptions - an array of strings to which the node's caption is added.*/
    virtual void GetCaption(TArray<FString>& OutCaptions) const override;

    /*Retrieving the list of inputs for the node.
    Returns a view (TArrayView) of an array of pointers to input expressions (FExpressionInput*).*/
    virtual TArrayView<FExpressionInput*> GetInputsView() override;

    /*Retrieving a specific input by its index.
    InputIndex - the index of the input parameter.
    Returns a pointer to the input expression (FExpressionInput*) or nullptr if the index is invalid.*/
    virtual FExpressionInput* GetInput(int32 InputIndex) override;

    /*Retrieving the name of an input parameter by its index.
    InputIndex - the index of the input parameter.
    Returns the name of the input parameter (FName) or NAME_None if the index is invalid.*/
    virtual FName GetInputName(int32 InputIndex) const override;
#endif
};
