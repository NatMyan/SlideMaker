cmake_minimum_required(VERSION 3.5)
project(Pptx)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

add_executable(Pptx
    "zhelpers/Definitions.cpp"
    "Application.cpp"
    "CLI/Controller.cpp"
    "CLI/CommandHistory.cpp"
    "CLI/CommandFactory.cpp"
    "CLI/Parser9/SyntaxAnalyzer.cpp"
    "CLI/Parser9/SemanticAnalyzer.cpp"
    "CLI/CommandRegistry.cpp"
    "CLI/Parser9/Tokenizer.cpp"
    "CLI/Parser9/Parser9.cpp"
    "CLI/Commands/AddCommand.cpp"
    "CLI/Commands/RemoveCommand.cpp"
    "CLI/Commands/ChangeCommand.cpp"
    "CLI/Commands/MoveCommand.cpp"
    "CLI/Commands/SwitchCommand.cpp"
    "CLI/Commands/ExitCommand.cpp"
    "CLI/Commands/SaveCommand.cpp"
    "CLI/Commands/LoadCommand.cpp"
    "CLI/Commands/DisplayCommand.cpp"
    "CLI/Commands/DrawCommand.cpp"
    "CLI/Commands/ListCommand.cpp"
    "CLI/Commands/UndoCommand.cpp"
    "CLI/Commands/RedoCommand.cpp"
    "Data/Attributes.cpp"
    "Data/Item.cpp"
    "Data/ItemGroup.cpp"
    "Data/Slide.cpp"
    "Data/FormatSize.cpp"
    "Data/Document.cpp"
    "Director/Actions/AddItemAction.cpp"
    "Director/Actions/AddSlideAction.cpp"
    "Director/Actions/ChangeItemAction.cpp"
    "Director/Actions/MoveSlideAction.cpp"
    "Director/Actions/RemoveItemAction.cpp"
    "Director/Actions/RemoveSlideAction.cpp"
    "Director/Director.cpp"
    "Rendering/DimensionConverter.cpp"
    "Rendering/Shapes/ShapeBase.cpp"
    "Rendering/Shapes/EllipseShape.cpp"
    "Rendering/Shapes/LineShape.cpp"
    "Rendering/Shapes/PolygonShape.cpp"
    "Rendering/Shapes/RectangleShape.cpp"
    "Rendering/ShapeLibrary.cpp"
    "Rendering/Shapes/TrapezoidShape.cpp"
    "Rendering/Shapes/TriangleShape.cpp"
    "Rendering/Shapes/TextShape.cpp"
    "Rendering/Renderer.cpp"
    "Serialization/JSONDocument.cpp"
    "Serialization/JsonSerializer.cpp"
    "Serialization/JsonDeserializer.cpp"
    "main.cpp"
)

target_link_libraries(Pptx PRIVATE Qt6::Core Qt6::Widgets)




