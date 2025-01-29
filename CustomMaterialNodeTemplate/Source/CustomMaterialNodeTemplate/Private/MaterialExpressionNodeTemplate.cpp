// Copyright 2025 Andrew Laptev. All Rights Reserved.
// Fill out your own copyright notice.

#include "MaterialExpressionNodeTemplate.h"
#include "MaterialCompiler.h"

#define LOCTEXT_NAMESPACE "MaterialExpression"

UMaterialExpressionNodeTemplate::UMaterialExpressionNodeTemplate(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer), ConstExponent(2.0f)
{
}

void UMaterialExpressionNodeTemplate::RebuildOutputs()
{
    Outputs.Reset(1);
    bShowOutputNameOnPin = false;
    Outputs.Add(FExpressionOutput(TEXT("")));
}

#if WITH_EDITOR

int32 UMaterialExpressionNodeTemplate::Compile(FMaterialCompiler* Compiler, int32 OutputIndex)
{
    if (!ColorInner.Expression || !ColorOuter.Expression)
    {
        return Compiler->Errorf(TEXT("ColorInner and ColorOuter inputs are required!"));
    }

    // Pixel normal in world space
    int32 Normal = Compiler->PixelNormalWS();

    // Camera vector in world space
    int32 CameraVector = Compiler->CameraVector();

    // dot(Normal, CameraVector)
    int32 DotProduct = Compiler->Dot(Normal, CameraVector);

    // saturate(dot(Normal, CameraVector))
    int32 SaturatedDot = Compiler->Saturate(DotProduct);

    // Exponent (input or const)
    int32 ExpValue = Exponent.Expression ? Compiler->ComponentMask(Exponent.Compile(Compiler), 1, 0, 0, 0)
        : Compiler->Constant(ConstExponent);

    // power(saturate(dot(Normal, CameraVector)), Exponent)
    int32 PowerValue = Compiler->Power(SaturatedDot, ExpValue);

    // lerp(ColorInner, ColorOuter, PowerValue)
    int32 InnerColor = ColorInner.Compile(Compiler);
    int32 OuterColor = ColorOuter.Compile(Compiler);
    int32 Result = Compiler->Lerp(InnerColor, OuterColor, PowerValue);

    return Result;
}

void UMaterialExpressionNodeTemplate::GetCaption(TArray<FString>& OutCaptions) const
{
    OutCaptions.Add(TEXT("Custom Material Node Template"));
}

TArrayView<FExpressionInput*> UMaterialExpressionNodeTemplate::GetInputsView()
{
    CachedInputs.Empty();
    CachedInputs.Add(&ColorInner);
    CachedInputs.Add(&ColorOuter);
    CachedInputs.Add(&Exponent);
    return CachedInputs;
}

FExpressionInput* UMaterialExpressionNodeTemplate::GetInput(int32 InputIndex)
{
    switch (InputIndex)
    {
    case 0: return &ColorInner;
    case 1: return &ColorOuter;
    case 2: return &Exponent;
    default: return nullptr;
    }
}

FName UMaterialExpressionNodeTemplate::GetInputName(int32 InputIndex) const
{
    switch (InputIndex)
    {
    case 0: return TEXT("Inner Color");
    case 1: return TEXT("Outer Color");
    case 2: return TEXT("Exponent");
    default: return NAME_None;
    }
}

#endif

#undef LOCTEXT_NAMESPACE
