//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2020 MuseScore BVBA and others
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//=============================================================================
#ifndef MU_FRAMEWORK_IFILESYSTEM_H
#define MU_FRAMEWORK_IFILESYSTEM_H

#include "modularity/imoduleexport.h"
#include "retval.h"
#include "io/path.h"

namespace mu::framework {
class IFileSystem : MODULE_EXPORT_INTERFACE
{
    INTERFACE_ID(IFileSystem)

public:
    virtual ~IFileSystem() = default;

    virtual Ret exists(const io::path& path) const = 0;
    virtual Ret remove(const io::path& path) const = 0;

    virtual Ret makePath(const io::path& path) const = 0;

    enum class ScanMode {
        OnlyCurrentDir,
        IncludeSubdirs
    };

    virtual RetVal<io::paths> scanFiles(const io::path& rootDir, const QStringList& filters, ScanMode mode = ScanMode::IncludeSubdirs) const = 0;

    virtual RetVal<QByteArray> readFile(const io::path& filePath) const = 0;
};
}

#endif // MU_FRAMEWORK_IFILESYSTEM_H
