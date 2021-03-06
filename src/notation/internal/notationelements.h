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
#ifndef MU_NOTATION_NOTATIONELEMENTS_H
#define MU_NOTATION_NOTATIONELEMENTS_H

#include "inotationelements.h"
#include "igetscore.h"

namespace mu::notation {
class NotationElements : public INotationElements
{
public:
    NotationElements(IGetScore* getScore);

    Element* search(const std::string& searchText) const override;
    std::vector<Element*> elements(const FilterElementsOptions& elementsOptions) const override;

    Measure* measure(const int measureIndex) const override;
    PageList pages() const override;

private:
    Ms::Score* score() const;

    Ms::RehearsalMark* rehearsalMark(const std::string& name) const;
    Ms::Page* page(const int pageIndex) const;

    std::vector<Element*> allScoreElements() const;

    std::vector<Element*> filterElements(const FilterElementsOptions* elementsOptions) const;
    std::vector<Element*> filterNotes(const FilterNotesOptions* notesOptions) const;

    ElementPattern* constructElementPattern(const FilterElementsOptions* elementsOptions) const;
    Ms::NotePattern* constructNotePattern(const FilterNotesOptions* notesOptions) const;

    IGetScore* m_getScore = nullptr;
};
}

#endif // MU_NOTATION_NOTATIONELEMENTS_H
