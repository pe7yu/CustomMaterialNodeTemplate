# CustomMaterialNodeTemplate

Unreal Engine 5 plugin template for adding custom material expression nodes to the engine using `MaterialExpression`.

## Features

- **Basic Shader Functionality**: 
  - Creates a **view-dependent color gradient** on the surface.
  - The color smoothly transitions between `InnerColor` and `OuterColor` based on the viewing angle.
  - The `Exponent` parameter controls the sharpness or softness of the transition.

- **Engine Subsystem Module**:
  - Provides a template for creating and registering custom material nodes.
  - Easily extendable for additional functionality.

## Installation

1. Clone this repository into your Unreal Engine project's `Plugins` folder.
2. Rebuild your project in Visual Studio or your preferred IDE.
3. Enable the plugin in the Unreal Engine Editor under **Edit > Plugins**.

## Usage

1. Open the Material Editor in Unreal Engine.
2. Search for the **"Custom Material Node Template"** in the palette.
3. Connect the `InnerColor`, `OuterColor`, and `Exponent` inputs to customize the gradient effect.
4. Apply the material to any mesh to see the view-dependent gradient in action.

## Example

Here's an example of how the node can be used in a material:

- **InnerColor**: Blue
- **OuterColor**: Red
- **Exponent**: 5.0

This creates a smooth transition from blue to red, with a sharper gradient at the edges.

## Contributing

If you have suggestions or improvements, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Support

If you encounter any issues or have questions, please open an issue on this repository.