#include "First.hpp"

#include <vector>

namespace SAOD { namespace Seventh { namespace First {
    
    void Task::SetCountSpaceChildrens(std::vector<SpacePair>& vec, const std::vector<Tree<int>::Element>& elements) {
        for (int i = 0; i < vec.size(); i++) {
            vec[i].size = {1, 1};
        }
        
        int elementsIndex = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (elementsIndex < elements.size() && i*2 == elements[elementsIndex].index) {
                vec[i].size.left = GetSize(elements[elementsIndex++].value);
            }
            if (elementsIndex < elements.size() && i*2 + 1 == elements[elementsIndex].index) {
                vec[i].size.right = GetSize(elements[elementsIndex++].value);
            }
        }
    }
    
    // WORKING WITH NOT LONGER NUMBERS 1-3 (need to fix all)
    
    void Task::ShowTree(void) {
        // counting
        int count = GetCount((int) m_Tree.GetDeep());
        if (count)
            count /= 2;

        std::vector<std::vector<Tree<int>::Element>> elements(m_Tree.GetDeep());
        for (int i = 1; i <= m_Tree.GetDeep(); i++)
            elements[i - 1] = m_Tree.GetElements(i);
        
        int maximalTreeNumber = INT_MIN;
        m_Tree.TreeWalk([&](const int& value) { if (value > maximalTreeNumber) maximalTreeNumber = value; });
        
        if (maximalTreeNumber == INT_MIN)
            maximalTreeNumber = 0;
        
        std::vector<SpacePair> countSpacesPair(count / 2, { GetSize(maximalTreeNumber), {1,1} } );
        std::vector<int> countSpacesCell(count / 2 ? count / 2 - 1 : 0, GetSize(maximalTreeNumber) + 1);
        
        
        
        // main loop
        const std::string globalTreeOffset = "";
        std::vector<std::string> result(m_Tree.GetDeep(), globalTreeOffset);
        
        int firstElementOffset = 0;
        const size_t treeDeep = m_Tree.GetDeep() ? m_Tree.GetDeep() - 1 : 0;
        for (int i = 0; i < m_Tree.GetDeep(); i++) {
            SetCountSpaceChildrens(countSpacesPair, elements[treeDeep - i]);
            if (i + 1 == m_Tree.GetDeep()) {
                if (elements[0].size() == 0)
                    break;
                
                for (int l = 0; l < ceil(firstElementOffset - GetHalf(GetSize(elements[0][0].value))); l++)
                    result[i] += " ";
                result[i] += std::to_string(elements[treeDeep - i][0].value);
            } else {
                
                int elementsCounter = 0;
                int elementUpLayerCounter = 0;
                // print offset
                for (int l = 0; l < ceil(firstElementOffset - countSpacesPair[0].size.left/3.); l++)
                    result[i] += " ";
                for (int j = 0; j < countSpacesPair.size(); j++) {
                    // print
                    if (elementsCounter < elements[treeDeep - i].size() &&j*2 + 0 == elements[treeDeep - i][elementsCounter].index) { // left
                        result[i] += std::to_string(elements[treeDeep - i][elementsCounter++].value);
                    } else {
                        result[i] += "#";
                    }
                    
                    for (int l = 0; l < countSpacesPair[j].between; l++) // between
                        result[i] += " ";
                    
                    if (elementsCounter < elements[treeDeep - i].size() && j*2 + 1 == elements[treeDeep - i][elementsCounter].index) { // right
                        result[i] += std::to_string(elements[treeDeep - i][elementsCounter++].value);
                    } else {
                        result[i] += "#";
                    }
                    
                    
                    if (countSpacesCell.size() && j < countSpacesCell.size()) {
                        for (int l = 0; l < countSpacesCell[j]; l++) // after cell
                            result[i] += " ";
                    }
                    
                    // set first element's offset
                    if (j == 0) {
                        firstElementOffset = GetHalf(countSpacesPair[0].between
                            + countSpacesPair[0].size.left) + firstElementOffset;
                    }
                    
                    // calculating
                    if (j + 1 == countSpacesPair.size())
                        continue;
                    
                    float firstHalf = 0;
                    float secondHalf = 0;
                    
                    int firstCellSize = countSpacesPair[j].size.right + (firstHalf = GetHalf(countSpacesPair[j].between));
                    int secondCellSize = countSpacesPair[j + 1].size.left + (secondHalf = GetHalf(countSpacesPair[j + 1].between));
                    float betweenSpaces = countSpacesCell.size() ? countSpacesCell[j] : 0;
                    
                    int offsetDigits = 0;
                    if (elementUpLayerCounter < elements[treeDeep - i - 1].size() && j == elements[treeDeep - i - 1][elementUpLayerCounter].index) {
                        
                        bool isChange = false;
                        
                        if (firstHalf == (int) floor(firstHalf) && GetSize(elements[treeDeep - i - 1][elementUpLayerCounter].value)%2 != 0) {
                            firstCellSize--;
                            isChange = true;
                        }
                        if (firstHalf != (int) floor(firstHalf) && GetSize(elements[treeDeep - i - 1][elementUpLayerCounter].value)%2 == 0) {
                            firstCellSize--;
                            isChange = true;
                        }
                        
                        offsetDigits += GetHalf(GetSize(elements[treeDeep - i - 1][elementUpLayerCounter].value));
                        
                        elementUpLayerCounter++;
                        
                        if (isChange && elementUpLayerCounter < elements[treeDeep - i - 1].size() && j + 1 == elements[treeDeep - i - 1][elementUpLayerCounter].index) {
                            
                            if (secondHalf == (int) floor(secondHalf) && GetSize(elements[treeDeep - i - 1][elementUpLayerCounter].value)%2 == 0)
                                firstCellSize++;
                            if (secondHalf != (int) floor(secondHalf) && GetSize(elements[treeDeep - i - 1][elementUpLayerCounter].value)%2 != 0)
                                firstCellSize++;
                        }
                    } else {
//                        bool isChange = false;
                        if (firstHalf == (int) floor(firstHalf)) {
                            firstCellSize--;
                        }
                        elementUpLayerCounter++;
                        if (elementUpLayerCounter < elements[treeDeep - i - 1].size() && j + 1 == elements[treeDeep - i - 1][elementUpLayerCounter].index) {
                            
                            if (firstHalf == (int) floor(firstHalf) && GetSize(elements[treeDeep - i - 1][elementUpLayerCounter].value)%2 == 0)
                                firstCellSize++;
                            if (firstHalf != (int) floor(firstHalf) && GetSize(elements[treeDeep - i - 1][elementUpLayerCounter].value)%2 != 0)
                                firstCellSize++;
                        } else {
                            // fix
                        }
                        elementUpLayerCounter--;
                    }
                    
                    if (elementUpLayerCounter < elements[treeDeep - i - 1].size() && j + 1 == elements[treeDeep - i - 1][elementUpLayerCounter].index) {
                        
                        offsetDigits += GetHalf(GetSize(elements[treeDeep - i - 1][elementUpLayerCounter].value));
                    }
                    
                    if (j%2 == 0) { // spaces between elements
                        countSpacesPair[j/2].between = firstCellSize + secondCellSize + betweenSpaces - offsetDigits;
                    } else { // spaces between cells
                        countSpacesCell[j/2] = firstCellSize + secondCellSize + betweenSpaces - offsetDigits;
                    }
                    
                }
                // resize spaces' vectors to up level
                countSpacesPair.resize(countSpacesPair.size() / 2);
                countSpacesCell.resize(countSpacesCell.size() / 2);
            }
        }
        
        // showing
        system("clear");
        for (auto it = result.rbegin(); it != result.rend(); it++) {
            std::cout << *it << std::endl;
        }
    }
    
    void Task::DoExample(void) {
        
        while (m_IsRunning) {
            ShowTree();
            std::cout << "\n ~/";
            std::string command;
            std::cin >> command;
            
            switch (command[0]) {
                case static_cast<int>(Status::Add):
                {
                    int value = 0;
                    std::cin >> value;
                    
                    m_Tree.Add(value);
                    break;
                }
                case static_cast<int>(Status::Remove):
                {
                    int value = 0;
                    std::cin >> value;
                    
                    m_Tree.Remove(value);
                    break;
                }
                case static_cast<int>(Status::Clear):
                    m_Tree.Clear();
                    break;
                case static_cast<int>(Status::Exit):
                    m_IsRunning = false;
                    system("clear");
                    break;
                default:
                    break;
            }
       
        }
    }

} } }
