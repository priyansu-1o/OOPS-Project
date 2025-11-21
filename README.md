# OOPS-Project Music Library & Playlist Manager

A console-based music library and playlist manager for Windows written in modern C++ (C++17). It loads song metadata from `song.json`, lets users browse, search, play audio files (MP3/WAV), and build/manage playlists with a keyboard-driven UI. Audio playback uses the Windows MCI (`winmm.lib`).

## Features
- Load songs from JSON (`song.json`) via `JsonHelper::stringify()`.
- Interactive main menu (keyboard navigation using `getch()`):
  - View all songs with paginated scrollable list (W/S/A/D + Enter).
  - Search a song by title.
  - Play a song directly.
  - Playlist management window (create, add/remove songs, merge, delete, display, find).
  - Developer mode (password: `aaa`) to add/remove songs interactively.
  - Exit (intended to save; currently no explicit call to `jsonify`).
- Audio playback UI with progress bar, pause/resume/stop (`P`, `R`, `S`).
- Playlist operations including merge (`operator+`).
- Song display formatting and interactive selection in both library and playlist contexts.
- Basic library statistics (count, duration, unique artists/genres) maintained internally.

## Project Structure
```
OOPS-Project/
├─ README.md
├─ song.json                # Persistent song metadata store
└─ src/
   ├─ mainmenu.cpp          # Program entry, main menu loop
   ├─ library.(hpp|cpp)     # MusicLibrary class: indexing, search, display
   ├─ playlist.(hpp|cpp)    # Playlist class: collection + merge logic
   ├─ mediaplayer.(hpp|cpp) # SongPlayer + interfacemusicplayer (UI + playback)
   ├─ window3.(hpp|cpp)     # Playlist management UI routines
   ├─ xxx.cpp               # (Unused / placeholder)
   └─ models/
       ├─ songClass.(hpp|cpp) # Song class + JSON helpers
       └─ json.hpp            # nlohmann::json single-header library
```

## Build Instructions (Windows / MinGW or MSVC)
Ensure a C++17-capable compiler is installed.

### Using g++ (MinGW)
```powershell
g++ -std=c++17 -O2 -I src -I src/models ^
  src/mainmenu.cpp src/library.cpp src/playlist.cpp src/mediaplayer.cpp src/window3.cpp src/models/songClass.cpp ^
  -lwinmm -o music_player.exe
```
Run:
```powershell
./music_player.exe
```

### Using MSVC (Developer Command Prompt)
```powershell
cl /EHsc /std:c++17 /I src /I src/models ^
  src\mainmenu.cpp src\library.cpp src\playlist.cpp src\mediaplayer.cpp src\window3.cpp src\models\songClass.cpp ^
  winmm.lib /Fe:music_player.exe
```

## Runtime Requirements
- Windows OS (uses `<windows.h>`, `mmsystem.h`, `winmm.lib`, `_getch()`).
- Audio files located at paths referenced in `song.json` (e.g. `src/lib/...`).
- Console capable of at least 150 columns for best formatting (UI adapts minimally).

## Usage Overview
Main Menu Keys:
- Numeric options: select action.
- Inside song list: `W/S` navigate items, `A/D` page, `Enter` select, `Q` quit list.
- Player screen: `P` pause, `R` resume, `S` stop & exit.
- Playlist manager: numeric options; further nested interfaces also use `W/S` + `Enter`.

Developer Mode (Option 5):
- Password: `aaa`.
- Add new song (prompts for metadata + file path) or remove by index.

## Data Persistence
- Loading: At start, `mainmenu.cpp` calls `MusicLibrary::stringify()` (via inheritance from `JsonHelper`) to load all songs from `song.json`.
- Saving: Although `JsonHelper::jsonify()` exists, it is currently not invoked on exit. To persist changes (e.g., songs added in Developer Mode), add a call like:
```cpp
JsonHelper helper; // or (ob2) since MusicLibrary inherits JsonHelper
helper.jsonify(ob2.getAllSongs());
```
before returning from `main()` or in option 6 handling.

## Key Classes
- `Song`: Represents a track (title, artist, genre, duration, filepath). Supports stream I/O and JSON conversion.
- `MusicLibrary`: Maintains vector of songs + indexes by artist/genre; supports search, display, statistics.
- `Playlist`: Named collection of songs; supports merge via `operator+` and interactive display selection.
- `SongPlayer`: Thin wrapper over MCI commands for play/pause/resume/stop.
- `interfacemusicplayer`: Console playback UI with progress bar & controls.
- `window3`: Playlist management UI (create, modify, merge, play entries).

## Notable Implementation Details
- Pagination logic in `MusicLibrary::displayAllSongs()` with wrap-around navigation.
- Use of `_getch()` for non-blocking single-key input.
- JSON parsing via `nlohmann::json` single-header (`json.hpp`).
- Simple duplicate check on add (title match only).
- Merge playlists produces new playlist with combined songs and settable name.

## Potential Improvements
- Persist changes automatically on exit (call `jsonify`).
- Generate unique song IDs (currently empty in JSON).
- Replace `#include <bits/stdc++.h>` with explicit standard headers for portability.
- Fix case mismatch: `mediaplayer.cpp` includes `"MediaPlayer.hpp"` but file is `mediaplayer.hpp` (works on Windows, breaks on case-sensitive systems).
- Add error handling for missing audio files / invalid filepaths.
- Abstract UI rendering (reduce duplication of box formatting code).
- Avoid `using namespace std;` in headers.
- Add unit tests for parsing, merging playlists, and search.

## Adding New Songs Programmatically
```cpp
Song s("Title", "Artist", "Genre", 215);
// s.setDuration(215); // Already set in constructor
// s.setfilepath("path/to/file.mp3"); // (Add setter if needed)
lib.addSong(s);
```
Then (after implementing saving):
```cpp
lib.jsonify(lib.getAllSongs());
```

## License
(No explicit license file present. Consider adding one if distributing.)

## Acknowledgments
- Uses the [nlohmann/json](https://github.com/nlohmann/json) single-header library.
- Windows MCI for lightweight audio playback.

---
Feel free to request enhancements or clarification.
