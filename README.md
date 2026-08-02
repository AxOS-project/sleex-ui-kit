# Sleex UI kit

A collection of Qt Quick / QML components built with Sleex's design language (Material 3-inspired), packaged as standalone QML modules so any Quickshell instance or Qt app can use them without depending on the full [Sleex](https://github.com/AxOS-project/sleex) shell.

## Modules

The kit ships three independent QML modules, each its own `qt6_add_qml_module` target:

| Module | URI | Contents |
|---|---|---|
| Appearance | `SleexUiKit.Appearance` | `Appearance` singleton - colors, Material 3 color roles, typography, rounding, animation curves |
| Functions | `SleexUiKit.Functions` | Utility singletons: `ColorUtils`, `StringUtils`, `ObjectUtils`, `FileUtils`, `DesktopUtils`, `Fuzzy`, `Lavendist` |
| Widgets | `SleexUiKit.Widgets` | Reusable QML components (buttons, inputs, sliders, dialogs, etc.) |

`Widgets` depends on `Appearance` and `Functions`. `Appearance` is deliberately **Config-free**; it doesn't know about Sleex's own `Config`/`Directories`/`Persistent` singletons, which stay in Sleex's own source tree. Consumers wire Sleex-specific values (transparency, wallpaper tint, bar/dashboard sizes, etc.) into `Appearance` via their own small binding/bridge file.

## Building

```sh
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
```

## Installing

```sh
sudo cmake --install build
```

This installs the `SleexUiKit.Appearance`, `SleexUiKit.Functions`, and `SleexUiKit.Widgets` QML modules into your Qt QML import path (`${Qt6_INSTALL_PREFIX}/${Qt6_INSTALL_QML}/SleexUiKit`).

## Usage

```qml
import SleexUiKit.Appearance
import SleexUiKit.Functions
import SleexUiKit.Widgets

// A button with a ripple effect on click. This is a component from the Widgets module
RippleButton {
    // The button's background color is read from the Appearance singleton
    colBackground: Appearance.colors.colPrimary
    buttonText: "Click me"
    onClicked: console.log("clicked")
}
```
Some components have external runtime dependencies beyond the kit itself:

- `AudioDeviceSelectorButton` / `VolumeMixer` — need `Quickshell.Services.Pipewire` with a live Pipewire graph. Will require the `quickshell` package.
- `TimePicker` — expects a `DateTime` singleton from a `qs` module (provided by the consuming shell, e.g. Sleex).
- `CliphistImage` — expects a real `cliphist` entry and a working `cliphist decode` pipe.

## Testing

You can test the kit after building it by running the included `test.qml` file in a `qmlscene` or a Quickshell instance:

```sh
qs -p test.qml
```

https://github.com/user-attachments/assets/7e10f46c-14c8-48f2-88e2-a04317152357


