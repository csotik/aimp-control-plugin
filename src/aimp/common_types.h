// Copyright (c) 2013, Alexey Ivanov

#ifndef AIMP_COMMON_TYPES_H
#define AIMP_COMMON_TYPES_H

#include <vector>
#include <map>
#include <boost/shared_ptr.hpp>

namespace AIMPPlayer
{

typedef int PlaylistEntryID; //! playlist entry handle.
typedef int HPLS; //! playlist handle
typedef HPLS PlaylistID; //! playlist handle

//! direction of sorting.
enum ORDER_DIRECTION { ASCENDING = 0, DESCENDING };

//! Entry fields IDs available for sorting
enum ENTRY_FIELDS_ORDERABLE { ID = 0, TITLE, ARTIST, ALBUM, DATE, GENRE, BITRATE, DURATION, FILESIZE, RATING, FIELDS_ORDERABLE_SIZE };

} // namespace AIMPPlayer

#endif // #ifndef AIMP_COMMON_TYPES_H
