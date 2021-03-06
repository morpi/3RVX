#pragma once

#include <map>
#include <vector>

class HotkeyInfo {
public:
    enum HotkeyActions {
        IncreaseVolume,
        DecreaseVolume,
        SetVolume,
        Mute,
        VolumeSlider,
        EjectDrive,
        EjectLatestDrive,
        MediaKey,
        Run,
        Settings,
        Exit,
    };
    static std::vector<std::wstring> ActionNames;

    enum VolumeKeyArgTypes {
        NoArgs = -1,
        Units = 0,
        Percentage = 1,
    };

    enum MediaKeys {
        PlayPause,
        Stop,
        Next,
        Previous,
    };
    static std::vector<std::wstring> MediaKeyNames;
    static std::vector<unsigned short> MediaKeyVKs;

public:
    static VolumeKeyArgTypes VolumeArgType(HotkeyInfo &hki);

public:
    int keyCombination = 0;
    int action = -1;
    std::vector<std::wstring> args;

    /// <summary>
    /// Retrieves the argument at the given index and converts it to an integer.
    /// Subsequent calls that specify the same index will be cached.
    /// </summary>
    int ArgToInt(unsigned int argIdx);

    /// <summary>
    /// Retrieves the argument at the given index and converts it to a double.
    /// Subsequent calls that specify the same index will be cached.
    /// </summary>
    double ArgToDouble(unsigned int argIdx);

    bool HasArgs();
    bool HasArg(unsigned int argIdx);
    void AllocateArg(unsigned int argIdx);
    void ClearArgCache();

    std::wstring ToString();

private:
    std::map<int, int> _intArgs;
    std::map<int, double> _doubleArgs;
};